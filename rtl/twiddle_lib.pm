package twiddle_lib;
use strict;

sub log2 {
    my $n = shift @_;
    my $result = 1; while ( (2**$result) < $n ) { $result++; }
    return $result;
}

##############################################################################
# Kind of a hack, I guess; does it work?
my @inputs = ();
my @outputs = ();

my ($npoints, $nlevels, $nunits, $ncalcs_per_unit, $data_width);

sub setglobals {
  $npoints = shift @_;
  $nlevels = shift @_;
  $nunits  = shift @_;
  $ncalcs_per_unit = shift @_;
  $data_width = shift @_;

  my $cnbits = sprintf("[%d:0]", log2($ncalcs_per_unit)-1);  # Weird?  Contrived?
  @inputs = (
      $cnbits, "cycle_num", "// Counts from 0 to ncalcs/nunits(?) maybe",
  );
  my @outputs = (
  );
}

##############################################################################
# Local subroutines.
#
sub printconnections {
    my $indent = shift @_;
    my $indent = "      ";

    # .clk(clk_i),
    # .rst_n(rst_n_i), etc.

    print $indent."// begin twiddle->printconnections()\n";
    for (my $i = 0; $i < @inputs; $i += 3) {
        fftgen::printparm($indent, $inputs[$i+1], "_i", $inputs[$i+2]);
    }

    print "\n";
    for (my $i=0; $i<$nunits; $i++) {
            my $s = sprintf("BFLY%d_twiddle", $i);
            #printf(".$s($s), ");
            printf("$indent.${s}_cos_o(${s}_cos),\n");
            printf("$indent.${s}_sin_o(${s}_sin)");
            if ($i < ($nunits-1)) { print ",\n"; } else { print "\n"; }
    }
    print "\n";

    my $no_comma = "";
    my $n_outputs = @outputs; # No. items in array "@outputs"
    for (my $i = 0; $i < $n_outputs; $i += 2) {
        if ($i == ($n_outputs - 2)) { $no_comma = "no_comma"; }
        fftgen::printparm($indent, $outputs[$i], "_o", $outputs[$i+1], $no_comma);
    }
   print $indent."// end twiddle->printconnections()\n";
}

sub printwires {
   # Print port list as either list of wires ($list=wire_list)
   # or list of inputs and outputs ($list=io_list)

   my $indent = shift @_;
   # Okay yes this is weird but parm list has extra "HASH" when called as "function()" vs. "obj->function()"!!
   while ($indent =~ /HASH/) { $indent = shift @_; }

   my $list    = shift @_; # Either "io_list" (for me) or "wire_list" (for others)
   my $io_list = ($list eq "io_list") ? 1 : 0;
   
   print $indent."//------------------------------------------------\n";
   print $indent."// begin twiddle->printwires('$indent', '$list')\n";

   my $prefix  = ($io_list) ? "input " :  ""  ;
   my $suffix  = ($io_list) ? "_i"     :  ""  ;
   my $eol     = ($io_list) ? ","      :  ";" ;
   for (my $i = 0; $i < @inputs; $i += 3) {
        printf($indent."${prefix}logic %s %s${eol} %s\n", $inputs[$i], $inputs[$i+1].$suffix, $inputs[$i+2]);
   }
   print "\n";

   twiddle_factors("$indent", $list);
   
   my $prefix = ($io_list) ? "output " :  ""  ;
   my $suffix = ($io_list) ? "_o"      :  ""  ;
   for (my $i = 0; $i < @outputs; $i += 2) {
       if ($i == (@outputs - 2)) {
           $eol = $io_list ? "" : ";"  ;
       }
       printf($indent."%-19s %s\n", 
              "${prefix}logic ".$outputs[$i].$suffix.${eol}, $outputs[$i+1]);
   }
   print $indent."// end twiddle->printwires()\n";
   print $indent."//------------------------------------------------\n";
}

