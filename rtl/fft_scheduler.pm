package fft_scheduler;
use strict;

#push (@INC, "/home/steveri/fftgen/rtl/");
my $rtldir = mydir(".");  # Script lives in $FFTGEN/rtl;
push (@INC, "$rtldir/");  # scheduler lives in $FFTGEN/rtl
require swizzler;

my $DBG = 0;

##############################################################################
# To turn debugging on remotely, call fft_scheduler::DBG_ON();
# see bin/test_scheduler.pl
sub DBG_ON { $DBG = 1; }

##############################################################################
# Given:
#    $npoints     # length of FFT: must be a power of two
#    $nunits      # Number of butterfly units employed per cycle.
#    $reschedule  # (optional) Any non-zero value e.g. "reschedule" 
#    $TEST        # (optional) Return human-readable test and debug info.
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

##############################################################################
# To test the scheduler, use the extra "TEST" parm as called by e.g.
# test_fft_scheduler().  Also see bin/test_scheduler.pl.

##############################################################################
my @fft_info; # Persistent storage available as "@fft_scheduler::fft_info"
# To access e.g. @fft_info from e.g. fftram.vp, do this:
# //; require fft_scheduler;
# //; print "// fftram op1[0] is @fft_scheduler::fft_info[0]->{op1}\n";

sub test_fft_scheduler {
    $DBG = shift;

    my $npoints = 8; # Length of FFT: must be a power of two
    my $nunits  = 1; # How many butterfly units employed per cycle; must be a power of two.

    fft_schedule($npoints, $nunits, "reschedule", "TEST");
    fft_schedule($npoints,    2,    "reschedule", "TEST");
    fft_schedule(   16,       1,    "reschedule", "TEST");
    fft_schedule(   32,       4,    "reschedule", "TEST");
    fft_schedule(  1024,      1,    "reschedule", "TEST");
}

sub fft_schedule {
    my $npoints    = shift; # length of FFT: must be a power of two
    my $nunits     = shift; # Number of butterfly units employed per cycle.
    my $reschedule = shift; # "" or any non-zero value e.g. "reschedule_for_conflicts" 
    my $TEST = shift;

    # Generate the initial indices and schedule.
    @fft_info =
        fft_gen_indices($npoints, $nunits);

    # Reschedule for bypassing if requested.
    if ($reschedule) {
        @fft_info =
            reschedule($npoints, $nunits, @fft_info);
    }
    if ($TEST) {
        print "\n*** End of test. ***\n";
    }
    return @fft_info;
}

