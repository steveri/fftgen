FFT Generator
======

[![Build Status][1]][2] [![Build Status][3]][4]

[1]: https://github.com/steveri/fftgen/actions/workflows/CI.yml/badge.svg
[2]: https://github.com/steveri/fftgen/actions/workflows/CI.yml
[3]: https://app.travis-ci.com/steveri/fftgen.svg?branch=master
[4]: https://app.travis-ci.com/steveri/fftgen






This repo contains code for an FFT generator and testbench. The generator can build an 8-point FFT, a 1024-point FFT, or any power-of-two in between. It also provides a choice of 1, 2, or 4 butterfly units. The generator is powered by [Genesis2](https://github.com/StanfordVLSI/Genesis2).

This FFT uses a conflict-free schedule, meaning that it runs to completion without ever having to pause for memory-conflict resolution. Not counting setup and takedown simulation time, the FFT will therefore complete its operation in minimal time. So, for instance, if local memory access takes one cycle to complete, and if you use the generator to build a 1024-point FFT with only a single butterfly unit, it will complete its operation in (n/2)log2(n) or 5120 cycles. An FFT built with two butterflies working in parallel will take just half that amount of time, and so on.

The conflict-free schedule works on a variety of memory configurations, including single-ported SRAM. The single-ported version of this FFT would thus be the least-area memory configuration for a resource-constrained FFT.

Also see

* Richardson et al., "Building Conflict-Free FFT Schedules," April 2015, doi: 10.1109/TCSI.2015.2402935. https://ieeexplore.ieee.org/document/7070875

* Richardson et al., "An area-efficient minimum-time FFT schedule using single-ported memory," 2013, doi: 10.1109/VLSI-SoC.2013.6673242. https://ieeexplore.ieee.org/document/6673242


## Building FFT's with fftgen: A Quick How-To

You will need csh and perl (sorry!). If you don't already have them, see internet for instructions on how to install. Oh, and you'll also need verilator if you're going to use this prepackaged test build. VCS is also supported maybe, see `bin/golden_test.csh --help`.


```
  # 1. Clone the repo
  git clone https://github.com/steveri/fftgen
  FFTGEN=$PWD/fftgen

  # 2. The `setup_genesis` script installs Genesis.pl
  #    if it's not already in your path
  source $FFTGEN/bin/setup_genesis.sh

  # 3. Build a scratch/build area inside the clone
  mkdir fftgen/build; cd fftgen/build

  # 4. Build and test a single FFT design against a golden model,
  #    e.g. to build a 32-point in-place FFT using two butterfly units
  #    and one bank of single-port DRAM:
  $FFTGEN/bin/golden_test.csh 32 2 1port -sim verilator

  # 5. (Optional) Exhaustive test of multiple models
  $FFTGEN/bin/golden_test.csh

  # 6. (optional) More information
  $FFTGEN/bin/golden_test.csh --help
```

Our CI scripts also provide a good guide on how to build and run fftgen using an extensive test suite. Scripts are here:

* https://github.com/steveri/fftgen/tree/master/.github/workflows
* https://github.com/steveri/fftgen/blob/master/.travis.yml

And you can see the results of previous runs here:

* https://github.com/steveri/fftgen/actions/workflows/CI.yml
* https://app.travis-ci.com/github/steveri/fftgen/builds


#### CURRENT STATUS Jun 2021

- all regression tests PASS (47/47) using homebrew fpu
- I think it's all working with verilator now
- see 0notes-fft.txt, README.txt for latest/best info






#### NOTES

