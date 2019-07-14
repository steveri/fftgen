<pre>
HOW-TO regress
  1. Start the endless regression script going
     % bin/endless_regression.sh >& log &

  1a. While it's running, feel free to monitor the progress
      % tail -f log
        vcs  128  4 1port PASS -   6 warnings,    42 lint problems -   190708 59s
        vcs 8192  4 1port PASS -  37 warnings,    42 lint problems -   190708 93m
        ver 4096  2 dpump PASS -  29 warnings, 98406 lint problems -   190708  6m
        ver  128  1 dpump PASS -   6 warnings,    77 lint problems -   190708  9s
        vcs  256  4 dpump PASS -   6 warnings,    11 lint problems -   190708  1m
        ver 2048  1 dpump PASS -   9 warnings,    77 lint problems -   190708  2m
        ver 8192  2 1port PASS -  37 warnings, 213085 lint problems -   190708 14m
        ver  512  1 1port PASS -   6 warnings,    72 lint problems -   190708  1m
        ...


  2. After time has passed, you can request coverage statistics (see "regression summary" below)
     % awk -f bin/coverage.awk log
        ...
                   8   16   32   64  128  256  512 1024 2048 4096 8192

        1-1port   14   11   14   12    9    7   10    5   10   16    8
        1-2port   12   10    9    8    6    6   14    8   13   13   11
        1-dpump   10    6   15    8   16   20   11   10    8    7   10

        2-1port   12    8    9    9    9    9    6   13   11   12    9
        2-2port   12   10   14    9   11   11    8   13   13    7   10
        2-dpump    9   10   11   14   13    9   12   14   12   13    5

        4-1port    8   13    4   15   10   10    6   12   10   10   11
        4-2port    9   15    9   10   12    7    9   20   12   11    7
        4-dpump    8   14   16    6   12   11    9    8   11   10    4

  3. (Optional) vcs-only or verilator-only coverage
     % grep ver log | awk -f bin/coverage.awk
     % grep vcs log | awk -f bin/coverage.awk


TODO
- should probably move this whole directory to fftgen/tst/

NOTES
To find lint warnings try something like
alias clip="sed 's/ -   ..........$//'"
alias no_warn="sed 's/[^ ]* warnings,//'"
alias sortlint="sort -n -k 2 -k 1 -k 3"
clip $log | no_warn | sortlint | uniq | head
clip $log | no_warn | sortlint | uniq | grep 1port | h40

sed 's/..........$//' $log | sed 's/. warn/x warn/' | sort -n -k 2 -k 1 -k 3 | uniq | grep 1port | h40


log=log2
alias clip="sed 's/ -   ..........$//'"
alias no_warn="sed 's/[^ ]* warnings,//'"
alias sortlint="sort -n -k 2 -k 1 -k 3"
clip $log | no_warn | sortlint | uniq | grep ver | grep 2\ 2port | less
    ver    8  2 2port FAIL -        0 lint problems
    ver   16  2 2port PASS -      146 lint problems
    ver   32  2 2port PASS -      336 lint problems
    ver   32  2 2port PASS -      337 lint problems
    ver   64  2 2port PASS -      785 lint problems
    ver  128  2 2port PASS -     1809 lint problems
    ver  256  2 2port PASS -     4113 lint problems
    ver 1024  2 2port PASS -    20497 lint problems
    ver 2048  2 2port PASS -    45073 lint problems
    ver 4096  2 2port PASS -    98321 lint problems
    ver 8192  2 2port PASS -   213009 lint problems





</pre>