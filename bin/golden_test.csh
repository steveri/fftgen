#!/bin/csh -f
## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.

set VERBOSE

if ("$1" == "--help") then
cat <<EOF

  Build one or more FFT designs and test against a golden model.  The
  FFT uses an in-place algorithm, i.e. an n-point FFT requires exactly
  n words of memory. The algorithm is capable of operating with area-
  and energy-saving single-port SRAM without collisions. A
  fully-specified FFT (i.e. number of butterflies == n/2)
  would thus complete its transform in (n/2)log2(n) cycles.
  For now, however, the generator can build at most four butterfly
  units, and there are 6 cycles of overhead in each test, so the
  actual time is (n/2)log2(n)/b, where b is the number of butterfly
  units. I.e. a 1024-point FFT with one butterfly unit completes its
  transform in 5,126 cycles.

  To run an exhaustive regression test of multiple designs:
    $0

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

  E.g. to build a 32-point in-place FFT using two butterfly units and
  one bank of single-port DRAM:
    $0 32 2 1port

  Example2 fully-specified 32-point FFT should complete in log2(32) or five cycles
    $0 32 32 1port

EOF
exit
endif

# Quick check will save heartache later
set which_vcs = `which vcs`
if ("$which_vcs" == "") then
  echo "ERROR looks like you do not have vcs in your path"
  exit
endif

unset gt8k
if ("$0:t" == "gt8k.csh") set gt8k

# Find main $FFTGEN directory  (script lives in $FFTGEN/bin)
set myname=$0
set mydir=$myname:h
if ("$mydir" == "$myname") set mydir = .
set FFTGEN_DIR = $mydir/..

# Start in main $FFTGEN directory  (script lives in $FFTGEN/bin)
# cd $FFTGEN_DIR

# Use Makefile in $FFTGEN
set MAKEFILE = $FFTGEN_DIR/Makefile
set BIN      = $FFTGEN_DIR/bin

set tests = ()
set ntests = 1

# simulator can be either vcs or verilator
set SIMULATOR = 'vcs'
if ("$1" == "-sim") then
  set SIMULATOR=$2
  shift; shift;
endif


# Default swizz alg is 'round7' unless otherwise specified e.g. with
#    $0 -alg 'mod_bn_combo'
set swizzalg = 'round7'
if ("$1" == "-alg") then
  set swizzalg = $2
  shift; shift;
endif

