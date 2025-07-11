#!/bin/csh -f
## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.

set VERBOSE
set TRAVIS

if ("$1" == "--help") then
cat <<EOF

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
endif

set PYTHON_OR_PERL = "PERL"
if ("$1" == "--python") then
    set PYTHON_OR_PERL = "PYTHON" ; shift
else if ("$1" == "--perl") then
    set PYTHON_OR_PERL = "PERL"   ; shift
endif

# # !!? What the hell is this???
# # I think maybe it was a shortcut for "golden_test -gt8k ... ?"?
# unset gt8k
# if ("$0:t" == "gt8k.csh") set gt8k


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
set SIMULATOR = 'verilator'
if ("$1" == "-sim") then
  set SIMULATOR=$2
  shift; shift;
endif

# Convenient abbrev ver == verilator
if ("$SIMULATOR" == "ver") set SIMULATOR=verilator


if ("$SIMULATOR" == "verilator") then
  set simlog = "fft.log"

else if ("$SIMULATOR" == "vcs") then
  set simlog = "simv.log"

else
  echo "ERROR What is -sim '$SIMULATOR'? Can only handle -sim 'vcs' or 'verilator'"
  exit
endif

# Quick check will save heartache later
set w = `which $SIMULATOR`; if ("$w" == "") then
  echo "ERROR looks like you do not have '$SIMULATOR' in your path"
  exit
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

# Use "-abbrev" to run only the short tests. See below for '-gt8k'
if ("$1" == "-abbrev") set npoints_array = (8 16 32)
if ("$1" == "-gt8k")   set gt8k


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
    echo ""
   #echo "   -----------------------------------------"
  else
    echo "   $t" | awk '{ printf("%16s",$0); }'
    # echo -n " $t"
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
  if (-e $simlog) /bin/rm $simlog

  # Build a readable suffix that describes what test we're doing.
  # set parms="top_fft.n_fft_points=$npoints top_fft.units_per_cycle=$nunits top_fft.SRAM_TYPE=$sram top_fft.swizzle_algorithm=$swizzalg"
  set parms =        "top_fft.n_fft_points=$npoints"
  set parms = "$parms top_fft.units_per_cycle=$nunits"
  set parms = "$parms top_fft.SRAM_TYPE=$sram"
  set parms = "$parms top_fft.swizzle_algorithm=$swizzalg"
  set parms = "$parms top_fft.SIMULATOR=$SIMULATOR"
  set sfx=${npoints}_${nunits}_${nports}
  set tmp = /tmp/test_$sfx.log

  # "8_4_1port" is not supported (at least for now)
  if ($sfx == "8_4_1port") then
    echo "$sfx not supported (16 SRAM's for 8 points\!?)"; continue
  endif
  if ($sfx == "8_4_1port") echo "*** NOTE $sfx is SUPPOSED to fail! (16 SRAM's for 8 points\!?) ***"

  # Print out date, id info
  date; echo $sfx": npoints=$npoints, nunits=$nunits, sram=$sram; alg=$swizzalg; sim=$SIMULATOR"

  set cmd = "make -f $MAKEFILE clean gen SIM=$SIMULATOR TOP=fft"

  # Generate the FFT.
  unset fatal_error
  set dq = '"'
  if ($?VERBOSE) then
    echo "  $cmd GENESIS_PARAMS=$dq$parms$dq" >& $tmp
  endif
  $cmd GENESIS_PARAMS="$parms" >>& $tmp || set fatal_error

  # If FFT generator failed, print out a coherent error message.
  if ($?fatal_error) then
      echo fatal error
      echo "  ERROR 'make gen' failed. --- $npoints $nunits $nports"

      if ($?TRAVIS) cat $tmp
      if ($?TRAVIS) exit 13

      echo "  See $tmp for details"
      echo "  less -r $tmp"
      if ($sfx == "8_4_1port") echo "*** NOTE $sfx is SUPPOSED to fail! (16 SRAM's for 8 points\!?) ***"
      echo
      echo "-------------------------------------------"
      continue
  endif

  # Run the simulation
  # alias mr   make -j 1 run TOP=fft
  alias mr   make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR

  # Duh? Why twice?
  echo 1. make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR >> $tmp
  mr |& egrep -v '^Makefile' >> $tmp
  echo 2. make -f $MAKEFILE run TOP=fft SIM=$SIMULATOR >> $tmp
  mr |& egrep -v '^Makefile' >> $tmp

  # If "make run" failed, print out a coherent error message.
  if (! -e $simlog) then
      echo fatal error
      echo "ERROR No $simlog; 'make run' failed? --- $npoints $nunits $nports"
      echo "  See $tmp for details"
      echo "  less -r $tmp"
      echo
      echo "-------------------------------------------"
      continue
  endif

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
  set n_sram_writes   = `egrep '^SRAM.*Wrote' $simlog | wc -l`
  set n_bypass_writes = `egrep 'Bypass.*wrote' $simlog | wc -l`
  @ nwrites = $n_sram_writes + $n_bypass_writes

  set ncycles = \
    `awk -f $BIN/process_test5.awk $simlog | awk '/FFT took/{print $3}'`

  echo "$nwrites writes ($n_bypass_writes bypass writes), $ncycles cycles"

  ########################################################################
  # Results: first and last 

  set lastline = 2
  if ($npoints == 16) set lastline=3
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


  set keep_abbrev
  if ($?keep_abbrev) then
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
  endif

  ########################################################################
  # Now check against the golden model.
  # Save results in a summary file.

  set golden_test = $BIN/golden_test.pl
  if ($PYTHON_OR_PERL == "PYTHON") set golden_test = $BIN/golden_test.py

  echo ''
  # Note "make gen" deletes all logfiles *.log in "." (should I fix that?)
  set logfile = "/tmp/golden_test_${npoints}_${nunits}_${nports}.log"
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


end

# echo ==============================================================================
# cat $summfile
# echo ==============================================================================

if (! -e $summfile) then
  echo "ERROR golden_test.csh - no summary file generated"
  exit 13
endif


set npass = `grep PASS $summfile | wc -l`
echo "$npass/$ntests tests PASSED"
echo "    (NOTE 47/48 pass is normal because '8 4 1' not supported.)"
echo

if ($ntests == 48) then
    if ($npass != 47) then
        echo "ERROR golden_test.csh - should be 47/48 passes"
        exit 13
    endif
else if ($npass != $ntests) then
    echo "ERROR golden_test.csh - test(s) failed"
    exit 13
endif

echo Warnings:
grep -i warn $summfile || echo "   (no warnings found.)"
echo

echo Errors:
grep -i err $summfile || echo "   (no errors found.)"
echo

# echo "Result summary is here: '$summfile'"
/bin/rm $summfile
echo "NOTE did not keep result summary file '$summfile'"


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
