#!/usr/bin/python
import os
import sys
import math
from pprint import pprint

# Turn on ALL_LDBG for extensive debug info
ALL_LDBG = int(os.getenv("ALL_LDBG", 0))

# For comparison to perl version
if ALL_LDBG: print("PYTHON")

# E.g. extensive comparison w/ perl version
#    function fgm {
#      fft_golden_model.pl 8 1 > tmp.pl
#      fft_golden_model.py 8 1 > tmp.py
#      diff tmp.pl tmp.py
#    }
#    export ALL_LDBG=1
#    ( c; set -x; fgm )

# Not used (yet) because only ported 'round7' to python
# my $rtldir = mydir(".");  # This script lives in $FFTGEN/rtl;
# push (@INC, "$rtldir/");  # swizzler lives in $FFTGEN/rtl
# require swizzler;

# Originally, valid settings were 'round7' (new/best), 'mod_bn_combo'
# (old) and maybe 'takala'. But now I think they are all deprecated
# except for 'round7'

# Default to round7 if SCHED_ALG not exists
SCHED_ALG = os.getenv("SCHED_ALG", "round7")
assert SCHED_ALG == "round7",\
    f"\nERROR Found env var SCHED_ALG='{os.environ['SCHED_ALG']}'"+\
    "; don't know how to do that (yet)."

print(f"// Scheduling algorithm='{SCHED_ALG}'", end='')

# Note I think crazy-eye was specific to the deprecated algorithm
# "mod_bn_combo" and is NO LONGER USED

# To turn crazy_eye on remotely, set shell variable USE_CRAZY to 1
# Looks like...crazy eye gets ignored when alg is round7?
USE_CRAZY = int(os.getenv("USE_CRAZY", 0))
if       SCHED_ALG == 'round7': print("\n")
else:
    if  USE_CRAZY == 1: print(", using the crazy eye.\n")
    else:               print(", NOT using the crazy eye.\n")

##############################################################################
# NEW (ROUND7) STUFF:
#    build_base_schedule(), build_extended_schedule()
#    parity_map(), parity_mod(), get_twiddles()
#    debug subs show_i(), show_d(), show_bits() (TODO)

def build_base_schedule(D, G, DBG=0):
    '''
    ########################################################################
    # Given a group size G and desired number of datapoints D, build a basic
    # conflict-free schedule $datapoints{s,i}
    '''

    # Caclulate number of stages S and toggle bits T
    S = int( math.log2(D) )
    T = int( math.log2(G) ) 

    # Debugging
    if ALL_LDBG:
        print("Will build normal  stages", 0,     "to", S-T)
        print("Will build overlap stages", S-T+1, "to", S-1)
        print("")

    datapoints = {}

    # Normal stages 0 through S-T
    for s in range(0, (S-T)+1):
        if DBG: print("Building normal stage {s}")

        for i in range(0, D):
            if DBG: show_i(i, D, S)
            datapoints[f"{s},{i}"] = lrot(i, S, s);
            if DBG: print(datapoints)

            if DBG: show_d("%s => ", datapoints[f"{s},{i}"], D, G)
            if DBG:
                if (i>0 and (i%G == (G-1))): print('') # group separator

    # Overlap stages S-T through D
    LLDBG=0
    for s in range((S-T)+1, S):

        if DBG: print("Building overlap stage s={s}")
        for ilow in range(0, int(D/G)):
            for t in range(0,G):
            
                i = (ilow << T) + t;      # Counts from 0 to D-1
                if DBG: show_i(i,D,S)

                shift_amt = (s-(S-T)); #DBG
                if LLDBG: print(f"\n\nrotate {T}-bit t={t} left by {shift_amt} places")

                t_rot = lrot(t, T, s-(S-T))
                if LLDBG: print("( t_rot <<", (S-T), f") | {ilow} = {t_rot}")

                iprime = (t_rot<<(S-T)) | ilow
                if LLDBG: print(f"iprime={iprime}")

                s_i=f"{s},{i}"
                datapoints[s_i] = (t_rot<<(S-T)) | ilow
                
                if LLDBG: print(f"datapoints['{s},{i}'] = ", datapoints[s_i])
                if DBG: show_d("%s => ", datapoints[s_i], D, G)
                
            if DBG: print('') # group separator

    if DBG: print('')

    # For comparison to perl version
    if ALL_LDBG: 
        print(f"build_base_schedule({D},{G})=")
        pprint(datapoints); print("")

    return datapoints

