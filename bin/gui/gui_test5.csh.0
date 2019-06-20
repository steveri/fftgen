#!/bin/csh -f

#set echo
set DBG = 0

# Just used /home/steveri/fftgen/Makefile to build a bunch of stuff in...where...?

# Working directory pwd is something like "/nobackup/steveri/stewie_kiwi/cgi"
# $0 is something like '/home/steveri/fftgen/bin/tmp_hello_gui.csh' 

echo '<\!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">'
echo
if ($DBG) then
    echo "Howdy ho.  " I am here: `pwd` "<br><br>"
    echo "My name is '$0'<br><br>"
endif

echo "<pre>"
if ($DBG) echo "Now I am here: `pwd`<br><br>"
if ($DBG) echo "Gonna do: make -f /home/steveri/fftgen/Makefile -j 1 run TOP=fft<br><br>"

set tmp=/tmp/gui.simv.deleteme.$$
if ($DBG) echo "make stdout and stderr will go to $tmp<br><br>"

# BUG/TODO: Should source something more like "/nobackup/steveri/stewie_kiwi/configs/setup.cshrc"...?
#if (`hostname` == "vlsiweb") then
#  echo Sourcing...
#  ls -l /home/steveri/gui/configs/setup_stanford.cshrc
  source /home/steveri/gui/configs/setup_stanford.cshrc
#endif

if (`hostname` == "vlsiweb") then
    if (`whoami` == "www-data") then
        # vlsiweb non-stewie gui; cannot ssh anywhere else
        cat << ____eof | sed 's/^    //'
        <b><big>
        SORRY but this does not work from vlsiweb/genesis.
        Instead maybe try one of these:

        * <a href=http://vlsiweb.stanford.edu:8080>http://vlsiweb.stanford.edu:8080</a>
        * <a href=http://vlsiweb.stanford.edu:8081>http://vlsiweb.stanford.edu:8081</a>
        * <a href=http://vlsiweb.stanford.edu:8082>http://vlsiweb.stanford.edu:8082</a>
        </big></b>
____eof
    exit
  endif

    # vlsiweb stewie gui: can ssh to elsewheres maybe.
    #  set path = (/home/steveri/bin/fake_vcs $path)

    # As of 7/2013 neva-2 dir /cad/synopsys (needed for vcs) is EMPTY
    # ssh neva-2 /home/steveri/fftgen/bin/vlsiweb_hack.csh `pwd` >& $tmp

    # something wrong with vcs on neva, why am i not surprised
    #ssh neva /home/steveri/fftgen/bin/vlsiweb_hack.csh `pwd` >& $tmp

    # kiwi maybe works if remember to use .ssh/authorized_keys2
    ssh kiwi /home/steveri/fftgen/bin/vlsiweb_hack.csh `pwd` >& $tmp

    # /var/www/homepage/genesis_helper/whoami.pl
    # /var/www/homepage/genesis_helper/tmp-whoami.csh
else
    make clean
    make -f /home/steveri/fftgen/Makefile -j 1 run TOP=fft >& $tmp
endif
##############################################################################

if ($DBG) cat $tmp

set err = 0
egrep -i '^err' $tmp && set err = 1
if ($err) then
  echo "=============================================================================="
  echo "Error(s) maybe?"
  sed -n '/^[Ee][Rr][Rr]/,$p' $tmp | head -n 20
  echo "=============================================================================="
endif

#/bin/rm -rf /tmp/gui.simv.deleteme.$$

if ($DBG) echo "Gonna do: ls -l simv.log<br><br>"
if ($DBG) ls -l simv.log

if ($DBG) echo "Gonna do: head simv.log<br><br>"
if ($DBG) head simv.log

if ($DBG) echo "=============================================================================="

set myname=$0
set mydir=$myname:h
if ("$mydir" == "$myname") set mydir = .
set bindir = $mydir

if (! -e simv.log) then
  echo "I don't see a simv.log file; something must have gone wrong.  Sorry!"
  exit
endif

set simv_time = `find simv.log -ctime -.0417 -exec echo newer_than_one_hour \;`
if ("$simv_time" == "older_tan_one_hour") then
  echo "simv.log file is older than one hour..."
  echo "YOU PROBABLY SHOULD NOT TRUST THESE RESULTS!"
  echo "But here they are anyway...
  echo "------------------------------------------------------------------------"
endif

tail simv.log | sed -n '/V C S   S i m u l a t i o n   R e p o r t/,$p'
echo "------------------------------------------------------------------------"

cat simv.log | awk -f $bindir/process_test5.awk | sed -n '/TEST5 FINAL/,$p'

cat << eof
--------------------------------------------------------------------------
Sample correct output for eight data points:

           X             FFT X 
    ( 1.000, 0.000) ( 4.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-2.414)
    ( 1.000, 0.000) ( 0.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-0.414)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 0.414)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 2.414)

Sample correct output for sixteen data points:

           X             FFT X 
    ( 1.000, 0.000) ( 8.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-5.027)
    ( 1.000, 0.000) ( 0.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-1.496)
    ( 1.000, 0.000) ( 0.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-0.668)
    ( 1.000, 0.000) ( 0.000, 0.000)
    ( 1.000, 0.000) ( 1.000,-0.198)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 0.198)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 0.668)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 1.496)
    ( 0.000, 0.000) ( 0.000, 0.000)
    ( 0.000, 0.000) ( 1.000, 5.027)

eof

echo "</pre>"
