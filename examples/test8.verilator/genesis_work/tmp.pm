package tmp;
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
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/rtl/tmp.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/rtl/tmp.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/rtl/tmp.vp"
   #    my $t1b = $s * $in2_imag;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_mult #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spmult_t1b (.a(tws), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(t1b), .rnd(3\'b000), .status(status_t1b));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    my $t1 = $t1a - $t1b;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_addsub #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spsub_t1 (.a(t1a), .b(t1b), .z(t1), .op('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sub_op; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '), .rnd(3\'b000), .status(status_t1));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # my $t2 = $s * $in2_real + $c * $in2_imag;
   #    my $t2a = $s * $in2_real;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_mult #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spmult_t2a (.a(tws), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(t2a), .rnd(3\'b000), .status(status_t2a));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    my $t2b = $c * $in2_imag;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_mult #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spmult_t2b (.a(twc), .b(in2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .z(t2b), .rnd(3\'b000), .status(status_t2b));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    my $t2  = $t2a + $t2b;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_addsub #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spadd_t2 (.a(t2a), .b(t2b), .z(t2), .op('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $add_op; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '), .rnd(3\'b000), .status(status_t2));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    my $out2_real = $in1_real - $t1;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_addsub #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spsub_o2r (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t1), .z(out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .op('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sub_op; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '), .rnd(3\'b000), .status(status_o2r));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    my $out2_imag = $in1_imag - $t2;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_addsub #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spsub_o2i (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t2), .z(out2['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .op('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $sub_op; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '), .rnd(3\'b000), .status(status_o2i));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    my $out1_real = $in1_real + $t1;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_addsub #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spadd_o1r (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t1), .z(out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .op('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $add_op; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '), .rnd(3\'b000), .status(status_o1r));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    my $out1_imag = $in1_imag + $t2;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_addsub #(23, 8, 1) // #(sig, exp, compliance (0 or 1)) //cad/synopsys/dc_shell/latest/dw/sim_ver';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spadd_o1i (.a(in1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .b(t2), .z(out1['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']), .op('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $add_op; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '), .rnd(3\'b000), .status(status_o1i));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/rtl/tmp.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
