#!/usr/bin/python3
import os
import sys

# Turn on ALL_LDBG for extensive debug info
ALL_LDBG = os.getenv("ALL_LDBG", 0)

# E.g. extensive comparison w/ perl version
#    function fgm {
#      fft_golden_model.pl 8 1 > tmp.pl
#      fft_golden_model.py 8 1 > tmp.py
#      diff tmp.pl tmp.py
#    }
#    export ALL_LDBG=1
#    ( c; set -x; fgm )

# Want "round7" scheduler function etc. from "../rtl/fft_scheduler.py"
scriptdir=os.path.dirname(os.path.realpath(__file__))
FFTGEN_DIR=os.path.dirname(scriptdir)
sys.path.append(f"{FFTGEN_DIR}")
from rtl.fft_scheduler import fft_schedule

# test_fft(8, 1);

# Example usage, from golden_test.p[ly]:
# fft_golden_model.py 8 1
# ------------------------------------------------------------------------
# // Scheduling algorithm='round7'
# 
# // swizzler algorithm 'round7'
# //  0. Index ( 0, 1) => banks ( 0, 1),  twid(c,s) = ( 1.000,  0.000)
# //  1. Index ( 2, 3) => banks ( 2, 3),  twid(c,s) = ( 1.000,  0.000)
# //  2. Index ( 4, 5) => banks ( 0, 1),  twid(c,s) = ( 1.000,  0.000)
# //  3. Index ( 6, 7) => banks ( 2, 3),  twid(c,s) = ( 1.000,  0.000)
# //  4. Index ( 0, 2) => banks ( 0, 2),  twid(c,s) = ( 1.000,  0.000)
# //  5. Index ( 4, 6) => banks ( 1, 3),  twid(c,s) = ( 1.000,  0.000)
# //  6. Index ( 5, 7) => banks ( 0, 2),  twid(c,s) = ( 0.000, -1.000)
# //  7. Index ( 1, 3) => banks ( 1, 3),  twid(c,s) = ( 0.000, -1.000)
# //  8. Index ( 0, 4) => banks ( 0, 1),  twid(c,s) = ( 1.000,  0.000)
# //  9. Index ( 2, 6) => banks ( 2, 3),  twid(c,s) = ( 0.000, -1.000)
# // 10. Index ( 1, 5) => banks ( 0, 1),  twid(c,s) = ( 0.707, -0.707)
# // 11. Index ( 3, 7) => banks ( 2, 3),  twid(c,s) = (-0.707, -0.707)
#        0    4.000     0.000
#        1    1.000    -2.414
#        2    0.000     0.000
#        3    1.000    -0.414
#        4    0.000     0.000
#        5    1.000     0.414
#        6    0.000     0.000
#        7    1.000     2.414
# ------------------------------------------------------------------------

if (len(sys.argv) == 3): [ npoints, nunits ] = map(int,sys.argv[1:])
else:
    scriptname = sys.argv[0];
    print("")
    print("Usage:")
    print(f"    {scriptname} <npoints> <nunits>")
    print("")
    print("Example:")
    print(f"    {scriptname} 8 1")
    exit(13)
if ALL_LDBG: print(f"npoints={npoints}, nunits={nunits}")

def main(): test_fft(npoints, nunits)

##############################################################################
def test_fft(npoints,nunits):
    # npoints should be one of {8, 16, 32, ... 1024}
    # nunits  should be 1, 2 or 4

    # Test array is bit-reversed version of e.g. (for npoints=8)
    #   ar = (1, 1, 1, 1,  0, 0, 0, 0);
    #   ai = (0, 0, 0, 0,  0, 0, 0, 0);
    #
    # which looks like this:
    #   ar = (1, 0, 1, 0,  1, 0, 1, 0);
    #   ai = (0, 0, 0, 0,  0, 0, 0, 0);

    a = build_test_array(npoints)

    # Unpack real and imaginary portions
    ar = a[ 0       :   npoints  ]
    ai = a[ npoints : 2 * npoints]
    # printvals($npoints, @ar, @ai); print "\n";

    # Now replace test array with its FFT values
    a = do_fft(npoints, nunits, ar, ai)
    ar = a[ 0       :   npoints  ]
    ai = a[ npoints : 2 * npoints]

    # Now look what you've done!
    printvals(npoints, ar, ai)


