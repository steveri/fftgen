#!/usr/bin/env bash
bn=$(basename $0)  # E.g. 'test-gold.sh'

NOTES="
At the end of a successful test suite it says '47/48 tests PASSED'.
This is correct, b/c one test is SUPPOSED to fail on purpose.
Is this a problem?

TODO:
  - Choose just ONE option, python or perl, and get rid of the other one.
"

HELP="
DESCRIPTION
  Exhaustive test of FFT generator using multiple values for
  <npoints>, <n_butterfly_units>, <sram_type>.

  For each combination, fftgen builds the FFT, runs an RTL simulation
  using predetermined inputs, and compares the ourput to a perl or
  python model of the same FFT using the same inputs. 

OPTIONS
  $bn --python -sim vcs   # You need VCS installed on your system
  $bn --perl   -sim vcs

  $bn --python -sim ver   # This will try to install verilator if it's missing
  $bn --python -sim ver

  $bn --notes    # For more info
"  

# Process command-line args

nargs=$#
if [ "$1" == "--help" ];  then echo "$HELP"; exit   ; fi
if [ "$1" == "--notes" ]; then echo "$NOTES"; exit   ; fi
if [ $nargs -ne 3 ];     then echo "$HELP"; exit 13; fi

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

# Find Genesis2; if it does not exist, install it in /tmp
source $fftgen/bin/setup_genesis.sh

# Need numpy for comparison with python sim maybe
# FIXME/TODO when we get rid of the python option this is no longer necessary.
python -c 'import numpy' || pip install numpy || echo "Could not install numpy, maybe that's okay"

# See if fpu is up to date
# TODO/FIXME this (rtl/fpu_snapshot) should really be a submodule, yes?
clone=/tmp/fpu$$; git clone https://github.com/steveri/fpu $clone
SAME=True; for f in $(cd $clone; \ls *.v); do
    diff {$clone,$fftgen/rtl/fpu_snapshot}/$f || SAME=
done
[ "$SAME" ] || echo 'WARNING rtl/lib does not match info in latest fpu repo'
test -d /tmp/fpu$$ && /bin/rm -rf /tmp/fpu$$

# Prepare to issue caveats in case of verilator version
function verilator_caveats {
    printf "\n------------------------------------------------------------------------"
    printf "\nNote that verilator tests do not (yet) work for double-pump sram."
    printf "\nThis appears to be a verilator bug; all tests pass for vcs (trust me!)"
    printf "\n------------------------------------------------------------------------\n\n"
}

# Find verilator; if it's not there, try and install it
echo $* | grep ver > /dev/null && is_verilator=True || is_verilator=
if [ "$is_verilator" ]; then
    if ! which verilator; then
        echo 'WARNING Looks like you do not have verilator on your system'
        echo 'WARNING I will attempt to install it for you'
        echo sudo apt-get install verilator
        whoami || echo okay
        who am i || echo okay
        (cd; pwd; apt-get install verilator) || (cd; pwd; sudo apt-get install verilator)
        if ! which verilator; then
            echo 'ERROR could not install verilator: maybe try like "sudo apt-get install verilator"'
            exit 13
        fi
    fi
    # verilator_caveats; export SKIP_DPUMP=1  # dpump works now maybe woohoo!
fi

# Run the regressions!
(
    mkdir -p $fftgen/regression
    cd $fftgen/regression
    nobuf='stdbuf -oL -eL'
    echo $fftgen/bin/golden_test.sh $*
    $fftgen/bin/golden_test.sh $* \
        |& $nobuf tee test_results.log \
        |  $nobuf egrep 'PASS|FAIL|ERR| failure is allowed'

    # [ "$is_verilator" ] && verilator_caveats
    egrep '^FINAL RESULT.*PASS' test_results.log || exit 13
)