def build_extended_schedule(D, G, datapoints, DBG=0):

    ########################################################################
    # Given a group size G, and number of datapoints D, and a conflict-free
    # datapoint sequence %datapoints{s,i} for an FFT w/o pipeline overlap,
    # produce a CFS for FFT w/pipeline overlap

    (S,T) = (int(math.log2(D)), int(math.log2(G)))

    deltapoints = {}

    DBG = DBG | ALL_LDBG

    # Forward stages
    for s in range(0, (S-T)+1):
        if DBG: print(f"Transform normal stage {s}")
        for i in range(0,D):

            s_i = f"{s},{i}"
            d = datapoints[s_i]
            if DBG: show_d("  %s => ", d, D)

            for t in range( T-1, -1, -1):
                # Replace bit d(s+t) w/ P(s+t)
                bitpos =  (s+t)
                P = parity_mod(d, T, bitpos);
                
                d = replace_bit(d, bitpos, P);
                if DBG: print(f"P[{bitpos}]={P} ", end='')

            if DBG: show_d("=> %s", d, D); print('')
            deltapoints[s_i] = d

        if DBG: print('')

    # Reverse stages
    for s in range((S-T)+1, S):

        if DBG: print(f"Transform overlap stage {s}")
        for i in range(0,D):

            s_i = f"{s},{i}"

            d = datapoints[s_i]
            if DBG: show_d("  %s => ", d, D)
    
            for t in range(0,T):

                # Replace bit d(bitpos) w/ P(bitpos)
                bitpos = (S-1)-t
                P = parity_mod(d, T, bitpos);
                d = replace_bit(d, bitpos, P);
                if DBG: print(f"P[{bitpos}]={P} ", end='')

            if DBG: show_d("=> %s", d, D); print("")
            deltapoints[s_i] = d

        if DBG: print("")

    return deltapoints

# Given group size G, calculate mem bank m that corresponds to datapoint d
def parity_map(d, G, DBG=0):

    T = int(math.log2(G)) # Number of toggle bits

    # Calculate m= P(0) + 2P(1) + 4P(2) + ... + 2^(T-1)*P(T-1)
    (m, P) = (0, [0] * T)

    t = T - 1
    while t >= 0:
        P[t] = parity_mod(d, T, t)
        if DBG: print(f"P[t]={P[t]} ", end='')
        m = 2*m + P[t];
        t = t - 1

    if DBG: print(f"   m={m}")
    return m

# Take parity of every nth bit in operand op,
# starting w/bit (b mod n), where LSB is bit number 0.
def parity_mod(op,n,b, DBG=0):
    # E.g. if $op=118 (1101 1110) and n=3 and b=1
    # Then parity_mod returns XOR of bits 1,4,7 = xor(1,1,1) = 1

    #  op => Operand e.g. 1101 1110
    #  n  => XOR together every nth bit of operand, e.g. $n=3
    #  b  => Start with bit $b, e.g. $b=1

    b = int(b % n)

    # Shift the word such that desired starting bit is LSB
    tmp = op >> b

    # XOR every nth bit and return the answer.
    parity = 0
    while (tmp):
        parity = parity ^ (tmp & 0x1)
        tmp = (tmp >> n)

    if DBG: bits = show_bits(op,4)
    if DBG: print(f"parmod {op} = {bits} ; even_parity({op},{n},{b}) = {parity}\n")
    return parity

