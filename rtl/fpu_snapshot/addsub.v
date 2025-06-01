// 0 for add, 1 for sub (matches designware why not)
`define ADD 1'b0
`define SUB 1'b1

// +/- sign bit
`define POS 1'b0
`define NEG 1'b1

module addsub(
  input  wire op, // 0 for add, 1 for sub (matches designware why not)
  input  wire [31:0] a,
  input  wire [31:0] b,
  output wire [31:0] z
);

// SP floating point fields
`define sign     31
`define exponent 30:23
`define mantissa 22:0

// Add and subtract

wire [31:0] abs_a; assign abs_a = {`POS,a[30:0]};
wire [31:0] abs_b; assign abs_b = {`POS,b[30:0]};

wire [31:0] zadd;
sradd ADD (
  .a(abs_a),
  .b(abs_b),
  .z(zadd)
);

wire [31:0] zsub;
srsub SUB (
  .a(abs_a),
  .b(abs_b),
  .z(zsub)
);

//////////////////////////////////////
//   op  sign(a)   sign(b)   result //
// -------------------------------- //
//  add     +         +      (a+b)  //
//  add     +         -      (a-b)  //
//  add     -         +     -(a-b)  //
//  add     -         -     -(a+b)  //
// -------------------------------- //
//  sub     +         +      (a-b)  //
//  sub     +         -      (a+b)  //
//  sub     -         +     -(a+b)  //
//  sub     -         -     -(a-b)  //
//////////////////////////////////////

// Sign bit shortcuts
wire apos; assign apos = (a[`sign] == `POS);
wire bpos; assign bpos = (b[`sign] == `POS);

wire [31:0] zraw;
assign zraw = 
  ((op == `ADD) &&  apos &&  bpos) ? zadd :
  ((op == `ADD) &&  apos && ~bpos) ? zsub :
  ((op == `ADD) && ~apos &&  bpos) ? zsub^32'h80000000 :
  ((op == `ADD) && ~apos && ~bpos) ? zadd^32'h80000000 :

  ((op == `SUB) &&  apos &&  bpos) ? zsub :
  ((op == `SUB) &&  apos && ~bpos) ? zadd :
  ((op == `SUB) && ~apos &&  bpos) ? zadd^32'h80000000 :
  ((op == `SUB) && ~apos && ~bpos) ? zsub^32'h80000000 :

  32'hFFFFFFFF;


// oh how i hate to do this
// turn -0 (0x80000000) into true zero (0x00000000)
// wire [31:0] z;
assign z = (zraw == 32'h80000000) ? 32'h0 : zraw;

// FIXME Technically I think these are supposed to be OUTSIDE the module def
//`define DBG1
//`define DBG9

`ifdef DBG1
always @ (*) begin
  $display("%m fooo");
  if (op == `ADD) begin
    $display("%m..ADD a=bsr'%08X (%08X) b=bsr'%08X (%08X) z=bsr'%08X (%08X)",
        a, a, b, b, z, z);
  end else begin  
    $display("%m..SUB a=bsr'%08X (%08X) b=bsr'%08X (%08X) z=bsr'%08X (%08X)",
        a, a, b, b, z, z);
  end
`ifdef DBG9
  $display("%m    op=%1x apos=%1x bpos=%1x", op, apos, bpos);
  $display("%m    (op==SUB) = %x", (op==`SUB));
  $display("%m    (op==SUB) &&  apos &&  bpos) = %x", ((op == `SUB) &&  apos &&  bpos));
`endif
  $display("%m");
end
`endif

endmodule;


/*
  wire [31:0] a_plus_b;
  sradd ADD (

//`define SRADD_TEST1
`ifdef SRADD_TEST1
    // FIXME TEST CODE
    // 1 + .707 = 1.707?
    .a(32'h3f800000),
    .b(32'h3f3504f3),
`else
  `ifdef SRADD_TEST2
    // FIXME TEST CODE
    // 1 + 1 = 2?
    .a(32'h3f800000),
    .b(32'h3f800000),
  `else
    .a({a[`sign], a[`exponent], a[`mantissa]}),
    .b({a[`sign], b[`exponent], b[`mantissa]}),
  `endif
`endif

    .z(a_plus_b)
  );
*/
