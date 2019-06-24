package fftctl;
use strict;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK);

use Exporter;
use FileHandle;
use Env; # Make environment variables available


use Genesis2::Manager 1.00;
use Genesis2::UniqueModule 1.00;

@ISA = qw(Exporter Genesis2::UniqueModule);
@EXPORT = qw();
@EXPORT_OK = qw();
$VERSION = '1.0';
sub get_SrcSuffix {Genesis2::UniqueModule::private_to_me(); return ".vp";};
sub get_OutfileSuffix {Genesis2::UniqueModule::private_to_me(); return ".v"};
############################### Module Starts Here ###########################


  sub to_verilog{ 
      # START PRE-GENERATED TO_VERILOG PREFIX CODE >>>
      my $self = shift;
      
      print STDERR "$self->{BaseModuleName}->to_verilog: Start user code\n" 
	  if $self->{Debug} & 8;
      # <<< END PRE-GENERATED TO_VERILOG PREFIX CODE
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/rtl/fftctl.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/rtl/fftctl.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/rtl/fftctl.vp"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright 2013, all rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// See below (end of file) for extended copyright information.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# push (@INC, "./rtl"); # Now this happens when "Makefile.local" (sets PERL5LIB)
 require fftgen;        # log2(), iterate()
 require fft_scheduler; # Note fft_scheduler "requires" swizzler.pm

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- Begin default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # parameter() calls send default Genesis output to top of .v file

# Note parameter declarations (below) will be summarized in the verilog.
 my $npoints = parameter
    (Name=>'n_fft_points', Val=>16,
     Doc=>'Number of complex data values to process.');

 my $upc = parameter
    (Name=>'units_per_cycle', Val=>1.0, List=>[0.25, 0.5, 1.0, 2.0, 4.0],
     Doc=>'Number active butterfly units per cycle (.25 means one unit at 1/4 speed)');
 
 my $SRAM_TYPE = parameter
    (Name=>'SRAM_TYPE', Val=>"TRUE_1PORT",
     List=>["TRUE_1PORT", "TRUE_2PORT", "1PORT_DBLPUMP"],
     Doc=>'What kind of SRAM should the FFT use?');

 my $swizzle_algorithm = parameter
    (Name=>'swizzle_algorithm', Val=>"round7",
     List=>["round7", "mod_bn_combo", "takala"],
     Doc=>'round7 is the newest and best');

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- End default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Usage: my $fftctl = generate(\'fftctl\', \'fftctl\'';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//             , n_fft_points    => 1024';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//             , units_per_cycle => 4';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//             , SRAM_TYPE       => "1PORT_DBLPUMP"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//             );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Where (default value is starred)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   "n_fft_points"    can be any power of two greater than 8 (16*)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   "units_per_cycle" can be 0.25, 0.5, 1.0*, 2.0 or 4.0';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   "SRAM_TYPE"       is either "1PORT_DBLPUMP" or "TRUE_1PORT"* (or "TRUE_2PORT")';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// *default';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Example(s):  see above.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Parameter values used by this instantiation:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 foreach my $p (@{$self->{ParametersList}}) {
     my $val = $self->{Parameters}->{$p}->{Val};
     my $doc = $self->{Parameters}->{$p}->{Doc};
     printf("//     %-24s %s\n", "$p ($val)", $doc);
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 ##############################################################################
  my $WHICH_SCHED = $swizzle_algorithm;

 # Generate op1,op2 values with circuitry instead of using a lookup table.
 my $USE_LOOKUP_TABLE = 0;

 # To debug crazy eye, generate both lookup table and crazy eye ops and
 # compare using command 'egrep 'EYE|Crazy' simv.log | less'
 my $DEBUG_CRAZY_EYE = 0;  # BTW only works if also $USE_LOOKUP_TABLE==1
 if ($DEBUG_CRAZY_EYE ==1) { $USE_LOOKUP_TABLE = 1; }

 my $n_sram_ports = ($SRAM_TYPE eq "TRUE_1PORT") ? 1 : 2;

 # No need for crazy eye unless using single-ported SRAM
 my $USE_CRAZY_EYE = ($n_sram_ports == 1) ? 1 : 0;

 my $timestep = 1;
 my $nunits   = 1;
 
 if ($upc <= 1.0) {
     $timestep = 1/$upc;
     printf("// Building ONE butterfly unit\n");
     printf("// local_clock = global_clock/%d\n", 1/$upc);
 }
 else {
     $nunits = $upc;
     printf("// Building %d butterfly units\n", $upc);
     printf("// local_clock = global_clock\n", 1/$upc);
 }
 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Derived values:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//    $timestep ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $timestep; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') = time it takes (cycles) for butterfly unit to complete one operation';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//    $nunits   ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ')   = number of butterfly units we have to build (four maximum)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# $self->{nunits} = $nunits;  # Make nunits available to others.
#
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# // Generating our own private swizzler "get_banknum".
# //; my $get_banknum = generate
# //;            ('swizzle', "get_banknum",
# //;             , n_butterfly_units=>$nunits
# //;             , n_fft_points     =>$npoints
# //;            );
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $nlevels = fftgen::log2($npoints);            
 my $ncalcs_per_unit = ($nlevels * ($npoints/2))/$nunits;
 if ($nunits > 4) { print "\n\nERROR (fftctl.vp): Too many butterfly units ($nunits > 4)\n\n"; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//    $nlevels  ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nlevels; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ')  = levels (columns) in the (virtual) bfly network';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//    $ncalcs_per_unit ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ncalcs_per_unit; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') = total ncalcs to be performed by each bfly unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# //;
# //;
# //; # More useful variables to keep around:
# //; my $nbutts = $nunits;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
##############################################################################
# Create a complete conflict-free memory access schedule for the FFT.
# "Reschedule" (for 1port ram) means to use one or more bypass buffers.
#
# Is this sttmt actually CREATING @fft_scheduler::fft_sched?
# Without a "my" keyword e.g.?  Can it DO that???
 if ($n_sram_ports == 2) {
   @fft_scheduler::fft_sched = fft_scheduler::fft_schedule($npoints, $nunits, "");
 } else {
   @fft_scheduler::fft_sched = fft_scheduler::fft_schedule($npoints, $nunits, "reschedule");
 }
#
# //; for (my $i=0; $i <  @fft_scheduler::fft_sched; $i++) {
# //;     
# //;     my $bufnum1 = @fft_scheduler::fft_sched[$i]->{op1_buffer};
# //;     my $bufnum2 = @fft_scheduler::fft_sched[$i]->{op2_buffer};
# //;     my $bufacc1 = @fft_scheduler::fft_sched[$i]->{op1_buffer_access};
# //;     my $bufacc2 = @fft_scheduler::fft_sched[$i]->{op2_buffer_access};
# //;     
# //;     printf("//FOOG $i op1_buffer=$bufnum1 op2_buffer=$bufnum2 ".
# //;            "op1_buffer_access=$bufacc1 op2_buffer_access=$bufacc2\n");
# //; }

########################################################################
 # Port signals will be used in several different places...
 # (So put them in reusable arrays!)

 my @inputs = (
     "", "clk", "  // Clock",
     "", "rst_n", "// Reset signal per power-up",
     "", "start", "// Start signal per FFT",
 );

 my @butterfly_unit_indices = build_butterfly_unit_indices();

 my @atype_output = build_access_type_array();
 # E.g. ("blank", "",                  "// Per-butterfly access type\n",
 #       "[2:0]", "BFLY0_access_type", "",
 #       "[2:0]", "BFLY1_access_type", "",
 #       "[2:0]", "BFLY2_access_type", "",
 #       "[2:0]", "BFLY3_access_type", "",
 #       "[2:0]", "BFLY0_access_type", "")

 # my $cnbits = sprintf("[%d:0]", fftgen::log2($ncalcs_per_unit)-1);  # Weird?  Contrived?
 # May need to count a cycle or two beyond minimum!  (Why?)
 my $cnbits = sprintf("[%d:0]", fftgen::log2($ncalcs_per_unit));  # Weird?  Contrived?
 
 my @outputs = (
     $cnbits, "fftctl_cycle_num", "// 0, 1, 2, ...",
     "     ",      "busy",           "         // hi while busy computing fft",
     "     ",      "fftclk",   sprintf("         // local_clk = global_clk/%d",$timestep) # FIXME/TODO/BUG never used??
 );

 ########################################################################
 # Controls for bypass buffer.  E.g.:
 #    output logic [nbanks:0] suppress_wz_o; // {0,1}
 #    output logic [nbanks:0] bypass_read_o; // {0,1}
 #    output logic [0:1] bufnum_o[0:nbanks]; // {0,1,2,3}

 # I think these are only used when nunits==1
 # FIXME either make it conditional on nunits==1 or use for all cases!
 my $nbanks   = 4*$nunits;
 my $lastbank = $nbanks-1;
 # if 4 units, use 4 buffers, otherwise only need two (or one).
 my $bufbits  = ($nunits == 4) ? "[1:0]" : "     ";
 @outputs = (@outputs
     , "blank", "", "\n"
     , "blank", "", "// Bypass controls\n"
     , "[$lastbank:0]", "suppress_wz", " // one bit per bank, set 100 ps after posedge"
     , "[$lastbank:0]", "bypass_read", " // one bit per bank, set 100 ps after posedge"
     , "$bufbits", "bufnum[0:$lastbank]", "          // which buffer do we use for bypass (per bank)?"
 );

 ####################################################################
 # Generate submodules.
 #
 my $lclock = generate('fftclock','LCLK', DIV=>$timestep); # Divide by two
 
 ####################################################################
 # Verilog code starts here:

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Will produce '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nlevels; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' levels (columns) in the (virtual) butterfly network.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '  (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      printwires("      ", "io_list");  # List of inputs and outputs.
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // DECLARATIONS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($USE_LOOKUP_TABLE == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // If using lookup table for op1, declare a lookup table that will use';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // iterated op1_mem values to initialize reg file index values:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       gen_op1_mem_decl();
    }
    else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // No lookup table because ($USE_LOOKUP_TABLE='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $USE_LOOKUP_TABLE; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ').';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Will iterate on precomputed \'access_type\' registers to control';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // bypassing.  *****Only used for 1port SRAM when nunits==1.*****';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       gen_access_type_decl();
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // For nunits>1, use precomputed bit vectors to control bypass buffers.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Each register has one bit per SRAM (i.e. four bits per butterfly unit),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // to tell which (up to four) SRAM\'s are being bypassed in this cycle.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // E.g. suppress_wz = "0000 0000 0000 0011" means that the writes destined';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // for SRAM001 and SRAM000 should go to bypass buffers instead.  "Bufnum"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // tells which of up to four bypass buffers hold this data, thus "bufnum"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // needs two bits per SRAM access.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # my $nops = ($nunits * $ncalcs_per_unit) - 1;
    my $nops = $ncalcs_per_unit - 1;
    my $bufbits = ($nunits == 4) ? "[0: 1]" : "     ";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] precomputed_suppress_wz [0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nops; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];      // {0,1}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] precomputed_bypass_read [0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nops; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];      // {0,1}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bufbits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' precomputed_bufnum[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '][0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nops; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];      // {0,1,2,3}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $n_cycle_num_bits = fftgen::log2($ncalcs_per_unit);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Need to count through array(s) from 0 to '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ncalcs_per_unit-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME FIXME FIXME same as fftram cycle_num but different than top_fft cycle_num :(';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // May need to count a cycle or two beyond minimum!  (Why?)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_cycle_num_bits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] cycle_num;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Try it without, see what happens';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_cycle_num_bits-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] cycle_num;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // NOPE 7 of 48 regression tests FAIL ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TR FAIL: 2 mismatched results --- 16 1 dpump';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TR FAIL: 2 mismatched results --- 16 2 2port';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TR FAIL: 2 mismatched results --- 16 4 2port';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TR FAIL: 2 mismatched results --- 256 1 2port';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TR FAIL: 2 mismatched results --- 256 2 dpump';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TR FAIL: 2 mismatched results --- 256 4 2port';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $n_out2_offset_bits = fftgen::log2($npoints);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // out2_offset is used to calculate op2 from op1.\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_out2_offset_bits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] out2_offset;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $n_stageno_bits = fftgen::log2($npoints)-1;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Looks like we\'re (finally!) going to need a stage number.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_stageno_bits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] stageno;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Control signals.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic       STARTED;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic       LAST;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // [Optional code here iff $DEBUG_CRAZY_EYE==1]';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($DEBUG_CRAZY_EYE == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // For debugging the "crazy eye" option (instead of lookup table).';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nbits = fftgen::log2($npoints);
    my $bitrange = sprintf("[%d:0]", $nbits-1);
    for (my $b=0; $b< $nunits; $b++) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bitrange; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_ix_new;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bitrange; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_ix_new;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FUNCTION: OP GENERATOR "GenOps" generates op1, op2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Given cynum, stageno, buttno, generate the appropriate ops for each butterfly';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // deconstruct i = (cynum << log2(nbutts)) + butt_num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // e.g. if cynum = 7 and nbutts=4 then i is one of {28,29,30,31}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // op1,op2 = f(i,stageno,npoints)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($WHICH_SCHED ne 'round7') {  # Only need crazy eye for the old regime.
     my $bitwidth = fftgen::log2($npoints); # Need to hold values [0..($npoints-2)]
   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   function ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 2*$bitwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] GenOps;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # For each stage, i counts from 0 to npoints...or is it npoints/2?
       # FIXME definitely try golden test with imax=f(npoints/2) instead of npoints below
       my $imax = (fftgen::log2($npoints)-1);  
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($ncalcs_per_unit); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] CyNum;   // Yes there\'s an extra bit DON\'T CHANGE IT';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($nunits)         ; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] ButtNum;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($npoints)-1      ; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] StageNo; // E.g. 0..9 for npoints=1024';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '       ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 8                      ; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] s2; // Can count up to 256 stages, should be plenty!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] ii;   // Counts from 0 to npoints/2 (so there\'s an extra bit)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] i;    // i = ii or crazy(ii) depending on SRAM nports';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] j;    // i & mask';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] k;    // i >> shift_amt';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] op1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] op2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // op1 = BFLY[0123]_i & (511 >> stageno)) >> (9 - stageno);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         //i  = ((CyNum << '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($nunits-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') + ButtNum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         //i  = ((CyNum << '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($nunits-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') + ButtNum) & '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($npoints/2-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '; // Yes we need the mask.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          # if ($n_sram_ports == 1) {
           if ($USE_CRAZY_EYE == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '          // If we\'re gonna be crazy now\'s the time.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '          ii  = ((CyNum << '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($nunits); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') + ButtNum) & '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($npoints/2-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '; // Yes we need the mask.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '          i = CrazyEye(ii, (1 << StageNo));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("EYE2 %06d Changed normal i %1d to crazy i %1d", $time, ii, i);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
           } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         i  = ((CyNum << '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($nunits); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') + ButtNum) & '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($npoints/2-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '; // Yes we need the mask.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#           i = ii;
           }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         s2 = ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } (fftgen::log2($npoints)-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' - StageNo);  // 9,8,7,6,5,4,3,2,1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         j = i & ( (1<<s2) - 1);                         // i & (511,255,127...2,1,0)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         k = i >> s2;                                    // ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         op1 = (j << (stageno+1)) + k;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         op2 = op1 + (1 << StageNo);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("CrazyOp1 cy=%1d nbutts='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' log2=%1d, i=%d s=%d s2=%1d j=%d k=%d op1=%d",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  CyNum, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2(1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', i, StageNo, s2, j, k, op1);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         GenOps = {op1,op2};';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   endfunction';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FUNCTION: CRAZY-EYE';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // CrazyEye turns old normal i into a crazy resequenced i (CrazyEye)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($WHICH_SCHED ne 'round7') {  # Only need crazy eye for the old regime.
    # For each stage, i counts from 0 to npoints...or is it npoints/2?
    # FIXME definitely try golden test with imax=f(npoints/2) instead of npoints below
    my $imax = (fftgen::log2($npoints)-1);  # Max opcount (should be) $npoints/2
    my $smax = (fftgen::log2($npoints)-1);  # Max stage num is [log2($npoints)-1];
                                            # stage vec has one bit for each stage.
   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   function ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] CrazyEye;          // THESE BITS ALL HAVE TO BE FIXED!  FIXME!!!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // FIXME try these (here and above) with log2(npoints/2) instead of log2(npoints)?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] NormalEye;  // Each stage, counts from 0 to npoints...or is it npoints/2?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $smax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] StageVec;   // StageVec = 2**StageNumber = 0001, 0010, 0100, ...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                                    // StageVec ranges from 1 to (1 << StageNo)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] ce;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         case (StageVec)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            
             # Call fft_schedule to get the per-stage verilog code.
             my @crazy_verilog = fft_scheduler::fft_schedule($npoints, $nunits, "GET_CRAZY_VERILOG");
             my $nstages = fftgen::log2($npoints);
             for (my $s=0; $s<$nstages; $s++) {
                 my $svec = sprintf("%4d", 2**$s);
                 my $vlog = sprintf("%s", $crazy_verilog[$s]);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $svec; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ': '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $vlog; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
             }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            default: assert (0) $fatal("ERROR fftctl could not generate the crazy eye\\n\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         endcase';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("CrazyEye (t=%06d) NormalEye=%d StageVec=%d CrazyEye=%d",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $time, NormalEye, StageVec, ce);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//         CrazyEye = (NormalEye[2] == 0) ? NormalEye : (NormalEye^1);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#          ce = ((NormalEye & 2) == 0) ? NormalEye : (NormalEye^1);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("EYE2 %06d Given StageVec %1d, changed normal i %1d to crazy i %1d",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $time, StageVec, NormalEye, ce);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         CrazyEye = ce;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   endfunction';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FUNCTION: OP GENERATOR "GenOps2" generates op1, op2 using round2/formal-proof alg.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Given cynum, stageno, buttno, generate the appropriate ops for each butterfly';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // deconstruct i = (cynum << log2(nbutts)) + butt_num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // e.g. if cynum = 7 and nbutts=4 then i is one of {28,29,30,31}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // op1,op2 = f(i,stageno,npoints)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    {
     my $bitwidth = fftgen::log2($npoints); # Need to hold values [0..($npoints-2)]
   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   function ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 2*$bitwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] GenOps2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # For each stage, i counts from 0 to npoints...or is it npoints/2?
       # FIXME definitely try golden test with imax=f(npoints/2) instead of npoints below
       my $imax = (fftgen::log2($npoints)-1);  
       my $nstages   = fftgen::log2($npoints);     # not used?
       my $groupsize = $nunits*4;
       my $ntoggles  = fftgen::log2($groupsize);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($ncalcs_per_unit); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] CyNum;   // Yes there\'s an extra bit DON\'T CHANGE IT mos def';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($nunits)         ; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] ButtNum; // Yes there\'s an extra bit DON\'T CHANGE IT i guess';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($nstages)        ; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] StageNo; // Yes there\'s an extra bit DON\'T CHANGE IT i guess';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '       ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] ii, i, P, i_reordered;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] op1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imax; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] op2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      integer shift_amt;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          my $which_i = "i";  # By default, use wire "i"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Step 0, convert cynum/buttnum into an index.  RIGHT!??';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         ii  = (((CyNum << '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($nunits); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') + ButtNum) & '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($npoints/2-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') << 1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         //$display("GENOPS2 (t=%06d)           ii= %d", $time, ii);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Step 1, the rotate';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         i = (StageNo <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nstages-$ntoggles; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') ?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '             RotateLeft(ii, StageNo) :             // Rotate i left by StageNo bits';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '             RotateSubword(ii, StageNo);           // Rotate bottom t bits of i and move them to top';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2 (t=%06d) ii,i: (%1d,%1d) => (%1d,%1d)", $time, ii, ii+1, i, i+2**StageNo);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // If there\'s no reordering, we\'re done.  Can use i and i+1 as op1 and op2,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // yields a valid schedule although with multiple conflicts.  For conflict-';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // free schedule, must do reordering.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          my $REORDER_I = 1;  # Hmm.  Oops?  Hmmm.
          if ($REORDER_I == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Step 2, the reorder';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Replace appropriate bits in i w/ P(i) a.k.a. swizzle(i)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
         # Want e.g. "P[0] = i[0] ^ i[3] ^ i[6] ... ;"
         # Step 1: build the "i[0] ^ i[3] ^ i[6] ..." part;
          my @xors;
          for (my $t=0; $t < $ntoggles; $t++) {
              $xors[$t] = "i[$t]";
              for (my $ibit=($t+$ntoggles); $ibit <= $imax; $ibit += $ntoggles) {
                  $xors[$t] .= " ^ i[$ibit]";
              }
          }
         
         # Step 2: print the P[] assignments
          for (my $i=0; $i <= $imax; $i++) {  # This also works instead of nested next two(?)
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         P['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $xors[$i % $ntoggles]; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ';';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          }
          
          ########################################################################
          # And now the reordering equations.
          my @perstage_ir = ();
          {
             my $DBG = 0;  my $S = $nstages; my $T = $ntoggles; my $ilen = $S;
             if ($DBG) { print "// Build reorder equations:\n"; }
          
             # Forward stages
             for (my $s=0; $s <= ($S-$T); $s++) {
                 # Replace toggle bits in i ($s thru $s+$T-1) w/ P[] bits
                 # e.g. "ir={i[2],P[1],P[0]}"
                 my @bits = ();
                 for (my $i=0; $i<$ilen; $i++) {
                     $bits[$i] = (($i >= $s) && ($i < ($s+$T))) ? "P[$i]" : "i[$i]";
                 }
                 $perstage_ir[$s] = "{". join(",", reverse(@bits)) . "}";
                 if ($DBG) { print "//     stage $s: ir = $perstage_ir[$s]; // NORMAL\n"; }
             }
             # Reverse stages
             for (my $s = ($S-$T)+1; $s < $S; $s++) {
                 # Replace toggle bits (top T bits) in i w/ P[] bits
                 # e.g. "ir={P[2],P[1],i[0]}"
                 my @bits = ();
                 for (my $i=0; $i<$ilen; $i++) {
                     $bits[$i] = ($i >= ($ilen-$T)) ? "P[$i]" : "i[$i]";
                 }
                 $perstage_ir[$s] = "{". join(",", reverse(@bits)) . "}";
                 if ($DBG) { print "//     stage $s: ir = $perstage_ir[$s]; // OVERLAP\n"; }
             }
             if ($DBG) { print "\n"; }
          }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2 (t=%06d) > P = %08b", $time, P);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         case (StageNo) // Uh, use StageNo why not (used to be StageVec(?))';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
             my $nstages = fftgen::log2($npoints);
             for (my $s=0; $s<$nstages; $s++) {
            #     my $svec = sprintf("%4d", 2**$s);
            #     my $vlog = sprintf("%s", $crazy_verilog[$s]);
                 my $type = ($s <= ($nstages-$ntoggles)) ? "NORMAL" : "OVERLAP";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ': i_reordered = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $perstage_ir[$s]; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '; // '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $type; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
             }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            // default: assert (0) $fatal("ERROR fftctl could not generate the craaaaaazy eye\\n\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            // default: no_crazy: assert (0) $fatal("ERROR fftctl could not generate the craaaaaazy eye\\n\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            // default: $fatal("ERROR fftctl could not generate the craaaaaazy eye\\n\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         endcase';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2 (t=%06d) > ir= %08b", $time, i_reordered);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
         
          $which_i = "i_reordered"; # Use wire "i_reordered" instead of "i"
          } # if ($REORDER_I == 1)
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         op1 = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $which_i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' & ~(1\'b1 << StageNo);  // To guarantee that op1 < op2.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         op2 = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $which_i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' |  (1\'b1 << StageNo);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2 (t=%06d) > op1= %08b", $time, {8\'h0,op1});';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2 (t=%06d) > op2= %08b", $time, {8\'h0,op2});';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2 (t=%06d) ops=(%d,%d)", $time, op1, op2);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("GENOPS2 -----------------------------------------------------");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         GenOps2 = {op1,op2};';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   endfunction';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FUNCTION: ROTATELEFT';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // RotateLeft(i, StageNo):  Rotate reg i left by StageNo bits';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // i is known to have $iwidth bits, where $iwidth is log2($npoints) and $npoints';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // is a Genesis2 parameter of the fftctl module, which contains this function.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Perl setup and containing scope.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    {
        my $iwidth  = fftgen::log2($npoints); # i counts 0..(npoints-1) per stage
        my $nstages = fftgen::log2($npoints); # $npoints is (should be) a module parm
        my $swidth  = fftgen::log2($nstages); # StageNo is one of {0..nstages-1}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   function ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $iwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] RotateLeft;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $iwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] i;        // i counts 0..(npoints-1) per stage';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $swidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] StageNo;  // StageNo is one of {0..(nstages-1)}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 2*$iwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] shifted_double_i;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         shifted_double_i = {i,i} << StageNo;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         RotateLeft = shifted_double_i['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 2*$iwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $iwidth; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   endfunction';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }  # Perl windup and close-scope for verilog function RotateLeft
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FUNCTION: ROTATESUBWORD';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // RotateSubword(i, StageNo):  Rotate bottom T bits of reg i left by s bits, then move them to top.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // s is (StageNo - (nstages-ntoggles))';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // i is known to have $iwidth bits, where $iwidth is log2($npoints) and $npoints';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // T is the number of toggle bits, which is log2(groupsize)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // is a Genesis2 parameter of the fftctl module, which contains this function.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Perl setup and containing scope.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    {
        my $groupsize = $nunits*4;
        if ($groupsize > $npoints) { $groupsize = $npoints; } # For .e.g D=8 and G=16 (8 4 2port)   
        my $ntoggles = fftgen::log2($groupsize); # t counts 0..(groupsize-1) per group
        my $iwidth   = fftgen::log2($npoints);   # i counts 0..(npoints-1) per stage
        my $twidth   = fftgen::log2($ntoggles);  # t counts 0..
        # E.g. if iwidth is 8 and groupsize is 4, then ntoggles is 2 and twidth is 1
   
        my $nstages = fftgen::log2($npoints); # $npoints is (should be) a module parm
        my $swidth  = fftgen::log2($nstages);    # StageNo is one of {0..nstages-1}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   function ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $iwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] RotateSubword;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $iwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] ii;        // i counts 0..(npoints-1) per stage';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      input ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $swidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] StageNo;  // StageNo is one of {0..(nstages-1)}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ntoggles-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] low_T;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 2*$ntoggles-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] shifted_double_t;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Bottom T bits get rotated left s bits, e.g. if iwidth is 8 and ntoggles is 2,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // low_T bits are [1:0] and new i is (rotated ii[1:0]) concat with ii[2:2]';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         low_T = ii['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($ntoggles-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         shifted_double_t = {low_T,low_T} << (StageNo - '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($nstages-$ntoggles); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          if ($ntoggles == $iwidth) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // No need to reassemble word because ntoggles '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ntoggles; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' == iwidth '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $iwidth; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         RotateSubword = shifted_double_t['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 2*$ntoggles-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ntoggles; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Assemble the return value.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // E.g. if ntoggles = 30 and iwidth=100, would have rs={sdt[59:30],i[69:0]}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         RotateSubword = {shifted_double_t['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 2*$ntoggles-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ntoggles; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], ii['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($iwidth-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($ntoggles); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']};';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   endfunction';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }  # Perl windup and close-scope for verilog function RotateSubword
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // INIT BLOCKS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      cycle_num   <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_cycle_num_bits  +1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      STARTED     <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} }                     1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      LAST        <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} }                     1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      stageno     <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_stageno_bits    +1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      out2_offset <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_out2_offset_bits+1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("GENOPS2 -----------------------------------------------------");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("GENOPS2 (t=%06d) STAGE 0", $time);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       if ($USE_LOOKUP_TABLE == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // Precompute values for op1 index "op1_ix_mem"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // {(0,2,4,...) (0,4,8,...1,5,9,...) (0,8,16,...1,9,17...) ... (0,1,2,3,...n/2)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # E.g. for n=8
       #    /***************** Stage 0: ******************/
       #    BFLY0_op1_ix_mem[ 0] =  0;    // indices (0,1)
       #    BFLY0_op1_ix_mem[ 1] =  2;    // indices (2,3)
       #    BFLY0_op1_ix_mem[ 2] =  4;    // indices (4,5)
       #    BFLY0_op1_ix_mem[ 3] =  6;    // indices (6,7)
       #
       #     /***************** Stage 1: ******************/
       #    BFLY0_op1_ix_mem[ 4] =  0;    // indices (0,2)
       #    BFLY0_op1_ix_mem[ 5] =  4;    // indices (4,6)
       #    BFLY0_op1_ix_mem[ 6] =  1;    // indices (1,3)
       #    BFLY0_op1_ix_mem[ 7] =  5;    // indices (5,7)
                    
          gen_op1_mem_values("   ");
       }
       else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // No lookup table because ($USE_LOOKUP_TABLE='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $USE_LOOKUP_TABLE; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ').';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # E.g. for each cycle [0] through [n]:
       #  precomputed_suppress_wz[0] = 16`h01; # Write to  buffer[bufnum[0]] instead of SRAM000
       #  precomputed_bypass_read[0] = 16`h02; # Read from buffer[bufnum[1]] instead of SRAM001
       #  
       #  precomputed_bufnum[7][0] = 2'h0;
       #  precomputed_bufnum[6][0] = 2'h0;
       #  precomputed_bufnum[5][0] = 2'h0;
       #  precomputed_bufnum[4][0] = 2'h0;
       #  precomputed_bufnum[3][0] = 2'h0;
       #  precomputed_bufnum[2][0] = 2'h0;
       #  precomputed_bufnum[1][0] = 2'h3;
       #  precomputed_bufnum[0][0] = 2'h2;
                    
          gen_precomputed_bypass_controls("   ");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Initialize loop variables.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge start_i) if (~rst_n_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      cycle_num   <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_cycle_num_bits  +1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      STARTED     <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} }                     1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      LAST        <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} }                     1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      out2_offset <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $n_out2_offset_bits+1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      suppress_wz_o <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbanks-1        +1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign busy_o = ~LAST;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Generate local clock fftclk_o from global clock gclk';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TODO: would feel better if divisor was passed in as a parameter rather than generated cross-module...?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TODO: if $upc==1 could maybe replace this with an ASSIGN';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lclock->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.clock_in(clk_i), .clock_out(fftclk_o));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Fetch and deliver precomputed ops and bypass info on a per-cycle basis.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($DEBUG_CRAZY_EYE == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge fftclk_o) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("EYE        (t=%06d) cy=%d cy^1=%d", $time, cycle_num, (cycle_num^1));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      #1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("EYE NORMAL OP (t=%06d) op1=%d op2=%d", $time, BFLY0_op1_ix_o, BFLY0_op2_ix_o);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("EYE CRAZY  OP (t=%06d) op1=%d op2=%d", $time, BFLY0_op1_ix_new, BFLY0_op2_ix_new);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("EYE");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge fftclk_o) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if (STARTED & ~rst_n_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Debug info';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftctl %1d: cycle_num = %1d", $time, cycle_num); ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftctl %1d: fftctl_cycle_num_o = %1d", $time, fftctl_cycle_num_o); ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftctl %1d: out2_offset = %1d", $time, out2_offset); ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#         //; if ($USE_LOOKUP_TABLE == 1) {
