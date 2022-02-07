#!/usr/bin/perl

### TO USE: bin/analyze_reads_and_writes.pl -d9 | bin/summarize_analysis.sh | less

# Command is "$0"; command-line arguments can be found in array @ARGV
use strict;
$| = 1; # Autoflush output why not.

my $DBG = 0;
my $DBG9 = 0;
my $tfmt = "%06d";
# ($DBG,$DBG9) = (1,1);

my $simv_log = "/home/steveri/fftgen/simv.log";

while (@ARGV) {
    if    ($ARGV[0] eq "-d")  { $DBG=1; }
    elsif ($ARGV[0] eq "-d9") { $DBG=1; $DBG9 = 1; }
    else {
        $simv_log = $ARGV[0];
        printf("\n\nUsing \"$simv_log\" as simv file\n\n");
    }
    shift @ARGV;
}

# test_bypass2();     exit(0);  # Uncomment to test process_bypasses2()


# Process simv.log from an FFT run;
# show all the reads and writes in a coherent order, something like:
#
#    14000 BFLY0_op1 reads  ( 1.00000, -5.027340) from (SRAM001[0], SRAM002[2])
#    14000 BFLY0_op2 reads  ( 1.00000,  0.000000) from (SRAM004[0], SRAM006[1])
#    14500 BFLY0_op1 out is (-1.496606, 0.000000)
#    14500 BFLY0_op2 out is ( 2.770132, 0.000000)
#    15000 BFLY0_op1 writes (-1.496606, 0.000000)  to  (SRAM001[0], SRAM002[2])
#    15000 BFLY0_op2 writes ( 2.770132, 0.000000)  to  (SRAM004[0], SRAM006[1])

##############################################################################
# This separate prepass sets up the swizzle tables %ix2sram and %sram2ix
# Also use this pass to set the SRAM_TYPE global why not.

my %ix2sram = ();     # E.g. ix2sram("ix4") = "SRAM001[1]"
my %sram2ix = ();     # E.g. sram2ix("SRAM001[1]") = "ix4"

# test_set_ix2bfly(); exit 0;  # Uncomment this to test set_ix2bfly()

my $SRAM_TYPE; # "1port" or "2port"

open FILE, "< $simv_log" or die "Can't open $simv_log";
foreach my $line (<FILE>) {

    # Note SRAM type from line "top_fft     0 SRAM_TYPE=1PORT_DBLPUMP"
    if ($line =~ /SRAM_TYPE=(\S+)/) {
        $SRAM_TYPE = ($1 eq "1PORT_DBLPUMP") ? "2port" : "1port";
    }
    #if ($DBG) { print "              $line"; }

    # top_fft swizzle  3500: BFLY0_op1 ix08 => SRAM008 mem[00]
    # Means:
    #     $ix2sram{"ix1"} = "SRAM003_0"
    #     $sram2ix{"SRAM003_0"} = "ix1"

    if ($line =~ /top_fft swizzle.*ix(\d+) .. (SRAM...) mem.(\d+)/) {
        my $ix = "ix".($1+0); # E.g. "ix0" (NOT "ix00")
        my $srow = $3+0;
        my $sram = "${2}[$srow]"; # E.g. "SRAM000[3]"
        $ix2sram{$ix} = $sram;     # E.g.     ix2sram("ix4") = "SRAM001[1]"
        $sram2ix{$sram} = $ix; # E.g. sram2ix("SRAM001[1]") = "ix4"
        
        if ($DBG) {
            my $pfx = "DBG0-$ix ";
            print $pfx."ix2sram(\"$ix\") = \"$sram\"\n";
        }
    }
}
close FILE;

##############################################################################
my $bflynum = 0;

my %ix2bfly = ();    # E.g. ix2bfly{"ix5"} = "BFLY0_op1"
my %bfly2ix = ();    # E.g. bfly2ix{"BFLY0_op1"} = "ix5"
my %prev_bfly2ix = ();

my @sram2bfly = ();  # E.g. sram2bfly[2] = "BFLY0_op1";
my @prev_sram2bfly = ();

# my %mem = ();
my %inputpair = ();
my %outputpair = ();

