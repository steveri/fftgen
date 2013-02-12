Also see README_files.txt(?)

2/11/2013

FFT generator works and passes regression tests for
  * nunits = 1, 2 and 4
  * npoints = 8, 16, 32, 64, 128, 256, 512, 1024
  * sram = 1port, 2port, dpump

To see latest version in action, do e.g.:
  p4 sync
  cd $CHIPGEN/fftgen
  bin/golden_test.csh 32 2 1port  

To run complete regression:
  bin/golden_test.csh
  
To run abbreviated regression:
  bin/golden_test.csh -abbrev


Golden_test basically does this:
  make clean
  set parms="top_fft.n_fft_points=128 top_fft.units_per_cycle=0.25 top_fft.SRAM_TYPE=1port"
  make gen TOP=fft GENESIS_PARAMS="$parms"
  make run

2/2/2013
Complete regression test "bin/golden_test.csh" works lint-free as of perforce change 11653.

2/2/2013
How to use analysis tools to debug errors:

    alias anal ~/fftgen/bin/analyze_reads_and_writes.pl
    alias summ ~/fftgen/bin/summarize_analysis.csh

    # Generate readable summary of FFT operation
    bin/golden_test.csh 16 1 1port
    anal -d simv.log | summ
    
    # Compare working and non-working FFT's
    bin/golden_test.csh 16 1 1port  # Working config
    anal -d9 simv.log > tmp.good
    bin/golden_test.csh 16 4 2port  # Non-working config
    anal -d9 simv.log > tmp.bad
    diff tmp.{good,bad}             # Compare and look for errors.


10/27/2012
Waveform viewer:
   source ~/gui/configs/setup.cshrc; dve -vpd vcdplus.vpd -full64
   "load session", "save session"


------------------------------------------------------------------------------
Okay this works:
  c ; make clean run TOP=clock | & tee make.log

  

This is an FFT generator and testbench

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






##############################################################################
### TRASH ####################################################################

To use perl script to run jobs and to plot graphs, do following step:

0. To set up the environment, use
	source ./scripts/setup.csh	# for tcsh shell
	source ./scripts/setup.bash	# for bash shell, for example, cyclades

1. To compile .vp file and to run synthesis jobs, use:
	./scripts/run.pl [--cluster] [--jobs=50] --xml=XMLFILE --synth=SYNTHSCRIPT

   Example:
	./scripts/run.pl -c -x=Designware_16_syn.xml -s=run_lvt_16.sh -x=Designware_32_syn.xml -s=run_lvt_32.sh  -x=Designware_64_syn.xml -s=run_lvt_64.sh -x=Designware_128_syn.xml -s=run_lvt_128.sh -x=WlcBth2Sqr_16_syn.xml -s=run_lvt_16.sh -x=WlcBth3Sqr_16_syn.xml -s=run_lvt_16.sh -x=WlcBth2Sqr_32_syn.xml -s=run_lvt_32.sh -x=WlcBth3Sqr_32_syn.xml -s=run_lvt_32.sh -x=WlcBth2Sqr_64_syn.xml -s=run_lvt_64.sh -x=WlcBth3Sqr_64_syn.xml -s=run_lvt_64.sh -x=WlcBth2Sqr_128_syn.xml -s=run_lvt_128.sh -x=WlcBth3Sqr_128_syn.xml -s=run_lvt_128.sh

  Description:
	Compile and run Genesis .vp file for each XMLFILE in ./work directory,
	and then run synthesis with target delay script SYNTHSCRIPT.

  Options:
	-c, --cluster: whether you are on a cluster
	-j, --jobs: the maximum jobs to run on the cluster. The default is 50.
	-x, --xml: input xml config file in ./SysCfgs folder to run genesis
	-s, --synth: target delay script in ./synthesis folder to run synthesis
	
	**NOTE: input option XMLFILE must be followed by its SYNTHSCRIPT, 
	and more than one pairs of XMLFILE and SYNTHSCRIPT can be set, but
	the numbers of input XMLFILE and SYNTHSCRIPT must be the same.


2. To collect the synthesis results, use:
	./scripts/collectResults.pl [--folder=FOLDER] -xml=XMLFILE

   Example:
	./scripts/collectResults.pl -x=Designware_16_syn.xml -x=Designware_32_syn.xml -x=Designware_64_syn.xml -x=Designware_128_syn.xml -x=WlcBth2Sqr_16_syn.xml -x=WlcBth3Sqr_16_syn.xml -x=WlcBth2Sqr_32_syn.xml -x=WlcBth3Sqr_32_syn.xml -x=WlcBth2Sqr_64_syn.xml -x=WlcBth3Sqr_64_syn.xml -x=WlcBth2Sqr_128_syn.xml -x=WlcBth3Sqr_128_syn.xml

   Description:
	Collect results for each XMLFILE, the output csv files will be saved
	in FOLDER folder.

   Options:
	-f, --folder: define the folder to save csv files. The default is ./results


3. To plot the graphs, use:
	./scripts/graph.pl [--folder=FOLDER] [--nodisplay] [--Vdd=VDD] [--Vth=VTH] --csv=CSVFILE --desinware=DESIGNWARE_CSV

   Example:
	./scripts/graph.pl -c=WlcBth2Sqr_64_syn.csv -c=WlcBth3Sqr_64_syn.csv -d=Designware_64_syn.csv
	./scripts/graph.pl -n -c=WlcBth2Sqr_64_syn.csv -c=WlcBth3Sqr_64_syn.csv -d=Designware_64_syn.csv 
	./scripts/graph.pl -f=MultP_results -c=WlcBth2Sqr_64_syn.csv -c=WlcBth3Sqr_64_syn.csv -d=Designware_64_syn.csv

   Description:
	Generate a MATLAB script to plot a graph of several result csv files.
	Then run MATLAB, generate the graph and save a pdf version in
	FOLDER folder. --nodisplay option is available for non-GUI
	environment.

   Options:
	-f, --folder: define the folder to get csv files and save pdf file. The default is ./results
	-n, --nodisplay: do not launch MATLAB GUI
	--Vdd: the Vdd we use to plot the graph. The default is 1.0.
	--Vth: the Vth we use to plot the graph. The default is lvt.

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
