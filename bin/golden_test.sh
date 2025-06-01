#!/bin/bash
    
cat <<EOF > /dev/null

------------------------------------------------------------------------
# To test vs. csh version, quick test:

c; golden_test.csh 16 1 1port |& tee tmp.csh
cp /tmp/test_16_1_1port.log tmplog.csh

c;  golden_test.sh 16 1 1port |& tee tmp.sh
cp /tmp/test_16_1_1port.log tmplog.sh

c; diff tmp.csh tmp.sh
c; diff -Bb tmplog.csh tmplog.sh


------------------------------------------------------------------------
# To test vs. csh version, full test:

mkdir tmptest; cd tmptest
gtcsh='../golden_test.csh --perl -sim verilator'
gtsh='../golden_test.sh --perl -sim verilator'


i=100
$gtcsh |& head -$i | tee test_results.log.csh$i; \
$gtsh  |& head -$i | tee test_results.log.sh$i
diff -Bb -I '2022$' test_results.log.{csh,sh}$i |& less

$gtcsh | tee test_results.log.csh | egrep 'PASS|FAIL|ERR'; \
$gtsh  | tee test_results.log.sh  | egrep 'PASS|FAIL|ERR' &
diff -Bb -I '2022$' test_results.log.{csh,sh} |& less

EOF


VERBOSE=True
TRAVIS=''

if [ "$1" == "--help" ]; then cat <<EOF

SYNOPSIS
  $0
  $0 8 1 1port
  $0 -sim vcs
  $0 -sim vcs -gt8k
  $0 -sim verilator 128 8 2port

  $0 --python <args>

ARGUMENT SUMMARY
  no arguments  - use standard test suite of 48 programs with npoints=(8,16,32..1024)
  -gt8k         - use extra-large test suite w/ npoints=(2K, 4K, 8K)
  -sim <sim>    - specify simulator to use, either "vcs" or "verilator"
  <pts bts mem> - instead of running a suite, run a single test
  --python      - use python instead of perl to generate and compare results

  where
    <pts> = 8, 16, 32, 64, 128, 256, 512, or 1024

  and
    <bts> = 1, 2, or 4  (butterfly units working in parallel)
    <bts> = 0.5 or 0.25 (one butterfly unit w/ latency of 2 or 4 instead of 1)

  and <mem> is one of:
   "1port" for true single-port SRAM
   "2port" for true dual-port SRAM
   "dpump" for double-pump single-port (virtual 2-port)


DESCRIPTION
  Build one or more FFT designs and test against a golden model.  The
  FFT uses an in-place algorithm, i.e. an n-point FFT requires exactly
  n words of memory. The algorithm is capable of operating with area-
  and energy-saving single-port SRAM without collisions. A fully
  specified FFT (i.e. number of butterflies == n/2) would thus
  complete its transform in (n/2)log2(n) cycles.  For now, however,
  the generator can build at most four butterfly units, and there are
  6 cycles of overhead in each test, so the actual time is
  (n/2)log2(n)/b, where b is the number of butterfly units. I.e. a
  1024-point FFT with one butterfly unit completes its transform in
  5,126 cycles.

HOW-TO
  To run an exhaustive regression test of multiple designs (verilator)
    $0

  To run an exhaustive regression test of multiple designs (vcs)
    $0 -sim vcs

  To build and run a single design:
    $0 <n_points> <n_butterfly_units> <memory_type>

  where
    <n_points> = 8, 16, 32, 64, 128, 256, 512, or 1024
    <n_units> = 1, 2, or 4 (butterfly units, working in parallel)
    <n_units> = 0.5 or 0.25 (one butterfly unit w/ latency of 2 or 4 instead of 1)

  and <memory_type> is one of:
   "1port" for true single-port SRAM
   "2port" for true dual-port SRAM
   "dpump" for double-pump single-port (virtual 2-port)

EXAMPLES
  32-point in-place FFT using two butterfly units and one bank of single-port DRAM
    $0 32 2 1port

  Fully-specified 32-point FFT should complete in log2(32) or five cycles
    $0 32 32 1port

