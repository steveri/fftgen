# TO RUN ALL TESTS MAYBE, DO THIS MAYBE
source /nobackup/steveri/garnet_venv/bin/activate
testall.sh |& tee tmp.log | less


========================================================================
NOTES

ref: /nobackup/steveri/github/fftgen/.github/workflows/CI.yml

TESTS in CI.yml: test-summary.sh?
- cd bin/simv_analysis; make test
- all it does is it just
-- takes the pre-built log of an fft run
-- runs it through a (perl!) filter to make a readable summary
-- compares the summary to a gold model `exampes/analysis_results.txt`

------------------------------------------------------------------------
TESTS in CI.yml: test-pypl.sh --gold8
- build and test an 8-point fft, compare to cached fftgen results

TESTS in CI.yml: test-pypl.sh --comp16
- verify perl and python models get same answer for 16-point FFT

# TESTS in CI.yml: test-regress.sh -sim verilator --perl
- exhaustive regression test, perl version

# TESTS in CI.yml: test-regress.sh -sim verilator --python
- exhaustive regression test, python version


# OLD i think
# ------------------------------------------------------------------------
# TESTS in CI.yml: regressions.sh --perl?
# - bin/golden_test.sh --perl -sim verilator > log
# - egrep 'FAIL|ERR' test_results.log
# 
# TESTS in CI.yml: regressions.sh --python?
# - bin/golden_test.sh --python -sim verilator > log
# - egrep 'FAIL|ERR' test_results.log
