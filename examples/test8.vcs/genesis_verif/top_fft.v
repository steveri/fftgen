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
//  Source file: /nobackup/steveri/github/fftgen/tst/top_fft.vp
//  Source template: top_fft
//
// --------------- Begin Pre-Generation Parameters Status Report ---------------
//
//	From 'generate' statement (priority=5):
//
//		---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
//
//	From Command Line input (priority=4):
// Parameter SRAM_TYPE 	= TRUE_1PORT
// Parameter SIMULATOR 	= vcs
// Parameter n_fft_points 	= 8
// Parameter swizzle_algorithm 	= round7
// Parameter units_per_cycle 	= 1
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
// n_fft_points (_GENESIS2_CMD_LINE_PRIORITY_) = 8
//
// units_per_cycle (_GENESIS2_CMD_LINE_PRIORITY_) = 1
//
// SRAM_TYPE (_GENESIS2_CMD_LINE_PRIORITY_) = TRUE_1PORT
//
// op_width (_GENESIS2_IMMUTABLE_PRIORITY_) = 64
//
// swizzle_algorithm (_GENESIS2_CMD_LINE_PRIORITY_) = round7
//
// test_mode (_GENESIS2_IMMUTABLE_PRIORITY_) = TEST5
//
// SIMULATOR (_GENESIS2_CMD_LINE_PRIORITY_) = vcs
//
// ---------------- End default Genesis2 parameter summary ----------------


// Generating clock unit clock/GCLK (vcs only)...

// Generating fftctl unit fftctl/fftctl (nunits = 1, npoints=8)...

// Generating twiddle unit twiddle/twiddle (nunits = 1, npoints=8)...

// Generating swizzle units swizzle/BFLY[0123]_{in,out}[12]_swizzle...

// Generating fft ram fftram/fftram...

// Generating butterfly unit(s), test mode TEST5...

