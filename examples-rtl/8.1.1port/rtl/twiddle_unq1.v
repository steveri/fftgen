//
//--------------------------------------------------------------------------------
//          THIS FILE WAS AUTOMATICALLY GENERATED BY THE GENESIS2 ENGINE        
//  FOR MORE INFORMATION: OFER SHACHAM (CHIP GENESIS INC / STANFORD VLSI GROUP)
//    !! THIS VERSION OF GENESIS2 IS NOT FOR ANY COMMERCIAL USE !!
//     FOR COMMERCIAL LICENSE CONTACT SHACHAM@ALUMNI.STANFORD.EDU
//--------------------------------------------------------------------------------
//
//  
//	-----------------------------------------------
//	|            Genesis Release Info             |
//	|  $Change: 11904 $ --- $Date: 2013/08/03 $   |
//	-----------------------------------------------
//	
//
//  Source file: /nobackup/steveri/github/fftgen/rtl/twiddle.vp
//  Source template: twiddle
//
// --------------- Begin Pre-Generation Parameters Status Report ---------------
//
//	From 'generate' statement (priority=5):
// Parameter units_per_cycle 	= 1
// Parameter n_fft_points 	= 8
// Parameter data_width 	= 32
//
//		---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
//
//	From Command Line input (priority=4):
//
//		---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
//
//	From XML input (priority=3):
//
//		---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
//
//	From Config File input (priority=2):
//
// ---------------- End Pre-Generation Pramameters Status Report ----------------

// Copyright 2013, all rights reserved.
// See below (end of file) for extended copyright information.
//
// ---------------- Begin default Genesis2 parameter summary ----------------
//
// n_fft_points (_GENESIS2_INHERITANCE_PRIORITY_) = 8
//
// units_per_cycle (_GENESIS2_INHERITANCE_PRIORITY_) = 1
//
// data_width (_GENESIS2_INHERITANCE_PRIORITY_) = 32
//
// ---------------- End default Genesis2 parameter summary ----------------

////////////////////////////////////////////////////////////////////////
// module twiddle_unq1
//
// Usage: twiddle(n_fft_points, units_per_cycle), where
//
//   n_fft_points can be any power of two greater than 8;
//   units_per_cycle can be 0.25, 0.5, 1.0, 2.0 or 4.0
//
// Example(s):  twiddle n=16 upc=1.0
//
// Parameters:
//     units_per_cycle           (1) Number active butterfly units per cycle (.25 means one unit at 1/4 speed)
//     data_width               (32) 32 for sp float (shortreal), 64 for dp (real)
//     n_fft_points              (8) Number of complex data values to process.
//
// Derived values:
// Building twiddles for ONE butterfly unit
// local_clock = global_clock/1
//    $timestep (1) = time it takes (cycles) for butterfly unit to complete one operation
//    $nunits   (1)   = number of butterfly units we have to build (four maximum)
//    $nlevels  (3)  = levels (columns) in the (virtual) bfly network
//    $ncalcs_per_unit (12) = total ncalcs to be performed by each bfly unit
//

// Will produce 3 levels (columns) in the (virtual) butterfly network.

module twiddle_unq1
  (
   //------------------------------------------------
   // begin twiddle->printwires('   ', 'io_list')
   input logic [3:0] cycle_num_i, // Counts from 0 to ncalcs/nunits(?) maybe

   // Twiddle factors for butterfly units
   output logic [31:0] BFLY0_twiddle_cos_o,
   output logic [31:0] BFLY0_twiddle_sin_o

   // end twiddle->printwires()
   //------------------------------------------------
   );
   
   //////////////////////////////////////////////////////////////////////////////
   // DECLARATIONS
   // 12 32-bit wide registers per butterfly unit.

   logic [31:0] BFLY0_twiddle_mem_cos[0:11];
   logic [31:0] BFLY0_twiddle_mem_sin[0:11];

