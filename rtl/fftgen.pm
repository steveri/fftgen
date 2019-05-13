## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
package fftgen;

sub log2 {
    my $n = shift @_;
    if ($n==1) { return 0; }
    my $result = 1; while ( (2**$result) < $n ) { $result++; }
    return $result;
}

sub iterate {
    # E.g.
    #   print fftgen::iterate(4
    #       "   logic [$obits] BFLY%d_in1_data;   ",
    #       "   logic [$obits] BFLY%d_in2_data;\n");
    # yields
    #   logic [63:0] BFLY0_in1_data;      logic [63:0] BFLY0_in2_data;
    #   logic [63:0] BFLY1_in1_data;      logic [63:0] BFLY1_in2_data;
    #   logic [63:0] BFLY2_in1_data;      logic [63:0] BFLY2_in2_data;
    #   logic [63:0] BFLY3_in1_data;      logic [63:0] BFLY3_in2_data;

    #my ($begin, $end, $step) = (shift, shift, shift);
    my $n = shift;
    my @format_strings = @_;
    my $rval = "";

    for (my $i=0; $i<$n; $i++) {
        foreach my $fmt (@format_strings) {
            my $s = sprintf($fmt, $i);
            $rval = $rval.$s;
        }
    }
    return $rval;
}

sub printparm {
    # Print a beautiful port connection for an instance.
    # E.g. printparm("   ", "rfsel", "_o", "// bank select for register file(s)");
    # Prints "   .rfsel_o(rfsel), // bank select for register file(s)"
    my $indent = shift @_;

    my $parm = shift @_;      # e.g. "rfsel" or "clk"
    my $sfx = shift @_;       # Usually "_i" or "_o"
    my $comm = shift @_;      # Comment, e.g. "// register select"
    my $no_comma = shift @_;  # 1 for terminate-with-comma, else 0
    my $comma = $no_comma ? "" : ",";

    my $local = $parm;        # E.g. "clk"
    my $remote = $parm.$sfx;  # E.g. "clk_i"

    printf($indent."%-20s %s\n", ".$remote($local)$comma", $comm);
}

# All .pm packages must end in "1"...because perl is so stoopid...
1;
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