# If a fourth arg is specified, that will be the swizzler algorithm (e.g. "round7" or "mod_bn_combo")
if ($#argv == 4) then
  set swizzalg = $4
  set argv=($1 $2 $3)
endif

# Want 'round7' to be the default; should only have to set env var if ne 'round7'
if ("$swizzalg" != 'round7') then
  echo "Setting env var SCHED_ALG='$swizzalg'" 
  setenv SCHED_ALG $swizzalg
endif


# For one-off tests specified on command line e.g. "golden_test.csh 8 1 1port"
if ($#argv == 3) then
  set tests = ("$1 $2 $3")
  goto DO_TEST
endif

set npoints_array = (8 16 32 64 128 256 512 1024)

# Use "-abbrev" to run only the short tests.
if ("$1" == "-abbrev") set npoints_array = (8 16 32)

# To infinity...and BEYOND!
# if ($?gt8k)            set npoints_array = (8 2048 4096 8192)
if ($?gt8k)            set npoints_array = (8 8192 4096 2048)

# Throw in a "dpump" here and there.
set dpump=0

foreach npoints ($npoints_array)
    foreach nports ("1port" "2port")    # "1port" => "TRUE_1PORT"; "2port" => "1PORT_DBLPUMP"
        set npsave = $nports
        foreach nunits (1 2 4)

            # Throw in a "dpump" here and there
            @ dpump = $dpump + 1
            if ($dpump == 5) then
                set nports = "dpump"
                set dpump = 0
            else
                set nports = $npsave
            endif

           set tests = ($tests:q "$npoints $nunits $nports")
        end
        set tests = ($tests:q "hline 2 3")
    end
end

set ntests = 0;
echo "Tests to run:"
foreach t ($tests:q)
  if ("$t" == "hline 2 3") then
    echo
   #echo "   -----------------------------------------"
  else
    echo "   $t" | awk '{ printf("%16s",$0); }'
    @ ntests = $ntests + 1
  endif
end
echo Total $ntests tests.
echo

echo ==============================================================================
# Individual tests INSTEAD OF "alltests"
# set tests = ("512 1 2port")
# set tests = ("8 1 2port" "8 1 1port")

# Individual tests IN ADDITION TO "alltests"
# set tests = ("8 2 1port" $tests:q)

##############################################################################
DO_TEST:

set summfile = /tmp/golden-test_summary.$$
if (-e $summfile) /bin/rm $summfile

foreach t ($tests:q)
  set a = ($t)        # String => array e.g. "8 4 1port" => (8,4,"1port")
  set npoints = $a[1]
  set nunits  = $a[2]
  set nports  = $a[3]

  if ("$nports" == "1port") set sram = "TRUE_1PORT";
  if ("$nports" == "2port") set sram = "TRUE_2PORT";
  if ("$nports" == "dpump") set sram = "1PORT_DBLPUMP";

  if ($npoints == "hline") then
    echo
    echo "TR ========================================================================"
    echo
    continue
  endif

  # Start with a clean slate
  # cd $FFTGEN_DIR
  if (-e simv.log) /bin/rm simv.log

  # Build a readable suffix that describes what test we're doing.
  # set parms="top_fft.n_fft_points=$npoints top_fft.units_per_cycle=$nunits top_fft.SRAM_TYPE=$sram top_fft.swizzle_algorithm=$swizzalg"
  set parms =        "top_fft.n_fft_points=$npoints"
  set parms = "$parms top_fft.units_per_cycle=$nunits"
  set parms = "$parms top_fft.SRAM_TYPE=$sram"
  set parms = "$parms top_fft.swizzle_algorithm=$swizzalg"
  set parms = "$parms top_fft.SIMULATOR=vcs"
  set sfx=${npoints}_${nunits}_${nports}
  set tmp = /tmp/test_$sfx.log

  # "8_4_1port" is not supported (at least for now)
  if ($sfx == "8_4_1port") then
    echo "$sfx not supported (16 SRAM's for 8 points\!?)"; continue
  endif
  if ($sfx == "8_4_1port") echo "*** NOTE $sfx is SUPPOSED to fail! (16 SRAM's for 8 points\!?) ***"

  # Print out date, id info
  date; echo $sfx": npoints=$npoints, nunits=$nunits, sram=$sram; alg=$swizzalg"

  # Generate the FFT.
  unset fatal_error
  set dq = '"'
  if ($?VERBOSE) then
    echo "  make -f $MAKEFILE clean gen TOP=fft GENESIS_PARAMS=$dq$parms$dq >& $tmp"
  endif

  make  -f $MAKEFILE clean gen TOP=fft \
    GENESIS_PARAMS="$parms" >& $tmp || set fatal_error

  # If FFT generator failed, print out a coherent error message.
  if ($?fatal_error) then
      echo fatal error
      echo "  ERROR 'make gen' failed. --- $npoints $nunits $nports"
      echo "  See $tmp for details"
      echo "  less -r $tmp"
      if ($sfx == "8_4_1port") echo "*** NOTE $sfx is SUPPOSED to fail! (16 SRAM's for 8 points\!?) ***"
      echo
      echo "-------------------------------------------"
      continue
  endif

  # Run the generator
  # alias mr   make -j 1 run TOP=fft
  alias mr   make -f $MAKEFILE run TOP=fft

  mr |& egrep -v '^Makefile' >> $tmp
  mr |& egrep -v '^Makefile' >> $tmp

  # If "make run" failed, print out a coherent error message.
  if (! -e simv.log) then
      echo fatal error
      echo "ERROR No simv.log; 'make run' failed? --- $npoints $nunits $nports"
      echo "  See $tmp for details"
      echo "  less -r $tmp"
      echo
      echo "-------------------------------------------"
      continue
  endif

  echo ""
  echo "Processing bsr macros in simv.log..."
  echo "  awk -f $BIN/bsr.awk %9.6f < simv.log > simv.log.bsr$$"
          awk -f $BIN/bsr.awk %9.6f < simv.log > simv.log.bsr$$
  echo "  mv simv.log.bsr$$ simv.log"
          mv simv.log.bsr$$ simv.log
  echo ""

  ########################################################################
  # Stats: ncycles, nwrites.
  set n_sram_writes   = `egrep '^SRAM.*Wrote' simv.log | wc -l`
  set n_bypass_writes = `egrep 'Bypass.*wrote' simv.log | wc -l`
  @ nwrites = $n_sram_writes + $n_bypass_writes

  set ncycles = \
    `awk -f $BIN/process_test5.awk simv.log | awk '/FFT took/{print $3}'`

  echo "$nwrites writes ($n_bypass_writes bypass writes), $ncycles cycles"

  ########################################################################
  # Results: first and last 

  set lastline = 2
  if ($npoints == 16) set lastline=3
  cat simv.log \
    | awk -f $BIN/process_test5.awk \
    | sed -n '/TEST5 FINAL/,$p'\
    | egrep '^(ix00|ix07|ix15)' | sed -n "1p;${lastline}p"

  ########################################################################
  # Lint errors?
  egrep '^Lint' $tmp | awk '{print $0 "'" --- $npoints $nunits $nports"'"; }'

  ########################################################################
  # Now check against the golden model.
  # Save results in a summary file.

  echo
  # Note "make gen" deletes all logfiles *.log in "." (should I fix that?)
  set logfile = "/tmp/golden_test_${npoints}_${nunits}_${nports}.log"
  $BIN/golden_test.pl $npoints $nunits $nports \
    |& tee $logfile | egrep '^PASS|^FAIL|ERROR|WARNING|See|less' \
    | sed 's/\(^ERROR.*\)/\1 --- '"$npoints $nunits $nports/"\
    | sed 's/^/TR /' | tee -a $summfile

  # "TR" => "Test Result"
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR For more info:"    | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR     less $logfile" | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "       less $logfile" | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR "                  | tee -a $summfile

  # Check for problems in the log file; it's important to have errors AFTER warnings, right?
  egrep -i 'warn'        simv.log | sed 's/\(.*\)/simv.log: \1/' | tee -a $summfile
  egrep -i 'fatal|error' simv.log | sed 's/\(.*\)/simv.log: \1/' | tee -a $summfile

  echo "-------------------------------------------"


end

# echo ==============================================================================
# cat $summfile
# echo ==============================================================================

if (! -e $summfile) then
  exit
endif


set npass = `grep PASS $summfile | wc -l`
echo "$npass/$ntests tests PASSED"
echo "    (NOTE 47/48 pass is normal because '8 4 1' not supported.)"
echo

echo Warnings:
grep -i warn $summfile || echo "   (no warnings found.)"
echo

echo Errors:
grep -i err $summfile || echo "   (no errors found.)"
echo


echo "Result summary is here: '$summfile'"##############################################################################
## Copyright Stephen Richardson and Stanford University.  All rights reserved.
##              Exclusively Licensed by Chip Genesis Inc.
##
## The code, the algorithm, or any part of it is not to be copied/reproduced.
## The code, the algorithm, or results from running this code may not be used
## for any commercial use unless legally licensed.
##
## For more information please contact
##   Ofer Shacham (Stanford Univ./Chip Genesis)   shacham@alumni.stanford.edu
##   Professor Mark Horowitz (Stanford Univ.)     horowitz@stanford.edu
##
## Genesis2 is patent pending. For information regarding the patent please
## contact the Stanford Technology Licensing Office.
###############################################################################
