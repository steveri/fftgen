package top_fftram;
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
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/tst/top_fftram.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/tst/top_fftram.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/tst/top_fftram.vp"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright 2013, all rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// See below (end of file) for extended copyright information.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 push (@INC, "./rtl");
 require fftgen;       # log2(), iterate()
 
 ########################################################################
 # PARAMETERS cause default Genesist output to .v file
 ########################################################################
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- Begin default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 

 my $npoints = parameter
    #(Name=>'n_fft_points', Val=>16,
    (Name=>'n_fft_points', Val=>8,
     Doc=>'Number of complex data values to process.');

 my $upc = parameter
    (Name=>'units_per_cycle', Val=>1.0,
     Doc=>'Number of butterfly units per cycle (0.25, 0.5, 1.0, 2.0 or 4.0).');
 
 my $op_width = parameter
    (Name=>'op_width', Val=>32,
     Doc=>'E.g. 64 (bits) for 32b each complex real+imaginary');

 my $test_mode = parameter
    (Name=>'test_mode', Val=>"TEST5",
     List=>["TEST0", "TEST1", "TEST2", "TEST3", "TEST4", "TEST5"],
     Doc=>'TEST0: integer adds; TEST1: complex adds; TEST2: complex mults');

 ########################################################################

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- End default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # TEST overrides for op_width, etc.
 if ($test_mode eq "TEST0") { $op_width = 32; }
 if ($test_mode =~ "TEST[1-9]") { $op_width = 64; }  # TEST1, TEST2, TEST3, TEST4, TEST5...

 if ($test_mode eq "TEST5") {
     print "ERROR (top_fftram): TEST5 is supported by top_fft, not top_fftram.\n";
     $npoints = 8;
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # To finish, must go through at least log2(npoints) stages
 # of ($npoints/2) calcs at $nunits = min(1,$upc) calcs per
 # cycle ($upc < 1 is taken care of by clock division).

 my $nunits = ($upc < 1) ? 1 : $upc;
 my $ncy = fftgen::log2($npoints) * ($npoints/2)/$nunits;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating clock unit clock/GCLK...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $gclock = generate
    ('clock','GCLK',
     CLK_PERIOD=>1000, # 5 ns clock period
     RST_PERIOD=>   1, # Currently not used
     MAX_CYCLES=>  ($ncy+6)  # End simulation after complete cycle plus some.
 );
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating fftctl unit fftctl/fftctl (nunits = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', npoints='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $npoints; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ')...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $fftctl = generate
    ('fftctl', 'fftctl',
     n_fft_points   =>$npoints,
     units_per_cycle=>$upc
 );
# my $nunits = $fftctl->{nunits};
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating twiddle unit twiddle/twiddle (nunits = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', npoints='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $npoints; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ')...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $twiddle = generate
    ('twiddle', 'twiddle',
     n_fft_points   =>$npoints,
     units_per_cycle=>$upc,
     data_width     =>($op_width/2)
 );
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating swizzle units swizzle/BFLY[0123]_{in,out}[12]_swizzle...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # E.g. $swizzle{BFLY0_in1} = BFLY0_in1_swizzle etc.
 my %swizzle = ();
 foreach my $io ("in1", "in2", "out1", "out2") {
    for (my $i=0; $i<$nunits; $i++) {
        my $pfx = "BFLY${i}_${io}"; # BFLY0_in1, BFLY0_in2, BFLY0_out1, ...
        $swizzle{$pfx} = generate
            ('swizzle', "${pfx}_swizzle",    # E.g. BFLY0_in1_swizzle
             , n_butterfly_units=>$nunits
             , n_fft_points     =>$npoints
            );
    }
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating fft ram fftram/fftram...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# if ($test_mode =~ /TEST[12]/) { $op_width = 64; } # op_width override (redundant w/above!)
 my $fftram = generate
    ('fftram','fftram'
     , n_butterfly_units=>$nunits
     , n_fft_points     =>$npoints
     , op_width         =>$op_width
     , test_mode        =>$test_mode
 );
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating butterfly unit(s), test mode '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $test_mode; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# In TEST0 mode, all operands == 1 to start, bfly unit adds out = in1 + in2,
# so that, at end, all locations should equal (npoints/2).  Magic!
 my @BFLY = ();
 for (my $i=0;  $i<$nunits; $i++) {
    $BFLY[$i] = generate
            ('butterfly', "BFLY$i"    # E.g. BFLY0, BFLY1, BFLY2, BFLY3
             , op_width=>32
             , op_type=>$test_mode
            );
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# //; foreach my $p (@{$fftctl->{ParametersList}}) {
# //;     my $val = $fftctl->{Parameters}->{$p}->{Val};
# //;     my $doc = $fftctl->{Parameters}->{$p}->{Doc};
# //;     printf("FOO 2a //     %-20s %8s %s\n", $p, "($val)", $doc);
# //; }

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '();';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // BEGIN WIRE DECLARATIONS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    $fftctl->printwires("      ", "wire_list");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    $twiddle->printwires("      ", "wire_list");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nbanks = 4*$nunits;
    #my $awidth = fftgen::log2($npoints);
    my $bwidth = fftgen::log2($nbanks);
    my $rwidth = fftgen::log2($npoints/$nbanks);
    my $bbits = ($bwidth-1).":0";
    my $rbits = ($rwidth-1).":0";
    my $obits = ($op_width-1).":0";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   #    logic [1:0] BFLY0_in1_bnum;      logic [1:0] BFLY0_in2_bnum;
   #    logic [1:0] BFLY0_out1_bnum;      logic [1:0] BFLY0_out2_bnum;
   #    logic [1:0] BFLY0_in1_rnum;      logic [1:0] BFLY0_in2_rnum;
   #    logic [1:0] BFLY0_out1_rnum;      logic [1:0] BFLY0_out2_rnum;
   #
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // in1, in2 data from fftram to butterfly unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$obits] BFLY%d_in1_data;   ",
        "   logic [$obits] BFLY%d_in2_data;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // out1, out2 data from butterfly unit to fftram';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$obits] BFLY%d_out1_data;  ",
        "   logic [$obits] BFLY%d_out2_data;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // NOTE/BUG/TODO/FIXME how stupid this is; i think it\'s always the case that';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // (in1_bnum == out1_bnum) and (in1_rnum == out1_rnum) etc.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle-wires for in1, in2 bank num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$bbits] BFLY%d_in1_bnum;   ",
        "   logic [$bbits] BFLY%d_in2_bnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle-wires for out1, out2 bank num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$bbits] BFLY%d_out1_bnum;   ",
        "   logic [$bbits] BFLY%d_out2_bnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle-wires for in1, in2 row num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$rbits] BFLY%d_in1_rnum;   ",
        "   logic [$rbits] BFLY%d_in2_rnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle-wires for out1, out2 row num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$rbits] BFLY%d_out1_rnum;   ",
        "   logic [$rbits] BFLY%d_out2_rnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // END WIRE DECLARATIONS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # BEGIN SPM TEST__________________________________________________________
    my $spm_test = 1;
    if ($spm_test) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   /////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // http://msdn.microsoft.com/en-us/library/0b34tf65.aspx';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Single-precision multiplier: 64-bit fp is 23, 8';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0] dsa;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0] dsb;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0] dsz;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [ 7:0] status_sp;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   DW_fp_mult #(23, 8, 1)// #(sig, exp, compliance (0 or 1)) ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   spmult (.a(dsa), .b(dsb), .z(dsz), .rnd(3\'b000), .status(status_sp));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      dsa = $shortrealtobits(0.5);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      dsb = $shortrealtobits(0.5);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge start) if (~rst_n) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram_spm: test of single-precision multiplier");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram_spm: dsa_x=%x dsb_x=%x dsz_x=%x", dsa, dsb, dsz);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram_spm: dsa_f=%f dsb_f=%f dsz_f=%f", $bitstoshortreal(dsa), $bitstoshortreal(dsb), $bitstoshortreal(dsz));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram_spm: status=%x", status_sp);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram_spm:");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
   # END SPM TEST____________________________________________________________
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign cycle_num = fftctl_cycle_num;  // Weird?  Contrived?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("\\nfftmem.vp: n_butterfly_units='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' and n_fft_points='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $npoints; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Instantiate swizzle units BFLY0_in1_swizzle, BFLY0_in2_swizzle etc.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   
   #swizzle_unq1  BFLY0_in1_swizzle(.addr_i(BFLY0_in1_ix), .rnum_o(BFLY0_in1_rnum), .bnum_o(BFLY0_in1_bnum));
   
    foreach my $io ("in1", "in2", "out1", "out2") {
       for (my $i=0; $i<$nunits; $i++) {
           my $pfx = "BFLY${i}_${io}";    # BFLY0_in1, BFLY0_in2, BFLY0_out1, ...
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $swizzle{$pfx}->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.addr_i('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix), .rnum_o('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rnum), .bnum_o('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzler translation guide.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(negedge clk) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram swizzle: ix%02d => SRAM%03d mem[%02d]", BFLY0_in1_ix, BFLY0_in1_bnum, BFLY0_in1_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram swizzle: ix%02d => SRAM%03d mem[%02d]", BFLY0_in2_ix, BFLY0_in2_bnum, BFLY0_in2_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    // In TEST0 mode, all operands == 1 to start, bfly unit adds out = in1 + in2,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    // so that, at end, all locations should equal (npoints/2).  Magic!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $i=0; $i<$nunits; $i++) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $BFLY[$i]->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.in1(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_in1_data), // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .in2(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_in2_data),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .twc(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_twiddle_cos),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .tws(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_twiddle_sin),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .out1(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_out1_data),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .out2(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_out2_data)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
     }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // DEBUG/TEST info: cycle_nums';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge clk) if (~rst_n) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#      $display("top_fftram %5d: fftctl_cycle_num=%d", $time, fftctl_cycle_num);
#      $display("top_fftram %5d:        cycle_num=%d",        $time, cycle_num);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram %5d: BFLY0_twiddle_cos = %x (%f)", $time, BFLY0_twiddle_cos,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                                                              $bitstoshortreal(BFLY0_twiddle_cos));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#      $display("top_fftram %5d: BFLY0_twiddle_cos = %f", $time, $bitstoshortreal(BFLY0_twiddle_cos));
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // DEBUG/TEST info: show swizzle translations.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge clk) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    //$display("\\ntop_fftram: ez_i=%1d, wz_i=%d\\n", ez_i, wz_i);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       foreach my $io ("in1", "in2") {
          for (my $i=0; $i<$nunits; $i++) {
              my $pfx = "BFLY${i}_${io}";    # BFLY0_in1, BFLY0_in2, BFLY0_out1, ...
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram %1d: '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ix %02d comes from bank %2d row %3d", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       foreach my $io ("out1", "out2") {
          for (my $i=0; $i<$nunits; $i++) {
              my $pfx = "BFLY${i}_${io}";    # BFLY0_in1, BFLY0_in2, BFLY0_out1, ...
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram %1d: '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix %02d goes to bank %2d row %3d", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fftram");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end // always @ (posedge clk)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Instantiate and connect up the fft memory.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $fftram->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '  // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '       .clk_i(clk)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      my $bitwidth = sprintf("[%d:0]", fftgen::log2($npoints)-1);  #  E.g. "[0:3]" if npoints = 16
            
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // in1, in2 addresses from fftram (bnum)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_in1_bnum_i", "(BFLY%d_in1_bnum)   ",
                            "     ,.BFLY%d_in2_bnum_i", "(BFLY%d_in2_bnum)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // in1, in2 addresses from fftram (rnum)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_in1_rnum_i", "(BFLY%d_in1_rnum)   ",
                            "     ,.BFLY%d_in2_rnum_i", "(BFLY%d_in2_rnum)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // out1, out2 addresses from fftram (bnum)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_out1_bnum_i", "(BFLY%d_out1_bnum)  ",
                            "     ,.BFLY%d_out2_bnum_i", "(BFLY%d_out2_bnum)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // out1, out2 addresses from fftram (rnum)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_out1_rnum_i", "(BFLY%d_out1_rnum)  ",
                            "     ,.BFLY%d_out2_rnum_i", "(BFLY%d_out2_rnum)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Data OUT from fftram (and in) to butterfly units: in1, in2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_in1_data_o", "(BFLY%d_in1_data)    ",
                            "     ,.BFLY%d_in2_data_o", "(BFLY%d_in2_data)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Data IN from butterfly units (and out) to fftram: out1, out2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "    ,.BFLY%d_out1_data_i", "(BFLY%d_out1_data) ",
                            "    ,.BFLY%d_out2_data_i", "(BFLY%d_out2_data)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,.fft_started(busy | start)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '       );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#    // Here's the magic: out = in1 + in2 means that, at end, all locations should equal (npoints/2).
#    //;# assign BFLY0_out1_data = BFLY0_in1_data + BFLY0_in2_data;
#    //;# assign BFLY0_out2_data = BFLY0_in1_data + BFLY0_in2_data;
#    //; print fftgen::iterate($nunits,
#    //;     "   assign BFLY%d_out1_data = ", "BFLY%d_in1_data + ", "BFLY%d_in2_data;\n",
#    //;     "   assign BFLY%d_out2_data = ", "BFLY%d_in1_data + ", "BFLY%d_in2_data;\n\n",);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $real="63:32"; # Real
    my $imag="31: 0"; # Imaginary
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge clk) if (busy | start) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       if ($test_mode eq "TEST0") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1=(in1+in2): %2d = (%1d + %1d)",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $time, BFLY0_out1_data, BFLY0_in1_data, BFLY0_in2_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST1") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1_real=in1_real=%1d", $time, BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1_imag=(in1_real+in1_imag): %1d = (%1d + %1d)", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST2") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1_real=in1_real=%1d", $time, BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1_imag=(in1_real*in1_imag): %2d = (%1d * %1d)", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST3") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1_real=in1_real=%1f", $time, $bitstoshortreal(BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1_imag=(in1_real*in1_imag): %1f = (%1f * %1f)", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $bitstoshortreal(BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $bitstoshortreal(BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $bitstoshortreal(BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST4") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out1_imag = %9.6f", $time, $bitstoshortreal(BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fftram %5d: out2_imag = %9.6f", $time, $bitstoshortreal(BFLY0_out2_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Generate clock and connect it to local wire ".clk"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $gclock->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.clk(clk), .reset(rst_n));       // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $fftctl->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     (                                                       // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        $fftctl->printconnections("      ");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $twiddle->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     (                                                       // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        $twiddle->printconnections("      ");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $vcdpluson(   0  , '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($self->get_top())->mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      //start <= 0; // It\'s STUPID to use "<=" in an initial block (right!??)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      start = 0; // It\'s STUPID to use "<=" in an initial block (right!??)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(negedge rst_n) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      start = 1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      @(posedge clk) begin start = 0; end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
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
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/tst/top_fftram.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
