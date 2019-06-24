package fftram;
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
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/rtl/fftram.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/rtl/fftram.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/rtl/fftram.vp"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright 2013, all rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// See below (end of file) for extended copyright information.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# push (@INC, "./rtl"); # Now this happens when "Makefile.local" (sets PERL5LIB)
 require fftgen;        # log2(), iterate()

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- Begin default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # parameter() calls send default Genesis output to top of .v file

 my $nunits = parameter
    (Name=>'n_butterfly_units', Val=>4,
     Doc=>'Number of butterfly units.');
 
 my $npoints = parameter
    (Name=>'n_fft_points', Val=>16,
     Doc=>'Number of complex data values to process.');

 my $op_width = parameter
    (Name=>'op_width', Val=>32,
     Doc=>'E.g. 64 (bits) for 32b each complex real+imaginary');

 my $SRAM_TYPE = parameter
    (Name=>'SRAM_TYPE', Val=>"1PORT_DBLPUMP",
     List=>["TRUE_1PORT", "TRUE_2PORT", "1PORT_DBLPUMP"],
     Doc=>'What kind of SRAM should the FFT use?');

 my $test_mode = parameter
    (Name=>'test_mode', Val=>"TEST1",
     List=>["TEST0", "TEST1", "TEST2", "TEST3", "TEST4", "TEST5"],
     Doc=>'TEST0: integer adds; TEST1: complex adds; TEST2: complex mults');

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- End default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $PRECOMPUTED_BYPASS = 0;
 my $BYPASS_MECHANISM = 'old';
 my $BYPASS_MECHANISM = 'new';
 
 my $n_sram_ports = ($SRAM_TYPE eq "TRUE_1PORT") ? 1 : 2;
 my $nbanks = 4*$nunits;               # Number of mem banks (SRAMs) we need.
 my $nrows = $npoints/$nbanks;         # Number of rows per mem bank.
 if ($nrows < 1) { $nrows = 1; }       # Need at least one row!!!
 my $bwidth = fftgen::log2($nbanks);   # Number of bits in bank address.
 my $rwidth = fftgen::log2($nrows);    # Number of bits in row address.
 if ($rwidth < 1) { $rwidth = 1; }     # Need at least one bit!!!
 my $bbits = ($bwidth-1).":0";         # Bit range for bank address.
 my $rbits = ($rwidth-1).":0";         # Bit range for row address.
 
 # Number of bits in a data point (e.g. two 32-bit complex values => "[63:0]")
 my $obits = ($op_width-1).":0";       
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// nunits='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' npoints='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $npoints; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' nbanks='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbanks; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' nrows='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nrows; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 
 # Number of bits for cycle_num (when used)
 # i.e. when (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1))
 my $nlevels = fftgen::log2($npoints);            
 my $ncalcs_per_unit = ($nlevels * ($npoints/2))/$nunits;
 # (Note $ncalcs_per_unit may not always be a power of two.)
 my $nbits_cycle_num=0; while ((2**$nbits_cycle_num) <= ($ncalcs_per_unit+1)) { $nbits_cycle_num++; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $real_bits = "63:32";
 my $imag_bits = "31: 0";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # Quick error check
 (($nbanks <= $npoints) || ($n_sram_ports == 2)) # next must be "or" and not "and"
    or $self->error("Too many butterfly units! Must be <= (n_fft_points/4)");

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating SRAMs (SRAM000, SRAM001, SRAM002...SRAM015...)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my %sram = ();
 for (my $i=0; $i<$nbanks; $i++) {
     my $sname = sprintf("SRAM%03d", $i);
     $sram{$i} = generate('SRAM', $sname,
                          nwords=>$nrows,
                          SRAM_TYPE =>$SRAM_TYPE,
                          data_width=>$op_width,
                          test_mode=>$test_mode);
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Usage: fftram(n_butterfly_units, n_fft_points, op_width, test_mode), where';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   n_butterfly_units is the number of butterfly units to build (1,2,4,8,...)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   n_fft_points can be any power of two greater than 8;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   op_width is number of bits per FFT data point, e.g. 64 for 32b real + 32b imaginary';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   test_mode tells what kind of FFT test to build and run e.g. "TEST5"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     input logic clk_i';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // in1, in2 addresses from fftram - bank (SRAM) number bnum';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
     # E.g. ", input logic [3:0] BFLY0_op1_bnum_i, input logic [3:0] BFLY0_op2_bnum_i";
     # for (1 to $nunits-1) (e.g. BFLY0, BFLY1, BFLY2, BFLY3)
      print fftgen::iterate($nunits,
                            "     ,input logic [$bbits] BFLY%d_op1_bnum_i  ",
                            "     ,input logic [$bbits] BFLY%d_op2_bnum_i\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // in1, in2 addresses from fftram - row (index) number rnum';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,input logic [$rbits] BFLY%d_op1_rnum_i  ",
                            "     ,input logic [$rbits] BFLY%d_op2_rnum_i\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Data from fftram to butterfly units: in1, in2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,output logic [$obits] BFLY%d_in1_data_o  ",
                            "     ,output logic [$obits] BFLY%d_in2_data_o\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Data from butterfly units to fftram: out1, out2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,input logic [$obits] BFLY%d_out1_data_i  ",
                            "     ,input logic [$obits] BFLY%d_out2_data_i\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Only used for TRUE_1PORT.  Otherwise, gets eliminated automatically, right?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // ...or...? Shold they be ifdef\'ed?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Bypass controls';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      my $lastbank = 4*$nunits - 1;
      my $bufbits = ($nunits==4)?"[1:0]":"     ";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,input logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] suppress_wz_i  // one bit per bank, set 100 ps after posedge';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      if ($BYPASS_MECHANISM eq 'old') {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,input logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] bypass_read_i  // one bit per bank, set 100 ps after posedge';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,input logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bufbits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' bufnum_i[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']  // which buffer do we use for bypass?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,input logic fft_started';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '  );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // BEGIN WIRE DECLARATIONS__________________________________________________';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # Just printing a comment to make the verilog more readable:
    my $plural = ($nunits == 1) ? "" : "s";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Wires to/from SRAMs:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' butterfly unit'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $plural; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' means we need 4x'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbanks; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' single-port SRAM\'s named e.g. {SRAM000, SRAM001,...SRAM015}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # Wires to/from SRAMs, e.g.
   # logic [3:0] SRAM000_ix; logic [63:0] SRAM000_rd_data; ...
   # logic [3:0] SRAM001_ix; logic [63:0] SRAM001_rd_data; ...
    for (my $i=0; $i<$nbanks; $i++) {
        my $sname = sprintf("SRAM%03d", $i);  # "000", "001", ... "015" etc.
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $rbits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix;   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rd_data;   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wr_data;   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ez;   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wz;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    # no longer optional i guess, everyone needs cycle_num...right? FIXME
    # if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
    if (1 == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // (For now) BOTF: must duplicate fftctl\'s \'cycle_num\' signal so we';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // can conservatively BYPASS ALL FINAL-CYCLE WRITES in a each stage.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME Really shouldn\'t bypass final-stage writes!!!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME Later, can just bring \'cycle_num\' (below) in from fftctl as a signal.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME Or something smarter.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Need to count from 0 to [log2(npoints) x (npoints/2) / (nbutts)]';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // plus at least one beyond that.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbits_cycle_num-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] cycle_num;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic bypass_time;              // Bypass_time==1 when cycle_time says it is time to bypass.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for optional BOTF signals, unused in this configuration (cycle_num).';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // E.g. SRAM001_active=1 during any cycle that we\'re accessing SRAM001 (BOTF).';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    for (my $i=0; $i<$nbanks; $i++) {
       my $sname = sprintf("SRAM%03d", $i);  # "000", "001", ... "015" etc.
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_active;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        }
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for optional BOTF signals, unused in this configuration (SRAM003_active).';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#   //; if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
#   // Trying something new for bypasses: BOTF (bypass on the fly)
#   //; # logic SRAM000_wants_to_read_then_write;
#   //; # logic SRAM001_wants_to_read_then_write;
#   //; # logic SRAM002_wants_to_read_then_write;
#   //; # ...
#   //;     for (my $i=0; $i<$nbanks; $i++) {
#   //;         my $sname = sprintf("SRAM%03d", $i);  # "000", "001", ... "015" etc.
#   logic `$sname`_wants_to_read_then_write; 
#   //;     }
#   //; } else {
#   // Placeholder for optional BOTF signals, unused in this configuration.
#   //; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // BOTF: At end of each stage, there is possibility of read/write';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // conflict where one butterfly wants to write to the (single ported)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // SRAM at the same time another one wants to read from the SRAM.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // When this happens, bypass the write data to the \'bypassed_data\' buffer.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nsrams = $nbanks;
    my $r1 = sprintf("%-6s", "");
    my $r2 = sprintf("%-6s", "[$rbits]");
    my $r3 = sprintf("%-6s", "[$obits]");
    
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $r1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' bypass_valid[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nsrams-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];  // True (1) iff bypassed_data is valid';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $r2; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' bypassed_rnum[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nsrams-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']; // Use target row number (index) of valid data as an ID.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $r3; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' bypassed_data[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nsrams-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']; // Valid data lives here instead of \'rnum\' in SRAM.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
    else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for optional BOTF signals, unused in this configuration.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Only needed when bypass buffers are used; otherwise gets hardwired to rd_data.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nsrams = $nbanks;
    my $r3 = sprintf("%-6s", "[$obits]");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $r3; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' sram_or_buf[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nsrams-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']; // Staging area for read data.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   ##################################################################################
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // (op1,op2)_"match" wires TRUE iff (op1,op2) address matches SRAM id ([0], [1], ...)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' butterfly unit'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $plural; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' means we need 4x'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbanks; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' single-port SRAM\'s named e.g. {SRAM000, SRAM001,...SRAM015}';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   
   # E.g.:  "logic BFLY0_op1_match[0:7];   logic BFLY0_op2_match[0:7];"
    for (my $i=0; $i < $nunits; $i++) {
        my $bfly = "BFLY$i";
        my $nn = sprintf("%2d", $nbanks-1);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_match[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];    logic '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_match[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($BYPASS_MECHANISM eq 'old') {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Bypass controls';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nbanks = 4 * $nunits;
    my $lastbank = $nbanks - 1;
    my $bufbits = ($nunits==4)?"[1:0]":"     ";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Need one bypass buffer for each butterfly unit.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($nunits==1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $obits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] bypass_buffer;         // Bypass buffer';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   
    } elsif ($nunits==2) {   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $obits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] bypass_buffer[0:1];    // Two bypass buffers';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   
    } else {   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $obits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] bypass_buffer[0:3];    // Four bypass buffers';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // For debugging the bypass buffer contents.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0]     bbr[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];  // Real part of value in bypass buffer.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0]     bbi[0:'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $lastbank; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];  // Imag part of value in bypass buffer.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // For a clean waveform view...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial bypass_buffer = {default:\'x}; // Tricky...!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // LOOK MA NO BYPASS BUFFER';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#   //; if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
