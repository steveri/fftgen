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


</pre>