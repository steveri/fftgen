#!/bin/bash

########################################################################
# For now, assume input is "stdin"
# First, save input to a tmp file
#
# Keep ONLY lines containing ("FINAL" or "ERROR" *and* "^DBG..ix") or "twid"
# *but not* lines containing "^DBG3" or "IGNORE"

tmp=/tmp/sum.$$
cat > $tmp.1

#  | egrep '(^DBG..ix.*(FIN|ERR))|twid' \
cat $tmp.1 \
  | egrep '^DBG..ix.*(FIN|ERR)' \
  | egrep -v '^DBG3|IGNORE' \
  > $tmp

########################################################################
# Make a list of all "ix" values (0 1 2 ... 1023) e.g.
# "DBG2-ix11 FINAL 001000 BFLY0_op1 reads  ( 1.000000, 0.000000) from SRAM000[0] (ix0)"
#  => "11"

cat $tmp \
   | sed 's/DBG[0-9]*[-]ix\([0-9]*\) .*/\1/' \
   | sort -n | uniq > $tmp.ix

########################################################################
# Make an array containing all the ix values
# E.g. ix_array = (0 1 2 3 4 5 6 7)
ix_array=(`cat $tmp.ix`)

########################################################################
# For each index in order, capture its progress as it gets read out,
# transformed and written back to SRAM (or bypass buffer).
#
# foreach "ix" term (0 1 2 ... <n>)
#        grep "^DBG..ix1 " | egrep 'FIN|ERR' | grep -v IGNORE | add-blank-lines
# 2a. "add-blank-lines" means one blank line after every "DBG5"
# except at end do a "hline"

echo -n "" > $tmp.3

# foreach i ($ix_array:q)
cat $tmp.ix | while read i; do

  ix=ix$i
  #echo $ix
  cat $tmp\
    | grep "^DBG..$ix " | uniq  \
    | grep -v 'out is'    \
    | sed 's/ to SRAM/  to  SRAM/'     \
    | awk '\
           /^DBG2/ && NR>1 { print "" }\
           {print }\
'\
    >> $tmp.3

   hline="===========================================";
   echo "$hline$hline" >> $tmp.3
done

cat $tmp.3


