### simv_analysis

#### DESCRIPTION

<pre>
  simv_analysis/ - tools for analyzing simv log for correctness

  Takes RTL simulation output e.g. "simv.log" and turns it into a
  readable schedule inc. twiddles.
</pre>


#### EXAMPLE

<pre>

  % log=/nobackup/steveri/github/fftgen/examples/test8.vcs/simv.log
  % c ; analyze_reads_and_writes.pl -d $log |\
    summarize_reads_and_writes.pl | egrep -v '^IGNORE|BB|wr' |\
    uniq | sed 's/.*BREAK//' | less

sort 001500 mem2r dp0 <- SRAM000     -- DBG2-ix0 FINAL 001500  reads  ( 0.000000, 0.000000) from SRAM000[0] (ix0)
sort 001500 mem2r dp1 <- SRAM001     -- DBG2-ix1 FINAL 001500  reads  ( 0.000000, 0.000000) from SRAM001[0] (ix1)
sort 001500 mem2r dp0 <- SRAM000     -- DBG2-ix0 FINAL 001500  reads  ( 1.000000, 0.000000) from SRAM000[0] (ix0)
sort 001500 mem2r dp1 <- SRAM001     -- DBG2-ix1 FINAL 001500  reads  ( 0.000000, 0.000000) from SRAM001[0] (ix1)
sort 002500 twiddle s0/dp0:  1.000   --               top_fft  2500: BFLY0_twiddle_cos = 3f800000 ( 1.000000)

Also see example simv log and analysis result in examples/ subdirectory.

</pre>

#### TEST

To test the analyzer, should be able simply to do, from this directory:

  make test

