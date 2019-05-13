## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
package fft_scheduler;
use strict;
$| = 1; # Autoflush output why not.

my $rtldir = mydir(".");  # This script lives in $FFTGEN/rtl;
push (@INC, "$rtldir/");  # swizzler lives in $FFTGEN/rtl
require swizzler;

my $DBG = 0;
sub DBG { $DBG = shift; }

##############################################################################
# To turn debugging on remotely, call fft_scheduler::DBG_ON();
# see bin/test_scheduler.pl
sub DBG_ON { $DBG = 1; }

# Valid settings are 'round7' (new/best), 'mod_bn_combo' (old) and maybe 'takala'
my $SCHED_ALG = 'round7';
if ($ENV{SCHED_ALG} ne "") { $SCHED_ALG = $ENV{SCHED_ALG}; }

# To turn crazy_eye on remotely, set shell variable USE_CRAZY to 1
print "// Scheduling algorithm='$SCHED_ALG'";
if    ($SCHED_ALG eq 'round7') { print "\n\n"; }
elsif ($ENV{USE_CRAZY} == 1)   { print ", using the crazy eye.\n\n"; }
else                           { print ", NOT using the crazy eye.\n\n"; }

# if ($SCHED_ALG ne 'round7') {
#     my $msg = "\n\nERROR This version of fft_scheduler does not work with alg '$SCHED_ALG'\n";
#     $msg .=   "Try again after doing 'setenv SCHED_ALG mod_bn_combo'\n";
#     print $msg; die $msg;
# }

##############################################################################
# NEW (ROUND7) STUFF:
#    build_base_schedule(), build_extended_schedule()
#    parity_map(), parity_mod(), get_twiddles()
#    debug subs show_i(), show_d(), show_bits()

sub build_base_schedule {

    ########################################################################
    # Given a group size G and desired number of datapoints D, build a basic
    # conflict-free schedule $datapoints{s,i}

    my $D = shift; # Number of datapoints in the FFT transform
    my $G = shift; # Desired group size

    my ($S,$T) = (log2($D), log2($G)); # Number of stages S and toggle bits T
    my %datapoints = {};

    # Normal stages 0 through S-T
    for (my $s=0; $s <= ($S-$T); $s++) {
        if ($DBG) { print "Building normal stage $s\n"; }
        for (my $i=0; $i<$D; $i++) {
            if ($DBG) { show_i($i,$D,$S); }
            $datapoints{"$s,$i"} = lrot($i, $S, $s);
            if ($DBG) { show_d("%s => ", $datapoints{"$s,$i"}, $D, $G); }
            if ($DBG) { if ($i>0 && ($i%$G == ($G-1))) { print "\n"; }} # group separator
        }
    }
    # Overlap stages S-T through D
    my $LDBG=0;
    for (my $s = ($S-$T)+1; $s < $S; $s++) {
        if ($DBG) { print "Building overlap stage $s\n"; }
        for (my $ilow=0; $ilow<($D/$G); $ilow++) {
            for (my $t=0; $t<$G; $t++) {
                my $i = ($ilow << $T) + $t;      # Counts from 0 to $D-1
                if ($DBG) { show_i($i,$D,$S); }

                my $shift_amt = ($s-($S-$T)); #DBG
                if ($LDBG) { print "\n\nrotate $T-bit t=$t left by $shift_amt places\n"; }

                my $t_rot = lrot($t, $T, $s-($S-$T));
                if ($LDBG) { print "(t_rot << " . ($S-$T) . ") | " . $ilow . " = $t_rot\n"; }

                my $iprime = ($t_rot<<($S-$T)) | $ilow;
                if ($LDBG) { print "iprime=$iprime\n"; }

                $datapoints{"$s,$i"} = ($t_rot<<($S-$T)) | $ilow;

                if ($LDBG) { print "datapoints[$s,$i] = '" . $datapoints{"$s,$i"} . "'\n"; }
                if ($DBG) { show_d("%s => ", $datapoints{"$s,$i"}, $D, $G); }
            }
            if ($DBG) { print "\n"; } # group separator
        }
    }
    if ($DBG) { print "\n"; }
    return %datapoints;
}

sub build_extended_schedule {

    ########################################################################
    # Given a group size G, and number of datapoints D, and a conflict-free
    # datapoint sequence %datapoints{s,i} for an FFT w/o pipeline overlap,
    # produce a CFS for FFT w/pipeline overlap

    my $D = shift;          # Number of datapoints in the FFT transform
    my $G = shift;          # Desired group size
    my $datapoints = shift; # Pointer to hash containing datapoints

    my ($S,$T) = (log2($D), log2($G));

    my %deltapoints = {};

    # Forward stages
    for (my $s=0; $s <= ($S-$T); $s++) {
        if ($DBG) { print "Transform normal stage $s\n"; }
        for (my $i=0; $i<$D; $i++) {

            my $d = $datapoints->{"$s,$i"};
            if ($DBG) { show_d("  %s => ", $d, $D); }
            for (my $t=($T-1); $t>=0; $t--) {

                # Replace bit d(s+t) w/ P(s+t)
                my $bitpos =  ($s+$t);
                my $P = parity_mod($d, $T, $bitpos);
                $d = replace_bit($d, $bitpos, $P);
                if ($DBG) { print "P[$bitpos]=$P "; }
            }
            if ($DBG) { show_d("=> %s", $d, $D); print "\n"; }
            $deltapoints{"$s,$i"} = $d;
        }
        if ($DBG) { print "\n"; }
    }

    # Reverse stages
    for (my $s = ($S-$T)+1; $s < $S; $s++) {
        if ($DBG) { print "Transform overlap stage $s\n"; }
        for (my $i=0; $i<$D; $i++) {
            my $d = $datapoints->{"$s,$i"};
            if ($DBG) { show_d("  %s => ", $d, $D); }

            for (my $t=0; $t<$T; $t++) {

                # Replace bit d(bitpos) w/ P(bitpos)
                my $bitpos = ($S-1)-$t;
                my $P = parity_mod($d, $T, $bitpos);
                $d = replace_bit($d, $bitpos, $P);
                if ($DBG) { print "P[$bitpos]=$P "; }
            }
            if ($DBG) { show_d("=> %s", $d, $D); print "\n"; }
            $deltapoints{"$s,$i"} = $d;
        }
        if ($DBG) { print "\n"; }
    }
    return %deltapoints;
}

# Given group size G, calculate mem bank m that corresponds to datapoint d
sub parity_map {
    my $d = shift;    # Datapoint index
    my $G = shift;    # Group size
    my $T = log2($G); # Number of toggle bits

    # Calculate m= P(0) + 2P(1) + 4P(2) + ... + 2^(T-1)*P(T-1)
    my ($m, @P) = (0,());
    for (my $t=$T-1; $t>=0; $t--) {
        $P[$t] = parity_mod($d, $T, $t);
        if ($DBG) { print "P[$t]=$P[$t] "; }
        $m = 2*$m + $P[$t];
    }
    if ($DBG) { print "   m=$m"; }
    return $m;
}

# Take parity of every nth bit in operand $op,
# starting w/bit ($b mod $n), where LSB is bit number 0.
sub parity_mod {
    # E.g. if $op=118 (1101 1110) and $n=3 and $b=1
    # Then parity_mod returns XOR of bits 1,4,7 = xor(1,1,1) = 1

    my $op = shift; # Operand e.g. 1101 1110
    my  $n = shift; # XOR together every nth bit of operand, e.g. $n=3
    my  $b = shift; # Start with bit $b, e.g. $b=1

    $b = $b % $n;

    # Shift the word such that desired starting bit is LSB
    my $tmp = $op >> $b;

    # XOR every nth bit and return the answer.
    my $parity = 0;
    while ($tmp) {
        $parity = $parity ^ ($tmp & 0x1);
        $tmp = ($tmp >> $n);
    }
    # if ($DBG) { my $bits = show_bits($op,4); }
    # if ($DBG) { print "foopm $op = $bits ; even_parity = $parity\n\n"; }
    return $parity;
}

# Get the twiddle factor associated w/operand $op in stage $s of $S stages.
sub get_twiddles {
    my $op = shift;  # Want sequential opnum (0,1,2...D-1) not index (0,4,1,5...) or whatever
    my $s = shift;
    my $S = shift;
    my $nowarn = shift;
    my $warn = ($nowarn == 0) ? 0 : 1;

    # Op must be (I think) the smallest of the pair ($op, $op + 2^$s)
    my $zbit = 2**$s;
    if ($op & $zbit) {
        if ($warn) { print "WARNING: opnum should be smallest of the pair\n"; }
        $op = $op & ~$zbit;
    }
    my $i = rrot($op, $S, $s+1);

    my $s2 = ($S-1) - $s;
    my $k = $i >> $s2;
    my $n2 = 2**($s+1);                # n2:  2  4  8 16 32 ... 1024
    my $e = -6.283185307179586;        #  e: -2pi, dunno why really
    my $cos = cos(0.0 + $k * $e/$n2);  # Somehow the "0.0" prevents "-0" answers...!?
    my $sin = sin(0.0 + $k * $e/$n2);
    #printf("TWID op=%2d,     s=$s and S=$S =>     cos is %6.3f\n", $op, $cos); 
    return ($cos,$sin);
}

