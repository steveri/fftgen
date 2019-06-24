package top_fft;
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
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/tst/top_fft.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/tst/top_fft.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/tst/top_fft.vp"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright 2013, all rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// See below (end of file) for extended copyright information.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# push (@INC, "./rtl"); # Now this happens when "Makefile.local" (sets PERL5LIB)
 require fftgen;        # log2(), iterate()
 require twiddle;
 require sram_init;     # swizzled_test_pattern()

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- Begin default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # parameter() calls send default Genesis output to top of .v file
 
 my $npoints = parameter
    (Name=>'n_fft_points', Val=>8, List=>[8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192],
     Doc=>'Number of complex data values to process.');
 
 my $upc = parameter
    (Name=>'units_per_cycle', Val=>1.0, List=>[0.25, 0.50, 1.0, 2.0, 4.0],
     Doc=>'Butterfly units per cycle (0.25, 0.5, 1.0, 2.0 or 4.0).');
 
 my $SRAM_TYPE = parameter
    (Name=>'SRAM_TYPE', Val=>"TRUE_1PORT",
     List=>["TRUE_1PORT", "TRUE_2PORT", "1PORT_DBLPUMP"],
     Doc=>'What kind of SRAM should the FFT use?');
 
 my $op_width = parameter
    (Name=>'op_width', Val=>64, List=>[64], Force=>1,
     Doc=>'For now only option is 64 (bits) for 32b each complex real+imaginary');
 
 my $swizzle_algorithm = parameter
    (Name=>'swizzle_algorithm', Val=>"round7",
     List=>["round7", "mod_bn_combo", "takala"],
     Doc=>'round7 is the only one that works(!)');
 
 my $test_mode = parameter
    (Name=>'test_mode', Val=>"TEST5", Force=>1,
     List=>["TEST0", "TEST1", "TEST2", "TEST3", "TEST4", "TEST5"],
     Doc=>'TEST0: integer adds; TEST1: complex adds; TEST2: complex mults');
 
 
 my $SIMULATOR = parameter
    (Name=>'SIMULATOR', Val=>"verilator",
     List=>["verilator", "vcs"],
 	Doc=>'Simulator: "verilator" or "vcs"');

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- End default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # Should match identical line(s) in fftram.vp
 my $BYPASS_MECHANISM = 'old';
 my $BYPASS_MECHANISM = 'new';
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # TEST can override op_width, etc. settings.
 if ($test_mode eq "TEST0") { $op_width = 32; }
 if ($test_mode =~ "TEST[1-9]") { $op_width = 64; }  # TEST1, TEST2, TEST3, TEST4, TEST5...

 # To finish, must go through at least log2(npoints) stages
 # of ($npoints/2) calcs at $nunits = min(1,$upc) calcs per
 # cycle ($upc < 1 is taken care of by clock division).

 my $nunits = ($upc < 1) ? 1 : $upc;
 my $ncy = fftgen::log2($npoints) * ($npoints/2)/$upc;
 my $endtime = $ncy + 6; # End simulation after complete cycle plus some.

 my $gclock = "";
 if ($SIMULATOR eq "vcs") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating clock unit clock/GCLK (vcs only)...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   $gclock = generate
      ('clock','GCLK',
       SIMULATOR=>$SIMULATOR, # vcs or verilator
       CLK_PERIOD=>1000,      # 5 ns clock period
       RST_PERIOD=>   1,      # Currently not used
       MAX_CYCLES=>  $endtime # End simulation after complete cycle plus some.
   );
 } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Clock will be supplied by verilator...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generating fftctl unit fftctl/fftctl (nunits = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', npoints='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $npoints; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ')...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $fftctl = generate
    ('fftctl', 'fftctl'
     , n_fft_points    =>$npoints
     , units_per_cycle =>$upc
     , SRAM_TYPE       =>$SRAM_TYPE
     , swizzle_algorithm=>$swizzle_algorithm
 );
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
 # E.g. $swizzle{BFLY0_op1} = BFLY0_op1_swizzle etc.
 my %swizzle = ();
 foreach my $io ("op1", "op2") {
    for (my $i=0; $i<$nunits; $i++) {
        my $pfx = "BFLY${i}_${io}";          # E.g. "BFLY0_op1, BFLY0_op2"
        $swizzle{$pfx} = generate
            ('swizzle', "${pfx}_swizzle",    # E.g. "BFLY0_op1_swizzle"
             , n_butterfly_units=>$nunits
             , n_fft_points     =>$npoints
             , swizzle_algorithm=>$swizzle_algorithm
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
     , SRAM_TYPE        =>$SRAM_TYPE
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
# If you wanted to print a(nother) summary of the parameters, here's how you'd do it.
#
# //; foreach my $p (@{$fftctl->{ParametersList}}) {
# //;     my $val = $fftctl->{Parameters}->{$p}->{Val};
# //;     my $doc = $fftctl->{Parameters}->{$p}->{Doc};
# //;     printf("FOO 2a //     %-20s %8s %s\n", $p, "($val)", $doc);
# //; }

 if ($SIMULATOR eq "vcs") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '();';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '( input logic clk, output wire done );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // BEGIN WIRE DECLARATIONS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    $fftctl->printwires("   ", "wire_list");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME FIXME cycle_num below different than cycle_num signals in fftram, fftctl !!! :(';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    twiddle_lib::printwires("   ", "wire_list");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nbanks = 4*$nunits;             # SRAM banks, four for each butterfly.
    if (($swizzle_algorithm eq 'round7') && ($nbanks > $npoints)) { $nbanks = $npoints; } # FIXME little hacky hack here.
    my $bwidth = fftgen::log2($nbanks);
    my $bbits = ($bwidth-1).":0";
   
    my $rwidth = fftgen::log2($npoints/$nbanks); # SRAM rows
    if ($rwidth < 1) { $rwidth = 1; }     # Need at least one bit!!!
    my $rbits = ($rwidth-1).":0";
   
    my $obits = ($op_width-1).":0";     # Operand width (e.g. 64 => 32bit complex)
   
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
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle-wires for op1, op2 bank num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$bbits] BFLY%d_op1_bnum;   ",
        "   logic [$bbits] BFLY%d_op2_bnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle-wires for op1, op2 row num';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$rbits] BFLY%d_op1_rnum;   ",
        "   logic [$rbits] BFLY%d_op2_rnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // END WIRE DECLARATIONS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Because fftctl calls it one thing and twiddle calls it something else.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign cycle_num = fftctl_cycle_num;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // *Verilator* don\'t know from no $shortrealtowhatever';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // So instead of $shortrealtobits(1) we get...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0] _shortrealtobits_0 = 32\'h0000_0000;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0] _shortrealtobits_1 = 32\'h3f80_0000;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    if ($test_mode eq "TEST5") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // Generate a square wave to test the FFT, e.g.:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // @a_real = (1, 0, 1, 0,  1, 0, 1, 0);    // bitreverse(1,1,1,1,  0,0,0,0)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // @a_imag = (0, 0, 0, 0,  0, 0, 0, 0);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      
      # // ix=0 => bank 0, row 0 <= ( 1.000,  0.000)
      # top_fft.fftram.SRAM000.mem[0][`$real`] = _shortrealtobits_1;
      # top_fft.fftram.SRAM000.mem[0][`$imag`] = _shortrealtobits_0;
      #
      # // ix=1 => bank 3, row 0 <= ( 0.000,  0.000)
      # top_fft.fftram.SRAM003.mem[0][`$real`] = _shortrealtobits_0;
      # top_fft.fftram.SRAM003.mem[0][`$imag`] = _shortrealtobits_0;
      # ...
      
       my $real="63:32"; # Real
       my $imag="31: 0"; # Imaginary
       sram_init::swizzled_test_pattern("      ", $npoints, $nunits, $real, $imag, "sq_wave", $swizzle_algorithm);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("\\nfftmem.vp: n_butterfly_units='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' and n_fft_points='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $npoints; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '\\n");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 if ($SIMULATOR eq "vcs") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Generate clock and connect it to local wire ".clk" (vcs only)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $gclock->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.clk(clk), .reset(rst_n));       // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Clock will be supplied by verilator; "clock_unq1" is for vcs only.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // clock_unq1  GCLK(.clk(clk), .reset(rst_n));       // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Instantiate swizzle units BFLY0_op1_swizzle, BFLY0_op2_swizzle etc.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   
   #swizzle_unq1  BFLY0_op1_swizzle(.addr_i(BFLY0_op1_ix), .rnum_o(BFLY0_op1_rnum), .bnum_o(BFLY0_op1_bnum));
   
    foreach my $io ("op1", "op2") {
       for (my $i=0; $i<$nunits; $i++) {
           my $pfx = "BFLY${i}_${io}";    # BFLY0_op1, BFLY0_op2
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $swizzle{$pfx}->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.addr_i('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix), .rnum_o('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rnum), .bnum_o('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzler translation guide.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge fftclk) if (cycle_num > 0) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       for (my $i = 0; $i < $nunits; $i++) {
          my $b = "BFLY$i"; # BFLY0, BFLY1, BFLY2...
#  $display("top_fft swizzle: ix%02d => SRAM%03d mem[%02d]", `$b`_op1_ix, `$b`_op1_bnum, `$b`_op1_rnum);
#  $display("top_fft swizzle: ix%02d => SRAM%03d mem[%02d]", `$b`_op2_ix, `$b`_op2_bnum, `$b`_op2_rnum);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft swizzle %5d: '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1 ix%02d => SRAM%03d mem[%02d]", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_ix, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_bnum, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op1_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft swizzle %5d: '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2 ix%02d => SRAM%03d mem[%02d]", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_ix, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_bnum, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $b; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_op2_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    // In TEST0 mode, all operands == 1 to start, bfly unit adds out = in1 + in2,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    // so that, at end, all locations should equal (npoints/2).  Magic!';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        for (my $i=0; $i<$nunits; $i++) {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $BFLY[$i]->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.fftclk(fftclk),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .ready(~rst_n & (busy|start)), // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .in1(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_in1_data),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .in2(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_in2_data),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .twc(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_twiddle_cos),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .tws(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_twiddle_sin),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .out1(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_out1_data),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               .out2(BFLY'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $i; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_out2_data)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                               );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
     }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // DEBUG/TEST info: twiddle_cos, apparently.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge fftclk) if (~rst_n) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %5d: BFLY0_twiddle_cos = %x (bsr\'%08X)",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               $time, BFLY0_twiddle_cos, BFLY0_twiddle_cos);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // DEBUG/TEST info: show swizzle translations.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME I think this is supposed to be "negedge fftclk..?"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME originally displayed at 602, 1602, 2602,...right???';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ (fftclk) if (fftclk==1) begin   // 602,1602,2602...(?)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       foreach my $io ("op1", "op2") {
          for (my $i=0; $i<$nunits; $i++) {
              my $pfx = "BFLY${i}_${io}";    # BFLY0_op1, BFLY0_op2, BFLY1_op1...
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %1d: '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ix %02d comes from bank %2d row %3d", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '               '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end // always @ (posedge fftclk)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Instantiate the fft memory and connect to it..';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $fftram->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '  // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '       .clk_i(fftclk)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      my $bitwidth = sprintf("[%d:0]", fftgen::log2($npoints)-1);  #  E.g. "[0:3]" if npoints = 16
            
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // op1, op2 addresses from fftram (bnum)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_op1_bnum_i", "(BFLY%d_op1_bnum)   ",
                            "     ,.BFLY%d_op2_bnum_i", "(BFLY%d_op2_bnum)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // op1, op2 addresses from fftram (rnum)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_op1_rnum_i", "(BFLY%d_op1_rnum)   ",
                            "     ,.BFLY%d_op2_rnum_i", "(BFLY%d_op2_rnum)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Data OUT from fftram (and in) to butterfly units: in1, in2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_in1_data_o", "(BFLY%d_in1_data)    ",
                            "     ,.BFLY%d_in2_data_o", "(BFLY%d_in2_data)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Data IN from butterfly units (and out) to fftram: out1, out2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      print fftgen::iterate($nunits,
                            "     ,.BFLY%d_out1_data_i", "(BFLY%d_out1_data) ",
                            "     ,.BFLY%d_out2_data_i", "(BFLY%d_out2_data)\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     // Bypass controls';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,.suppress_wz_i(suppress_wz)  // one bit per bank, set 100 ps after posedge';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      if ($BYPASS_MECHANISM eq 'old') {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,.bypass_read_i(bypass_read)  // one bit per bank, set 100 ps after posedge';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,.bufnum_i(bufnum)            // which buffer do we use for bypass?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
      }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     ,.fft_started(busy | start)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $real="63:32"; # Real
    my $imag="31: 0"; # Imaginary
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Per-test display info for debugging.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge fftclk) if (busy | start) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       if ($test_mode eq "TEST0") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1=(in1+in2): %2d = (%1d + %1d)",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $time, BFLY0_out1_data, BFLY0_in1_data, BFLY0_in2_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST1") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1_real=in1_real=%1d", $time, BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1_imag=(in1_real+in1_imag): %1d = (%1d + %1d)", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST2") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1_real=in1_real=%1d", $time, BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1_imag=(in1_real*in1_imag): %2d = (%1d * %1d)", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '], BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST3") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1_real=in1_real=%1f", $time, $bitstoshortreal(BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1_imag=(in1_real*in1_imag): %1f = (%1f * %1f)", $time,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $bitstoshortreal(BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $bitstoshortreal(BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $real; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  $bitstoshortreal(BFLY0_in1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST4") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out1_imag = bsr\'%08X", $time, BFLY0_out1_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft %5d: out2_imag = bsr\'%08X", $time, BFLY0_out2_data['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $imag; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ']);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       } elsif ($test_mode eq "TEST5") {
         
          # sub sr{ my $s = shift; return "\$bitstoshortreal(${s})"; }
          # 06/2019 oops cannot use bitstoshortreal any more b/c verilator
          sub sr{ my $s = shift; return "${s}"; }
          sub r { my $s = shift; return sr("${s}[$real]"); }
          sub i { my $s = shift; return sr("${s}[$imag]"); }
          sub ri{ my $s = shift; return r($s).", ".i($s); }
         
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5 %5d: in1(r,i)= (bsr\'%08X,bsr\'%08X)", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("BFLY0_in1_data"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5 %5d: in2(r,i)= (bsr\'%08X,bsr\'%08X)", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("BFLY0_in2_data"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5 %5d: tw_cos  =     bsr\'%08X", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("BFLY0_twiddle_cos"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5 %5d: tw_sin  =     bsr\'%08X", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } sr("BFLY0_twiddle_sin"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5 %5d: out1(r,i)= (bsr\'%08X,bsr\'%08X)", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("BFLY0_out1_data"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5 %5d: out2(r,i)= (bsr\'%08X,bsr\'%08X)", $time, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ri("BFLY0_out2_data"); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_fft t5");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
         
       } else {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      //$display("top_fft %5d: in1 = %1d, in2 = %1d => out1 = %1d", $time, BFLY0_in1_data, BFLY0_in2_data, BFLY0_out1_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %5d: in1 = %1d", $time, BFLY0_in1_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %5d: in2 = %1d", $time, BFLY0_in2_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %5d: out1 = %1d", $time, BFLY0_out1_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      #100;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %5d: in1 = %1d", $time, BFLY0_in1_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %5d: in2 = %1d", $time, BFLY0_in2_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("top_fft %5d: out1 = %1d", $time, BFLY0_out1_data);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FFT control signals and clock.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $fftctl->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     (                                                       // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        $fftctl->printconnections("      ");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $twiddle->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     (                                                       // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        twiddle_lib::printconnections("      ");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // BEGIN CLOCK AND RESET';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Generate a reset and start';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // clk   ___.---.___.---.___.---.___';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // rstn  ---._______________________';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // start ___.---.___________________';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      start = 1\'b0; // Should be comb logic based on rst_n etc? leave it for now';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      rst_n = 1\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // note cgra does this:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //  always @(posedge clk or posedge reset) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //    if (reset==1\'b1) begin ...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //    end else begin  ...';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Reset on very first posedge';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // FIXME this is terrible; for now we do it b/c matches vcs test rig :(';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Eventually will need like a ncy signal or something';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ (posedge clk) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     if (rst_n) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        $display("\\nRESET!!!");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        rst_n <= 1\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        start <= 1\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     else begin // start is a one-shot, yes?';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '        start <= 1\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // cycle counter I guess';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   logic [31:0] cycle_counter;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ (posedge clk or negedge rst_n) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     if (rst_n) cycle_counter <= 32\'b0;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     else       cycle_counter <= cycle_counter + 32\'b1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # FIXME not sure this (divisor thingy) is correct or useful...
 my $divisor = ($SIMULATOR eq "vcs") ? "1000" : "1";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @ (posedge clk) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("------------------------------------------------------------------------------");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("clock.vp: reset=%d, ncy=%4d, time=%6d ns", rst_n, cycle_counter, $time/'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $divisor; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $display("------------------------------------------------------------------------------");';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 if ($SIMULATOR eq "verilator") {
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   assign done = (cycle_counter == 32\'d'; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $endtime; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // END CLOCK AND RESET';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'endmodule';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#    //;# BEGIN SPM TEST (single-precision-multiplier)____________________________
#    //; my $spm_test = 0;
#    //; if ($spm_test) {
#    /////////////////////////////////////////////////////////////////////////////
#    // http://msdn.microsoft.com/en-us/library/0b34tf65.aspx
#    // Single-precision multiplier: 64-bit fp is 23, 8
# 
#    logic [31:0] dsa;
#    logic [31:0] dsb;
#    logic [31:0] dsz;
#    logic [ 7:0] status_sp;
#    
#    DW_fp_mult #(23, 8, 1)// #(sig, exp, compliance (0 or 1)) 
#    spmult (.a(dsa), .b(dsb), .z(dsz), .rnd(3'b000), .status(status_sp));
#    
#    initial begin
#       dsa = $shortrealtobits(0.5);
#       dsb = $shortrealtobits(0.5);
#       $display("top_fft %5d SRAM_TYPE=`$SRAM_TYPE`", $time);
#    end
#    
#    always @(posedge start) if (~rst_n) begin
#       $display("top_fft_spm: test of single-precision multiplier");
#       $display("top_fft_spm: dsa_x=%x dsb_x=%x dsz_x=%x", dsa, dsb, dsz);
#       $display("top_fft_spm: dsa_f=%f dsb_f=%f dsz_f=%f", $bitstoshortreal(dsa), $bitstoshortreal(dsb), $bitstoshortreal(dsz));
#       $display("top_fft_spm: status=%x", status_sp);
#       $display("top_fft_spm:");
#    end
#    //; }
#    //;# END SPM TEST____________________________________________________________
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
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/tst/top_fft.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