my $prevtime = "";
open FILE, "< $simv_log" or die "Can't open $simv_log";
foreach my $line (<FILE>) {
    if ($DBG) { print "              $line"; }
  
    # 1port does this on every (posedge clk)+102 => (602,1602,2602...)
    # "top_fft 4500: BFLY0_op2 ix 05 comes from bank  2 row   1"
    set_ix2bfly("DBG0", $line, \%ix2bfly, \%bfly2ix, \%prev_bfly2ix, \%ix2sram);

# ------------------------------------------------------------------------
# SRAM002 t5 13000: Read(f) wr_data_i mem[1] <= ( 1.000000,-2.414214)
# 
# Means:
#     13000 BFLY1_op1 reads ( 1.000000,-2.414214) from SRAM003[0] (ix1)

    if ($line =~ /^(SRAM...) *t5 *(\d+).*Read.*mem.(\d+).*(\(.*\))/) {

      my ($sram,$time,$ix,$numpair) = ($1, $2, $3, $4);
      my $sram = "${sram}[$ix]"; # E.g. "SRAM005[1]"

      my $ix = $sram2ix{$sram};
      my $b = $ix2bfly{$ix};
      $inputpair{$b} = $numpair; # E.g. "( 1.000000,-2.414214)"

      my $pfx = $DBG ? "DBG2-$ix " : "";

      $prevtime = timegap($prevtime, $time);

      if ($DBG) {
          print $pfx."$line";
#           print $pfx."$1 $2 $3 \"$4\" sram=\"$sram\" mem{\"$sram\"}=\"$b\"\n";
          print $pfx."$1 $2 $3 \"$4\"\n";
          print $pfx."sram=\"$sram\" ix2bfly{\"$ix\"}=\"$b\"\n";
          print $pfx."bfly2ix{\"$b\"}=\"$ix\"\n";
          print $pfx."inputpair{$b} = $numpair\n";
          print "$pfx\n";
      }
      printf($pfx."FINAL $tfmt $b reads  $numpair from $sram ($ix)\n", $time);
      print "$pfx\n";
  }

# ------------------------------------------------------------------------
# top_fft.BFLY1 t5 13000: in1(r,i)= ( 1.000000,-2.414214)
# 
# Confirms:
#     BFLY1_op1 reads ( 1.000000,-2.414214) (from SRAM003[0])
# 
#     if ($inputpair{"BFLY1_op1"} ne "( 1.000000,-2.414214)") ERROR
#     same for op2
# 
#     print("14000 BFLY0_op1 reads  ( 1.00000, -5.027340) from (SRAM001[0], SRAM002[2])")

  # top_fft.BFLY1 t5 13000: in1(r,i)= ( 1.000000,-2.414214)
  if ($line =~ /^top_fft.BFLY(\d) *t5 *(\d+): *in(\d).*= (.*)/) {
      my ($bnum,$time,$opnum,$numpair) = ($1,$2,$3,$4);
      my $bfly = "BFLY${bnum}_op${opnum}";
      my $ix = $bfly2ix{$bfly};

      my $pfx = $DBG ? "DBG3-$ix " : "";

      my $err="ERROR";
      if ($time =~ /50[0-9]$/) {
          # Ignore off-cycle bfly input
          $err = $pfx."IGNORE ERROR ";
          $pfx = $pfx."IGNORE ";
      }

      my $in = $inputpair{$bfly};
      if ($DBG) {
          print $pfx."------------------------------------------------------------------------\n";
          print $pfx."$line";
          print "$pfx\n";
          print $pfx."bnum=$bnum time=$time opnum=$opnum and numpair=\"$numpair\"\n";
          print $pfx."bfly=$bfly in=\"$in\"\n";
          print "$pfx\n";
      }
      my $t_ix = $bfly2ix{$bfly};
      my $sram = $ix2sram{$t_ix};

      $prevtime = timegap($prevtime, $time);
      printf($pfx."FINAL $tfmt $bfly reads  $numpair [ from $sram ($ix) ]\n", $time);
      if ($in ne $numpair) {
          my $errmsg = $err."$ix numpair \"$numpair\" does not match prev numpair in=\"$in\"\n";
          print $errmsg;
          #die $errmsg;
      }
      if ($DBG) { 
          print $pfx."------------------------------------------------------------------------\n";
      }
#       exit 0;
  }

# ------------------------------------------------------------------------
# top_fft.BFLY1 t5 13002: out1(r,i)= (in1_real+t1, in1_imag+t2) = ( 1.000000,-5.027340)
# 
# Means:
#     BFLY1_op1 out is ( 1.000000,-5.027340)
# 
#     print "BFLY1_op1 out is ( 1.000000,-5.027340)";
# 

################# TODO #########################

  if ($line =~ /^top_fft.(BFLY\d) *t5 *(\d+).*out(\d)([^=]+=)([^=]+=) (\(.*\))/) {

      my ($bfly,$time,$opnum,$numpair) = ($1,$2,$3,$6);
      my $bfly = "${bfly}_op${opnum}";
      my $ix = $bfly2ix{$bfly};
      my $pfx = $DBG ? "DBG4-$ix " : "";

      # Ignore off-cycle bfly input ("off-cycle" differs according to sram type)
      if    (($SRAM_TYPE eq "1port") && ($time =~ /00[0-9]$/)) {
          $pfx = $pfx."IGNORE ";
      }
      elsif (($SRAM_TYPE eq "2port") && ($time =~ /50[0-9]$/)) {
          # Ignore off-cycle bfly input ("off-cycle" differs according to sram type)
          $pfx = $pfx."IGNORE ";
      }

      $outputpair{$bfly} = $numpair;
      if ($DBG) {
          print $pfx."------------------------------------------------------------------------\n";
          print $pfx."$line";
          print "$pfx\n";
          print $pfx."bfly=\"$bfly\" time=$time opnum=$opnum and numpair=\"$numpair\"\n";
          print $pfx."bfly=$bfly out=\"$outputpair{$bfly}\"\n";
          print "$pfx\n";
      }

      # Could also use...? sram2ix, right?  AKA sram2ix{sram}
      my $t_ix = $bfly2ix{$bfly};
      my $sram = $ix2sram{$t_ix};
      my $sram2 = $ix2sram{$ix};
      $prevtime = timegap($prevtime, $time);
      printf($pfx."FINAL $tfmt $bfly out is $numpair [ $ix, $sram ]\n", $time);
  }

# ------------------------------------------------------------------------
# SRAM004 t5  3000: Wrote(f) wr_data_i mem[0] <= ( 1.000000, 0.000000)
# SRAM005 t5  3000: Wrote(f) wr_data_i mem[0] <= ( 1.000000, 0.000000)
# 
# Means:
#     BFLY0_op1 wrote ( 1.000000, 0.000000) to SRAM004[0]
#     BFLY1_op2 wrote ( 1.000000, 0.000000) to SRAM005[0]
# 
#     my $bfly = $mem{"SRAM004[0]"}
#     print "$bfly wrote ( 1.000000, 0.000000) to SRAM004[0]";
# 
# 
    if ($line =~ /^(SRAM...) t5 *(\d+).*Wrote.*mem.(\d+).*(\(.*\))/) {
        my ($sram,$time,$srow,$numpair) = ($1,$2,$3,$4);
        $srow = $srow+0; # Canonicalize e.g. "00" => "0"
        $sram = "${sram}[$srow]";

        my $ix = $sram2ix{$sram};
        my $b = $ix2bfly{$ix};

        # Compare to numpair previously written by $b, above.

        my $prev_outpair = $outputpair{$b};
        if ($prev_outpair ne $numpair) {  # E.g. "( 1.000000,-2.414214)"
            my $errmsg = "ERROR $ix outpair \"$numpair\" does not match prev numpair \"$prev_outpair\"\n";
            print $errmsg;
            #die $errmsg;
        }

        my $pfx = $DBG? "DBG5-$ix " : "";
        if ($DBG) {
            print $pfx."------------------------------------------------------------------------\n";
            print $pfx."$line";
            print "$pfx\n";
            print $pfx."sram=\"$sram\" time=$time numpair=\"$numpair\"\n";
            print "$pfx\n";
        }
        $prevtime = timegap($prevtime, $time);
        printf($pfx."FINAL $tfmt $b writes $numpair to $sram ($ix)\n", $time);
    }
    process_bypasses2("DBG7", $line);
}
close FILE;
##############################################################################
# Decode the following sequence:
# 
# fftram   5000 BFLY0_op1_matches = 00000001
# fftram   5000 BFLY0_op2_matches = 00000100
# fftram   5000 Bypassed SRAM 0100, wrote ( 1.000000, 0.000000) to bypass_buffer
# 
# As shown:
# "fftram   5000 BFLY0_op1_matches = 00000001"
#     # Clear the sram2bfly array;
#     $sram2bfly[0] = "BFLY0_op1";
# 
# "fftram   5000 BFLY0_op2_matches = 00000100"
#     if ($sram2bfly[2]) { ERROR }
#     else { $sram2bfly[2] = "BFLY_op2"; }
# 
# "fftram   5000 Bypassed SRAM 0100, wrote ( 1.000000, 0.000000) to bypass_buffer"
#     my $sram_vec = "0100";
#     @sram_vec = split($sram_vec);
#     my $sram = 2;
#     my $bfly = $sram2bfly[2];
# 

