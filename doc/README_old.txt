Last update: 2/18/2013

(Notes in "0notes.txt"; publish to "README.md"))

# Online Interactive FFT Builder

An online, interactive working version of the generator was once
available here:

    http://www-vlsi.stanford.edu:8081

With a backup mirror here:

    http://www-vlsi.stanford.edu/genesis

STATUS: As of May 2019, the backup mirror is still up but the
generator is not working...

<!--
# Source code
Source for the generator is available via download from the URL above
[TBD and/or from github as "steveri/fftgen" and/or "StanfordAHA/fftgen"]
-->

# FFT Generator

FFT generator works and passes regression tests for
  * nunits = 1, 2 and 4 (number of butterfly units working in parallel)
  * npoints = 8, 16, 32, 64, 128, 256, 512, 1024
  * sram = 1port, 2port, dpump(*)

(*) dpump = double-pumped SRAM accessed on both clock edges.

The FFT uses an in-place algorithm, i.e. an n-point FFT requires
exactly n words of memory. The algorithm is capable of operating with
area- and energy-saving single-port SRAM without collisions. A
fully-specified FFT (i.e. number of butterflies == n/2) would thus
complete its transform in (n/2)log2(n) cycles.  For now, however, the
generator can build at most four butterfly units, and there are 6 cycles
of overhead in each test, so the actual time is (n/2)log2(n)/b, where
b is the number of butterfly units. I.e. a 1024-point FFT with one
butterfly unit completes its transform in 5,126 cycles.

In addition, the generator can produce nunits 0.5 or 0.25, which means
one butterfly unit producing results once every two or four cycles
respectively.  I.e. for 32 data points (ignoring the 6-cycle constant
overhead mentioned above), one nunit will complete the FFT in 80
cycles, two units will complete in 40 cycles and four units will
complete in 20 cycles.  0.5 units (one unit with latency 2) will take
160 cycles to complete etc.

To see latest version in action, do e.g.:
  fftgen=<fftgen directory>
  mkdir build; cd build
  $fftgen/bin/golden_test.csh 32 2 1port  

To run complete regression:
  $fftgen/bin/golden_test.csh
  
To run abbreviated regression:
  $fftgen/bin/golden_test.csh -abbrev

To build a single FFT instance do e.g.:
  make -f $fftgen/Makefile clean
  set parms="top_fft.n_fft_points=128 top_fft.units_per_cycle=0.25 top_fft.SRAM_TYPE=1port"
  make -f $fftgen/Makefile gen TOP=fft GENESIS_PARAMS="$parms"

By default the FFT instance is built with a pre-loaded square wave in
its SRAM.  To run the FFT instance (built above), transform the square
wave and produce a simv.log output, do "make run":
  make -f $fftgen/Makefile run

------------------------------------------------------------------------------
Analyzing the output of the FFT.

Several tools are available to read and interpret the "make run"
output simv.log file.

"analyze_reads_and_writes" reads and prints out exhaustive semi-
readable information about the data found in simv.log.  "-d" and "-d9"
print successively even more exhaustive information.  Example:

   bin/analyze_reads_and_writes.pl -d9 simv.log | less



"summarize_analysis.csh" uses output from "analyze_reads_and_writes.pl"
to track the progress of each FFT data point as it gets read from and
written back to memory multiple times.  Use it like this:

   bin/analyze_reads_and_writes.pl -d simv.log | bin/summarize_analysis.csh | less

------------------------------------------------------------------------------
Notes

Also see README_files.txt(?)

2/2/2013
Complete regression test "bin/golden_test.csh" works lint-free as of perforce change 11653.

10/27/2012
Waveform viewer:
   source ~/gui/configs/setup.cshrc; dve -vpd vcdplus.vpd -full64
   "load session", "save session"


------------------------------------------------------------------------------
Generic notes on running the generator.

##############################################################################################################
SETUP: Probably need to do 
  source $CHIPGEN/bin/setup.cshrc
and maybe
  source /horowitz/users/steveri/gui/configs/setup_stanford.cshrc

##############################################################################################################
To run the generator, use:
  make clean [gen|run] [SIM_ENGINE=mentor] [GENESIS_HIERARCHY=new.xml] [GENESIS_CFG_XML=SysCfgs/changefile.xml]

Example:
  make clean gen GENESIS_CFG_XML=SysCfgs/my_config.xml
  make clean run GENESIS_CFG_XML=SysCfgs/your_config.xml

* gen -- generate the design
* run -- generate the design and run the testbench

* Replace SIM_ENGINE=mentor with SIM_ENGINE=synopsys for using synopsys simulation tools.
* GENESIS_HIERARCHY=new.xml redirect the OUTPUT xml file to file 'new.xml' (important for the gui)
* GENESIS_CFG_XML=SysCfgs/changefile.xml tells genesis to use design config specified in 'changefile.xml'

##############################################################################################################
TEST

First clock test (bin/test0_clock.csh):
  touch SysCfgs/blank.xml
  make clean run TOP=clock GENESIS_CFG_XML=SysCfgs/blank.xml

or, if necessary,
  make clean run TOP=clock GENESIS_HIERARCHY=new.xml GENESIS_CFG_XML=SysCfgs/blank.xml






==============================================================================
OLD/REF_________________________________________________________________
  - use danielson-lanzcos to perform the fft?
    - http://www.codeproject.com/Articles/9388/How-to-implement-the-FFT-algorithm
    - http://www.drdobbs.com/cpp/a-simple-and-efficient-fft-implementatio/199500857
  - see example inputs/outputs here:
    - http://rosettacode.org/wiki/Fast_Fourier_transform

  merge printconnections, printwires in fftctl.vp?  or at least use same data struct / array?
  //;  ###TODO/FIXME uhhhh....why not have the caller put in the parens!!?

  ref. fft1.pl to fix init values for BFLYx_in[12}_ix
