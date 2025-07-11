#!/bin/csh -f

goto main
usage:
  echo "Usage: $0 <filename>.{csh,sh,v,vp,pm,pl}"
  exit

main:
set dcr = /tmp/default_copyright_notice

cat << eof > ${dcr}_top.txt
## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
eof

cat << eof > ${dcr}_bottom.txt
##############################################################################
## Copyright Stephen Richardson and Stanford University.  All rights reserved.
##              Exclusively Licensed by Chip Genesis Inc.
##
## The code, the algorithm, or any part of it is not to be copied/reproduced.
## The code, the algorithm, or results from running this code may not be used
## for any commercial use unless legally licensed.
##
## For more information please contact
##   Ofer Shacham (Stanford Univ./Chip Genesis)   shacham@alumni.stanford.edu
##   Professor Mark Horowitz (Stanford Univ.)     horowitz@stanford.edu
##
## Genesis2 is patent pending. For information regarding the patent please
## contact the Stanford Technology Licensing Office.
###############################################################################
eof

if ($#argv != 1) then
  goto usage
endif

if (! -f $1) then
  echo "Could not find file '$1'"
  goto usage
endif

set commchar = '#';
set ext = $1:e
echo $ext
if ( (0)\
  || ("$ext" == "v") \
  || ("$ext" == "vp") \
  ) then 
    set commchar = '/';
endif

echo "Using '$commchar' as comment character."
echo

set tmp = ${1}_copyrighted

# Must preserve e.g. if first line is  '#!/usr/bin/csh -f'
head -n 1 $1 | egrep '^#!' > $tmp

# Add copyright notice
cat {$dcr}_top.txt    | sed "s.#.$commchar.g" >>  $tmp
cat $1                >> $tmp
cat {$dcr}_bottom.txt | sed "s.#.$commchar.g" >>  $tmp

echo "Coyprighted file is '$tmp'"
