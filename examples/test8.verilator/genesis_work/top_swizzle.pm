package top_swizzle;
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
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/tst/top_swizzle.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/tst/top_swizzle.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/tst/top_swizzle.vp"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright 2013, all rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// See below (end of file) for extended copyright information.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# push (@INC, "./rtl"); # Now this happens in "Makefile.local"
 require fftgen;        # log2(), iterate()

 ########################################################################
 # PARAMETERS cause default Genesist output to .v file
 ########################################################################
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- Begin default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 

 my $npoints = parameter
    (Name=>'n_fft_points', Val=>16,
     Doc=>'Number of complex data values to process.');

 my $upc = parameter
    (Name=>'units_per_cycle', Val=>1.0,
     Doc=>'Number of butterfly units per cycle (0.25, 0.5, 1.0, 2.0 or 4.0).');
 
 ########################################################################

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- End default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $nunits = ($upc < 1) ? 1 : $upc;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generate clock unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $gclock = generate
    ('clock','GCLK',
     CLK_PERIOD=>1000, # 5 ns clock period
     RST_PERIOD=>   1, # Currently not used
     MAX_CYCLES=>  16  # End simulation after 16 cycles
 );
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# Generate fftctl unit
 my $fftctl = generate
    ('fftctl', 'fftctl',
     n_fft_points   =>$npoints,
     units_per_cycle=>$upc
 );
# my $nunits = $fftctl->{nunits};
# my $npoints = $fftctl->{Parameters}->{"n_fft_points"}->{Val};
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generated fftctl unit (nunits = '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $nunits; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ', npoints='; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $npoints; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ')';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# print "// nunits = $nunits, npoints=$npoints\n";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generate monsterfile';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 my $monsterfile = generate
    ('monsterfile', 'monsterfile',
     n_butterfly_units  =>$nunits,
     n_fft_points       =>16
 );
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Generate swizzle unit(s)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
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