sub twiddle_factors {
    my $indent = shift @_;
    my $list    = shift @_; # Either "io_list" or "wire_list"

    my $output = ($list eq "io_list") ? "output " :  ''  ;
    my $eol    = ($list eq "io_list") ?    '_o,'    :  ';' ;
    my $final  = ($list eq "io_list") ?    '_o'     :  ';' ;

    print $indent."// Twiddle factors for butterfly units\n";
    for (my $i=0; $i<$nunits; $i++) {
        foreach my $tf ( ("twiddle_cos", "twiddle_sin") ) {
            if (($i == ($nunits-1)) && ($tf eq "twiddle_sin")) { $eol = $final; } # UGH!
            printf($indent.$output."logic [%d:0] ", $data_width - 1);
            printf("BFLY${i}_${tf}${eol}\n");
        }
        if ($nunits > 1) { print "\n"; }
    }
    if ($nunits == 1) { print "\n"; }
}

sub gen_twiddle_mem_decl {
    ###################################
    # E.g.
    #     logic [3:0] BFLY0_twiddle1_mem [0:7];
    #     logic [3:0] BFLY1_twiddle2_mem [0:7];
    my $indent   = "   ";
    my $bitwidth = $data_width; # 32 or 64 (single or double precision fp)
    print $indent."// $ncalcs_per_unit $data_width-bit wide registers per butterfly unit.\n";
    print "\n";
    for (my $i=0; $i<$nunits; $i++) {
        printf($indent."logic [%d:0] BFLY%d_twiddle_mem_cos[0:%d];\n", $bitwidth-1, $i, $ncalcs_per_unit-1);
        printf($indent."logic [%d:0] BFLY%d_twiddle_mem_sin[0:%d];\n", $bitwidth-1, $i, $ncalcs_per_unit-1);
        print "\n";
    }
  }
   
#sub fft_gen_twiddles {
#    # Usage: fft_gen_twiddles(indent, npoints, nunits, twiddle_bitwidth)
#    # E.g. fft_gen_twiddles("   ", 1024, 4, 32);
#    # Inspired by a c program found online at http://cnx.org/content/m12016/latest/
#    # Also see: alg_rev_in.ref.c
#
#    # Some useful tests one could do: see "sub test_gen_twiddles", below.
#
#    my $DBG = 0;
#    my $DBG = 1;
#
#    my $indent = shift;
#    my $npoints = shift; # length of FFT: must be a power of two
#    my $nunits = shift;  # Number of butterfly units employed per cycle.
#    my $tw = shift;
#
#    my $convert;
#    if    ($tw == 32) { $convert = '$shortrealtobits'; }
#    elsif ($tw == 64) { $convert = '$realtobits'; }
#    else {
#        printf("ERROR (twiddle.vp): data width %d not supported\n", $tw);
#    }
#    my $howmany = $nunits == 1 ? "using one butterfly unit" : "spread over $nunits butterfly units";
#    print $indent."/////////////////////////////////////////////////////////////////////////\n";
#    print $indent."// Pre-load LUT with $tw-bit twiddle factors for $npoints FFT data points\n";
#    print $indent."// $howmany.\n";
#
#    #my $tw_ix = 0;
#    my $unum  = 0;
#    my $cynum = 0;
#    for (my $i=0; $i < log2($npoints); $i++) {
#        if ($DBG) { printf($indent."//------------------------------ Stage %d ------------------------------//\n\n", $i); }
#
#        my $n1 = 2**$i;  # $n1:  1  2  4  8 16 ... = 2**$i
#        my $n2 = 2*$n1;  # $n2:  2  4  8 16 32 ... = 2*$n1
#
#        my $e = -6.283185307179586 / $n2;
#        my $a = 0.0;
#
#        for (my $j = 0; $j < $n1; $j++) {
#            my $c = cos($a);
#            my $s = sin($a);
#            $a = $a + $e;
#
#            for (my $k = $j; $k < $npoints; $k = $k + $n2) {
#
#                printf($indent."BFLY${unum}_twiddle_mem_cos[%2d] = ${convert}(%15.8e);", $cynum, $c);
#                printf("  // %6.3f\n", $c);
#                printf($indent."BFLY${unum}_twiddle_mem_sin[%2d] = ${convert}(%15.8e);", $cynum, $s);
#                printf("  // %6.3f\n", $s);
#                #if ((($k + $n2) >= $npoints) && (($j+1) >= $n1)) { print "\n"; }
#                print "\n";
#
#                #$tw_ix++;
#                $unum = ($unum + 1) % $nunits;  # 0,1,2,3,0,1,2,3,...
#                if ($unum == 0) { print ""; $cynum++; }
#            }
#        }
#    }
#}