##############################################################################
# Rescrubbed to here 208pm 
##############################################################################

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

    if ($LDBG) {
        print "*********************************************************************\n";
        print "*** Initial call to fft_gen_indices() *******************************\n";
    }
    my $indent = ""; # Was: "my $indent = shift;"

    my $npoints = shift;   # length of FFT: must be a power of two.
    my $nunits = shift;    # Number of butterfly units employed per cycle.

    # Clear the global data structs.
    my @fft_info = ();
    my $fftno = 0;

    if ($LDBG) {
        my $howmany_butts = $nunits == 1 ? "one butterfly unit" : "$nunits butterfly units";
        print "\n";
        print $indent."/////////////////////////////////////////////////////////////////////\n";
        print $indent."// $npoints FFT data points; $howmany_butts.\n";
        print "\n";
    }
    for (my $i=0; $i < log2($npoints); $i++) {
        if ($LDBG) {
            print $indent;
            my $hline = "----------------------------";
            print "//$hline Stage $i $hline//\n\n";
        }

        my $n1 = 2**$i;  # $n1:  1  2  4  8 16 ... = 2**$i
        my $n2 = 2*$n1;  # $n2:  2  4  8 16 32 ... = 2*$n1

        my $e = -6.283185307179586 / $n2;
        my $a = 0.0;

        for (my $j = 0; $j < $n1; $j++) {
            my $c = cos($a);
            my $s = sin($a);
            $a = $a + $e;

            for (my $k = $j; $k < $npoints; $k = $k + $n2) {

                my ($op1, $op2) = ($k, $k + $n1);

                my ($b1, $r1) = swizzler::swizzle($op1, $npoints, 4*$nunits);
                my ($b2, $r2) = swizzler::swizzle($op2, $npoints, 4*$nunits);

                if ($LDBG) {
                    printf($indent."// %2d. ", $fftno);
                    printf("Index (%2d,%2d) => banks (%2d,%2d)", $op1, $op2, $b1, $b2);
                    printf(",  twid(c,s) = (%6.3f, %6.3f)", $c, $s);
                    print "\n";
                }

                # Choices for {access} (default is always "SRAM"):
                # ("SRAM", "op1 from buf", "op2 from buf", "op1 to buf", "op2 to buf")
                my $access = "SRAM";

                $fft_info[$fftno] = {};
                $fft_info[$fftno]->{stage} = $i;
                $fft_info[$fftno]->{op1} = $op1;
                $fft_info[$fftno]->{op2} = $op2;
                $fft_info[$fftno]->{bank1} = $b1;
                $fft_info[$fftno]->{bank2} = $b2;
                $fft_info[$fftno]->{ctwid} = $c;
                $fft_info[$fftno]->{stwid} = $s;

                # For $nunits==1 only, uses "access"
                $fft_info[$fftno]->{access} = $access;

                # For $nunits>1 only, uses op[12]_buffer and op[12]_buffer_access
                $fft_info[$fftno]->{op1_buffer} = -1;            # 0, 1, 2, or 3
                $fft_info[$fftno]->{op2_buffer} = -1;
                $fft_info[$fftno]->{op1_buffer_access} = "NONE"; # "RD", "WR", "NONE", or "BOTH"
                $fft_info[$fftno]->{op2_buffer_access} = "NONE"; # "RD", "WR", "NONE", or "BOTH"

                $fftno++;

                if ($LDBG) {
                    # Separator at the end of each stage.
                    if ((($k + $n2) >= $npoints) && (($j+1) >= $n1)) { print "\n"; }
                }
            }
        }
    }
    if ($LDBG) {
        print "\n";
        print "*** Result of initial call to fft_gen_indices(): ***\n\n";
        print_fft_info($nunits, @fft_info);
    }
    return @fft_info;
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
    my @grouping = fix_bank_conflicts($npoints, $nunits, \@fft_info, $LDBG);

    if ($LDBG) {
        print "\n\n*** and now schedule looks like this: ***\n\n";
        print_fft_info($nunits, @fft_info);
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

        # Grouping is either 0 ("odds/evens") or 1 ("hi/lo").  Or 4 ("1247/0356").
        my ($prevgrp,$thisgrp) = ($grouping[$stage-1], $grouping[$stage]);
        if ($LDBG) {
            my @gstring = ("odds/evens", "hi/lo", "2", "3", "1247/0356");
            printf("grouping: stage %d %-10s, ", $stage-1, $gstring[$prevgrp]);
            printf("stage %d %s\n",              $stage,   $gstring[$thisgrp]);
        }
        if ($prevgrp ne $thisgrp) {
            if ($LDBG) { printf("\nOD NOD must buffer things between stages %d/%d.", $stage-1, $stage); }
            fourbuffer($LDBG, \@fft_info, $npoints, $nunits, $stage-1, $prevgrp);
        }
    }
    if ($LDBG) {
        print "\n\n*** and now schedule looks like this: ***\n\n";
        print_fft_info($nunits, @fft_info);
    }
    my $dhline = "=====================================================================\n";
    if ($LDBG) {
        print "\n$dhline\n";
        print "\n*** FINAL SCHEDULE (below) ***\n\n";
        print_fft_info($nunits, @fft_info);
    }
    return (@fft_info);
}

sub log2 {
    my $N = shift @_;
    my $result = 1; while ( (2**$result) < $N ) { $result++; }
    return $result;
}