# Get the twiddle factor associated w/operand $op in stage $s of $S stages.
def get_twiddles(op, s, S, warn, DBG=1):
    # Want op = sequential opnum (0,1,2...D-1) not index (0,4,1,5...) or whatever


    # Op must be (I think) the smallest of the pair ($op, $op + 2^$s)
    zbit = 2 ** s
    if (op & zbit):
        if (warn != "nowarn"): print("WARNING: opnum should be smallest of the pair") # I think this is not used!!!
        op = op & ~zbit;

    i = rrot(op, S, s+1);

    s2 = (S-1) - s                  # s2:  1  2  3  4  5 ...   10
    n2 = 2 ** (s+1)                 # n2:  2  4  8 16 32 ... 1024
    k  = i >> s2
    e  = -6.283185307179586         # e = -2pi, dunno why really
    e  = -2.0 * math.pi             # Flaunt it I suppose
    cos = math.cos(0.0 + k * e/n2)  # Somehow the "0.0" prevents "-0" answers...!?
    sin = math.sin(0.0 + k * e/n2)
    #printf("TWID op=%2d,     s=$s and S=$S =>     cos is %6.3f\n", $op, $cos) 
    return (cos,sin)

########################################################################
# For debugging only, and only with sched alg 'round7'

def show_i(i, D, S):
    istring = ("%2d" % i) if (D>10) else i
    ibits = show_bits(i,S); print(f"    i={istring}({ibits}) => ", end='')

def show_d(fmt, d, D, G=0):
    # E.g. fmt = "%s => "

    S = math.log2(D)

    dstring = ("%2d" % d) if (D>10) else d
    dbits = show_bits(d,S); print( fmt % f"d={dstring}({dbits})", end='')

    # If $G was specified, print the map why not.
    if (G > 0): parity_map(d, G)
    # print('')

def show_bits(n, w, DBG=0):
    '''
    Turn decimal n into a length-w array of its composite bits.
    E.g. show_bits(7,8) = "00000111"
    '''
    # Turn n into its equivalent binary representation
    bits = bin(n).replace('0b','')
    
    # 0-extend to length w
    while (len(bits) < w): bits = '0' + bits
    
    if DBG: print(f"\n{n} = '{bits}' maybe")
    
    return(bits)


##############################################################################
# Simple helper functions --- all but log2() are used only by 'round7'
#
# log2(n) => E.g. log2(1024) returns "10"
#
# sub reverse_bits(i,nbits)
#    # Reverse the bits in the n-bit intege i
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

# def log2() => use math.log2
# def reverse_bits => use python built-in functions
# def blow2bits    => use python built-in functions

# Right-rotate
def rrot(n, size, shift_amt, DBG=0):
    "Example: rrot(7,4,1) = 11  ('0111' => '1011')"

    #     n         = shift;  # Integer to be rotated e.g. 7 ('00111')
    #     size      = shift;  # Size of integer e.g. 5 (bits)
    #     shift_amt = shift;  # Rotate right this many places\ e.g. 1.

    LLDBG = 0
    if LLDBG:
        n_string = show_bits(n, size)
        print(f"\nRotate '{n_string}' right by '{shift_amt}' places.")
        
    for i in range(0, shift_amt):
        lsb = n%2;
        if LLDBG: print(f"lsb is {lsb}")
        msb = lsb * 2**(size-1); # New msb is old lsb.
        n = (n >> 1) + msb;
        if LLDBG:
            n_string = show_bits(n, size);
            print(f"msb is {msb}; new n is '{n_string}'")
            
    if LLDBG:
        def int2bin(n, size): return show_bits(n, size)
        n_string = int2bin(n, size);
        print(f"Result is '{n_string}\n")
        
    return n

