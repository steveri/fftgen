# How To Use The Examples

To simulate and test the 8-port FFT with 1 butterfly unit and 1-port SRAM in subdirectory `8.1.1port`:
```
  # Set "repo" to wherever you cloned the fftgen repo;
  # e.g. $repo/bin/golden_test.pl should exist.

  repo=/nobackup/steveri/github/fftgen
  ls -l $repo/bin/golden_test.pl

  # Find the working directory for the desired configuration

  cd $repo/examples-rtl/8.1.1port

  # Build C code for an RTL simulator using the SystemVerilog in rtl/, with
  # tst/fft.cpp as testbench and cached collateral in fpu_snapshot as FPU
  # NOTE there will be warnings :(

  verilator -Wno-fatal -Wall --cc rtl/top_fft.v --exe $repo/tst/fft.cpp \
    --trace -y rtl/ -y $repo/rtl/fpu_snapshot

  # Compile the C code to make an executable simulator "Vtop_fft"

  make -j -C obj_dir/ -f Vtop_fft.mk Vtop_fft

  # Clean up from the simulator, leaving only the "Vtop_fft" simulator itself

  mv obj_dir/Vtop_fft .
  /bin/rm -rf obj_dir

  # At this point, the only thing left in the directory should be the
  # original "rtl" subdirectory,  plus the new simulator "Vtop_fft"

  # Run the RTL simulator, using an awk script to translate output bits
  # into readable floating-point formats. Note the simulator should also
  # produce a waveform file "counter.vcd" for debugging the RTL.

  Vtop_fft |& /nobackup/steveri/github/fftgen/bin/bsr.awk %9.6f \
    | awk -f $repo/bin/bsr.awk %9.6f > fft.log

  # Set parameters for perl-based high-level simulator ("golden model").
  # nports options include "1port", "2port", "dpump"

  npoints=8;   nunits=1;   nports="1port"

  # Compare RTL sim against real and imaginary results from golden model (GM)
  # WARNING: perl script "pl" requires you to have perl installed :(

  $repo/bin/golden_test.pl fft.log $npoints $nunits $nports

  # Output from above command should look like this (below).
  # "GM" and "FFT" columns should match.

  ------------------------------------------------------------------------
  Comparing fft.log against GM w/ npoints=8, nunits=1 and sram_type="1port".

  Real results:      GM          FFT
                   4.000        4.000
                   1.000        1.000
                   0.000        0.000
                   1.000        1.000
                   0.000        0.000
                   1.000        1.000
                   0.000        0.000
                   1.000        1.000

  Imag results:      GM          FFT
                   0.000        0.000
                  -2.414       -2.414
                   0.000        0.000
                  -0.414       -0.414
                   0.000        0.000
                   0.414        0.414
                   0.000        0.000
                   2.414        2.414

  PASS: 0 mismatched results --- 8 1 1port
  ------------------------------------------------------------------------
```

Note for 1024-4-2port example, you would use a similar sequence except with
`npoints=1024`, `nunits=4`, `nports="2port`.


<!-- ------------------------------------------------------------------------ -->
# How Genesis2 Was Used To Generate The Example RTL


For 8-port FFT with 1 butterfly unit and 1-port SRAM example
```
  # Set "repo" to wherever you cloned the fftgen repo;
  # $repo/Makefile should exist
  repo=/nobackup/steveri/github/fftgen
  ls $repo/Makefile

  # Prepare a working directory
  mkdir 8.1.1port; cd 8.1.1port

  # Translate sram choice into genesis-speak;
  # options include "TRUE_1PORT", "1PORT_DBLPUMP", "TRUE_2PORT"
  if [ "$nports" == "1port" ]; then sram="TRUE_1PORT";
  if [ "$nports" == "2port" ]; then sram="TRUE_2PORT";
  if [ "$nports" == "dpump" ]; then sram="1PORT_DBLPUMP";

  # Genesis parameters for makefile
  p1=top_fft.n_fft_points=$npoints
  p2=top_fft.units_per_cycle=$nunits
  p3=top_fft.SRAM_TYPE=$sram
  p4=top_fft.swizzle_algorithm=round7
  p5=top_fft.SIMULATOR=verilator

  # Generate the RTL
  make -f $repo/Makefile clean gen SIM=verilator TOP=fft \
    GENESIS_PARAMS="$p1 $p2 $p3 $p4 $p5" |& tee make.log | less

  # Clean up; This should get rid of everything except make.log and rtl/
  # (genesis_clean.cmd should have been created by above "make" command)
  mv genesis_verif rtl
  genesis_clean.cmd
```

The above sequence would leave you with the SystemVerilog RTL in a subdirectory
`8.1.1port/rtl`.

