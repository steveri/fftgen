#!/bin/bash

# Playspace (remember to delete later):
tmpdir=`mktemp -d /tmp/fftgen_daily_regressions.XXX` || exit
cd $tmpdir || exit

  # Standard regressions, vcs
  test=vcs_std; echo "TEST $test"
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=vcs | tee ../$test.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

  # Extended regressions, vcs
  test=vcs_ext; echo "TEST $test"
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=vcs TEST_SUITE=-gt8k | tee ../$test.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

  # Extended regressions, verilator
  test=ver_ext; echo "TEST $test"
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=verilator TEST_SUITE=-gt8k | tee ../$test.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

  # Standard regressions, verilator (redundant w/travis)
  test=ver_std; echo "TEST $test"
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=verilator | tee ../$test.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

# Summarize
echo "------------------------------------------------------------------------"
/bin/ls -l *.log
for log in `/bin/ls *.log`; do
  echo $log
  egrep -i 'pass|fail|err' $log
  echo ""; echo ""; echo ""
done


# Clean up
cd $tmpdir/..; /bin/rm -rf $tmpdir
