#!/usr/bin/awk -f

function help() {
    # Can pass command name on command line for e.g. wrapper e.g.
    # "bsr.sh -v CMD=bsr.sh 0xffff0000"
    if (CMD == "") CMD = "bsr.awk"; # Command name
    cmd1   = "    " CMD;            # One level of indent
    print                                               \
        CMD " - Convert 8-digit hex to 32-bit float\n"          \
                                                                \
        cmd1" 3f80_0000       // Returns '3f800000 =  1.000e+00'\n"     \
        cmd1" bf800000        // Returns 'bf800000 = -1.000e+00'\n"     \
        cmd1" %6.3f bf800000  // Returns 'bf800000 = -1.000'\n"         \
        "\n"                                                            \
        "Also: convert all instances of \"bsr'<hex8>\" found in stdin:\n" \
        "    echo \"answer=bsr'3f800000\" | "CMD" %3.1f  // Returns 'answer=1.0'\n" \
        cmd1" %9.6f < IN > OUT\n"                                       \
        "        IN:  \"SRAM001 t5 103500: Wrote(f) wr_data_i mem[0] <= (bsr'3f800000,bsr'c0a0dff6)\"\n" \
        "        OUT: \"SRAM001 t5 103500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-5.027339)\"\n" \
        "\n"                                                            \
        "Also:\n"                                                       \
        cmd1" --test       // regression test\n"                        \
        cmd1" help         // help!\n"                                  \
        "\n"                                                            \
        "More examples:\n"                                              \
        cmd1" %7.3f 3f800000 %12.4e 3fc00000 3fe00000\n"                \
        ;
}

BEGIN { argc=ARGC; for (i in ARGV) {argv[i] = ARGV[i]; delete ARGV[i] } }
BEGIN {
    # printf(" CMD='%s' \n", CMD);
    FORMAT = "%10.3e"; # Default
        saveDBG=DBG; DBG=0
        if (DBG) printf("Found %d args:\n", argc);
#         if (argc == 1) { help(); exit; }
        for (i=1; i<argc; i++) {
            if (DBG) printf(" %d %s\n", i, argv[i]);
            if      (argv[i] == "help")   { help(); exit; }
            else if (argv[i] == "--test") { test_bsr(); brtest_all(); exit; }
            else if (match(argv[i], /^-/)){ help(); exit; }
            else if (match(argv[i], /^%/)){ FORMAT=argv[i]; }
            else {
                hex8 = argv[i]; gsub("_", "", hex8);  gsub(/^0x/, "", hex8); 
                printf("%s = "FORMAT"\n", hex8, bsr(hex8)) }
        }
        DBG=saveDBG
#         exit
}

# here we go...
{ print bsr_replace($0) }

# function help_bsr() {
#     # cmd = ENVIRON["_"] # :(
#     cmd = "bsr.awk";     # :)
#     print "Converts 8-digit hex into a short real"
#     print ""
#     print "Examples"
#     print "    " cmd " 3f80_0000    // returns  1.0"
#     print "    " cmd " bf800000     // returns -1.0"
#     print ""
#     print "    " cmd " --test       // regression test"
#     print "    " cmd " help         // help!"
# }

function brtest(line,gold) {
    t1 = bsr_replace(line)
    printf("  Wanted: '%s'\n", gold);
    printf("  Gotted: '%s'\n", t1);
    if (t1 == gold) printf "  PASS"; else printf "  FAIL";
    print "____________________________________";
    if (t1 == gold) nfails=0; else nfails=1;
    return nfails
    # 1 is good, 0 is bad, what's so hard to understand???
}
function brtest_all() {
    print "TEST BSR_REPLACE"
    nfails = 0; ntests = 0;
    ntests++; nfails += brtest(                                          \
         "SRAM002 2500: ez_i=0 and wz_i=1", "SRAM002 2500: ez_i=0 and wz_i=1");
    ntests++; nfails += brtest(                                          \
         "SRAM001 t5 103500: Wrote(f) wr_data_i mem[0] <= (bsr'3f800000,bsr'c0a0dff6)",\
         "SRAM001 t5 103500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-5.027339)");
    result = nfails ? "FAILED" : "PASSED";
    printf("TEST BSR_REPLACE %s (%d pass, %d fail)\n\n", result, ntests-nfails, nfails);


}
function bsr_replace(line) {
    # IN:  "SRAM001 t5 103500: Wrote(f) wr_data_i mem[0] <= (bsr'3f800000,bsr'c0a0dff6)"
    # OUT: "SRAM001 t5 103500: Wrote(f) wr_data_i mem[0] <= ( 1.000000,-5.027339)"
    save_DBG=DBG; DBG=0
    # e.g. fa[2] = "3f800000,"
    nf = split(line, fa, "bsr'");
    if (nf == 1) return line; # No bsr's found

    line2 = fa[1]
    if (DBG) printf("  INPUT=  '%s'\n", line);
    if (DBG) print  "  ---";
    for (i=2; i<=nf; i++) {
        if (DBG) printf("  field%d = '%s'\n", i, fa[i]);
        hex8 = substr(fa[i], 1, 8);
        if (DBG) printf("  hex8_%d = '%s'\n", i, hex8);
        fp32 = sprintf("%9.6f", bsr(hex8));
        if (DBG) printf("  fp32_%d = '%s'\n", i, fp32);
        fai2 = fp32 substr(fa[i],9,1000);
        if (DBG) printf("  field%d = '%s'\n", i, fai2);
        line2 = line2 fai2
        if (DBG) print  "  ---";
    }
    if (DBG) printf("  OUTPUT= '%s'\n", line2);
    if (DBG) print "";

    DBG=save_DBG; return line2
}