########################################################################
# For debugging only, and only with sched alg 'round7'

sub show_i {
    my $i = shift;
    my $D = shift;
    my $S = shift;

    my $istring = $D > 10 ? sprintf("%2d", $i) : $i;
    my $ibits = show_bits($i,$S); print "    i=$istring($ibits) => ";
}


sub show_d {
    my $fmt = shift; # E.g. "%s => "
    my $d = shift;
    my $D = shift;
    my $G = shift; # Optional

    my $S = log2($D);

    my $dstring = $D > 10 ? sprintf("%2d", $d) : $d;
    my $dbits = show_bits($d,$S); printf $fmt, "d=$dstring($dbits)";

    # If $G was specific, print the map why not.
    if ($G > 0) { parity_map($d, $G); print "\n"; }

}

sub show_bits {
    # Turn number n=10 into an nbit binary string "1010"
    # E.g. show_bits(7,8) = "00000111"

    my $n = shift;
    my $nbits = shift;

    my @bits = blow2bits($n, $nbits);
    my $bits = scalar(reverse(@bits));
    return $bits;
}

##############################################################################
# Simple helper functions --- all but log2() are used only by 'round7'
#
# log2(n) => E.g. log2(1024) returns "10"
#
# sub reverse_bits(i,nbits)
#    # Reverse the bits in the n-bit integer i
#    # E.g. reverse_bits(13,4)=11 and reverse_bits(13,5)=22
#
# sub rrot(n,nbits,shift_amt)
#    # Right-rotate n-bit integer n by shift_amt
#    # E.g. rrot(13,4,1) = 14  and rrot(13,5,1) = 22
#
# sub lrot(n,nbits,shift_amt)
#    # Left-rotate n-bit integer n by shift_amt
#    # E.g. lrot(13,4,1) = 11  and lrot(13,5,1) = 26
#
##############################################################################

sub log2 {
    my $N = shift @_;
    my $result = 1; while ( (2**$result) < $N ) { $result++; }
    return $result;
}

sub reverse_bits {
    # Reverse the bits in the n-bit integer i
    # E.g.reverse_bits(13,4) = 11
    my $i = shift;
    my $nbits = shift;
    my $rev_i = 0;
    for (my $b=0; $b<$nbits; $b++) {
        my $bottom_bit = $i & 1; 
        $rev_i = 2*$rev_i + $bottom_bit;
        $i = $i >> 1;
    }
    return $rev_i;
}

