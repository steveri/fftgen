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

#################################################################################
## MIT License
## 
## Copyright (c) 2013 Stephen E. Richardson and Stanford University
## 
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is
## furnished to do so, subject to the following conditions:
## 
## The above copyright notice and this permission notice shall be included in all
## copies or substantial portions of the Software.
## 
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IM-
## PLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
## FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
## COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
## IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNEC-
## TION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
## 
## For more information please contact
## Stephen E. Richardson  steveri@stanford.edu (Stanford University)
## Prof. Mark Horowitz   horowitz@stanford.edu (Stanford University)
#################################################################################