#   // Initialize BOTF (bypass on the fly) signals
#   //; # SRAM000_wants_to_read_then_write <= 0; 
#   //; # SRAM001_wants_to_read_then_write <= 0; 
#   //; # SRAM002_wants_to_read_then_write <= 0; 
#   //; # ...
#   initial begin
#   //; for (my $i=0; $i<$nbanks; $i++) {
#   //;     my $sname = sprintf("SRAM%03d", $i);  # "000", "001", ... "015" etc.
#      `$sname`_wants_to_read_then_write <= 0; 
#   //; }
#   end
#   //; } else {
#   // Placeholder for initialization of optional BOTF signals, unused in this configuration (sram_wants...).
#   //; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    # FIXME cycle_num no longer optional i guess...
    # if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
    if (1 == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Initialize BOTF (bypass on the fly) signals (cycle_num)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial cycle_num <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbits_cycle_num; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for initialization of optional BOTF signals, unused in this configuration (cycle_num).';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Initialize BOTF (bypass on the fly) signals';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // bypass_valid:  True (1) iff bypassed_data is valid';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // bypassed_rnum: Use target row number (index) of valid data as an ID.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // bypassed_data: Valid data lives here instead of \'rnum\' in SRAM.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    # ...
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // \'x means "set all bits to x", or so I\'m told.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    for (my $i=0; $i<$nbanks; $i++) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      bypass_valid['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']=1\'b0;  bypassed_rnum['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $rwidth; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;  bypassed_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']=\'x;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for initialization of optional BOTF signals, unused in this configuration.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // END WIRE DECLARATIONS____________________________________________________';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($BYPASS_MECHANISM eq 'old') {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial assert (1) $warning("WARNING Using OLD bypass mechanism.");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    # FIXME cycle_num no longer optional i guess...
    # if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
    if (1 == 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge clk_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // FIXME FIXME FIXME OH NO!!! waveform shows this';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     //   cycle_num != top_fft cycle_num !! :( :(';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     if (fft_started == 1) cycle_num <= cycle_num + 1\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     else cycle_num <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbits_cycle_num; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge clk_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftctl %1d: cycle_num = %1d BOTF", $time, cycle_num);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // On first cycle of each stage (except stage 0), set bypass_time==1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // to indicate that we will bypass ALL (active bnum-match) WRITES';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nstages      = fftgen::log2($npoints);     # Right?
    my $cy_per_stage = ($npoints/2)/$nunits;       # Right?
    my $cymask       = $cy_per_stage - 1;          # Right?
    my $tot_cycles   = $cy_per_stage * $nstages;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign bypass_time = ((cycle_num > 0) &&';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                         (cycle_num < '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $tot_cycles; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') &&';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                         ((cycle_num & '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $cymask; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') == 0)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                         ) ? 1\'b1 : 1\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for optional BOTF signals, unused in this configuration.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Instantiate SRAM\'s (SRAM000, SRAM001, SRAM002...SRAM015) (.remote(local))';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # E.g.: SRAM_unq1  SRAM000( .clk_i(clk_i), .ez_i(SRAM000_ez), .wz_i(SRAM000_wz), .addr_i(SRAM000_ix), .rd_data_o(SRAM000_rd_data), .wr_data_i(SRAM000_wr_data) );
   # E.g.: SRAM_unq1  SRAM001( .clk_i(clk_i), .ez_i(SRAM001_ez), .wz_i(SRAM001_wz), .addr_i(SRAM001_ix), .rd_data_o(SRAM001_rd_data), .wr_data_i(SRAM001_wr_data) );
   # TODO: should probably be an array...!
    for (my $i=0; $i<$nbanks; $i++) {
        my $sname = sprintf("SRAM%03d", $i);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sram{$i}->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '( .clk_i(clk_i), .ez_i('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ez), .wz_i('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wz), .addr_i('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix), .rd_data_o('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rd_data), .wr_data_i('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wr_data) );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // ez signals for SRAMs';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $new_timing = 0;
    my ($open_paren, $close_paren) = ("(", ")"); # Yeah, this is readable.
   
    for (my $snum=0; $snum<$nbanks; $snum++) {
        my $sram = sprintf("SRAM%03d", $snum);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sram; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ez = ~fft_started | ~'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $open_paren; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $i=0; $i < $nunits; $i++) {
            if ($i < ($nunits-1)) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        (BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_bnum_i == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ) | (BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_bnum_i == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ) |';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        (BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_bnum_i == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ) | (BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_bnum_i == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ) | ~'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ${sram}; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wz '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $close_paren; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ';';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            }
        }
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Bypass buffer control signals.  Only used for TRUE_1PORT.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Otherwise...what...gets eliminated automatically, right?  BUG/FIXME/TODO';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#    // Big trouble if don't initialize bypass_buffer control signals.
#    always @(posedge fft_started) suppress_wz <= 0;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $real=$real_bits; # E.g. "63:32" = real part
    my $imag=$imag_bits; # E.g. "31: 0" = imaginary part
    # sub sr{ my $s = shift; return "\$bitstoshortreal(${s})"; }
    # 06/2019 oops cannot use bitstoshortreal any more b/c verilator
    sub sr{ my $s = shift; return "${s}"; }
    sub r { my $s = shift; return sr("${s}[$real]"); }
    sub i { my $s = shift; return sr("${s}[$imag]"); }
    sub ri{ my $s = shift; return r($s).", ".i($s); }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // NOTE also need this if there\'s no bypass at all e.g. when nports > 1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($BYPASS_MECHANISM eq 'old') {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Ugly but necessary...solely for debugging the bypass buffer...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    for (my $i = 0; $i < $nbanks; $i++) {
        my $nn  = sprintf("%2d", $i);
        my $nnn = sprintf("%03d", $i);
        my $buffer = ($nunits==1) ? "bypass_buffer" : "bypass_buffer[bufnum_i[$nn]]";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign {bbr['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], bbi['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']} = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $buffer; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '; // Separate 64bit complex into two 32bit components.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // TODO: could probably replace ugly repetitive "$display" calls w/single beautiful "task".';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ (posedge clk_i) begin ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       for (my $i = 0; $i < $nbanks; $i++) {
           my $nn  = sprintf("%2d", $i);
           my $bufnum = ($nunits==1) ? "0" : "bufnum_i[$nn]";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if (bypass_read_i['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '])';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftram %6d Bypassed SRAM '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', read  (bsr\'%08X,bsr\'%08X) from bypass_buffer[%1d]",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $time, bbr['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], bbi['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bufnum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // LOOK MA NO BYPASS BUFFER';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ (posedge clk_i) begin ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %6d bypass_valid[2]=%1d SRAM002_active=%1d bypassed_rnum[2]=%1d SRAM002_ix=%1d GLOOP",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               $time,  bypass_valid[2], SRAM002_active, bypassed_rnum[2], SRAM002_ix);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    for (my $s=0; $s<$nbanks; $s++) {
        my $sname = sprintf("SRAM%03d", $s);  # "000", "001", ... "015" etc.
   # if ((`$sname`_ix == bypassed_rnum[`$s`]) && (bypass_valid[`$s`] == 1)) begin
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if ((bypass_valid['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] == 1\'b1) &&';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '          ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_active == 1) &&';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '          ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix == bypassed_rnum['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '])';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         bypass_valid['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = 1\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftram %6d Bypassed SRAM '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', read  (bsr\'%08X,bsr\'%08X) from bypassed_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] BOTF", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                   bypassed_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real_bits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], // Real part';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                   bypassed_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag_bits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']); // Imaginary part';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for optional BOTF signals, unused in this configuration.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($BYPASS_MECHANISM eq 'old') {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // If suppress_wz was set (at posedge clk above), we suppress write to the';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // indicated SRAM.  Contents originally destined for SRAM now go to bypass_buffer.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // If I were more paranoid, maybe each case would get its own "@ (negedge clk)"?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ (posedge clk_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      #
      #  if (suppress_wz[ 0]) bypass_buffer[bufnum_i[ 0]] <= SRAM000_wr_data;
      #  if (suppress_wz[ 1]) bypass_buffer[bufnum_i[ 1]] <= SRAM001_wr_data;
      #  ...
      #  if (suppress_wz[15]) bypass_buffer[bufnum_i[15]] <= SRAM015_wr_data;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // TODO again, replace ugly repetitive $display w/a task.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // if nunits == 1 this (suppress_wz) is one-hot (or zero)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       for (my $i = 0; $i < $nbanks; $i++) {
           my $nn  = sprintf("%2d", $i);
           my $nnn = sprintf("%03d", $i);
           my $bufnum = ($nunits==1) ? "" : "[bufnum_i[$nn]]";
           my $bufnum2 = ($nunits==1) ? "0" : "bufnum_i[$nn]";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if (suppress_wz_i['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         bypass_buffer'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bufnum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' <= SRAM'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nnn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wr_data;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("fftram %6d Bypassed SRAM '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', wrote (bsr\'%08X,bsr\'%08X) to bypass_buffer[%1d]",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("SRAM${nnn}_wr_data"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bufnum2; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // LOOK MA NO BYPASS BUFFER mano mano';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // wz signals.  If Anyone wants to access a given bank n (op1_bnum==1),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // set wz(n) (to zero), unless suppress_wz says not to.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # The timing changes according to whether we have a 1port or a 2port SRAM.
    my ($wz_event, $wz_value);
   
    my ($open_paren, $close_paren) = ("(", ")"); # Yeah, this is readable.
    for (my $snum=0; $snum<$nbanks; $snum++) {
        my $sram = sprintf("SRAM%03d", $snum);
        if ($n_sram_ports == 2) {
            $wz_event = "clk_i";
            $wz_value = "clk_i";
        }
        elsif ($n_sram_ports == 1) {
            $wz_event = "posedge clk_i";
            $wz_value = "suppress_wz_i[$snum]";
        }
   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $wz_event; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if (cycle_num == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nbits_cycle_num; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\'b0) '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ${sram}; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wz = 1\'b1; else';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if ( fft_started & (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        my $i; for ($i=0; $i < ($nunits-1); $i++) {
        print "         (BFLY${i}_op1_bnum_i == $snum ) | (BFLY${i}_op2_bnum_i == $snum ) |\n";
        }
        print "         (BFLY${i}_op1_bnum_i == $snum ) | (BFLY${i}_op2_bnum_i == $snum )\n";
        print "      )) begin\n";
        print "         ${sram}_wz = $wz_value;\n";
        if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {    # BOTF
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '          // \\$display(\\"FLOOF BOTF %1d okay want to write ${sram}\\", \\$time);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         if (bypass_time == 1) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            // FIXME really need a task here, no?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            $display("FLOOF %1d prev was 1, swz is 0 (suppress) - I predicted it!!!", $time);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            //assert (1) $fatal("ERROR ha ha JK\\n\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            bypass_valid['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']  <= 1\'b1;              // True (1) means bypassed_data is valid';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            bypassed_rnum['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sram; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix;     // Use target row number (index) of valid data as an ID.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            bypassed_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] <= '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sram; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wr_data; // Valid data lives here instead of \'rnum\' in SRAM.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '            $display("fftram %6d Bypassed SRAM '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', wrote (bsr\'%08X,bsr\'%08X) to bypassed_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] BTOF row %1d", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("${sram}_wr_data"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ',';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                     bypassed_rnum['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      else begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ${sram}; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wz = 1\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(clk_i) if (fft_started) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: fft_started = %1d", $time, fft_started);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: BFLY0_op1_bnum_i = %1d", $time, BFLY0_op1_bnum_i);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM000_ez = %1d", $time, SRAM000_ez);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM001_ez = %1d", $time, SRAM001_ez);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM002_ez = %1d", $time, SRAM002_ez);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM003_ez = %1d", $time, SRAM003_ez);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM000_wz = %1d", $time, SRAM000_wz);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM001_wz = %1d", $time, SRAM001_wz);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM002_wz = %1d", $time, SRAM002_wz);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: SRAM003_wz = %1d", $time, SRAM003_wz);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // SRAM address (ix) to access.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Ugh. vcs version works b/c address is x and it doesn\'t know where to write bad value';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // and so it doesn\'t write anything, which is the real desired behavior.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Solution is to disable ez and/or wz when value would otherwise be x';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME/TODO after things are fixed and working, disable the stupid x\'s!!!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    for (my $snum=0; $snum<$nbanks; $snum++) {
        my $sram = sprintf("SRAM%03d", $snum);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sram; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix = ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $i=0; $i < $nunits; $i++) {
            my $term = ($i == ($nunits-1)) ? ": 'x;" : ":";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        (BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_bnum_i  == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ) ? BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_rnum_i  : (BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_bnum_i  == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ) ? BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_rnum_i '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $term; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        }
        print "\n";
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    foreach my $p ("1", "2") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // op'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $p; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' match signals';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $i=0; $i < $nunits; $i++) { my $bfly = "BFLY$i";
            for (my $snum=0; $snum<$nbanks; $snum++) {
                my $m = sprintf("match[%03d]", $snum);
                my $s = sprintf("%2d", $snum);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $p; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_match['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $p; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum_i == '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ') ? 1\'b1 : 1\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            }
        print "\n";
        }
        print "\n";
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($n_sram_ports > 1) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // E.g. assign sram_or_buf[0] = SRAM000_rd_data;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $snum=0; $snum<$nbanks; $snum++) {
            my $nn = sprintf("%2d", $snum);
            my $nnn = sprintf("%03d", $snum);
            my $bufnum = ($nunits==1)? "" : "[bufnum_i[$nn]]"; # FIXME this $bufnum not used, right?
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign sram_or_buf['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = SRAM'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nnn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rd_data;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        }
    }
    elsif ($BYPASS_MECHANISM eq 'old') {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // assign sram_or_buf[0] = bypass_read_i[0] ? bypass_buffer : SRAM000_rd_data;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $snum=0; $snum<$nbanks; $snum++) {
            my $nn = sprintf("%2d", $snum);
            my $nnn = sprintf("%03d", $snum);
            my $bufnum = ($nunits==1)? "" : "[bufnum_i[$nn]]";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign sram_or_buf['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = bypass_read_i['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] ? bypass_buffer'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bufnum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' : SRAM'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nnn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rd_data;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        }
    }
    else {
        for (my $snum=0; $snum<$nbanks; $snum++) {
            my $nn = sprintf("%2d", $snum);
            my $sname = sprintf("SRAM%03d", $snum);
            my $bufnum = ($nunits==1)? "" : "[bufnum_i[$nn]]";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign sram_or_buf['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      (bypass_valid['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] == 1\'b1) &&';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_active  == 1) &&';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix     == bypassed_rnum['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '])';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ) ? bypassed_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] : '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rd_data;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        }
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    foreach my $p ("1", "2") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // SRAM data in'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $p; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' OUT from sram (or bypass buffer) to butterfly unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #   assign BFLY0_in1_data_o =                   <=  BUG/FIXME/TODO inaccurate
   #      ( BFLY0_op1_match[0] ) ? (bypass000 ? (buf000 : SRAM000_rd_data)) :
   #      ( BFLY0_op1_match[1] ) ? (bypass001 ? (buf001 : SRAM001_rd_data) :
   #      ( BFLY0_op1_match[2] ) ? (bypass002 ? (buf002 : SRAM002_rd_data) :
   #      ( BFLY0_op1_match[3] ) ? (bypass003 ? (buf003 : SRAM003_rd_data) : 'x;
        for (my $i=0; $i < $nunits; $i++) { my $bfly = "BFLY$i";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_in'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $p; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_data_o =';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            for (my $snum=0; $snum<$nbanks; $snum++) {
                my $nn = sprintf("%2d", $snum);
                my $nnn = sprintf("%03d", $snum);
                my $term = ($snum == ($nbanks-1)) ? ": 'x;" : ":";
                my $bufnum = ($nunits==1)? "" : "[bufnum_i[$nn]]";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $p; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_match['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] ? sram_or_buf['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $term; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            }
            print "\n";
        }
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // SRAM data (out1,out2) IN to sram (or bypass buffer) from butterfly unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $snum=0; $snum<$nbanks; $snum++) {
            my $nnn = sprintf("%03d", $snum);
            my $nn  = sprintf("%2d", $snum);
   
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign SRAM'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nnn; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_wr_data =';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            for (my $i=0; $i < $nunits; $i++) { my $bfly = "BFLY$i";
                my $term = ($i == ($nunits-1)) ? " 'x;" : "";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_match['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] ? '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_out1_data_i : '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_match['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $snum; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] ? '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bfly; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_out2_data_i :'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $term; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            }
        }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge clk_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // Along for the ride...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: BFLY0_op1_match[0] = %1d", $time, BFLY0_op1_match[0]);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("fftram %1d: BFLY0_out1_data_i = %16x", $time, BFLY0_out1_data_i);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#  $display("fftram %1d: SRAM000_wr_data   = %16x", $time, SRAM000_wr_data);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                                ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    # assign SRAM002_active = BFLY0_op1_match[2] | BFLY0_op2_match[2];
    if (($PRECOMPUTED_BYPASS == 0) && ($n_sram_ports == 1)) {
        for (my $s=0; $s<$nbanks; $s++) {
            my $sname = sprintf("SRAM%03d", $s);  # "000", "001", ... "015" etc.
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_active =';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            for (my $b=0; $b<$nunits; $b++) {
                my $term = ($b == $nunits-1) ? ";" : " |";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_match['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] | BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_match['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $s; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $term; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
            }
            print "\n";
        }
    } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Placeholder for optional BOTF signals, unused in this configuration.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'endmodule';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
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
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/rtl/fftram.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