def build_test_array(npoints):

    # Test array is bit-reversed version of e.g. (for npoints=8)
    #   @ar = (1, 1, 1, 1,  0, 0, 0, 0);
    #   @ai = (0, 0, 0, 0,  0, 0, 0, 0);
    #
    # which looks like this:
    #   @ar = (1, 0, 1, 0,  1, 0, 1, 0);
    #   @ai = (0, 0, 0, 0,  0, 0, 0, 0);

    n2 = int(npoints/2)
    ar = [0]*n2; ai = [0]*n2;

    for i in range (0,npoints,2):
        ar[i:i+1] = [1,0]
        ai[i:i+1] = [0,0]

    return (ar+ai)


def do_fft(npoints, nunits, ar, ai, DBG=0):
    # npoints should be one of {8, 16, 32, ... 1024}
    # nunits  should be 1, 2 or 4
    LDBG = ALL_LDBG

    assert (len(ar) + len(ai)) == (2*npoints), "ERROR bad arg list for do_fft()"

    # Generate FFT info

    #my @fft_info = fft_scheduler::fft_schedule($npoints, $nunits, "reschedule", "");
    # For now, assuming "reschedule" is just asking for trouble...
    # in particular, trouble for npoints=8 and nunits=4

    # fft_info = fft_schedule_round7(npoints, nunits, "", "")
    fft_info = fft_schedule(npoints, nunits, "", "")

    # fft_info parms:
    #     my $npoints    = shift; # length of FFT: must be a power of two
    #     my $nunits     = shift; # Number of butterfly units employed per cycle.
    #     my $reschedule = shift; # "" or any non-zero value e.g. "reschedule_for_conflicts" 
    #     my $TEST       = shift; # No longer used.

    # I guess we don't do this no more
    #   my @fft_info =
    #       $ENV{USE_CRAZY} ?
    #       fft_scheduler::fft_schedule($npoints, $nunits, "reschedule", "") :
    #       fft_scheduler::fft_schedule($npoints, $nunits, "", "") ;

    # BUG/FIXME/TODO maybe later, emulate swizzle and bypass behavior
    # Maybe later, emulate swizzle and bypass behavior
    # For now, FFT in place.  Also, serialize all parallel-butt action.

    for cy in range( len(fft_info) ):

        op1 = fft_info[cy]["op1"]
        op2 = fft_info[cy]["op2"]
        ctwid = fft_info[cy]["ctwid"]
        stwid = fft_info[cy]["stwid"]

        (c,s) = (ctwid,stwid);

        if (LDBG):
            print("Using indices (%d,%d), twiddle factors c,s= (%6.3f %6.3f)" % (op1, op2, c, s))

        in1_real = ar[op1];     in2_real = ar[op2];
        in1_imag = ai[op1];     in2_imag = ai[op2];

        if (LDBG):
            print("in1(r,i) = (%6.3f, %6.3f)" % (in1_real, in1_imag))
            print("in2(r,i) = (%6.3f, %6.3f)" % (in2_real, in2_imag))
            print("")
            print("twc = %6.3f" % c);
            print("tws = %6.3f" % s);
            print("")

        t1 = c * in2_real - s * in2_imag
        t2 = s * in2_real + c * in2_imag

        # Ugh
        # In python, (-1.0 * 0.0) = -0.0
        # In perl,   (-1.0 * 0.0) =  0.0
        # So we do this to compare w/ equivalent perl model :(
        if (t1 == -0.0): t1 = 0.0
        if (t2 == -0.0): t2 = 0.0

        if (LDBG):
            print("t1 = %6.3f" % t1);
            print("t2 = %6.3f" % t2);
            print("")

        out2_real = in1_real - t1;
        out2_imag = in1_imag - t2;

        ar[op2] = out2_real;
        ai[op2] = out2_imag;

        out1_real = in1_real + t1;
        out1_imag = in1_imag + t2;

        ar[op1] = out1_real;
        ai[op1] = out1_imag;

        if (LDBG):
            print("out1(r,i) = (%6.3f, %6.3f)" % (out1_real, out1_imag))
            print("out2(r,i) = (%6.3f, %6.3f)" % (out2_real, out2_imag))
            print("------------------------------------------------------------------------------")

    return (ar+ai)


def printvals(npoints, ar, ai):
    for i in range(npoints):
        #printf("        $i-real = %f, $i-comp=%f\n", getreal($i), getcomp($i));
        #printf("        $i-real= %9.6f, $i-comp= %9.6f\n", getreal($i), getcomp($i));
        #printf("        $i-real= %6.3f, $i-comp= %6.3f\n", $ar[$i], $ai[$i]);
        print("    %4d   %6.3f    %6.3f" % (i, ar[i], ai[i]))

main()