sub print_fft_info {
    my $nunits = shift @_;
    my @fft_info = @_;

    my $prev_stage = -1;
    for (my $i = 0; $i < @fft_info; $i++) {
        my $stage  = $fft_info[$i]->{stage};
        my $op1    = $fft_info[$i]->{op1};
        my $op2    = $fft_info[$i]->{op2};
        my $bank1  = $fft_info[$i]->{bank1};
        my $bank2  = $fft_info[$i]->{bank2};
        my $ctwid  = $fft_info[$i]->{ctwid};
        my $stwid  = $fft_info[$i]->{stwid};
        my $access = $fft_info[$i]->{access};
        
        # Print stage header.
        if ($prev_stage != $stage) {
            if ($stage != 0) { print "\n"; }
            my $hline = "----------------------------";
            print "//$hline Stage $stage $hline//\n\n";
            $prev_stage = $stage;
        }
        # Extra line after each cycle
        elsif (($nunits > 1) && ($i > 0) && (($i % $nunits) == 0)) { print "\n"; }

        printf("// %2d (cy %d). %d   ", $i, $i/$nunits, $nunits);
        printf("Index (%2d,%2d) => banks (%2d,%2d)", $op1, $op2, $bank1, $bank2);

        printf(",  twid(c,s) = (%6.3f, %6.3f)", $ctwid, $stwid);

        if ($nunits > 1) {
            # Use alternate buffer_access info

            my $buf1 =    $fft_info[$i]->{op1_buffer};        # -1, 0, 1, 2, or 3
            my $buf2 =    $fft_info[$i]->{op2_buffer};        # -1, 0, 1, 2, or 3
            my $access1 = $fft_info[$i]->{op1_buffer_access}; # "RD", "WR", "NONE", or "BOTH"
            my $access2 = $fft_info[$i]->{op2_buffer_access};

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

sub find_acctype {
    # 0=>odds, 1=>hi, 2=>evens, 3=>lo, -1=>ERROR
    # Adding: 4=>"1247", 5=>"0356"

    my $fi  = shift @_;
    my $nbanks = shift @_;
    my $fft_info = shift @_;

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

    return -1;
}

sub fourbuffer {
    my $LDBG     = shift @_;
    my $fft_info = shift @_;
    my $npoints  = shift @_;
    my $nunits   = shift @_;
    my $curstage = shift @_;
    my $curgtype = shift @_;

    my $nxtstage = $curstage+1;

    # "curstage" has grouptype "curgtype" (0="odd/even" or 1="hi/lo") and "curstage+1"
    # is the other type.  For each access in the final pack (quad or duo) of "curstage",
    # set buffer_access_op$i to "WR" and op$i_buffer to (0,1,2,3) respectively;
    # search forward to find next read of this op and 
    # set buffer_access_op$i to "RD" and op$i_buffer to (0,1,2,3) respectively.

    if ($LDBG) {
        print "\n";
        my $pack = ($nunits==4)? "quad" : "duo";
        printf("  Final $pack of stage %d is \"%s\" banks;\n", $curstage, $curgtype?"hi":"odds");
        printf("  first $pack of stage %d is \"%s\" banks;\n", $nxtstage, $curgtype?"evens":"lo");
        printf("  thus must redirect stage-%d banks that match \"%s\" of first $pack in stage %d.",
               $curstage, $curgtype?"hi's":"odds", $nxtstage);
        print "\n\n";
    }
    my $firstcy_nxtstage  = $nxtstage*$npoints/2;
    my $lastcy_nxtstage   = ($nxtstage+1)*$npoints/2 - 1;
   #my $lastpack_curstage = $firstcy_nxtstage - 4;
    my $lastpack_curstage = $firstcy_nxtstage - $nunits;

    my $bufnum = 0;
    for (my $fcur = $lastpack_curstage; $fcur < $firstcy_nxtstage; $fcur++) {
        my $curb1 = @{$fft_info}[$fcur]->{bank1};
        my $curb2 = @{$fft_info}[$fcur]->{bank2};

        my $cur_op1 = @{$fft_info}[$fcur]->{op1};
        my $cur_op2 = @{$fft_info}[$fcur]->{op2};

#         my $curbank = $curb1;
#         my $cur_op  = $cur_op1;

        # Search first pack of stage n+1 to see if bank conflict.
       #for (my $fnxt = $firstcy_nxtstage; $fnxt < ($firstcy_nxtstage + 4); $fnxt++) {
        for (my $fnxt = $firstcy_nxtstage; $fnxt < ($firstcy_nxtstage + $nunits); $fnxt++) {
            my $nxtb1 = @{$fft_info}[$fnxt]->{bank1};
            my $nxtb2 = @{$fft_info}[$fnxt]->{bank2};

            my $dbgmsg;
            # Look bank1 conflict.
            if ($dbgmsg = bypass_next_read(
#                    $curb1, $cur_op1, $nxtb1, $nxtb2, $firstcy_nxtstage, $lastcy_nxtstage, $fft_info, $bufnum
                    $curb1, $cur_op1, $fnxt, $firstcy_nxtstage, $lastcy_nxtstage, $fft_info, $bufnum
                )) {
               #if ($bufnum > 4) { print "\nERROR fft_scheduler.pm: too many bufs!\n"; }
                if ($bufnum > $nunits) { print "\nERROR fft_scheduler.pm: too many bufs!\n"; }
                if ($LDBG) { printf("$fcur: Bypass-write op1 to buffer $bufnum\n$dbgmsg\n"); }
                @{$fft_info}[$fcur]->{op1_buffer} = $bufnum;
                @{$fft_info}[$fcur]->{op1_buffer_access} = "WR";
                $bufnum++;

                # BUG/TODO/FIXME different bypass mechanism for nunits==1
                if ($nunits==1) { @{$fft_info}[$fcur]->{access} = "op1 to buffer"; }

            }
            # Look for bank2 conflict.
            if ($dbgmsg = bypass_next_read(
#                    $curb2, $cur_op2, $nxtb1, $nxtb2, $firstcy_nxtstage, $lastcy_nxtstage, $fft_info, $bufnum
                    $curb2, $cur_op2, $fnxt, $firstcy_nxtstage, $lastcy_nxtstage, $fft_info, $bufnum
                )) {
                if ($bufnum > $nunits) { print "\nERROR fft_scheduler.pm: too many bufs!\n"; }
                if ($LDBG) { printf("$fcur: Bypass-write op2 to buffer $bufnum\n$dbgmsg\n"); }
                @{$fft_info}[$fcur]->{op2_buffer} = $bufnum;
                @{$fft_info}[$fcur]->{op2_buffer_access} = "WR";
                $bufnum++;

                # BUG/TODO/FIXME different bypass mechanism for nunits==1
                if ($nunits==1) { @{$fft_info}[$fcur]->{access} = "op2 to buffer"; }

            }
        }
    }
}

# Find next usage of $cur_op; read it from bypass_buffer[$bufnum] instead of SRAM
sub bypass_next_read {
    my $curbank = shift;
    my $cur_op = shift;
#    my $nxtb1 = shift;
#    my $nxtb2 = shift;
    my $fnxt = shift;
    my $firstcy_nxtstage = shift;
    my $lastcy_nxtstage = shift;
    my $fft_info = shift @_;
    my $bufnum = shift;

    # Find next usage of $cur_op; read it from bypass_buffer[$bufnum] instead of SRAM

    my $nxtb1 = @{$fft_info}[$fnxt]->{bank1};
    my $nxtb2 = @{$fft_info}[$fnxt]->{bank2};

    my $dbgmsg = "";
    if (($curbank == $nxtb1) || ($curbank == $nxtb2)) {
        # Conflict! (error if bufnum >= 4)

        # 2. Search forward for next use of $bypassed; read from bufnum
        for (my $fi=$firstcy_nxtstage; $fi < $lastcy_nxtstage; $fi++) {
            my $op1 = @{$fft_info}[$fi]->{op1};
            my $op2 = @{$fft_info}[$fi]->{op2};

            if ($op1 == $cur_op) {
                $dbgmsg = "$fi: Bypass-read  op1 from buffer $bufnum\n";
                @{$fft_info}[$fi]->{op1_buffer} = $bufnum;
                if (@{$fft_info}[$fi]->{op1_buffer_access} eq "WR") {
                    print "\nERROR fft_scheduler.pm: not prepared to handle \"BOTH\"?\n";
                };
                @{$fft_info}[$fi]->{op1_buffer_access} = "RD";

                # BUG/TODO/FIXME different bypass mechanism for nunits==1
#                if ($nunits==1) { @{$fft_info}[$fi]->{access} = "op1 from buffer"; }
                @{$fft_info}[$fi]->{access} = "op1 from buffer"; # Used only for nunits==1

                last;
            }
            elsif ($op2 == $cur_op) {
                $dbgmsg = "$fi: Bypass-read  op2 from buffer $bufnum\n";
                @{$fft_info}[$fi]->{op2_buffer} = $bufnum;
                if (@{$fft_info}[$fi]->{op2_buffer_access} eq "WR") {
                    print "\nERROR fft_scheduler.pm: not prepared to handle \"BOTH\"?\n";
                };
                @{$fft_info}[$fi]->{op2_buffer_access} = "RD";

                # BUG/TODO/FIXME different bypass mechanism for nunits==1
#                if ($nunits==1) { @{$fft_info}[$fi]->{access} = "op2 from buffer"; }
                @{$fft_info}[$fi]->{access} = "op2 from buffer"; # Used only for nunits==1

                last;
            }
        }
    }
    return $dbgmsg;
}


sub fix_bank_conflicts {
    my $npoints  = shift;
    my $nunits   = shift;  # Should be four or two
    my $fft_info = shift;
    my $LDBG     = shift;

    # Classify the accesses of each stage ($firstcy to $firstcy+($npoints/2))
    # into one of the following groups: 0=>odds, 1=>hi, 2=>evens, 3=>lo, -1=>ERROR
    # Because of how the FFT works, all access of a given stage will either be
    # odds and evens (e.g. {(0,8),(2,10)...(1,9),(3,11)...})
    # or hi's and lo's (e.g. {(0,1),(2,3)...(12,13),(14,15)})
    #
    # On each cycle, access either e.g. all odds or all evens; this guarantees
    # no bank conflicts for the duration of the stage.
    #
    # Bank conflicts then only occur when e.g. stage n ends in evens and stage (n+1)
    # begins with lo's.

    # E.g. grouping[0] = grouping strategy for stage 0 ("odd/even" or "hi/lo")
    my @grouping;

    my $nstages = log2($npoints);                   # E.g. 16points => 4
    for (my $stage=0; $stage<$nstages; $stage++) {  # E.g. (0, 1, 2, 3)

        my $firstcy = $stage*$npoints/2;            # E.g. (0, 8,16,24)
        my $lastcy  = $firstcy + $npoints/2 - 1;    # E.g. (7,15,23,31)

        for (my $fi = $firstcy; $fi < ($firstcy + $npoints/2); $fi++) {

            my $op1    = @{$fft_info}[$fi]->{op1};
            my $op2    = @{$fft_info}[$fi]->{op2};
            my $bank1  = @{$fft_info}[$fi]->{bank1};
            my $bank2  = @{$fft_info}[$fi]->{bank2};

            # grouping type of $fi access: 0=>odds, 1=>hi, 2=>evens, 3=>lo, -1=>ERROR
            # Also: 4=>"1247", 5=>"0356"
            my $acctype = find_acctype($fi, $nunits*4, $fft_info);
            if ($acctype == -1) { print "\nERROR! fft_scheduler.pm bad acctype\n"; }

            # Record the grouping type; should be same throughout the stage.
            # Final assignment will be either 0 ("odds") or 1 ("hi").  Or 4 ("1247").
            $grouping[$stage] = $acctype;   # 0 ("odds") or 1 ("hi").  Or 4 ("1247").

            # Count by packs.  For nunits==4 a pack is a quad; for units==2 it's a duo.
            # alternate even_group/odd_group; swap if wrong; complain if error.
            # Remember: 0=>odds, 1=>hi, 2=>evens, 3=>lo, -1=>ERROR

            # "packgroup" will be either 0 for "lo/evens/0356" or 1 for "hi/odds/1247"
            my $packno    = int($fi/$nunits); # (0,0,0,0)(1,1,1,1)(2,2,2,2)(3,3,3,3)...
            my $packgroup = $packno%2;        # (0,0,0,0)(1,1,1,1)(0,0,0,0)(1,1,1,1)...

            # Alternate odd/hi/1247 with even/lo/0356.
            # Remember: 0=>odds, 1=>hi, 2=>evens, 3=>lo, -1=>ERROR
            # Also, now: 4=>"1247", 5=>"0356"
            my ($even_or_lo_or_0356, $odd_or_hi_or_1247) = (0, 1);
            my $packtype = ($acctype < 2) ? $odd_or_hi_or_1247 : $even_or_lo_or_0356;
            if ($acctype == 4) { $packtype = $odd_or_hi_or_1247; }
            if ($acctype == 5) { $packtype = $even_or_lo_or_0356; }

            if ($LDBG) {
                my @accstr = ("odds", "hi", "evens", "lo", "1247", "0356");
                my @packstr = ("odd/hi/1247",  "even/lo/0356");
                printf("Stage $stage cy %d fft_info[%2d] ix (%2d,%2d) => banks (%2d,%2d)",
                       $fi/$nunits, $fi, $op1, $op2, $bank1, $bank2);
                printf(" => atype %d (%s), qgrp %d (%s) qtyp %d\n",
                       $acctype, $accstr[$acctype],                    # atype
                      #$packgroup, $packgroup ? "odd/hi" : "even/lo",  # qgrp
                       $packgroup, $packstr[$packgroup],               # qgrp
                       $packtype);                                     # qtyp
            }

            # if whichpack(acctype) doesn't match packgroup, swap with next eligible entry
            if ($packgroup != $packtype) {
                if ($LDBG) { printf("\noops fft_info[%2d] qgrp != qtyp;", $fi); }
                if ($LDBG) { print " search forward for someone to swap\n"; }
                # Search forward IN THIS STAGE for entry with eligible packtype.
                my $success = 0;
                for (my $fn = ($fi+1); $fn <= $lastcy; $fn++) {
                    if ($LDBG) { print "   [$fn]...?"; }

                    my $fn_atype = find_acctype($fn, $nunits*4, $fft_info);

                    # So stupid (below), shoudla used enums I guess...
                    # 1 for "odds/hi/1247" or 0 for "evens/lo/0356"
                    my ($even_or_lo_or_0356, $odd_or_hi_or_1247) = (0, 1);
                    my $fn_qtype = ($fn_atype < 2) ? $odd_or_hi_or_1247 : $even_or_lo_or_0356;
                    if ($fn_atype == 4) { $fn_qtype = $odd_or_hi_or_1247; }
                    if ($fn_atype == 5) { $fn_qtype = $even_or_lo_or_0356; }

                    if ($fn_qtype == $packgroup) {
                        if ($LDBG) { print " Hey, [$fn] looks good.  Swap!\n"; }
                        @{$fft_info} = swap_entries($fi, $fn, @{$fft_info});
                        if ($LDBG) {
                            #my @accstr = ("odds", "hi", "evens", "lo");
                            my @accstr = ("odds", "hi", "evens", "lo", "1247", "0356");
                            my @packstr = ("odd/hi/1247",  "even/lo/0356");

                            my $op1    = @{$fft_info}[$fi]->{op1};
                            my $op2    = @{$fft_info}[$fi]->{op2};
                            my $bank1  = @{$fft_info}[$fi]->{bank1};
                            my $bank2  = @{$fft_info}[$fi]->{bank2};
                            print "\n";
                            printf("Stage $stage cy %d fft_info[%2d] ix (%2d,%2d) => banks (%2d,%2d)",
                                   $fi/$nunits, $fi, $op1, $op2, $bank1, $bank2);
                            printf(" => atype %d (%s), qgrp %d (%s) qtyp %d\n",
                                   $fn_atype, $accstr[$fn_atype],
                                  #$packgroup, $packgroup ? "odd/hi" : "even/lo", $packgroup);
                                   $packgroup, $packstr[$packgroup],               # qgrp
                                   $packtype);                                     # qtyp
                            print "\n";
                        }
                        $success = 1;
                        last;
                    }
                    else {
                        if ($LDBG) { print " nope.\n"; }
                    }
                }
                if ($success == 0) { print "\nERROR fft_scheduler.pm no findee swapee.\n"; }
                if ($LDBG) { print "\n"; }
            }
        } # for (my $fi = $firstcy; $fi < ($firstcy + $npoints/2); $fi++) {
        if ($LDBG) { print "\n"; }
    } # for (my $stage=0; $stage<$nstages; $stage++) {  # E.g. (0, 1, 2, 3)
    return @grouping;
}

sub swap_entries {
    # Swap "this" (fi) with "next" (fn) in array @fft_info.
    my $fi = shift @_;
    my $fn = shift @_;
    my @fft_info = @_;

    # Do the swap.
    my $tmp        = $fft_info[$fi];
    $fft_info[$fi] = $fft_info[$fn];
    $fft_info[$fn] = $tmp;
    
    # Return array with swapped entries.
    return @fft_info;
}

sub decode_conflict {
    my $conflict = shift;
    my $fh_prev  = shift;
    my $LDBG     = shift;
    my $inbuffer = -1;

    # "$conflict" contains coded information about which ops are in conflict.
    # 0 means "no conflict"; otherwise, "$conflict" is coded as follows:
    #    $conflict==0101 => prev_op1 conflicts with this_op1
    #    $conflict==0110 => prev_op1 conflicts with this_op2
    #    $conflict==1001 => prev_op2 conflicts with this_op1
    #    $conflict==1010 => prev_op2 conflicts with this_op2

    my $prev_op = $conflict >>  2;  # 1 => "op1", 2 => "op2"
    my $this_op = $conflict & 0x3;  # 1 => "op1", 2 => "op2"

    if ($conflict) {
        if ($fh_prev->{access} ne "SRAM") {
            printf "\n\nERROR fftram_scheduler need to read and write buffer at same time.\n\n";
            # Are you thanking me yet?  Because now this doesn't happen for npoints > 8.
        }
        
        $fh_prev->{access} = sprintf("op%d to buffer", $prev_op);
        $inbuffer = ($prev_op == 1) ? $fh_prev->{op1} : $fh_prev->{op2};
        if ($LDBG) {
            printf(" *** Prev op%d conflicts with cur op%d: ix%d to buffer.",
                   $prev_op, $this_op, $inbuffer);
        }
    }
    return $inbuffer;
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

1;
