# This file is to be SOURCED, not EXECUTED, get it?

# Avoid setup warning by ensuring .modules dir exists
test -d ~/.modules || mkdir ~/.modules

echo -n "BEFORE: "; which vcs
source /cad/modules/tcl/init/sh
module load base
module load vcs
echo -n "AFTER: "; which vcs

# export PATH=.:\
#   /home/steveri/bin:\
#   /usr/bin:/usr/local/sbin:\
#   /usr/local/bin:/usr/sbin:/sbin:\
#   /bin:/cad/common/Linux/x86_64/bin:\
#   /cad/synopsys/vcs/O-2018.09-SP1/bin:\
#   /cad/synopsys/vcs/O-2018.09-SP1/gui/dve/bin
