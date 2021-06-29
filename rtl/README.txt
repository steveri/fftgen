This is the verilog for the fft. To power the FFT, you'll need a
single-precision floating-point unit (FPU) in subdirectory `lib`. To
this end, I put together my own freeware FPU, you can see it at
https://github.com/steveri/fpu

For your convenience, a snapshot of the repo is included in this
directory. You can use the snapshot by creating a symbolic link:

  % ln -s fpu_snapshot lib/


...or you can bring in the latest code from the freeware repo:

  % test -e lib/ && unlink lib
  % git clone https://github.com/steveri/fpu lib
