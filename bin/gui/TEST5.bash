#!/bin/bash
## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
#!/bin/bash
# set -x

filter_test() {
  egrep 'Running|FFT took|ix.*Wrote' \
  | awk '/Running|took/{print} /^ix/{last=$0} END{print $0}'\
  | sed 's/Running.*for //'\
  | sed 's/ running on/,/'\
  | sed 's/butterfly units./butts: /'\
  | sed 's/FFT took //'\
  | sed 's/to complete.*//'\
  | sed 's/: SRAM.*<= //'\
  | sed 's/8 FFT/ 8 FFT/'\
  | sed 's/0.5 butt/0.5  butt/'\
  | sed 's/\([124]\) butt/\1    butt/'\
  | sed 's/^\([0-9]\) cy/  \1 cy/'\
  | sed 's/^\([0-9][0-9]\) cy/ \1 cy/'\
  | awk '{printf $0}'
  
  echo
}

do_test() {
  npoints=$1
  nbutts=$2

  echo "-------------------------------------------------------------------------"
  echo "Running TEST5 for $npoints FFT points running on $nbutts butterfly units."
  echo ""

  # declare -i points_per_butt=$npoints/$nbutts;
  # scale=0 means zero decimal places (i.e. integer)
  points_per_butt=$(echo "scale=0; $npoints/$nbutts" | bc -l)

#  if `test $points_per_butt -lt 4`; then
#     echo "Yeah, that don't work.  Need at least four FFT points per butterfly unit.";
#     echo
#     return;
#  fi


  echo "cd $CHIPGEN/fftgen"
  cd $CHIPGEN/fftgen

  ##############################################################################
  #make -j 1 clean gen TOP=fft GENESIS_PARAMS="$genparms" >& /tmp/tmp.makegen.log

  gencmd="make -j 1 clean gen TOP=fft"
#  genparms="top_fft.n_fft_points=${npoints} top_fft.test_mode=TEST5"
  genparms="top_fft.test_mode=TEST5 top_fft.n_fft_points=${npoints} top_fft.units_per_cycle=${nbutts}"
  echo "$gencmd GENESIS_PARAMS='$genparms' >& /tmp/tmp.makegen.log"
  $gencmd GENESIS_PARAMS="$genparms" >& /tmp/tmp.makegen.log
  
  echo "";
  egrep -i 'warn|err' /tmp/tmp.makegen.log;
  echo ""

  ##############################################################################
  #make -j 1 run TOP=fft

  runcmd="make -j 1 run TOP=fft"
  echo "$runcmd"
  touch tmp.makerun.log
  ($runcmd) >& tmp.makerun.log
  echo ""; egrep -i 'warn|err' tmp.makerun.log;  echo ""

  ##############################################################################
  # Process test5 output and make it easily understandable.

  echo 'cat simv.log | awk -f bin/process_test5.awk | sed -n "/TEST5 FINAL/,$p"'
  echo
  cat simv.log | awk -f bin/process_test5.awk | sed -n '/TEST5 FINAL/,$p'

  if `test $npoints -eq 8`; then
cat << eof
------------------------------------------------------------
Desired outcome was:

           X              FFT X 
    ( 1.000, 0.000) ( 4.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-2.414)
    ( 1.000, 0.000) ( 0.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-0.414)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 0.414)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 2.414)

eof
  fi
}

#cat << eof
#
#Choose your test:
#
#  1.  8 fft points, 1 butterfly unit
#  2.  8 fft points, 2 butterfly units
#  3.  8 fft points, 4 butterfly units
#  4. 16 fft points, 1 butterfly unit
#  5. 16 fft points, 2 butterfly units
#  6. 16 fft points, 4 butterfly units
#  7. All six tests
#
#eof

fp=(" 8" " 8" " 8" " 8"  " 8"  16   16   16   16    16)
bu=(  1    2    4  0.5  0.25    1    2    4  0.5  0.25)

if `test "$1" = "-a"`; then
  echo RUN ALL TESTS
  echo
  echo -n "0. "; do_test ${fp[0]} ${bu[0]} | filter_test;
  echo -n "7. "; do_test ${fp[7]} ${bu[7]} | filter_test;
  echo
  echo -n "4. "; do_test ${fp[4]} ${bu[4]} | filter_test;
  echo -n "3. "; do_test ${fp[3]} ${bu[3]} | filter_test;
