// 0 for add, 1 for sub (matches designware why not)
`define ADD 1'b0
`define SUB 1'b1

// +/- sign bit
`define POS 1'b0
`define NEG 1'b1

module adder(
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

  ////////////////////////////////////////////////////////////////
  //wire [31:0] zm;
  srsub SUB (
    .a({`POS, a[`exponent], a[`mantissa]}),
    .b({`POS, b[`exponent], b[`mantissa]}),
    .z(z)
  );

/*
//////////////////////////////////////
//   op  sign(a)   sign(b)   result //
// -------------------------------- //
//   +      +         +      (a+b)  //
//   +      +         -      (a-b)  //
//   +      -         +     -(a-b)  //
//   +      -         -     -(a+b)  //
// -------------------------------- //
//   -      +         +      (a-b)  //
//   -      +         -      (a+b)  //
//   -      -         +     -(a+b)  //
//   -      -         -     -(a-b)  //
//////////////////////////////////////

// Sign bit shortcuts
wire as; assign as = a[`sign];
wire bs; assign bs = b[`sign];


wire [31:0] z;
assign z = 
  ((op == `ADD) &&  as &&  bs) ? (zp & 32'h00000000) :
  ((op == `ADD) &&  as && ~bs) ? (zm & 32'h00000000) :
  ((op == `ADD) && ~as &&  bs) ? (zm & 32'h10000000) :
  ((op == `ADD) && ~as && ~bs) ? (zp & 32'h10000000) :

  ((op == `SUB) &&  as &&  bs) ? (zm & 32'h00000000) :
  ((op == `SUB) &&  as && ~bs) ? (zp & 32'h00000000) :
  ((op == `SUB) && ~as &&  bs) ? (zp & 32'h10000000) :
  ((op == `SUB) && ~as && ~bs) ? (zm & 32'h10000000) :

  32'hFFFFFFFF;

*/
endmodule;
