Driver "swizzle0_test1.bash" uses "swizzle0_buildtable.pl" to
produce a table "swizzle0_test1.out.ref" that can be compared to a
figure in Jarmo's paper. It executes "make gen" followed by "make
  run" to produce a simulation log "simv.log" and then process the log
to produce the table. The process repeats for 32-, 64-, and 16-point
fft. If you want to run the script it might need a bit of
hand-holding, since it's been awhile...

Result of running the script should match "swizzle0_test1.out.ref"
which, as of 6/2019, looks like this:

<pre>
Building 32-point table; compare to Takala paper.

cd /home/steveri/smart_memories/Smart_design/ChipGen/fftgen
make -j 1 clean gen TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=32'
make -j 1       run TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=32'

            b=0  b=1  b=2  b=3
            ---  ---  ---  ---
row  0:      0    3    2    1
row  1:      7    4    5    6
row  2:     10    9    8   11
row  3:     13   14   15   12
row  4:     19   16   17   18
row  5:     20   23   22   21
row  6:     25   26   27   24
row  7:     30   29   28   31
------------------------------------------------------------------------------
Building 64-point table; compare to Takala paper.

cd /home/steveri/smart_memories/Smart_design/ChipGen/fftgen
make -j 1 clean gen TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=64'
make -j 1       run TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=64'

            b=0  b=1  b=2  b=3
            ---  ---  ---  ---
row  0:      0    1    2    3
row  1:      5    4    7    6
row  2:     10   11    8    9
row  3:     15   14   13   12
row  4:     17   16   19   18
row  5:     20   21   22   23
row  6:     27   26   25   24
row  7:     30   31   28   29
row  8:     34   35   32   33
row  9:     39   38   37   36
row 10:     40   41   42   43
row 11:     45   44   47   46
row 12:     51   50   49   48
row 13:     54   55   52   53
row 14:     57   56   59   58
row 15:     60   61   62   63
------------------------------------------------------------------------------
Building 16-point table; compare to Takala paper.

cd /home/steveri/smart_memories/Smart_design/ChipGen/fftgen
make -j 1 clean gen TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=16'
make -j 1       run TOP=swizzle0 GENESIS_PARAMS='top_swizzle0.n_fft_points=16'

            b=0  b=1  b=2  b=3
            ---  ---  ---  ---
row  0:      0    1    2    3
row  1:      5    4    7    6
row  2:     10   11    8    9
row  3:     15   14   13   12
</pre>
