## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
##############################################################################
# Count how many cycles it takes to do the FFT
# BEGIN { found_reset = 0; }
# 
# RESET!!! (always happens at cycle #1)
# /^RESET\!\!\!/ { print "FOO Found reset"; found_reset = 1; }

BEGIN {
  DBG=0
  DBG=1
}

/^clock.vp.*ncy/ {
    # clock.vp: reset=0, ncy=   1, time=     1 ns
    gsub(/[=,]/, " "); # Eliminate equals and commas.
    # clock.vp: reset 0  ncy    1  time      1 ns
    cynum = $5;
    # if (found_reset) { begin_cy = cynum; print "FOO Begin at cy num " begin_cy; found_reset = 0; }
}

# SRAM001 t5 13000: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-0.414214)
/^SRAM.*Wrote/ {
    last_writes = cynum;
    print "FOO Did a write at cynum " last_writes;
}

##############################################################################
# Build a swizzle translation table
BEGIN { ixmax = 0; }

/^top_fft swizzle.*ix[0-9]/ {
    # "top_fft  7500 swizzle: BFLY0_op1 ix00 => SRAM003 mem[01]"
    ix   = $5;  # "ix00"
    bank = $7;  # "SRAM003"
    mem  = $8;  # "mem[01]"

    # "00" => "0" from "ix00"
    ix = substr(ix, 3, 99) + 0; 
    if (ix > ixmax) { ixmax = ix; }
    swizzle_table[ix] = $0;

    split(mem, memsplit, /[\[\]]/); # E.g. "mem[100]" => ("mem", "100")
    row = memsplit[2]+0;

    lix = bank "_" row;            # "SRAM003_100"
    swizzle_lookup[lix] = ix;      # swizzle_lookup["SRAM003_100"] = 0;

    if (DBG) {
        print  "FOO ix: \"" $0
        printf "FOO ix: ix=" ix
        printf ", lix= " lix
        printf ", swizzle_lookup[lix]=" swizzle_lookup[lix]
        print ""
        print "FOO"
    }
}


/^SRAM.*Wrote/ {
    # SRAM000 t5 13600: Wrote(f) wr_data_i mem[1] <= ( 1.000000, 2.414214)

    #print "FOO " $0;
    #print "FOO " $6;
    row = substr($6, 5, length($6)-5);    # "1" from "mem[1]"
    #print "FOO " row;
    lix = $1 "_" row;                     # e.g. "SRAM000_1" 
    #print "FOO " lix;
    #print "FOO " swizzle_lookup[lix];
    #print "FOO ";
    #print
    ix = swizzle_lookup[lix];             # E.g. "4"

    if (DBG) {
        print ""
        print "pt5.awk: " $0
        print "pt5.awk: sram=" lix ", ix=" ix;
        print ""
    }
    if (ix == "") {
        print "\nERROR ix appears to be null!?"
        print "lix=", lix
        print "swizzle_lookup[lix]=",  swizzle_lookup[lix]
        print "ix=", ix
        print ""
    }

    # ix04: SRAM000 t5 13600: Wrote(f) wr_data_i mem[1] <= ( 1.000000, 2.414214)
    if (ix != "") {
        sram_writes[ix] = sprintf("ix%02d: %s", ix, $0);

        if (DBG) {
            printf "FOO sw"
            #printf ", row=" row
            printf ", lix= " lix
            printf "=> ix = ." ix "."
            printf ", sr[ix]=" sram_writes[ix]
            print ""
        }
    }
}

END {
    print "--- TEST5 FINAL OUTPUT ---";
    print "FFT took " last_writes " cycles to complete."
    print "";
    for (i=0; i<=ixmax; i++) {
        print swizzle_table[i];
    }
    print "";
    for (i=0; i<=ixmax; i++) {
        print sram_writes[i];
    }

}

##############################################################################
# Do the other stuff

BEGIN { mybuf = ""; found_sram = 0; }

/ t5 --/ {
    if (found_sram) {
        print mybuf;
    }
    mybuf = ""; found_sram = 0;
}

/ t5/ {
    mybuf = mybuf $0 "\n";
}

/^SRAM/ { found_sram = 1; }
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
