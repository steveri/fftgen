#!/usr/bin/awk -f

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
#   srsub top_...spsub_o2i.SUB a= 0.00 (0000) b= 0.00 (0xxx) z= 0.00 (xxxx)
#   srsub top_...spsub_o2r.SUB a= 1.00 (3f80) b= 0.00 (0000) z= 0.00 (xxxx)
#   srsub top_...spsub_o2i.SUB a= 0.00 (0000) b= 0.00 (0000) z= 0.00 (0000)
#   srsub top_...spsub_o2r.SUB a= 1.00 (3f80) b= 0.00 (0000) z= 1.00 (3f80)
#   srsub top_...spsub_o2i.SUB a= 0.00 (0000) b= 0.00 (0000) z= 0.00 (0000)
#   srsub top_...spsub_o2i.SUB a= 0.00 (0000) b= 0.00 (0000) z= 0.00 (0000)
#   top_fft.BFLY0 t5 ------------------------
#   top_fft.BFLY0 t5  1502: in1(r,i)= ( 1.000000, 0.000000)
#   top_fft.BFLY0 t5  1502: in2(r,i)= ( 0.000000, 0.000000)
#   ...
# 
# Sample output:
#   % fptest3.awk test_128_1_1port.log$i |& less
#   
#   top_fft.BFLY0 t5 ------------------------
#   fptest top_fft.BFLY0.spsub_t1.SUB  (0.000000 - 0.000000) = 0.000000    true
#   fptest top_fft.BFLY0.spsub_o2r.SUB (1.000000 - 0.000000) = 1.000000    true
#   fptest top_fft.BFLY0.spsub_o2i.SUB (0.000000 - 0.000000) = 0.000000    true
#   fptest    z_op['top_fft.BFLY0.spsub_t1.SUB'] = 0.000000
#   fptest    z_op['top_fft.BFLY0.spsub_o2r.SUB'] = 1.000000
#   fptest    z_op['top_fft.BFLY0.spsub_o2i.SUB'] = 0.000000

##############################################################################
# Really?
function abs(v) {return v < 0 ? -v : v}

BEGIN { DBG = 0 }

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


    printf("fptest %-27s (%s - %s) = %s    %s\n", op, a, b, z, result);
    if (DBG) { printf("fptest    z_op['%s'] = %s\n", op, z_op[op]) }

    # Reset array
    line_op[op] = ""
  }
}

{ print }

/^srsub.*z=[ -0123456789]/ {
  # Sometimes there are not enough spaces after an '=', like in
  # srsub top_fft.BFLY0.spsub_o2i.SUB a= 0.000000 (00000000) b=-1.000000 ...
  gsub(/=/, "= ", $0)

  # before & after:
  # srsub top_fft.BFLY0.spsub_o2r.SUB a= 2.000000 (40000000) b= 2.000000 (40000000) z= 0.000000 (00000000)
  # srsub top_fft.BFLY0.spsub_o2r.SUB a=  2.000000 (40000000) b=  2.000000 (40000000) z=  0.000000 (00000000)

#   if (DBG) print "FP1 "
#   if (DBG) print "FP1 " $0

  op = $2 # E.g. "top_fft.BFLY0.spsub_o2r.SUB"
  line_op[op] = $0
  a_op[op] = $4; b_op[op] = $7; z_op[op] = $10;
  found_op[op] = 1

  if (DBG) { printf("fptest z_op['%s'] = %s\n", op, z_op[op]) }
}