#
#         // Retrieve precomputed op1 operands for each butterfly unit BFLY<i>
#         //;   for (my $i = 0; $i < $nunits; $i++) {   
#         BFLY`${i}`_op1_ix_o <= BFLY`${i}`_op1_ix_mem[cycle_num];
#         //;   }
#
#         // Use precomputed op1 to calculate op2
#         //;# BFLY0_op2_ix_o = BFLY0_op1_ix_o + out2_offset;
#         //;# BFLY1_op2_ix_o = BFLY1_op1_ix_o + out2_offset;
#         //;# ...
#         //;   for (my $i = 0; $i < $nunits; $i++) {
#         BFLY`${i}`_op2_ix_o <= BFLY`${i}`_op1_ix_mem[cycle_num] + out2_offset;
#         //;   }
#
#         //;   if ($DEBUG_CRAZY_EYE == 1) {
#         //;     for (my $i = 0; $i < $nunits; $i++) {
#         {BFLY`${i}`_op1_ix_new,BFLY`${i}`_op2_ix_new} <= `$genops`(cycle_num, `$i`, stageno);
#         //;     }
#         //;   }
#
#         //; } else {  # (! $USE_LOOKUP_TABLE)
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            my $genops = ($WHICH_SCHED eq "round7") ? "GenOps2" : "GenOps";
            for (my $i = 0; $i < $nunits; $i++) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         {BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ${i}; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_ix_o,BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ${i}; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_ix_o} <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $genops; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(cycle_num, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', stageno);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#         //; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#      $display("EYE NORMAL0 (t=%06d) op1=%d op2=%d", $time, BFLY0_op1_ix_o, BFLY0_op2_ix_o);
#      $display("EYE CRAZED0 (t=%06d) op1=%d op2=%d", $time, BFLY0_op1_ix_new, BFLY0_op2_ix_new);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // And now for access type!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // (Needed only for TRUE_1PORT.  Otherwise will be eliminated as unused...right?)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // TODO: Make this conditional on SRAM_TYPE==TRUE_1PORT';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          for (my $i = 0; $i < $nunits; $i++) {   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ${i}; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_access_type_o <= BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ${i}; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_access_type[cycle_num];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // New bypass controls.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         suppress_wz_o <= precomputed_suppress_wz[cycle_num];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         bypass_read_o <= precomputed_bypass_read[cycle_num];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          my $nbanks = $nunits * 4;
          for (my $i=0; $i<$nbanks; $i++) {
              my $ii = sprintf("%2d", $i);
              if ($nunits == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         bufnum_o['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ii; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] <= 1\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
              } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         bufnum_o['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ii; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] <= precomputed_bufnum['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $ii; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '][cycle_num];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
              }
          }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Debugging info';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
             for (my $i = 0; $i < $nunits; $i++) {   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftctl %1d: in(%2d,%2d), out(%2d, %2d)",$time, BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_ix_o, BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_ix_o, BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_ix_o, BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_ix_o);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
             }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // out2_offset is used to generate op2 from a given precomputed op1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          my $calcs_per_level = $npoints/2;              
          my $ncy_per_level = $calcs_per_level/$nunits;  
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         if ((cycle_num & '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($ncy_per_level-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($ncy_per_level-1); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            out2_offset <= (out2_offset << 1);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            stageno     <= (stageno + 1\'b1);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            $display("GENOPS2 (t=%06d) STAGE %1d", $time, stageno+1);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // Must make cycle_num available to twiddle LUT so as to generate the right twid at the right time.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         fftctl_cycle_num_o <= cycle_num;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         cycle_num          <= cycle_num + 1\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftctl %1d: cycle_num = %1d", $time, cycle_num); ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # TODO: Clean up stupid "LAST" signal.
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge fftclk_o) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // LAST signal tells us when we\'re done.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      my $last_cycle = $ncalcs_per_unit + 1;             # Need one extra cycle to complete (why?)
     
     
      # Trial and error debugging! Regressions work if comment out line below 6/2019 :(
      # if ($SRAM_TYPE eq "TRUE_1PORT") { $last_cycle++; } # Plus one cycle for the final write.
     
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     if (cycle_num == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $last_cycle-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') LAST <= 1\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if (LAST==1) begin  // TODO probably don\'t need LAST somehow...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         // We\'re done, turn everything off.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         STARTED <= 1\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          for (my $i = 0; $i < $nunits; $i++) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '             BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_ix_o <= {'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } fftgen::log2($npoints); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '{1\'bx}}; // Turn off output, for pretty waveform end.  TODO what about in2, out[12]?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '  end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'endmodule';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 ##############################################################################
 # Local subroutines.
 #
 sub printconnections {
     my $indent = shift @_;
     my $indent = "      ";
 
     # Print a beautiful list of port connections for an instance.
     # Used by e.g. "top_fft.vp" to connect to "fftctl.vp"; i.e. "top_fft.vp"
     # will call "fftctl->printconnections" to connect to "fftctl".
     #     .clk(clk_i),
     #     .rst_n(rst_n_i), etc.
 
     print $indent."// begin fftctl->printconnections()\n";
 
     # First print connections to inputs listed in "@inputs" array.
     for (my $i = 0; $i < @inputs; $i += 3) {
         if ($inputs[$i] eq "blank") {
             print $indent.$inputs[$i+2];    # "blank" => skip a line in the portlist.
         } else {
             fftgen::printparm($indent, $inputs[$i+1], "_i", $inputs[$i+2], 0);
         }
     }
     print "\n";
     print $indent."// Indices for where bfly should fetch from array of data point\n";
     for (my $i=0; $i<$nunits; $i++) {
             printf("$indent.BFLY${i}_op1_ix_o(BFLY${i}_op1_ix),\n");    # .BFLY0_op1_ix_o(BFLY0_op1_ix),
             printf("$indent.BFLY${i}_op2_ix_o(BFLY${i}_op2_ix),\n");    # .BFLY0_op2_ix_o(BFLY0_op2_ix),
             print "\n";
     }
     print "\n";
     print $indent."/////////////////////////////////////////////////////////////////////\n";
     print $indent.'// Access type: 0="SRAM"'."\n";
     print $indent.'// 1="op1 from buf", 2="op2 from buf", 3="op1 to buf", 4="op2 to buf"'."\n";
     print "\n";
     for (my $i=0; $i<$nunits; $i++) {
         printf("$indent.BFLY${i}_access_type_o(BFLY${i}_access_type),\n"); # .BFLY0_access_type_o(BFLY0_access_type),
     }
     print "\n";
     print "\n";
 
     # TODO Could easily merge this "output" routine w/ the "input" routine above.
     print $indent.'// Other output signals'."\n";
     print "\n";
     my $n_outputs = @outputs;                    # No. items in array "@outputs"
     for (my $i = 0; $i < $n_outputs; $i += 3) {
         if ($outputs[$i] eq "blank") {
             print $indent.$outputs[$i+2];    # "blank" => skip a line in the portlist.
         } else {
             #my $no_comma = "";
             #if ($i == ($n_outputs - 3)) { $no_comma = "no_comma"; }
 
             # !!$? Last item in list must have "no comma."
             my $no_comma = ($i == ($n_outputs - 3)) ? "no_comma" : "";
 
             # Strip off the bit specs and add a "_o", e.g.
             #   "mywires"     => ".mywires_o(mywires)" and
             #  "mywires[0:n]" => ".mywires_o(mywires)"
             my $wirename = $outputs[$i+1];
             if ($wirename =~ /(.*)(\[.*)/) { $wirename = $1; }
             fftgen::printparm($indent, $wirename, "_o", $outputs[$i+2], $no_comma);
         }
     }
    print "\n";
    print $indent."// end fftctl->printconnections()\n";
 }
 
 sub printwires {
    # Okay yes this is weird but parm list has extra "HASH" when called as "function()" vs. "obj->function()"!!
    my $indent = shift @_; while ($indent =~ /HASH/) { $indent = shift @_; }
    my $list    = shift @_; # Either "io_list" (for me) or "wire_list" (for others)

    my $io_list = ($list eq "io_list") ? 1 : 0;
    
    # Print port list as either list of wires ($list="wire_list")
    # or list of inputs and outputs           ($list="io_list")
    # Called by self (above) to print io's; called by e.g. "top_fft"
    # to build list of wires to connect to fftctl io ports.
 
    print $indent."//------------------------------------------------\n";
    print $indent."// begin fftctl->printwires('$indent', '$list')\n\n";
 
    # Print inputs.  If "$io_list" true, add "input" and comma, e.g.:
    #   input logic  clk_i,   // Clock
    #   input logic  rst_n_i, // Reset signal per power-up
    #   input logic  start_i, // Start signal per FFT
    pw($indent, $io_list, "input", @inputs, "not_last");
 
    # Butterfly unit operands, e.g.
    #   output logic [2:0] BFLY0_op1_ix_o, 
    #   output logic [2:0] BFLY0_op2_ix_o, 
    pw($indent, $io_list, "output", @butterfly_unit_indices, "not_last");
 
    # Bypass control signals
    pw($indent, $io_list, "output", @atype_output, "not_last");
 
    print $indent."// Remaining output signals\n";
    #   output logic [2:0] fftctl_cycle_num_o, // 0, 1, 2, ...
    #   output logic  busy_o,   // hi while busy computing fft
    #   output logic  fftclk_o // local_clk = global_clk/1
    pw($indent, $io_list, "output", @outputs, "last");
 
    print $indent."// end fftctl->printwires()\n";
    print $indent."//------------------------------------------------\n";
 }
 
 sub pw {

     ########################################################################
     # Printwires helper function pw().
     # Usage:    pw($indent, $io_list, $io_type, @signals, $last);
     # Example:  pw($indent, $io_list, "input", @inputs, "not_last");
     #
     # Print wires as indicated in array @signals.
     #  If "$io_list" true, add "input" and comma (if not "last"), e.g.:
     #   input logic  clk_i,   // Clock
     #   input logic  rst_n_i, // Reset signal per power-up
     #   input logic  start_i, // Start signal per FFT

     my $last = pop @_; # "last" or anything else (e.g. "notlast")
 
     my $indent  = shift @_;
     my $io_list = shift @_;  # 1 or 0
     my $io_type = shift @_;  # "input" or "output"
     my @signals = @_;
 
     for (my $i = 0; $i < @signals; $i += 3) {
         
         my $bits    = $signals[$i+0];  # E.g. "[3:0]"
         my $signame = $signals[$i+1];  # E.g. "fourbit_counter"
         my $comment = $signals[$i+2];  # E.g. "// Counts to sixteen"
         
         if ($bits eq "blank") {
             print $indent.$comment; # (newline char must be embedded in comment!)
             next;
         }
         if (! $io_list) {
             # Simple wire list e.g. "logic mywires[0:15];"
             printf($indent."logic %s %s; %s\n", $signals[$i], $signals[$i+1], $signals[$i+2]);
         }
         else {
             # IO wire list e.g.
             #     "mywires"      => "input logic mywires_i,"     or
             #     "mywires[0:n]" => "input logic mywires_i[0:n],"
             my ($aye,$oh) = ("_i","_o");

             # E.g. ""mywires[0:15]" => ("mywires", "_i[0:15]", "_o[0:15")
             if ($signame =~ /(.*)(\[.*)/) { ($signame,$aye,$oh) = ($1, "_i".$2, "_o".$2); }
             
             my $comma  = "," ;
             if (($last eq "last") && ($i == (@signals - 3))) { $comma = ""; } # No comma on last item
             
             if ($io_type eq "input") {
                 printf($indent."input logic $bits ${signame}$aye$comma $comment\n");
             } else {
                 printf($indent."output logic $bits ${signame}$oh$comma $comment\n");
             }
         }
     }
     print "\n";
 }
 
 sub gen_op1_mem_decl {
     #################################################################
     # Declare the memory that will hold precomputed op1 values.  E.g.
     #     logic [3:0] BFLY0_op1_ix_mem [0:7];
     #     logic [3:0] BFLY1_op1_ix_mem [0:7];
 
     my $indent   = "   ";
     my $bitwidth = fftgen::log2($npoints); # Need to hold values [0..($npoints-2)]
     printf($indent."// $bitwidth-bit wide registers hold op1 values ranging from 0 to npoints=%d\n", $npoints-1);
     printf($indent."// $ncalcs_per_unit registers per butterfly unit, one for each computation cycle.\n");
     printf($indent."\n");
     for (my $i=0; $i<$nunits; $i++) {
         printf($indent."logic [%d:0] BFLY%d_op1_ix_mem [0:%d];\n", $bitwidth-1, $i, $ncalcs_per_unit-1);
     }
   }
    
 sub gen_access_type_decl {
     #################################################################
     # Declare the memory that will hold precomputed access_type values.  E.g.
     #     logic [2:0] BFLY0_access_type [0:7];
     #     logic [2:0] BFLY1_access_type [0:7];
 
     my $indent   = "   ";
     print $indent."// Three-bit registers hold one of five access types:\n";
     print $indent.'// ("SRAM", "op1 from buf", "op2 from buf", "op1 to buf", "op2 to buf")'."\n";
     print "\n";
     for (my $i=0; $i<$nunits; $i++) {
         printf($indent."logic [2:0] BFLY%d_access_type [0:%d];\n", $i, $ncalcs_per_unit-1);
     }
   }
    
 sub gen_op1_mem_values {
     my $indent = shift;
     
     # Precompute values for op1 index "op1_ix_mem"
     #{(0,2,4,...) (0,4,8,...1,5,9,...) (0,8,16,...1,9,17...) ... (0,1,2,3,...n/2)
     # E.g. for n=8
     #    /***************** Stage 0: ******************/
     #    BFLY0_op1_ix_mem[ 0] =  0;    // indices (0,1)
     #    BFLY0_op1_ix_mem[ 1] =  2;    // indices (2,3)
     #    BFLY0_op1_ix_mem[ 2] =  4;    // indices (4,5)
     #    BFLY0_op1_ix_mem[ 3] =  6;    // indices (6,7)
     #
     #     /***************** Stage 1: ******************/
     #    BFLY0_op1_ix_mem[ 4] =  0;    // indices (0,2)
     #    BFLY0_op1_ix_mem[ 5] =  4;    // indices (4,6)
     #    BFLY0_op1_ix_mem[ 6] =  1;    // indices (1,3)
     #    BFLY0_op1_ix_mem[ 7] =  5;    // indices (5,7)
 
     my $unum = 0;
     my $bfly_ix = 0;
     my $prev_stage = -1;
     for (my $i=0; $i <  @fft_scheduler::fft_sched; $i++) {
         my $stage = @fft_scheduler::fft_sched[$i]->{stage};
         if ($stage != $prev_stage) {
             print $indent."\n";
             printf("$indent    /***************** Stage $stage: ******************/\n");
             $prev_stage = $stage;
         }
         my $op1 = @fft_scheduler::fft_sched[$i]->{op1};
         my $op2 = @fft_scheduler::fft_sched[$i]->{op2};
         
         printf("$indent    BFLY%d_op1_ix_mem[%2d] = %2d;", $unum, $bfly_ix, $op1);
         printf("    // indices (%d,%d)\n", $op1, $op2);
         if (($unum == ($nunits-1)) && ($nunits > 1)) { print "\n"; }
         
         $unum = ($unum + 1) % $nunits;   # 0,1,2,3, 0,1,2,3, ...
         if ($unum == 0) { $bfly_ix++; }  # 0,0,0,0, 1,1,1,1, ...
     }
 }
 
 sub gen_precomputed_bypass_controls {
     my $indent = shift;
 
      print "$indent   /////////////////////////////////////////////////////////////////////////////\n";
      print "$indent   // Note: for nunits==1 suppress_wz and bypass_read are one-hot\n";
 
      # precomputed_suppress_wz[0] = 16`h01; # Write to buffer[bufnum[0]] instead of SRAM000
      # precomputed_bypass_read[0] = 16`h02; # Read from buffer[bufnum[1]] instead of SRAM001
      # 
      #   // For nunits>1 only (otherwise bufnum always == 0)
      #   precomputed_bufnum[7][0] = 2'h0;
      #   precomputed_bufnum[6][0] = 2'h0;
      #   precomputed_bufnum[5][0] = 2'h0;
      #   precomputed_bufnum[4][0] = 2'h0;
      #   precomputed_bufnum[3][0] = 2'h0;
      #   precomputed_bufnum[2][0] = 2'h0;
      #   precomputed_bufnum[1][0] = 2'h3;
      #   precomputed_bufnum[0][0] = 2'h2;
     
      my $cynum = 0;
      my $prev_stage = -1; 
             print "\n";
      for (my $cynum=0; $cynum <  @fft_scheduler::fft_sched/$nunits; $cynum++) {

         my $stage = @fft_scheduler::fft_sched[$cynum*$nunits]->{stage};
         if ($stage != $prev_stage) {
             print $indent."    /***************** Stage $stage: ******************/\n\n";
             $prev_stage = $stage;
         }

         # $read_op     # Bit vector of all writes for a given cycle
         # $write_op    # Bit vector of all reads for a given cycle
         # @bufnums     # Array of bufnums for a given cycle (iff nunits>1)
         my ($read_op, $write_op, @bufnums) = build_access_vectors($cynum, $nunits);
 
         my $nbanks = 4*$nunits;
         printf("$indent    precomputed_suppress_wz[%2d] = %d'h%X;\n", $cynum, $nbanks, $write_op);
         printf("$indent    precomputed_bypass_read[%2d] = %d'h%X;\n", $cynum, $nbanks, $read_op);
         if ($nunits>1) {
             print "\n";
             my $nbanks = 4*$nunits;
             for (my $b=0; $b<$nbanks; $b++) {
                 printf("$indent    precomputed_bufnum[%2d][%2d] = 2'h%d;\n", $b, $cynum, $bufnums[$b]);
             }
             print "\n";
         }
     }
 }
 
 sub build_access_vectors {
    my $cynum = shift;
    my $nunits = shift;
 
    ########################################################################
    # For given cycle $cynum in the schedule, query the previously-initialized
    # data structure fft_sched and build <nunits>
    # access control vectors (one per butterfly unit) that will tell us when to bypass SRAM's.
 
    my $i = $cynum * $nunits; # Each cycle produces <nunits> ops, one per butterfly.

    my $read_op  = 0;    # Bit vector of all writes for a given cycle
    my $write_op = 0;    # Bit vector of all reads for a given cycle
    my @bufnums  = ();   # Array of bufnums for a given cycle (iff nunits>1)
 
    for (my $bfly = 0; $bfly < $nunits; $bfly++) {
        my $bank1 = @fft_scheduler::fft_sched[$i]->{bank1};
        my $bank2 = @fft_scheduler::fft_sched[$i]->{bank2};
        if ($nunits == 1) {
 
            my $access = @fft_scheduler::fft_sched[$i]->{access};
            
            # Only one of the following will be true...right?  RIGHT!  Duh.
            if ($access eq "op1 from buffer") { $read_op  |= 2**$bank1; }
            elsif ($access eq "op2 from buffer") { $read_op  |= 2**$bank2; }
            elsif ($access eq  "op1 to buffer")  { $write_op |= 2**$bank1; }
            elsif ($access eq  "op2 to buffer")  { $write_op |= 2**$bank2; }
        }
        else {
            # $fft_info[$fftno]->{op[12]_buffer}        = -1 or (0, 1, 2, 3)
            # $fft_info[$fftno]->{op[12]_buffer_access} = ("RD", "WR", "NONE", or "BOTH")
            
            my $bufnum1 = @fft_scheduler::fft_sched[$i]->{op1_buffer};
            my $bufnum2 = @fft_scheduler::fft_sched[$i]->{op2_buffer};
            my $bufacc1 = @fft_scheduler::fft_sched[$i]->{op1_buffer_access};
            my $bufacc2 = @fft_scheduler::fft_sched[$i]->{op2_buffer_access};
            
            # //; printf("//FOOG $i op1_buffer=$bufnum1 op2_buffer=$bufnum2 ".
            # //;        "op1_buffer_access=$bufacc1 op2_buffer_access=$bufacc2\n");

            if ($bufacc1 eq "RD" || $bufacc1 eq "BOTH") { # Really?  BOTH??
                $read_op  |= 2**$bank1; $bufnums[$bank1] = $bufnum1; }
            if ($bufacc1 eq "WR" || $bufacc1 eq "BOTH") {
                $write_op |= 2**$bank1; $bufnums[$bank1] = $bufnum1; }
 
            if ($bufacc2 eq "RD" || $bufacc2 eq "BOTH") {
                $read_op  |= 2**$bank2; $bufnums[$bank2] = $bufnum2; }
            if ($bufacc2 eq "WR" || $bufacc2 eq "BOTH") {
                $write_op |= 2**$bank2; $bufnums[$bank2] = $bufnum2; }
        }
        $i++;
    }
    return ($read_op, $write_op, @bufnums);
 }
 
 sub build_butterfly_unit_indices {

     # Build array of info for constructing wires and io ports, e.g.
     # (
     #   "blank", "", "// Butterfly unit operands\n",  # Title of the list
     #   "[4:0]", "BFLY0_op1_ix_o", "",
     #   "[4:0]", "BFLY0_op2_ix_o", ""
     # )

     my $nbits = fftgen::log2($npoints);
     my $bitrange = sprintf("[%d:0]", $nbits-1);

     my @oplist = ("blank", "", "// Butterfly unit operands\n");
     for (my $i=0; $i<$nunits; $i++) {
         push(@oplist, ($bitrange, "BFLY${i}_op1_ix", ""));
         push(@oplist, ($bitrange, "BFLY${i}_op2_ix", ""));
         if ($nunits > 1) { push(@oplist, ("blank", "", "\n")); }
     }
     return @oplist;
 }
 
 sub build_access_type_array {
     # E.g.   ("blank", "", "// Per-butterfly access type\n",
     #         "[2:0]", "BFLY0_access_type", "",
     #         "[2:0]", "BFLY1_access_type", "",
     #         "[2:0]", "BFLY2_access_type", "",
     #         "[2:0]", "BFLY3_access_type", "",
     #         "[2:0]", "BFLY0_access_type", "")
 
     my $nbits = fftgen::log2($npoints);
     my $bitrange = "[2:0]";
     my @oplist = ("blank", "", "// Per-butterfly access type\n");
     for (my $i=0; $i<$nunits; $i++) {
         push(@oplist, ($bitrange, "BFLY${i}_access_type", ""));
 #         if ($nunits > 1) { push(@oplist, ("blank", "", "\n")); }
     }
     return @oplist;
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright Stephen Richardson and Stanford University.  All rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//              Exclusively Licensed by Chip Genesis Inc.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// The code, the algorithm, or any part of it is not to be copied/reproduced.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// The code, the algorithm, or results from running this code may not be used';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// for any commercial use unless legally licensed.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// For more information please contact';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   Ofer Shacham (Stanford Univ./Chip Genesis)   shacham@alumni.stanford.edu';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   Professor Mark Horowitz (Stanford Univ.)     horowitz@stanford.edu';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Genesis2 is patent pending. For information regarding the patent please';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// contact the Stanford Technology Licensing Office.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '///////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/rtl/fftctl.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