##############################################################################
sub test_set_ix2bfly {
    my %ix2bfly; # E.g. ix2bfly{"ix5"} = "BFLY0_op1"
    my %bfly2ix; # E.g. ix2bfly{"BFLY0_op1"} = "ix5"
    my %prev_bfly2ix;
    my %ix2sram; # E.g. ix2sram{"ix5"} = "SRAM003[3]"
    
    foreach my $line # Verbatim lines from simv.log
        (
         "top_fft 4500: BFLY0_op2 ix 05 comes from bank  2 row   1\n"
        ) {
            print "$line";
            $ix2sram{"ix5"} = "SRAM002[1]";
            set_ix2bfly("FOO", $line, \%ix2bfly, \%bfly2ix, \%prev_bfly2ix, \%ix2sram);
            printf("ix2bfly{\"ix5\"} = %s\n\n", $ix2bfly{"ix5"});

            my $line = "top_fft 4500: BFLY0_op2 ix 07 comes from bank  2 row   1\n";
            # Okay this one should produce an error.
            print "$line";
            $ix2sram{"ix5"} = "SRAM002[WRONG]";
            set_ix2bfly("FOO", $line, \%ix2bfly, \%bfly2ix, \%prev_bfly2ix, \%ix2sram);
            printf("ix2bfly{'ix5'} = %s\n\n", $ix2bfly{"ix5"});
    }
}

