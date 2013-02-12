package swizzler;
use strict;
my $DBG = 0;
my $DBG_swizzler = 0;

##############################################################################
# Swizzler

if ($DBG_swizzler) { test_swizzler(); }

sub test_swizzler {
    print "8 points spread over four memory banks\n";
    for (my $i = 0; $i < 8; $i++) {
        my ($b, $r) = swizzle($i, 8, 4);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";
    print "16 points spread over four memory banks\n";
    for (my $i = 0; $i < 16; $i++) {
        my ($b, $r) = swizzle($i, 16, 4);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";
    print "16 points spread over sixteen(!) memory banks\n";
    for (my $i = 0; $i < 16; $i++) {
        my ($b, $r) = swizzle($i, 16, 16);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";
    print "32 points spread over four memory banks\n";
    for (my $i = 0; $i < 32; $i++) {
        my ($b, $r) = swizzle($i, 32, 4);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";
    print "64 points spread over four memory banks\n";
    for (my $i = 0; $i < 64; $i++) {
        my ($b, $r) = swizzle($i, 64, 4);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";
    print "1024 points spread over 16 memory banks\n";
    for (my $i = 0; $i < 1024; $i++) {
        my ($b, $r) = swizzle($i, 1024, 16);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
}

sub test_helper_functions {
    print "BEGIN test of xorbits() function________\n";
    my $n = 12;
    for (my $i=7; $i>=0; $i--) {
        printf("xorbits: $n bit $i = %d\n", getbit($n, $i));
    }
    print "\n";
    printf("xorbits(12,     (2,3)) = %d; should be %d\n", xorbits(12, 2, 3)   , 1^1);
    printf("xorbits(12,   (1,2,3)) = %d; should be %d\n", xorbits(12, 2, 3, 1), 0^1^1);
    printf("xorbits(12,   (5,6,7)) = %d; should be %d\n", xorbits(12, 5,6,7)  , 0^0^0);
    printf("xorbits(12,     (1,2)) = %d; should be %d\n", xorbits(12, 1,2)    , 0^1);

    printf("xorbits(12, (1,2,3,4)) = %d; should be %d\n", xorbits(12, 1,2,3,4), 0^0^1^1    );
    print "END test of xorbits() function__________\n";
    print "\n";

    print "BEGIN test of getbit() function________________________________________\n";
    my $n = 255;
    for (my $i=9; $i>=0; $i--) {
        printf("getbit: $n bit $i = %d\n", getbit($n, $i));
    }
    print "\n";
    my $n = 256;
    for (my $i=9; $i>=0; $i--) {
        printf("getbit: $n bit $i = %d\n", getbit($n, $i));
    }
    print "END test of getbit() function__________________________________________\n";
    print "\n";

    print "BEGIN test of gcd() function________\n";
    my ($a, $b) = (3,13); printf("gcd($a,$b) = %d\n", gcd($a, $b));
    my ($a, $b) = (8,32); printf("gcd($a,$b) = %d\n", gcd($a, $b));
    my ($a, $b) = (2,0); printf("gcd($a,$b) = %d\n", gcd($a, $b));
    print "\n";
    my ($a, $b) = (3,13); printf("gcdr($a,$b) = %d\n", gcdr($a, $b));
    my ($a, $b) = (8,32); printf("gcdr($a,$b) = %d\n", gcdr($a, $b));
    my ($a, $b) = (2,0); printf("gcdr($a,$b) = %d\n", gcdr($a, $b));
    print "END test of gcd() function__________\n\n";
}

my $DBG9 = 1;
my $DBG9 = 0;

if ($DBG9) {
    test_helper_functions();
}

sub swizzle {
    my $a = shift;    # unswizzled address of desired data

    my $N = shift;    # N = number of elements in FFT array
    my $n = log2($N); # n = log2(N)

    my $Q = shift;    # Q = number of memory modules
    my $q = log2($Q); # q = log2(Q)

my $LDBG  = 1;
my $LDBG  = 0;


# # row bits = n - q i.e.
# nrows = log2(N) - log2(Q), i.e.
#     1024 points spread over four memory banks => (10-2) = eight bits (256 rows/bank)
#       32 points spread over four memory banks => ( 5-2) = three bits (8 rows/bank)
#       16 points spread over four memory banks => ( 4-2) = two bits (4 rows/bank)

# rownum = address >> q
#     1024 points spread over four memory banks => q=2 => top eight bits of address
#       32 points spread over four memory banks => q=2 => top three bits of address
#       16 points spread over four memory banks => q=2 => top two bits of address

    if ($LDBG) { print "------------------------------------------------------------------------------\n"; }
#    printf("VLOG rnum_o = addr_i >> $q;\n");
    my $rownum = $a >> $q;
    if ($LDBG) { printf("  %2d (0x%04x) translates to row %2d (0x%04x)\n", $a, $a, $rownum, $rownum); }

    my $bank_num = 0;

    # Swizzle up the lower q bits
    for (my $i = 0; $i < $q; $i++) {
        my $nmodq = $n % $q;
        my $gcd = gcd($q, $nmodq);
        if ($DBG9) { printf("       n=$n; q=$q; n mod q=$nmodq; gcd($q, $nmodq) = $gcd\n"); }

        my $unfloored_thingy = ($n + $q - $gcd - $i - 1) / $q;
        my $floored_thingy = int($unfloored_thingy);
        if ($DBG9) { printf("       u=$unfloored_thingy, floor(u)=$floored_thingy\n"); }

        if ($DBG9) { print "            jqi = ";  }
        for (my $j=0; $j <= $floored_thingy; $j++) {
            my $jqi = $j * $q + $i;
            if ($DBG9) { print "$jqi,"; }
        }
        if ($DBG9) { print "\n"; }

        my @bits = ();
        if ($DBG9) { print "            jqi mod n = ";  }
        for (my $j=0; $j <= $floored_thingy; $j++) {
            my $jqi = $j * $q + $i;
            my $jqi_mod_n = $jqi % $n;
            if ($DBG9) { print "$jqi_mod_n,"; }
            push(@bits, $jqi_mod_n);
        }
        if ($DBG9) { print "\n"; }
        if ($DBG9) { printf("            m_$i = xor(@bits) = %d\n", xorbits($a, @bits)); }
        if ($DBG9) { print "\n\n"; }

#        my @bitstrings = ();
#        foreach my $b (@bits) { push(@bitstrings, "addr_i[$b]"); }
#        printf("VLOG bnum_o[$i] = %s;\n", join("^", @bitstrings));

        $bank_num = $bank_num + (2**$i) * xorbits($a, @bits);
    }
    if ($LDBG) {
        printf("    maybe bank_num is %2d (0x%04x)\n", $bank_num, $bank_num); 
        print "\n";
    }
#    printf("  Swizzle: ix=%d => bank %d, row %d\n", $a, $bank_num, $rownum);
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

1;
