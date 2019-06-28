#!/bin/bash

# Wh-....where am I?
scriptpath=$0      # E.g. "build_tarfile.sh" or "foo/bar/build_tarfile.sh"
scriptdir=${0%/*}  # E.g. "build_tarfile.sh" or "foo/bar"
if test "$scriptdir" == "$scriptpath"; then scriptdir="."; fi
scriptdir=`cd $scriptdir; pwd`

# egrep gives no output til the end unless use stdbuf
# I.e. will need stdbuf if want to do "tail -f" on regressions running in background
# alias egrep='stdbuf -oL grep -E' # This didn't work, had to inline instead :(

# Playspace (remember to delete later):
tmpdir=`mktemp -d /tmp/fftgen_daily_regressions.XXX` || exit
cd $tmpdir || exit

  function do_test {
    testname=$1; SIM=$2; SUITE=$3
    echo "TEST $testname"
    # Start each test with a clean slate
    git clone https://github.com/steveri/fftgen; cd fftgen
      source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
      make regress $SIM $SUITE | tee ../test.log | stdbuf -oL egrep 'TEST|PASS|ERR|FAIL|WARN'
    cd ..; /bin/rm -rf fftgen
    echo ""; echo ""; echo ""
  }
  # Standard regressions, vcs
  do_test vcs_std SIM=vcs

  # Extended regressions, vcs
  do_test vcs_ext SIM=vcs TEST_SUITE=-gt8k

  # Extended regressions, verilator
  do_test ver_std SIM=verilator

  # Standard regressions, verilator (redundant w/travis)
  do_test ver_ext SIM=verilator TEST_SUITE=-gt8k

# Summarize and then delete the Big log
egrep 'TEST|PASS|ERR|FAIL|WARN' ../test.log > ../summary1.log
echo "------------------------------------------------------------------------"
awk -f $scriptdir/daily_regression_summary.awk < ../summary1.log |& tee ../summary2.log
/bin/rm ../test.log


# Send smallest summary to steveri, who cares, w/ pointer to bigger summary
tmpsumfile=/tmp/fft_regression_`date +%y%m%d`
cp ../summary1.log $tmpsumfile
recipient=steveri
msgfile=../mailmsg.txt
CAT << EOF > $msgfile
To: $recipient
Subject: fftgen daily regressions

`cat ../summary2.log`

Log file is here, on `hostname`: $tmpsumfile
EOF
/usr/sbin/sendmail $recipient < $msgfile

# Clean up
cd $tmpdir/..; /bin/rm -rf $tmpdir



##############################################################################
# OLD
# Summarize
# /bin/ls -l *.log
# for log in `/bin/ls *.log`; do
#   echo $log
#   egrep -i 'pass|fail|err' $log
#   echo ""; echo ""; echo ""
# done
