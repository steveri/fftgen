#!/usr/bin/perl
# Command is "$0"; command-line arguments can be found in array @ARGV
use strict;

#push (@INC, "/home/steveri/fftgen/rtl/");
my $rtldir = mydir("../rtl");  # Script lives in $FFTGEN/bin;
push (@INC, "$rtldir/");       # scheduler lives in $FFTGEN/rtl
require fft_scheduler;

#test_fft(8, 1);

my ($npoints,$nunits);
if (@ARGV == 2) {
    ($npoints,$nunits) = ($ARGV[0], $ARGV[1]);
}
else {
    print "Usage: $0 <npoints> <nunits>\n\n";
    print "Example:\n";
    print "    $0 8 1\n";
    exit(-1);
}
#print "npoints=$npoints, nunits=$nunits\n";

# fft_scheduler::DBG_ON();
test_fft($npoints, $nunits);
exit(0);

##############################################################################
sub test_fft {
    my $npoints = shift; # 8, 16, 32, ... 1024
    my $nunits  = shift; # 1, 2 or 4

    # Test array is bit-reversed version of
    #   @ar = (1, 1, 1, 1,  0, 0, 0, 0);
    #   @ai = (0, 0, 0, 0,  0, 0, 0, 0);
    #
    # which looks like this:
    #   @ar = (1, 0, 1, 0,  1, 0, 1, 0);
    #   @ai = (0, 0, 0, 0,  0, 0, 0, 0);

    my @a = build_test_array($npoints);
    my @ar = @a[0          .. $npoints-1];
    my @ai = @a[$npoints .. 2*$npoints-1];

#    printvals($npoints, @ar, @ai); print "\n";

    # Now replace test array with its FFT values
#    my @a = do_fft($npoints, @ar, @ai);
    my @a = do_fft($npoints, $nunits, @ar, @ai);
    my @ar = @a[0          .. $npoints-1];
    my @ai = @a[$npoints .. 2*$npoints-1];

    # Now look what you've done!
    printvals($npoints, @ar, @ai);
}

sub build_test_array {
    my $npoints = shift;

    # Test array is bit-reversed version of
    #   @ar = (1, 1, 1, 1,  0, 0, 0, 0);
    #   @ai = (0, 0, 0, 0,  0, 0, 0, 0);
    #
    # which looks like this:
    #   @ar = (1, 0, 1, 0,  1, 0, 1, 0);
    #   @ai = (0, 0, 0, 0,  0, 0, 0, 0);

    my @ar = ();
    my @ai = ();

    for (my $i=0; $i < $npoints; $i += 2) {
        ($ar[$i], $ar[$i+1]) = (1, 0);
        ($ai[$i], $ai[$i+1]) = (0, 0);
    }
    return (@ar, @ai);
}

