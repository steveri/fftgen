#!/bin/csh -f

# Just used /home/steveri/fftgen/Makefile to build a bunch of stuff in...where...?

# Working directory pwd is something like "/nobackup/steveri/stewie_kiwi/cgi"
# $0 is something like '/home/steveri/fftgen/bin/tmp_hello_gui.csh' 


echo '<\!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">'
echo
echo "It did this:<br>"
echo "Howdy ho<br>"
echo "<br>"
echo I am here: `pwd`
echo "<br>"
echo "<br>"

echo "My name is '$0'"
echo "<br>"
echo "<br>"

# gui/cgi/do_anything.pl should have already done this:
# cd ../designs/FFTGenerator

echo "NOT gonna do: 'cd ../designs/FFTGenerator'<br><br>"


echo "<pre>"
echo "Now I am here: `pwd`"
echo
echo

set myname=$0
set mydir=$myname:h
if ("$mydir" == "$myname") set mydir = .
set bindir = $mydir

echo "bindir is '$bindir'"
echo
echo
echo "</pre>"
