#!/usr/bin/perl
##############################################################################
# Used by driver "swizzle0_test1.bash"; turns output of "swizzle0" test into a
# table that can be compared to a figure in Jarmo's paper.
##############################################################################
use strict;
my ($maxr,$maxb) = (0,0);

# Two passes.  One to determine maxr, maxb.
my @lines = (<>);
foreach my $line (@lines) {
    #print $_;
    #if (/^\s*address\s*([0-9]+).*bank\s*([0-9]+) row([0-9]+)/) {
    if ($line =~ /^\s*address\s*([0-9]+).*bank\s*([0-9]+)\s*row\s*([0-9]+)/) {
#        print $line;

        my $a = $1; # address
        my $b = $2; # bank
        my $r = $3; # row

        if ($b > $maxb) { $maxb = $b; }
        if ($r > $maxr) { $maxr = $r; }

#        print "a=$a b=$b r=$r\n";

    }
}

# Second pass builds the table
my @table = ();
foreach my $line (@lines) {
    #print $_;
    #if (/^\s*address\s*([0-9]+).*bank\s*([0-9]+) row([0-9]+)/) {
    if ($line =~ /^\s*address\s*([0-9]+).*bank\s*([0-9]+)\s*row\s*([0-9]+)/) {
#        print $line;

        my $a = $1; # address
        my $b = $2; # bank
        my $r = $3; # row

        my $ix = $r * ($maxb+1) + $b;
        $table[$ix] = $a;

#        print "foozy a=$a b=$b r=$r ix=$ix\n";

    }
}


print "            b=0  b=1  b=2  b=3\n";
print "            ---  ---  ---  ---\n";

for (my $r = 0; $r<=$maxr; $r++) {

    #for (my $b=0; $b<=$maxb; $b++) {
       #my $ix = $r * ($maxb+1) + $b;
    my $ix = $r * ($maxb+1);


        printf("row %2d:     %2d   %2d   %2d   %2d\n", $r, $table[$ix+0], $table[$ix+1], $table[$ix+2], $table[$ix+3]);

#    }

    #print "$row\n";
}

