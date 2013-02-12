#!/bin/csh -f

# Start in main $FFTGEN directory  (script lives in $FFTGEN/bin)
set myname=$0
set mydir=$myname:h
if ("$mydir" == "$myname") set mydir = .
set FFTGEN_DIR = $mydir/..
#cd ~/fftgen
cd $FFTGEN_DIR

set tests = ()
set ntests = 1

# For one-off tests specified on command line e.g. "golden_test.csh 8 1 1port"
if ($#argv == 3) then
  set tests = ("$1 $2 $3")
  goto DO_TEST
endif

# Use "-abbrev" to run only the short tests.
set npoints_array = (8 16 32 64 128 256 512 1024)
if ("$1" == "-abbrev") set npoints_array = (8 16 32)

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
  #cd ~/fftgen
  cd $FFTGEN_DIR
  if (-e simv.log) /bin/rm simv.log

  # Build a readable suffix that describes what test we're doing.
  set parms="top_fft.n_fft_points=$npoints top_fft.units_per_cycle=$nunits top_fft.SRAM_TYPE=$sram"
  set sfx=${npoints}_${nunits}_${nports}
  set tmp = /tmp/test_$sfx.log

  # "8_4_1port" is not supported (at least for now)
  if ($sfx == "8_4_1port") then
    echo "$sfx not supported (16 SRAM's for 8 points\!?)"; continue
  endif
  if ($sfx == "8_4_1port") echo "*** NOTE $sfx is SUPPOSED to fail! (16 SRAM's for 8 points\!?) ***"

  # Print out date, id info
  date; echo -n $sfx": npoints=$npoints, nunits=$nunits, sram=$sram; "

  # Generate the FFT.
  unset fatal_error
  make -j 1 clean gen TOP=fft \
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
  alias mr   make -j 1 run TOP=fft
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

  ########################################################################
  # Stats: ncycles, nwrites.
  set n_sram_writes   = `egrep '^SRAM.*Wrote' simv.log | wc -l`
  set n_bypass_writes = `egrep 'Bypass.*wrote' simv.log | wc -l`
  @ nwrites = $n_sram_writes + $n_bypass_writes

  set ncycles = \
    `awk -f bin/process_test5.awk simv.log | awk '/FFT took/{print $3}'`

  echo "$nwrites writes ($n_bypass_writes bypass writes), $ncycles cycles"

  ########################################################################
  # Results: first and last 

  set lastline = 2
  if ($npoints == 16) set lastline=3
  cat simv.log | awk -f bin/process_test5.awk | sed -n '/TEST5 FINAL/,$p'\
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
  bin/golden_test.pl $npoints $nunits $nports \
    |& tee $logfile | egrep '^PASS|^FAIL|ERROR|See|less' \
    | sed 's/\(^ERROR.*\)/\1 --- '"$npoints $nunits $nports/"\
    | sed 's/^/TR /' | tee -a $summfile

  # "TR" => "Test Result"
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR For more info:"    | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR     less $logfile" | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "       less $logfile" | tee -a $summfile
  (egrep '^FAIL|ERROR' $logfile > /dev/null) && echo "TR "                  | tee -a $summfile

  echo "-------------------------------------------"
end

echo ==============================================================================
cat $summfile
echo ==============================================================================

set npass = `grep PASS $summfile | wc -l`
echo "$npass/$ntests tests PASSED"
echo

echo Found the following errors:
grep -i err $summfile || echo "   (no errors found.)"
echo


echo "Result summary is here: '$summfile'"