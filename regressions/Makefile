regress:
	@echo "Copy 'n' paste:"
	@echo "  make -f ../Makefile cleanall"
	@echo '  log=gold.log1'
	@echo '  ../bin/golden_test.csh >& $$log &'
	@echo "  tail -f $$log | egrep 'PASS|FAIL'"
	@echo ""

clean:
	make -f ../Makefile clean

cleanall:
	make -f ../Makefile cleanall

