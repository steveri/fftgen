#!/usr/bin/perl
## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
#!/usr/bin/perl
# Command is "$0"; command-line arguments can be found in array @ARGV
use strict;

my $DBG = 0;
my $DBG9 = 0;
my $TEST_ERROR = 0;
my $LOGFILE = "simv.log";

if (@ARGV != 4) {
    my $errmsg = sprintf(
        "\n".
        "Generates correct fft answers and compares vs. $LOGFILE\n".
        "\n".
        "Usage:\n".
        "   $0 <logfile> <npoints> <n_butterfly_units> <sram_type>\n".
        "\n".
        "Examples:\n".
        "    $0 fft.log  8    1 \"2port\"\n".
        "    $0 simv.log 1024 4 \"1port\"\n".
        "\n");
    die $errmsg;
}
my ($LOGFILE, $npoints,$nunits,$sram_type) = ($ARGV[0], $ARGV[1], $ARGV[2], $ARGV[3]);
print "Comparing $LOGFILE against GM w/ npoints=$npoints, nunits=$nunits and sram_type=\"$sram_type\".\n";

if ($sram_type eq "test_error") {
    $sram_type = "1port";
    $TEST_ERROR = 1;  # Guarantees at least one error
}

# Compare results in "$FFTGEN_DIR/$LOGFILE" against result of running golden model
# on "npoints" and "nunits"

my $FFTGEN_DIR = mydir("..");  # Script lives in $FFTGEN_DIR/bin

# 1905 Assumes called from run dir; is this okay?
my $RUN_DIR = ".";


#golden_model(16, 1);
#do_test(8, 1, "1port");
#do_test(16, 1, "1port");
do_test($npoints, $nunits, $sram_type);
exit(0);

#do_test  8, 1, "2port";
#do_test 16, 4, "1port";

