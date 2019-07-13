#!/bin/bash

# small_vcs_only=1
small_only=0

# DBG=9
# DBG=1
DBG=0

# Delete temporary files? Or no?
delete_temp_files=true

# After cloning, can update files from local repo
want_local_updates=true
local_repo="/nobackup/steveri/github/fftgen"
local_updates="\
  Makefile \
  bin/do_one_random_test.sh \
  bin/golden_test.csh \
"
function update_from_local_repo {
  if $want_local_updates; then
    echo "WARNING updating some files from local repo"
    for f in $local_updates; do
      echo "WARNING using local file '$f'"
      cp $local_repo/$f $f
    done
    echo
  fi
}

function where_this_script_lives {
  # Where this script lives
  scriptpath=$0      # E.g. "build_tarfile.sh" or "foo/bar/build_tarfile.sh"
  scriptdir=${0%/*}  # E.g. "build_tarfile.sh" or "foo/bar"
  if test "$scriptdir" == "$scriptpath"; then scriptdir="."; fi
  s=`cd $scriptdir; pwd`
  echo $s
}

# Timestamp
time_begin=`date +%H%M%S`
test $DBG -gt 1 && echo "BEGIN_TIME $time_begin"

# Where this script lives
scriptdir=`where_this_script_lives`

# Where we do our work
tmpdir=`mktemp -d /tmp/fftgen_regress.XXX` || exit
cd $tmpdir || exit

  function do_test {
    which_sim=$1; which_test=$2

    # Start each test with a clean slate
    # Oof. Do we really want a new "git clone" for every test!!?
    git clone -q https://github.com/steveri/fftgen
    cd fftgen
      update_from_local_repo;
      source bin/setup_genesis.sh; source bin/setup_vcs_kiwi.sh
      $scriptdir/golden_test.csh -sim $which_sim $which_test |& cat
    cd ..
    if $delete_temp_files;
      then /bin/rm -rf fftgen
      else echo "WARNING not removing working directory '`pwd`/fftgen/'"
    fi
    echo ""; echo ""; echo ""
  }

  ################################################################
  # function random_test {

      # Pick vcs or verilator with equal probability maybe
      test $((RANDOM%2)) -eq 0 && sim=vcs || sim=verilator

      # npoints = (8, 16, 32, ... 8192) (2^3..2^13)
      npoints=$((2**(RANDOM%11+3)))

      # For debug, limit to cmall tests only, npoints = 8, 16, or 32
      test $DBG -gt 1 && echo "DBG npoints limited to l.e. 32"
      test $DBG -gt 1 && npoints=$((2**(RANDOM%4+3)))

      # vcs only
      # test $small_vcs_only -gt 0 && sim=vcs

      # Small tests only
      test $small_only -gt 0 && npoints=$((2**(RANDOM%4+3)))

      # nbutts = (1, 2, 4)
      nbutts=$((2**(RANDOM%3)))

      sram_choice[0]="1port"
      sram_choice[1]="2port"
      sram_choice[2]="dpump"
      i=$((RANDOM%3))
      sram=${sram_choice[$i]}


#       # FIXME verilator doesn't work (yet)
#       sim=vcs
#       sim=verilator

      # E.g. sim="verilator"; npoints=8; nbutts=1; sram="1port"

      tst=`echo $npoints $nbutts $sram | awk '{printf("%4d %2d %s", $1, $2, $3)}'`
      sim3=`expr $sim : '\(...\)'`

      # E.g. tst="   8  1 1port", sim="verilator", sim3="ver"

  # } function random_test
  ################################################################

  # E.g. "vcs    8  1 1port "
  test $DBG -gt 0 && echo "$sim3 $tst "

  log=`pwd`/test.log
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
    | awk '{printf("%s - %3d warnings, %5d lint problems - %8s %3s\n", $1, $2, $3, $4, $5)}'
  test $DBG -gt 0 && echo ""

# CLEAN UP!!!
gtlog=golden_test_${npoints}_${nbutts}_${sram}.log
if $delete_temp_files; then
  /bin/rm -rf $tmpdir
  /bin/rm -rf /tmp/$gtlog
else
  echo "WARNING no cleanup for $tmpdir"
  echo "WARNING no cleanup for /tmp/$gtlog"
fi

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
