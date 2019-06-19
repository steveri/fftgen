#!/usr/bin/perl
use strict;
$| = 1; # Autoflush output why not.

my %sram_map;  # E.g. $sram_map{SRAM001} = "dp5"
my ($mem,$dir);
my $prevcy = "001500";
my $appendix = "";

my $stagenum = -1;
my $least_dpnum = 99999;

foreach my $line (<STDIN>) {
    ($mem,$dir) = ("mem1w","->"); # Default is write because why not.
    if ($line =~ /IGNORE/) { next; }
    if ($line =~ /DBG3/)   { print "IGNORE $line"; $appendix .= "z$line"; next; }
    if ($line =~ /out is/) { print "IGNORE $line"; $appendix .= "z$line"; next; }
    if ($line =~ /twid.*xxxxxx/) { next; }

    if ($line =~ /read/) { ($mem,$dir) = ("mem2r","<-"); }

    my ($cynum,$dpnum,$sram) = ("","","");
    if ($line =~ /([0-9]*) Bypassed SRAM (.*),.*(read|wrote).*bypassed_data.([0-9]*)/) {
        my ($s,$rw,$bb) = ($2,$3,$4);
        $cynum = sprintf("%06d", $1);
        my $sname = sprintf("SRAM%03d", $s);
        $dpnum = $sram_map{$sname};
        $sram = "BBUF$bb  ";
        $mem = ($rw eq "read") ? "byp2r" : "byp1w";
    }
    elsif ($line =~ /DBG.-ix(.*) FINAL ([0-9]*) .*(SRAM...)/) {
        if ($prevcy ne $2) { print "sort $prevcy LINEBREAK\n"; }
        $prevcy = $2;
        ($dpnum,$cynum,$sram) = ($1,$2,$3);
        $sram_map{$sram} = $dpnum;
    }
    elsif ($line =~ /([0-9]*): BFLY.*twid.*[(](.*)[)]$/) {
        $cynum = sprintf("%06d", $1);
        my $twid=sprintf("%6.3f", $2);

        if ($least_dpnum == 0) {
#             print "FOO stagenum was $stagenum\n";
            $stagenum++;
#             print "FOO now stagenum is $stagenum\n";
        }
#         my $d = sprintf("dp%02d", $least_dpnum);
        my $d = sprintf("dp%d", $least_dpnum);

        print "sort $cynum twiddle s$stagenum/$d: $twid   -- $line";
        $least_dpnum = 99999; # Reset least_dpnum
        next;
    }

    else { next; }

#     print "FOO dpnum is $dpnum and ld is $least_dpnum\n";

    if ($line =~ /read/) {
        if ($dpnum < $least_dpnum) { $least_dpnum = $dpnum; }
    }

    print "sort $cynum $mem dp$dpnum $dir $sram     -- $line";
}

# print $appendix;

