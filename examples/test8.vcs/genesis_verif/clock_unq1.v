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
//  Source file: /nobackup/steveri/github/fftgen/tst/clock.vp
//  Source template: clock
//
// --------------- Begin Pre-Generation Parameters Status Report ---------------
//
//	From 'generate' statement (priority=5):
// Parameter RST_PERIOD 	= 1
// Parameter MAX_CYCLES 	= 18
// Parameter SIMULATOR 	= vcs
// Parameter CLK_PERIOD 	= 1000
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
// CLK_PERIOD (_GENESIS2_INHERITANCE_PRIORITY_) = 0x3e8
//
// RST_PERIOD (_GENESIS2_INHERITANCE_PRIORITY_) = 1
//
// MAX_CYCLES (_GENESIS2_INHERITANCE_PRIORITY_) = 18
//
// SIMULATOR (_GENESIS2_INHERITANCE_PRIORITY_) = vcs
//
// ---------------- End default Genesis2 parameter summary ----------------

////////////////////////////////////////////////////////////////////////
//module clock
module clock_unq1
  (output reg clk,
  input reset);
   
   parameter CLK_PERIOD = 1000;  // E.g. 5000 = 5ns
   parameter RST_PERIOD = 1;  // E.g. 20 (cycles)
   parameter MAX_CYCLES = 18;  // E.g. 10 (cycles), then call $finish

   int 		 clk_period;
   int 		 clk_half_period;
   int           nclocks;

   //if ($SIMULATOR eq "vcs") {
       // Build a vcd wave trace; to get mem signals also must do "simv +vcs+dumparrays"
       // DON'T need "+memcbk" on vcs cmd line :(
       initial begin
         $dumpon;
         $dumpvars;
         $dumpfile("fft.vcd");
       end

   //}
   initial begin
      $display("\nclock.vp: BEGIN STUPID SIMULATION THINGY\n");

      clk   = 1'b0;
      $display("\nclock.vp: BEGIN clk=%d \n", clk);
      $display("\nclock.vp: BEGIN reset=%d \n", reset);
      calibrate_clk;
      fork
	 do_clk;
      join_none
   end

   // Task to read runtime clock period argument if any
   task calibrate_clk;
      clk_period = CLK_PERIOD;
      clk_half_period = clk_period / 2;
      
      if ($test$plusargs("clk_period")) begin
	 $value$plusargs("clk_period=%g",clk_period);
	 clk_half_period = clk_period / 2 ;
      end
      
      if (clk_period < 100) begin
	      $display("clock.vp: ERROR: Clock period %1d too small, Try again", clk_period);
	      $finish(2);
      end else begin
	$display("clock.vp: Using clock period= %1d ns\n", clk_period/1000) ;
      end
   endtask // calibrate_clk

   // task to toggle clk
   task do_clk;
      while (1) begin // Endless loop(ends when reach MAX_CYCLES).
         if (clk == 0) begin
            if (nclocks == MAX_CYCLES) begin
               $display("\n\nclock.vp: ENDING AFTER %1d CLOCKS time=%1d ps,  ncy=%1d\n\n", MAX_CYCLES, $time, nclocks);
               $finish;
            end
            nclocks++;
         end
	 #clk_half_period clk = ~clk;
      end
   endtask // do_clk
   
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