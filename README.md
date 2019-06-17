fftgen - FFT Generator
======

| Status                       |
|------------------------------|
| [![linux build status][1]][2]|

[1]: https://travis-ci.org/steveri/fftgen.svg?branch=master
[2]: https://travis-ci.org/steveri/fftgen



UNDER DEVELOPMENT

Temporarily down for maintenance.  Check Back Again Tomorrow (tm).


#### CURRENT STATUS

- all regression tests PASS (47/47) using homebrew fpu
- still to do: make everything work with verilator
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
