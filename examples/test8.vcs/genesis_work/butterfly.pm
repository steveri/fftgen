package butterfly;
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
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/rtl/butterfly.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/rtl/butterfly.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/rtl/butterfly.vp"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright 2013, all rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// See below (end of file) for extended copyright information.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# push (@INC, "./rtl"); # Now this happens in "Makefile.local"
 require fftgen;        # log2(), iterate()

 ########################################################################
 # PARAMETERS cause default Genesis output to .v file
 ########################################################################
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- Begin default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 

 my $op_width = parameter
    (Name=>'op_width', Val=>64,
     Doc=>'E.g. 64 (bits) for 32b each complex real+imaginary');

 my $op_type = parameter
    (Name=>'op_type', Val=>"complex float",
     List=>["fix", "float", "complex fix", "complex float", "TEST0", "TEST1", "TEST2", "TEST3", "TEST4", "TEST5"],
     Doc=>'fix=fixed-point, float=floating-point');
 
 ########################################################################

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- End default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # op_width overrides
 my $test_mode = $op_type; # BUG/TOD/FIXME SHOULD NOT NEED!
 if ($test_mode eq "TEST0") { $op_width = 32; }
 if ($test_mode eq "TEST1") { $op_width = 64; }
 if ($test_mode eq "TEST2") { $op_width = 64; }
 if ($test_mode eq "TEST3") { $op_width = 64; }
 if ($test_mode eq "TEST4") { $op_width = 64; }
 if ($test_mode eq "TEST5") { $op_width = 64; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Usage: butterfly(op_width, op_type)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   op_width is total width of each operand (e.g. 64b for 32b each real + imaginary)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   op_type is "float", "fix", "complex float", "complex fix", "TEST0", "TEST1", ...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     input logic fftclk,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     input logic ready,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     input logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] in1,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     input logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] in2,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     input logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] twc, // twiddle (cos)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     input logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] tws, // twiddle (sin)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     output logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] out1,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     output logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] out2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $real="63:32"; # Real
    my $imag="31: 0"; # Imaginary
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($op_type eq "TEST0") {  # Assume 32-bit integer(!)
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out1 = in1 + in2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out2 = in1 + in2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
    elsif ($op_type eq "TEST1") {     # complex integer add
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];                 // Doesn\'t change, always == 1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] + in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];  // Maybe counts 0, 1, 2, 3';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];                 // Doesn\'t change, always == 1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] + in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];  // Maybe counts 0, 1, 2, 3';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
    elsif ($op_type eq "TEST2") {     # complex integer mul
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];                 // Doesn\'t change, always == 2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] * in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];  // Maybe counts 1, 2, 4, 8';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];                 // Doesn\'t change, always == 1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] * in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];  // Maybe counts 1, 2, 4, 8';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
    elsif ($op_type eq "TEST3") {     # complex float mul
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];                 // Doesn\'t change, always == 1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];                 // Doesn\'t change, always == 1';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] * in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $mult_t1 = generate('fpu', 'mult_t1', op=>"mul");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $mult_t1->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] * in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '];';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $mult_t2 = generate('fpu', 'mult_t2', op=>"mul");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $mult_t2->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
    elsif ($op_type eq "TEST4") {     # twiddles only
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      assign out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = twc;     // twiddle_cos';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      assign out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '] = tws;     // twiddle_sin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
   ##############################################################################
    elsif ($op_type eq "TEST5") {     # complex float mul
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] t1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] t1a;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] t1b;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] t2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] t2a;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $op_width/2-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] t2b;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_t1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_t1a;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_t1b;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_t2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_t2a;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_t2b;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_o1r;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_o1i;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_o2r;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [7:0] status_o2i;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $add_op = "1'b0"; my $sub_op = "1'b1";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // $t1 = $c * $in2_real - $s * $in2_imag';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $t1 = $t1a - $t1b';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $t1a = $c * $in2_real';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $t1b = $s * $in2_imag';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      my $sub_t1 = generate('fpu', 'sub_t1', op=>'sub');
      my $mult_t1a = generate('fpu', 'mult_t1a', op=>"mul");
      my $mult_t1b = generate('fpu', 'mult_t1b', op=>'mul');
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sub_t1->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(t1a), .b(t1b), .z(t1));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $mult_t1a->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(twc), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(t1a));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $mult_t1b->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(tws), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(t1b));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // $t2 = $s * $in2_real + $c * $in2_imag;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $t2  = $t2a + $t2b;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $t2a = $s * $in2_real;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $t2b = $c * $in2_imag;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      my $add_t2 = generate('fpu', 'add_t2', op=>'add');
      my $mult_t2a = generate('fpu', 'mult_t2a', op=>'mul');
      my $mult_t2b = generate('fpu', 'mult_t2b', op=>'mul');
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $add_t2->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(t2a), .b(t2b), .z(t2));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $mult_t2a->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(tws), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(t2a));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $mult_t2b->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(twc), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(t2b));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $out1_real = $in1_real + $t1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $out1_imag = $in1_imag + $t2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $out2_real = $in1_real - $t1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // $out2_imag = $in1_imag - $t2;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      my $add_o1r = generate('fpu', 'add_o1r', op=>'add');
      my $add_o1i = generate('fpu', 'add_o1i', op=>'add');
      my $sub_o2r = generate('fpu', 'sub_o2r', op=>'sub');
      my $sub_o2i = generate('fpu', 'sub_o2i', op=>'sub');
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $add_o1r->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t1), .z(out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $add_o1i->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t2), .z(out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sub_o2r->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t1), .z(out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sub_o2i->instantiate; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t2), .z(out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    # sub sr{ my $s = shift; return "\$bitstoshortreal(${s})"; }
    # 06/2019 oops cannot use bitstoshortreal any more b/c verilator
    sub sr{ my $s = shift; return "${s}"; }
    sub r { my $s = shift; return sr("${s}[$real]"); }
    sub i { my $s = shift; return sr("${s}[$imag]"); }
    sub ri{ my $s = shift; return r($s).", ".i($s); }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(fftclk) if (ready) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // #2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 ------------------------");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: in1(r,i)= (bsr\'%08X,bsr\'%08X)", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("in1"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: in2(r,i)= (bsr\'%08X,bsr\'%08X)", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("in2"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: t1  = bsr\'%08X",     $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("t1"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: t1a = bsr\'%08X",     $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("t1a"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: t1b = bsr\'%08X",     $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("t1b"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: t2  = bsr\'%08X",     $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("t2"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: t2a = bsr\'%08X",     $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("t2a"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: t2b = bsr\'%08X",     $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("t2b"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: out1(r,i)= (in1_real+t1, in1_imag+t2) = (bsr\'%08X,bsr\'%08X)",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("out1"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 %5d: out2(r,i)= (in1_real-t1, in1_imag-t2) = (bsr\'%08X,bsr\'%08X)",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("out2"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("%m t5 ------------------------");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'endmodule';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
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
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/rtl/butterfly.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
