package swizzle;
use strict;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK);

use Exporter;
use FileHandle;
use Env; # Make environment variables available


use Genesis2::Manager 1.00;
use Genesis2::UniqueModule 1.00;

@ISA = qw(Exporter Genesis2::UniqueModule);
@EXPORT = qw();
@EXPORT_OK = qw();
$VERSION = '1.0';
sub get_SrcSuffix {Genesis2::UniqueModule::private_to_me(); return ".vp";};
sub get_OutfileSuffix {Genesis2::UniqueModule::private_to_me(); return ".v"};
############################### Module Starts Here ###########################


  sub to_verilog{ 
      # START PRE-GENERATED TO_VERILOG PREFIX CODE >>>
      my $self = shift;
      
      print STDERR "$self->{BaseModuleName}->to_verilog: Start user code\n" 
	  if $self->{Debug} & 8;
      # <<< END PRE-GENERATED TO_VERILOG PREFIX CODE
	$self->SUPER::to_verilog('/nobackup/steveri/github/fftgen/rtl/swizzle.vp');
# START USER CODE FROM /nobackup/steveri/github/fftgen/rtl/swizzle.vp PARSED INTO PACKAGE >>>
# line 1 "/nobackup/steveri/github/fftgen/rtl/swizzle.vp"
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright 2013, all rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// See below (end of file) for extended copyright information.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '/* *****************************************************************************';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * Description:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * ------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * Given FFT of size n_fft_points, and given n_butterfly_units, assume four';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * single-ported SRAM banks for each butterfly unit and map input address';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * addr_i to non-conflicting output address row "rnum_o" in bank "bnum_o".';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * ';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * Refer to equation 5 of:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * Takala, J.H.; Jarvinen, T.S.; Sorokin, H.T.; , "Conflict-free';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * parallel memory access scheme for FFT processors," Circuits and';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * Systems, 2003. ISCAS \'03. Proceedings of the 2003 International';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' * Symposium on , vol.4, no., pp. IV-524- IV-527 vol.4, 25-28 May 2003';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' *';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ' */';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# push (@INC, "./rtl"); # Now this happens in "Makefile.local"
 require fftgen;        # log2(), iterate()
 require swizzler;      # swizzle()

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- Begin default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 # parameter() calls send default Genesis output to top of .v file

 my $nunits = parameter
    (Name=>'n_butterfly_units', Val=>1,
     Doc=>'Number of butterfly units.');
 
 my $npoints = parameter
    (Name=>'n_fft_points', Val=>32,
     Doc=>'Number of complex data values to process.');

 my $swizzle_algorithm = parameter
    (Name=>'swizzle_algorithm', Val=>"round7",
     List=>["round7", "mod_bn_combo", "takala"],
     Doc=>'round7 is the only one that works w new scheduler(!)');

 ########################################################################

print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// ---------------- End default Genesis2 parameter summary ----------------';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Usage: swizzle(n_butterfly_units, n_fft_points), where';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   n_butterfly_units is any power of two, but usually 1, 2 or 4 ish';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   n_fft_points can be any power of two greater than 8;';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Given FFT of size n_fft_points, and given n_butterfly_units, assume four';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// single-ported SRAM banks for each butterfly unit and map input address';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// addr_i to non-conflicting output address row "rnum_o" in bank "bnum_o".';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
##############################################################################
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Parameters:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 foreach my $p (@{$self->{ParametersList}}) {
     my $val = $self->{Parameters}->{$p}->{Val};
     my $doc = $self->{Parameters}->{$p}->{Doc};
     printf("//     %-20s %8s %s\n", $p, "($val)", $doc);
 }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
##############################################################################
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Derived values:';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
 
 my $nbanks = 4*$nunits;
 # For some reason the below bug-fix breaks when swizzle_alg is mod_bn_combo...?
 if ($swizzle_algorithm eq 'round7') { if ($nbanks > $npoints) { $nbanks = $npoints; } }
 my $awidth = fftgen::log2($npoints);
 my $bwidth = fftgen::log2($nbanks);
 my $rwidth = fftgen::log2($npoints/$nbanks);
 
 if ($rwidth < 1) { $rwidth = 1; }     # Need at least one bit!!!
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'module '; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } mname; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '  (';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   input  logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $awidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] addr_i,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   output logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $rwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] rnum_o,';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   output logic ['; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } $bwidth-1; print { $Genesis2::UniqueModule::myself->{OutfileHandle} } ':0] bnum_o';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   );';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
    print "   // npoints=$npoints, nbanks=$nbanks\n";
   #swizzle('VLOG', $npoints, $nbanks);
    swizzler::swizzle('VLOG', $npoints, $nbanks, $swizzle_algorithm);
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //Uncomment and tweak for a nice check of the alg as it runs.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //always @(addr_i) begin';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //   $display("b1=%1d (a0,a1,a3)=(%1d,%1d,%1d)", bnum_o[1], addr_i[0], addr_i[1], addr_i[3]);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //   $display("b0=%1d (a0,a2)=(%1d,%1d)",        bnum_o[0], addr_i[0], addr_i[2]);';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '   //end';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } 'endmodule';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# //; ##############################################################################
# //; # Local subroutines.
# //; #
# //; sub swizzle_ooh {
# //;     my $a = shift;    # unswizzled address of desired data
# //;
# //;     # swizzle('VLOG', $N, $Q) => prints verilog for calculating rnum, bnum; else
# //;     # swizzle($a, $N, $Q) => returns row and bank num corresponding to address "a"
# //;     # FIXME/TODO cite takala paper.
# //; 
# //;     my $N = shift;            # N = number of elements in FFT array
# //;     my $n = fftgen::log2($N); # n = log2(N)
# //; 
# //;     my $Q = shift;            # Q = number of memory modules
# //;     my $q = fftgen::log2($Q); # q = log2(Q)
# //; 
# //;     # For VLOG only
# //;     my $npoints = $N; my $nbanks = $Q;
# //;     my $awidth = fftgen::log2($npoints);
# //;     my $bwidth = fftgen::log2($nbanks);
# //;     my $rwidth = fftgen::log2($npoints/$nbanks);
# //; 
# //;     my $LDBG  = 0; my $DBG9 = 0;
# //;     # Uncomment to debug this sub:
# //;     # my $LDBG  = 1; my $DBG9  = 1;
# //; 
# //;     # Use top (n-q) bits for row address within a given memory bank, i.e.:
# //;     #
# //;     # nrows = log2(N) - log2(Q), i.e.
# //;     #     1024 points spread over four memory banks => (10-2) = eight bits (256 rows/bank)
# //;     #       32 points spread over four memory banks => ( 5-2) = three bits (8 rows/bank)
# //;     #       16 points spread over four memory banks => ( 4-2) = two bits (4 rows/bank)
# //;     #
# //;     # rownum = address >> q
# //;     #     1024 points spread over four memory banks => q=2 => top eight bits of address
# //;     #       32 points spread over four memory banks => q=2 => top three bits of address
# //;     #       16 points spread over four memory banks => q=2 => top two bits of address
# //; 
# //;     # "assign rnum_o = (addr_i >> 2);" Causes a lint error:
# //;     #         Lint-[CAWM-L] Width mismatch
# //;     #         genesis_verif/swizzle_unq1.v, 87
# //;     #           Continuous assignment width mismatch
# //;     #           1 bits (lhs) versus 3 bits (rhs).
# //;     #           Source info: assign rnum_o = (addr_i >> 2);  
# //;     # 
# //;     # Instead, do "assign rnum_o = addr_i[5:2]"
# //;     
# //;     if ($LDBG) { print "------------------------------------------------------------------------------\n"; }
# //; 
# //;     my $rownum;
# //;     if ($a eq 'VLOG') {
# //;     # For rownum, generate "addri[$abit:$q]" or, if $abit<$q, simply always use "1'b0".
# //;     my $abit = $awidth-1;
# //;     my $rownum = ($abit < $q) ? "1'b0" : sprintf("addr_i[%d:%d]", $abit, $q);
# //;
# //;     print "\n";
# //;     printf("   assign rnum_o = $rownum;\n");
# //;     print "\n";
# //;     }
# //;     else {
# //;     $rownum = $a >> $q;
# //;     if ($LDBG) { printf("  %2d (0x%04x) translates to row %2d (0x%04x)\n", $a, $a, $rownum, $rownum); }
# //;     }
# //; 
# //;     # Swizzle up the lower q bits to get the bank number
# //;     my $bank_num = 0;
# //; 
# //;     # for (my $i = 0; $i < $q; $i++) {
# //;     for (my $i = ($q-1); $i >= 0; $i--) {
# //;         #print "// i=$i n=$n q=$q\n";
# //;         my $nmodq = $n % $q;
# //;         my $gcd = gcd($q, $nmodq);  # Could alternatively use recursive "gcdr"
# //;         if ($DBG9) { printf("       n=$n; q=$q; n mod q=$nmodq; gcd($q, $nmodq) = $gcd\n"); }
# //; 
# //;         my $unfloored_thingy = ($n + $q - $gcd - $i - 1) / $q; #print "// u=$unfloored_thingy\n";
# //;         my $floored_thingy = int($unfloored_thingy);           #print "// f=$floored_thingy\n";
# //;         if ($DBG9) { printf("       u=$unfloored_thingy, floor(u)=$floored_thingy\n"); }
# //; 
# //;         if ($DBG9) { print "            jqi = ";  }
# //;         for (my $j=0; $j <= $floored_thingy; $j++) {
# //;             my $jqi = $j * $q + $i;
# //;             if ($DBG9) { print "$jqi,"; }
# //;         }
# //;         if ($DBG9) { print "\n"; }
# //; 
# //;         my @bits = ();
# //;         if ($DBG9) { print "            jqi mod n = ";  }
# //;         for (my $j=0; $j <= $floored_thingy; $j++) {
# //;             my $jqi = $j * $q + $i;
# //;             my $jqi_mod_n = $jqi % $n;
# //;             if ($DBG9) { print "$jqi_mod_n,"; }
# //;             push(@bits, $jqi_mod_n);
# //;         }
# //; 
# //;         if ($a eq 'VLOG') {
# //; 
# //; # Here's a fun hack!  (Didn't need after fixed a problem with the verilog test file).
# //; #        if (($n==4) && ($q==2)) {
# //; #            if ($i==0) { @bits=(0,2); }
# //; #            if ($i==1) { @bits=(0,1,3); }
# //; #        }
# //; 
# //;         my @bitstrings = ();
# //;         my @sortedbits = sort { my $a <=> $b } @bits;  # !!??$# sorts in descending numeric order !!?#%
# //;         foreach my $b (@sortedbits) { push(@bitstrings, "addr_i[$b]"); }
# //;         printf("   assign bnum_o[$i] = %s;\n", join(" ^ ", @bitstrings));
# //;         }
# //;         else {
# //; 
# //;         if ($DBG9) { print "\n"; }
# //;         if ($DBG9) { printf("            m_$i = xor(@bits) = %d\n", xorbits($a, @bits)); }
# //;         if ($DBG9) { print "\n\n"; }
# //; 
# //;         # Optional: generate verilog to do the swizzle.
# //;         # my @bitstrings = ();
# //;         # foreach my $b (@bits) { push(@bitstrings, "addr_i[$b]"); }
# //;         # printf("VLOG bnum_o[$i] = %s;\n", join("^", @bitstrings));
# //; 
# //;         $bank_num = $bank_num + (2**$i) * xorbits($a, @bits);
# //;         }
# //;     }
# //;     print "\n";
# //;     return;
# //; }
# //; 
# //; sub gcd {
# //;     # Find greatest common denominator of a and b
# //;     my $a = shift; my $b = shift;
# //;     if ($a == 0) { return $b; }
# //;     if ($b == 0) { return $a; }
# //;     for (my $i = $a; $i > 0; $i--) {
# //;         if (
# //;             (($a % $i) == 0) &&
# //;             (($b % $i) == 0)
# //;             ) {
# //;             return $i;
# //;         }
# //;     }
# //; }
# //; 
# //; 
# //; sub gcdr {
# //;     # Find greatest common denominator of a and b
# //;     my $a = shift; my $b = shift;
# //;     if ($a == 0) { return $b; }
# //;     if ($b == 0) { return $a; }
# //;     if ($a > $b) {
# //;         return gcdr($a % $b, $b);
# //;     } else {
# //;         return gcdr($a, $b % $a);
# //;     }
# //; }
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Copyright Stephen Richardson and Stanford University.  All rights reserved.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//              Exclusively Licensed by Chip Genesis Inc.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// The code, the algorithm, or any part of it is not to be copied/reproduced.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// The code, the algorithm, or results from running this code may not be used';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// for any commercial use unless legally licensed.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// For more information please contact';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   Ofer Shacham (Stanford Univ./Chip Genesis)   shacham@alumni.stanford.edu';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//   Professor Mark Horowitz (Stanford Univ.)     horowitz@stanford.edu';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '//';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// Genesis2 is patent pending. For information regarding the patent please';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '// contact the Stanford Technology Licensing Office.';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
print { $Genesis2::UniqueModule::myself->{OutfileHandle} } '///////////////////////////////////////////////////////////////////////////////';print { $Genesis2::UniqueModule::myself->{OutfileHandle} } "\n"; 
# <<< END USER CODE FROM /nobackup/steveri/github/fftgen/rtl/swizzle.vp PARSED INTO PACKAGE


      # START PRE-GENERATED TO_VERILOG SUFFIX CODE >>>
      print STDERR "$self->{BaseModuleName}->to_verilog: Done with user code\n" 
	  if $self->{Debug} & 8;

      #
      # clean up code comes here...
      #
      # <<< END PRE-GENERATED TO_VERILOG SUFFIX CODE
  }
