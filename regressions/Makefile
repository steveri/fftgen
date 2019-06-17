regress:
	@echo "Copy 'n' paste:"
	@echo "i=0"
	@echo "make -f ../Makefile cleanall"
	@echo '../bin/golden_test.csh -sim verilog >& gold.log$$i &'
	@echo 'tail -f gold.log$$i | egrep "PASS|ERR"'
	@echo ""

clean:
	make -f ../Makefile clean

cleanall:
	make -f ../Makefile cleanall

