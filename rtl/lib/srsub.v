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

  // Extract sign, exponent, mantissa  
  wire [7:0] ae; assign ae = a[`exponent];
  wire [7:0] be; assign be = b[`exponent];

  // Extract sign, exponent, mantissa  
  // Restore hidden one's, use 48-bit precision
  wire [47:0] am; assign am = {24'b0, 1'b1, a[`mantissa]};
  wire [47:0] bm; assign bm = {24'b0, 1'b1, b[`mantissa]};

  // NORMALIZE
  // Shift the larger operand left 'ediff' bits, and reduce exp accordingly
  wire [7:0] ediff; assign ediff = (ae >= be) ? (ae - be) : (be - ae);

  // Ummmmmm...if ediff too great, then somebody is essentially zero...
  wire ignore_a; assign ignore_a = (a == 32'b0) || ((ediff > 8'd22) && (be > ae));
  wire ignore_b; assign ignore_b = (b == 32'b0) || ((ediff > 8'd22) && (ae > be));

  // Can left-shift smaller mantissa as much as 22 bits and still get valid result maybe
  wire [47:0] am_adj; assign am_adj = (ae > be) ? (am << ediff) : am;
  wire [47:0] bm_adj; assign bm_adj = (be > ae) ? (bm << ediff) : bm;

  // FIXME check to see if exp will go l.t. zero
  // FIXME not sure what that means exc. need extensive testing!


  // am range 0000 to 1111
  // bm range 0000 to 1111
  // am-bm range -1111 to 1111 (10000 to 01111)

  wire [47:0] abs_am_minus_bm;
  assign abs_am_minus_bm = (am_adj >= bm_adj) ?
                               (am_adj - bm_adj) : (bm_adj - am_adj);

  // Previously, we normalized by shifting larger operand *left* by 'ediff' bits
  // Now we can shift back down (remember, ediff can be as small as 0 bits)

  // use bit range 23+ediff down to ediff, right?
  wire [47:0] zm48; assign zm48 = (abs_am_minus_bm >> ediff);
  wire [23:0] zm; assign zm = zm48[23:0];

  // 'magic name "unused" (-unused-regexp) is recognized by Verilator and suppresses warnings' //
  wire _unused_ok_zm = &{1'b0, zm48[47:24]};

// Huh this whole thing seems wrong
//   wire [22:0] zm_final; assign zm_final = 
//     zm[23+ediff] == 1'b1 ? zm >> ediff :
//     zm[22+ediff] == 1'b1 ? zm >> (ediff+1) :
//     zm[21+ediff] == 1'b1 ? zm >> (ediff+2) : <<<<<<< ediff=1 zm=4ffff zm[22], >> 3
//     zm[20+ediff] == 1'b1 ? zm >> (ediff+3) :
// /*
//     zm[22+ediff] == 1'b1 ? zm[21+ediff:ediff] :
//     zm[21+ediff] == 1'b1 ? zm[20+ediff:ediff] :
//     zm[20+ediff] == 1'b1 ? zm[19+ediff:ediff] :
// */
// 
//     zm[19] == 1'b1 ? { 4'b0, zm[18:0]} :
//     zm[18] == 1'b1 ? { 5'b0, zm[17:0]} :
//     zm[17] == 1'b1 ? { 6'b0, zm[16:0]} :
//     zm[16] == 1'b1 ? { 7'b0, zm[15:0]} :
//     zm[15] == 1'b1 ? { 8'b0, zm[14:0]} :
//     zm[14] == 1'b1 ? { 9'b0, zm[13:0]} :
//     zm[13] == 1'b1 ? {10'b0, zm[12:0]} :
//     zm[12] == 1'b1 ? {11'b0, zm[11:0]} :
//     zm[11] == 1'b1 ? {12'b0, zm[10:0]} :
//     zm[10] == 1'b1 ? {13'b0, zm[ 9:0]} :
// 
//     zm[9] == 1'b1 ? {14'b0, zm[8:0]} :
//     zm[8] == 1'b1 ? {15'b0, zm[7:0]} :
//     zm[7] == 1'b1 ? {16'b0, zm[6:0]} :
//     zm[6] == 1'b1 ? {17'b0, zm[5:0]} :
//     zm[5] == 1'b1 ? {18'b0, zm[4:0]} :
//     zm[4] == 1'b1 ? {19'b0, zm[3:0]} :
//     zm[3] == 1'b1 ? {20'b0, zm[2:0]} :
//     zm[2] == 1'b1 ? {21'b0, zm[1:0]} :
//     zm[1] == 1'b1 ? {22'b0, zm[0:0]} :
//                     {23'b0};
// /*
//     zm[19+ediff] == 1'b1 ? zm >> (ediff+4) :
//     zm[18+ediff] == 1'b1 ? zm >> (ediff+5) :
//     zm[17+ediff] == 1'b1 ? zm >> (ediff+6) :
//     zm[16+ediff] == 1'b1 ? zm >> (ediff+7) :
//     zm[15+ediff] == 1'b1 ? zm >> (ediff+8) :
//     zm[14+ediff] == 1'b1 ? zm >> (ediff+9) :
//     zm[13+ediff] == 1'b1 ? zm >> (ediff+10) :
//     zm[12+ediff] == 1'b1 ? zm >> (ediff+11) :
//     zm[11+ediff] == 1'b1 ? zm >> (ediff+12) :
//     zm[10+ediff] == 1'b1 ? zm >> (ediff+13) :
// 
//     zm[9+ediff] == 1'b1 ? zm >> (ediff+14) :
//     zm[8+ediff] == 1'b1 ? zm >> (ediff+15) :
//     zm[7+ediff] == 1'b1 ? zm >> (ediff+16) :
//     zm[6+ediff] == 1'b1 ? zm >> (ediff+17) :
//     zm[5+ediff] == 1'b1 ? zm >> (ediff+18) :
//     zm[4+ediff] == 1'b1 ? zm >> (ediff+19) :
//     zm[3+ediff] == 1'b1 ? zm >> (ediff+20) :
//     zm[2+ediff] == 1'b1 ? zm >> (ediff+21) :
//     zm[1+ediff] == 1'b1 ? zm >> (ediff+22) :
//     23'b0;
// */

  // Top bit should be '1' for normalization (one gets hidden later)
  wire [7:0] need_shift; assign need_shift = 
    zm[23] == 1'b1 ?  0 :
    zm[22] == 1'b1 ?  1 :
    zm[21] == 1'b1 ?  2 :
    zm[20] == 1'b1 ?  3 :
    zm[19] == 1'b1 ?  4 :

    zm[18] == 1'b1 ?  5 :
    zm[17] == 1'b1 ?  6 :
    zm[16] == 1'b1 ?  7 :
    zm[15] == 1'b1 ?  8 :
    zm[14] == 1'b1 ?  9 :
    zm[13] == 1'b1 ? 10 :
    zm[12] == 1'b1 ? 11 :
    zm[11] == 1'b1 ? 12 :
    zm[10] == 1'b1 ? 13 :
    zm[ 9] == 1'b1 ? 14 :
    zm[ 8] == 1'b1 ? 15 :
    zm[ 7] == 1'b1 ? 16 :
    zm[ 6] == 1'b1 ? 17 :
    zm[ 5] == 1'b1 ? 18 :
    zm[ 4] == 1'b1 ? 19 :
    zm[ 3] == 1'b1 ? 20 :
    zm[ 2] == 1'b1 ? 21 :
    zm[ 1] == 1'b1 ? 22 :
    zm[ 0] == 1'b1 ? 23 : 24;

  // zm is 24 bits, verilator complains if zm_final is not also 24 bits
  wire [23:0] zm_final; assign zm_final = zm << need_shift;


  // Remember, we adjusted the larger op to match the smaller...
  // wire [7:0] ze; assign ze = (ae < be)? ae : be;

  // Oh, no, but then we shifted it back down again, right?
  // So matches the bigger one again maybe
  wire [7:0] ze; assign ze = (ae > be)? ae : be;


  // ae > be; ae=0x81; zm=0x600000; zm[22] = 1; want new ze = 0x80

  wire [7:0] ze_final; assign ze_final =
    zm[23] == 1'b1 ? ze - 7'd0 :
    zm[22] == 1'b1 ? ze - 7'd1 :
    zm[21] == 1'b1 ? ze - 7'd2 :
    zm[20] == 1'b1 ? ze - 7'd3 :

    zm[19] == 1'b1 ? ze - 7'd4 :
    zm[18] == 1'b1 ? ze - 7'd5 :
    zm[17] == 1'b1 ? ze - 7'd6 :
    zm[16] == 1'b1 ? ze - 7'd7 :
    zm[15] == 1'b1 ? ze - 7'd8 :
    zm[14] == 1'b1 ? ze - 7'd9 :
    zm[13] == 1'b1 ? ze - 7'd10 :
    zm[12] == 1'b1 ? ze - 7'd11 :
    zm[11] == 1'b1 ? ze - 7'd12 :
    zm[10] == 1'b1 ? ze - 7'd13 :

    zm[9] == 1'b1 ?  ze - 7'd14 :
    zm[8] == 1'b1 ?  ze - 7'd15 :
    zm[7] == 1'b1 ?  ze - 7'd16 :
    zm[6] == 1'b1 ?  ze - 7'd17 :
    zm[5] == 1'b1 ?  ze - 7'd18 :
    zm[4] == 1'b1 ?  ze - 7'd19 :
    zm[3] == 1'b1 ?  ze - 7'd20 :
    zm[2] == 1'b1 ?  ze - 7'd21 :
    zm[1] == 1'b1 ?  ze - 7'd22 :
    zm[0] == 1'b1 ?  ze - 7'd23 :
    8'd0;

  ////////////////////////////////////////////////////////////////
  assign z =
    a == b   ? 32'b0 :
    ignore_b ? a :
    ignore_a ? {~b[`sign],b[`exponent],b[`mantissa]} :
    (a > b)  ? {as,ze_final,zm_final[22:0]} :
              {~as,ze_final,zm_final[22:0]} ;

// FIXME FIXME this little fixme block
// Somebody else has to do this check now:
// a[`sign] != b[`sign] ? a_plus_b :
// FIXME need some kind of ASSERT a[`sign] == b[`sign]
// 
// FIXME instead of (a>b) above, should do...ah never mind


// FIXME Technically I think these are supposed to be OUTSIDE the module def
//`define DBG1
//`define DBG9

`ifdef DBG1
  // DEBUGGING
//always @ (z) // why does this not work!!?
  always @ (*) if (a[`sign] == b[`sign]) begin

   if (a == a) begin
// if (a == 32'h3f800000) begin
// if ((a != 0) && (b != 0)) begin
// if ((a != 0) && (b == 32'h40000000)) begin
  
      $display("%m");
      $display("%m a=bsr'%08x (%08X) b=bsr'%08x (%08X) z=bsr'%08x (%08X)",
               a, a, b, b, z, z);

 `ifdef DBG9
        $display("%m    ae=%02x be=%02x", ae, be);
        $display("%m    ae+bias=%1d be+bias=%1d", ae - 8'd127, be - 8'd127);
        $display("%m    ediff=%2d", ediff);
        $display("%m    am=%06X bm=%06X", am,     bm);
        $display("%m    am_adj=%012X", am_adj);
        $display("%m    bm_adj=%012X", bm_adj);
        $display("%m    a>b = %1b", am_adj >= bm_adj);
        $display("%m    |am-bm| == %012X", abs_am_minus_bm);
        $display("%m    ze      =%02X", ze);
        $display("%m    ze_final=%02X", ze_final);
        $display("%m    zm      =%06X", zm);
        $display("%m    zm_final=%06X", zm_final);
        $display("%m  ");
     `endif // DBG9
    end // if ((a != 0) && (b != 0))
  end // always @ (*)
`endif // DBG1

endmodule
