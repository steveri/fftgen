# FIXME clean up Makefile it's a mess
##############################################################################
################ Makefile Definitions
################################################################################

SHELL := /bin/bash

howto:
	@echo ""
	@echo "For a clean build, you should do something like this:"
	@echo "    mkdir build; cd build; make -f ../Makefile all"
	@echo ""


########### Generic Env Defs ############
#########################################
# TOP is name of module to compile and run, e.g.
#   - make TOP=fftgen for fftgen test
#   - make TOP=clock to test clock.vp module only.
TOP := fft

# Simulator can be "vs" or "verilator"
SIM := verilator
$(warning SIMULATOR set to $(SIM))

# This little trick finds where the makefile exists (not used so far as I can tell)
MAKEFILE_PATH:=$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

DESIGN_HOME:=$(shell cd $(dir $(MAKEFILE_PATH)); pwd -P)
$(warning Home dir set to $(DESIGN_HOME))

# RUNDIR is where we are actually running
RUNDIR := $(shell cd ./; pwd -P)
$(warning Work started at $(RUNDIR)) 

# DELETED 05/2019 ------------------------------------------------------------
# this line enables a local Makefile to override values of the main makefile
# -include Makefile.local
# DELETED 05/2019 ------------------------------------------------------------


############# For Genesis2 ##############
#########################################
GENESIS_TOP = top_$(TOP)
GENESIS_SYNTH_TOP_PATH = $(GENESIS_TOP).$(TOP)


# list src folders and include folders
GENESIS_SRC := 	-srcpath ./			\
		-srcpath $(DESIGN_HOME)/rtl	\
		-srcpath $(DESIGN_HOME)/tst			

GENESIS_INC := 	-incpath ./			\
		-incpath $(DESIGN_HOME)/rtl	\
		-incpath $(DESIGN_HOME)/tst


GENESIS_LIB := 	-perl_libs ./			\
		-perl_libs $(DESIGN_HOME)/rtl	\
		-perl_libs $(DESIGN_HOME)/tst


GENESIS_CFG := 	-cfgpath ./			\
		-cfgpath $(DESIGN_HOME)/SysCfgs


# vpath directive tells where to search for *.vp and *.vph files
vpath %.vp   $(GENESIS_SRC)
vpath %.svp  $(GENESIS_SRC)

vpath %.vph  $(GENESIS_INC)
vpath %.svph $(GENESIS_INC)

vpath %.cfg $(GENESIS_CFG)
vpath %.xml $(GENESIS_CFG)


# Now list all inputs to genesis: 
GENESIS_PRIMITIVES :=	