sub set_ix2bfly {
    my $pfx = shift;
    my $line = shift;
    my $ix2bfly = shift;
    my $bfly2ix = shift;
    my $prev_bfly2ix = shift;
    my $ix2sram = shift;

    # "top_fft 4500: BFLY0_op2 ix 05 comes from bank  2 row   1"

    # Line should look like "top_fft 4500: BFLY0_op2 ix 05 comes from bank  2 row   1"
    if ($line =~ /^top_fft *(\d+): *(BFLY\S+) *ix *(\d+) *comes from *bank *(\d+) *row *(\d+)/) {
        my ($time,$op,$ix,$bank,$row) = ($1,$2,$3,$4,$5);
        $time = sprintf($tfmt, $time);
        $ix = "ix".($ix+0);               # E.g. "05" => "ix5"
        my $nnn = sprintf("%03d",$bank);
        $row += 0;
        my $sram = "SRAM${nnn}[$row]";
        my $sram2 = $ix2sram->{$ix};
        $pfx = "$pfx-$ix ";
#         $prev_ix2bfly->{$ix} = $ix2bfly->{$ix}

        $prev_bfly2ix->{$op} = $bfly2ix->{$op};

        $ix2bfly->{$ix} = $op; # E.g. ix2bfly{"ix5"} = "BFLY0_op1"
        $bfly2ix->{$op} = $ix; # E.g. ix2bfly{"BFLY0_op1"} = "ix5"

        if ($DBG9) {
            printf($pfx.$line);
            printf($pfx."time=$time, op=\"$op\", ix=$ix, sram=\"$sram\" =? \"$sram2\"\n");
            printf($pfx."bfly2ix     {\"$op\"}=%s\n",      $bfly2ix->{$op});
            printf($pfx."prev_bfly2ix{\"$op\"}=%s\n", $prev_bfly2ix->{$op});
        }

        # Little error check on ix2sram
        if ($sram ne $sram2) {
            my $errmsg = "ERROR analyze_reads...: set_ix2bfly mismatched srams \"$sram\" ne \"$sram2\"\n";
            printf($errmsg);
            die $errmsg;
        }

        return 1;
    }
    return 0;
}

