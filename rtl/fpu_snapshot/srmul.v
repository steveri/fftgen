// z = a * b, all 32-bit (single-precision) floating point.
// Returns zero if underflow, NaN if overflow.

module srmul(
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

  ////////////////////////////////////////////////////////////////
  // Sign is easy.
  wire zs; assign zs = a[`sign] ^ b[`sign];

  ////////////////////////////////////////////////////////////////
  // Mantissa is hard. Remember mantissa is [22:0]

  // Restore hidden one's, use 48-bit precision
  wire [47:0] am; assign am = {24'b0, 1'b1, a[`mantissa]};
  wire [47:0] bm; assign bm = {24'b0, 1'b1, b[`mantissa]};
  wire [47:0] ab; assign ab = am * bm;

  // Normalized result will have leading '0' e.g. 01x01=0100
  // Else "too big", must make mantissa smaller (rshft 1) and exp bigger (add 1)
  wire too_big; assign too_big = (ab[47] == 1'b1);

  // am,bm range = 80,0000-FF,FFFF; ab range = 4000,0000,0000 - 8000,0000,0001
  wire [23:0] zm_true;   assign zm_true = too_big ? ab[47:24] : ab[46:23];
  wire [22:0] zm_hidden; assign zm_hidden = zm_true[22:0];

  // Final z mantissa is zm with hidden (implied) leading 'one' bit
  wire [22:0] zm; assign zm = zm_hidden[22:0];

  ////////////////////////////////////////////////////////////////
  // Exponent. Use 9-bit computation to get accurate final 8-bit result.
  wire [8:0] bias;  assign bias  = 9'd127;
  wire [8:0] a_exp; assign a_exp = {1'b0, a[`exponent]};
  wire [8:0] b_exp; assign b_exp = {1'b0, b[`exponent]};

  wire [8:0] ae_plus_be; assign ae_plus_be = a_exp + b_exp;
  wire [8:0] ze_prenorm; assign ze_prenorm = ae_plus_be - bias;
  wire [8:0] ze_norm;    assign ze_norm = too_big ? (ze_prenorm + 9'b1) : ze_prenorm;

  // Final z exponent
  wire [7:0] ze; assign ze = ze_norm[7:0];

  ////////////////////////////////////////////////////////////////
  // overflow and underflow
  wire ufw; assign ufw = too_big ? ((ae_plus_be + 9'b1) < bias) : (ae_plus_be < bias);
  wire ofw; assign ofw = (ze_norm[8] == 1'b1);

  ////////////////////////////////////////////////////////////////
/*
  assign z = (a==`zero) ? `zero : (
               (b==`zero) ? `zero : (
                (ufw)      ? `zero : (
                  (ofw)      ? `NaN :  (
                                 {zs, ze, zm} 
              ))));
*/

  assign z = (a==`zero) ? `zero : (
               (b==`zero) ? `zero : (
                  (ofw)      ? `NaN :  (
                                 {zs, ze, zm} 
              )));



// `define DBG1
// `define DBG9

`ifdef DBG1
  // DEBUGGING
  always @ (*) begin
    if ((a != 0) && (b != 0)) begin
//    if ((a != 0) && (b == 32'h40000000)) begin
      $display("srmul a=bsr'%08X (%08X) b=bsr'%08X (%08X) z=bsr'%08X (%08X)",
                a, a, b, b, z, z);
     `ifdef DBG9
        $display("srmul as=%1x bs=%1x zs=%1x", a[`sign], b[`sign], z[`sign]);
        $display("srmul ----");
        $display("srmul ae8=%09b be8=%09b ze8=%09b", a[`exponent], b[`exponent], z[`exponent]);
        $display("srmul ae9=%09b be9=%09b ze9=%09b", a_exp, b_exp, ze);
        $display("srmul   ae_plus_be=%09b", ae_plus_be);
        $display("srmul   ze_prenorm=%09b", ze_prenorm);
        $display("srmul   too_big=%1b ze_norm=%09b", too_big, ze_norm);
        $display("srmul aeb=%09b beb=%09b zeb=%09b", a_exp-bias, b_exp-bias, ze-bias);
        $display("srmul ----");
        $display("srmul am=%06X bm=%06X zm=%06X", am, bm, zm);
        $display("srmul ab=%012X ab[47:46]=%02b", ab, ab[47:46]);
        $display("srmul   zm_true=%06X",   zm_true);
        $display("srmul   zm_hidden=%06X", zm_hidden);
        $display("srmul   zm_true[23]=%1b ab[46]=%1b", zm_true[23], ab[46]);
        $display("srmul ----");
        $display("srmul ufw=%1b ofw=%1b", ufw, ofw);
        $display("srmul ");
     `endif
    end // if ((a != 0) && (b != 0))
  end // always @ (*)
`endif

endmodule
