fftgen - FFT Generator
======

| Status                       |
|------------------------------|
| [![linux build status][1]][2]|

[1]: https://travis-ci.com/steveri/fftgen.svg?branch=master
[2]: https://travis-ci.com/steveri/fftgen


This is an FFT generator and testbench. The generator can build an 8-point FFT, a 1024-point FFT, or any power-of-two in between. It also provides a choice of 1, 2, or 4 butterfly units. The generator is powered by [Genesis2](https://github.com/StanfordVLSI/Genesis2).

This FFT uses a conflict-free schedule, meaning that it runs to completion without ever having to pause for memory-conflict resolution. Not counting setup and takedown simulation time, the FFT will therefore complete its operation in minimal time; e.g. if local memory access takes one cycle to complete, and you use the generator to build a 1024-point FFT with only a single butterfly unit, it will complete in
(n/2)log2(n)= 5120 cycles. A unit build with two butterflies working in parallel will complete in half that time, and so on.

The conflict-free schedule works on a variety of SRAM configurations, including single-ported SRAM. The single-ported version of this FFT should thus be the least-area memory configuration for a resource-constrained FFT.

Also see

* Richardson et al., "Building Conflict-Free FFT Schedules," April 2015, doi: 10.1109/TCSI.2015.2402935. https://ieeexplore.ieee.org/document/7070875

* Richardson et al., "An area-efficient minimum-time FFT schedule using single-ported memory," 2013, doi: 10.1109/VLSI-SoC.2013.6673242. https://ieeexplore.ieee.org/document/6673242


# Building the FFT(s): A Quick How-To Guide

0. You'll need csh and perl (sorry!). If you don't already have them, see internet for instructions on how to install. Oh, and you'll also need verilator if you're going to use this prepackaged test build. VCS is also supported maybe, see `bin/golden_test.csh --help`.


1. Clone the repo
```
  git clone https://github.com/steveri/fftgen
  FFTGEN=$PWD/fftgen
```


2. This script installs Genesis.pl if it's not already in your path
```
  source $FFTGEN/bin/setup_genesis.sh
```


3. Build a scratch/build area inside the clone
```
  mkdir fftgen/build; cd fftgen/build
```


4. Build and test a single FFT design against a golden model, e.g. to build a 32-point in-place FFT using two butterfly units and one bank of single-port DRAM:
```

  $FFTEGEN/bin/golden_test.csh 32 2 1port -sim verilator
```


5. Exhaustive test of multiple models
```
  $FFTEGEN/bin/golden_test.csh
```


6. More information
```
  $FFTEGEN/bin/golden_test.csh --help
```

Also look at .travis.yml to see how we run these test on travis for CI (continuous integration) purposes.










#### CURRENT STATUS Jun 2021

- all regression tests PASS (47/47) using homebrew fpu
- I think it's all working with verilator now
- see 0notes-fft.txt, README.txt for latest/best info






#### NOTES
<pre>
dependences include perl, csh, genesis2, ...others...?
</pre>

<pre>
2. Need Synopsys' vcs tool in your path. On kiwi:
   (TODO should be a bin/setup_vcs.sh, yes?)
   which vcs
   source /cad/modules/tcl/init/sh
     +(0):WARN:0: Directory '/home/steveri/.modules' not found
   module load base
   module load vcs
   export PATH=.:/home/steveri/bin:/usr/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/sbin:/bin:/cad/common/Linux/x86_64/bin:/cad/synopsys/vcs/O-2018.09-SP1/bin:/cad/synopsys/vcs/O-2018.09-SP1/gui/dve/bin

   vcs -full64 -help | head

Note this process can destroy your MANPATH by doing this:

  % echo $MANPATH
  /cad/synopsys/vcs/O-2018.09-SP1/doc/man
  % man bash
  No manual entry for bash

...this can maybe be fixed by unsetting MANPATH

  % export MANPATH=
  % man bash
  <success!>

original path:
  export PATH=.:/home/steveri/bin:/usr/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/sbin:/bin
</pre>