##############################################################################
sub timegap {
    my $prevtime = shift;
    my $time = shift;
    if ($prevtime && ($prevtime != $time)) {
        print "\n";
        return $time;
    }
    return $prevtime;
}

#sub show_array {
#    my $pfx = shift;
#    my $arrname = shift;
#    my @arr = @_;
#
#    for (my $i=0; $i<@arr; $i++) {
#        printf($pfx."${arrname}[$i] = $arr[$i]\n");
#    }
#    print "$pfx\n";
#}

sub test_bypass2 {
    my @test_array = 
        (""  # Verbatim lines from simv.log
         ,"top_fft swizzle  7500: BFLY0_op2 ix12 => SRAM013 mem[00]\n"
         ,"fftram   7500 Bypassed SRAM 13, wrote ( 0.000000, 0.000000) to bypass_buffer[1]\n"
         ,"top_fft swizzle  8500: BFLY2_op2 ix12 => SRAM013 mem[00]\n"
         ,"fftram   8500 Bypassed SRAM 13, read  ( 0.000000, 0.000000) from bypass_buffer[1]\n"
        );
    foreach my $line (@test_array) {
        process_bypasses2("DBG7", $line);
    }

}

my %bypass_map;         # E.g. $bypass_map{"SRAM013"} = "BFLY_op2 ix12";
sub process_bypasses2 {
    my $pfx = shift;
    my $line = shift;

    # Given the sequence
    #     top_fft swizzle  7500: BFLY0_op2 ix12 => SRAM013 mem[00]
    #     fftram   7500 Bypassed SRAM 13, wrote ( 0.000000, 0.000000) to bypass_buffer[1]
    #     top_fft swizzle  8500: BFLY2_op2 ix12 => SRAM013 mem[00]
    #     fftram   8500 Bypassed SRAM 13, read  ( 0.000000, 0.000000) from bypass_buffer[1]
    #
    # Print:
    # "DBG7-ix12 FINAL 007500 BFLY0_op2 reads  ( 0.000000, 0.000000) from bypass_buffer[1] (!SRAM012)"
    # "DBG7-ix12 FINAL 008500 BFLY2_op2 reads  ( 0.000000, 0.000000) from bypass_buffer[1] (!SRAM013)"

    # "top_fft swizzle  7500: BFLY0_op2 ix12 => SRAM013 mem[00]\n"
    if ($line =~ /^top_fft swizzle.*(BFLY\d+_op[12]).*ix(\d+).*(SRAM\d+)/) {
        my ($bfly_op, $ixnum, $sram) = ($1, $2, $3);
        my $ix = "ix".($ixnum+0);  # E.g. "08" => "ix8"
        $bypass_map{$sram} = "$bfly_op $ix";    # E.g. $bypass_map{"SRAM013"} = "BFLY_op2 ix12";
        return 1;
    }

    # "fftram   7500 Bypassed SRAM 13, wrote ( 0.000000, 0.000000) to bypass_buffer[1]\n"
    elsif ($line =~ /^fftram\D+(\d+).*Bypassed SRAM (\d+), (read|wrote).*(\(.*\)).*(to|from).*(bypass_buffer\S+)/) {
        my ($time, $snum, $rw, $numpair, $tf, $bybuf) = ($1, $2, $3, $4, $5, $6);
        my $sram = sprintf("SRAM%03d", $snum);
        my ($bfly_op, $ix) = split(" ", $bypass_map{$sram});

        # Print:
        # DBG7-ix12 FINAL 007500 BFLY0_op2 reads  ( 0.000000, 0.000000) from bypass_buffer[1] (!SRAM012)
        # DBG7-ix12 FINAL 008500 BFLY2_op2 reads  ( 0.000000, 0.000000) from bypass_buffer[1] (!SRAM013)

        printf("$pfx-$ix FINAL %06d $bfly_op %s $numpair %s $bybuf (!$sram)\n"
               ,$time,
               ,($rw eq 'wrote') ? "writes" : "reads "
               ,($tf eq "from") ? "from" : " to "
            );
        return 1;
    }
    else {
        return 0;
    }
}



