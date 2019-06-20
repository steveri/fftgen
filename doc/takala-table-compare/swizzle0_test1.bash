#!/bin/bash

failed() {
  failfile=$1;
  echo ""; echo "make FAILED:";  echo ""
  egrep -i 'warn|err' $failfile; echo ""
  exit -1
}

do_test() {
  fail=0
  npoints=$1;

  echo "Building ${npoints}-point table; compare to Takala paper."
  echo ""

  gencmd="make -j 1 clean gen TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=${npoints}'"
  runcmd="make -j 1       run TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=${npoints}'"

  echo "cd $CHIPGEN/fftgen"
  echo "$gencmd"
  cd $CHIPGEN/fftgen
  ($gencmd) >& tmp.makegen.log || failed tmp.makegen.log

  echo "$runcmd"
  ($runcmd) >& tmp.makerun.log || failed tmp.makerun.log
  echo ""

  bin/swizzle0_buildtable.pl < simv.log
  #echo ""; echo -n "Continue?  "; read answer; echo ""
}

do_test 32
echo '------------------------------------------------------------------------------'
do_test 64
echo '------------------------------------------------------------------------------'
do_test 16
echo ''



  