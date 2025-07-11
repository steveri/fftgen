## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
package sram_init;  # Formerly known as "swizzle_inits.pm"
use strict;

//;# push (@INC, "./rtl"); # Now this happens in "Makefile.local"
//; require swizzler;      # swizzle()

##############################################################################
# For generating initialization of FFT sram's.

my $DBG  = 1;
my $DBG  = 0;

my $DBG9 = 1;
my $DBG9 = 0;

#swizzle_init_tests(); exit;

sub swizzled_test_pattern {
    ##############################################################################
    # Given <np> FFT points and <nb> butterfly units, generate initiation code for
    # a wave that's high for the first n/2 points and then low for n/2 points.
    # Because of bit-reversing, it's going to look like the points are interleaved
    # e.g. instead of (1,1,1,1,0,0,0,0) it's going to be (1,0,1,0,1,0,1,0).

    my $indent = shift;
    my $npoints = shift;
    my $nbutts  = shift;

    my $rbits = shift;  # Real bits, e.g.     "63:32"
    my $ibits = shift;  # Imaginary bits e.g. "31:0"

    my $which_pattern = shift; # Currently only choice is "sq_wave"

    my $swizzalg = shift; # 'round7' or 'mod_bn_combo'
    if ("$swizzalg" eq "") { $swizzalg = 'round7'; }

    my @ai = ();
    for (my $i=0; $i < $npoints; $i++) { $ai[$i] = 0; }

    my @ar = @ai;
    for (my $i=0; $i < $npoints; $i+=2) { $ar[$i] = 1; }

    my $nrams = 4 * $nbutts; # Assumes four SRAMs per butterfly unit.
    swizzle_init($indent, $nrams, \@ar, \@ai, $rbits, $ibits, $swizzalg);
}

sub swizzle_init {
    ##############################################################################
    # Given (bit-reversed) real, imag arrays @ar, @ai; and given n_memory_banks
    # memory banks (e.g. 4); generate SRAM-swizzled initialization code.
    #
    # Example:
    #    my @ar = (1,0,1,0,  1,0,1,0);   my @ai = (0,0,0,0,  0,0,0,0);
    #    swizzle_init("   ", 4, \@ar, \@ai);
    #
    # Output:
    #    // ix=0 => bank 0, row 0 <= ( 1.000,  0.000)
    #    top_fft.fftram.SRAM000.mem[0][63:32] = _shortrealtobits_1;
    #    top_fft.fftram.SRAM000.mem[0][31:0]  = _shortrealtobits_0;
    #   
    #    // ix=1 => bank 3, row 0 <= ( 0.000,  0.000)
    #    top_fft.fftram.SRAM003.mem[0][63:32] = _shortrealtobits_0;
    #    top_fft.fftram.SRAM003.mem[0][31:0]  = _shortrealtobits_0;
    #    ...

    my $indent = shift;
    my $nbanks = shift;

    my $ar_ptr = shift; my @ar = @{$ar_ptr};
    my $ai_ptr = shift; my @ai = @{$ai_ptr};

    my $rbits = shift;  # Real bits, e.g.     "63:32"
    my $ibits = shift;  # Imaginary bits e.g. "31:0"

    my $swizzalg = shift; # 'round7' or 'mod_bn_combo'
    if ("$swizzalg" eq "") { $swizzalg = 'round7'; }

    my $npoints = @ar;

    for (my $i = 0; $i < $npoints; $i++) {

        # Given unswizzled address $i, npoints $noints, nbanks $nbanks,
        # real number $real with bit assignments $rbits (e.g. "63:32"),
        # imaginary number $imag with bit assignments $ibits (e.g. "31:0"),
        # print verilog code to initialize the appropriate swizzled
        # SRAM location (bank, row) with the value (real,imag).

        # Given address $i, return banknum and rownum of swizzled mapping to sram banks
       #my ($bank_num, $rownum) = swizzler::swizzle($i, $npoints, $nbanks, 'mod_bn_combo');
        my ($bank_num, $rownum) = swizzler::swizzle($i, $npoints, $nbanks, $swizzalg);

        if ($DBG) { printf("    maybe bank_num is %2d (0x%04x)\n", $bank_num, $bank_num); }
        if ($DBG) { print "\n"; }

        my ($real, $imag) = ($ar[$i], $ai[$i]);

        print "\n";
        printf($indent."// ix=%02d => bank %d, row %d", $i, $bank_num, $rownum);
        printf(" <= (%6.3f, %6.3f)\n", $real, $imag);

        # top_fft.fftram.SRAM000.mem[0][63:32] = _shortrealtobits(1);
        # top_fft.fftram.SRAM000.mem[0][31:0]  = _shortrealtobits(0);

        printf($indent."top_fft.fftram.SRAM%03d.mem[%d][$rbits] = _shortrealtobits_$real;\n", $bank_num, $rownum);
        printf($indent."top_fft.fftram.SRAM%03d.mem[%d][$ibits] = _shortrealtobits_$imag;\n", $bank_num, $rownum);
    }
}

