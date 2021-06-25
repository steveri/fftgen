// z = a + b, all 32-bit (single-precision) floating point.
// Returns zero if underflow, NaN if overflow.

// FIXME need maybe an ERROR signal to show when e.g. sign(a) != sign(b)

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

// Extract sign, exponent, mantissa  
wire [7:0] ae; assign ae = a[`exponent];
wire [7:0] be; assign be = b[`exponent];

// Restore hidden one's, use 48-bit precision
wire [47:0] am; assign am = {24'b0, 1'b1, a[`mantissa]};
wire [47:0] bm; assign bm = {24'b0, 1'b1, b[`mantissa]};

// NORMALIZE
// Shift the smaller operand left ediff bits, and reduce exp accordingly
// Can left-shift smaller mantissa as much as 22 bits and still get valid result maybe
wire [7:0] ediff; assign ediff = (ae >= be) ? (ae - be) : (be - ae);

// Ummmmmm...if ediff too great, then somebody is essentially zero...
wire ignore_a; assign ignore_a = (a == 32'b0) || ((ediff > 8'd22) && (be > ae));
wire ignore_b; assign ignore_b = (b == 32'b0) || ((ediff > 8'd22) && (ae > be));

wire [47:0] am_adj; assign am_adj = (ae > be) ? (am << ediff) : am;
wire [47:0] bm_adj; assign bm_adj = (be > ae) ? (bm << ediff) : bm;


// smaller operand shifts up and back, so end up with larger exponent right?
wire [7:0] ze; assign ze = (ae > be) ? ae : be;

// FIXME check to see if exp will go l.t. zero
// FIXME not sure what that means exc. need extensive testing!

// am range    0000_0080_0000 to 7FFF_8000_0000
// bm range    0000_0080_0000 to 7FFF_8000_0000
// am+bm range 0000_0100_0000 to FFFF_FFFF_FFFF
//
// ...riiight? And then when you shift it back down again:
//
// zm range 0000_0080_0000 to  0000_01FF_FFFF maybe?

wire [47:0] am_plus_bm; assign am_plus_bm = am_adj + bm_adj;
// wire [24:0] zm; assign zm = am_plus_bm >> ediff;
wire [47:0] zm48; assign zm48 = am_plus_bm >> ediff;
wire [24:0] zm; assign zm = zm48[24:0];

// 'magic name "unused" (-unused-regexp) is recognized by Verilator and suppresses warnings' //
wire _unused_ok_zm = &{1'b0, zm48[47:23]};

// The 'one' bit will *always* be at position 23 or 24, RIGHT??
// So adjust exp, mantissa accordingly.
// Hidden one happens at the end...RIGHT???

wire [22:0] zm_final; assign zm_final = 
  zm[24] == 1'b1 ? zm[23:1] : zm[22:0];

// FIXME can ze overflow??
wire [7:0] ze_final; assign ze_final = 
  zm[24] == 1'b1 ? ze+1 : ze;

////////////////////////////////////////////////////////////////
assign z =
  ignore_a ? b :
  ignore_b ? a :
  {as,ze_final,zm_final};

// FIXME not supposed to use adder if signs not equal!
// FIXME need some kind of ASSERT a[`sign] == b[`sign]

// DEBUGGING
// FIXME Technically I think these are supposed to be OUTSIDE the module def
//`define DBG1
//`define DBG9

`ifdef DBG1
  // DEBUGGING
  always @ (*) begin

   if (a == a) begin
   //if (a == 32'h3f800000) begin
   //if ((a != 0) && (b != 0)) begin
   //if ((a != 0) && (b == 32'h40000000)) begin
  
      $display("%m");
      $display("%m a=bsr'%08X (%08X) b=bsr'%08X (%08X) z=bsr'%08X (%08X)",
               a, a, b, b, z, z);

     `ifdef DBG9
        $display("%m   ae=%02x be=%02x", ae, be);
        $display("%m   ae+bias=%1d be+bias=%1d", ae - 8'd127, be - 8'd127);
        $display("%m   ediff=%2d", ediff);
        $display("%m   am=%06X bm=%06X", am,     bm);
        $display("%m   am_adj=%012X", am_adj);
        $display("%m   bm_adj=%012X", bm_adj);
        $display("%m   am+bm =%012X", am_plus_bm);

        $display("%m   ze      =%02X", ze);
        $display("%m   ze_final=%02X", ze_final);
        $display("%m   zm      =%06X", zm);
        $display("%m   zm_final=%06X", zm_final);
        $display("%m ");
     `endif  // DBG9
    end    // if ((a != 0) && (b != 0))
  end    // always @ (*)
`endif // DBG1

endmodule
