## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
package swizzler;
use strict;
my $DBG = 0;
my $DBG_swizzler = 0;

##############################################################################
# Swizzler

if ($DBG_swizzler) { test_swizzler(); }

sub test_swizzler {
    my $WHICH_ALG = 'mod_bn_combo';

    print "8 points spread over four memory banks\n";
    for (my $i = 0; $i < 8; $i++) {
        my ($b, $r) = swizzle($i, 8, 4, $WHICH_ALG);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";

    print "16 points spread over four memory banks\n";
    for (my $i = 0; $i < 16; $i++) {
        my ($b, $r) = swizzle($i, 16, 4, $WHICH_ALG);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";

    print "16 points spread over sixteen(!) memory banks\n";
    for (my $i = 0; $i < 16; $i++) {
        my ($b, $r) = swizzle($i, 16, 16, $WHICH_ALG);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";

    print "32 points spread over four memory banks\n";
    for (my $i = 0; $i < 32; $i++) {
        my ($b, $r) = swizzle($i, 32, 4, $WHICH_ALG);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";

    print "64 points spread over four memory banks\n";
    for (my $i = 0; $i < 64; $i++) {
        my ($b, $r) = swizzle($i, 64, 4, $WHICH_ALG);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
    }
    print "\n";

    print "128 points spread over eight memory banks\n";
    for (my $i = 0; $i < 128; $i++) {
        my ($b, $r) = swizzle($i, 128, 8, $WHICH_ALG);
        printf("  Swizzle: ix=%2d => bank %2d, row %2d\n", $i, $b, $r);
        if ($i%8 == 7) { print "\n"; }
    }
    print "\n";

    print "1024 points spread over 16 memory banks\n";
    for (my $i = 0; $i < 1024; $i++) {
        my ($b, $r) = swizzle($i, 1024, 16, $WHICH_ALG);
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

my $WHICH = 'mod_bn_combo';    # Default is mod_bn_combo
#  $WHICH = 'takala';          # no WARN no ERR
#  $WHICH = 'mod_bn_combo';    # NO warnings NO errors WHOAAAAA!
#  $WHICH = 'round7';          # From the formal proof.
#  $WHICH = 'round7_genops';   # Generate verilog for round7 fftctl:GenOps2()

sub set_swizzle_alg { $WHICH = shift; }

my $FIRST = 1;  # Only report algorithm once (first time thru).
sub swizzle {
    my $a = shift;    # unswizzled address of desired data

    # Using specified algorithm $alg, 
    # swizzle('VLOG', $N, $Q, $alg) => prints verilog for calculating rnum, bnum; else
    # swizzle($a, $N, $Q, $alg) => returns row and bank num corresponding to address "a"
    # FIXME/TODO cite takala paper.

    my $N = shift;    # N = number of elements in FFT array
    my $n = log2($N); # n = log2(N)

    my $Q = shift;    # Q = number of memory modules
    my $q = log2($Q); # q = log2(Q)

    my $alg = shift; if ($alg eq "") { print "\nERROR: Unspecified algorithm for swizzle()\n"; }
    $WHICH = $alg;

    # Only report algorithm once (first time thru).
    if ($FIRST == 1) { print "// swizzler algorithm '$WHICH'\n"; $FIRST = 0; }

    my $LDBG  = 0;
    # Uncomment to debug this sub:
    # my $LDBG  = 1; my $DBG9  = 1;

    # Use top (n-q) bits for row address within a given memory bank, i.e.:
    #
    # nrows = log2(N) - log2(Q), i.e.
    #     1024 points spread over four memory banks => (10-2) = eight bits (256 rows/bank)
    #       32 points spread over four memory banks => ( 5-2) = three bits (8 rows/bank)
    #       16 points spread over four memory banks => ( 4-2) = two bits (4 rows/bank)
    #
    # rownum = address >> q
    #     1024 points spread over four memory banks => q=2 => top eight bits of address
    #       32 points spread over four memory banks => q=2 => top three bits of address
    #       16 points spread over four memory banks => q=2 => top two bits of address

    if ($LDBG) { print "------------------------------------------------------------------------------\n"; }

    my $rownum = $a >> $q;
    if ($LDBG) { printf("  %2d (0x%04x) translates to row %2d (0x%04x)\n", $a, $a, $rownum, $rownum); }

    if ($a eq 'VLOG') {
        gen_verilog_to_calculate_rownum($n, $q);
    }

    ########################################################################
    # Bank number: swizzle up ALL the bits to get the bank number
    my $bank_num = 0;

    if    ($WHICH eq 'takala')       { $bank_num =    takala_swizzle($a, $n, $q); }
    elsif ($WHICH eq 'mod_bn_combo') { $bank_num = swiz_mod_bn_combo($a, $n, $q); }
    elsif ($WHICH eq 'round7')       { $bank_num = swiz_mod_bn_combo($a, $n, $q); }
#    elsif ($WHICH eq 'round7_genops'){ $bank_num = swiz_mod_bn_combo($a, $n, $q); }
# round7_genops only used in swiz_mod_bn_combo() i think
    else { die 'Oops invalid algorithm WHICH="$WHICH"\n'; }
     
    if ($LDBG) {
        printf("    maybe bank_num is %2d (0x%04x)\n", $bank_num, $bank_num); 
        print "\n";
    }
    # printf("  Swizzle: ix=%d => bank %d, row %d\n", $a, $bank_num, $rownum);

    if ($DBG9) {
        my @bbits = blow2bits($bank_num, $q);
        printf("  Swizzly: ix=%d => row %d, bank {%s}=$bank_num\n", $a, $rownum, join('',reverse(@bbits)));
    }

    if ($a eq 'VLOG') { print "\n"; }    # So pretty and so useless.
    return ($bank_num, $rownum);
}

sub gen_verilog_to_calculate_rownum {

    my $awidth = shift;    # $awidth = log2($npoints)
    my $bwidth = shift;    # $bwidth = log2($nbanks)

    #  my $rownum = ($abit < $bwidth) ? "1'b0" : sprintf("addr_i[%d:%d]", $abit, $bwidth);
    # "assign rnum_o = (addr_i >> 2);" Causes a lint error:
    #         Lint-[CAWM-L] Width mismatch
    #         genesis_verif/swizzle_unq1.v, 87
    #           Continuous assignment width mismatch
    #           1 bits (lhs) versus 3 bits (rhs).
    #           Source info: assign rnum_o = (addr_i >> 2);  
    # 
    # Instead, do "assign rnum_o = addr_i[5:2]"

    # For rownum, generate "addri[$abit:$q]" or, if $abit<$q, simply always use "1'b0".
    my $abit = $awidth-1;
    my $rownum = ($abit < $bwidth) ? "1'b0" : sprintf("addr_i[%d:%d]", $abit, $bwidth);
    
    printf("\n   assign rnum_o = $rownum;\n\n");
}        

sub takala_swizzle {
    my $a = shift; my $n = shift; my $q = shift;

    my $bank_num = 0;

    # for (my $i = 0; $i < $q; $i++) {
    for (my $i = ($q-1); $i >= 0; $i--) {
        #print "// i=$i n=$n q=$q\n";
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

        # For the sake of generating verilog, build an array
        # @bits that contains the bits that should be xor'ed e.g.
        # @bits = (0,2,4) means generate b[i] = a[0]^a[2]^a[4]

        my @bits = ();
        if ($DBG9) { print "            jqi mod n = ";  }
        for (my $j=0; $j <= $floored_thingy; $j++) {
            my $jqi = $j * $q + $i;
            my $jqi_mod_n = $jqi % $n;
            if ($DBG9) { print "$jqi_mod_n,"; }
            push(@bits, $jqi_mod_n);
        }

        # If requested, generate verilog to do the swizzle.
        if ($a eq 'VLOG') {
            # generate bank bit b[i] = XOR(a[j], forall j in @bits)
            generate_verilog_to_calculate_bank_bits($i, @bits);
        }
        else {
            if ($DBG9) { printf("\n            m_$i = xor(@bits) = %d\n\n\n", xorbits($a, @bits)); }
            $bank_num = $bank_num + (2**$i) * xorbits($a, @bits);
        }
    }
    return $bank_num;
}

sub generate_verilog_to_calculate_bank_bits {
    # generate bank bit b[i] = XOR(a[j], forall j in @bits)

    my ($i,@bits) = @_;

    my @bitstrings = ();
    my @sortedbits = sort { my $a <=> $b } @bits;  # !!??$# sorts in descending numeric order !!?#%

    if ($WHICH eq "round7_genops") {
        foreach my $b (@sortedbits) { push(@bitstrings, "i[$b]"); }
        my $b = @bitstrings;
        # Sometimes @bitstrings is blank (why?)
        if ($b>0) { printf("         newtogs[$i] = %s;\n", join(" ^ ", @bitstrings)); }
    }
    else {
        foreach my $b (@sortedbits) { push(@bitstrings, "addr_i[$b]"); }
        printf("   assign bnum_o[$i] = %s;\n", join(" ^ ", @bitstrings));
    }
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

sub blow2bits {
    # Turn $n into a length-w array of its composite bits.
    my $n = shift;
    my $w = shift;
    my $original_n = $n;

    my $DBG9 = 0;
    if ($DBG9) { print "I see '$n' and I'm-a gonna blow it to bits!"; }

    if (! ($n =~ /[0-9]+/)) {
        die "ERROR swizzler::blow2bits(): '$n' is not a valid number\n";
    }

    my @bits = ();
#     my @bits = ($b x $w);  $n = $n >> 1;
#     while ($n) {
    for (my $i = 0; $i < $w; $i++) {
        my $b = $n%2;
        if ($DBG9) { print " $b"; }
        $b = sprintf("%d", $b);
        push(@bits, $b); $n = $n >> 1;
    }
    if ($DBG9) { print "\n$original_n = {"; print reverse(@bits);  print "} maybe; "; }
    if ($DBG9) { print "  MSB=".$bits[$#bits].",LSB=". $bits[0] . "\n\n\n"; }
    return @bits;
}

sub kings_horses {
    # Turn array of bits into an integer.
    my @bits = @_;
    my @original_bits = @bits;

    my $n = 0;

    my $DBG9 = 0;

    if ($DBG9) { print "I see array of bits {". join('', reverse(@bits)) . "}\n"; }

    while (@bits) {
        my $b = pop(@bits);
        if    ($b eq '0') { $n = 2*$n; }
        elsif ($b eq '1') { $n = 2*$n + 1; }

        else { die "ERROR swizzler::kings_horses got bad bit '$b' ne '0' or '1'\n"; }
    }
    if ($DBG9) { print "Okay {".join('', reverse(@original_bits))."} = $n maybe\n\n"; }
    return $n;
}

sub swiz_mod_bn_combo {
    # Given address $a, goal is to produce 
    # q bank bits b(q-1)...b(0) where b(0) is LSB of banknum
    my $a = shift;
    my $nabits = shift; # log2($npoints)
    my $nbbits = shift; # log2($nbanks)

    # Option $alg parm overrides "WHICH"
    my $alg = shift;
    if ($alg ne "") { $WHICH = $alg; }  # This is bad.  But I think it should work.

    my $VLOG = ($a eq 'VLOG');

    my @bbits = ((0) x $nbbits); # Start with $q bits, all equal to 0
    # print "FOO q=$q bbits="; print @bbits; print "\n\n";

    my @abits = $VLOG ? () : blow2bits($a, $nabits);  # E.g. "14" => (0000 1110)

    my $DBG9 = 0;

    # Must reverse, otherwise prints LSB at beginning of string
    if ($DBG9) { print "address $a = {".join('',reverse(@abits))."}\n", }
    if ($DBG9) { print "\nSwizzling banknum b = f(address a=$a), nbbits = $nbbits...\n"; }

    ########################################################################
    # This is swizzle algorithm "mod_bn_combo"
    # Four banks, two bank bits => b0 = XOR(all even bits), b1 = XOR(all odd bits)
    # Eight banks, three bank bits =>
    #    b0 = XOR(every third bit starting w/a0)
    #    b1 = XOR(every third bit starting w/a1)
    #    b2 = XOR(every third bit starting w/a2)
    # Etc.
    # With "special attention" for "orphans" when nabits is not an even multiple of nbbits.
    #
    # Or, in the case of 'round7',
    # with NO "special attention" for "orphans" when nabits is not an even multiple of nbbits.

    my @bmsg; # Record of xor operations, to print out for debugging purposes. # DBG
    for (my $bi = 0; $bi < $nbbits; $bi++) { $bmsg[$bi] = "b($bi) = XOR("; }   # DBG

    # Let's put the per-bbit abits in an array of arrays
    my @build_bbit = ();
    for (my $bi = 0; $bi < $nbbits; $bi++) {
        $build_bbit[$bi] = ();
    }

    my ($ai, $bi);                         # Suppose nabits=8 and nbbits=3
    for ($ai = 0; $ai < $nabits; $ai++) {  # 0, 1, 2, 3, 4, 5, 6, 7
        $bi = $ai % $nbbits;               # 0, 1, 2, 0, 1, 2, 0, 1

        if ($DBG9) { print "  b($bi) ^= a($ai)\n"; }

        # We're either generating verilog or else we're simply doing a translation.
        #   - If generating verilog, don't need the "NOT VLOG" clauses.
        #   - If simply translating, don't need the "VLOG" clauses.
        #   - No harm if keep both

        ### NOT VLOG ###
        # if ($DBG9) { printf("b($bi) = a($ai)=$abits[$ai]"); }
        $bbits[$bi] ^= $abits[$ai];
        $bmsg[$bi] .= "a($ai)=$abits[$ai], ";
        # if ($DBG9) { printf(" = $bbits[$bi]\n"); }
        ### NOT VLOG ###

        ### VLOG ###
        push (@{$build_bbit[$bi]}, $ai);
        ### VLOG ###
    }

    ########################################################################
    my $DO_ORPHANS = ($WHICH =~ /round7/) ? 0 : 1;
    if ($DO_ORPHANS) { # Don't care about orphans if WHICH='round7'

    # Now take care of the orphans (if any)
    # Currently do very different things depending on whether $n_orphans == 1
    # Future: try and do one thing only regardless of number of orphans.

    my $n_orphans = $nabits % $nbbits;

    # Start back at a0 and continue xor'ing with b bits;
    # If n_orphans==1 do this until finished with final b group (i.e. do it (nbbits-1) more times)
    # Else do it once for each orphan found.

    if ($n_orphans == 1) {
        if ($DBG9) { print "\n  Need to take care of ONE orphan beginning back at a(0)\n"; }

        # Finish out the b group by continuing to xor addr bits, starting back at ai=a0.
        # I.e. treat it the same as if there were (nbbits-1) orphans...

        $n_orphans = $nbbits - 1;
    }
    else {
        if ($DBG9) { print "\n  Need to take care of $n_orphans orphans beginning back at a(0)\n"; }
    }

    # For each orphan, xor another a bit into the next b bit, starting back at ai=a0
    for (my $ai = 0; $ai < $n_orphans; $ai++) {
        
        if ($DBG9) { print "  b($bi) ^= a($ai)\n"; }
        
        ### NOT VLOG ###
        $bi = ($bi + 1) % $nbbits; # yes it can wrap
        $bbits[$bi] ^= $abits[$ai];
        $bmsg[$bi] .= "a($ai)=$abits[$ai], ";
        ### NOT VLOG ###
        
        ### VLOG ###
        push (@{$build_bbit[$bi]}, $ai);
        ### VLOG ###
    }
    }
    ########################################################################

    # Print out the nice bmsg debugs
    if ($DBG9) { print "\n  Final conversion:\n"; }
    for (my $bi = 0; $bi < $nbbits; $bi++) {
        chop($bmsg[$bi]); chop($bmsg[$bi]); # Elim extra two chars ", " at end
        if ($DBG9) { print "  $bmsg[$bi]) = $bbits[$bi]\n"; }
    }
    if ($DBG9) { print "\n"; }

    ### VLOG ###
    # Quick check of build_bbit array for verilog
    # Oh, and also generate the verilog.
    for (my $bi=0; $bi<$nbbits; $bi++) {

        # Optionally print a little debug message maybe?
        # my $abits = join(' a', @{$build_bbit[$bi]});
        # if ($DBG9) { print "VLOG b($bi) = XOR(a$abits)\n"; }

        if (($DBG9) || ($a eq 'VLOG')) {
            generate_verilog_to_calculate_bank_bits($bi, @{$build_bbit[$bi]});
        }
    }
    if ($DBG9) { print "\n"; }

    # $bbits[0] = 0; # Break it to test it
    my $bank_num = kings_horses(@bbits);
    return $bank_num;
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
