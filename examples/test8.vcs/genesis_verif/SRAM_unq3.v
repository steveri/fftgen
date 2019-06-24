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
// Parameter nwords 	= 2
// Parameter data_width 	= 64
// Parameter SRAM_TYPE 	= TRUE_1PORT
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
// nwords (_GENESIS2_INHERITANCE_PRIORITY_) = 2
//
// SRAM_TYPE (_GENESIS2_INHERITANCE_PRIORITY_) = TRUE_1PORT
//
// data_width (_GENESIS2_INHERITANCE_PRIORITY_) = 64
//
// test_mode (_GENESIS2_INHERITANCE_PRIORITY_) = TEST5
//
// ---------------- End default Genesis2 parameter summary ----------------

////////////////////////////////////////////////////////////////////////
// module SRAM_unq3
//
// Usage: SRAM(n_words), where
//
//   nwords is the number of (32-bit) words in the SRAM.
   


// WARNING test_mode "TEST5" is setting data_width to 64

module SRAM_unq3
(clk_i, ez_i, wz_i, addr_i, rd_data_o, wr_data_i);

   input  logic clk_i;
   input  logic ez_i;             // Active low chip select
   input  logic wz_i;             // Active low write control
   input  logic [0:0] addr_i;     // Address bus

   output logic [63:0] rd_data_o; // Read data OUT.
   input  logic [63:0] wr_data_i; // Write data IN.

   reg [63:0] mem[0:1];           // memory cells

/* FIXME not the right place to check for cheats maybe
   // Testing and verification - no cheating on 1port configs!
   reg                     wz_at_posedge_clk;
   reg                     ez_at_posedge_clk;
   reg                     wz_at_wz;
   reg                     ez_at_ez;

   integer           i;

   // True one-port SRAM cannot read and write at the same time.
   // 
   // To prove that we're not cheating (e.g. double pumping), want to verify
   // that ez and wz DO NOT CHANGE during the course of a clock cycle.

   // Verify that ez does not change throughout complete clock cycle
   always @(posedge clk_i) #1 ez_at_posedge_clk = ez_i;
   always @(ez_i)          #1 ez_at_ez = ez_i;

   // Verify that wz does not change throughout complete clock cycle
   always @(posedge clk_i) #1 wz_at_posedge_clk = wz_i;
   always @(wz_i)          #1 wz_at_wz = wz_i;

   always @ (clk_i or ez_i or wz_i) begin
      if ($time > 500) begin // Skip first clock cycle to get past initialization weirdness...
         // Must use '===' (below) because '==' fails if either (or both) are 'x'
         ez_check: assert (ez_at_posedge_clk === ez_at_ez) else
                   $fatal("ERROR SRAM is trying to cheat (ez)!");
         wz_check: assert (wz_at_posedge_clk === wz_at_wz) else
                   $fatal("ERROR SRAM is trying to cheat (wz)!");
      end
   end
*/
   //////////////////////////////////////////////////////////////////////////////
   // READ
   assign rd_data_o = (~ez_i & wz_i) ? mem[addr_i] : 'x;  // READ TRUE_1PORT

   // READ DEBUG
   // READ INFO (historical) (also for analyze_reads_and_writes.pl -d9)
   always @(ez_i or wz_i or addr_i) if (~ez_i & wz_i) begin
      $display("%m %1d: ez_i=%1d and wz_i=%1d", $time, ez_i, wz_i);
      $display("%m %1d: Reading rd_data_o mem[%1d] <= %16x", $time, addr_i, rd_data_o);
      $display("SRAM002 t5 %5d: Read(f) wr_data_i mem[%1d] <= (bsr'%08X,bsr'%08X)", 
                       $time, addr_i, rd_data_o[63:32], rd_data_o[31: 0]);
      $display("");
   end

   //  sync sram see http://www.asic-world.com/examples/verilog/ram_sp_sr_sw.html
   // async sram see http://www.asic-world.com/examples/verilog/ram_sp_ar_aw.html

   //////////////////////////////////////////////////////////////////////////////
   // WRITE TRUE_1PORT
   // FIXME use a proper async SRAM (see above)!!! fiddle w/signals outside, in wrapper :(
   // 
   // always @(ez_i or wz_i) begin // doesn't work for verilator
   // always @(ez_i or wz_i) begin // NOT AN EDGE!!!!!!!!!
   //
   always @(negedge wz_i) begin // trial/error debugging - saw behavior on (correct) vcs wave
      if (~ez_i & ~wz_i) begin

         // WRITE TRUE_1PORT
         mem[addr_i] <= wr_data_i;

         // WRITE DEBUG
         $display("%m %1d: ez_i=%1d and wz_i=%1d", $time, ez_i, wz_i);
         $display("%m %1d: Wrote   wr_data_i mem[%1d] <= %16x", $time, addr_i, wr_data_i);
         $display("SRAM002 t5 %5d: Wrote(f) wr_data_i mem[%1d] <= (bsr'%08X,bsr'%08X)",
                       $time, addr_i, wr_data_i[63:32], wr_data_i[31: 0]);
         $display("");
      end
   end
    

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
