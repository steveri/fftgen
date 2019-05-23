// I mean how hard can it be haha

// z = a + b, all 32-bit (single-precision) floating point.
// Returns zero if underflow, NaN if overflow.

module sradd(
  input  wire [31:0] a,
  input  wire [31:0] b,
  output wire [31:0] z
  );

  // Assume (should assert) that sign[a] = sign[b]

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


  wire [7:0] ediff; assign ediff = (ae >= be) ? (ae - be) : (be - ae);

  // NORMALIZE
  // Shift the smaller operand left ediff bits, and reduce exp accordingly
  // Can left-shift smaller mantissa as much as 22 bits and still get valid result maybe

  wire [47:0] am_adj; assign am_adj = (ediff > 8'd22) ? am : (
    (ae > be) ? (am << ediff) : am
  ); 
  wire [47:0] bm_adj; assign bm_adj = (ediff > 8'd22) ? bm : (
    (be > ae) ? (bm << ediff) : bm
  ); 

  // smaller one shifts up and back, so end up with larger exponent right?
  wire [7:0] ze; assign ze = (ae > be) ? ae : be;

  // FIXME check to see if exp will go l.t. zero

  // am_adj range 0010 (ediff=0) to 1100 (ediff=22)
  // bm_adj range 0010           to 0011
  // am+bm range  0100           to 1111

  wire [47:0] am_plus_bm;
  assign am_plus_bm = am_adj + bm_adj;

//  // use bit range 23+ediff down to ediff, right?
//  wire [23:0] zm; assign zm = (am_plus_bm >> ediff);

  wire [24:0] zm; assign zm = am_plus_bm >> ediff;

// The one bit will *always* be at position 23 + (ediff+1 or ediff) (right?)


  wire [22:0] zm_final; assign zm_final = 
    zm[24] == 1'b1 ? zm[23:1] : zm[22:0];

  // FIXME can ze overflow??
  wire [7:0] ze_final; assign ze_final = 
    zm[24] == 1'b1 ? ze+1 : ze;

/*
  // Remember, we adjusted the larger op to match the smaller...
  // wire [7:0] ze; assign ze = (ae < be)? ae : be;

  // Oh, no, but then we shifted it back down again, right?
  // So matches the bigger one again maybe
  wire [7:0] ze; assign ze = (ae > be)? ae : be;

*/


//  // use if (as != bs)
//  wire [47:0] abs_am_minus_bm;
//  assign am_plus_bm = am + bm;



  ////////////////////////////////////////////////////////////////
  assign z =
    b == 32'b0 ? a :
    a == 32'b0 ? b :
    {as,ze_final,zm_final};



`define DBG1
`define DBG9

`ifdef DBG1
  // DEBUGGING
  always @ (*) begin

   if (a == 32'h3f800000) begin
//    if ((a != 0) && (b != 0)) begin
//    if ((a != 0) && (b == 32'h40000000)) begin
  
      $display("sradd");

      $display("sradd a=%9.6f (%08X) b=%9.6f (%08X) z=%9.6f (%08X)",
      $bitstoshortreal(a), a, $bitstoshortreal(b), b, $bitstoshortreal(z), z);

// `ifdef DBG9
//        $display("sradd as=%1x bs=%1x zs=%1x", a[`sign], b[`sign], z[`sign]);

        $display("sradd   ae=%02x be=%02x", ae, be);
        $display("sradd   ae+bias=%1d be+bias=%1d", ae - 8'd127, be - 8'd127);
        $display("sradd   ediff=%2d", ediff);


//        $display("sradd ----");
        $display("sradd   am=%06X bm=%06X", am,     bm);
        $display("sradd   am_adj=%012X", am_adj);
        $display("sradd   bm_adj=%012X", bm_adj);
        $display("sradd   am+bm =%012X", am_plus_bm);

        $display("sradd   ze      =%02X", ze);
        $display("sradd   ze_final=%02X", ze_final);

        $display("sradd   zm      =%06X", zm);
        $display("sradd   zm_final=%06X", zm_final);


        $display("sradd ");
//     `endif
    end // if ((a != 0) && (b != 0))

  end // always @ (*)
`endif

endmodule