EOF
exit
fi

PYTHON_OR_PERL="PERL"
if [ "$1" == "--python" ]; then
    PYTHON_OR_PERL="PYTHON" ; shift
elif [ "$1" == "--perl" ]; then
    PYTHON_OR_PERL="PERL"   ; shift
fi

[ "$DBG" ] || DBG=  # Can override with env var, see?
if [ "$DBG" == 1 ]; then echo PYTHON_OR_PERL = $PYTHON_OR_PERL; fi

# # !!? What the hell is this???
# # I think maybe it was a shortcut for "golden_test -gt8k ... ?"?
# unset gt8k
# if [ "$0:t" == "gt8k.csh") gt8k

# Find main $FFTGEN directory  (script lives in $FFTGEN/bin)
myname=$0
mydir=`dirname $myname`
if [ "$mydir" == "$myname" ]; then mydir=.; fi
# FFTGEN_DIR=`cd $mydir/..; pwd`
FFTGEN_DIR=$mydir/..


# Start in main $FFTGEN directory  (script lives in $FFTGEN/bin)
# cd $FFTGEN_DIR

# Use Makefile in $FFTGEN
MAKEFILE=$FFTGEN_DIR/Makefile
     BIN=$FFTGEN_DIR/bin

tests=()
ntests=1

# simulator can be either vcs or verilator
SIMULATOR='verilator'
if [ "$1" == "-sim" ]; then
  SIMULATOR=$2; shift; shift;
fi

# Convenient abbrev ver == verilator
[ "$SIMULATOR" == "ver" ] && SIMULATOR=verilator

if [ "$SIMULATOR" == "verilator" ]; then
  simlog="fft.log"

elif [ "$SIMULATOR" == "vcs" ]; then
  simlog="simv.log"

else
  echo "ERROR What is -sim '$SIMULATOR'? Can only handle -sim 'vcs' or 'verilator'"
  exit
fi

# Quick check will save heartache later
w=`which $SIMULATOR`; if [ "$w" == "" ]; then
  echo "ERROR looks like you do not have '$SIMULATOR' in your path"
  exit
fi

# Default swizz alg is 'round7' unless otherwise specified e.g. with
#    $0 -alg 'mod_bn_combo'
swizzalg='round7'
if [ "$1" == "-alg" ]; then
  swizzalg=$2
  shift; shift;
fi

