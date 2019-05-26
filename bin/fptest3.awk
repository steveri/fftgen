#!/usr/bin/awk -f
BEGIN { DBG = 0 }

# HOW TO USE:
#   % ../bin/golden_test.csh 128 1 1port|& tee tmp.log.srsub$i | tail
#   % cp /tmp/test_128_1_1port.log test_128_1_1port.log$i
#   % fptest3.awk test_128_1_1port.log$i |& grep fptest | sort | uniq | less
#   fptest top_fft.BFLY0.spsub_o2i.SUB (0.000000 - 0.000000) = 0.000000    true
#   fptest top_fft.BFLY0.spsub_o2i.SUB (-0.049126 - -1.001206) = 0.952080    true
#   fptest top_fft.BFLY0.spsub_o2i.SUB (-0.098491 - -1.004838) = 0.906347    true
#   fptest top_fft.BFLY0.spsub_o2i.SUB (-0.148336 - -1.010942) = 0.862606    true
#   ...
# 
# Printed-out signals can fluctuate before achieving final value.
# This script finds and emits final answer as of each clock edge.
# 
# Sample input:
#   % less test_128_1_1port.log$i
#   ...
#   top_fft.BFLY0.spsub_o2r.SUB a= 1.000000 (3f800000) b= 0.000000 (00000000) z= 1.000000 (3f800000)
#   top_fft.BFLY0.spsub_o2r.SUB a= 1.000000 (3f800000) b= 0.000000 (00000000) z= 1.000000 (3f800000)
#   top_fft.BFLY0.spsub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.000000 (Xxxxxxxx)
#   top_fft.BFLY0.spsub_o2r.SUB a= 1.000000 (3f800000) b= 0.000000 (00000000) z= 1.000000 (3f800000)
#   top_fft.BFLY0.spsub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.000000 (Xxxxxxxx)
#   top_fft.BFLY0.spsub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.000000 (Xxxxxxxx)
#   top_fft.BFLY0.spsub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.414214 (3ed413cc)
#   top_fft.BFLY0 t5 ------------------------
#   ...
# 
# Sample output:
#   % fptest3.awk test_128_1_1port.log$i |& less
#   ...
#   fptest top_fft.BFLY0.spsub_o2r.SUB    (1.000000 - 0.000000)    =   1.000000    true
#   fptest top_fft.BFLY0.spsub_o2i.SUB   (-1.000000 - -1.414214)   =   0.414214    true
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

    # Generate comparison value
    # #     if (op == "sradd") { r = sprintf("%9.6f", prev[op "-a"] + prev[op "-b"]) }
    # #     if (op == "srsub") { r = sprintf("%9.6f", prev[op "-a"] - prev[op "-b"]) }
    # #     if (op == "srmul") { r = sprintf("%9.6f", prev[op "-a"] * prev[op "-b"]) }
    if (1) { r = sprintf("%9.6f", a-b) }

    diff = abs(r - zcmp)
    should_be = sprintf("false (should be %s) (del = %9.6f)", r, diff)
    good_enough = (diff <= 0.000002)
    # FIXME but is this really good enough?
   # A question for fpu testing i guess...

    result = (r == zcmp) ? "true" : should_be
    result = good_enough ? "true" : should_be

    printf("fptest %-27s %12s - %-12s = %10s    %s\n", op, "(" a, b ")", z, result);
    if (DBG) { printf("fptest    z_op['%s'] = %s\n", op, z_op[op]) }

    # Reset array
    line_op[op] = ""
  }
}

{ print }

/.*spsub.*z=[ -0123456789]/ {

  # before & after gsub:
  # top_fft.BFLY0.spsub_o2i.SUB a=-1.000000 (bf800000) b=-1.414214 (bfb504f3) z= 0.414214 (3ed413cc)
  # top_fft.BFLY0.spsub_o2i.SUB a= -1.000000 (bf800000) b= -1.414214 (bfb504f3) z=  0.414214 (3ed413cc)
  gsub(/=/, "= ", $0)

  # E.g. op="top_fft.BFLY0.spsub_o2r.SUB"
  op = $1
  line_op[op] = $0
  found_op[op] = 1

  # E.g. a,b,z = "1.000000","-1.414214","0.414214"
  a_op[op] = $3; b_op[op] = $6; z_op[op] = $9;

  if (DBG) { printf("fptest z_op['%s'] = %s\n", op, z_op[op]) }
}
