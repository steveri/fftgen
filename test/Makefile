test: test_64_1_1port
fptest: fptest_64_1_1port


# Should we include "cleanall" as a dependence???
test_64_1_1port: cleanall
	../bin/golden_test.csh 64 1 1port |& tee gold_64_1_1port.log
	cp /tmp/test_64_1_1port.log test_64_1_1port.log

fptest_64_1_1port: test_64_1_1port.log
	../bin/fptest3.awk test_64_1_1port.log |& egrep ' (true|false)' | sort | uniq

clean:
	make -f ../Makefile clean

cleanall:
	make -f ../Makefile cleanall