##############################################################################
# Output should look something like this:
# DBG2-ix0 FINAL 001000 BFLY0_op1 reads  ( 1.000000, 0.000000) from SRAM000[0] (ix0)
# DBG3-ix0 FINAL 001000 BFLY0_op1 reads  ( 1.000000, 0.000000) [ from SRAM000[0] (ix0) ]
# DBG4-ix0 FINAL 001002 BFLY0_op1 out is ( 1.000000, 0.000000) [ ix0, SRAM000[0] ]
# DBG5-ix0 FINAL 001500 BFLY0_op1 writes ( 1.000000, 0.000000) to SRAM000[0] (ix0)
# 
# DBG2-ix0 FINAL 009000 BFLY0_op1 reads  ( 1.000000, 0.000000) from SRAM000[0] (ix0)
# DBG3-ix0 FINAL 009000 BFLY0_op1 reads  ( 1.000000, 0.000000) [ from SRAM000[0] (ix0) ]
# DBG4-ix0 FINAL 009002 BFLY0_op1 out is ( 2.000000, 0.000000) [ ix0, SRAM000[0] ]
# DBG5-ix0 FINAL 009500 BFLY0_op1 writes ( 2.000000, 0.000000) to SRAM000[0] (ix0)
# 
# DBG2-ix0 FINAL 017000 BFLY0_op1 reads  ( 2.000000, 0.000000) from SRAM000[0] (ix0)
# DBG3-ix0 FINAL 017000 BFLY0_op1 reads  ( 2.000000, 0.000000) [ from SRAM000[0] (ix0) ]
# DBG4-ix0 FINAL 017002 BFLY0_op1 out is ( 4.000000, 0.000000) [ ix0, SRAM000[0] ]
# DBG5-ix0 FINAL 017500 BFLY0_op1 writes ( 4.000000, 0.000000) to SRAM000[0] (ix0)
# 
# DBG2-ix0 FINAL 025000 BFLY0_op1 reads  ( 4.000000, 0.000000) from SRAM000[0] (ix0)
# DBG3-ix0 FINAL 025000 BFLY0_op1 reads  ( 4.000000, 0.000000) [ from SRAM000[0] (ix0) ]
# DBG4-ix0 FINAL 025002 BFLY0_op1 out is ( 8.000000, 0.000000) [ ix0, SRAM000[0] ]
# DBG5-ix0 FINAL 025500 BFLY0_op1 writes ( 8.000000, 0.000000) to SRAM000[0] (ix0)
# ==============================================================================
# DBG2-ix1 FINAL 001000 BFLY0_op2 reads  ( 0.000000, 0.000000) from SRAM001[0] (ix1)
# DBG3-ix1 FINAL 001000 BFLY0_op2 reads  ( 0.000000, 0.000000) [ from SRAM001[0] (ix1) ]
# DBG4-ix1 FINAL 001002 BFLY0_op2 out is ( 1.000000, 0.000000) [ ix1, SRAM001[0] ]
# DBG5-ix1 FINAL 001500 BFLY0_op2 writes ( 1.000000, 0.000000) to SRAM001[0] (ix1)
# 
# DBG2-ix1 FINAL 013000 BFLY0_op1 reads  ( 1.000000, 0.000000) from SRAM001[0] (ix1)
# DBG3-ix1 FINAL 013002 BFLY0_op1 reads  ( 1.000000, 0.000000) [ from SRAM001[0] (ix1) ]
# DBG4-ix1 FINAL 013002 BFLY0_op1 out is ( 1.000000,-1.000000) [ ix1, SRAM001[0] ]
# DBG5-ix1 FINAL 013500 BFLY0_op1 writes ( 1.000000,-1.000000) to SRAM001[0] (ix1)
# 
# DBG2-ix1 FINAL 019000 BFLY0_op1 reads  ( 1.000000,-1.000000) from SRAM001[0] (ix1)
# DBG3-ix1 FINAL 019000 BFLY0_op1 reads  ( 1.000000,-1.000000) [ from SRAM001[0] (ix1) ]
# DBG4-ix1 FINAL 019002 BFLY0_op1 out is ( 1.000000,-2.414214) [ ix1, SRAM001[0] ]
# DBG5-ix1 FINAL 019500 BFLY0_op1 writes ( 1.000000,-2.414214) to SRAM001[0] (ix1)
# 
# DBG2-ix1 FINAL 026000 BFLY0_op1 reads  ( 1.000000,-2.414214) from SRAM001[0] (ix1)
# DBG3-ix1 FINAL 026000 BFLY0_op1 reads  ( 1.000000,-2.414214) [ from SRAM001[0] (ix1) ]
# DBG4-ix1 FINAL 026002 BFLY0_op1 out is ( 1.000000,-5.027340) [ ix1, SRAM001[0] ]
# DBG5-ix1 FINAL 026500 BFLY0_op1 writes ( 1.000000,-5.027340) to SRAM001[0] (ix1)
# 
# ...


#            BEGIN { d5 = "DBG2-ix0"; }\
#            /^DBG2/ && NF>1 { if ($1==d5) print ""; else print hline hline; d5 = $1; }\
#            {print NR " - " $0; }\
##############################################################################
## Copyright Stephen Richardson and Stanford University.  All rights reserved.
##              Exclusively Licensed by Chip Genesis Inc.
##
## The code, the algorithm, or any part of it is not to be copied/reproduced.
## The code, the algorithm, or results from running this code may not be used
## for any commercial use unless legally licensed.
##
## For more information please contact
##   Ofer Shacham (Stanford Univ./Chip Genesis)   shacham@alumni.stanford.edu
##   Professor Mark Horowitz (Stanford Univ.)     horowitz@stanford.edu
##
## Genesis2 is patent pending. For information regarding the patent please
## contact the Stanford Technology Licensing Office.
###############################################################################
