This is the verilog for the fft. To use this verilog, you'll need a single-precision floating-point unit (FPU) in a subdirectory lib/.

You can use the default snapshot included with this repo:

  % ln -s fpu_snapshot lib/


...or you can bring in the latest from the FPU repo:

  % test -e lib/ && unlink lib
  % git clone https://github.com/steveri/fpu lib