GENESIS_ENV :=		$(wildcard $(DESIGN_HOME)/tst/*.vp) $(wildcard $(DESIGN_HOME)/tst/*.svp)
GENESIS_ENV :=		$(notdir $(GENESIS_ENV)) 

GENESIS_DESIGN := 	$(wildcard $(DESIGN_HOME)/rtl/*.vp) $(wildcard $(DESIGN_HOME)/rtl/*.svp)
GENESIS_DESIGN := 	$(notdir $(GENESIS_DESIGN))

GENESIS_INPUTS :=	$(GENESIS_PRIMITIVES) $(GENESIS_ENV) $(GENESIS_DESIGN) 

# debug level
GENESIS_DBG_LEVEL := 0

# List of generated verilog files
GENESIS_VLOG_LIST := genesis_vlog.vf
GENESIS_SYNTH_LIST := $(GENESIS_VLOG_LIST:%.vf=%.synth.vf)
GENESIS_VERIF_LIST := $(GENESIS_VLOG_LIST:%.vf=%.tst.vf)

# Input xml/cfg files, input parameters
GENESIS_CFG_XML	:=
GENESIS_CFG_SCRIPT	:=
GENESIS_PARAMS	:=

# output xml hierarchy file
ifndef GENESIS_HIERARCHY
GENESIS_HIERARCHY := $(TOP).xml
else
  $(warning WARNING: GENESIS_HIERARCHY set to $(GENESIS_HIERARCHY))
endif

# Genesis-parse options from 'Genesis2.pl -help'
#        [-parse]                    ---   should we parse input file to generate perl modules?
#        [-sources|srcpath dir]      ---   Where to find source files
#        [-includes|incpath dir]     ---   Where to find included files
#        [-input file1 .. filen]     ---   List of top level files
#                                    ---   The default is STDIN, but some functions
#                                    ---   (such as "for" or "while")
#                                    ---   may not work properly.
#        [-perl_modules modulename]  ---   Additional perl modules to load

GENESIS_PARSE_FLAGS := 	-parse $(GENESIS_SRC) $(GENESIS_INC) $(GENESIS_LIB) -input $(GENESIS_INPUTS) 		

# Genesis-generate options from 'Genesis2.pl -help'
#        [-generate]                 ---   should we generate a verilog hierarchy?
#        [-top topmodule]            ---   Name of top module to start generation from
#        [-depend filename]          ---   Should Genesis2 generate a dependency file list? (list of input files)
#        [-product filename]         ---   Should Genesis2 generate a product file list? (list of output files)
#        [-hierarchy filename]       ---   Should Genesis2 generate a hierarchy representation tree?
#        [-cfgpath|configs dir]		# Where to find config files (xml/scripts)
#        [-xml filename]             ---   Input XML representation of definitions
#        [-cfg filename]                 # Config file to specify parameter values as a Perl script (overrides xml definitions)
#	 [-parameter path.to.prm1=value1 path.to.another.prm2=value2] --- List of parameter override definitions

# As of genesis version 9a3686c, must use new option '-unqstyle numeric' or it breaks :(
#        [-unqstyle style]               # Preferred module uniquification style [param numeric]

# UNQSTYLE = $(shell Genesis2.pl --help | grep unqstyle > /dev/null && echo '-unqstyle numeric')
UNQSTYLE = $(shell Genesis2.pl --help | grep gloggle > /dev/null && echo '-unqstyle numeric')

GENESIS_GEN_FLAGS :=	-gen $(UNQSTYLE) -top $(GENESIS_TOP)			\
			-synthtop $(GENESIS_SYNTH_TOP_PATH)			\
			-depend depend.list					\
			-product $(GENESIS_VLOG_LIST)				\
			-hierarchy $(GENESIS_HIERARCHY)				\
			$(GENESIS_CFG)


# What the hell...?
ifneq ($(strip $(GENESIS_CFG_SCRIPT)),)
  GENESIS_GEN_FLAGS	:= $(GENESIS_GEN_FLAGS) -cfg $(GENESIS_CFG_SCRIPT)
  $(warning WARNING: GENESIS_CFG_SCRIPT set to $(GENESIS_CFG_SCRIPT))
endif
ifneq ($(strip $(GENESIS_CFG_XML)),)
  GENESIS_GEN_FLAGS	:= $(GENESIS_GEN_FLAGS) -xml $(GENESIS_CFG_XML)
  $(warning WARNING: GENESIS_CFG_XML set to $(GENESIS_CFG_XML))
endif
ifneq ($(strip $(GENESIS_PARAMS)),)
  GENESIS_GEN_FLAGS	:= $(GENESIS_GEN_FLAGS) -parameter $(GENESIS_PARAMS)
  $(warning WARNING: GENESIS_PARAMS set to $(GENESIS_PARAMS))
endif


##### FLAGS FOR SYNOPSYS VCS COMPILATION #####
##############################################
SIMV = $(RUNDIR)/simv

SIM_TOP = top_$(TOP)
#SIM_TOP = top_clock
#SIM_TOP = clock

VERILOG_ENV :=		 

VERILOG_DESIGN :=	

VERILOG_FILES :=  	$(VERILOG_ENV)	$(VERILOG_DESIGN)					

SYNOPSYS := /hd/cad/synopsys/dc_shell/latest

# rtl/lib is where I put my home-growed fpu 5/2019
VERILOG_LIBS := \
  -y $(RUNDIR) +incdir+$(RUNDIR) \
  -y      $(SYNOPSYS)/dw/sim_ver \
  +incdir+$(SYNOPSYS)/dw/sim_ver \
  -y      $(DESIGN_HOME)/rtl/lib \
  +incdir+$(DESIGN_HOME)/rtl/lib

ifndef TCBN45GS_VERILOG
  $(warn WARNING TCBN45GS_VERILOG not defined)
endif
ifndef TCBN45GSLVT_VERILOG
  $(warn WARNING TCBN45GSLVT_VERILOG not defined)
endif
ifndef TCBN45GSHVT_VERILOG
  $(warn WARNING TCBN45GSHVT_VERILOG not defined)
endif

VERILOG_GATE_LIBS :=	-v $(TCBN45GS_VERILOG)                          \
			-v $(TCBN45GSLVT_VERILOG)                       \
			-v $(TCBN45GSHVT_VERILOG)


# "-sverilog" enables system verilog
# "+lint=PCWM" enables linting error messages (Port connect width mismatch)
# "+lint=all,noVCDE" enables ALL linting error messages except "Verilog compiler directive encountered"
# "+libext+.v" specifies that library files (imported by the "-y" directive) ends with ".v"
# "-notice" used to get details when ports are coerced to inout
# "-full64" for 64 bit compilation and simulation
# "+v2k" for verilog 2001 constructs such as generate and "mecbk" (below)
# "-timescale=1ns/1ns" sets the time unit and time precision for the entire design
# "+noportcoerce" compile-time option to shut off the port coercion for the entire design
# "-top topModuleName" specifies the top module
# "-f verilogFiles.list" specifies a file that contains list of verilog files to compile
# "+memcbk" Enables callbacks for memories and multi-dimensional arrays (MDAs). 

#				+lint=PCWM					\

VERILOG_COMPILE_FLAGS := 	-sverilog 					\
				+cli 						\
                                +memcbk                                         \
				+lint=all,noVCDE				\
				+libext+.v					\
				-notice						\
				-full64						\
				+v2k						\
				-debug_pp					\
				-timescale=1ps/1ps				\
				+noportcoerce         				\
				+vcs+lic+wait					\
				-licqueue					\
				-ld $(VCS_CC) 					\
				-top $(SIM_TOP)					\
				$(VERILOG_FILES) $(VERILOG_LIBS)

# "+vpdbufsize+100" limit the internal buffer to 100MB (forces flushing to disk)
# "+vpdports" Record information about ports (signal/in/out)
# "+vpdfileswitchsize+1000" limits the wave file to 1G (then switch to next file)
VERILOG_SIMULATION_FLAGS := 	$(VERILOG_SIMULATION_FLAGS) 			\
				-l simv.log					\
				+vcs+lic+wait					\
				+vpdbufsize+100					\
				+vcs+dumparrays					\
				+vpdfileswitchsize+100

##### END OF FLAGS FOR SYNOPSYS COMPILATION ####

##### FLAGS FOR SYNOPSYS DC-SHELL #####
#######################################
### See Makefile.synth for synthesis crap that would otherwise go here...
### -include Makefile.synth
######## END OF FLAGS FOR SYNOPSYS DC-SHELL #####


################################################################################
################ Makefile Rules
################################################################################
#default rule: 
all: run_$(SIM)


###### Genesis2 rules: ######
#############################
# phony rules for verilog generation process
.PHONY: gen genesis_clean
gen: $(GENESIS_VLOG_LIST) $(GENESIS_SYNTH_LIST) $(GENESIS_VERIF_LIST)

# This is the rule to activate Genesis2 generator to generate verilog 
# files (_unqN.v) from the genesis (.vp) program.
# Use "make gen GEN=<genesis2_gen_flags>" to add elaboration time flags
$(GENESIS_VLOG_LIST) $(GENESIS_SYNTH_LIST) $(GENESIS_VERIF_LIST): $(GENESIS_INPUTS) $(GENESIS_CFG_XML) $(GENESIS_CFG_SCRIPT)
        # Check for existence of Genesis2.pl
	@if ! `command -v Genesis2.pl > /dev/null`; then echo;\
	 echo 'ERROR Cannot find Genesis2.pl';\
         echo 'ERROR Did you source bin/setup_genesis.sh?';\
	 echo; false; fi
	@echo ""
	@echo Making $@ because of $?
	@echo ==================================================
       #Genesis2.pl $(GENESIS_GEN_FLAGS) $(GEN) $(GENESIS_PARSE_FLAGS) -debug $(GENESIS_DBG_LEVEL) 
	echo Genesis2.pl $(GENESIS_GEN_FLAGS) $(GEN) $(GENESIS_PARSE_FLAGS) -debug $(GENESIS_DBG_LEVEL) 
	Genesis2.pl $(GENESIS_GEN_FLAGS) $(GEN) $(GENESIS_PARSE_FLAGS) -debug $(GENESIS_DBG_LEVEL) 

genesis_clean:
	@echo ""
	@echo Cleaning previous runs of Genesis
	@echo ===================================
	@if test -f "genesis_clean.cmd"; then 	\
		 ./genesis_clean.cmd;		\
	fi
	\rm -rf $(GENESIS_VLOG_LIST) $(GENESIS_SYNTH_LIST) $(GENESIS_VERIF_LIST)
###### END OF Genesis2 Rules #######



# VCS compile rules:
#####################
# compile rules:
# use "make COMP=+define+<compile_time_flag[=value]>" to add compile time flags
.PHONY: comp
comp: $(SIMV)

#$(SIMV):$(GENESIS_VLOG_LIST) clock.v
$(SIMV): $(GENESIS_VLOG_LIST)
	@echo ""
	@echo Making $@ because of $?
	@echo ==================================================
	sleep 1;
#	vcs  $(VERILOG_COMPILE_FLAGS) clock.v $(COMP) 2>&1 | tee comp_bb.log 
#	vcs  $(VERILOG_COMPILE_FLAGS) -f $(RUNDIR)/$(GENESIS_VLOG_LIST) $(COMP) 2>&1 | tee comp_bb.log 
#	export VCS_ARCH_OVERRIDE=linux; # 5/2019 this caused mucho errors
	vcs  $(VERILOG_COMPILE_FLAGS) -f $(RUNDIR)/$(GENESIS_VLOG_LIST) $(COMP)


# Simulation rules:
#####################
# use "make run RUN=+<runtime_flag[=value]>" to add runtime flags
# "PHONY" means there is no actual file named "run" :)
.PHONY: run
run: run_$(SIM)

.PHONY: run_vcs
run_vcs: $(SIMV)
	@echo ""
	@echo Now Running simv
	@echo ==================================================
	$(SIMV) $(VERILOG_SIMULATION_FLAGS) $(RUN)

# E.g. VTOP=Vtop_fft
VTOP := Vtop_$(TOP)

# E.g. obj_dir/Vtop_fft |& $(DESIGN_HOME)/bin/bsr.awk %9.6f > Vtop_fft.log
.PHONY: run_verilator
run_verilator: obj_dir/$(VTOP) $(DESIGN_HOME)/bin/bsr.awk
	@echo ""
	@echo Now Running verilator simulator obj_dir/$(VTOP)
	@echo ==================================================
	obj_dir/$(VTOP) |& $(DESIGN_HOME)/bin/bsr.awk %9.6f > $(TOP).log

obj_dir/$(VTOP): obj_dir/$(VTOP).mk
	make -j -C obj_dir/ -f $(VTOP).mk $(VTOP)


# verilator -Wno-fatal -Wall --cc ${top} --exe ${cpp} --trace -y ${vdir}
# verilator -Wno-fatal -Wall --cc genesis_verif/top_fft.v --exe $(DESIGN_HOME)/tst/fft.cpp 
#           --trace -y genesis_verif/ -y $(DESIGN_HOME)/rtl/lib/
# 
# FIXME shouldn't dependence be "$(RUNDIR)/$(GENESIS_VLOG_LIST)"???
VERILATOR_TESTBENCH := $(DESIGN_HOME)/tst/$(TOP).cpp
obj_dir/$(VTOP).mk: $(VERILATOR_TESTBENCH) $(GENESIS_VLOG_LIST)
	verilator -Wno-fatal -Wall --cc \
	  genesis_verif/top_fft.v --exe $(VERILATOR_TESTBENCH) \
	  --trace -y genesis_verif/ -y $(DESIGN_HOME)/rtl/lib/

# Top module should be e.g. genesis_verif/top_fft.v
VFILE_TOP := genesis_verif/$(GENESIS_TOP).v
verilator_list.vf: $(GENESIS_VLOG_LIST)
	grep -v $(VFILE_TOP) $(GENESIS_VLOG_LIST) > verilator_list.vf

# # Something for the GUI: "make gui_info" gives the gui everything it needs to know.
# gui_info:
# 	@echo Hello GUI how are you?
# 	$(DESIGN_HOME)/bin/tmp_hello_gui.csh

# Cleanup rules:
#####################
.PHONY: clean
#clean: genesis_clean synthesis_clean
clean:
	@echo ""
	@echo Cleaning old files, objects, logs and garbage
	@echo ==================================================
	\rm -f depend.list
	\rm -f vcdplus.vpd
	\rm -rf $(SIMV) simv.*
	\rm -f *.tcl
	\rm -f *.info
	\rm -rf csrc
	\rm -rf *.daidir
	\rm -rf *.pvl
	\rm -rf *.syn
	\rm -rf *.mr
	\rm -rf *.pvk
	\rm -rf *.flc
	\rm -rf ucli.key
	\rm -rf *~
	\rm -rf top.v
	\rm -rf top_*.v
	\rm -f graph_*.m
#	\rm -rf $(IBM_TRGT_DIR)
	\rm -f $(SAIF_FILE)
	@echo ""
	@echo "To clean *everything* run 'make cleanall'"
	@echo ==================================================

.PHONY: cleanall
cleanall: clean 
	genesis_clean.cmd >& /dev/null || echo genesis_clean.cmd already gone
	\rm -rf depend.list
	\rm -rf DVE*
	\rm -rf vcdplus.vpd
	\rm -rf obj_dir


##############################################################################
# TESTING

.PHONY: test
test:
	@echo ""
	@echo "Quick test"
	@echo "  " make test8 "(default)"
	@echo "  " make quicktest
	@echo "  " make quicktest SIM=vcs
	@echo "Complete regressions"
	@echo "  " make regress
	@echo "  " make regress SIM=vcs
	@echo "  " make regress SIM=vcs TEST_SUITE=-gt8k
	@echo "  " make regress SIM=verilator "(default)"
	@echo ""

# 1905 regression tests; regressions/ subdir should already exist!! (as part of dist)
# For BIG tests test TEST_SUITE="-gt8k" on make command line
TEST_SUITE := ""
.PHONY: regress regressions
regressions: regress
regress:
	tmpdir=`mktemp -d tmp.regressions.XXX`;\
	  echo $(DESIGN_HOME)/bin/golden_test.csh -sim $(SIM) $(TEST_SUITE); \
	  cd $$tmpdir; $(DESIGN_HOME)/bin/golden_test.csh -sim $(SIM) $(TEST_SUITE)


.PHONY: quicktest
quicktest: test8

.PHONY: test8
test8:
	tmpdir=`mktemp -d tmp.test8.XXX`;\
	  cd $$tmpdir; $(DESIGN_HOME)/bin/golden_test.csh -sim $(SIM) 8 1 1port

# AND/OR?
# test8:
# 	npoints="top_fft.n_fft_points=8"
# 	nbutts="top_fft.units_per_cycle=1";\
# 	sram="top_fft.SRAM_TYPE=TRUE_1PORT";\
# 	alg="top_fft.swizzle_algorithm=round7";\
# 	make clean gen TOP=fft \
# 	  GENESIS_PARAMS="$$npoints $$nbutts $$sram $$alg" \
# 	  >& test_8_1_1port.log
