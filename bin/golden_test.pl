#!/usr/bin/perl
use strict;

# Compares FFT log file from rtl simulation, against a golden model.
# Summarizes results from each and says either PASS or FAIL.

# This script should produce same results as the alternative python version
# "golden_test.py". E.g. to compare the two
# 
#   f=../tst/regress/old/verlint/fft.log
#   golden_test.pl $f 8 1 2port > tmp.pl
#   golden_test.py $f 8 1 2port > tmp.py
#   diff tmp.p[ly]

# Set one or more of these vars to "1" to test the script
my $DBG = 0;
my $DBG9 = 0;

# Help message
if (@ARGV != 4) {
    my $errmsg = sprintf(
        "\n".
        "Generates correct fft answers and compares vs. <logfile>\n".
        "\n".
        "Usage:\n".
        "   $0 <logfile> <npoints> <n_butterfly_units> <sram_type>\n".
        "\n".
        "Examples:\n".
        "    $0 fft.log  8    1 \"2port\"\n".
        "    $0 simv.log 1024 4 \"1port\"\n".
        "\n".
        "To test failure mechanism, use sram_type \"test_error\"\n".
        "    $0 fft.log  8    1 \"test_error\"\n".
        "\n".
        "    $0 ../tst/regress/old/verlint/fft.log 8 1 \"2port\"\n".
        "\n");
    die $errmsg;
}

# Process command-line arguments
my ($LOGFILE, $npoints,$nunits,$sram_type) = ($ARGV[0], $ARGV[1], $ARGV[2], $ARGV[3]);

print "Comparing FFT log '$LOGFILE' vs. gold model (GM)\n";
print "with npoints=$npoints, nunits=$nunits, sram_type='$sram_type'\n";


########################################################################
# Set FFTGEN_DIR as the path to the local fftgen repo.
# Assumes that this script lives in FFTGEN_DIR/bin
# E.g. scriptdir='/home/steveri/github/fftgen/bin'
my $FFTGEN_DIR = mydir("..");
my $RUN_DIR = ".";


# Compare results in "$FFTGEN_DIR/$LOGFILE" against result of running golden model
do_test($npoints, $nunits, $sram_type);
exit(0);

sub do_test {
    my $npoints = shift;
    my $nunits = shift;
    my $sram_type = shift;
    my $DBG = 0;

    # Compare results in <LOGFILE> against result of running golden model

    # Examples:
    #   do_test  8, 1, "2port"
    #   do_test 16, 4, "1port"

    if ($DBG) { print('do_test %s %s %s\n', $npoints, $nunits, $sram_type); }

print("bookmarkpl\n");
    my @gm_results = golden_model($npoints, $nunits);

#    foreach my $result (@gm_results) { print "bat $result\n"; } print "\n";

#    my @fft_results = do_fft(8, 1, "1port");
    my @fft_results = do_fft();  # Use results found in "$LOGFILE".
    print "\n";
#    foreach my $result (@fft_results) { print "fat $result\n\n"; } print "\n";

    # If lengths don't match, maybe user got command line args wrong (???)
    # gm_results=(0,1,2,3,4,5,6,7,8); # Uncomment to check error message
    if ($#gm_results != $#fft_results) {

        my $errmsg = sprintf("ERROR Golden model produced %d results and FFT produced %d.\n",
                            ($#gm_results+1)/2, ($#fft_results+1)/2);
        $errmsg .= "Maybe try this:\n";
        $errmsg .= "$FFTGEN_DIR/bin/fft_golden_model.pl $npoints $nunits\n";
        die $errmsg;
        exit(-1);
    }

    # Secret sram type to test error handling; inserts a single faulty datapoint
    if ($sram_type eq "test_error") {
        $sram_type = "1port";
        $fft_results[3] = "99999";   # Guarantees at least one error
    }

#     if ($TEST_ERROR) { $gm_results[3] = "42"; }

    my $nerrors = 0;
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

    if ($ENV{ALL_LDBG}) {
        print STDERR "WARNING\n";
        print STDERR "WARNING Env var ALL_LDBG is set (=$ENV{ALL_LDBG})".
            ", that can screw up the golden model.\n";
        print STDERR "WARNING\n\n";
    }

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
    if (($#ar+1) != $npoints) {
        die "ERROR Golden model produced $#ar results but npoints=$npoints\n";
        exit(-1);
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
    print "$rtype results:      GM          FFT\n";
    for (my $i=$first; $i < $last; $i++) {
        #printf("             %6s    %9s\n", $gm_results[$i], $fft_results[$i]);
        #printf("             %6.3f    %6.3f\n", $gm_results[$i]+0, $fft_results[$i]+0);

        # Should match to three decimal places; two or one means WARNING
        my $gr3 = sprintf("%9.3f",  @{$gm_results}[$i]+0);
        my $fr3 = sprintf("%9.3f", @{$fft_results}[$i]+0);
        # Oh this is annoying; must canonicalize "-0.000" => "0.000"
        $gr3 =~ s/[-]0[.]000/ 0.000/;
        $fr3 =~ s/[-]0[.]000/ 0.000/;

        my $gr2 = sprintf("%9.2f",  @{$gm_results}[$i]+0);
        my $fr2 = sprintf("%9.2f", @{$fft_results}[$i]+0);
        # Oh this is annoying; must canonicalize "-0.000" => "0.000"
        $gr2 =~ s/[-]0[.]00/ 0.00/;
        $fr2 =~ s/[-]0[.]00/ 0.00/;

        my $gr1 = sprintf("%9.1f",  @{$gm_results}[$i]+0);
        my $fr1 = sprintf("%9.1f", @{$fft_results}[$i]+0);
        # Oh this is annoying; must canonicalize "-0.000" => "0.000"
        $gr1 =~ s/[-]0[.]0/ 0.0/;
        $fr1 =~ s/[-]0[.]0/ 0.0/;

        # Warning if no match @ three sig figs.
        my $status = "";
        if ($gr3 ne $fr3) {
            if ($gr2 ne $fr2) {
                if ($gr1 ne $fr1) {
                    $status = " *** ERROR '$gr1' ne '$fr1'";
                    $nerrors++;
                } else {
                    $status = " *** WARNING only match to 1 sig fig";
                    $nwarnings++;
                }
            } else {
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