# Left-rotate
def lrot(n, size, shift_amt):
    #     n         =   # Integer to be rotated e.g. 7 ('00111')
    #     size      =   # Size of integer e.g. 5 (bits)
    #     shift_amt =   # Rotate right this many places\ e.g. 1.

    # lrot by s bits is same as rrot by nbits-s
    n = rrot(n, size, size-shift_amt)
    return(n)

def replace_bit(n,i,b, DBG=0):
    # In the given number $n, replace bit $i with new bit $b

    oldbit = n & (1<<i);
    newbit =     (b<<i);

    newnum = n ^ oldbit ^ newbit;

    if DBG:
        oldbits = show_bits(n,8)
        newbits = show_bits(newnum,8)
        print(f"rb {n} = {oldbits}; replace bit {i} with {b} => {newbits} = {newnum}")

    return newnum;

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

##############################################################################
# To test the scheduler, use sub test_fft_scheduler().
# Also see bin/test_scheduler.pl.
# (See perl versions maybe, don't think these are translated yet.)

# For now, "round7 is the only option here
def fft_schedule(npoints, nunits, reschedule, DBG=0):
    return fft_schedule_round7(npoints, nunits, "", "")

#     if ($SCHED_ALG eq 'round7') {
#         return fft_schedule_round7($npoints, $nunits, $reschedule); }
#     else {
#         return fft_schedule_modbncombo($npoints, $nunits, $reschedule); }

def fft_schedule_round7(npoints, nunits, reschedule, DBG=0):
    # $npoints    # length of FFT: must be a power of two
    # $nunits     # Number of butterfly units employed per cycle.
    # $reschedule # "" or any non-zero value e.g. "reschedule_for_conflicts" 

    D = npoints
    G = 4 * nunits
    S = int(math.log2(D))

    # This fixes a bug when e.g. G=8 and D=4 e.g. nbutts=4 and npoints=8 and pipedepth=2 (8 4 2port)
    if (G > D): G = D

    datapoints  = build_base_schedule(D,G, DBG=0)
    deltapoints = build_extended_schedule(D,G,datapoints)
    schedule = deltapoints     # Somewhat unnecessary dontcha think.

    # Debugging vs. perl version e.g.
    if ALL_LDBG:
        print("extended_schedule=")
        pprint(schedule); print("")

    fftno = 0;     # cycle number I guess, but not really maybe
    fft_info = []

    print(f"// swizzler algorithm 'round7'") # Because why not.
    for s in range(0,S):
        for i in range(0,D,2):
            (i0,i1) = (i+0, i+1)

            # op1, op2
            op1 = schedule[f"{s},{i0}"]
            op2 = schedule[f"{s},{i1}"]

            # b1, b2 OLD
            # my ($npoints,$nunits) = ($D, $G/4);
            # my ($b1, $r1) = swizzler::swizzle($op1, $npoints, 4*$nunits, 'round7'); # 'round7' should be same as 'mod_bn_combo' I think.
            # my ($b2, $r2) = swizzler::swizzle($op2, $npoints, 4*$nunits, 'round7');

            # b1, b2 NEW
            b1 = parity_map(op1, G)
            b2 = parity_map(op2, G)

            (cos,sin) = get_twiddles(op1, s, S, "nowarn")
            # print "fftno=len(fft_info) s=$s op1,op2=$op1,$op2 cos,sin=$cos,$sin\n";

            if (op1 > op2): t=op1; op1=op2; op2=t  # Hmmm....

            # I like this so much I'm making it permanent.
            # LDBG=1; if ($LDBG) {
            indent = ""
            print( (indent+"// %2d. ") % fftno, end='' )
            print("Index (%2d,%2d) => banks (%2d,%2d)" % (op1, op2, b1, b2), end='')
            print(",  twid(c,s) = (%6.3f, %6.3f)" % (cos, sin))

            assert fftno == len(fft_info)
            fft_info = fft_info + init_fft_info(fftno,   s,   op1, op2,   b1,b2,   cos,sin);

            fftno = fftno + 1
            assert fftno == len(fft_info)

            LLDBG=0
            if LLDBG: pprint(fft_info)

    # Okay, now add conflict/bypass buffer information.
    (nstages,npoints,nunits) = (S,D,G/4)
    for stage in range (1,nstages):  # E.g. (0, 1, 2, 3)
        add_bypass_info(fft_info, npoints, nunits, stage-1);

    return fft_info