/*
$shortrealtobits( 1.00000000e+00) = 32'h3f80_0000   
$shortrealtobits( 0.00000000e+00) = 32'h0000_0000
$shortrealtobits(-1.00000000e+00) = 32'hbf80_0000
$shortrealtobits( 7.07106781e-01) = 32'h3f35_04f3
$shortrealtobits( 6.12323400e-17) = 32'h248d_3132
$shortrealtobits(-7.07106781e-01) = 32'hbf35_04f3
*/
   //////////////////////////////////////////////////////////////////////////////////////
   // INIT BLOCKS
   initial begin

      /////////////////////////////////////////////////////////////////////////
      // Pre-load LUT with 32-bit twiddle factors for 8 FFT data points
      // using one butterfly unit.
      //------------------------------ Stage 0 ------------------------------//

      BFLY0_twiddle_mem_cos[ 0] = 32'h3f80_0000;  //  1.000
      BFLY0_twiddle_mem_sin[ 0] = 32'h0000_0000;  //  0.000

      BFLY0_twiddle_mem_cos[ 1] = 32'h3f80_0000;  //  1.000
      BFLY0_twiddle_mem_sin[ 1] = 32'h0000_0000;  //  0.000

      BFLY0_twiddle_mem_cos[ 2] = 32'h3f80_0000;  //  1.000
      BFLY0_twiddle_mem_sin[ 2] = 32'h0000_0000;  //  0.000

      BFLY0_twiddle_mem_cos[ 3] = 32'h3f80_0000;  //  1.000
      BFLY0_twiddle_mem_sin[ 3] = 32'h0000_0000;  //  0.000

      //------------------------------ Stage 1 ------------------------------//

      BFLY0_twiddle_mem_cos[ 4] = 32'h3f80_0000;  //  1.000
      BFLY0_twiddle_mem_sin[ 4] = 32'h0000_0000;  //  0.000

      BFLY0_twiddle_mem_cos[ 5] = 32'h3f80_0000;  //  1.000
      BFLY0_twiddle_mem_sin[ 5] = 32'h0000_0000;  //  0.000

      BFLY0_twiddle_mem_cos[ 6] = 32'h248d_3132;  //  0.000
      BFLY0_twiddle_mem_sin[ 6] = 32'hbf80_0000;  // -1.000

      BFLY0_twiddle_mem_cos[ 7] = 32'h248d_3132;  //  0.000
      BFLY0_twiddle_mem_sin[ 7] = 32'hbf80_0000;  // -1.000

      //------------------------------ Stage 2 ------------------------------//

      BFLY0_twiddle_mem_cos[ 8] = 32'h3f80_0000;  //  1.000
      BFLY0_twiddle_mem_sin[ 8] = 32'h0000_0000;  //  0.000

      BFLY0_twiddle_mem_cos[ 9] = 32'h248d_3132;  //  0.000
      BFLY0_twiddle_mem_sin[ 9] = 32'hbf80_0000;  // -1.000

      BFLY0_twiddle_mem_cos[10] = 32'h3f35_04f3;  //  0.707
      BFLY0_twiddle_mem_sin[10] = 32'hbf35_04f3;  // -0.707

      BFLY0_twiddle_mem_cos[11] = 32'hbf35_04f3;  // -0.707
      BFLY0_twiddle_mem_sin[11] = 32'hbf35_04f3;  // -0.707

   end

   assign BFLY0_twiddle_cos_o = BFLY0_twiddle_mem_cos[cycle_num_i];
   assign BFLY0_twiddle_sin_o = BFLY0_twiddle_mem_sin[cycle_num_i];

endmodule

//////////////////////////////////////////////////////////////////////////////
// Copyright Stephen Richardson and Stanford University.  All rights reserved.
//              Exclusively Licensed by Chip Genesis Inc.
//
// The code, the algorithm, or any part of it is not to be copied/reproduced.
// The code, the algorithm, or results from running this code may not be used
// for any commercial use unless legally licensed.
//
// For more information please contact
//   Ofer Shacham (Stanford Univ./Chip Genesis)   shacham@alumni.stanford.edu
//   Professor Mark Horowitz (Stanford Univ.)     horowitz@stanford.edu
//
// Genesis2 is patent pending. For information regarding the patent please
// contact the Stanford Technology Licensing Office.
///////////////////////////////////////////////////////////////////////////////
