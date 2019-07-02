#!/bin/bash

# DBG=9
# DBG=1
DBG=0

# Timestamp
time_begin=`date +%H%M%S`
test $DBG -gt 1 && echo "BEGIN_TIME $time_begin"

# Where we're starting
test_dir=`pwd`

# Where this script lives
scriptpath=$0      # E.g. "build_tarfile.sh" or "foo/bar/build_tarfile.sh"
scriptdir=${0%/*}  # E.g. "build_tarfile.sh" or "foo/bar"
if test "$scriptdir" == "$scriptpath"; then scriptdir="."; fi
scriptdir=`cd $scriptdir; pwd`

# Where we do our work
tmpdir=`mktemp -d /tmp/fftgen_regress.XXX` || exit
cd $tmpdir || exit

  function do_test {
    which_sim=$1; which_test=$2

    # Start each test with a clean slate
    # Oof. Do we really want a new "git clone" for every test!!?
    git clone -q https://github.com/steveri/fftgen
    cd fftgen

      if test $DBG -gt 0; then
        ################################################################
        echo TEMPORARY LOCAL FIXUP for debugging - Makefile, summary.awk
        fftgen=/nobackup/steveri/github/fftgen
        cp $fftgen/Makefile .
        cp $fftgen/bin/daily_regression_summary.awk bin/
        ################################################################
      fi

      # Avoid setup warning by ensuring .modules exists
      test -d ~/.modules || mkdir ~/.modules
      source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh

      # Do the test!
      $scriptdir/golden_test.csh -sim $which_sim $which_test |& cat

    cd ..
    /bin/rm -rf fftgen
    echo ""; echo ""; echo ""
  }

  ################################################################
  # function random_test {

      # Pick vcs or verilator with equal probability maybe
      test $((RANDOM%2)) -eq 0 && sim=vcs || sim=verilator

      # npoints = (8, 16, 32, ... 8192) (2^3..2^13)
      npoints=$((2**(RANDOM%10+3)))

      # For debug, limit to cmall tests only, npoints = 8, 16, or 32
      test $DBG -gt 1 && echo "DBG npoints limited to l.e. 32"
      test $DBG -gt 1 && npoints=$((2**(RANDOM%4+3)))

      # nbutts = (1, 2, 4)
      nbutts=$((2**(RANDOM%3)))

      sram_choice[0]="1port"
      sram_choice[1]="2port"
      sram_choice[2]="dpump"
      i=$((RANDOM%3))
      sram=${sram_choice[$i]}


      # FIXME verilator doesn't work (yet)
      sim=vcs

      # E.g. sim="verilator"; npoints=8; nbutts=1; sram="1port"

      tst=`echo $npoints $nbutts $sram | awk '{printf("%4d %2d %s", $1, $2, $3)}'`
      sim3=`expr $sim : '\(...\)'`

      # E.g. tst="   8  1 1port", sim="verilator", sim3="ver"

  # } function random_test
  ################################################################

  # E.g. "vcs    8  1 1port "
  test $DBG -gt 0 && echo "$sim3 $tst "

  log=$test_dir/test.log
  if test $DBG -gt 1; then
    do_test $sim "$tst" |& tee $log
  else
    do_test $sim "$tst" > $log
  fi


  # Collect lints, warnings, pass/fail info
  nlint=`egrep ^Lint $log | wc -l`
  nwarn=`grep -i warn $log | wc -l`
  egrep '^TR PASS' $log > /dev/null && passfail="PASS" || passfail="FAIL"

  # Timestamp
  time_end=`date +%H%M%S`
  test $DBG -gt 1 && echo "END_TIME $time_end"

  # How long did it take, in minutes?
  tdiff=`expr $time_end - $time_begin`
  nsec=`test $tdiff -gt 0 && echo $tdiff || expr 0 - $tdiff`
  nmin=$((nsec/60))
  test $nmin -gt 0 && rtime=${nmin}m || rtime=${nsec}s

  # Today
  date=`date +%y%m%d`

  # first challenge:
  # - build "regress quicktest" with output "vcs 8 1 1port PASS 20m (3 warnings)"

  # echo "$sim $tst - $passfail ${rtime}m - $nwarn warnings, $nlint lint problems"
  # echo "$sim $tst $passfail - $nwarn warnings, $nlint lint problems - $date ${rtime}m"
  # echo "$passfail - $nwarn warnings, $nlint lint problems - $date ${rtime}m"
  echo -n "$sim3 $tst "
  echo $passfail $nwarn $nlint $date $rtime \
    | awk '{printf("%s - %3d warnings, %3d lint problems - %s %s\n", $1, $2, $3, $4, $5)}'
  test $DBG -gt 0 && echo ""


##############################################################################
# NOTES
# 
# how to do aliases in a script e.g. (alias time='/usr/bin/time -f "REALTIME %E"')
# declare -a time=( /usr/bin/time -f "REALTIME %E" )
# "${time[@]}" sleep 3  | sed 's/[:.]/ /g' | awk '{print $(NF-2)}'
# 
#     echo TEST $testname begin `date +%H%M`
#     echo TEST $testname end `date +%H%M`
# 
#        /usr/bin/time -f "REALTIME %E"\
#          $scriptdir/golden_test.csh -sim $which_sim $which_test |& cat
# 
#       # make regress $SIM $SUITE | tee $test_dir/test.log | stdbuf -oL egrep 'TEST|PASS|ERR|FAIL|WARN'
#       # echo make regress $which_sim $which_test
#       # make regress $which_sim "$which_test"
# 
#   function my_filter {
#     tee $1 | stdbuf -oL egrep 'TEST|PASS|ERR|FAIL|WARN'
#   }

  # do_test $sim "$tst" | my_filter $log

# #   # "REALTIME 0:05.00" => "05"
# #   egrep ^REALTIME $log
# #   egrep ^REALTIME $log | sed 's/[:.]/ /g'
# #   egrep ^REALTIME $log | sed 's/[:.]/ /g' | awk '{print $(NF-1)}'
# 
#   rtime=`egrep ^REALTIME $log | sed 's/[:.]/ /g' | awk '{printf("%d", $(NF-1))}'`
# 
