SHELL := /bin/bash
export PATH := .:$(PATH)

LOG := examples/simv.log
# TMP := analysis_results.tmp
TMP := $(shell mktemp)

.PHONY: test
test:
	@echo analyze_reads_and_writes.pl
	@analyze_reads_and_writes.pl -d $(LOG) |\
	  summarize_reads_and_writes.pl |\
	  egrep -v '^IGNORE|BB|wr' |\
	  uniq | sed 's/.*BREAK//' > $(TMP)
	@echo Compare results...
	@cmp examples/analysis_results.txt $(TMP) && res="PASS" || res="FAIL";\
	  rm $(TMP); echo $$res;\
	  [ "$$res" == "PASS" ] && exit 0 || exit 13



