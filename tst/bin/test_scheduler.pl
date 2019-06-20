#!/usr/bin/perl
## Copyright 2013, all rights reserved.
## See below (end of file) for extended copyright information.
##
#!/usr/bin/perl
use strict;

##############################################################
# To use:
#    $0 > tmp0
#    grep -i err tmp0

##############################################################
# FIXME use /home/steveri/fftgen/rtl/fft_scheduler.pm
# push (@INC, "/home/steveri/fftgen/rtl/tmp-scheduler-debug");
# push (@INC, "/home/steveri/fftgen/rtl/dev");
# push (@INC, "/home/steveri/fftgen/rtl/");

my $rtldir = mydir("../rtl");  # Script lives in $FFTGEN/bin;
push (@INC, "$rtldir/");       # scheduler lives in $FFTGEN/rtl
require fft_scheduler;

##############################################################
fft_scheduler::DBG_ON();

#fft_scheduler::test_gen_indices(128,4);
#exit 0;

foreach my $npoints (8,16,32,64,128,256,512,1024) {
    foreach my $nunits (1,2,4) {
        if (($npoints==8)&&($nunits==4)) { next; }
        fft_scheduler::fft_schedule($npoints, $nunits, "reschedule");
    }
}
exit 0;

##############################################################################
# fft_scheduler::fft_schedule(1028,2, "resched");
# print "==============================================================================\n";
# exit;
# 
# fft_scheduler::fft_schedule(16,1, "resched");
# print "==============================================================================\n";
# fft_scheduler::fft_schedule(16,2, "resched");
# print "==============================================================================\n";
# fft_scheduler::fft_schedule(16,4, "resched");
# 
# @fft_scheduler::fft_sched = fft_scheduler::fft_schedule(16, 4, "reschedule");
# print "hello\n";
# print "\n";
# for (my $i=0; $i <  @fft_scheduler::fft_sched; $i++) {
#     
#     my $bufnum1 = @fft_scheduler::fft_sched[$i]->{op1_buffer};
#     my $bufnum2 = @fft_scheduler::fft_sched[$i]->{op2_buffer};
#     my $bufacc1 = @fft_scheduler::fft_sched[$i]->{op1_buffer_access};
#     my $bufacc2 = @fft_scheduler::fft_sched[$i]->{op2_buffer_access};
#     
#     printf("//FOOG $i op1_buffer=$bufnum1 op2_buffer=$bufnum2 ".
#            "op1_buffer_access=$bufacc1 op2_buffer_access=$bufacc2\n");
# }
# 
sub mydir {
    my $offset = shift;  # E.g. "../rtl"

    # Return full path of directory where this script lives, offset according to $offset.
    use Cwd 'abs_path';
    my $fullpath = abs_path($0); # Full pathname of script e.g. "/foo/bar/opendesign.pl"

    use File::Basename 'fileparse';
    my ($filename, $dir, $suffix) = fileparse($fullpath);
    return abs_path("$dir/$offset");
}
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
