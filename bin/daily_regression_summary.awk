#!/usr/bin/awk

# Skip this line :(
# "+(0):WARN:0: Directory '/home/steveri/.modules' not found"
/not found/ { next }

# Test name e.g. "TEST vcs_std"
/^TEST/ { testname = $2; testnames[testnum++] = $2 }
/^TEST/ { print testnum, testname }

# Stats
/^TR PASS/ { successes[testname]++ }
/WARN/     {  warnings[testname]++ }
/ERROR/    {    errors[testname]++ }
/^TR FAIL/ {  failures[testname]++ }

# Print
END {
  for (i=0; i< testnum; i++) {
    t = testnames[i]
    printf("TEST %s - %3d fail, %3d pass, %3d errors, %3d warnings\n", t,
      failures[t],
      successes[t],
      errors[t],
      warnings[t])
  }
}

# TEST vcs_std -  47 pass,   0 fail,   0 errors,   0 warnings
# TEST vcs_ext -  17 pass,   6 fail,  24 errors, 336 warnings
# TEST ver_ext -  17 pass,   6 fail,  24 errors, 336 warnings
# TEST ver_std - 175 pass,  12 fail,  48 errors,   0 warnings








##############################################################################
# OLD
# 
# Don't care about tests that passed e.g.
# "TR PASS: 0 mismatched results --- 8 1 1port (vcs)"
# Sample input:
#     TEST vcs_std
#     TR PASS: 0 mismatched results --- 8 2 dpump (vcs)
#     TR              -2607.594    -2607.593 *** WARNING only match to 2 sig figs (vcs)
#     TR                  5.790        5.789 *** ERROR '    5.79' ne '    5.78' (vcs)
#     ...

