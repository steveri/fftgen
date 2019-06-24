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
//  Source file: /nobackup/steveri/github/fftgen/rtl/fftram.vp
//  Source template: fftram
//
// --------------- Begin Pre-Generation Parameters Status Report ---------------
//
//	From 'generate' statement (priority=5):
// Parameter test_mode 	= TEST5
// Parameter n_fft_points 	= 8
// Parameter n_butterfly_units 	= 1
// Parameter op_width 	= 64
// Parameter SRAM_TYPE 	= TRUE_1PORT
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
// n_butterfly_units (_GENESIS2_INHERITANCE_PRIORITY_) = 1
//
// n_fft_points (_GENESIS2_INHERITANCE_PRIORITY_) = 8
//
// op_width (_GENESIS2_INHERITANCE_PRIORITY_) = 64
//
// SRAM_TYPE (_GENESIS2_INHERITANCE_PRIORITY_) = TRUE_1PORT
//
// test_mode (_GENESIS2_INHERITANCE_PRIORITY_) = TEST5
//
// ---------------- End default Genesis2 parameter summary ----------------

// nunits=1 npoints=8 nbanks=4 nrows=2



// Generating SRAMs (SRAM000, SRAM001, SRAM002...SRAM015...)

////////////////////////////////////////////////////////////////////////
// module fftram_unq1
//
// Usage: fftram(n_butterfly_units, n_fft_points, op_width, test_mode), where
//
//   n_butterfly_units is the number of butterfly units to build (1,2,4,8,...)
//   n_fft_points can be any power of two greater than 8;
//   op_width is number of bits per FFT data point, e.g. 64 for 32b real + 32b imaginary
//   test_mode tells what kind of FFT test to build and run e.g. "TEST5"

