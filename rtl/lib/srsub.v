// z = a - b, all 32-bit (single-precision) floating point.
// Returns zero if underflow, NaN if overflow.

module srsub(
  input  wire [31:0] a,
  input  wire [31:0] b,
  output wire [31:0] z
  );

   // SP floating point fields
  `define sign     31
  `define exponent 30:23
  `define mantissa 22:0

   // various other constants
  `define zero     32'b0
  `define NaN      32'hFFFFFFFF

  // Extract sign, exponent, mantissa  

  wire as = a[`sign];
  wire bs = b[`sign];

  // Restore hidden one's, use 48-bit precision
  wire [47:0] am; assign am = {23'b0, 1'b1, a[`mantissa]};
  wire [47:0] bm; assign bm = {23'b0, 1'b1, b[`mantissa]};

  // 
  wire [7:0] ae; assign ae = a[`exponent];
  wire [7:0] be; assign be = b[`exponent];


  // Can left-shift smaller mantissa as much as 22 bits and still get valid result maybe
  wire [7:0] ediff; assign ediff = (ae >= be) ? (ae - be) : (be - ae);




  // Shift the larger operand left ediff bits, and reduce exp accordingly

  wire [47:0] am_adj; assign am_adj = (ediff > 8'd22) ? am : (
    (ae > be) ? (am << ediff) : am
  ); 
  wire [47:0] bm_adj; assign bm_adj = (ediff > 8'd22) ? bm : (
    (be > ae) ? (bm << ediff) : bm
  ); 


/*
  // FIXME check to see if exp will go l.t. zero
  wire [8:0] ae_adj; assign ae_adj = (ediff > 8'd22) ? ae : (
    (ae > be) ? ({1'b0,ae} - {1'b0,ediff}) : ae
  );
  wire [8:0] be_adj; assign be_adj = (ediff > 8'd22) ? be : (
    (be > ae) ? ({1'b0,be} - {1'b0,ediff}) : be
  );
*/

  // am range 0000 to 1111
  // bm range 0000 to 1111
  // am-bm range -1111 to 1111 (10000 to 01111)

  // use if (as == bs)
  wire [47:0] abs_am_minus_bm;
  assign abs_am_minus_bm = (am_adj >= bm_adj) ? (am_adj - bm_adj) : (bm_adj - am_adj);

  // use bit range 23+ediff down to ediff, right?
  wire [23:0] zm; assign zm = (abs_am_minus_bm >> ediff);

  wire [22:0] zm_final; assign zm_final = 
/*
    zm[23] == 1'b1 ? {       zm[22:0]} :
    zm[22] == 1'b1 ? { 1'b0, zm[21:0]} :
    zm[21] == 1'b1 ? { 2'b0, zm[20:0]} :
    zm[20] == 1'b1 ? { 3'b0, zm[19:0]} :
*/

//    zm[23+ediff] == 1'b1 ? zm[22+ediff:ediff] :
    zm[23+ediff] == 1'b1 ? zm >> ediff :
    zm[22+ediff] == 1'b1 ? zm >> (ediff+1) :
    zm[21+ediff] == 1'b1 ? zm >> (ediff+2) :
    zm[20+ediff] == 1'b1 ? zm >> (ediff+3) :


/*
    zm[22+ediff] == 1'b1 ? zm[21+ediff:ediff] :
    zm[21+ediff] == 1'b1 ? zm[20+ediff:ediff] :
    zm[20+ediff] == 1'b1 ? zm[19+ediff:ediff] :
*/


    zm[19] == 1'b1 ? { 4'b0, zm[18:0]} :
    zm[18] == 1'b1 ? { 5'b0, zm[17:0]} :
    zm[17] == 1'b1 ? { 6'b0, zm[16:0]} :
    zm[16] == 1'b1 ? { 7'b0, zm[15:0]} :
    zm[15] == 1'b1 ? { 8'b0, zm[14:0]} :
    zm[14] == 1'b1 ? { 9'b0, zm[13:0]} :
    zm[13] == 1'b1 ? {10'b0, zm[12:0]} :
    zm[12] == 1'b1 ? {11'b0, zm[11:0]} :
    zm[11] == 1'b1 ? {12'b0, zm[10:0]} :
    zm[10] == 1'b1 ? {13'b0, zm[ 9:0]} :

    zm[9] == 1'b1 ? {14'b0, zm[8:0]} :
    zm[8] == 1'b1 ? {15'b0, zm[7:0]} :
    zm[7] == 1'b1 ? {16'b0, zm[6:0]} :
    zm[6] == 1'b1 ? {17'b0, zm[5:0]} :
    zm[5] == 1'b1 ? {18'b0, zm[4:0]} :
    zm[4] == 1'b1 ? {19'b0, zm[3:0]} :
    zm[3] == 1'b1 ? {20'b0, zm[2:0]} :
    zm[2] == 1'b1 ? {21'b0, zm[1:0]} :
    zm[1] == 1'b1 ? {22'b0, zm[0:0]} :
                    {23'b0};

  // Remember, we adjusted the larger op to match the smaller...
  // wire [7:0] ze; assign ze = (ae < be)? ae : be;

  // Oh, no, but then we shifted it back down again, right?
  // So matches the bigger one again maybe
  wire [7:0] ze; assign ze = (ae > be)? ae : be;



  wire [7:0] ze_finall; assign ze_finall =
    zm[23] == 1'b1 ? ze + 7'd0 :
    zm[22] == 1'b1 ? ze + 7'd1 :
    zm[21] == 1'b1 ? ze + 7'd2 :
    zm[20] == 1'b1 ? ze + 7'd3 :

    zm[19] == 1'b1 ? ze + 7'd4 :
    zm[18] == 1'b1 ? ze + 7'd5 :
    zm[17] == 1'b1 ? ze + 7'd6 :
    zm[16] == 1'b1 ? ze + 7'd7 :
    zm[15] == 1'b1 ? ze + 7'd8 :
    zm[14] == 1'b1 ? ze + 7'd9 :
    zm[13] == 1'b1 ? ze + 7'd10 :
    zm[12] == 1'b1 ? ze + 7'd11 :
    zm[11] == 1'b1 ? ze + 7'd12 :
    zm[10] == 1'b1 ? ze + 7'd13 :

    zm[9] == 1'b1 ?  ze + 7'd14 :
    zm[8] == 1'b1 ?  ze + 7'd15 :
    zm[7] == 1'b1 ?  ze + 7'd16 :
    zm[6] == 1'b1 ?  ze + 7'd17 :
    zm[5] == 1'b1 ?  ze + 7'd18 :
    zm[4] == 1'b1 ?  ze + 7'd19 :
    zm[3] == 1'b1 ?  ze + 7'd20 :
    zm[2] == 1'b1 ?  ze + 7'd21 :
    zm[1] == 1'b1 ?  ze + 7'd22 :
    zm[0] == 1'b1 ?  ze + 7'd23 :
    7'd0;

  wire [7:0] ze_final; assign ze_final = ze_finall - 8'd1;


//  // use if (as != bs)
//  wire [47:0] abs_am_minus_bm;
//  assign am_plus_bm = am + bm;



  wire [31:0] a_plus_b;
  sradd SUBADDER (

// `define TEST_SRADD_ONE_PLUS_ONE
`define TEST_SRADD_ONE_PLUS_707

`ifdef TEST_SRADD_ONE_PLUS_ONE
    // FIXME TEST CODE
    // 1 + 1 = 2?
    .a(32'h3f800000),
    .b(32'h3f800000),
`else
  `ifdef TEST_SRADD_ONE_PLUS_707
    // FIXME TEST CODE
    // 1 + .707 = 1.707?
    .a(32'h3f800000),
    .b(32'h3f3504f3),
  `else
    .a({a[`sign], a[`exponent], a[`mantissa]}),
    .b({a[`sign], b[`exponent], b[`mantissa]}),
  `endif
`endif

    .z(a_plus_b)
  );



  ////////////////////////////////////////////////////////////////
  assign z =
    a[`sign] != b[`sign] ? a_plus_b :
    a == b     ? 32'b0 :
    b == 32'b0 ? a :
    a == 32'b0 ? {~b[`sign],b[`exponent],b[`mantissa]} :
    ((ediff > 8'd22)) && (a > b) ? a :
    ((ediff > 8'd22)) && (a < b) ? {~b[`sign],b[`exponent],b[`mantissa]} :
    (a > b) ? {as,ze_final,zm_final} :
              {~as,ze_final,zm_final};


`define DBG1
`define DBG9

`ifdef DBG1
  // DEBUGGING
  always @ (*) begin

   if (a == 32'h3f800000) begin
//    if ((a != 0) && (b != 0)) begin
//    if ((a != 0) && (b == 32'h40000000)) begin
  
      $display("srsub");

      $display("srsub a=%9.6f (%08X) b=%9.6f (%08X) z=%9.6f (%08X)",
      $bitstoshortreal(a), a, $bitstoshortreal(b), b, $bitstoshortreal(z), z);

// `ifdef DBG9
//        $display("srsub as=%1x bs=%1x zs=%1x", a[`sign], b[`sign], z[`sign]);
        $display("srsub   ae=%02x be=%02x", ae, be);
        $display("srsub   ae+bias=%1d be+bias=%1d", ae - 8'd127, be - 8'd127);
        $display("srsub   ediff=%2d", ediff);


//        $display("srsub ae8=%09b be8=%09b ze8=%09b", a[`exponent], b[`exponent], z[`exponent]);
//        $display("srsub ae9=%09b be9=%09b ze9=%09b", a_exp, b_exp, ze);
//        $display("srsub   ae_plus_be=%09b", ae_plus_be);
//        $display("srsub   ze_prenorm=%09b", ze_prenorm);
//        $display("srsub   too_big=%1b ze_norm=%09b", too_big, ze_norm);
//        $display("srsub aeb=%09b beb=%09b zeb=%09b", a_exp-bias, b_exp-bias, ze-bias);



//        $display("srsub ----");
        $display("srsub   am=%06X bm=%06X", am,     bm);
        $display("srsub   am_adj=%012X", am_adj);
        $display("srsub   bm_adj=%012X", bm_adj);
        $display("srsub   a>b = %1b", am_adj >= bm_adj);
        $display("srsub   |am-bm| == %012X", abs_am_minus_bm);

        $display("srsub   ze      =%02X", ze);
        $display("srsub   ze_final=%02X", ze_final);

        $display("srsub   zm      =%06X", zm);
        $display("srsub   zm_final=%06X", zm_final);


//        $display("srsub   zm_true=%06X",   zm_true);
//        $display("srsub   zm_hidden=%06X", zm_hidden);
//        $display("srsub   zm_true[23]=%1b ab[46]=%1b", zm_true[23], ab[46]);
//        $display("srsub ----");
//        $display("srsub ufw=%1b ofw=%1b", ufw, ofw);
        $display("srsub ");
//     `endif
    end // if ((a != 0) && (b != 0))

  end // always @ (*)
`endif

endmodule
