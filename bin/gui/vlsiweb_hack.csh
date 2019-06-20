#!/bin/csh -f

set wd=$1
shift

set DBG = 0

if ($DBG) then
  echo hey looka me i am neva-2 maybe; echo
  hostname; echo
  echo and maybe wd is $wd; echo
  echo and maybe i have args: $*:q; echo
endif

source /home/steveri/gui/configs/setup_stanford.cshrc

if ($DBG) then
  which vcs; echo
endif

cd $wd

if ($DBG) then
  echo and maybe now i am here: `pwd`; echo
endif

# BUG/TODO so wait...this file (vlsiweb_hack.csh) is called from gui_test5.csh like so:
# "ssh neva-2 vlsiweb_hack ..."
# ...and "source setup" above does this:
# if (`hostname` == "vlsiweb")  set path = ($path /home/steveri/bin/fake_vcs)
# ... but now we're at neva-2 so vcs is still /cad/.../vcs and not fake_vcs/vcs
# ... conclusion: GET RID OF fake_vcs in setup etc.!
# BUG/TODO


if ($DBG) then
  echo and now i m gonna do: make -f /home/steveri/fftgen/Makefile -j 1 run TOP=fft
endif
make -f /home/steveri/fftgen/Makefile -j 1 run TOP=fft