# If a fourth arg is specified, that will be the swizzler algorithm (e.g. "round7" or "mod_bn_combo")
if [ $# == 4 ]; then
  swizzalg=$4
  argv=($1 $2 $3)
fi

# Want 'round7' to be the default; should only have to set env var if ne 'round7'
if [ "$swizzalg" != 'round7' ]; then
  echo "Setting env var SCHED_ALG='$swizzalg'" 
  export SCHED_ALG=$swizzalg
fi

##############################################################################
if [ $"DBG" == 1 ]; then
    echo ''; set | egrep 'DBG'
    echo ''; set | egrep 'MAKEFILE|BIN|FFTGEN_DIR'
    echo ''; set | egrep 'SIMULATOR|simlog|^w='
    echo ''; set | egrep 'swizzalg|SCHED_ALG'
    echo ''
fi
##############################################################################

# For one-off tests specified on command line e.g. "golden_test.sh 8 1 1port"
if [ $# == 3 ]; then
    tests=("$1 $2 $3")
    if [ $DBG ]; then
        echo "FOUND one-off test '${tests[@]}'"
    fi

else
    # Do full suite of tests
    npoints_array=(8 16 32 64 128 256 512 1024)

    # Use "-abbrev" to run only the short tests. See below for '-gt8k'
    [ "$1" == "-abbrev" ] && npoints_array=(8 16 32)
    [ "$1" == "-gt8k"   ] && gt8k=1

    # To infinity...and BEYOND!
    # if [ $?gt8k)            npoints_array=(8 2048 4096 8192)
    [ "$gt8k" == 1 ] && npoints_array=(8 8192 4096 2048)

    # Throw in a "dpump" here and there.
    dpump=0

    for npoints in ${npoints_array[@]}; do
        for nports in 1port 2port; do
            # ("1port" => "TRUE_1PORT"; "2port" => "1PORT_DBLPUMP")
            npsave=$nports
            for nunits in 1 2 4; do

                # Throw in a "dpump" here and there
                ((dpump++))
                if [ $dpump == 5 ]; then
                    nports="dpump"
                    dpump=0
                else
                    nports=$npsave
                fi

               tests=("${tests[@]}" "$npoints $nunits $nports")
            done
            tests=("${tests[@]}" "hline 2 3")
        done
    done

    if [ "$DO_2PORT_ONLY" ]; then
        # Delete all tests except sram=2port
        # This hack exists b/c Verilator only works on 2port srams
        t2=$(printf '%s\n' "${tests[@]}" | egrep '2port|hline')
        mapfile -t tests < <(echo "${t2[@]}")
    fi

    ntests=0;
    echo "Tests to run:"
    for t in "${tests[@]}"; do
      if [ "$t" == "hline 2 3" ]; then
        echo ""
       #echo "   -----------------------------------------"
      else
        echo "   $t" | awk '{ printf("%16s",$0); }'
        # echo -n " $t"
        ((ntests++))
      fi
    done
    echo Total $ntests tests.
    echo

    echo ==============================================================================
    # Individual tests INSTEAD OF "alltests"
    # tests=("512 1 2port")
    # tests=("8 1 2port" "8 1 1port")

    # Individual tests IN ADDITION TO "alltests"
    # tests=("8 2 1port" "${tests[@]}")

fi

if [ $"DBG" == 1 ]; then
    echo '------------------------------------------------------------------------'
    set | egrep 'npoints_array|^gt8k|^dpump'
    set | egrep '^tests'
    echo '------------------------------------------------------------------------'
fi


##############################################################################
# DO_TEST:

summfile=/tmp/golden-test_summary.$$
test -e $summfile && /bin/rm $summfile

for t in "${tests[@]}"; do
  a=($t)        # String => array e.g. "8 4 1port" => (8,4,"1port")
  npoints=${a[0]}
   nunits=${a[1]}
   nports=${a[2]}

  [ "$nports" == "1port" ] && sram="TRUE_1PORT";
  [ "$nports" == "2port" ] && sram="TRUE_2PORT";
  [ "$nports" == "dpump" ] && sram="1PORT_DBLPUMP";

  if [ $npoints == "hline" ]; then
    echo
    echo "TR ========================================================================"
    echo
    continue
  fi

  # Start with a clean slate
  # cd $FFTGEN_DIR
  test -e $simlog && /bin/rm $simlog

  # Build a readable suffix that describes what test we're doing.
  # parms="top_fft.n_fft_points=$npoints top_fft.units_per_cycle=$nunits top_fft.SRAM_TYPE=$sram top_fft.swizzle_algorithm=$swizzalg"
         parms="top_fft.n_fft_points=$npoints"
  parms="$parms top_fft.units_per_cycle=$nunits"
  parms="$parms top_fft.SRAM_TYPE=$sram"
  parms="$parms top_fft.swizzle_algorithm=$swizzalg"
  parms="$parms top_fft.SIMULATOR=$SIMULATOR"
  sfx=${npoints}_${nunits}_${nports}
  tmp=/tmp/test_$sfx.log

  if [ $"DBG" == 1 ]; then
    echo '------------------------------------------------------------------------'
    set | egrep '^a='
    set | egrep '^npoints='
    set | egrep '^nunits='
    set | egrep '^nports='
    set | egrep '^sram='
    echo ''
    set | egrep '^parms='
    set | egrep '^sfx='
    set | egrep '^tmp='

    echo '------------------------------------------------------------------------'
  fi

  # "8_4_1port" is not supported (at least for now)
  if [ $sfx == "8_4_1port" ]; then
      echo "$sfx not supported (16 SRAM's for 8 points!?)"; continue
  fi
  [ $sfx == "8_4_1port" ] && echo "*** NOTE $sfx is SUPPOSED to fail! (16 SRAM's for 8 points\!?) ***"

  # Print out date, id info
  date; echo $sfx": npoints=$npoints, nunits=$nunits, sram=$sram; alg=$swizzalg; sim=$SIMULATOR"

  cmd="make -f $MAKEFILE clean gen SIM=$SIMULATOR TOP=fft"

  # Generate the FFT.
  fatal_error=
  dq='"'
  if [ "$VERBOSE" != "" ]; then
    echo "  $cmd GENESIS_PARAMS=$dq$parms$dq" >& $tmp
  fi
  [ $DBG ] && echo "  $cmd GENESIS_PARAMS=$dq$parms$dq"
  $cmd GENESIS_PARAMS="$parms" &>> $tmp || fatal_error=True

  # If FFT generator failed, print out a coherent error message.
  if [ "$fatal_error" ]; then
      echo fatal error
      echo "  ERROR 'make gen' failed. --- $npoints $nunits $nports"

      [ $TRAVIS ] && cat $tmp
      [ $TRAVIS ] && exit 13

      echo "  See $tmp for details"
      echo "  less -r $tmp"
      [ $sfx == "8_4_1port" ] && echo "*** NOTE $sfx is SUPPOSED to fail! (16 SRAM's for 8 points\!?) ***"
      echo
      echo "-------------------------------------------"
      continue
  fi

  # Run the simulation
  # alias mr   make -j 1 run TOP=fft
  alias mr='make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR'
  function mr { make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR; }

  # Duh? Why twice?
  [ $DBG ] && echo "  make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR"
  echo 1. make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR >> $tmp
  mr |& egrep -v '^Makefile' >> $tmp
  echo 2. make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR >> $tmp
  mr |& egrep -v '^Makefile' >> $tmp

  # If "make run" failed, print out a coherent error message.
  if [ ! -e $simlog ]; then
      echo fatal error
      echo "ERROR No $simlog; 'make run' failed? --- $npoints $nunits $nports"
      echo "  See $tmp for details"
      echo "  less -r $tmp"
      echo
      echo "-------------------------------------------"
      continue
  fi

  # DEBUG
  #   echo "  TEMPORARY cp $simlog $simlog.orig FIXME"
  #                     cp $simlog $simlog.orig

  echo ""
  echo "Processing bsr macros in $simlog..."
  echo "  awk -f $BIN/bsr.awk %9.6f < $simlog > $simlog.bsr.tmp"
          awk -f $BIN/bsr.awk %9.6f < $simlog > $simlog.bsr.tmp
  echo "  mv $simlog.bsr.tmp $simlog"
          mv $simlog.bsr.tmp $simlog
  echo ""

  ########################################################################
  # Stats: ncycles, nwrites.
    n_sram_writes=`egrep '^SRAM.*Wrote' $simlog | wc -l`
  n_bypass_writes=`egrep 'Bypass.*wrote' $simlog | wc -l`
  ((nwrites = $n_sram_writes + $n_bypass_writes))

  if [ $"DBG" == 1 ]; then
    echo '------------------------------------------------------------------------'
    set | egrep '^n_sram'
    set | egrep '^n_bypass'
    set | egrep '^nwrites'
    echo '------------------------------------------------------------------------'
  fi

  ncycles=`awk -f $BIN/process_test5.awk $simlog | awk '/FFT took/{print $3}'`

  echo "$nwrites writes ($n_bypass_writes bypass writes), $ncycles cycles"

  ########################################################################
  # Results: first and last  lines (why?)

  lastline=2
  [ $npoints == 16 ] && lastline=3
  cat $simlog \
    | awk -f $BIN/process_test5.awk \
    | sed -n '/TEST5 FINAL/,$p'\
    | egrep '^(ix00|ix07|ix15)' | sed -n "1p;${lastline}p"

  ########################################################################
  # Lint errors?
  egrep '^Lint' $tmp | awk '{print $0 "'" --- $npoints $nunits $nports"'"; }'

  # Verilator lint problems look like this:
  # "%Warning-SYNCASYNCNET: genesis_verif/top_fft.v:356: ... Location of sync usage"
  egrep '^%Warning' $tmp \
    | sed 's/^%Warning-/Lint /' \
    | awk '{print $0 "'" --- $npoints $nunits $nports"'"; }'

  keep_abbrev=1
  if [ "$keep_abbrev" ]; then
    echo ""
    echo "Keeping first 300 lines ONLY of $tmp"
    wc -l $tmp
    head -n 300 $tmp > $tmp.0
    mv $tmp.0 $tmp
    wc -l $tmp
    echo ""
  else
    # FIXME maybe want a --keep option or something for debugging
    echo ""
    echo "Deleting tmp file $tmp b/c OMG it's HUGE"
    /bin/ls -l $tmp
    /bin/rm $tmp
    echo ""
  fi

  ########################################################################
  # Now check against the golden model.
  # Save results in a summary file.

  golden_test=$BIN/golden_test.pl
  [ $PYTHON_OR_PERL == "PYTHON" ] && golden_test=$BIN/golden_test.py

  echo ''
  # Note "make gen" deletes all logfiles *.log in "." (should I fix that?)
  logfile="/tmp/golden_test_${npoints}_${nunits}_${nports}.log"
#   $BIN/golden_test.pl $simlog $npoints $nunits $nports
  echo $PYTHON_OR_PERL $golden_test $simlog $npoints $nunits $nports
  echo ''
  $golden_test $simlog $npoints $nunits $nports \
    | tee $logfile | egrep '^PASS|^FAIL|ERROR|WARNING|See|less' \
    | sed 's/\(^ERROR.*\)/\1 --- '"$npoints $nunits $nports/"\
    | sed "s/^\(.*\)/TR \1 ($SIMULATOR)/" | tee -a $summfile

  # "TR" => "Test Result"
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR For more info:"    | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR     less $logfile" | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "       less $logfile" | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR "                  | tee -a $summfile

  # Check for problems in the log file; it's important to have errors AFTER warnings, right?
  egrep -i 'warn'        $simlog | sed "s/\(.*\)/${simlog}: \1/" | tee -a $summfile
  egrep -i 'fatal|error' $simlog | sed "s/\(.*\)/${simlog}: \1/" | tee -a $summfile

  echo "-------------------------------------------"

done

if [ ! -e $summfile ]; then
  echo "ERROR golden_test.sh - no summary file generated"
  exit 13
fi

npass=`grep PASS $summfile | wc -l`
echo "$npass/$ntests tests PASSED"
echo "    (NOTE 47/48 pass is normal because '8 4 1' not supported.)"
echo

if [ $ntests == 48 ]; then
    if [ $npass != 47 ]; then
        echo "ERROR golden_test.sh - should be 47/48 passes"
        exit 13
    fi
elif [ $npass != $ntests ]; then
    echo "ERROR golden_test.sh - test(s) failed"
    exit 13
fi

echo Warnings:
grep -i warn $summfile || echo "   (no warnings found.)"
echo

echo Errors:
grep -i err $summfile || echo "   (no errors found.)"
echo

# echo "Result summary is here: '$summfile'"
/bin/rm $summfile
echo "NOTE did not keep result summary file '$summfile'"

# echo ==============================================================================
# cat $summfile
# echo ==============================================================================
exit





##############################################################################
## BOOKMARK ##################################################################
##############################################################################
if [ $"DBG" == 1 ]; then
    echo '------------------------------------------------------------------------'
    set | egrep '^golden_test'
    echo '------------------------------------------------------------------------'
fi
exit
##############################################################################
##############################################################################
##############################################################################