sub swizzle_init_tests {
    my $rbits="63:32"; # Real
    my $ibits="31: 0"; # Imaginary

    print "------------------------------------------------------------------------------\n";
    print "Okay for reals this time: 8 points spread over four memory banks\n";
    # "swizzled_test_pattern" calls swizzle_init w/default square wave pattern
    # @ar = (1,0,1,0,  1,0,1,0) and @ai = (0,0,0,0,  0,0,0,0);
    my $npoints = 8; my $nbutts = 1;
    swizzled_test_pattern("   ", $npoints, $nbutts, $rbits, $ibits, "sq_wave");

    print "------------------------------------------------------------------------------\n";
    print "8 points spread over four memory banks\n";
    my @ar = ( 1, 2, 3, 4,    5, 6, 7, 8);
    my @ai = (11,22,33,44,   55,66,77,88);
    swizzle_init("VLOG ", 4, \@ar, \@ai, $rbits, $ibits);

    print "------------------------------------------------------------------------------\n";
    print "8 points spread over four memory banks\n";
    my @ar8 = (0,0,0,0,  0,0,0,0);
    my @ai8 = (1,1,1,1,  1,1,1,1);
    swizzle_init("VLOG ", 4, \@ar8, \@ai8, $rbits, $ibits);

    print "------------------------------------------------------------------------------\n";
    print "16 points spread over four memory banks\n";
    my @ar16 = (@ar8, @ar8);
    my @ai16 = (@ai8, @ai8);
    swizzle_init("VLOG ", 4, \@ar16, \@ai16, $rbits, $ibits);

    print "------------------------------------------------------------------------------\n";
    print "16 points spread over sixteen(!) memory banks\n";
    swizzle_init("VLOG ", 16, \@ar16, \@ai16, $rbits, $ibits);

    print "------------------------------------------------------------------------------\n";
    print "32 points spread over four memory banks\n";
    my @ar32 = (@ar16, @ar16);
    my @ai32 = (@ai16, @ai16);
    swizzle_init("VLOG ", 4, \@ar32, \@ai32, $rbits, $ibits);

    print "------------------------------------------------------------------------------\n";
    print "64 points spread over four memory banks\n";
    my @ar64 = (@ar32, @ar32);
    my @ai64 = (@ai32, @ai32);
    swizzle_init("VLOG ", 4, \@ar64, \@ai64, $rbits, $ibits);

    print "------------------------------------------------------------------------------\n";
    print "1024 points spread over 16 memory banks\n";
    my @ar256 = (@ar64, @ar64, @ar64, @ar64);
    my @ai256 = (@ai64, @ai64, @ai64, @ai64);

    my @ar1024 = (@ar256, @ar256, @ar256, @ar256);
    my @ai1024 = (@ai256, @ai256, @ai256, @ai256);

    swizzle_init("VLOG ", 16, \@ar1024, \@ai1024, $rbits, $ibits);
}

1;

#################################################################################
## MIT License
## 
## Copyright (c) 2013 Stephen E. Richardson and Stanford University
## 
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is
## furnished to do so, subject to the following conditions:
## 
## The above copyright notice and this permission notice shall be included in all
## copies or substantial portions of the Software.
## 
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IM-
## PLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
## FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
## COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
## IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNEC-
## TION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
## 
## For more information please contact
## Stephen E. Richardson  steveri@stanford.edu (Stanford University)
## Prof. Mark Horowitz   horowitz@stanford.edu (Stanford University)
#################################################################################
