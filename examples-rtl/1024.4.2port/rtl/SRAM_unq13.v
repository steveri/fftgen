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
//  Source file: /nobackup/steveri/github/fftgen/rtl/SRAM.vp
//  Source template: SRAM
//
// --------------- Begin Pre-Generation Parameters Status Report ---------------
//
//	From 'generate' statement (priority=5):
// Parameter data_width 	= 64
// Parameter nwords 	= 64
// Parameter SRAM_TYPE 	= TRUE_2PORT
// Parameter test_mode 	= TEST5
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
// nwords (_GENESIS2_INHERITANCE_PRIORITY_) = 64
//
// SRAM_TYPE (_GENESIS2_INHERITANCE_PRIORITY_) = TRUE_2PORT
//
// data_width (_GENESIS2_INHERITANCE_PRIORITY_) = 64
//
// test_mode (_GENESIS2_INHERITANCE_PRIORITY_) = TEST5
//
// ---------------- End default Genesis2 parameter summary ----------------

////////////////////////////////////////////////////////////////////////
// module SRAM_unq13
//
// Usage: SRAM(n_words), where
//
//   nwords is the number of (32-bit) words in the SRAM.
   


// WARNING test_mode "TEST5" is setting data_width to 64

module SRAM_unq13
(clk_i, ez_i, wz_i, addr_i, rd_data_o, wr_data_i);

   input  logic clk_i;
   input  logic ez_i;             // Active low chip select
   input  logic wz_i;             // Active low write control
   input  logic [5:0] addr_i;     // Address bus

   output logic [63:0] rd_data_o; // Read data OUT.
   input  logic [63:0] wr_data_i; // Write data IN.

   reg [63:0] mem[0:63];           // memory cells

   // Only dpump uses clk_i; this may or may not be the best way to address that
   wire unused_ok; assign unused_ok = clk_i;

   // True 2-port SRAM *can* read and write at the same time.
   assign rd_data_o = (~ez_i) ? mem[addr_i] : 'x;            // READ TRUE_2PORT

   always @(ez_i or addr_i) if (~ez_i) begin
      // READ INFO (historical) (also for analyze_reads_and_writes.pl -d9)
      $display("%m %1d: ez_i=%1d and wz_i=%1d", $time, ez_i, wz_i);
      $display("%m %1d: Reading rd_data_o mem[%1d] <= %16x", $time, addr_i, rd_data_o);
      $display("SRAM012 t5 %5d: Read(f) wr_data_i mem[%1d] <= (bsr'%08X,bsr'%08X)", $time, addr_i, rd_data_o[63:32], rd_data_o[31: 0]);
      $display("");
   end

   //always @(ez_i or wz_i) //does not work for verilator
   always @(negedge wz_i) // will it...? it did!!!
      if (~ez_i & ~wz_i) begin                               // WRITE TRUE_2PORT
         mem[addr_i] <= wr_data_i;
         $display("%m %1d: ez_i=%1d and wz_i=%1d", $time, ez_i, wz_i);
         $display("%m %1d: Wrote   wr_data_i mem[%1d] <= %16x", $time, addr_i, wr_data_i);
         $display("SRAM012 t5 %5d: Wrote(f) wr_data_i mem[%1d] <= (bsr'%08X,bsr'%08X)", $time, addr_i, wr_data_i[63:32], wr_data_i[31: 0]);
         $display("");
      end

//   // This might keep lint from complaining that clk_i is "unused." NOPE
//   always @(posedge clk_i) assert (0==0);


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
