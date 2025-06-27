#!/usr/bin/env bash
bn=$(basename $0)  # E.g. 'test-gold.sh'
NOTES='
Q. "-gold" runs "golden_test" and "-comp" runs "fft_golden_model".
   How are they different?

A. Given a set of parameters <npoints> <n_butterfly_units> <sram_type>,
   "fft_golden_model" uses a perl or python model to simulate the
   fftgen algorithm and produce test results.

   Given a log file from an fftgen run, "golden_test" calls
   "fft_golden" model to produce a set of simulated test results
   and checks to see that they match the results in the given log.

TODO
- Choose just ONE, python or perl, and get rid of the other one.
- Should probably be perl, which is required for Genesis2 already.
'

HELP="
DESCRIPTION
  We have two fftgen simulators 'fft_golden_model', one python-based and one perl.
  This checks that they both get similar answers, and also checks that the answer
  matches that from a previously-built fftgen run.

  Results appear in log files tmp.py and tmp.pl.

  Note: this is not a functional test of the fftgen generator, no RTL is generated.

OPTIONS
  $bn --comp16  # Verify perl and python models get same answer for 16-point FFT
  $bn --gold8   # Build and test an 8-point fft, compare to cached fftgen results
  $bn --notes   # Detailed notes about the test(s) and how they work
"  

# Process command-line args

DO_GOLD= ; DO_COMP=
arg1="$1"; function argmatch { expr "$arg1" : "$1" > /dev/null; }
if   argmatch '--comp'; then DO_COMP=True
elif argmatch '--gold'; then DO_GOLD=True
elif argmatch '--note'; then echo "$NOTES"; exit
elif argmatch '--help'; then echo "$HELP"; exit
else
    echo "$HELP"; exit 13
fi

# Helper function, finds home of fftgen repo

function where_this_script_lives {

  local cmd="$0"    # Is script being executed or sourced?
  [ "${BASH_SOURCE[0]}" -ef "$0" ] || cmd="${BASH_SOURCE[0]}" 

  local scriptpath=`realpath $cmd`       # Full path of script e.g. "/foo/bar/baz.sh"
  local scriptdir=${scriptpath%/*}       # Script dir e.g. "/foo/bar"
  scriptdir=$(cd $scriptdir; pwd)       # Get abs path instead of rel
  [ "$scriptdir" == `pwd` ] && scriptdir="."
  echo $scriptdir
}
test=`where_this_script_lives`
fftgen=$(cd $test/..; pwd)

# Need numpy for python part of perl v. python tests
# FIXME/TODO when we get rid of the python option this is no longer necessary.
python -c 'import numpy' || pip install numpy || echo "Could not install numpy, maybe that's okay"

##########################################################################
# --gold  =>  8-point fft with summary results
# Simulate the fft and compare to a previously-generated fftgen result log.
# Do the same using both python and perl and verify both get same correct answer.
# Note this is NOT a functional test of fftgen, no RTL is produced.
# FIXME/TODO when we get rid of the python option, we no longer need the perl v. py part.

if [ "$DO_GOLD" ]; then
    echo 'PERL v. PYTHON quick test (golden_test.{pl.py})'
    set -x
    result=PASS
    unset ALL_LDBG
    gunzip -c $fftgen/examples-rtl/8.1.1port/fft.log.gz > tmp.fftlog
    $fftgen/bin/golden_test.pl tmp.fftlog 8 1 2port > tmp.pl || result=FAIL
    $fftgen/bin/golden_test.py tmp.fftlog 8 1 2port > tmp.py || result=FAIL
    set +x

    # echo "PERL                                          PYTHON"
    function hline { seq -s_ $1 | sed 's/[0-9]//g'; }
    printf "\nPERL`hline 47`      PYTHON`hline 45`\n\n"

    diff -Bb --side-by-side -W 110 <(grep . tmp.pl)  <(grep . tmp.py) || result=FAIL
    echo ""
    echo FINAL TEST RESULT: $result
    [ $result == PASS ] || exit 13
fi

##########################################################################
# --comp  =>  16-point fft with full debugging ON
# Simulate the fft and produce results in a log file.
# Compare perl and python results to see if they match.
# All this does is prove that the python and perl models get the same answer.
# FIXME/TODO when we get rid of the python option this is no longer necessary.

if [ "$DO_COMP" ]; then
    echo 'PERL v. PYTHON extended test (ALL_LDBG + fft_golden_model.{pl.py})'
    set -x
    result=PASS
    export ALL_LDBG=1
    $fftgen/bin/fft_golden_model.pl 16 1 > tmp.pl || result=FAIL
    $fftgen/bin/fft_golden_model.py 16 1 > tmp.py || result=FAIL
    set +x
    # Only diff should be that one says "PERL" and one says "PYTHON"
    diff tmp.pl tmp.py -I '^.*PERL$\|^.*PYTHON$' || result=FAIL

    # Print results side by side for comparison

    # diff -Bb --side-by-side -W 80 tmp.pl tmp.py | tail -n 16

    function shape { echo '     -----------------------'; tail -16 $1; }
    pr -h '------------------' -m -t <(shape tmp.pl) <(shape tmp.py)
    echo ""
    echo FINAL TEST RESULT: $result
    [ $result == PASS ] || exit 13
fi