function test_bsr() {
    FAIL=0;
    print "TEST BSR"
    tests =                                       \
        "3f80_0000  1.0\n"                        \
        "3f800000   1.0\n"                        \
        "bf800000  -1.0\n"                        \
        ;
    ntests = split(tests, pair_array, "\n") - 1;
    for (i=1; i<=ntests; i++) {
        n = split(pair_array[i], a, / */);
        query=a[1]; gold=a[2];
        ans = bsr(query);
        printf("  bsr(%9s) = %10.3e = %10.3e ? ", query, ans, gold);
        if ((ans+0.0) == (gold+0.0)) print "PASS"; else print "FAIL"
        if ((ans+0.0) != (gold+0.0)) FAIL++
    }
    if (FAIL) printf("TEST BSR FAILED");
    else      printf("TEST BSR PASSED");
    printf(" (%d pass, %d fail)\n\n", ntests-FAIL, FAIL);
}

function bsr(bits) {
  # Similar to verilog "$bitstoshortreal()"
  # E.g. bsr("3f80_0000") =  1.0
  # E.g. bsr("bf80_0000") = -1.0

  # bits = 32b number [31:0]
  # sign = bit 32 = bits[31]
  # exponent = 8 bits [30:23] offset by 127
  # mantissa = 23 bits [22:0] plus hidden 1 at the front (total 24 bits)

  save_DBG = DBG
  DBG=0
#   if (DBG==9) {
#     bits = "3f80_0000" #  1.0 ?
#     bits = "bf80_0000" # -1.0 ?
#   }

  t0 = bits

  # Remove underbars e.g. "3f80_0000" == "3f800000"
  t1 = bits; gsub(/_/, "", t1)
  gsub(/^0x/, "", t1); # Just for kicks
  if (length(t1) != 8) {
      printf("ERROR Too many digits in input string '%s'\n", t1) | "cat >&2";
      exit(13)
  }

  # Hex it
  tstr = "0x" t1

  # Turn it into a 32-bit integer (unsigned I hope?)
  tnum = and(strtonum(tstr), 0xffffffff)

  # What we got so far
  if (DBG==9) { printf("t_in= '%s' = '%s' = '%s' = '%08X'\n", t0, t1, tstr, tnum) }

  sign = rshift(tnum, 31)
  expt0 = rshift( and(tnum,0x7f800000), 23)
  mant0 = and(tnum,0x7fffff)

  # Now what we got, e.g.
  # raw (sign,expt,mant) = (1, 7f, 000000)
  if (DBG==9) printf("raw (sign,expt,mant) = (%d,  %02x, %06x)\n", sign, expt0, mant0)

  expt = expt0 - 127; mant = or(mant0,0x800000)
  if (DBG==9) printf("tru (sign,expt,mant) = (%s,%4d, %06x)\n",\
                     sign ? "-" : "=", expt, mant)

  sc = sign ? "-" : "+";
  s = sign ? -1.0 : 1.0; 
  rval = s * mant * (2**-23) * (2**expt);

  if (DBG==9) {
      printf("final value = %7s[0x%06X * 2^(-23)] * 2^(%d)\n", sc, mant, expt)
      printf("final value = %7s%e * 2^(%d)\n", sc, mant * (2**-23),      expt)
      printf("final value = %7s%e\n",          sc, mant * (2**-23) * (2**expt))
  }
  if (DBG) printf("  bsr('%s') = %10.3e\n", t0, rval);

  DBG = save_DBG
  return rval;
}