# //; my $nunits = $fftctl->{Parameters}->{"n_butterfly_units"}->{Val};
# 
# //; foreach my $p (@{$fftctl->{ParametersList}}) {
# //;     my $val = $fftctl->{Parameters}->{$p}->{Val};
# //;     my $doc = $fftctl->{Parameters}->{$p}->{Doc};
# //;     printf("FOO 2a //     %-20s %8s %s\n", $p, "($val)", $doc);
# //; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '  ();';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // BEGIN WIRE DECLARATIONS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // fftctl->printwires("   ", "wire_list")';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    $fftctl->printwires("   ", "wire_list");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // in1, in2 data from regfile to butterfly unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [31:0] BFLY%d_in1_data;   ",
        "   logic [31:0] BFLY%d_in2_data;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // out1, out2 data from butterfly unit to regfile';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [31:0] BFLY%d_out1_data;  ",
        "   logic [31:0] BFLY%d_out2_data;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle wires.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $nbanks = 4*$nunits;
    #my $awidth = fftgen::log2($npoints);
    my $bwidth = fftgen::log2($nbanks);
    my $rwidth = fftgen::log2($npoints/$nbanks);
    my $bbits = ($bwidth-1).":0";
    my $rbits = ($rwidth-1).":0";
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle banknum wires for in1, in2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$bbits] BFLY%d_in1_bnum;   ",
        "   logic [$bbits] BFLY%d_in2_bnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle banknum wires for out1, out2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$bbits] BFLY%d_out1_bnum;   ",
        "   logic [$bbits] BFLY%d_out2_bnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle rownum wires for in1, in2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$bbits] BFLY%d_in1_rnum;   ",
        "   logic [$bbits] BFLY%d_in2_rnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Swizzle rownum wires for out1, out2';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print fftgen::iterate($nunits,
        "   logic [$bbits] BFLY%d_out1_rnum;   ",
        "   logic [$bbits] BFLY%d_out2_rnum;\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // END WIRE DECLARATIONS';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Here\'s the magic: out = in1 + in2 means that, at end, all locations should equal (npoints/2).';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
   # assign BFLY0_out1_data = BFLY0_in1_data + BFLY0_in2_data;
   # assign BFLY0_out2_data = BFLY0_in1_data + BFLY0_in2_data;
    print fftgen::iterate($nunits,
        "   assign BFLY%d_out1_data = ", "BFLY%d_in1_data + ", "BFLY%d_in2_data;\n",
        "   assign BFLY%d_out2_data = ", "BFLY%d_in1_data + ", "BFLY%d_in2_data;\n\n",);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // generates clock and connects it to local wire ".clk_i"';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $gclock->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.clk(clk_i), .reset(rst_n_i)); // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $fftctl->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     (                                                     // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
        $fftctl->printconnections("      ");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '    );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $monsterfile->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '     (                                                     // .remote(local)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      .clk_i(clk_i),';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // Butterfly unit addresses and data';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // in1, in2 addresses';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # input logic [3:0] BFLY0_in1_ix,       input logic [3:0] BFLY0_in2_ix,
       # input logic [3:0] BFLY1_in1_ix,       input logic [3:0] BFLY1_in2_ix,
       # input logic [3:0] BFLY2_in1_ix,       input logic [3:0] BFLY2_in2_ix,
       # input logic [3:0] BFLY3_in1_ix,       input logic [3:0] BFLY3_in2_ix,
       # print "FOO1 nunits = $nunits, npoints=$npoints\n";
       print fftgen::iterate($nunits,
           "      .BFLY%d_in1_ix", "(BFLY%d_in1_ix),",
           "      .BFLY%d_in2_ix", "(BFLY%d_in2_ix),\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // out1, out2 addresses';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # input logic [3:0] BFLY0_out1_ix,     input logic [3:0] BFLY0_out2_ix,
       # input logic [3:0] BFLY1_out1_ix,     input logic [3:0] BFLY1_out2_ix,
       # input logic [3:0] BFLY2_out1_ix,     input logic [3:0] BFLY2_out2_ix,
       # input logic [3:0] BFLY3_out1_ix,     input logic [3:0] BFLY3_out2_ix,
       print fftgen::iterate($nunits,
           "      .BFLY%d_out1_ix", "(BFLY%d_out1_ix),",
           "      .BFLY%d_out2_ix", "(BFLY%d_out2_ix),\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // in1, in2 data OUT to butterfly unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # input logic [3:0] BFLY0_in1_data,       input logic [3:0] BFLY0_in2_data,
       # input logic [3:0] BFLY1_in1_data,       input logic [3:0] BFLY1_in2_data,
       # input logic [3:0] BFLY2_in1_data,       input logic [3:0] BFLY2_in2_data,
       # input logic [3:0] BFLY3_in1_data,       input logic [3:0] BFLY3_in2_data,
       print fftgen::iterate($nunits,
           "      .BFLY%d_in1_data", "(BFLY%d_in1_data),",
           "      .BFLY%d_in2_data", "(BFLY%d_in2_data),\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      // out1, out2 data back IN from butterfly unit';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       # input logic [3:0] BFLY0_out1_data,     input logic [3:0] BFLY0_out2_data,
       # input logic [3:0] BFLY1_out1_data,     input logic [3:0] BFLY1_out2_data,
       # input logic [3:0] BFLY2_out1_data,     input logic [3:0] BFLY2_out2_data,
       # input logic [3:0] BFLY3_out1_data,     input logic [3:0] BFLY3_out2_data,
       print fftgen::iterate($nunits,
           "      .BFLY%d_out1_data", "(BFLY%d_out1_data),",
           "      .BFLY%d_out2_data", "(BFLY%d_out2_data),\n");
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      .we_i(we_o)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#   //; my $i = 0;
#   `$swizzle->instantiate()`(.addr_i(BFLY`$i`_in1_ix), .rnum_o(BFLY`$i`_in1_rnum), .bnum_o(BFLY`$i`_in1_bnum));
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   // Instantiate swizzle units BFLY0_in1_swizzle, BFLY0_in2_swizzle etc.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       foreach my $io ("in1", "in2", "out1", "out2") {
          for (my $i=0; $i<$nunits; $i++) {
              my $pfx = "BFLY${i}_${io}";    # BFLY0_in1, BFLY0_in2, BFLY0_out1, ...
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $swizzle{$pfx}->instantiate(); print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '(.addr_i('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix), .rnum_o('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rnum), .bnum_o('; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum));';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
       }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    my $i = 0;
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(posedge clk_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      if (busy_o === 1) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
#         $display("top_swizzle: BFLY0_in1 ix %02d goes to bank %2d row %3d",
#                  BFLY`$i`_in1_ix, BFLY`$i`_in1_bnum, BFLY`$i`_in1_rnum);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          foreach my $io ("in1", "in2", "out1", "out2") {
             for (my $i=0; $i<$nunits; $i++) {
                 my $pfx = "BFLY${i}_${io}";    # BFLY0_in1, BFLY0_in2, BFLY0_out1, ...
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '         $display("top_swizzle: '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' ix %02d goes to bank %2d row %3d",';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '                  '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_ix, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_bnum, '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $pfx; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '_rnum);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
          }}
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   initial begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      $vcdpluson(   0  , '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ($self->get_top())->mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ');';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      //start_i <= 0; // It\'s STUPID to use "<=" in an initial block (right!??)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      start_i = 0; // It\'s STUPID to use "<=" in an initial block (right!??)';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   always @(negedge rst_n_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      start_i = 1;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '      @(posedge clk_i) begin start_i = 0; end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
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
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/tst/top_swizzle.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
