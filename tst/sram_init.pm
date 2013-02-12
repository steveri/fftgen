package sram_init;  # Formerly known as "swizzle_inits.pm"
use strict;

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

    my @ai = ();
    for (my $i=0; $i < $npoints; $i++) { $ai[$i] = 0; }

    my @ar = @ai;
    for (my $i=0; $i < $npoints; $i+=2) { $ar[$i] = 1; }

    my $nrams = 4 * $nbutts; # Assumes four SRAMs per butterfly unit.
    swizzle_init($indent, $nrams, \@ar, \@ai, $rbits, $ibits);
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
    #    top_fft.fftram.SRAM000.mem[0][63:32] = $shortrealtobits(1);
    #    top_fft.fftram.SRAM000.mem[0][31:0]  = $shortrealtobits(0);
    #   
    #    // ix=1 => bank 3, row 0 <= ( 0.000,  0.000)
    #    top_fft.fftram.SRAM003.mem[0][63:32] = $shortrealtobits(0);
    #    top_fft.fftram.SRAM003.mem[0][31:0]  = $shortrealtobits(0);
    #    ...

    my $indent = shift;
    my $nbanks = shift;

    my $ar_ptr = shift; my @ar = @{$ar_ptr};
    my $ai_ptr = shift; my @ai = @{$ai_ptr};

    my $rbits = shift;  # Real bits, e.g.     "63:32"
    my $ibits = shift;  # Imaginary bits e.g. "31:0"

    my $npoints = @ar;

    for (my $i = 0; $i < $npoints; $i++) {

        # Given unswizzled address $i, npoints $noints, nbanks $nbanks,
        # real number $real with bit assignments $rbits (e.g. "63:32"),
        # imaginary number $imag with bit assignments $ibits (e.g. "31:0"),
        # print verilog code to initialize the appropriate swizzled
        # SRAM location (bank, row) with the value (real,imag).

        my ($bank_num, $rownum) = swizzle($indent, $i, $npoints, $nbanks);

        if ($DBG) { printf("    maybe bank_num is %2d (0x%04x)\n", $bank_num, $bank_num); }
        if ($DBG) { print "\n"; }

        my ($real, $imag) = ($ar[$i], $ai[$i]);

        print "\n";
        printf($indent."// ix=%d => bank %d, row %d", $a, $bank_num, $rownum);
        printf(" <= (%6.3f, %6.3f)\n", $real, $imag);

        # top_fft.fftram.SRAM000.mem[0][63:32] = $shortrealtobits(1);
        # top_fft.fftram.SRAM000.mem[0][31:0]  = $shortrealtobits(0);

        printf($indent."top_fft.fftram.SRAM%03d.mem[%d][$rbits] = \$shortrealtobits($real);\n", $bank_num, $rownum);
        printf($indent."top_fft.fftram.SRAM%03d.mem[%d][$ibits] = \$shortrealtobits($imag);\n", $bank_num, $rownum);
    }
}

sub swizzle {
    # Given unswizzled address $a, npoints $N, nbanks $Q, return
    # swizzled SRAM location (bank, row) to which it maps.

    my $indent = shift;

    my $a = shift;    # unswizzled address of desired data
    my $N = shift;    # N = number of elements in FFT array
    my $Q = shift;    # Q = number of memory modules

    my $real = shift;
    my $imag = shift;

    my $rbits = shift;  # Real bits, e.g.     "63:32"
    my $ibits = shift;  # Imaginary bits e.g. "31:0"

    my $n = log2($N); # n = log2(N)
    my $q = log2($Q); # q = log2(Q)

    if ($DBG) { print "------------------------------------------------------------------------------\n"; }
    if ($DBG) { printf("VLOG rnum_o = addr_i >> $q;\n"); }
    my $rownum = $a >> $q;
    if ($DBG) { printf("  %2d (0x%04x) translates to row %2d (0x%04x)\n", $a, $a, $rownum, $rownum); }

    my $bank_num = 0;

    # Swizzle up the lower q bits
    for (my $i = 0; $i < $q; $i++) {
        my $nmodq = $n % $q;
        my $gcd = gcd($q, $nmodq);
        if ($DBG) { printf("       n=$n; q=$q; n mod q=$nmodq; gcd($q, $nmodq) = $gcd\n"); }

        my $unfloored_thingy = ($n + $q - $gcd - $i - 1) / $q;
        my $floored_thingy = int($unfloored_thingy);
        if ($DBG) { printf("       u=$unfloored_thingy, floor(u)=$floored_thingy\n"); }

        if ($DBG) { print "            jqi = ";  }
        for (my $j=0; $j <= $floored_thingy; $j++) {
            my $jqi = $j * $q + $i;
            if ($DBG) { print "$jqi,"; }
        }
        if ($DBG) { print "\n"; }

        my @bits = ();
        if ($DBG) { print "            jqi mod n = ";  }
        for (my $j=0; $j <= $floored_thingy; $j++) {
            my $jqi = $j * $q + $i;
            my $jqi_mod_n = $jqi % $n;
            if ($DBG) { print "$jqi_mod_n,"; }
            push(@bits, $jqi_mod_n);
        }
        if ($DBG) { print "\n"; }
        if ($DBG) { printf("            m_$i = xor(@bits) = %d\n", xorbits($a, @bits)); }
        if ($DBG) { print "\n\n"; }

        my @bitstrings = ();
        foreach my $b (@bits) { push(@bitstrings, "addr_i[$b]"); }
        if ($DBG) { printf("VLOG bnum_o[$i] = %s;\n", join("^", @bitstrings)); }

        $bank_num = $bank_num + (2**$i) * xorbits($a, @bits);
    }
    return ($bank_num, $rownum);
}

sub log2 {
    my $n = shift @_;
    my $result = 1; while ( (2**$result) < $n ) { $result++; }
    return $result;
}

sub gcd {
    # Find greatest common denominator of a and b
    my $a = shift; my $b = shift;
    if ($a == 0) { return $b; }
    if ($b == 0) { return $a; }
    for (my $i = $a; $i > 0; $i--) {
        if (
            (($a % $i) == 0) &&
            (($b % $i) == 0)
            ) {
            return $i;
        }
    }
}

sub gcdr {
    # Find greatest common denominator of a and b
    my $a = shift; my $b = shift;
    if ($a == 0) { return $b; }
    if ($b == 0) { return $a; }
    if ($a > $b) {
        return gcdr($a % $b, $b);
    } else {
        return gcdr($a, $b % $a);
    }
}

sub getbit {
    # getbit(n, i): Return bit #i of the integer n
    my $n = shift;
    my $i = shift;
    if ($n & (2**$i)) { return 1; } else { return 0; }
}

sub xorbits {
    # Given a number n and a list of bits @bits, xor those bits together.
    my $n = shift;
    my @bits = @_;
    my $rval = getbit($n, shift(@bits));
    while (@bits) { $rval = $rval ^ getbit($n, shift(@bits)); }
    return $rval;
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
