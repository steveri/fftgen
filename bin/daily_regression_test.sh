#!/bin/bash

# Playspace (remember to delete later):
tmpdir=`mktemp -d /tmp/fftgen_daily_regressions.XXX` || exit
cd $tmpdir || exit

  # Standard regressions, vcs
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=vcs | tee ../vcs_std.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

  # Extended regressions, vcs
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=vcs TEST_SUITE=-gt8k | tee ../vcs_ext.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

  # Extended regressions, verilator
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=verilator TEST_SUITE=-gt8k | tee ../ver_ext.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

  # Standard regressions, verilator (redundant w/travis)
  git clone https://github.com/steveri/fftgen; cd fftgen
  source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
  make regress SIM=verilator | tee ../ver_std.log
  cd ..; /bin/rm -rf fftgen
  echo ""; echo ""; echo ""

# Clean up
cd $tmpdir/..; /bin/rm -rf $tmpdir