# echo
  echo -n "0. "; do_test ${fp[0]} ${bu[0]} | filter_test;
  echo -n "1. "; do_test ${fp[1]} ${bu[1]} | filter_test;
  echo
  echo -n "9. "; do_test ${fp[9]} ${bu[9]} | filter_test;
  echo -n "8. "; do_test ${fp[8]} ${bu[8]} | filter_test;
  echo -n "5. "; do_test ${fp[5]} ${bu[5]} | filter_test;
  echo -n "6. "; do_test ${fp[6]} ${bu[6]} | filter_test;
  echo -n "7. "; do_test ${fp[7]} ${bu[7]} | filter_test;
  exit
fi

cat << eof

Choose your test:

  0. ${fp[0]} fft points, ${bu[0]} butterfly unit
  1. ${fp[1]} fft points, ${bu[1]} butterfly unit
  2. ${fp[2]} fft points, ${bu[2]} butterfly units
  3. ${fp[3]} fft points, ${bu[3]} butterfly units
  4. ${fp[4]} fft points, ${bu[4]} butterfly unit

  5. ${fp[5]} fft points, ${bu[5]} butterfly units
  6. ${fp[6]} fft points, ${bu[6]} butterfly units
  7. ${fp[7]} fft points, ${bu[7]} butterfly units
  8. ${fp[8]} fft points, ${bu[8]} butterfly units
  9. ${fp[9]} fft points, ${bu[9]} butterfly units

  a. All ten tests

eof

echo "";
echo -n "Test number?  "; read answer; echo ""

if `test "$answer" = ''`; then
  echo "Running default test 0";
  answer=0;
else
  echo "You picked test number $answer"
fi

echo ""

case "$answer" in
  (0) { do_test ${fp[0]} ${bu[0]}; exit; };;
  (1) { do_test ${fp[1]} ${bu[1]}; exit; };;
  (2) { do_test ${fp[2]} ${bu[2]}; exit; };;
  (3) { do_test ${fp[3]} ${bu[3]}; exit; };;
  (4) { do_test ${fp[4]} ${bu[4]}; exit; };;
  (5) { do_test ${fp[5]} ${bu[5]}; exit; };;
  (6) { do_test ${fp[6]} ${bu[6]}; exit; };;
  (7) { do_test ${fp[7]} ${bu[7]}; exit; };;
  (8) { do_test ${fp[8]} ${bu[8]}; exit; };;
  (9) { do_test ${fp[9]} ${bu[9]}; exit; };;
  (a) {
        do_test ${fp[0]} ${bu[0]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[7]} ${bu[7]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[1]} ${bu[1]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[2]} ${bu[2]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[3]} ${bu[3]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[4]} ${bu[4]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[5]} ${bu[5]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[6]} ${bu[6]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[7]} ${bu[7]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[8]} ${bu[8]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        do_test ${fp[9]} ${bu[9]}; echo ""; echo -n "Continue?  "; read answer; echo "";
        exit;
   };;
esac

echo "Choice '$answer' not supported; try again."

exit

#  (1) { do_test  8 1; exit; };;
#  (1) { do_test  8 0.5; exit; };;
#  (3) { do_test  8 4; exit; };;
#  (4) { do_test 16 1; exit; };;

#  (7) {
#        do_test  8 1; echo ""; echo -n "Continue?  "; read answer; echo "";
#        do_test  8 0.5; echo ""; echo -n "Continue?  "; read answer; echo "";
#        do_test  8 0.25; echo ""; echo -n "Continue?  "; read answer; echo "";
#        do_test  8 2; echo ""; echo -n "Continue?  "; read answer; echo "";
#        do_test  8 4; echo ""; echo -n "Continue?  "; read answer; echo "";
#        do_test 16 1; echo ""; echo -n "Continue?  "; read answer; echo "";
#        exit;
#      };;


do_test 8


echo




##############################################################################
# TRASH ######################################################################
##############################################################################
failed() {
  failfile=$1;
  echo ""; echo "make FAILED:";  echo ""
  egrep -i 'warn|err' $failfile; echo ""
  exit -1
}

#echo '------------------------------------------------------------------------------'
#do_test 64
#echo '------------------------------------------------------------------------------'
#do_test 16
#echo ''

#################################################################################
## MIT License
## 
## Copyright (c) 2013 Stephen E. Richardson and Stanford University
## 
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is
## furnished to do so, subject to the following conditions:
## 
## The above copyright notice and this permission notice shall be included in all
## copies or substantial portions of the Software.
## 
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IM-
## PLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
## FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
## COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
## IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNEC-
## TION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
## 
## For more information please contact
## Stephen E. Richardson  steveri@stanford.edu (Stanford University)
## Prof. Mark Horowitz   horowitz@stanford.edu (Stanford University)
#################################################################################