def init_fft_info(fftno, stage,  op1, op2,   bank1, bank2,    ctwid,stwid):

    fft_info_local = {}
    fft_info_local["stage"] = stage
    fft_info_local["op1"]   = op1
    fft_info_local["op2"]   = op2
    fft_info_local["bank1"] = bank1
    fft_info_local["bank2"] = bank2
    fft_info_local["ctwid"] = ctwid
    fft_info_local["stwid"] = stwid

    # For $nunits==1 only, uses "access"
    # Choices for {access} (default is always "SRAM"):
    # ("SRAM", "op1 from buf", "op2 from buf", "op1 to buf", "op2 to buf")
    fft_info_local["access"] = "SRAM"

    # For $nunits>1 only, uses op[12]_buffer and op[12]_buffer_access
    fft_info_local["op1_buffer"] = -1;            # 0, 1, 2, or 3
    fft_info_local["op2_buffer"] = -1;
    fft_info_local["op1_buffer_access"] = "NONE"; # "RD", "WR", "NONE", or "BOTH"
    fft_info_local["op2_buffer_access"] = "NONE"; # "RD", "WR", "NONE", or "BOTH"

    # Return dict inside a list for conatenation to upper-level fft_info[]
    return [fft_info_local]

# Not translated (yet), see fft_scheduler.pm
# def print_fft_info
# def print_fft_info_round7

###############################################################################
# add_bypass_info() calculates and adds bypass info to @fft_info
#
# To call it:
#     for stage in range (1,nstages):  # E.g. (0, 1, 2, 3)
#         add_bypass_info(fft_info, npoints, nunits, stage-1);
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

def add_bypass_info(fft_info, npoints, nunits, curstage):

    # FIXME see calling context; (curstage, nxtstage) should be relabeled (prev_stage, this_stage)
    nxtstage = curstage+1;

    firstcy_nxtstage  = int((curstage+1) * npoints/2)
    lastcy_nxtstage   = int((curstage+2) * npoints/2 - 1)
    lastpack_curstage = int(firstcy_nxtstage - nunits)

    odnod  = 1 # First conflict (only) should trigger an OD NOD message.
    bufnum = 0

    LDBG = ALL_LDBG;

    # See if there's a bank conflict between last group in current stage and first group of next stage.

    # for (fcur = lastpack_curstage; fcur < firstcy_nxtstage; fcur++) {
    for fcur in range(lastpack_curstage, firstcy_nxtstage):
        found_conflict = 0;
        for fnxt in range(firstcy_nxtstage, int(firstcy_nxtstage + nunits)):

            # Look for bank1, bank2 conflicts each in turn.
            for which_op in ['op1', 'op2']:

                if LDBG: print(f"Comparing cycles {fcur} and {fnxt}")

                # if which_op's write bank conflicts with next cycle's read bank, must bypass
                cur_op = find_conflict(fft_info, fcur, which_op, fnxt)
                if (cur_op == ""): continue  # No conflicts found.

                # Conflict! cur_op is index of conflicting op, in {0..npoints-1}.
                # (Error if bufnum >= 4)
                found_conflict = 1
                if LDBG:
                    # NOTE odnod message only invoked once per stage pair comparison
                    odnodmsg = f"\nOD NOD must buffer things between stages {curstage}/{nxtstage}."
                    if odnod: print(odnodmsg)
                    if odnod: odnod = 0       # Only print once per stage pai

                # In cycle $fcur, write $which_op to buffer $bufnum instead of SRAM
                if LDBG: print(f"  {fcur}: Bypass-write {which_op} to buffer {bufnum}")
                bypass_write(fft_info, fcur, bufnum, which_op)

                # Search fft_info from firstcy to lastcy, find next usage of $cur_op;
                #read it from bufnum instead of memory.
                bypass_next_read(
                    fft_info, firstcy_nxtstage, lastcy_nxtstage,
                    cur_op, bufnum, LDBG);

                # FIXME should be an assert here
                if (bufnum > nunits): print("\nERROR fft_scheduler.pm: too many bufs!")
                bufnum = bufnum + 1

                # BUG/TODO/FIXME different bypass mechanism for nunits==1
                # BUG/TODO/FIXME is it used?
                if (nunits==1): fft_info[fcur]["access"] = f"{which_op} to buffer"

        assert (found_conflict != 0),\
            "\nERROR no bank conflict between stages?"