sub do_test {
    my $npoints = shift;
    my $nunits = shift;
    my $sram_type = shift;

    my @gm_results = golden_model($npoints, $nunits);

#    foreach my $result (@gm_results) { print "bat $result\n"; } print "\n";

#    my @fft_results = do_fft(8, 1, "1port");
    my @fft_results = do_fft();  # Use results found in "$LOGFILE".
    print "\n";
#    foreach my $result (@fft_results) { print "fat $result\n\n"; } print "\n";

    if ($#gm_results != $#fft_results) {

        my $errmsg = sprintf("ERROR Golden model produced %d results and FFT produced %d.\n",
                            ($#gm_results+1)/2, ($#fft_results+1)/2);
        $errmsg .= "Maybe try this:\n";
        $errmsg .= "$FFTGEN_DIR/bin/fft_golden_model.pl $npoints $nunits\n";
        die $errmsg;
        exit(-1);
    }

    my $nerrors = 0;

    if ($TEST_ERROR) { $gm_results[3] = "42"; }

    $nerrors += print_results("Real", $npoints, \@gm_results, \@fft_results);
    $nerrors += print_results("Imag", $npoints, \@gm_results, \@fft_results);

#    print "\n";
    my $test_result = ($nerrors==0) ? "PASS" : "FAIL";
    my $plural = ($nerrors==1) ? "" : "s";
    print "$test_result: $nerrors mismatched result$plural --- $npoints $nunits $sram_type\n";
}

sub do_fft {
    # Use whatever results we find in "$LOGFILE"
    #my $npoints = shift;
    #my $nunits = shift;
    #my $sram_type = shift;
    ##############################################################################
    # Print results from FFT.

    #my $fft = `cat /home/steveri/fftgen/$LOGFILE | egrep '^SRAM.*Wrote'`;
    #my $fft = `cat /home/steveri/fftgen/$LOGFILE | awk -f bin/process_test5.awk | egrep '^ix'`;

    # 1905 can run from any directory!
    # my $fft = `cat $FFTGEN_DIR/$LOGFILE | awk -f bin/process_test5.awk | egrep '^ix'`;
    my $fft = `cat $RUN_DIR/$LOGFILE | awk -f $FFTGEN_DIR/bin/process_test5.awk | egrep '^ix'`;


    # Above command should have yielded e.g.
    #
    # ix00: SRAM000 t5 13500: Wrote(f) wr_data_i mem[0] <= ( 8.000000, 0.000000)
    # ix01: SRAM003 t5 13500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-5.027340)
    # ix02: SRAM006 t5 14500: Wrote(f) wr_data_i mem[0] <= ( 0.000000, 0.000000)
    # ix03: SRAM005 t5 14500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-1.496606)
    # ix04: SRAM004 t5 15500: Wrote(f) wr_data_i mem[0] <= ( 0.000000, 0.000000)
    # ix05: SRAM007 t5 15500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.668179)
    # ix06: SRAM002 t5 16500: Wrote(f) wr_data_i mem[0] <= ( 0.000000, 0.000000)
    # ix07: SRAM001 t5 16500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.198912)

    #print $fft;

    #my @fft = split("\n", $fft);
    my @ar = (); # Real part of complex number
    my @ai = (); # Imaginary part of complex number
    foreach my $line (split("\n", $fft)) {
        if ($DBG9) { print "foo $line\n"; }
            
    #         # From sample line
    #         # "SRAM005 t5  9000: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.668179)"
    #         # Want to extract $1 = "1.000000" and $2 = "-0.668179"
    # 
    #         if ($line =~ /^(SRAM...).*\( *([^ ,]*), *([^ ,]*).$/) {
    #             my ($sram,$real,$imag) = ($1,$2,$3);
    #             #print "bar    $sram $real $imag\n";
    #             $ar{$sram} = $real;
    #             $ai{$sram} = $imag;
    #         }
    # 
        # From sample line
        # "ix05: SRAM007 t5 15500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.668179)"
        # Want to extract $1 = "5" and $2 = "1.000000" and $3 = "-0.668179"
 
        if ($line =~ /^ix([0-9]+).*\( *([^ ,]*), *([^ ,]*).$/) {
            my ($ix,$real,$imag) = ($1,$2,$3);
            #print "bar    $ix $real $imag\n";
            $ar[$ix] = $real;
            $ai[$ix] = $imag;
        }
    }

    if ($DBG) {
        print "      _____________FFT____________\n";
    }

#    my $i = 0;
#    my @ar = ();
#    my @ai = ();
#    foreach my $bank (sort (keys %ar)) {
    for (my $ix = 0; $ix < @ar; $ix++) {
        #print "baz \"$ix\" r=$ar{$ix} i=$ai{$ix}\n";
        if ($DBG) {
            printf("    %4d   %9s    %9s\n", $ix, $ar[$ix], $ai[$ix]);
        }
        #printf("    %4d   %6.3f    %6.3f\n", $i, $ar[$i], $ai[$i]);

#        @ar = (@ar, $ar{$bank});
#        @ai = (@ai, $ai{$bank});
    }
    return (@ar,@ai);
}


sub golden_model {
    my $npoints = shift;
    my $nunits = shift;

    ##############################################################################
    # Print results from Golden Model

#     my $golden_model = "/home/steveri/fftgen/bin/fft_golden_model.pl";
    my $golden_model = "$FFTGEN_DIR/bin/fft_golden_model.pl";

#    my $gm = `$golden_model 8 1`;
    # Only want the lines with numbers ONLY.
    my $gm = `$golden_model $npoints $nunits | egrep -v '[a-zZ-Z]'`;
    if ($DBG) {
        print "\n";
        print "     ______GOLDEN MODEL______\n";
        print $gm;
        print "\n";
    }

    # Build and return real and imag arrays.

    my @ar = ();
    my @ai = ();
    foreach my $line (split("\n", $gm)) {
        # Each line looks like this:
        # "       1    1.000    -2.414"
        if ($line =~ /\s*(\S+)\s*(\S+)\s*(\S+)/) {
            my ($ix,$real,$imag) = ($1,$2,$3);
            #print "foo found $real and $imag\n";
            @ar = (@ar,$real);
            @ai = (@ai,$imag);
        }
    }
    return (@ar,@ai);
}

sub print_results {
    my $rtype = shift; # "Real" or "Imag"
    my $npoints = shift; 
    my $gm_results = shift;  # Pointer to results e.g. \@gm_results
    my $fft_results = shift; # Pointer to results e.g. \@fft_results

    my $nerrors = 0;
    my $nwarnings = 0;
    my ($first,$last) = ($rtype eq "Real") ? (0, $npoints) : ($npoints, 2*$npoints);
    print "$rtype results:  GM        FFT\n";
    for (my $i=$first; $i < $last; $i++) {
        #printf("             %6s    %9s\n", $gm_results[$i], $fft_results[$i]);
        #printf("             %6.3f    %6.3f\n", $gm_results[$i]+0, $fft_results[$i]+0);

        # Warning if no match @ three sig figs.
        my $status = "";

        my $gr3 = sprintf("%9.3f",  @{$gm_results}[$i]+0);
        my $fr3 = sprintf("%9.3f", @{$fft_results}[$i]+0);

        # Oh this is annoying; must canonicalize "-0.000" => "0.000"
        # if ($gr3 eq '-0.000') { $gr3 = '0.000'; }
        # if ($fr3 eq '-0.000') { $fr3 = '0.000'; }

        $gr3 =~ s/[-]0[.]000/ 0.000/;
        $fr3 =~ s/[-]0[.]000/ 0.000/;

        if ($gr3 ne $fr3) {

            # Well which is it, error or warning?
            my $gr2 = $gr3; chop($gr2);
            my $fr2 = $fr3; chop($fr2);
            if ($gr2 ne $fr2) {
                $status = " *** ERROR '$gr2' ne '$fr2'";
                $nerrors++;
            }
            else {
                $status = " *** WARNING only match to 2 sig figs";
                $nwarnings++;
            }
        }

        printf("             %s    %s$status\n", $gr3, $fr3);
    }
    print "\n";
    return $nerrors
} # sub print_results

sub mydir {
    my $offset = shift;  # E.g. "../rtl"

    # Return full path of directory where this script lives, offset according to $offset.
    use Cwd 'abs_path';
    my $fullpath = abs_path($0); # Full pathname of script e.g. "/foo/bar/opendesign.pl"

    use File::Basename 'fileparse';
    my ($filename, $dir, $suffix) = fileparse($fullpath);
    return abs_path("$dir/$offset");
}
##############################################################################
## Copyright Stephen Richardson and Stanford University.  All rights reserved.
##              Exclusively Licensed by Chip Genesis Inc.
##
## The code, the algorithm, or any part of it is not to be copied/reproduced.
## The code, the algorithm, or results from running this code may not be used
## for any commercial use unless legally licensed.
##
## For more information please contact
##   Ofer Shacham (Stanford Univ./Chip Genesis)   shacham@alumni.stanford.edu
##   Professor Mark Horowitz (Stanford Univ.)     horowitz@stanford.edu
##
## Genesis2 is patent pending. For information regarding the patent please
## contact the Stanford Technology Licensing Office.
###############################################################################