module fftram_unq1
    (
     input logic clk_i

     // in1, in2 addresses from fftram - bank (SRAM) number bnum
     ,input logic [1:0] BFLY0_op1_bnum_i       ,input logic [1:0] BFLY0_op2_bnum_i

     // in1, in2 addresses from fftram - row (index) number rnum
     ,input logic [0:0] BFLY0_op1_rnum_i       ,input logic [0:0] BFLY0_op2_rnum_i

     // Data from fftram to butterfly units: in1, in2
     ,output logic [63:0] BFLY0_in1_data_o       ,output logic [63:0] BFLY0_in2_data_o

     // Data from butterfly units to fftram: out1, out2
     ,input logic [63:0] BFLY0_out1_data_i       ,input logic [63:0] BFLY0_out2_data_i

     // Only used for TRUE_1PORT.  Otherwise, gets eliminated automatically, right?
     // ...or...? Shold they be ifdef'ed?
     // Bypass controls
     ,input logic [3:0] suppress_wz_i  // one bit per bank, set 100 ps after posedge

     ,input logic fft_started
  );

   // BEGIN WIRE DECLARATIONS__________________________________________________

   // Wires to/from SRAMs:
   // 1 butterfly unit means we need 4x1 = 4 single-port SRAM's named e.g. {SRAM000, SRAM001,...SRAM015}

   logic [0:0] SRAM000_ix;   logic [63:0] SRAM000_rd_data;   logic [63:0] SRAM000_wr_data;   logic SRAM000_ez;   logic SRAM000_wz;
   logic [0:0] SRAM001_ix;   logic [63:0] SRAM001_rd_data;   logic [63:0] SRAM001_wr_data;   logic SRAM001_ez;   logic SRAM001_wz;
   logic [0:0] SRAM002_ix;   logic [63:0] SRAM002_rd_data;   logic [63:0] SRAM002_wr_data;   logic SRAM002_ez;   logic SRAM002_wz;
   logic [0:0] SRAM003_ix;   logic [63:0] SRAM003_rd_data;   logic [63:0] SRAM003_wr_data;   logic SRAM003_ez;   logic SRAM003_wz;


   // (For now) BOTF: must duplicate fftctl's 'cycle_num' signal so we
   // can conservatively BYPASS ALL FINAL-CYCLE WRITES in a each stage.
   // FIXME Really shouldn't bypass final-stage writes!!!
   // FIXME Later, can just bring 'cycle_num' (below) in from fftctl as a signal.
   // FIXME Or something smarter.
   // Need to count from 0 to [log2(npoints) x (npoints/2) / (nbutts)]
   // plus at least one beyond that.
   logic [3:0] cycle_num;
   logic bypass_time;              // Bypass_time==1 when cycle_time says it is time to bypass.

   // E.g. SRAM001_active=1 during any cycle that we're accessing SRAM001 (BOTF).
   logic SRAM000_active;
   logic SRAM001_active;
   logic SRAM002_active;
   logic SRAM003_active;


   // BOTF: At end of each stage, there is possibility of read/write
   // conflict where one butterfly wants to write to the (single ported)
   // SRAM at the same time another one wants to read from the SRAM.
   // When this happens, bypass the write data to the 'bypassed_data' buffer.
   logic        bypass_valid[0:3];  // True (1) iff bypassed_data is valid
   logic [0:0]  bypassed_rnum[0:3]; // Use target row number (index) of valid data as an ID.
   logic [63:0] bypassed_data[0:3]; // Valid data lives here instead of 'rnum' in SRAM.

   // Only needed when bypass buffers are used; otherwise gets hardwired to rd_data.
   logic [63:0] sram_or_buf[0:3]; // Staging area for read data.

   // (op1,op2)_"match" wires TRUE iff (op1,op2) address matches SRAM id ([0], [1], ...)
   // 1 butterfly unit means we need 4x1 = 4 single-port SRAM's named e.g. {SRAM000, SRAM001,...SRAM015}
   logic BFLY0_op1_match[0: 3];    logic BFLY0_op2_match[0: 3];

   // LOOK MA NO BYPASS BUFFER


   // Initialize BOTF (bypass on the fly) signals (cycle_num)
   initial cycle_num <= 4'b0;

   // Initialize BOTF (bypass on the fly) signals
   // bypass_valid:  True (1) iff bypassed_data is valid
   // bypassed_rnum: Use target row number (index) of valid data as an ID.
   // bypassed_data: Valid data lives here instead of 'rnum' in SRAM.
   // 'x means "set all bits to x", or so I'm told.
   initial begin
      bypass_valid[0]=1'b0;  bypassed_rnum[0]=1'b0;  bypassed_data[0]='x;
      bypass_valid[1]=1'b0;  bypassed_rnum[1]=1'b0;  bypassed_data[1]='x;
      bypass_valid[2]=1'b0;  bypassed_rnum[2]=1'b0;  bypassed_data[2]='x;
      bypass_valid[3]=1'b0;  bypassed_rnum[3]=1'b0;  bypassed_data[3]='x;
   end

   // END WIRE DECLARATIONS____________________________________________________


   always @(posedge clk_i) begin
     // FIXME FIXME FIXME OH NO!!! waveform shows this
     //   cycle_num != top_fft cycle_num !! :( :(
     if (fft_started == 1) cycle_num <= cycle_num + 1'b1;
     else cycle_num <= 4'b0;
   end

   always @(posedge clk_i) begin
      $display("fftctl %1d: cycle_num = %1d BOTF", $time, cycle_num);
   end

   // On first cycle of each stage (except stage 0), set bypass_time==1
   // to indicate that we will bypass ALL (active bnum-match) WRITES
   assign bypass_time = ((cycle_num > 0) &&
                         (cycle_num < 12) &&
                         ((cycle_num & 3) == 0)
                         ) ? 1'b1 : 1'b0;

   // Instantiate SRAM's (SRAM000, SRAM001, SRAM002...SRAM015) (.remote(local))
   SRAM_unq1  SRAM000( .clk_i(clk_i), .ez_i(SRAM000_ez), .wz_i(SRAM000_wz), .addr_i(SRAM000_ix), .rd_data_o(SRAM000_rd_data), .wr_data_i(SRAM000_wr_data) );
   SRAM_unq2  SRAM001( .clk_i(clk_i), .ez_i(SRAM001_ez), .wz_i(SRAM001_wz), .addr_i(SRAM001_ix), .rd_data_o(SRAM001_rd_data), .wr_data_i(SRAM001_wr_data) );
   SRAM_unq3  SRAM002( .clk_i(clk_i), .ez_i(SRAM002_ez), .wz_i(SRAM002_wz), .addr_i(SRAM002_ix), .rd_data_o(SRAM002_rd_data), .wr_data_i(SRAM002_wr_data) );
   SRAM_unq4  SRAM003( .clk_i(clk_i), .ez_i(SRAM003_ez), .wz_i(SRAM003_wz), .addr_i(SRAM003_ix), .rd_data_o(SRAM003_rd_data), .wr_data_i(SRAM003_wr_data) );

   //////////////////////////////////////////////////////////////////////////////
   // ez signals for SRAMs
   assign SRAM000_ez = ~fft_started | ~(
        (BFLY0_op1_bnum_i == 0 ) | (BFLY0_op2_bnum_i == 0 ) | ~SRAM000_wz );
   assign SRAM001_ez = ~fft_started | ~(
        (BFLY0_op1_bnum_i == 1 ) | (BFLY0_op2_bnum_i == 1 ) | ~SRAM001_wz );
   assign SRAM002_ez = ~fft_started | ~(
        (BFLY0_op1_bnum_i == 2 ) | (BFLY0_op2_bnum_i == 2 ) | ~SRAM002_wz );
   assign SRAM003_ez = ~fft_started | ~(
        (BFLY0_op1_bnum_i == 3 ) | (BFLY0_op2_bnum_i == 3 ) | ~SRAM003_wz );

   //////////////////////////////////////////////////////////////////////////////
   // Bypass buffer control signals.  Only used for TRUE_1PORT.
   // Otherwise...what...gets eliminated automatically, right?  BUG/FIXME/TODO



   // NOTE also need this if there's no bypass at all e.g. when nports > 1
   // LOOK MA NO BYPASS BUFFER

   always @ (posedge clk_i) begin 

      $display("fftram %6d bypass_valid[2]=%1d SRAM002_active=%1d bypassed_rnum[2]=%1d SRAM002_ix=%1d GLOOP",
               $time,  bypass_valid[2], SRAM002_active, bypassed_rnum[2], SRAM002_ix);


      if ((bypass_valid[0] == 1'b1) &&
          (SRAM000_active == 1) &&
          (SRAM000_ix == bypassed_rnum[0])
      ) begin
         bypass_valid[0] = 1'b0;
         $display("fftram %6d Bypassed SRAM 0, read  (bsr'%08X,bsr'%08X) from bypassed_data[0] BOTF", $time,
                   bypassed_data[0][63:32], // Real part
                   bypassed_data[0][31: 0]); // Imaginary part
      end

      if ((bypass_valid[1] == 1'b1) &&
          (SRAM001_active == 1) &&
          (SRAM001_ix == bypassed_rnum[1])
      ) begin
         bypass_valid[1] = 1'b0;
         $display("fftram %6d Bypassed SRAM 1, read  (bsr'%08X,bsr'%08X) from bypassed_data[1] BOTF", $time,
                   bypassed_data[1][63:32], // Real part
                   bypassed_data[1][31: 0]); // Imaginary part
      end

      if ((bypass_valid[2] == 1'b1) &&
          (SRAM002_active == 1) &&
          (SRAM002_ix == bypassed_rnum[2])
      ) begin
         bypass_valid[2] = 1'b0;
         $display("fftram %6d Bypassed SRAM 2, read  (bsr'%08X,bsr'%08X) from bypassed_data[2] BOTF", $time,
                   bypassed_data[2][63:32], // Real part
                   bypassed_data[2][31: 0]); // Imaginary part
      end

      if ((bypass_valid[3] == 1'b1) &&
          (SRAM003_active == 1) &&
          (SRAM003_ix == bypassed_rnum[3])
      ) begin
         bypass_valid[3] = 1'b0;
         $display("fftram %6d Bypassed SRAM 3, read  (bsr'%08X,bsr'%08X) from bypassed_data[3] BOTF", $time,
                   bypassed_data[3][63:32], // Real part
                   bypassed_data[3][31: 0]); // Imaginary part
      end
   end

   // LOOK MA NO BYPASS BUFFER mano mano

   //////////////////////////////////////////////////////////////////////////////
   // wz signals.  If Anyone wants to access a given bank n (op1_bnum==1),
   // set wz(n) (to zero), unless suppress_wz says not to.

   always @ (posedge clk_i) begin
      if (cycle_num == 4'b0) SRAM000_wz = 1'b1; else
      if ( fft_started & (
         (BFLY0_op1_bnum_i == 0 ) | (BFLY0_op2_bnum_i == 0 )
      )) begin
         SRAM000_wz = suppress_wz_i[0];
          // \$display(\"FLOOF BOTF %1d okay want to write ${sram}\", \$time);

         if (bypass_time == 1) begin
            // FIXME really need a task here, no?
            $display("FLOOF %1d prev was 1, swz is 0 (suppress) - I predicted it!!!", $time);
            //assert (1) $fatal("ERROR ha ha JK\n\n");
            
            bypass_valid[0]  <= 1'b1;              // True (1) means bypassed_data is valid
            bypassed_rnum[0] <= SRAM000_ix;     // Use target row number (index) of valid data as an ID.
            bypassed_data[0] <= SRAM000_wr_data; // Valid data lives here instead of 'rnum' in SRAM.
            $display("fftram %6d Bypassed SRAM 0, wrote (bsr'%08X,bsr'%08X) to bypassed_data[0] BTOF row %1d", $time,
                     SRAM000_wr_data[63:32], SRAM000_wr_data[31: 0],
                     bypassed_rnum[0]);
         end
      end
      else begin
         SRAM000_wz = 1'b1;
      end
   end
   always @ (posedge clk_i) begin
      if (cycle_num == 4'b0) SRAM001_wz = 1'b1; else
      if ( fft_started & (
         (BFLY0_op1_bnum_i == 1 ) | (BFLY0_op2_bnum_i == 1 )
      )) begin
         SRAM001_wz = suppress_wz_i[1];
          // \$display(\"FLOOF BOTF %1d okay want to write ${sram}\", \$time);

         if (bypass_time == 1) begin
            // FIXME really need a task here, no?
            $display("FLOOF %1d prev was 1, swz is 0 (suppress) - I predicted it!!!", $time);
            //assert (1) $fatal("ERROR ha ha JK\n\n");
            
            bypass_valid[1]  <= 1'b1;              // True (1) means bypassed_data is valid
            bypassed_rnum[1] <= SRAM001_ix;     // Use target row number (index) of valid data as an ID.
            bypassed_data[1] <= SRAM001_wr_data; // Valid data lives here instead of 'rnum' in SRAM.
            $display("fftram %6d Bypassed SRAM 1, wrote (bsr'%08X,bsr'%08X) to bypassed_data[1] BTOF row %1d", $time,
                     SRAM001_wr_data[63:32], SRAM001_wr_data[31: 0],
                     bypassed_rnum[1]);
         end
      end
      else begin
         SRAM001_wz = 1'b1;
      end
   end
   always @ (posedge clk_i) begin
      if (cycle_num == 4'b0) SRAM002_wz = 1'b1; else
      if ( fft_started & (
         (BFLY0_op1_bnum_i == 2 ) | (BFLY0_op2_bnum_i == 2 )
      )) begin
         SRAM002_wz = suppress_wz_i[2];
          // \$display(\"FLOOF BOTF %1d okay want to write ${sram}\", \$time);

         if (bypass_time == 1) begin
            // FIXME really need a task here, no?
            $display("FLOOF %1d prev was 1, swz is 0 (suppress) - I predicted it!!!", $time);
            //assert (1) $fatal("ERROR ha ha JK\n\n");
            
            bypass_valid[2]  <= 1'b1;              // True (1) means bypassed_data is valid
            bypassed_rnum[2] <= SRAM002_ix;     // Use target row number (index) of valid data as an ID.
            bypassed_data[2] <= SRAM002_wr_data; // Valid data lives here instead of 'rnum' in SRAM.
            $display("fftram %6d Bypassed SRAM 2, wrote (bsr'%08X,bsr'%08X) to bypassed_data[2] BTOF row %1d", $time,
                     SRAM002_wr_data[63:32], SRAM002_wr_data[31: 0],
                     bypassed_rnum[2]);
         end
      end
      else begin
         SRAM002_wz = 1'b1;
      end
   end
   always @ (posedge clk_i) begin
      if (cycle_num == 4'b0) SRAM003_wz = 1'b1; else
      if ( fft_started & (
         (BFLY0_op1_bnum_i == 3 ) | (BFLY0_op2_bnum_i == 3 )
      )) begin
         SRAM003_wz = suppress_wz_i[3];
          // \$display(\"FLOOF BOTF %1d okay want to write ${sram}\", \$time);

         if (bypass_time == 1) begin
            // FIXME really need a task here, no?
            $display("FLOOF %1d prev was 1, swz is 0 (suppress) - I predicted it!!!", $time);
            //assert (1) $fatal("ERROR ha ha JK\n\n");
            
            bypass_valid[3]  <= 1'b1;              // True (1) means bypassed_data is valid
            bypassed_rnum[3] <= SRAM003_ix;     // Use target row number (index) of valid data as an ID.
            bypassed_data[3] <= SRAM003_wr_data; // Valid data lives here instead of 'rnum' in SRAM.
            $display("fftram %6d Bypassed SRAM 3, wrote (bsr'%08X,bsr'%08X) to bypassed_data[3] BTOF row %1d", $time,
                     SRAM003_wr_data[63:32], SRAM003_wr_data[31: 0],
                     bypassed_rnum[3]);
         end
      end
      else begin
         SRAM003_wz = 1'b1;
      end
   end

   always @(clk_i) if (fft_started) begin
      $display("");
      $display("fftram %1d: fft_started = %1d", $time, fft_started);
      $display("fftram %1d: BFLY0_op1_bnum_i = %1d", $time, BFLY0_op1_bnum_i);
      $display("");
      $display("fftram %1d: SRAM000_ez = %1d", $time, SRAM000_ez);
      $display("fftram %1d: SRAM001_ez = %1d", $time, SRAM001_ez);
      $display("fftram %1d: SRAM002_ez = %1d", $time, SRAM002_ez);
      $display("fftram %1d: SRAM003_ez = %1d", $time, SRAM003_ez);
      $display("");
      $display("fftram %1d: SRAM000_wz = %1d", $time, SRAM000_wz);
      $display("fftram %1d: SRAM001_wz = %1d", $time, SRAM001_wz);
      $display("fftram %1d: SRAM002_wz = %1d", $time, SRAM002_wz);
      $display("fftram %1d: SRAM003_wz = %1d", $time, SRAM003_wz);
      $display("");
   end

   //////////////////////////////////////////////////////////////////////////////
   // SRAM address (ix) to access.

   // Ugh. vcs version works b/c address is x and it doesn't know where to write bad value
   // and so it doesn't write anything, which is the real desired behavior.
   // Solution is to disable ez and/or wz when value would otherwise be x
   // FIXME/TODO after things are fixed and working, disable the stupid x's!!!

   assign SRAM000_ix = 
        (BFLY0_op1_bnum_i  == 0 ) ? BFLY0_op1_rnum_i  : (BFLY0_op2_bnum_i  == 0 ) ? BFLY0_op2_rnum_i : 'x;

   assign SRAM001_ix = 
        (BFLY0_op1_bnum_i  == 1 ) ? BFLY0_op1_rnum_i  : (BFLY0_op2_bnum_i  == 1 ) ? BFLY0_op2_rnum_i : 'x;

   assign SRAM002_ix = 
        (BFLY0_op1_bnum_i  == 2 ) ? BFLY0_op1_rnum_i  : (BFLY0_op2_bnum_i  == 2 ) ? BFLY0_op2_rnum_i : 'x;

   assign SRAM003_ix = 
        (BFLY0_op1_bnum_i  == 3 ) ? BFLY0_op1_rnum_i  : (BFLY0_op2_bnum_i  == 3 ) ? BFLY0_op2_rnum_i : 'x;


   //////////////////////////////////////////////////////////////////////////////
   // op1 match signals
   //
   assign BFLY0_op1_match[ 0] = (BFLY0_op1_bnum_i ==  0) ? 1'b1 : 1'b0;
   assign BFLY0_op1_match[ 1] = (BFLY0_op1_bnum_i ==  1) ? 1'b1 : 1'b0;
   assign BFLY0_op1_match[ 2] = (BFLY0_op1_bnum_i ==  2) ? 1'b1 : 1'b0;
   assign BFLY0_op1_match[ 3] = (BFLY0_op1_bnum_i ==  3) ? 1'b1 : 1'b0;


   //////////////////////////////////////////////////////////////////////////////
   // op2 match signals
   //
   assign BFLY0_op2_match[ 0] = (BFLY0_op2_bnum_i ==  0) ? 1'b1 : 1'b0;
   assign BFLY0_op2_match[ 1] = (BFLY0_op2_bnum_i ==  1) ? 1'b1 : 1'b0;
   assign BFLY0_op2_match[ 2] = (BFLY0_op2_bnum_i ==  2) ? 1'b1 : 1'b0;
   assign BFLY0_op2_match[ 3] = (BFLY0_op2_bnum_i ==  3) ? 1'b1 : 1'b0;



   assign sram_or_buf[ 0] = (
      (bypass_valid[0] == 1'b1) &&
      (SRAM000_active  == 1) &&
      (SRAM000_ix     == bypassed_rnum[0])
      ) ? bypassed_data[0] : SRAM000_rd_data;

   assign sram_or_buf[ 1] = (
      (bypass_valid[1] == 1'b1) &&
      (SRAM001_active  == 1) &&
      (SRAM001_ix     == bypassed_rnum[1])
      ) ? bypassed_data[1] : SRAM001_rd_data;

   assign sram_or_buf[ 2] = (
      (bypass_valid[2] == 1'b1) &&
      (SRAM002_active  == 1) &&
      (SRAM002_ix     == bypassed_rnum[2])
      ) ? bypassed_data[2] : SRAM002_rd_data;

   assign sram_or_buf[ 3] = (
      (bypass_valid[3] == 1'b1) &&
      (SRAM003_active  == 1) &&
      (SRAM003_ix     == bypassed_rnum[3])
      ) ? bypassed_data[3] : SRAM003_rd_data;


   //////////////////////////////////////////////////////////////////////////////
   // SRAM data in1 OUT from sram (or bypass buffer) to butterfly unit
   //
   assign BFLY0_in1_data_o =
      BFLY0_op1_match[ 0] ? sram_or_buf[ 0] :
      BFLY0_op1_match[ 1] ? sram_or_buf[ 1] :
      BFLY0_op1_match[ 2] ? sram_or_buf[ 2] :
      BFLY0_op1_match[ 3] ? sram_or_buf[ 3] : 'x;

   //////////////////////////////////////////////////////////////////////////////
   // SRAM data in2 OUT from sram (or bypass buffer) to butterfly unit
   //
   assign BFLY0_in2_data_o =
      BFLY0_op2_match[ 0] ? sram_or_buf[ 0] :
      BFLY0_op2_match[ 1] ? sram_or_buf[ 1] :
      BFLY0_op2_match[ 2] ? sram_or_buf[ 2] :
      BFLY0_op2_match[ 3] ? sram_or_buf[ 3] : 'x;


   //////////////////////////////////////////////////////////////////////////////
   // SRAM data (out1,out2) IN to sram (or bypass buffer) from butterfly unit

   assign SRAM000_wr_data =
        BFLY0_op1_match[0] ? BFLY0_out1_data_i : BFLY0_op2_match[0] ? BFLY0_out2_data_i : 'x;
   assign SRAM001_wr_data =
        BFLY0_op1_match[1] ? BFLY0_out1_data_i : BFLY0_op2_match[1] ? BFLY0_out2_data_i : 'x;
   assign SRAM002_wr_data =
        BFLY0_op1_match[2] ? BFLY0_out1_data_i : BFLY0_op2_match[2] ? BFLY0_out2_data_i : 'x;
   assign SRAM003_wr_data =
        BFLY0_op1_match[3] ? BFLY0_out1_data_i : BFLY0_op2_match[3] ? BFLY0_out2_data_i : 'x;

   always @(posedge clk_i) begin
      // Along for the ride...
      $display("");
      $display("fftram %1d: BFLY0_op1_match[0] = %1d", $time, BFLY0_op1_match[0]);
      $display("fftram %1d: BFLY0_out1_data_i = %16x", $time, BFLY0_out1_data_i);
      $display("");
   end
                                
   assign SRAM000_active =
      BFLY0_op1_match[0] | BFLY0_op2_match[0];

   assign SRAM001_active =
      BFLY0_op1_match[1] | BFLY0_op2_match[1];

   assign SRAM002_active =
      BFLY0_op1_match[2] | BFLY0_op2_match[2];

   assign SRAM003_active =
      BFLY0_op1_match[3] | BFLY0_op2_match[3];


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
