#!/bin/bash

DBG=1

# Wh-....where am I?
scriptpath=$0      # E.g. "build_tarfile.sh" or "foo/bar/build_tarfile.sh"
scriptdir=${0%/*}  # E.g. "build_tarfile.sh" or "foo/bar"
if test "$scriptdir" == "$scriptpath"; then scriptdir="."; fi
scriptdir=`cd $scriptdir; pwd`

# egrep gives no output til the end unless use stdbuf
# I.e. will need stdbuf if want to do "tail -f" on regressions running in background
# alias egrep='stdbuf -oL grep -E' # This didn't work, had to inline instead :(

# Where we're running the test from
test_dir=`pwd`
test_log=$test_dir/test.log

# Playspace (remember to delete later):
tmpdir=`mktemp -d /tmp/fftgen_daily_regressions.XXX` || exit
cd $tmpdir || exit

  function do_test {
    testname=$1; SIM=$2; SUITE=$3
    echo TEST $testname begin `date +%H%M`
    # Start each test with a clean slate
    git clone https://github.com/steveri/fftgen; cd fftgen

# TEMPORARY LOCAL FIXUP
echo FIXUP FIXUP FIXUP FIXUP FIXUP FIXUP FIXUP FIXUP
fftgen=/nobackup/steveri/github/fftgen
cp $fftgen/Makefile .
cp $fftgen/bin/daily_regression_summary.awk bin/

      source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
      # make regress $SIM $SUITE | tee $test_dir/test.log | stdbuf -oL egrep 'TEST|PASS|ERR|FAIL|WARN'
      echo make regress $SIM $SUITE
      make regress $SIM "$SUITE"
    cd ..; /bin/rm -rf fftgen
    echo TEST $testname end `date +%H%M`
    echo ""; echo ""; echo ""
  }
  function my_filter {
    tee $1 | stdbuf -oL egrep 'TEST|PASS|ERR|FAIL|WARN'
  }
  # Pipe cleaner
  echo CLEANING THE PIPES
  do_test vcs_std SIM=vcs TEST_SUITE="8 1 1port" | my_filter $test_dir/test.log
#   do_test vcs_std SIM=vcs TEST_SUITE="8 1 1port"

#   # std = standard regression suite, ext = extended regression suite
#   do_test vcs_std SIM=vcs                        | my_filter $test_dir/test.log
#   do_test vcs_ext SIM=vcs       TEST_SUITE=-gt8k | my_filter $test_dir/test.log
#   do_test ver_std SIM=verilator TEST_SUITE=-gt8k | my_filter $test_dir/test.log
#   do_test ver_ext SIM=verilator                  | my_filter $test_dir/test.log

# Summarize and then delete the Big log
egrep 'TEST|PASS|ERR|FAIL|WARN' $test_dir/test.log > $test_dir/summary1.log
echo "------------------------------------------------------------------------"
awk -f $scriptdir/daily_regression_summary.awk < $test_dir/summary1.log |& tee $test_dir/summary2.log

# Send smallest summary to steveri, who cares, w/ pointer to bigger summary
tmpsumfile=/tmp/fft_regression_`date +%y%m%d`
cp $test_dir/summary1.log $tmpsumfile
recipient=steveri
msgfile=$test_dir/mailmsg.txt
cat << EOF > $msgfile
To: $recipient
Subject: fftgen daily regressions

`cat $test_dir/summary2.log`

Log file is here, on `hostname`: $tmpsumfile
EOF
/usr/sbin/sendmail $recipient < $msgfile

# Clean up
if test ! $DBG; then
  cd $tmpdir/..
  /bin/rm -rf $tmpdir
  /bin/rm $test_dir/test.log
  /bin/rm $test_dir/summary[12].log
fi

echo $tmpdir


##############################################################################
# OLD
# Summarize
# /bin/ls -l *.log
# for log in `/bin/ls *.log`; do
#   echo $log
#   egrep -i 'pass|fail|err' $log
#   echo ""; echo ""; echo ""
# done