sub blow2bits {
    # Turn $n into a length-w array of its composite bits.
    my $n = shift;
    my $w = shift;
    my $original_n = $n;

    my $DBG = 0;
    if ($DBG) { print "I see '$n' and I'm-a gonna blow it to bits!"; }

    if (! ($n =~ /[0-9]+/)) {
        die "ERROR blow2bits(): '$n' is not a valid number\n";
    }

    my @bits = ();
#     my @bits = ($b x $w);  $n = $n >> 1; 
    for (my $i = 0; $i < $w; $i++) {
        my $b = $n%2;
        if ($DBG) { print " $b"; }
        $b = sprintf("%d", $b);
        push(@bits, $b); $n = $n >> 1;
    }
    if ($DBG) { print "\n$original_n = {"; print reverse(@bits);  print "} maybe; "; }
    if ($DBG) { print "  MSB=".$bits[$#bits].",LSB=". $bits[0] . "\n\n\n"; }
    return @bits;
}

# Right-rotate
sub rrot {
    my $n         = shift;  # Integer to be rotated e.g. 7 ('00111')
    my $size      = shift;  # Size of integer e.g. 5 (bits)
    my $shift_amt = shift;  # Rotate right this many places\ e.g. 1.

    my $LDBG = 0;
    if ($LDBG) {
        my $n_string = show_bits($n, $size);
        print "\nRotate '$n_string' right by '$shift_amt' places.\n";
    }

    for (my $i=0; $i < $shift_amt; $i++) {
        my $lsb = $n%2;
#        print "lsb is $lsb\n";
        my $msb = $lsb * 2**($size-1); # New msb is old lsb.
        $n = ($n >> 1) + $msb;
#        $n_string = show_bits($n, $size);
#        print "msb is $msb; new n is '$n_string'\n";
    }

    if ($LDBG) {
        my $n_string = int2bin($n, $size);
        print "Result is '$n_string\n\n";
    }

    return $n;
}

# Left-rotate
sub lrot {
    my $n         = shift;  # Integer to be rotated e.g. 7 ('00111')
    my $size      = shift;  # Size of integer e.g. 5 (bits)
    my $shift_amt = shift;  # Rotate right this many places\ e.g. 1.

    # lrot by s bits is same as rrot by nbits-s
    my $n = rrot($n, $size, $size-$shift_amt);
    return $n;
}

sub replace_bit {
    # In the given number $n, replace bit $i with new bit $b
    my $n = shift;
    my $i = shift;
    my $b = shift;

    my $oldbit = $n & (1<<$i);
    my $newbit =     ($b<<$i);

    my $newnum = $n ^ $oldbit ^ $newbit;

#     my $oldbits = show_bits($n,8);        
#     my $newbits = show_bits($newnum,8);   
#     print "rbfoo $n = $oldbits; replace bit $i with $b => $newbits = $newnum\n";    

    return $newnum;
}

##############################################################################
# To test the scheduler, use sub test_fft_scheduler().
# Also see bin/test_scheduler.pl.

sub fft_schedule {
    my $npoints    = shift; # length of FFT: must be a power of two
    my $nunits     = shift; # Number of butterfly units employed per cycle.
    my $reschedule = shift; # "" or any non-zero value e.g. "reschedule_for_conflicts" 
    my $TEST       = shift; # No longer used.

    if ($SCHED_ALG eq 'round7') {
        return fft_schedule_round7($npoints, $nunits, $reschedule);
    }
    else {
        return fft_schedule_modbncombo($npoints, $nunits, $reschedule);
    }
}

##############################################################################
# Compatibility module fft_schedule(npoints,nunits,reschedule)
# must do the same thing as previously: supply @fft_info array
# containing, on a per-cycle basis:
#
# $fft_info[cy]->{op1,op2,ctwid,stwid}
#
# ops and cynums are generated assuming a two-deep pipeline RE/W
# so group size is G=4*nunits
#
# Call from fft_golden_model looks like this:
#    my @fft_info = fft_scheduler::fft_schedule($npoints, $nunits, "");

sub fft_schedule_round7 {
    my $npoints    = shift; # length of FFT: must be a power of two
    my $nunits     = shift; # Number of butterfly units employed per cycle.
    my $reschedule = shift; # "" or any non-zero value e.g. "reschedule_for_conflicts" 

    my $D = $npoints;
    my $G = 4*$nunits;
    my $S = log2($D);

    # This fixes a bug when e.g. G=8 and D=4 e.g. nbutts=4 and npoints=8 and pipedepth=2 (8 4 2port)
    if ($G > $D) { $G = $D; }

    my %datapoints  = build_base_schedule($D,$G);
    my %deltapoints = build_extended_schedule($D,$G,\%datapoints);
    my $schedule = \%deltapoints; # Somewhat unnecessary dontcha think.

    my $fftno = 0;     # cycle number I guess, but not really maybe
    my @fft_info = ();

    print "// swizzler algorithm 'round7'\n"; # Because why not.
    for (my $s=0; $s < $S; $s++) {
        for (my $i=0; $i<$D; $i+=2) {
            my ($i0,$i1) = ($i+0, $i+1);

            # op1, op2
            my $op1 = $schedule->{"$s,$i0"};
            my $op2 = $schedule->{"$s,$i1"};

            # b1, b2 OLD
            # my ($npoints,$nunits) = ($D, $G/4);
            # my ($b1, $r1) = swizzler::swizzle($op1, $npoints, 4*$nunits, 'round7'); # 'round7' should be same as 'mod_bn_combo' I think.
            # my ($b2, $r2) = swizzler::swizzle($op2, $npoints, 4*$nunits, 'round7');

            # b1, b2 NEW
            my $b1 = parity_map($op1, $G);
            my $b2 = parity_map($op2, $G);

            my ($cos,$sin) = get_twiddles($op1, $s, $S, "nowarn");
            # print "fftno=$fftno s=$s op1,op2=$op1,$op2 cos,sin=$cos,$sin\n";

            if ($op1>$op2) { my $t=$op1; $op1=$op2; $op2=$t; }  # Hmmm....

            # I like this so much I'm making it permanent.
            # my $LDBG=1; if ($LDBG) {
                my $indent = "";
                printf($indent."// %2d. ", $fftno);
                printf("Index (%2d,%2d) => banks (%2d,%2d)", $op1, $op2, $b1, $b2);
                printf(",  twid(c,s) = (%6.3f, %6.3f)", $cos, $sin);
                print "\n";
            # }

            init_fft_info(\@fft_info, $fftno,   $s,   $op1, $op2,   $b1,$b2,   $cos,$sin);
            $fftno++;
        }
    }

    # Okay, now add conflict/bypass buffer information.
    my ($nstages,$npoints,$nunits) = ($S,$D,$G/4);
    for (my $stage=1; $stage<$nstages; $stage++) {  # E.g. (0, 1, 2, 3)
        add_bypass_info(\@fft_info, $npoints, $nunits, $stage-1);
    }
    return @fft_info;
}

sub init_fft_info {
    my $fft_info = shift;
    my $fftno    = shift;

    @{$fft_info}[$fftno] = {};
    @{$fft_info}[$fftno]->{stage} = shift;
    @{$fft_info}[$fftno]->{op1} =   shift;
    @{$fft_info}[$fftno]->{op2} =   shift;
    @{$fft_info}[$fftno]->{bank1} = shift;
    @{$fft_info}[$fftno]->{bank2} = shift;
    @{$fft_info}[$fftno]->{ctwid} = shift;
    @{$fft_info}[$fftno]->{stwid} = shift;

    # For $nunits==1 only, uses "access"
    # Choices for {access} (default is always "SRAM"):
    # ("SRAM", "op1 from buf", "op2 from buf", "op1 to buf", "op2 to buf")
    @{$fft_info}[$fftno]->{access} = "SRAM";

    # For $nunits>1 only, uses op[12]_buffer and op[12]_buffer_access
    @{$fft_info}[$fftno]->{op1_buffer} = -1;            # 0, 1, 2, or 3
    @{$fft_info}[$fftno]->{op2_buffer} = -1;
    @{$fft_info}[$fftno]->{op1_buffer_access} = "NONE"; # "RD", "WR", "NONE", or "BOTH"
    @{$fft_info}[$fftno]->{op2_buffer_access} = "NONE"; # "RD", "WR", "NONE", or "BOTH"
}

sub print_fft_info {
    if ($SCHED_ALG eq 'round7') {
        print_fft_info_round7(@_);
    }
    else {
        print_fft_info_modbncombo(@_);
    }
}

sub print_fft_info_round7 {
    my $fft_info = shift;

    my $fmt ="// %2d. %2d | %2d %2d | %2d %2d | %6.3f %6.3f | %2s %-2s | %2s %-2s | %-s\n";
    my $hfmt="// %2s.  %2s | %2s %2s | %2s %2s | %6s %6s | %5s | %5s | %-s\n";
    my $hline = "// --------------------------------------------------------------------\n";

    printf($hfmt, "i", "s","i1","i2","m1","m2","cos  ","sin  ","bbuf1","bbuf2", "access");
    print $hline;

    # if $var == default value $val, print nothing.
    sub pds { my $var = shift; my $val = shift; return ("$var" eq "$val") ? "" : "$var"; }
    sub pdi { my $var = shift; my $val = shift; return ($var == $val) ? "" : "$var"; }

    my $prev_stage = 0;
    for (my $i=0; $i < @{$fft_info}; $i++) {
        my $s = @{$fft_info}[$i]->{stage};
        if ($s != $prev_stage) { print $hline; $prev_stage = $s; }
        printf($fmt, $i,
           @{$fft_info}[$i]->{stage},
           @{$fft_info}[$i]->{op1},
           @{$fft_info}[$i]->{op2},
           @{$fft_info}[$i]->{bank1},
           @{$fft_info}[$i]->{bank2},
           @{$fft_info}[$i]->{ctwid},
           @{$fft_info}[$i]->{stwid},

           pds(@{$fft_info}[$i]->{op1_buffer_access}, "NONE"),
           pds(@{$fft_info}[$i]->{op1_buffer}, "-1"),
           pds(@{$fft_info}[$i]->{op2_buffer_access}, "NONE"),
           pds(@{$fft_info}[$i]->{op2_buffer}, "-1"),
           pds(@{$fft_info}[$i]->{access}, "SRAM"));
    }
}

sub mydir {
    my $offset = shift;  # E.g. "../rtl"

    # Return full path of directory where this script lives offset, according to $offset.
    use Cwd 'abs_path';
    my $fullpath = abs_path($0); # Full pathname of script e.g. "/foo/bar/opendesign.pl"

    use File::Basename 'fileparse';
    my ($filename, $dir, $suffix) = fileparse($fullpath);
    return abs_path("$dir/$offset");
}

###############################################################################
# add_bypass_info() calculates and adds bypass info to @fft_info
#
# To call it:
#    for (my $stage=1; $stage<$nstages; $stage++) {  # E.g. (0, 1, 2, 3)
#        add_bypass_info(\@fft_info, $npoints, $nunits, $stage-1);
#    }
#
# In the case where there's just one butterfly unit, it suffices to set
# 
#    @{$fft_info}[$i]->{access} = (
#      "op1 from buffer", "op2 from buffer", "op1 to buffer" or "op2 to buffer")
#
# When there's more than one butterfly unit we use op[12]_buffer and op[12]_buffer_access
#
#    @{$fft_info}[$i]->{op1_buffer} = $bufnum;       # also {op2_buffer}
#    @{$fft_info}[$i]->{op1_buffer_access} = "WR";   # "RD", "WR", "NONE", or "BOTH"

sub add_bypass_info {
    my $fft_info = shift;
    my $npoints  = shift;
    my $nunits   = shift;
    my $curstage = shift;

    # FIXME see calling context; (curstage, nxtstage) should be relabeled (prev_stage, this_stage)
    my $nxtstage = $curstage+1;

    my $firstcy_nxtstage  = ($curstage+1) * $npoints/2;
    my $lastcy_nxtstage   = ($curstage+2) * $npoints/2 - 1;
    my $lastpack_curstage = $firstcy_nxtstage - $nunits;

    my $odnod = 1; # First conflict (only) should trigger an OD NOD message.
    my $bufnum = 0;

    my $LDBG = 0;
    # See if there's a bank conflict between last group in current stage and first group of next stage.
    for (my $fcur = $lastpack_curstage; $fcur < $firstcy_nxtstage; $fcur++) {
        my $found_conflict = 0;
        for (my $fnxt = $firstcy_nxtstage; $fnxt < ($firstcy_nxtstage + $nunits); $fnxt++) {

            # Look for bank1, bank2 conflicts each in turn.
            foreach my $which_op ('op1', 'op2') {
                
                # if $which_op's write bank conflicts with next cycle's read bank, must bypass
                my $cur_op = find_conflict($fft_info, $fcur, $which_op, $fnxt);
                if ($cur_op eq "") { next; }  # No conflicts found.

                # Conflict! $cur_op is index of conflicting op, in {0..$npoints-1}.
                # (Error if bufnum >= 4)
                $found_conflict = 1;
                if ($LDBG) {
                    my $odnodmsg = "\nOD NOD must buffer things between stages $curstage/$nxtstage.\n";
                    if ($odnod) { $odnod=0; print $odnodmsg; }
                }

                # In cycle $fcur, write $which_op to buffer $bufnum instead of SRAM
                if ($LDBG) { printf("  $fcur: Bypass-write $which_op to buffer $bufnum\n"); }
                bypass_write($fft_info, $fcur, $bufnum, $which_op);

                # Search fft_info from firstcy to lastcy, find next usage of $cur_op;
                #read it from bufnum instead of memory.
                bypass_next_read(
                    $fft_info, $firstcy_nxtstage, $lastcy_nxtstage,
                    $cur_op, $bufnum, $LDBG);

                if ($bufnum > $nunits) { print "\nERROR fft_scheduler.pm: too many bufs!\n"; }
                $bufnum++;

                # BUG/TODO/FIXME different bypass mechanism for nunits==1
                # BUG/TODO/FIXME is it used?
                if ($nunits==1) { @{$fft_info}[$fcur]->{access} = "$which_op to buffer"; }
            }
        }
        if ($found_conflict == 0) {
            my $msg = "\nERROR fft_scheduler::add_bypass_info(): no bank conflict between stages?\n";
            print $msg; die $msg;
        }
    }
}

sub find_conflict {
    my $fft_info = shift;
    my $fcur = shift;
    my $which_op = shift;
    my $fnxt = shift;

    my ($cur_op1, $cur_op2, $curb1, $curb2) = get_ops_and_banks($fft_info, $fcur);
    my $cur_op  = ($which_op eq 'op1') ? $cur_op1 : $cur_op2;
    my $curbank = ($which_op eq 'op1') ? $curb1   : $curb2;

    my $nxtb1 = @{$fft_info}[$fnxt]->{bank1};
    my $nxtb2 = @{$fft_info}[$fnxt]->{bank2};

    my $LDBG=0;
    if ($LDBG) { print "  bnr(): cy$fcur.$which_op=b$curbank; cy$fnxt.op1=b$nxtb1 and cy$fnxt.op1=b$nxtb2\n"; }


#    if (($curb1 == $nxtb1) || ($curb2 == $nxtb2)) { return $cur_op; }
    if (($curbank == $nxtb1) || ($curbank == $nxtb2)) { return $cur_op; }
    else { return ""; }
}


# Find next usage of $cur_op; read it from bypass_buffer[$bufnum] instead of SRAM
sub bypass_next_read {
    my $fft_info = shift;
    my $firstcy_nxtstage = shift;
    my $lastcy_nxtstage = shift;
    my $cur_op = shift;
    my $bufnum = shift;
    my $LDBG = shift;

    # Find next usage of $cur_op; read it from bypass_buffer[$bufnum] instead of SRAM
    for (my $fi=$firstcy_nxtstage; $fi <= $lastcy_nxtstage; $fi++) {
   #for (my $fi=$firstcy_nxtstage; $fi < $lastcy_nxtstage; $fi++) {  # Substitute this to break subtly.

        if ($cur_op == @{$fft_info}[$fi]->{op1}) {

            # In cycle $fi, read op1 from $bufnum instead of SRAM
            bypass_read( $fft_info, $fi,   $bufnum, "op1");
            if ($LDBG) { print "  $fi: Bypass-read  op1 from buffer $bufnum\n\n"; }
            return;
        }
        elsif ($cur_op == @{$fft_info}[$fi]->{op2}) {

            # In cycle $fi, read op2 from $bufnum instead of SRAM
            bypass_read( $fft_info, $fi,   $bufnum, "op2");
            if ($LDBG) { print "  $fi: Bypass-read  op2 from buffer $bufnum\n\n"; }
            return;
        }
    }
}

sub bypass_read {
    my $fft_info = shift;
    my $readcy   = shift;
    my $bufnum   = shift;
    my $op       = shift;

    #my $dbgmsg = "  $readcy: Bypass-read  $op from buffer $bufnum\n";
    @{$fft_info}[$readcy]->{"${op}_buffer"} = $bufnum;
    if (@{$fft_info}[$readcy]->{"${op}_buffer_access"} eq "WR") {
        print "\nERROR fft_scheduler.pm: not prepared to handle \"BOTH\"?\n";
    };
    @{$fft_info}[$readcy]->{"${op}_buffer_access"} = "RD";
    
    # BUG/TODO/FIXME different bypass mechanism for nunits==1
    # if ($nunits==1) { @{$fft_info}[$fi]->{access} = "op1 from buffer"; }
    @{$fft_info}[$readcy]->{access} = "$op from buffer"; # Used only for nunits==1
}

sub bypass_write {
    my $fft_info = shift;
    my $fcur     = shift;
    my $bufnum   = shift;
    my $op       = shift; # 'op1' or 'op2'

    @{$fft_info}[$fcur]->{"${op}_buffer"} = $bufnum;
    @{$fft_info}[$fcur]->{"${op}_buffer_access"} = "WR";
}



sub get_ops_and_banks {
    my $fft_info = shift;
    my $fi = shift;

    my $op1    = @{$fft_info}[$fi]->{op1};
    my $op2    = @{$fft_info}[$fi]->{op2};
    my $bank1  = @{$fft_info}[$fi]->{bank1};
    my $bank2  = @{$fft_info}[$fi]->{bank2};

    return ($op1, $op2, $bank1, $bank2);
}

####################################################################################
####################################################################################
####################################################################################
# Everything from here down is specific to the old/deprecated scheduling algorithm #
# 'mod_bn_combo'.  If when we stop using 'mod_bn_combo', this can just go away.    #
####################################################################################
####################################################################################
####################################################################################

##############################################################################
# Given:
#    $npoints     # length of FFT: must be a power of two
#    $nunits      # Number of butterfly units employed per cycle.
#    $reschedule  # (optional) Any non-zero value e.g. "reschedule" 
#
# fft_scheduler($npoints, $nunits) returns array @fft_info, where each entry contains:
#   $fft_info[$i]->{stage}  # FFT stage number (see below)
#   $fft_info[$i]->{op1}    # Index of butterfly op 1
#   $fft_info[$i]->{op2}    # Index of butterfly op 2
#   $fft_info[$i]->{bank1}  # SRAM bank for op1
#   $fft_info[$i]->{bank2}  # SRAM bank for op2
#   $fft_info[$i]->{ctwid}  # twiddle factor COSINE
#   $fft_info[$i]->{stwid}  # twiddle factor SINE
#
#   $fft_info[$i]->{access} # If reschedule TRUE, tells when to use the bypass buffer.
#
#   $fft_info[$fftno]->{op1_buffer} = -1;  # {access} info for nunits > 1
#   $fft_info[$fftno]->{op2_buffer} = -1;  # {access} info for nunits > 1
#   $fft_info[$fftno]->{op1_buffer_access} # {access} info for nunits > 1
#   $fft_info[$fftno]->{op2_buffer_access} # {access} info for nunits > 1
#
# Choices for {access} (default is always "SRAM"):
#         ("SRAM", "op1 from buf", "op2 from buf", "op1 to buf", "op2 to buf")
#
# For nunits>1, there are multiple bypass buffers numbered from 0 to (nunits-1)
#   {op1_buffer} = which buffer (0 to nunits-1) holds op1 
#   {op1_buffer_access} == "RD" => Read op1 from buffer
#   {op1_buffer_access} == "WR" => Write op1 to buffer
# ...and similarly for op2.
#
##############################################################################
# Sample fft_info contents returned by fft_schedule(8,1,"resched"):
# 
# //---------------------------- Stage 0 ----------------------------//
# 
# //  0. Index ( 0, 1) => banks ( 0, 3),  twid(c,s) = ( 1.000,  0.000)
# //  1. Index ( 2, 3) => banks ( 2, 1),  twid(c,s) = ( 1.000,  0.000)
# //  2. Index ( 6, 7) => banks ( 3, 0),  twid(c,s) = ( 1.000,  0.000)
# //  3. Index ( 4, 5) => banks ( 1, 2),  twid(c,s) = ( 1.000,  0.000) * op2 to buffer (ix5)
# 
# //---------------------------- Stage 1 ----------------------------//
# 
# //  4. Index ( 0, 2) => banks ( 0, 2),  twid(c,s) = ( 1.000,  0.000)
# //  5. Index ( 4, 6) => banks ( 1, 3),  twid(c,s) = ( 1.000,  0.000)
# //  6. Index ( 5, 7) => banks ( 2, 0),  twid(c,s) = ( 0.000, -1.000) * op1 from buffer (ix5)
# //  7. Index ( 1, 3) => banks ( 3, 1),  twid(c,s) = ( 0.000, -1.000) * op2 to buffer (ix3)
# 
# //---------------------------- Stage 2 ----------------------------//
# 
# //  8. Index ( 0, 4) => banks ( 0, 1),  twid(c,s) = ( 1.000,  0.000)
# //  9. Index ( 1, 5) => banks ( 3, 2),  twid(c,s) = ( 0.707, -0.707)
# // 10. Index ( 3, 7) => banks ( 1, 0),  twid(c,s) = (-0.707, -0.707) * op1 from buffer (ix3)
# // 11. Index ( 2, 6) => banks ( 2, 3),  twid(c,s) = ( 0.000, -1.000)

sub test_fft_scheduler {
    $DBG = shift;

    my $npoints = 8; # Length of FFT: must be a power of two
    my $nunits  = 1; # How many butterfly units employed per cycle; must be a power of two.

    fft_schedule($npoints, $nunits, "reschedule");
    fft_schedule($npoints,    2,    "reschedule");
    fft_schedule(   16,       1,    "reschedule");
    fft_schedule(   32,       4,    "reschedule");
    fft_schedule(  1024,      1,    "reschedule");
}

# COLLSITES Keeps track of per-stage collision sites,
# e.g. $COLLSITES[2] = (2,4) means stage 2 had collisions at ops 2 and 4
# For now, at least, I guess we need this to be global.
my @COLLSITES;

sub fft_schedule_modbncombo {
    my $npoints    = shift; # length of FFT: must be a power of two
    my $nunits     = shift; # Number of butterfly units employed per cycle.
    my $reschedule = shift; # "" or any non-zero value e.g. "reschedule_for_conflicts" 

    # Turn this on to test the algorithm finder.
    # test_ag_alg_finder(); exit;

    # Generate the initial indices and schedule.  Sets the global COLLSITES
    my @fft_info =
        fft_gen_indices($npoints, $nunits);

    # If the reschedule parm says "GET_CRAZY_VERILOG" (and not e.g. "" or "reschedule"), 
    # generate verilog code and then quit.
    if ($reschedule eq "GET_CRAZY_VERILOG") {
        my @crazy_verilog = ();
        my $nstages = log2($npoints);                   # E.g. 16 points => 4 stages
        for (my $s=0; $s < $nstages; $s++) {
            my @alg = find_ag_alg($npoints,@{$COLLSITES[$s]});
            my $alg = decode_alg(@alg);
            $crazy_verilog[$s] = gen_crazy_verilog($s, @alg);
        }
        return @crazy_verilog;
    }

   # Early out.
    if ($reschedule ne 'reschedule') { return @fft_info; }

    # Now do it again with the crazy eye, generates a crazy (collision-free!) clock.
    @fft_info =
        fft_gen_indices($npoints, $nunits, 'crazy');

    # Reschedule for bypassing if requested.
    # I think all this does anymore is insert the bypass buffers.
    # if ($reschedule eq 'reschedule') { I think this breaks if called from testsched
    if ($reschedule ne '') {
        @fft_info =
            reschedule($npoints, $nunits, @fft_info);
    }
    return @fft_info;
}

sub fft_gen_indices {
    #################################################################################
    # Generate an initial schedule for an npoint FFT having "nunits" butterfly units.
    # Schedule may or may not have bank conflicts, those will be fixed later.
    # 
    # To use:  fft_gen_indices($npoints, $nunits);
    # Where:
    #    npoints is 8, 16, 32, 64, 128, 256, 512 or 1024
    #    and nunits is 1, 2 or 4

    # Inspired by a c program found online at http://cnx.org/content/m12016/latest/
    # Also see: alg_rev_in.ref.c

    my $LDBG = $DBG;
    track_banks("off");  # Don't track collisions (yet).

    my $indent = ""; # Was: "my $indent = shift;"

    my $npoints = shift;   # length of FFT: must be a power of two.
    my $nunits = shift;    # Number of butterfly units employed per cycle.
    my $eye    = shift;    # Might be CRAZY!!!

    # Clear the global data structs.
    my @fft_info = ();
    my $fftno = 0;

    if ($LDBG) {
        my $call_type = $eye eq 'crazy' ? "*** Crazy" : "* Initial";
        print "*********************************************************************\n";
        print "***$call_type call to fft_gen_indices() *******************************\n";
    }
    if ($LDBG) {
        my $orphans = log2($npoints) % log2(4*$nunits);
        # printf("orphan nabits=$NABITS nbbits=$NBBITS orphans=$orphans HELLO\n");

        my $howmany_butts = $nunits == 1 ? "one butterfly unit" : "$nunits butterfly units";
        print "\n";
        print $indent."/////////////////////////////////////////////////////////////////////\n";
        print $indent."// $npoints FFT data points; $howmany_butts (orphans: $orphans )\n";
        print "\n";
    }

    my $nstages = log2($npoints);
    for (my $s=0; $s < $nstages; $s++) {           # E.g. 0,1,2...9 for npoints=1024

        if ($LDBG) {
            print $indent;
            my $hline = "----------------------------";
            print "//$hline Stage $s $hline//\n\n";
        }

        for (my $ii=0; $ii < $npoints/2; $ii++) {

            # If requested generate a crazy clock munger that automatically
            # avoids all collisions w/out the need for swap operations.
            my $i = $eye eq 'crazy' ? 
                crazy_eye($ii, $npoints, $nunits, $s) : $ii;

            my $s2 = ($nstages-1) - $s;        # 9,8,7,6,5,4,3,2,1,0
            my $j = $i & (2**$s2 - 1);         # i & (511,255,127...2,1,0)
            my $k = $i >> $s2;                 # s=0,i=(0,1,2,...509,510,511)=>k=(0,1,2...511)

            # Calculate twiddle factors        #  s:  0  1  2  3  4 ... 9
            my $n2 = 2**($s+1);                # n2:  2  4  8 16 32 ... 1024
            my $e = -6.283185307179586;        #  e: -2pi, dunno why really
            my $cos = cos(0.0 + $k * $e/$n2);  # Somehow the "0.0" prevents "-0" answers...!?
            my $sin = sin(0.0 + $k * $e/$n2);
            
            my $op1 = ($j << ($s+1)) + $k;     # s=0 => op1=(j<<
            my $op2 = $op1 + 2**$s;
            
            # (See far below for "Old algorithm for calculating op1 and op2.")
            
            my ($b1, $r1) = swizzler::swizzle($op1, $npoints, 4*$nunits, 'mod_bn_combo');
            my ($b2, $r2) = swizzler::swizzle($op2, $npoints, 4*$nunits, 'mod_bn_combo');
            
            # I like this, I'm keeping it.
            # if ($LDBG) {
                printf($indent."// %2d. ", $fftno);
                printf("Index (%2d,%2d) => banks (%2d,%2d)", $op1, $op2, $b1, $b2);
                printf(",  twid(c,s) = (%6.3f, %6.3f)", $cos, $sin);
                print "\n";
            # }

            init_fft_info(\@fft_info, $fftno,   $s,   $op1, $op2,   $b1,$b2,   $cos,$sin);
            $fftno++;
        }
        if ($LDBG) { print "\n"; }  # Separator at the end of each stage.
    }

    # First time through ($eye ne crazy), generate collision sites $COLLSITES
    # (Second time through, USE collision sites @COLLSITES (in crazy_eye() call, above).
    if ($eye ne 'crazy') {
        find_collision_sites($npoints, $nunits, \@fft_info);

    }
    # printf("shlag0 cs[0]=%s\n\n", join(',', @{$COLLSITES[0]}));

    if ($LDBG) {
        print "\n";
        my $call_type = $eye eq 'crazy' ? "crazy" : "initial";
        print "*** Result of $call_type call to fft_gen_indices(): ***\n\n";
        track_banks("on"); # This is the only place where we need to detect collisions
        print_fft_info($npoints, $nunits, @fft_info);
        check_for_well_formed_schedule($npoints, $nunits, \@fft_info, $#fft_info);
        track_banks("off");
    }
    return @fft_info;
}

sub crazy_eye {
    my $ii = shift;
    my $npoints = shift;
    my $nunits = shift;
    my $s = shift;        # Stage number e.g. 0..9

    # Use information in COLLSITES to generate a crazy clock-munge algorithm
    # that avoids ALL COLLISIONS (except interstage collisions).
    my @alg = find_ag_alg($npoints, @{$COLLSITES[$s]});
    my $alg = decode_alg(@alg);

    my $default_direction = 'down'; # Count DOWN e.g. from 1023 down to 0
    my $default_direction = 'up';   # Count UP e.g. from 0 to 1023

    my $other_direction = ($default_direction eq 'up') ? 'down' : 'up';

    # count_direction eq  'up'  => i={0,1,2,3, 4,5,6,7, 8,9,a,b, c,d,e,f}
    # count_direction eq 'down' => i={f,d,e,c, b,a,9,8, 7,6,5,4, 3,2,1,0}

    # Automatically munge the clock using @alg, e.g. $i = f(alg, $ii)
    # where $ii is the original clock value and $i is the new clock value.
    if (1) {
        # @alg = ($npoints, $mask, $toggle-point(s))
        #   E.g. alg=(16,0x3,4) => i={0,1,2,3, 7,6,5,4, 8,9,a,b, f,d,e,c} (I think)
        #   Count up four, then down four etc.
        #   (This is the fix when the first star appears at Index 4).

        my $npoints = shift @alg;    # E.g. 16
        my $mask =    shift @alg;    # E.g. 0x3

        # xor all the toggle-points together;
        # count up or down according to the final value.
        my $xors = 0;
        foreach my $iibit (@alg) {
            my $bit = ($ii & $iibit) ? 1 : 0;
            $xors = $xors ^ $bit;
        }
        my $count_direction = ($xors == 0) ? 'up' : 'down' ;
        my $i = $count_direction eq 'up' ? $ii : $ii ^ ($mask);
        return $i;
    }
}

sub reschedule {
    my $LDBG = $DBG;        # BUG/TODO/FIXME What's the point of this??

    my $npoints = shift @_; # $npoints and $nunits are not really necessary here...
    my $nunits = shift @_;
    my @fft_info = @_;

    if ($LDBG) { print "\n*** reschedule() ***\n"; }

    # First pass sorts each stage according to either hi-lo
    # or odds and evens (or "0356/1247", aka "xor/xnor")

    # E.g. grouping[0] = grouping strategy for stage 0 ("odd/even" or "hi/lo") (or "0356/1247")
    # E.g. grouping[0] = grouping strategy for stage 0 ("odd/even" or "hi/lo")

    my @grouping;
    my $nstages = log2($npoints);                   # E.g. 16points => 4
    for (my $stage=0; $stage<$nstages; $stage++) {  # E.g. (0, 1, 2, 3)

        # Record the grouping type; should be same throughout the stage.
        # Final assignment will be either 0 ("odds") or 1 ("hi").  Or 4 ("1247").
        # Or...maybe other things too.

        # Could as easily (or better!) base grouping type on first op of each stage:
        my $first = $stage*$npoints/2;            # E.g. (0, 8,16,24)

        # But for now continue to use last, avoids short-term problems.
        my $last = $first + $npoints/2 - 1;
        $grouping[$stage] = find_acctype($last, $nunits*4, \@fft_info);        
        if ($LDBG) {
            print "FOOB stage $stage has grouping $grouping[$stage]\n";
        }
    }

    if ($LDBG) {
        print "\n\n*** and now schedule looks like this: ***\n\n";
        print_fft_info($npoints, $nunits, @fft_info);
        print "\n";
    }

    # Make another pass, check final pack in each stage n
    # (except final stage) to see if we need to do bypassing.
    #
    # E.g. for nunits==4 and packs are quads:
    # final_quad(n)  final_quad(n+1) action
    # -------------  --------------- ------
    #  odds               odds        none
    #  odds               hi          "lo" banks => buffer
    #  hi                 hi          none
    #  hi                 odds        "odd" banks => buffer
    #
    # "buffer" means all "lo" (or "odd" as the case may be) ops
    # get buffered until next use.
    # need to add the following fields for nunits==4 case:
    # op1_buffer_access ("RD", "WR", "NONE", or "BOTH") (what does that mean "BOTH"??)
    # op1_buffer (0, 1, 2, or 3)
    # same for op2
    #
    # Note: above algorithm later extended to "0356/1247"

    my $nstages = log2($npoints);                   # E.g. 16points => 4
    for (my $stage=1; $stage<$nstages; $stage++) {  # E.g. (0, 1, 2, 3)
        add_bypass_info(\@fft_info, $npoints, $nunits, $stage-1);
    }
    if ($LDBG) {
        print "\n\n*** and now schedule looks like this: ***\n\n";
        print_fft_info($npoints, $nunits, @fft_info);
    }
    my $dhline = "=====================================================================\n";
    if ($LDBG) {
        print "\n$dhline\n";
        print "\n*** FINAL SCHEDULE (below) ***\n\n";
        print_fft_info($npoints, $nunits, @fft_info);
    }
    return (@fft_info);
}

sub find_collision_sites {
    my $npoints = shift @_;
    my $nunits = shift @_;
    my $fft_info = shift;

    @COLLSITES = ();

    my $nstages = log2($npoints);
    for (my $s = 0; $s < $nstages; $s++) {

        @{$COLLSITES[$s]} = ();

        my @prev_banks = ();
        my @this_banks = ();

        my $first_i = $s * ($npoints/2);
        my $last_i = $first_i + $npoints/2;

        for (my $i = $first_i; $i < $last_i; $i++) {

            my $stage = @{$fft_info}[$i]->{stage};
            my $op1   = @{$fft_info}[$i]->{op1};
            my $op2   = @{$fft_info}[$i]->{op2};
            my $b1    = @{$fft_info}[$i]->{bank1};
            my $b2    = @{$fft_info}[$i]->{bank2};

            $this_banks[$b1] = $b1;
            $this_banks[$b2] = $b2;

            # FIXME Looks like this (below) should be a separate sub...?
            if (($i % $nunits) == ($nunits - 1)) {
                # Compare this cycle's banks to prev cycle (unless first cycle)
                if ($i != $first_i) {
                    my $nc = 0;
                    foreach my $tb (@this_banks) {
                        my $DBG9 = 0;
                        if ($DBG9) { print "  foo tb $tb\n"; }
                        if ($tb eq "") { next; }
                        foreach my $pb (@prev_banks) {
                            if ($DBG9) { print "    foo pb $pb"; }
                            if ($tb eq $pb) {
                                if ($DBG9) { print " BAM!\n"; } # else { print " *"; }
                                $nc++;
                                last;
                            }
                            elsif ($DBG9) { print "\n"; }
                        }
                    }
                    if ($nc) {
                        my $stage = $s;
                        push @{$COLLSITES[$stage]}, (($i - ($nunits-1)) - $first_i);
                        # printf("shlag cs[$stage] = %s\n\n", join(',', @{$COLLSITES[$stage]}));
                    }
                }
                @prev_banks = @this_banks;
                @this_banks = ();
            }
        }
    }
    # printf("shlaggy9 cs[0]=%s\n\n", join(',', @{$COLLSITES[0]}));
}

sub print_fft_info_modbncombo {
    my $npoints = shift @_;
    my $nunits = shift @_;
    my @fft_info = @_;

    my $cytype = "ic";
    my $prev_stage = -1;

    track_banks("init");

    for (my $i = 0; $i < @fft_info; $i++) {
        my $stage  = $fft_info[$i]->{stage};
        my $op1    = $fft_info[$i]->{op1};
        my $op2    = $fft_info[$i]->{op2};
        my $bank1  = $fft_info[$i]->{bank1};
        my $bank2  = $fft_info[$i]->{bank2};
        my $ctwid  = $fft_info[$i]->{ctwid};
        my $stwid  = $fft_info[$i]->{stwid};

        # Print stage header.
        if ($prev_stage != $stage) {
            if ($stage != 0) { print "\n"; }
            my $hline = "----------------------------";
            print "//$hline Stage $stage $hline//\n\n";
            $prev_stage = $stage;
            $cytype = "is";
        }
        # Extra line after each cycle
        elsif (($nunits > 1) && ($i > 0) && (($i % $nunits) == 0)) { print "\n"; }

        printf("// %2d (cy %d). %d   ", $i, $i/$nunits, $nunits);
        printf("Index (%2d,%2d) => banks (%2d,%2d)", $op1, $op2, $bank1, $bank2);
        printf(",  twid(c,s) = (%6.3f, %6.3f)", $ctwid, $stwid);

        # At end of each operation, update list of banks used.
        track_banks("add", ($bank1,$bank2));

        # At end of each cycle, check bank conflicts
        my $nc = 0; # How many collisions?
        if ($nunits == 1) {
#             $nc = track_banks($cytype); $cytype = "ic"; # Reset conflict type to ic (intercycle).
            $nc = track_banks($cytype, $npoints, $nunits, $i);
            $cytype = "ic"; # Reset conflict type to ic (intercycle).
        }
        elsif (($i % $nunits) == ($nunits-1)) {
#             $nc = track_banks($cytype); $cytype = "ic"; # Reset conflict type to ic (intercycle).
            $nc = track_banks($cytype, $npoints, $nunits, $i);
            $cytype = "ic"; # Reset conflict type to ic (intercycle).
        }
        else {
           # (don't check for conflict yet; not yet reached end of cycle)
        }
        print_buffer_access_info(\@fft_info, $i, $nunits);
    }

    # Report swizzle-algorithm and collision sites
    # FIXME this should all be wrapped in a separate report_reseq_info routine.
    if (tb_power_switch() eq 'on') {
        print "\n\n";

        # NOTE as part of print_fft_info, none of this ever happens unless $LDBG==1 (right?)

        # FIXME!
        # Okay this is really awful.  Redirect stdout to print verilog for swizzling the address,
        # as a RESEQ informational comment.
        open FILE, ">/tmp/tmp";     # Send swizzler output to /tmp/tmp
        select FILE;                # Swizzler-prints will use FILE instead of STDOUT
        swizzler::swizzle('VLOG', $npoints, 4*$nunits, 'mod_bn_combo');
        select STDOUT;              # Back to normal (restore STDOUT)
        my $msg = `cat /tmp/tmp | grep bnum | sed 's/^/RESEQ/' | sed 's/assign\\|num_o\\|ddr_i//g'`;
        print "$msg";
        print "RESEQ\n";

        print "RESEQ n= $npoints , b= $nunits , collision sites: ";
        my $nstages = log2($npoints);
        for (my $s=0; $s < $nstages; $s++) {
            printf("{%s}", join(',', @{$COLLSITES[$s]}));
        }
        print " =>\n";

        for (my $s=0; $s < $nstages; $s++) {
            my @alg = find_ag_alg($npoints,@{$COLLSITES[$s]});
            my $alg = decode_alg(@alg);
            printf("RESEQ alg n= %4d , b= $nunits s= $s %s\n", $npoints, $alg);

            my $v = gen_crazy_verilog($s, @alg);
            $v =~ /(^.*[?])(.*)/;    # E.g.  (CrazyEye <= CycleNum[2] ?)( CycleNum : CycleNum^1;)
            my ($v1,$v2) = ($1,$2);
            print "RESEQ VLOG $v1 // Stage $s\n";
            print "RESEQ VLOG   $v2\n";

            print "RESEQ\n";
        }
        print "RESEQ____________________________________________________________\n";
    }

    # time for our collision report now
    track_banks("report", $npoints, $nunits);
    return;

    ######### LOCAL SUBROUTINES ##########
    sub print_buffer_access_info {
        my $fft_info = shift;
        my $i = shift;
        my $nunits = shift;

        my $op1 =     @{$fft_info}[$i]->{op1};
        my $op2 =     @{$fft_info}[$i]->{op2};

        my $access = @{$fft_info}[$i]->{access};
        if ($nunits > 1) {
            # Use alternate buffer_access info

            my $buf1 =    @{$fft_info}[$i]->{op1_buffer};        # -1, 0, 1, 2, or 3
            my $buf2 =    @{$fft_info}[$i]->{op2_buffer};        # -1, 0, 1, 2, or 3
            my $access1 = @{$fft_info}[$i]->{op1_buffer_access}; # "RD", "WR", "NONE", or "BOTH"
            my $access2 = @{$fft_info}[$i]->{op2_buffer_access};

            my @comm = ();

            if (($access1 eq "RD") || ($access1 eq "BOTH")) {
                push @comm, sprintf("op1 (ix%02d) from buf%d",   $op1, $buf1);
            }
            if (($access1 eq "WR") || ($access1 eq "BOTH")) {
                push @comm, sprintf("op1 (ix%02d) to buf%d", $op1, $buf1);
            }
            if (($access2 eq "RD") || ($access2 eq "BOTH")) {
                push @comm, sprintf("op2 (ix%02d) from buf%d",   $op2, $buf2);
            }
            if (($access2 eq "WR") || ($access2 eq "BOTH")) {
                push @comm, sprintf("op2 (ix%02d) to buf%d", $op2, $buf2);
            }
            if (@comm) { printf(" * %s", join("; ", @comm)); }
        }

        elsif ($access ne "SRAM") {
            my $ix = ($access =~ /op1/) ? $op1 : $op2;
            printf(" * $access (ix%d)", $ix);
        }
        print "\n";
    }
}

##################################################################################
# FIXME track_banks is maybe a good candidate for a separate module track_banks.pm
# with subs e.g. trac_banks::add tracK_banks::power etc.

# Globals for use by track_banks.
my @prev_banks = ();
my @this_banks = ();
my %ncollisions = ("ic", 0, "is", 0);
my %nstalls     = ("ic", 0, "is", 0);
my $tb_power_switch = "on"; # Turn "track_banks" on or off.

# FIXME power switch is a stoopid hack.
sub tb_power_switch { return $tb_power_switch; }

sub track_banks {
    my $DBG9 = 0;
    # track_banks("add", ($b1,$b2)) => add ($b1,$b2) to @this_bank list
    # track_banks("ic") => check @this_banks against prev for intercycle collisions
    # track_banks("is") => check @this_banks against prev for interstage collisions
    # track_banks("init")   => see below (cop-out!)
    # track_banks("on")     => see below (cop-out!)
    # track_banks("off")    => see below (cop-out!)
    # track_banks("report") => see below (cop-out!)
    # track_banks("ic" or "is", ($npoints/$b1, $nunits/$b2, $fi)
    #                       => Build COLLSITES collision sites array

    # Unpack the args
    my $cytype = shift @_; # "add", "is" or "ic" (see above)
    my $b1 = shift;
    my $b2 = shift;
    my $fi = shift;

    my ($npoints,$nunits) = ($b1,$b2); # oops FIXME args do double duty

    # Turn track_banks() on or off
    if ($cytype eq "off") { $tb_power_switch = "off"; return; }
    if ($cytype eq "on" ) { $tb_power_switch = "on" ; return; }
    if ($tb_power_switch eq "off") { return; }

    if ($cytype eq "init") { # Reset globals used by track_banks()
        @prev_banks = (); @this_banks = ();
        %ncollisions = ("ic", 0, "is", 0);
        %nstalls     = ("ic", 0, "is", 0);
        return;
    }
    if ($cytype eq "add") { # Add indicated banks to list of banks used this cycle.
        $this_banks[$b1] = $b1;
        $this_banks[$b2] = $b2;
        return;
    }

    if ($cytype eq "report") { # Report a summary of all collisions found so far.
        print "\n";
        my ($npoints,$nunits) = ($b1,$b2); # oops
        print "*** Collision report: $npoints data points $nunits butterfly unit(s) ***\n";

        my $ic = sprintf("%4d intercycle collisions", $ncollisions{"ic"});
        my $is = sprintf("%4d interstage collisions", $ncollisions{"is"});
        my $tot= sprintf("%4d total collisions", $ncollisions{"ic"} + $ncollisions{"is"});
        print "*** $ic + $is = $tot ***\n";

        my $ic = sprintf("%4d intercycle stalls    ", $nstalls{"ic"});
        my $is = sprintf("%4d interstage stalls    ", $nstalls{"is"});
        my $tot= sprintf("%4d total stalls", $nstalls{"ic"} + $nstalls{"is"});
        print "*** $ic + $is = $tot ***\n";

        printf("*** csv_conflicts, %4d, %4d, %4d, %4d, ***\n", $npoints, $nunits, $nstalls{'ic'}, $nstalls{'is'});

        print "\n";
        return;
    }

    # $ctype = "is" or "ic"

    if ($DBG9) { # For internal debugging.
        print "\n";
        print "$cytype This cycle used banks: " . join(" ", @this_banks) . "\n";
        print "$cytype Prev cycle used banks: " . join(" ", @prev_banks) . "\n";
    }

    # Default action: compare all banks used in this cycle with those used in prev cycle
    # Count and classify collisions according to cytype "ic" (intercycle) or "is" (interstage)
    my $nc = 0; # How many conflicts *in this cycle only*
    foreach my $tb (@this_banks) {
        if ($DBG9) { print "  foo tb $tb\n"; }
        if ($tb eq "") { next; }
        foreach my $pb (@prev_banks) {
            if ($DBG9) { print "    foo pb $pb"; }
            if ($tb eq $pb) {
                if ($DBG9) { print " BAM!\n"; } else { print " *"; }
                $nc++;
                $ncollisions{$cytype}++;
                last;
            }
            elsif ($DBG9) { print "\n"; }
        }
    }
    if ($nc) {
        $nstalls{$cytype}++;
        if ($DBG9) {
            print "ic collisions = " . $ncollisions{"ic"} . "; ";
            print "is collisions = " . $ncollisions{"is"} . "\n";

            print "ic stalls = " . $nstalls{"ic"} . "; ";
            print "is stalls = " . $nstalls{"is"} . "\n";
        }
    }
    @prev_banks=@this_banks; @this_banks = ();
    return $nc;
}
    
sub find_acctype_old {
    # 0=>odds, 1=>hi, 2=>evens, 3=>lo, -1=>ERROR
    # Adding: 4=>"1247", 5=>"0356"

    my $fi  = shift @_;
    my $nbanks = shift @_;
    my $fft_info = shift @_;

    # 0=>odds, 1=>hi, 2=>evens, 3=>lo, -1=>ERROR
    my $b1 = @{$fft_info}[$fi]->{bank1};  # Or: $fft_info->[$fi]->{bank1}
    my $b2 = @{$fft_info}[$fi]->{bank2};

#    my $op1    = @{$fft_info}[$fi]->{op1};
#    my $op2    = @{$fft_info}[$fi]->{op2};
#    printf("\nFOO fi=$fi nbanks=$nbanks b1=$b1 b2=$b2 op1=$op1 op2=$op2\n");

    # DO NOT CHANGE ORDER!!!  There's a precedence. 
    if (is_hi  ($b1,$nbanks) && is_hi  ($b2,$nbanks)) { return 1; }
    if (is_lo  ($b1,$nbanks) && is_lo  ($b2,$nbanks)) { return 3; }
    if (is_odd ($b1,$nbanks) && is_odd ($b2,$nbanks)) { return 0; }
    if (is_even($b1,$nbanks) && is_even($b2,$nbanks)) { return 2; }

    if (is_0356($b1,$nbanks) && is_0356($b2,$nbanks)) { return 5; }
    if (is_1247($b1,$nbanks) && is_1247($b2,$nbanks)) { return 4; }

    # die "\n\nERROR find_acctype_old() unknown group!\n\n";
    my $LDBG = $DBG;
    if ($LDBG) {
        print "\n\nWARNING find_acctype_old() unknown group.";
        print "(But that don't stop us no more.)\n\n";
    }
    return -1;

    ### LOCAL SUBROUTINES ###
    sub is_hi   { my $i=shift; my $nbanks=shift; return ($i >= $nbanks/2); }
    sub is_lo   { my $i=shift; my $nbanks=shift; return ($i <  $nbanks/2); }
    sub is_odd  { my $i=shift; my $nbanks=shift; return (($i%2) == 1); }
    sub is_even { my $i=shift; my $nbanks=shift; return (($i%2) == 0); }

    # XOR all the bits together and get 0 ("0356") or 1 ("1247")
    sub is_0356 { my $i=shift; my $nbanks=shift; return
                      (($i == 0) || ($i == 3) || ($i == 5) || ($i == 6) ||
                       ($i == 9) || ($i ==10) || ($i ==12) || ($i ==15)); }

    sub is_1247 { my $i=shift; my $nbanks=shift; return
                      (($i == 1) || ($i == 2) || ($i == 4) || ($i == 7) ||
                       ($i == 8) || ($i ==11) || ($i ==13) || ($i ==14)); }
}

sub find_acctype {
    
    ##############################################################################
    # Turn crazy eye on or off (not used with 'round7')
    my $USE_ACCTYPES = 0; # 0=> Rely on crazy eye ONLY to remove collisions.
    my $USE_ACCTYPES = 1; # 1=> Use access types to guide "swapping".

    ##############################################################################
    # Control USE_ACCTYPES from the shell.
    # To turn crazy_eye on remotely, set shell variable USE_CRAZY to 1
    if ($ENV{USE_CRAZY} == 1) { $USE_ACCTYPES = 0; } else  { $USE_ACCTYPES = 1; }

    if ($USE_ACCTYPES) {
        # Not using crazy eye algorithm
        # FIXME really should NEVER use the "old" routine regardless of USE_ACCTYPES
        return find_acctype_old( @_ );
    } else {
        # Using crazy eye algorithm instead
        return -1;
    }
}

sub check_for_well_formed_schedule {
    # Returns "1" if schedule is well-formed, otherwise returns "0"
    # Well-formed means we cycle through all *n* banks every *n/2* operations.
    # E.g. if there are four banks, this would be well formed:
    #   addresses(0,1,2,3, 4,5,6,7) => banks(3,2,1,0, 0,1,2,3)
    # And these would be ill formed:
    #   addresses(0,1,2,3, 4,5,6,7) => banks(0,1,0,1, 2,3,2,3)

    my $npoints = shift;
    my $nunits = shift;
    my $fft_info = shift;
    my $n_ops = shift;

    my $nbanks = 4*$nunits;
    my $DBG9 = 0;

    # Separately check each group of $nbanks consecutive operations.
    for (my $group_begin=0; $group_begin < $n_ops; $group_begin += $nbanks/2) {

        my %banks;
        my $msg = ""; # $msg prints on $DBG9 and/or if warning occurs.

        # Should cycle through all $nbanks banks exactly once for each group.
        for (my $fi = $group_begin; $fi < ($group_begin + $nbanks/2); $fi++) {
            
            my $b1 = @{$fft_info}[$fi]->{bank1};  # Or: $fft_info->[$fi]->{bank1}
            my $b2 = @{$fft_info}[$fi]->{bank2};
            my $op1 = @{$fft_info}[$fi]->{op1};
            my $op2 = @{$fft_info}[$fi]->{op2};

            $banks{$b1} = 1; # "1" is arbitrary; could use any non-null value.
            $banks{$b2} = 2; #  Could use any non-null value.

            my $banks_found = keys %banks; # How many banks did we find?

            #print "FOO $fi b1=$b1 b2=$b2 nbanks=$banks_found (";

            # Build a debug and/or warning message.
            my $bcount = $DBG9 ? '//bcount' : '//';
            $msg .= sprintf("  $bcount %2d (cy %2d) ", $fi, $fi/$nunits);
            $msg .= sprintf("Index (%2d,%2d) => banks (%2d,%2d)", $op1, $op2, $b1, $b2);
            $msg .= " nbanks=$banks_found (";
            my $comma = ''; foreach my $i (sort keys %banks) { $msg .= "$comma$i"; $comma = ','; }
            $msg .= ")\n";
        }
        if ($DBG9) { print "\n\n$msg"; }

        # Check to make sure we found exactly $nbanks unique bank numbers.
        my $banks_found = keys %banks; # How many banks did we find?
        if ($banks_found != $nbanks) {

            my $nabits  = log2($npoints);
            my $nbbits  = log2(4*$nunits);
            my $orphans = $nabits % $nbbits;
            printf("\nORPHAN nabits=$nabits nbbits=$nbbits orphans = $orphans WARNING\n");

            printf("\nWARNING Banks not well formed, cycles $group_begin to %d:\n",
                   ($group_begin + $nbanks/2)-1);
            print $msg;
        }
    }
}

# # This is the fix when first star appears at Index (op1=) 32
# # Change direction every four (op1=8) and sixteen (op1=32)
# #my $count_direction = ($ii4^$ii16 == 0) ? 'up' : 'down' ;
# 
# #  ii&4   ii&16   direction
# #   0       0        up
# #   1       0       down
# #   0       1       down
# #   1       1        up
# 
# # After 4 and 16 (above), next star(s) appear at Index 128
# # And 64 (op1=128)
# # my $count_direction = ($ii4^$ii16^$ii64 == 0) ? 'up' : 'down' ;
# 
# # Now there's one at op1=512
# # This (below) is sufficient to remove *all collisions* for the case n=1024 and b=1
# $count_direction = ($ii4^$ii16^$ii64^$ii256 == 0) ? 'up' : 'down' ;
# $mask = 3;  # Up or down by fours.

sub find_ag_alg {
    # Given a number of data points e.g. 16
    # and a list of collision sites e.g. {2,6,8,10,14}
    # return an appropriate munging algorithm e.g. ii2ii4ii8m1

    my $npoints = shift; # E.g. 16
    my @collsites = @_;  # E.g. (2,6,8,10,14)

    my $LDBG = 0;
    if ($LDBG) {
        printf("npoints = $npoints, collsites = (%s)\n", join(',', @collsites));
    }

    my $n_ops = $npoints/2;

    my $ncollsites = scalar(@collsites);

    # Algorithm will be encoded as follows: (npoints, mask, ii_bit0, ii_bit1, ii_bit2...)
    # E.g. ii2ii4ii8m1 is encoded as (32, 0x1, 2,4,8)
    my @alg=($npoints, 0, 0);

    if ($ncollsites == 0) { return @alg; }  # No collision sites; guess we're done.

    my $ii = $collsites[0];   # E.g. "2"
    my $mask = $ii - 1;       # E.g. "1" - mask is based on smallest (first) ii bit.

    # my @alg = ($npoints, $mask, $ii);       # Unnecessary optimization...
    # if ($ncollsites == 1) { return @alg; }  # Unnecessary optimization...

    # Okay, now things get tricky.  First, set up a bit vector.
    my @cs_bvec = ((0) x $n_ops);
    # printf("FOO cs_bvec = %s\n\n", join('', @cs_bvec));

    # Load up the bit vector with the coll site values
    foreach my $cs (@collsites) { $cs_bvec[$cs] = 1; }
    # printf("FOO cs_bvec = %s\n\n", join('', @cs_bvec));

    # Walk through and transform $cs_bvec until it is all zeroes.
    # FIXME PLEASE EXPLAIN WHY/HOW THIS WORKS...!!!  (also see comments above)

    # Foreach collision site s : bvec[s]==1,
    # add a toggle bit s and transform the bitvec such that
    # every location pvec[i*2**s] gets toggled 0->1 or 1->0
    # by the time you get halfway through the vector, all bits should be == 0
    # And @alg will contain a record of the necessary transforms that got us there.
    # How's that?

    my @alg = ($npoints, $mask);
    if ($LDBG) { print "\n"; }

    # Start at opnum 2, because 0 and 1 never collide w/prev (why?)
    for (my $cs = 2; $cs <= $n_ops/2; $cs *= 2) {
        if ($cs_bvec[$cs] == 1) {

            # $alg .= "ii".$cs;       # E.g. "ii2", "ii2ii4", "ii2ii4ii8"
            push @alg, $cs;
            # print join(',', @alg) . "\n\n";

            if ($LDBG) {
                my $alg = decode_alg(@alg);
                print "find_ag_alg() alg=$alg does this:\n";
                printf("find_ag_alg() cs_bvec1 = %s\n", join('', @cs_bvec));
            }
            for (my $tog = $cs; $tog < $n_ops; $tog += $cs) {
                $cs_bvec[$tog] = 1 - $cs_bvec[$tog];  # 1=>0 and 0=>1
            }
            if ($LDBG) {
                printf("find_ag_alg() cs_bvec2 = %s\n", join('', @cs_bvec));
                print "\n";
            }
        }
    }
    # $alg .= "m$mask";  # Used to code alg as a string instead of an array.
    return @alg;
}

sub decode_alg {
    # Algorithm is encoded as follows: (npoints, mask, ii_bit0, ii_bit1, ii_bit2...)
    # E.g. ii2ii4ii8m1 is encoded as (32, 0x1, 2,4,8)

    my $npoints = shift;
    my $mask    = shift;
    my @ii      = @_;

    my $alg;
    for (my $i=0; $i < scalar(@ii); $i++) { $alg .= sprintf("ii%03d.", $ii[$i]); }
    return $alg."m$mask";
}

sub test_ag_alg_finder {
    my @alg;

    @alg = find_ag_alg(8, ());
    print decode_alg(@alg)."\n\n";
    
    @alg = find_ag_alg(8, (2));
    print decode_alg(@alg)."\n\n";
    
    @alg = find_ag_alg(16, (4));
    print decode_alg(@alg)."\n\n";

    @alg = find_ag_alg(32, (2,6,8,10,14));
    print decode_alg(@alg)."\n\n";
}

sub gen_crazy_verilog {
    # Algorithm is encoded as follows: (npoints, mask, 2**ii_bit0,  2**ii_bit1,  2**ii_bit2...)
    # E.g. ii2ii4ii8m1 is encoded as (32, 0x1, 2,4,8)

    my $stage   = shift;  # Unused! (FIXME)
    my $npoints = shift;  # $alg[0] - passed in as part of @alg - (unused)
    my $mask    = shift;  # $alg[1] - passed in as part of @alg
    my @ii      = @_;     # Remainder of @alg

    # Based value of unswizzled NormalEye, build verilog to
    # set CrazyEye (ce) to either NormalEye or (NormalEye^$mask).
    # E.g. for mask=15, @ii=(16,64,256), want this verilog:
    # "ce = ((NormalEye[4]^NormalEye[6]^NormalEye[8]) == 0) ? NormalEye : (NormalEye^15);"

    # Early out: if mask==0 that means we don't do any crazy transforms.
    if ($mask == 0) { return "ce = NormalEye;"; }

    # Given e.g. array @ii=(16,64,256) the map() below builds array
    # @t=('NormalEye[4]', 'NormalEye[6]', 'NormalEye[8]')
    my @t = map( sprintf("NormalEye[%s]", log2($_)), @ii);

    # Given e.g. array @t=('NormalEye[4]', 'NormalEye[6]', 'NormalEye[8]')
    # this join produces $t='NormalEye[4]^NormalEye[6]^NormalEye[8]'
    my $t = join('^',@t);

    # Okay we're done!  Return the verilog as a string.
    my $rval = "ce = (($t) == 0) ? NormalEye : (NormalEye^$mask);";
    return $rval;
}
1;
##############################################################################
## Copyright Stephen Richardson and Stanford University.  All rights reserved.
##############################################################################