sub fft_gen_twiddles2 {
    # Given data struct @fft_scheduler::fft_sched (see below), do the same thing that fft_gen_twiddles used to do.

    # fft_scheduler($npoints, $nunits) generated array @fft_sched, where each entry contains:
    #   $fft_sched[$i]->{stage}  # FFT stage number (see below)
    #   $fft_sched[$i]->{op1}    # Index of butterfly op 1
    #   $fft_sched[$i]->{op2}    # Index of butterfly op 2
    #   $fft_sched[$i]->{bank1}  # SRAM bank for op1
    #   $fft_sched[$i]->{bank2}  # SRAM bank for op2
    #   $fft_sched[$i]->{ctwid}  # twiddle factor COSINE
    #   $fft_sched[$i]->{stwid}  # twiddle factor SINE
    #   $fft_sched[$i]->{access} # If reschedule TRUE, tells when to use the bypass buffer.

    # Usage: fft_gen_twiddles(indent)
    # E.g. fft_gen_twiddles("   ");

    # Some useful tests one could do: see "sub test_gen_twiddles", below.

    my $DBG = 0;
    my $DBG = 1;

    my $indent = shift;
    my $npoints = shift; # length of FFT: must be a power of two
    my $nunits = shift;  # Number of butterfly units employed per cycle.
    my $tw = shift;

#    $indent = "// FOOP ";
#    print $indent."\n";

    my $convert;
    if    ($tw == 32) { $convert = '$shortrealtobits'; }
    elsif ($tw == 64) { $convert = '$realtobits'; }
    else {
        printf("ERROR (twiddle.vp): data width %d not supported\n", $tw);
    }
    my $howmany = $nunits == 1 ? "using one butterfly unit" : "spread over $nunits butterfly units";
    print $indent."/////////////////////////////////////////////////////////////////////////\n";
    print $indent."// Pre-load LUT with $tw-bit twiddle factors for $npoints FFT data points\n";
    print $indent."// $howmany.\n";

#    print "//FOOP twiddle_lib op1[0] is @fft_scheduler::fft_sched[0]->{op1}\n";
#    print "//FOOP twiddle_lib op2[0] is @fft_scheduler::fft_sched[0]->{op2}\n";

    my $unum  = 0;
    my $cynum = 0;
    my $prev_stage = -1;
    for (my $i=0; $i <  @fft_scheduler::fft_sched; $i++) {
        my $stage = @fft_scheduler::fft_sched[$i]->{stage};
        if ($stage != $prev_stage) {
            if ($DBG) {
                printf($indent.
                       "//------------------------------ Stage %d ------------------------------//\n\n",
                       $stage);
            }
            $prev_stage = $stage;
        }
        my $c = @fft_scheduler::fft_sched[$i]->{ctwid};
        printf($indent."BFLY${unum}_twiddle_mem_cos[%2d] = ${convert}(%15.8e);", $cynum, $c);
        printf("  // %6.3f\n", $c);
        my $s = @fft_scheduler::fft_sched[$i]->{stwid};
        printf($indent."BFLY${unum}_twiddle_mem_sin[%2d] = ${convert}(%15.8e);", $cynum, $s);
        printf("  // %6.3f\n", $s);
        print "\n";
        $unum = ($unum + 1) % $nunits;  # 0,1,2,3,0,1,2,3,...
        if ($unum == 0) { print ""; $cynum++; }
    }
}

sub test_gen_twiddles {
    my $npoints = 8; # Length of FFT: must be a power of two
    my $nunits  = 1; # How many butterfly units employed per cycle; must be a power of two.
    my $twiddle_width = 32;
    fft_gen_twiddles("   ", $npoints, $nunits, $twiddle_width);
    fft_gen_twiddles("", $npoints, 2, 64);
    fft_gen_twiddles("", $npoints, 4, 64);
    fft_gen_twiddles("", 16, 4, 64);
    fft_gen_twiddles("", 32, 4, 64);
}

# All .pm packages must end in "1"...because perl is so stoopid...
1;