module top_fft();
   // BEGIN WIRE DECLARATIONS

   //------------------------------------------------
   // begin fftctl->printwires('   ', 'wire_list')

   logic  clk;   // Clock
   logic  rst_n; // Reset signal per power-up
   logic  start; // Start signal per FFT

   // Butterfly unit operands
   logic [2:0] BFLY0_op1_ix; 
   logic [2:0] BFLY0_op2_ix; 

   // Per-butterfly access type
   logic [2:0] BFLY0_access_type; 

   // Remaining output signals
   logic [4:0] fftctl_cycle_num; // 0, 1, 2, ...
   logic       busy;          // hi while busy computing fft
   logic       fftclk;          // local_clk = global_clk/1
   
   // Bypass controls
   logic [3:0] suppress_wz;  // one bit per bank, set 100 ps after posedge
   logic [3:0] bypass_read;  // one bit per bank, set 100 ps after posedge
   logic       bufnum[0:3];           // which buffer do we use for bypass (per bank)?

   // end fftctl->printwires()
   //------------------------------------------------

   // FIXME FIXME cycle_num below different than cycle_num signals in fftram, fftctl !!! :(
   //------------------------------------------------
   // begin twiddle->printwires('   ', 'wire_list')
   logic [4:0] cycle_num; // Counts from 0 to ncalcs/nunits(?) maybe

   // Twiddle factors for butterfly units
   logic [31:0] BFLY0_twiddle_cos;
   logic [31:0] BFLY0_twiddle_sin;

   // end twiddle->printwires()
   //------------------------------------------------

   // in1, in2 data from fftram to butterfly unit
   logic [63:0] BFLY0_in1_data;      logic [63:0] BFLY0_in2_data;

   // out1, out2 data from butterfly unit to fftram
   logic [63:0] BFLY0_out1_data;     logic [63:0] BFLY0_out2_data;

   // Swizzle-wires for op1, op2 bank num
   logic [1:0] BFLY0_op1_bnum;      logic [1:0] BFLY0_op2_bnum;

   // Swizzle-wires for op1, op2 row num
   logic [0:0] BFLY0_op1_rnum;      logic [0:0] BFLY0_op2_rnum;

   // END WIRE DECLARATIONS

   // Because fftctl calls it one thing and twiddle calls it something else.
   assign cycle_num = fftctl_cycle_num;

   // *Verilator* don't know from no $shortrealtowhatever
   // So instead of $shortrealtobits(1) we get...
   logic [31:0] _shortrealtobits_0 = 32'h0000_0000;
   logic [31:0] _shortrealtobits_1 = 32'h3f80_0000;

   initial begin
      // Generate a square wave to test the FFT, e.g.:
      // @a_real = (1, 0, 1, 0,  1, 0, 1, 0);    // bitreverse(1,1,1,1,  0,0,0,0)
      // @a_imag = (0, 0, 0, 0,  0, 0, 0, 0);

      // ix=00 => bank 0, row 0 <= ( 1.000,  0.000)
      top_fft.fftram.SRAM000.mem[0][63:32] = _shortrealtobits_1;
      top_fft.fftram.SRAM000.mem[0][31: 0] = _shortrealtobits_0;

      // ix=01 => bank 1, row 0 <= ( 0.000,  0.000)
      top_fft.fftram.SRAM001.mem[0][63:32] = _shortrealtobits_0;
      top_fft.fftram.SRAM001.mem[0][31: 0] = _shortrealtobits_0;

      // ix=02 => bank 2, row 0 <= ( 1.000,  0.000)
      top_fft.fftram.SRAM002.mem[0][63:32] = _shortrealtobits_1;
      top_fft.fftram.SRAM002.mem[0][31: 0] = _shortrealtobits_0;

      // ix=03 => bank 3, row 0 <= ( 0.000,  0.000)
      top_fft.fftram.SRAM003.mem[0][63:32] = _shortrealtobits_0;
      top_fft.fftram.SRAM003.mem[0][31: 0] = _shortrealtobits_0;

      // ix=04 => bank 1, row 1 <= ( 1.000,  0.000)
      top_fft.fftram.SRAM001.mem[1][63:32] = _shortrealtobits_1;
      top_fft.fftram.SRAM001.mem[1][31: 0] = _shortrealtobits_0;

      // ix=05 => bank 0, row 1 <= ( 0.000,  0.000)
      top_fft.fftram.SRAM000.mem[1][63:32] = _shortrealtobits_0;
      top_fft.fftram.SRAM000.mem[1][31: 0] = _shortrealtobits_0;

      // ix=06 => bank 3, row 1 <= ( 1.000,  0.000)
      top_fft.fftram.SRAM003.mem[1][63:32] = _shortrealtobits_1;
      top_fft.fftram.SRAM003.mem[1][31: 0] = _shortrealtobits_0;

      // ix=07 => bank 2, row 1 <= ( 0.000,  0.000)
      top_fft.fftram.SRAM002.mem[1][63:32] = _shortrealtobits_0;
      top_fft.fftram.SRAM002.mem[1][31: 0] = _shortrealtobits_0;

   end

   initial begin
      $display("\nfftmem.vp: n_butterfly_units=1 and n_fft_points=8\n");
   end

   // Generate clock and connect it to local wire ".clk" (vcs only)
   clock_unq1  GCLK(.clk(clk), .reset(rst_n));       // .remote(local)

   // Instantiate swizzle units BFLY0_op1_swizzle, BFLY0_op2_swizzle etc.
   swizzle_unq1  BFLY0_op1_swizzle(.addr_i(BFLY0_op1_ix), .rnum_o(BFLY0_op1_rnum), .bnum_o(BFLY0_op1_bnum));
   swizzle_unq1  BFLY0_op2_swizzle(.addr_i(BFLY0_op2_ix), .rnum_o(BFLY0_op2_rnum), .bnum_o(BFLY0_op2_bnum));

   // Swizzler translation guide.
   always @(posedge fftclk) if (cycle_num > 0) begin
      $display("");
      $display("top_fft swizzle %5d: BFLY0_op1 ix%02d => SRAM%03d mem[%02d]", $time, BFLY0_op1_ix, BFLY0_op1_bnum, BFLY0_op1_rnum);
      $display("top_fft swizzle %5d: BFLY0_op2 ix%02d => SRAM%03d mem[%02d]", $time, BFLY0_op2_ix, BFLY0_op2_bnum, BFLY0_op2_rnum);
      $display("");
   end
               
    // In TEST0 mode, all operands == 1 to start, bfly unit adds out = in1 + in2,
    // so that, at end, all locations should equal (npoints/2).  Magic!
    butterfly_unq1  BFLY0(.fftclk(fftclk),
                               .ready(~rst_n & (busy|start)), // .remote(local)
                               .in1(BFLY0_in1_data),
                               .in2(BFLY0_in2_data),
                               .twc(BFLY0_twiddle_cos),
                               .tws(BFLY0_twiddle_sin),
                               .out1(BFLY0_out1_data),
                               .out2(BFLY0_out2_data)
                               );

   // DEBUG/TEST info: twiddle_cos, apparently.
   always @(posedge fftclk) if (~rst_n) begin
      $display("");
      $display("top_fft %5d: BFLY0_twiddle_cos = %x (bsr'%08X)",
               $time, BFLY0_twiddle_cos, BFLY0_twiddle_cos);
      $display("");
   end

   // DEBUG/TEST info: show swizzle translations.
   // FIXME I think this is supposed to be "negedge fftclk..?"
   // FIXME originally displayed at 602, 1602, 2602,...right???
   always @ (fftclk) if (fftclk==1) begin   // 602,1602,2602...(?)
      $display("top_fft %1d: BFLY0_op1 ix %02d comes from bank %2d row %3d", $time,
               BFLY0_op1_ix, BFLY0_op1_bnum, BFLY0_op1_rnum);
      $display("top_fft %1d: BFLY0_op2 ix %02d comes from bank %2d row %3d", $time,
               BFLY0_op2_ix, BFLY0_op2_bnum, BFLY0_op2_rnum);
      $display("top_fft");
   end // always @ (posedge fftclk)



   // Instantiate the fft memory and connect to it..
   fftram_unq1  fftram  // .remote(local)
      (
       .clk_i(fftclk)

     // op1, op2 addresses from fftram (bnum)
     ,.BFLY0_op1_bnum_i(BFLY0_op1_bnum)        ,.BFLY0_op2_bnum_i(BFLY0_op2_bnum)

     // op1, op2 addresses from fftram (rnum)
     ,.BFLY0_op1_rnum_i(BFLY0_op1_rnum)        ,.BFLY0_op2_rnum_i(BFLY0_op2_rnum)

     // Data OUT from fftram (and in) to butterfly units: in1, in2
     ,.BFLY0_in1_data_o(BFLY0_in1_data)         ,.BFLY0_in2_data_o(BFLY0_in2_data)

     // Data IN from butterfly units (and out) to fftram: out1, out2
     ,.BFLY0_out1_data_i(BFLY0_out1_data)      ,.BFLY0_out2_data_i(BFLY0_out2_data)

     // Bypass controls
     ,.suppress_wz_i(suppress_wz)  // one bit per bank, set 100 ps after posedge

     ,.fft_started(busy | start)
     );


   // Per-test display info for debugging.
   always @(posedge fftclk) if (busy | start) begin
         $display("top_fft t5");
         $display("top_fft t5 %5d: in1(r,i)= (bsr'%08X,bsr'%08X)", $time, BFLY0_in1_data[63:32], BFLY0_in1_data[31: 0]);
         $display("top_fft t5 %5d: in2(r,i)= (bsr'%08X,bsr'%08X)", $time, BFLY0_in2_data[63:32], BFLY0_in2_data[31: 0]);
         $display("top_fft t5");
         $display("top_fft t5 %5d: tw_cos  =     bsr'%08X", $time, BFLY0_twiddle_cos);
         $display("top_fft t5 %5d: tw_sin  =     bsr'%08X", $time, BFLY0_twiddle_sin);
         $display("top_fft t5");
         $display("top_fft t5 %5d: out1(r,i)= (bsr'%08X,bsr'%08X)", $time, BFLY0_out1_data[63:32], BFLY0_out1_data[31: 0]);
         $display("top_fft t5 %5d: out2(r,i)= (bsr'%08X,bsr'%08X)", $time, BFLY0_out2_data[63:32], BFLY0_out2_data[31: 0]);
         $display("top_fft t5");
   end

   // FFT control signals and clock.
   fftctl_unq1  fftctl
     (                                                       // .remote(local)
      // begin fftctl->printconnections()
      .clk_i(clk),           // Clock
      .rst_n_i(rst_n),     // Reset signal per power-up
      .start_i(start),     // Start signal per FFT

      // Indices for where bfly should fetch from array of data point
      .BFLY0_op1_ix_o(BFLY0_op1_ix),
      .BFLY0_op2_ix_o(BFLY0_op2_ix),


      /////////////////////////////////////////////////////////////////////
      // Access type: 0="SRAM"
      // 1="op1 from buf", 2="op2 from buf", 3="op1 to buf", 4="op2 to buf"

      .BFLY0_access_type_o(BFLY0_access_type),


      // Other output signals

      .fftctl_cycle_num_o(fftctl_cycle_num), // 0, 1, 2, ...
      .busy_o(busy),                // hi while busy computing fft
      .fftclk_o(fftclk),            // local_clk = global_clk/1
      
      // Bypass controls
      .suppress_wz_o(suppress_wz),  // one bit per bank, set 100 ps after posedge
      .bypass_read_o(bypass_read),  // one bit per bank, set 100 ps after posedge
      .bufnum_o(bufnum)              // which buffer do we use for bypass (per bank)?

      // end fftctl->printconnections()
    );

   twiddle_unq1  twiddle
     (                                                       // .remote(local)
      // begin twiddle->printconnections()
      .cycle_num_i(cycle_num), // Counts from 0 to ncalcs/nunits(?) maybe

      .BFLY0_twiddle_cos_o(BFLY0_twiddle_cos),
      .BFLY0_twiddle_sin_o(BFLY0_twiddle_sin)

      // end twiddle->printconnections()
    );

   ////////////////////////////////////////////////////////////////////////
   // BEGIN CLOCK AND RESET

   ////////////////////////////////////
   // Generate a reset and start
   // clk   ___.---.___.---.___.---.___
   //
   // rstn  ---._______________________
   // 
   // start ___.---.___________________
   //
   ////////////////////////////////////

   initial begin
      start = 1'b0; // Should be comb logic based on rst_n etc? leave it for now
      rst_n = 1'b1;
   end

   // note cgra does this:
   //  always @(posedge clk or posedge reset) begin
   //    if (reset==1'b1) begin ...
   //    end else begin  ...

   // Reset on very first posedge
   // FIXME this is terrible; for now we do it b/c matches vcs test rig :(
   // Eventually will need like a ncy signal or something
   always @ (posedge clk) begin
     if (rst_n) begin
        $display("\nRESET!!!");
        rst_n <= 1'b0;
        start <= 1'b1;
     end
     else begin // start is a one-shot, yes?
        start <= 1'b0;
     end
   end

   ////////////////////////////////////////////////////////////////////////
   // cycle counter I guess
   //
   logic [31:0] cycle_counter;

   always @ (posedge clk or negedge rst_n) begin
     if (rst_n) cycle_counter <= 32'b0;
     else       cycle_counter <= cycle_counter + 32'b1;
   end
   
   always @ (posedge clk) begin
      $display("------------------------------------------------------------------------------");
      $display("clock.vp: reset=%d, ncy=%4d, time=%6d ns", rst_n, cycle_counter, $time/1000);
      $display("------------------------------------------------------------------------------");
   end


   // END CLOCK AND RESET

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