sub do_fft {
    my $npoints = shift; # 8, 16, 32, ... 1024
    my $nunits  = shift; # 1, 2 or 4

    if (@_ != 2*$npoints) { print "ERROR bad arg list for do_fft\n"; exit(-1); }

    my @ar = @_[0          .. $npoints-1];
    my @ai = @_[$npoints .. 2*$npoints-1];
    
    my $LDBG = 0;

    # Generate FFT info
    #my @fft_info = fft_scheduler::fft_schedule($npoints, $nunits, "reschedule", "");

    # For now, assuming "reschedule" is just asking for trouble...
    # in particular, trouble for npoints=8 and nunits=4
    my @fft_info = fft_scheduler::fft_schedule($npoints, $nunits, "", "");

    # BUG/FIXME/TODO maybe later, emulate swizzle and bypass behavior
    # Maybe later, emulate swizzle and bypass behavior
    # For now, FFT in place.  Also, serialize all parallel-butt action.

    for (my $cy=0; $cy < @fft_info; $cy++) {

#        my $stage = $fft_info[$cy]->{stage};
        my $op1 = $fft_info[$cy]->{op1};
        my $op2 = $fft_info[$cy]->{op2};
#        my $bank1 = $fft_info[$cy]->{bank1};
#        my $bank2 = $fft_info[$cy]->{bank2};
        my $ctwid = $fft_info[$cy]->{ctwid};
        my $stwid = $fft_info[$cy]->{stwid};
#        my $access = $fft_info[$cy]->{access};

#        # For nunits==4 (only)
#        my $op1_buffer = $fft_info[$cy]->{op1_buffer};
#        my $op2_buffer = $fft_info[$cy]->{op2_buffer};
#        my $op1_buffer_access = $fft_info[$cy]->{op1_buffer_access};
#        my $op2_buffer_access = $fft_info[$cy]->{op2_buffer_access};

        my ($c,$s) = ($ctwid,$stwid);

        if ($LDBG) {
            printf("Using indices (%d,%d), twiddle factors c,s= (%6.3f %6.3f)\n", $op1, $op2, $c, $s);
        }

        my $in1_real = $ar[$op1];     my $in2_real = $ar[$op2];
        my $in1_imag = $ai[$op1];     my $in2_imag = $ai[$op2];

        if ($LDBG) {
            printf("in1(r,i) = (%6.3f, %6.3f)\n", $in1_real, $in1_imag);
            printf("in2(r,i) = (%6.3f, %6.3f)\n", $in2_real, $in2_imag);
            print  "\n";
            printf("twc = %6.3f\n", $c);
            printf("tws = %6.3f\n", $s);
            print  "\n";
        }

        my $t1 = $c * $in2_real - $s * $in2_imag;
        my $t2 = $s * $in2_real + $c * $in2_imag;

        if ($LDBG) {
            printf("t1 = %6.3f\n", $t1);
            printf("t2 = %6.3f\n", $t2);
            print  "\n";
        }
        # $ar[$op2] = $ar[$op1] - $t1;
        # $ai[$op2] = $ai[$op1] - $t2;
                
        my $out2_real = $in1_real - $t1;
        my $out2_imag = $in1_imag - $t2;

        $ar[$op2] = $out2_real;
        $ai[$op2] = $out2_imag;

        # $ar[$op1] = $ar[$op1] + $t1;
        # $ai[$op1] = $ai[$op1] + $t2

        my $out1_real = $in1_real + $t1;
        my $out1_imag = $in1_imag + $t2;

        $ar[$op1] = $out1_real;
        $ai[$op1] = $out1_imag;

        if ($LDBG) {
            printf("out1(r,i) = (%6.3f, %6.3f)\n", $out1_real, $out1_imag);
            printf("out2(r,i) = (%6.3f, %6.3f)\n", $out2_real, $out2_imag);
            print  "------------------------------------------------------------------------------\n";
        }
    }
    return (@ar,@ai);
}

sub printvals {
    my $npoints = shift;

    my @ar = @_[0          .. $npoints-1];
    my @ai = @_[$npoints .. 2*$npoints-1];

    for (my $i=0; $i < $npoints; $i++) {
        #printf("        $i-real = %f, $i-comp=%f\n", getreal($i), getcomp($i));
        #printf("        $i-real= %9.6f, $i-comp= %9.6f\n", getreal($i), getcomp($i));
        #printf("        $i-real= %6.3f, $i-comp= %6.3f\n", $ar[$i], $ai[$i]);
        printf("    %4d   %6.3f    %6.3f\n", $i, $ar[$i], $ai[$i]);

    }
}

sub mydir {
    my $offset = shift;  # E.g. "../rtl"

    # Return full path of directory where this script lives, offset according to $offset.
    use Cwd 'abs_path';
    my $fullpath = abs_path($0); # Full pathname of script e.g. "/foo/bar/opendesign.pl"

    use File::Basename 'fileparse';
    my ($filename, $dir, $suffix) = fileparse($fullpath);
    return abs_path("$dir/$offset");
}