def find_conflict(fft_info, fcur, which_op, fnxt):

    (cur_op1, cur_op2, curb1, curb2) = get_ops_and_banks(fft_info, fcur)
    cur_op  = cur_op1 if (which_op == 'op1') else cur_op2
    curbank = curb1   if (which_op == 'op1') else curb2

    fnxt = int(fnxt)
    nxtb1 = fft_info[fnxt]["bank1"]
    nxtb2 = fft_info[fnxt]["bank2"]

    LDBG=ALL_LDBG
    if LDBG: print(f"  bnr(): cy{fcur}.{which_op}=b{curbank}; cy{fnxt}.op1=b{nxtb1} and cy{fnxt}.op1=b{nxtb2}")

    if ((curbank == nxtb1) or (curbank == nxtb2)): return cur_op
    else: return ""


    
def bypass_next_read (
    fft_info, firstcy_nxtstage, lastcy_nxtstage, cur_op, bufnum, LDBG):
    'Find next usage of $cur_op; read it from bypass_buffer[$bufnum] instead of SRAM'

    for fi in range(firstcy_nxtstage, (lastcy_nxtstage+1)):
  # for fi in range(firstcy_nxtstage, (lastcy_nxtstage)):  # Substitute this to break subtly.

        if cur_op == fft_info[fi]["op1"]:

            # In cycle $fi, read op1 from $bufnum instead of SRAM
            bypass_read( fft_info, fi,   bufnum, "op1")
            if LDBG: print(f"  {fi}: Bypass-read  op1 from buffer {bufnum}\n")
            return

        if cur_op == fft_info[fi]["op2"]:

            # In cycle $fi, read op2 from $bufnum instead of SRAM
            bypass_read( fft_info, fi,   bufnum, "op2");
            if LDBG: print(f"  {fi}: Bypass-read  op2 from buffer {bufnum}\n")
            return

def bypass_read(fft_info, readcy, bufnum, op):

    #my $dbgmsg = "  $readcy: Bypass-read  $op from buffer $bufnum\n";
    fft_info[readcy][f"{op}_buffer"] = bufnum

    assert fft_info[readcy][f"{op}_buffer_access"] != "WR",\
        print('\nERROR fft_scheduler.pm: not prepared to handle "BOTH"?')

    fft_info[readcy][f"{op}_buffer_access"] = "RD"
    fft_info[readcy]["access"] = f"{op} from buffer";


def bypass_write(fft_info, fcur, bufnum, op):   # (where op = 'op1' or 'op2')

    fft_info[fcur][f"{op}_buffer"]        = bufnum
    fft_info[fcur][f"{op}_buffer_access"] = "WR"

def get_ops_and_banks(fft_info, fi):
    op1    = fft_info[fi]["op1"]
    op2    = fft_info[fi]["op2"]
    bank1  = fft_info[fi]["bank1"]
    bank2  = fft_info[fi]["bank2"]

    return (op1, op2, bank1, bank2);

