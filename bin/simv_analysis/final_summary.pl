#!/usr/bin/perl
use strict;
$| = 1; # Autoflush output why not.

my %sram_map;  # E.g. $sram_map{SRAM001} = "dp5"
my ($mem,$dir);
my $prevcy = "001500";
foreach my $line (<STDIN>) {
    ($mem,$dir) = ("mem1w","->"); # Default is write because why not.
    if ($line =~ /IGNORE/) { next; }
    if ($line =~ /DBG3/) { print "z$line"; next; }
    if ($line =~ /out is/) { print "z$line"; next; }
    if ($line =~ /read/) { ($mem,$dir) = ("mem2r","<-"); }


    my ($cynum,$dpnum,$sram) = ("","","");
    if ($line =~ /([0-9]*) Bypassed SRAM (.*),.*(read|wrote).*bypassed_data.([0-9]*)/) {
        my ($s,$rw,$bb) = ($2,$3,$4);
        $cynum = sprintf("%06d", $1);
        my $sname = sprintf("SRAM%03d", $s);
        $dpnum = $sram_map{$sname};
        $sram = "BBUF$bb  ";
        $mem = ($rw eq "read") ? "byp2r" : "byp1w";
#         print "sort $cynum $sram_map{$sram}   -- $line";
    }
    if ($line =~ /DBG.-ix(.*) FINAL ([0-9]*) .*(SRAM...)/) {
        if ($prevcy ne $2) { print "sort $prevcy\n"; }
        $prevcy = $2;
        ($dpnum,$cynum,$sram) = ($1,$2,$3);
#        print "sort $2 $mem dp$1 $dir $3     -- $line";
        $sram_map{$sram} = $dpnum;
    }
        print "sort $cynum $mem dp$dpnum $dir $sram     -- $line";
}
