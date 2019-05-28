#!/usr/bin/awk -f
BEGIN { DBG = 1 } # Whoever's last wins! Right?
BEGIN { DBG = 0 }

# HOW TO USE:
#   % ../bin/golden_test.csh 128 1 1port|& tee tmp.log.srsub$i | tail
#   % cp /tmp/test_128_1_1port.log test_128_1_1port.log$i
#   % fptest3.awk test_128_1_1port.log$i |& grep fptest | sort | uniq | less
#   fptest top_fft.BFLY0.sub_o2i.SUB (0.000000 - 0.000000) = 0.000000    true
#   fptest top_fft.BFLY0.sub_o2i.SUB (-0.049126 - -1.001206) = 0.952080    true
#   fptest top_fft.BFLY0.sub_o2i.SUB (-0.098491 - -1.004838) = 0.906347    true
#   fptest top_fft.BFLY0.sub_o2i.SUB (-0.148336 - -1.010942) = 0.862606    true
#   ...
# 
# Printed-out signals can fluctuate before achieving final value.
# This script finds and emits final answer as of each clock edge.
# 
# Sample input:
#   % less test_128_1_1port.log$i
#   ...
#   top_fft.BFLY0.sub_o2r.SUB a= 1.000000 (3f800000) b= 0.000000 (00000000) z= 1.000000 (3f800000)
#   top_fft.BFLY0.sub_o2r.SUB a= 1.000000 (3f800000) b= 0.000000 (00000000) z= 1.000000 (3f800000)
#   top_fft.BFLY0.sub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.000000 (Xxxxxxxx)
#   top_fft.BFLY0.sub_o2r.SUB a= 1.000000 (3f800000) b= 0.000000 (00000000) z= 1.000000 (3f800000)
#   top_fft.BFLY0.sub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.000000 (Xxxxxxxx)
#   top_fft.BFLY0.sub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.000000 (Xxxxxxxx)
#   top_fft.BFLY0.sub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.414214 (3ed413cc)
#   top_fft.BFLY0 t5 ------------------------
#   ...
# 
# Sample output:
#   % fptest3.awk test_128_1_1port.log$i |& less
#   ...
#   fptest o2i.FPU.SUB      (0.414214 - 1.082392)     =  -0.668179 true
#   fptest o2i.FPU..SUB    (-0.414214 - -1.082392)    =   0.668179 true
#   fptest o1i.FPU..ADD    (-0.414214 + -1.082392)    =  -1.496606 true
#   fptest o2r.FPU..SUB     (1.000000 - 0.000000)     =   1.000000 true
#   fptest o1r.FPU..ADD     (1.000000 + 0.000000)     =   1.000000 true
#   fptest t2.FPU..ADD     (-0.923880 + -0.158513)    =  -1.082392 true
#   fptest t1.FPU.ADD       (0.382683 + 0.382683)     =   0.765367 true
#   top_fft.BFLY0 t5 ------------------------
#   ...

##############################################################################
# Really?
function abs(v) {return v < 0 ? -v : v}

# Trigger final result when see "t5" printouts at 2 cy after clock edge:
# e.g. stdout = "top_fft.BFLY0 t5 ------------------------"
/top_fft.* t5/ {
  for (op in line_op) if (line_op[op] != "") {
    # printf("Looks like I have results for op '%s'\n", op)

    line=line_op[op]
    a=a_op[op]
    b=b_op[op]
    z=z_op[op]

    # For compare, remove spaces from front of z string
    zcmp = sprintf("%9s", z)

    # Generate comparison value; op comes from a line that might look like this:
    # top_fft.BFLY0.sub_o2r.SUB.ADD a= 1.000000 (3f800000) b= 1.000000 ...
         if (match(op, /ADD$/)) { r = sprintf("%9.6f", a + b); fn="+" }
    else if (match(op, /SUB$/)) { r = sprintf("%9.6f", a - b); fn="-" }
    else if (match(op, /MUL$/)) { r = sprintf("%9.6f", a * b); fn="*" }
    else { printf("fptest ERROR what is op '%s'?\n", op) }

    diff = abs(r - zcmp)
    should_be = sprintf("false (wanted %s, off by %.6f)", r, diff)
    good_enough = (diff <= 0.000003)
    # FIXME but is this really good enough? IT KEEPS CREEPING!!!
    # A question for fpu testing i guess...

    result = (r == zcmp) ? "true" : should_be
    result = good_enough ? "true" : should_be

    # op="top_fft.BFLY0.sub_t1.FPU.SUB" is TOO MUCH
    # This shortens it to e.g. "t1.FPU.SUB"
    short_op = op; gsub(/top_fft.*_/, "", short_op);
    printf("fptest %-12s %13s %s %-13s = %10s %s\n",
             short_op, "(" a, fn, b ")", z,   result);
    if (DBG) { printf("fptest    z_op['%s'] = %s\n", op, z_op[op]) }

    # Reset array
    line_op[op] = ""
  }
}

{ print }

# FIXME have to restore mul one of these days...!!!
/.*BFLY[0-9]*.(add|sub).*z=[ -0123456789]/ {

  # before & after gsub:
  # top_fft.BFLY0.sub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.414214 (3ed413cc)
  # top_fft.BFLY0.sub_o2i.SUB a= -1.000000 (bf800000) b= -1.414214 (bfb504f3) z=  0.414214 (3ed413cc)
  gsub(/=/, "= ", $0)

  # E.g. op="top_fft.BFLY0.sub_o2r.SUB"
  op = $1
  line_op[op] = $0
  found_op[op] = 1

  # E.g. a,b,z = "1.000000","-1.414214","0.414214"
  a_op[op] = $3; b_op[op] = $6; z_op[op] = $9;

  if (DBG) { printf("fptest z_op['%s'] = %s\n", op, z_op[op]) }
}
