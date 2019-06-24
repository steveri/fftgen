// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_fft__Syms.h"


//======================

void Vtop_fft::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vtop_fft::traceInit, &Vtop_fft::traceFull, &Vtop_fft::traceChg, this);
}
void Vtop_fft::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop_fft* t=(Vtop_fft*)userthis;
    Vtop_fft__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop_fft::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop_fft* t=(Vtop_fft*)userthis;
    Vtop_fft__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vtop_fft::traceInitThis(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop_fft::traceFullThis(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop_fft::traceInitThis__1(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+398,"clk",-1);
	vcdp->declBit  (c+399,"done",-1);
	vcdp->declBit  (c+398,"v clk",-1);
	vcdp->declBit  (c+399,"v done",-1);
	vcdp->declBit  (c+110,"v rst_n",-1);
	vcdp->declBit  (c+49,"v start",-1);
	vcdp->declBus  (c+396,"v BFLY0_op1_ix",-1,2,0);
	vcdp->declBus  (c+386,"v BFLY0_op2_ix",-1,2,0);
	vcdp->declBus  (c+387,"v BFLY0_access_type",-1,2,0);
	vcdp->declBus  (c+388,"v fftctl_cycle_num",-1,4,0);
	vcdp->declBit  (c+108,"v busy",-1);
	vcdp->declBit  (c+398,"v fftclk",-1);
	vcdp->declBus  (c+395,"v suppress_wz",-1,3,0);
	vcdp->declBus  (c+389,"v bypass_read",-1,3,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBit  (c+390+i*1,"v bufnum",(i+0));}}
	vcdp->declBus  (c+388,"v cycle_num",-1,4,0);
	vcdp->declBus  (c+83,"v BFLY0_twiddle_cos",-1,31,0);
	vcdp->declBus  (c+84,"v BFLY0_twiddle_sin",-1,31,0);
	vcdp->declQuad (c+123,"v BFLY0_in1_data",-1,63,0);
	vcdp->declQuad (c+125,"v BFLY0_in2_data",-1,63,0);
	vcdp->declQuad (c+127,"v BFLY0_out1_data",-1,63,0);
	vcdp->declQuad (c+129,"v BFLY0_out2_data",-1,63,0);
	vcdp->declBus  (c+102,"v BFLY0_op1_bnum",-1,1,0);
	vcdp->declBus  (c+85,"v BFLY0_op2_bnum",-1,1,0);
	vcdp->declBus  (c+397,"v BFLY0_op1_rnum",-1,0,0);
	vcdp->declBus  (c+394,"v BFLY0_op2_rnum",-1,0,0);
	// Tracing: v _shortrealtobits_0 // Ignored: Inlined leading underscore at genesis_verif/top_fft.v:136
	// Tracing: v _shortrealtobits_1 // Ignored: Inlined leading underscore at genesis_verif/top_fft.v:137
	vcdp->declBus  (c+385,"v cycle_counter",-1,31,0);
	vcdp->declBus  (c+396,"v BFLY0_op1_swizzle addr_i",-1,2,0);
	vcdp->declBus  (c+397,"v BFLY0_op1_swizzle rnum_o",-1,0,0);
	vcdp->declBus  (c+102,"v BFLY0_op1_swizzle bnum_o",-1,1,0);
	vcdp->declBus  (c+386,"v BFLY0_op2_swizzle addr_i",-1,2,0);
	vcdp->declBus  (c+394,"v BFLY0_op2_swizzle rnum_o",-1,0,0);
	vcdp->declBus  (c+85,"v BFLY0_op2_swizzle bnum_o",-1,1,0);
	vcdp->declBit  (c+398,"v BFLY0 fftclk",-1);
	vcdp->declBit  (c+131,"v BFLY0 ready",-1);
	vcdp->declQuad (c+123,"v BFLY0 in1",-1,63,0);
	vcdp->declQuad (c+125,"v BFLY0 in2",-1,63,0);
	vcdp->declBus  (c+83,"v BFLY0 twc",-1,31,0);
	vcdp->declBus  (c+84,"v BFLY0 tws",-1,31,0);
	vcdp->declQuad (c+127,"v BFLY0 out1",-1,63,0);
	vcdp->declQuad (c+129,"v BFLY0 out2",-1,63,0);
	vcdp->declBus  (c+132,"v BFLY0 t1",-1,31,0);
	vcdp->declBus  (c+133,"v BFLY0 t1a",-1,31,0);
	vcdp->declBus  (c+134,"v BFLY0 t1b",-1,31,0);
	vcdp->declBus  (c+135,"v BFLY0 t2",-1,31,0);
	vcdp->declBus  (c+136,"v BFLY0 t2a",-1,31,0);
	vcdp->declBus  (c+137,"v BFLY0 t2b",-1,31,0);
	vcdp->declBus  (c+400,"v BFLY0 status_t1",-1,7,0);
	vcdp->declBus  (c+401,"v BFLY0 status_t1a",-1,7,0);
	vcdp->declBus  (c+402,"v BFLY0 status_t1b",-1,7,0);
	vcdp->declBus  (c+403,"v BFLY0 status_t2",-1,7,0);
	vcdp->declBus  (c+404,"v BFLY0 status_t2a",-1,7,0);
	vcdp->declBus  (c+405,"v BFLY0 status_t2b",-1,7,0);
	vcdp->declBus  (c+406,"v BFLY0 status_o1r",-1,7,0);
	vcdp->declBus  (c+407,"v BFLY0 status_o1i",-1,7,0);
	vcdp->declBus  (c+408,"v BFLY0 status_o2r",-1,7,0);
	vcdp->declBus  (c+409,"v BFLY0 status_o2i",-1,7,0);
	vcdp->declBus  (c+133,"v BFLY0 sub_t1 a",-1,31,0);
	vcdp->declBus  (c+134,"v BFLY0 sub_t1 b",-1,31,0);
	vcdp->declBus  (c+132,"v BFLY0 sub_t1 z",-1,31,0);
	vcdp->declBit  (c+410,"v BFLY0 sub_t1 FPU op",-1);
	vcdp->declBus  (c+133,"v BFLY0 sub_t1 FPU a",-1,31,0);
	vcdp->declBus  (c+134,"v BFLY0 sub_t1 FPU b",-1,31,0);
	vcdp->declBus  (c+132,"v BFLY0 sub_t1 FPU z",-1,31,0);
	vcdp->declBus  (c+138,"v BFLY0 sub_t1 FPU abs_a",-1,31,0);
	vcdp->declBus  (c+139,"v BFLY0 sub_t1 FPU abs_b",-1,31,0);
	vcdp->declBus  (c+140,"v BFLY0 sub_t1 FPU zadd",-1,31,0);
	vcdp->declBus  (c+141,"v BFLY0 sub_t1 FPU zsub",-1,31,0);
	vcdp->declBit  (c+142,"v BFLY0 sub_t1 FPU apos",-1);
	vcdp->declBit  (c+143,"v BFLY0 sub_t1 FPU bpos",-1);
	vcdp->declBus  (c+144,"v BFLY0 sub_t1 FPU zraw",-1,31,0);
	vcdp->declBus  (c+138,"v BFLY0 sub_t1 FPU ADD a",-1,31,0);
	vcdp->declBus  (c+139,"v BFLY0 sub_t1 FPU ADD b",-1,31,0);
	vcdp->declBus  (c+140,"v BFLY0 sub_t1 FPU ADD z",-1,31,0);
	vcdp->declBit  (c+145,"v BFLY0 sub_t1 FPU ADD as",-1);
	vcdp->declBit  (c+146,"v BFLY0 sub_t1 FPU ADD bs",-1);
	vcdp->declBus  (c+147,"v BFLY0 sub_t1 FPU ADD ae",-1,7,0);
	vcdp->declBus  (c+148,"v BFLY0 sub_t1 FPU ADD be",-1,7,0);
	vcdp->declQuad (c+149,"v BFLY0 sub_t1 FPU ADD am",-1,47,0);
	vcdp->declQuad (c+151,"v BFLY0 sub_t1 FPU ADD bm",-1,47,0);
	vcdp->declBus  (c+153,"v BFLY0 sub_t1 FPU ADD ediff",-1,7,0);
	vcdp->declBit  (c+154,"v BFLY0 sub_t1 FPU ADD ignore_a",-1);
	vcdp->declBit  (c+155,"v BFLY0 sub_t1 FPU ADD ignore_b",-1);
	vcdp->declQuad (c+156,"v BFLY0 sub_t1 FPU ADD am_adj",-1,47,0);
	vcdp->declQuad (c+158,"v BFLY0 sub_t1 FPU ADD bm_adj",-1,47,0);
	vcdp->declBus  (c+160,"v BFLY0 sub_t1 FPU ADD ze",-1,7,0);
	vcdp->declQuad (c+161,"v BFLY0 sub_t1 FPU ADD am_plus_bm",-1,47,0);
	vcdp->declBus  (c+163,"v BFLY0 sub_t1 FPU ADD zm",-1,24,0);
	vcdp->declBus  (c+164,"v BFLY0 sub_t1 FPU ADD zm_final",-1,22,0);
	vcdp->declBus  (c+165,"v BFLY0 sub_t1 FPU ADD ze_final",-1,7,0);
	vcdp->declBus  (c+138,"v BFLY0 sub_t1 FPU SUB a",-1,31,0);
	vcdp->declBus  (c+139,"v BFLY0 sub_t1 FPU SUB b",-1,31,0);
	vcdp->declBus  (c+141,"v BFLY0 sub_t1 FPU SUB z",-1,31,0);
	vcdp->declBit  (c+145,"v BFLY0 sub_t1 FPU SUB as",-1);
	vcdp->declBit  (c+146,"v BFLY0 sub_t1 FPU SUB bs",-1);
	vcdp->declBus  (c+147,"v BFLY0 sub_t1 FPU SUB ae",-1,7,0);
	vcdp->declBus  (c+148,"v BFLY0 sub_t1 FPU SUB be",-1,7,0);
	vcdp->declQuad (c+149,"v BFLY0 sub_t1 FPU SUB am",-1,47,0);
	vcdp->declQuad (c+151,"v BFLY0 sub_t1 FPU SUB bm",-1,47,0);
	vcdp->declBus  (c+153,"v BFLY0 sub_t1 FPU SUB ediff",-1,7,0);
	vcdp->declBit  (c+154,"v BFLY0 sub_t1 FPU SUB ignore_a",-1);
	vcdp->declBit  (c+155,"v BFLY0 sub_t1 FPU SUB ignore_b",-1);
	vcdp->declQuad (c+166,"v BFLY0 sub_t1 FPU SUB am_adj",-1,47,0);
	vcdp->declQuad (c+168,"v BFLY0 sub_t1 FPU SUB bm_adj",-1,47,0);
	vcdp->declQuad (c+170,"v BFLY0 sub_t1 FPU SUB abs_am_minus_bm",-1,47,0);
	vcdp->declBus  (c+172,"v BFLY0 sub_t1 FPU SUB zm",-1,23,0);
	vcdp->declBus  (c+173,"v BFLY0 sub_t1 FPU SUB need_shift",-1,7,0);
	vcdp->declBus  (c+174,"v BFLY0 sub_t1 FPU SUB zm_final",-1,22,0);
	vcdp->declBus  (c+160,"v BFLY0 sub_t1 FPU SUB ze",-1,7,0);
	vcdp->declBus  (c+175,"v BFLY0 sub_t1 FPU SUB ze_final",-1,7,0);
	vcdp->declBus  (c+83,"v BFLY0 mult_t1a a",-1,31,0);
	vcdp->declBus  (c+176,"v BFLY0 mult_t1a b",-1,31,0);
	vcdp->declBus  (c+133,"v BFLY0 mult_t1a z",-1,31,0);
	vcdp->declBus  (c+83,"v BFLY0 mult_t1a MUL a",-1,31,0);
	vcdp->declBus  (c+176,"v BFLY0 mult_t1a MUL b",-1,31,0);
	vcdp->declBus  (c+133,"v BFLY0 mult_t1a MUL z",-1,31,0);
	vcdp->declBit  (c+98,"v BFLY0 mult_t1a MUL zs",-1);
	vcdp->declQuad (c+86,"v BFLY0 mult_t1a MUL am",-1,47,0);
	vcdp->declQuad (c+177,"v BFLY0 mult_t1a MUL bm",-1,47,0);
	vcdp->declQuad (c+179,"v BFLY0 mult_t1a MUL ab",-1,47,0);
	vcdp->declBit  (c+181,"v BFLY0 mult_t1a MUL too_big",-1);
	vcdp->declBus  (c+182,"v BFLY0 mult_t1a MUL zm_true",-1,23,0);
	vcdp->declBus  (c+183,"v BFLY0 mult_t1a MUL zm_hidden",-1,22,0);
	vcdp->declBus  (c+183,"v BFLY0 mult_t1a MUL zm",-1,22,0);
	vcdp->declBus  (c+411,"v BFLY0 mult_t1a MUL bias",-1,8,0);
	vcdp->declBus  (c+88,"v BFLY0 mult_t1a MUL a_exp",-1,8,0);
	vcdp->declBus  (c+184,"v BFLY0 mult_t1a MUL b_exp",-1,8,0);
	vcdp->declBus  (c+185,"v BFLY0 mult_t1a MUL ae_plus_be",-1,8,0);
	vcdp->declBus  (c+186,"v BFLY0 mult_t1a MUL ze_prenorm",-1,8,0);
	vcdp->declBus  (c+187,"v BFLY0 mult_t1a MUL ze_norm",-1,8,0);
	vcdp->declBus  (c+188,"v BFLY0 mult_t1a MUL ze",-1,7,0);
	vcdp->declBit  (c+189,"v BFLY0 mult_t1a MUL ufw",-1);
	vcdp->declBit  (c+190,"v BFLY0 mult_t1a MUL ofw",-1);
	vcdp->declBus  (c+84,"v BFLY0 mult_t1b a",-1,31,0);
	vcdp->declBus  (c+191,"v BFLY0 mult_t1b b",-1,31,0);
	vcdp->declBus  (c+134,"v BFLY0 mult_t1b z",-1,31,0);
	vcdp->declBus  (c+84,"v BFLY0 mult_t1b MUL a",-1,31,0);
	vcdp->declBus  (c+191,"v BFLY0 mult_t1b MUL b",-1,31,0);
	vcdp->declBus  (c+134,"v BFLY0 mult_t1b MUL z",-1,31,0);
	vcdp->declBit  (c+99,"v BFLY0 mult_t1b MUL zs",-1);
	vcdp->declQuad (c+89,"v BFLY0 mult_t1b MUL am",-1,47,0);
	vcdp->declQuad (c+192,"v BFLY0 mult_t1b MUL bm",-1,47,0);
	vcdp->declQuad (c+194,"v BFLY0 mult_t1b MUL ab",-1,47,0);
	vcdp->declBit  (c+196,"v BFLY0 mult_t1b MUL too_big",-1);
	vcdp->declBus  (c+197,"v BFLY0 mult_t1b MUL zm_true",-1,23,0);
	vcdp->declBus  (c+198,"v BFLY0 mult_t1b MUL zm_hidden",-1,22,0);
	vcdp->declBus  (c+198,"v BFLY0 mult_t1b MUL zm",-1,22,0);
	vcdp->declBus  (c+411,"v BFLY0 mult_t1b MUL bias",-1,8,0);
	vcdp->declBus  (c+91,"v BFLY0 mult_t1b MUL a_exp",-1,8,0);
	vcdp->declBus  (c+199,"v BFLY0 mult_t1b MUL b_exp",-1,8,0);
	vcdp->declBus  (c+200,"v BFLY0 mult_t1b MUL ae_plus_be",-1,8,0);
	vcdp->declBus  (c+201,"v BFLY0 mult_t1b MUL ze_prenorm",-1,8,0);
	vcdp->declBus  (c+202,"v BFLY0 mult_t1b MUL ze_norm",-1,8,0);
	vcdp->declBus  (c+203,"v BFLY0 mult_t1b MUL ze",-1,7,0);
	vcdp->declBit  (c+204,"v BFLY0 mult_t1b MUL ufw",-1);
	vcdp->declBit  (c+205,"v BFLY0 mult_t1b MUL ofw",-1);
	vcdp->declBus  (c+136,"v BFLY0 add_t2 a",-1,31,0);
	vcdp->declBus  (c+137,"v BFLY0 add_t2 b",-1,31,0);
	vcdp->declBus  (c+135,"v BFLY0 add_t2 z",-1,31,0);
	vcdp->declBit  (c+412,"v BFLY0 add_t2 FPU op",-1);
	vcdp->declBus  (c+136,"v BFLY0 add_t2 FPU a",-1,31,0);
	vcdp->declBus  (c+137,"v BFLY0 add_t2 FPU b",-1,31,0);
	vcdp->declBus  (c+135,"v BFLY0 add_t2 FPU z",-1,31,0);
	vcdp->declBus  (c+206,"v BFLY0 add_t2 FPU abs_a",-1,31,0);
	vcdp->declBus  (c+207,"v BFLY0 add_t2 FPU abs_b",-1,31,0);
	vcdp->declBus  (c+208,"v BFLY0 add_t2 FPU zadd",-1,31,0);
	vcdp->declBus  (c+209,"v BFLY0 add_t2 FPU zsub",-1,31,0);
	vcdp->declBit  (c+210,"v BFLY0 add_t2 FPU apos",-1);
	vcdp->declBit  (c+211,"v BFLY0 add_t2 FPU bpos",-1);
	vcdp->declBus  (c+212,"v BFLY0 add_t2 FPU zraw",-1,31,0);
	vcdp->declBus  (c+206,"v BFLY0 add_t2 FPU ADD a",-1,31,0);
	vcdp->declBus  (c+207,"v BFLY0 add_t2 FPU ADD b",-1,31,0);
	vcdp->declBus  (c+208,"v BFLY0 add_t2 FPU ADD z",-1,31,0);
	vcdp->declBit  (c+213,"v BFLY0 add_t2 FPU ADD as",-1);
	vcdp->declBit  (c+214,"v BFLY0 add_t2 FPU ADD bs",-1);
	vcdp->declBus  (c+215,"v BFLY0 add_t2 FPU ADD ae",-1,7,0);
	vcdp->declBus  (c+216,"v BFLY0 add_t2 FPU ADD be",-1,7,0);
	vcdp->declQuad (c+217,"v BFLY0 add_t2 FPU ADD am",-1,47,0);
	vcdp->declQuad (c+219,"v BFLY0 add_t2 FPU ADD bm",-1,47,0);
	vcdp->declBus  (c+221,"v BFLY0 add_t2 FPU ADD ediff",-1,7,0);
	vcdp->declBit  (c+222,"v BFLY0 add_t2 FPU ADD ignore_a",-1);
	vcdp->declBit  (c+223,"v BFLY0 add_t2 FPU ADD ignore_b",-1);
	vcdp->declQuad (c+224,"v BFLY0 add_t2 FPU ADD am_adj",-1,47,0);
	vcdp->declQuad (c+226,"v BFLY0 add_t2 FPU ADD bm_adj",-1,47,0);
	vcdp->declBus  (c+228,"v BFLY0 add_t2 FPU ADD ze",-1,7,0);
	vcdp->declQuad (c+229,"v BFLY0 add_t2 FPU ADD am_plus_bm",-1,47,0);
	vcdp->declBus  (c+231,"v BFLY0 add_t2 FPU ADD zm",-1,24,0);
	vcdp->declBus  (c+232,"v BFLY0 add_t2 FPU ADD zm_final",-1,22,0);
	vcdp->declBus  (c+233,"v BFLY0 add_t2 FPU ADD ze_final",-1,7,0);
	vcdp->declBus  (c+206,"v BFLY0 add_t2 FPU SUB a",-1,31,0);
	vcdp->declBus  (c+207,"v BFLY0 add_t2 FPU SUB b",-1,31,0);
	vcdp->declBus  (c+209,"v BFLY0 add_t2 FPU SUB z",-1,31,0);
	vcdp->declBit  (c+213,"v BFLY0 add_t2 FPU SUB as",-1);
	vcdp->declBit  (c+214,"v BFLY0 add_t2 FPU SUB bs",-1);
	vcdp->declBus  (c+215,"v BFLY0 add_t2 FPU SUB ae",-1,7,0);
	vcdp->declBus  (c+216,"v BFLY0 add_t2 FPU SUB be",-1,7,0);
	vcdp->declQuad (c+217,"v BFLY0 add_t2 FPU SUB am",-1,47,0);
	vcdp->declQuad (c+219,"v BFLY0 add_t2 FPU SUB bm",-1,47,0);
	vcdp->declBus  (c+221,"v BFLY0 add_t2 FPU SUB ediff",-1,7,0);
	vcdp->declBit  (c+222,"v BFLY0 add_t2 FPU SUB ignore_a",-1);
	vcdp->declBit  (c+223,"v BFLY0 add_t2 FPU SUB ignore_b",-1);
	vcdp->declQuad (c+234,"v BFLY0 add_t2 FPU SUB am_adj",-1,47,0);
	vcdp->declQuad (c+236,"v BFLY0 add_t2 FPU SUB bm_adj",-1,47,0);
	vcdp->declQuad (c+238,"v BFLY0 add_t2 FPU SUB abs_am_minus_bm",-1,47,0);
	vcdp->declBus  (c+240,"v BFLY0 add_t2 FPU SUB zm",-1,23,0);
	vcdp->declBus  (c+241,"v BFLY0 add_t2 FPU SUB need_shift",-1,7,0);
	vcdp->declBus  (c+242,"v BFLY0 add_t2 FPU SUB zm_final",-1,22,0);
	vcdp->declBus  (c+228,"v BFLY0 add_t2 FPU SUB ze",-1,7,0);
	vcdp->declBus  (c+243,"v BFLY0 add_t2 FPU SUB ze_final",-1,7,0);
	vcdp->declBus  (c+84,"v BFLY0 mult_t2a a",-1,31,0);
	vcdp->declBus  (c+176,"v BFLY0 mult_t2a b",-1,31,0);
	vcdp->declBus  (c+136,"v BFLY0 mult_t2a z",-1,31,0);
	vcdp->declBus  (c+84,"v BFLY0 mult_t2a MUL a",-1,31,0);
	vcdp->declBus  (c+176,"v BFLY0 mult_t2a MUL b",-1,31,0);
	vcdp->declBus  (c+136,"v BFLY0 mult_t2a MUL z",-1,31,0);
	vcdp->declBit  (c+100,"v BFLY0 mult_t2a MUL zs",-1);
	vcdp->declQuad (c+89,"v BFLY0 mult_t2a MUL am",-1,47,0);
	vcdp->declQuad (c+177,"v BFLY0 mult_t2a MUL bm",-1,47,0);
	vcdp->declQuad (c+244,"v BFLY0 mult_t2a MUL ab",-1,47,0);
	vcdp->declBit  (c+246,"v BFLY0 mult_t2a MUL too_big",-1);
	vcdp->declBus  (c+247,"v BFLY0 mult_t2a MUL zm_true",-1,23,0);
	vcdp->declBus  (c+248,"v BFLY0 mult_t2a MUL zm_hidden",-1,22,0);
	vcdp->declBus  (c+248,"v BFLY0 mult_t2a MUL zm",-1,22,0);
	vcdp->declBus  (c+411,"v BFLY0 mult_t2a MUL bias",-1,8,0);
	vcdp->declBus  (c+91,"v BFLY0 mult_t2a MUL a_exp",-1,8,0);
	vcdp->declBus  (c+184,"v BFLY0 mult_t2a MUL b_exp",-1,8,0);
	vcdp->declBus  (c+249,"v BFLY0 mult_t2a MUL ae_plus_be",-1,8,0);
	vcdp->declBus  (c+250,"v BFLY0 mult_t2a MUL ze_prenorm",-1,8,0);
	vcdp->declBus  (c+251,"v BFLY0 mult_t2a MUL ze_norm",-1,8,0);
	vcdp->declBus  (c+252,"v BFLY0 mult_t2a MUL ze",-1,7,0);
	vcdp->declBit  (c+253,"v BFLY0 mult_t2a MUL ufw",-1);
	vcdp->declBit  (c+254,"v BFLY0 mult_t2a MUL ofw",-1);
	vcdp->declBus  (c+83,"v BFLY0 mult_t2b a",-1,31,0);
	vcdp->declBus  (c+191,"v BFLY0 mult_t2b b",-1,31,0);
	vcdp->declBus  (c+137,"v BFLY0 mult_t2b z",-1,31,0);
	vcdp->declBus  (c+83,"v BFLY0 mult_t2b MUL a",-1,31,0);
	vcdp->declBus  (c+191,"v BFLY0 mult_t2b MUL b",-1,31,0);
	vcdp->declBus  (c+137,"v BFLY0 mult_t2b MUL z",-1,31,0);
	vcdp->declBit  (c+101,"v BFLY0 mult_t2b MUL zs",-1);
	vcdp->declQuad (c+86,"v BFLY0 mult_t2b MUL am",-1,47,0);
	vcdp->declQuad (c+192,"v BFLY0 mult_t2b MUL bm",-1,47,0);
	vcdp->declQuad (c+255,"v BFLY0 mult_t2b MUL ab",-1,47,0);
	vcdp->declBit  (c+257,"v BFLY0 mult_t2b MUL too_big",-1);
	vcdp->declBus  (c+258,"v BFLY0 mult_t2b MUL zm_true",-1,23,0);
	vcdp->declBus  (c+259,"v BFLY0 mult_t2b MUL zm_hidden",-1,22,0);
	vcdp->declBus  (c+259,"v BFLY0 mult_t2b MUL zm",-1,22,0);
	vcdp->declBus  (c+411,"v BFLY0 mult_t2b MUL bias",-1,8,0);
	vcdp->declBus  (c+88,"v BFLY0 mult_t2b MUL a_exp",-1,8,0);
	vcdp->declBus  (c+199,"v BFLY0 mult_t2b MUL b_exp",-1,8,0);
	vcdp->declBus  (c+260,"v BFLY0 mult_t2b MUL ae_plus_be",-1,8,0);
	vcdp->declBus  (c+261,"v BFLY0 mult_t2b MUL ze_prenorm",-1,8,0);
	vcdp->declBus  (c+262,"v BFLY0 mult_t2b MUL ze_norm",-1,8,0);
	vcdp->declBus  (c+263,"v BFLY0 mult_t2b MUL ze",-1,7,0);
	vcdp->declBit  (c+264,"v BFLY0 mult_t2b MUL ufw",-1);
	vcdp->declBit  (c+265,"v BFLY0 mult_t2b MUL ofw",-1);
	vcdp->declBus  (c+266,"v BFLY0 add_o1r a",-1,31,0);
	vcdp->declBus  (c+132,"v BFLY0 add_o1r b",-1,31,0);
	vcdp->declBus  (c+267,"v BFLY0 add_o1r z",-1,31,0);
	vcdp->declBit  (c+412,"v BFLY0 add_o1r FPU op",-1);
	vcdp->declBus  (c+266,"v BFLY0 add_o1r FPU a",-1,31,0);
	vcdp->declBus  (c+132,"v BFLY0 add_o1r FPU b",-1,31,0);
	vcdp->declBus  (c+267,"v BFLY0 add_o1r FPU z",-1,31,0);
	vcdp->declBus  (c+268,"v BFLY0 add_o1r FPU abs_a",-1,31,0);
	vcdp->declBus  (c+269,"v BFLY0 add_o1r FPU abs_b",-1,31,0);
	vcdp->declBus  (c+270,"v BFLY0 add_o1r FPU zadd",-1,31,0);
	vcdp->declBus  (c+271,"v BFLY0 add_o1r FPU zsub",-1,31,0);
	vcdp->declBit  (c+272,"v BFLY0 add_o1r FPU apos",-1);
	vcdp->declBit  (c+273,"v BFLY0 add_o1r FPU bpos",-1);
	vcdp->declBus  (c+274,"v BFLY0 add_o1r FPU zraw",-1,31,0);
	vcdp->declBus  (c+268,"v BFLY0 add_o1r FPU ADD a",-1,31,0);
	vcdp->declBus  (c+269,"v BFLY0 add_o1r FPU ADD b",-1,31,0);
	vcdp->declBus  (c+270,"v BFLY0 add_o1r FPU ADD z",-1,31,0);
	vcdp->declBit  (c+275,"v BFLY0 add_o1r FPU ADD as",-1);
	vcdp->declBit  (c+276,"v BFLY0 add_o1r FPU ADD bs",-1);
	vcdp->declBus  (c+277,"v BFLY0 add_o1r FPU ADD ae",-1,7,0);
	vcdp->declBus  (c+278,"v BFLY0 add_o1r FPU ADD be",-1,7,0);
	vcdp->declQuad (c+279,"v BFLY0 add_o1r FPU ADD am",-1,47,0);
	vcdp->declQuad (c+281,"v BFLY0 add_o1r FPU ADD bm",-1,47,0);
	vcdp->declBus  (c+283,"v BFLY0 add_o1r FPU ADD ediff",-1,7,0);
	vcdp->declBit  (c+284,"v BFLY0 add_o1r FPU ADD ignore_a",-1);
	vcdp->declBit  (c+285,"v BFLY0 add_o1r FPU ADD ignore_b",-1);
	vcdp->declQuad (c+286,"v BFLY0 add_o1r FPU ADD am_adj",-1,47,0);
	vcdp->declQuad (c+288,"v BFLY0 add_o1r FPU ADD bm_adj",-1,47,0);
	vcdp->declBus  (c+290,"v BFLY0 add_o1r FPU ADD ze",-1,7,0);
	vcdp->declQuad (c+291,"v BFLY0 add_o1r FPU ADD am_plus_bm",-1,47,0);
	vcdp->declBus  (c+293,"v BFLY0 add_o1r FPU ADD zm",-1,24,0);
	vcdp->declBus  (c+294,"v BFLY0 add_o1r FPU ADD zm_final",-1,22,0);
	vcdp->declBus  (c+295,"v BFLY0 add_o1r FPU ADD ze_final",-1,7,0);
	vcdp->declBus  (c+268,"v BFLY0 add_o1r FPU SUB a",-1,31,0);
	vcdp->declBus  (c+269,"v BFLY0 add_o1r FPU SUB b",-1,31,0);
	vcdp->declBus  (c+271,"v BFLY0 add_o1r FPU SUB z",-1,31,0);
	vcdp->declBit  (c+275,"v BFLY0 add_o1r FPU SUB as",-1);
	vcdp->declBit  (c+276,"v BFLY0 add_o1r FPU SUB bs",-1);
	vcdp->declBus  (c+277,"v BFLY0 add_o1r FPU SUB ae",-1,7,0);
	vcdp->declBus  (c+278,"v BFLY0 add_o1r FPU SUB be",-1,7,0);
	vcdp->declQuad (c+279,"v BFLY0 add_o1r FPU SUB am",-1,47,0);
	vcdp->declQuad (c+281,"v BFLY0 add_o1r FPU SUB bm",-1,47,0);
	vcdp->declBus  (c+283,"v BFLY0 add_o1r FPU SUB ediff",-1,7,0);
	vcdp->declBit  (c+284,"v BFLY0 add_o1r FPU SUB ignore_a",-1);
	vcdp->declBit  (c+285,"v BFLY0 add_o1r FPU SUB ignore_b",-1);
	vcdp->declQuad (c+296,"v BFLY0 add_o1r FPU SUB am_adj",-1,47,0);
	vcdp->declQuad (c+298,"v BFLY0 add_o1r FPU SUB bm_adj",-1,47,0);
	vcdp->declQuad (c+300,"v BFLY0 add_o1r FPU SUB abs_am_minus_bm",-1,47,0);
	vcdp->declBus  (c+302,"v BFLY0 add_o1r FPU SUB zm",-1,23,0);
	vcdp->declBus  (c+303,"v BFLY0 add_o1r FPU SUB need_shift",-1,7,0);
	vcdp->declBus  (c+304,"v BFLY0 add_o1r FPU SUB zm_final",-1,22,0);
	vcdp->declBus  (c+290,"v BFLY0 add_o1r FPU SUB ze",-1,7,0);
	vcdp->declBus  (c+305,"v BFLY0 add_o1r FPU SUB ze_final",-1,7,0);
	vcdp->declBus  (c+306,"v BFLY0 add_o1i a",-1,31,0);
	vcdp->declBus  (c+135,"v BFLY0 add_o1i b",-1,31,0);
	vcdp->declBus  (c+307,"v BFLY0 add_o1i z",-1,31,0);
	vcdp->declBit  (c+412,"v BFLY0 add_o1i FPU op",-1);
	vcdp->declBus  (c+306,"v BFLY0 add_o1i FPU a",-1,31,0);
	vcdp->declBus  (c+135,"v BFLY0 add_o1i FPU b",-1,31,0);
	vcdp->declBus  (c+307,"v BFLY0 add_o1i FPU z",-1,31,0);
	vcdp->declBus  (c+308,"v BFLY0 add_o1i FPU abs_a",-1,31,0);
	vcdp->declBus  (c+309,"v BFLY0 add_o1i FPU abs_b",-1,31,0);
	vcdp->declBus  (c+310,"v BFLY0 add_o1i FPU zadd",-1,31,0);
	vcdp->declBus  (c+311,"v BFLY0 add_o1i FPU zsub",-1,31,0);
	vcdp->declBit  (c+312,"v BFLY0 add_o1i FPU apos",-1);
	vcdp->declBit  (c+313,"v BFLY0 add_o1i FPU bpos",-1);
	vcdp->declBus  (c+314,"v BFLY0 add_o1i FPU zraw",-1,31,0);
	vcdp->declBus  (c+308,"v BFLY0 add_o1i FPU ADD a",-1,31,0);
	vcdp->declBus  (c+309,"v BFLY0 add_o1i FPU ADD b",-1,31,0);
	vcdp->declBus  (c+310,"v BFLY0 add_o1i FPU ADD z",-1,31,0);
	vcdp->declBit  (c+315,"v BFLY0 add_o1i FPU ADD as",-1);
	vcdp->declBit  (c+316,"v BFLY0 add_o1i FPU ADD bs",-1);
	vcdp->declBus  (c+317,"v BFLY0 add_o1i FPU ADD ae",-1,7,0);
	vcdp->declBus  (c+318,"v BFLY0 add_o1i FPU ADD be",-1,7,0);
	vcdp->declQuad (c+319,"v BFLY0 add_o1i FPU ADD am",-1,47,0);
	vcdp->declQuad (c+321,"v BFLY0 add_o1i FPU ADD bm",-1,47,0);
	vcdp->declBus  (c+323,"v BFLY0 add_o1i FPU ADD ediff",-1,7,0);
	vcdp->declBit  (c+324,"v BFLY0 add_o1i FPU ADD ignore_a",-1);
	vcdp->declBit  (c+325,"v BFLY0 add_o1i FPU ADD ignore_b",-1);
	vcdp->declQuad (c+326,"v BFLY0 add_o1i FPU ADD am_adj",-1,47,0);
	vcdp->declQuad (c+328,"v BFLY0 add_o1i FPU ADD bm_adj",-1,47,0);
	vcdp->declBus  (c+330,"v BFLY0 add_o1i FPU ADD ze",-1,7,0);
	vcdp->declQuad (c+331,"v BFLY0 add_o1i FPU ADD am_plus_bm",-1,47,0);
	vcdp->declBus  (c+333,"v BFLY0 add_o1i FPU ADD zm",-1,24,0);
	vcdp->declBus  (c+334,"v BFLY0 add_o1i FPU ADD zm_final",-1,22,0);
	vcdp->declBus  (c+335,"v BFLY0 add_o1i FPU ADD ze_final",-1,7,0);
	vcdp->declBus  (c+308,"v BFLY0 add_o1i FPU SUB a",-1,31,0);
	vcdp->declBus  (c+309,"v BFLY0 add_o1i FPU SUB b",-1,31,0);
	vcdp->declBus  (c+311,"v BFLY0 add_o1i FPU SUB z",-1,31,0);
	vcdp->declBit  (c+315,"v BFLY0 add_o1i FPU SUB as",-1);
	vcdp->declBit  (c+316,"v BFLY0 add_o1i FPU SUB bs",-1);
	vcdp->declBus  (c+317,"v BFLY0 add_o1i FPU SUB ae",-1,7,0);
	vcdp->declBus  (c+318,"v BFLY0 add_o1i FPU SUB be",-1,7,0);
	vcdp->declQuad (c+319,"v BFLY0 add_o1i FPU SUB am",-1,47,0);
	vcdp->declQuad (c+321,"v BFLY0 add_o1i FPU SUB bm",-1,47,0);
	vcdp->declBus  (c+323,"v BFLY0 add_o1i FPU SUB ediff",-1,7,0);
	vcdp->declBit  (c+324,"v BFLY0 add_o1i FPU SUB ignore_a",-1);
	vcdp->declBit  (c+325,"v BFLY0 add_o1i FPU SUB ignore_b",-1);
	vcdp->declQuad (c+336,"v BFLY0 add_o1i FPU SUB am_adj",-1,47,0);
	vcdp->declQuad (c+338,"v BFLY0 add_o1i FPU SUB bm_adj",-1,47,0);
	vcdp->declQuad (c+340,"v BFLY0 add_o1i FPU SUB abs_am_minus_bm",-1,47,0);
	vcdp->declBus  (c+342,"v BFLY0 add_o1i FPU SUB zm",-1,23,0);
	vcdp->declBus  (c+343,"v BFLY0 add_o1i FPU SUB need_shift",-1,7,0);
	vcdp->declBus  (c+344,"v BFLY0 add_o1i FPU SUB zm_final",-1,22,0);
	vcdp->declBus  (c+330,"v BFLY0 add_o1i FPU SUB ze",-1,7,0);
	vcdp->declBus  (c+345,"v BFLY0 add_o1i FPU SUB ze_final",-1,7,0);
	vcdp->declBus  (c+266,"v BFLY0 sub_o2r a",-1,31,0);
	vcdp->declBus  (c+132,"v BFLY0 sub_o2r b",-1,31,0);
	vcdp->declBus  (c+346,"v BFLY0 sub_o2r z",-1,31,0);
	vcdp->declBit  (c+410,"v BFLY0 sub_o2r FPU op",-1);
	vcdp->declBus  (c+266,"v BFLY0 sub_o2r FPU a",-1,31,0);
	vcdp->declBus  (c+132,"v BFLY0 sub_o2r FPU b",-1,31,0);
	vcdp->declBus  (c+346,"v BFLY0 sub_o2r FPU z",-1,31,0);
	vcdp->declBus  (c+268,"v BFLY0 sub_o2r FPU abs_a",-1,31,0);
	vcdp->declBus  (c+269,"v BFLY0 sub_o2r FPU abs_b",-1,31,0);
	vcdp->declBus  (c+270,"v BFLY0 sub_o2r FPU zadd",-1,31,0);
	vcdp->declBus  (c+271,"v BFLY0 sub_o2r FPU zsub",-1,31,0);
	vcdp->declBit  (c+272,"v BFLY0 sub_o2r FPU apos",-1);
	vcdp->declBit  (c+273,"v BFLY0 sub_o2r FPU bpos",-1);
	vcdp->declBus  (c+347,"v BFLY0 sub_o2r FPU zraw",-1,31,0);
	vcdp->declBus  (c+268,"v BFLY0 sub_o2r FPU ADD a",-1,31,0);
	vcdp->declBus  (c+269,"v BFLY0 sub_o2r FPU ADD b",-1,31,0);
	vcdp->declBus  (c+270,"v BFLY0 sub_o2r FPU ADD z",-1,31,0);
	vcdp->declBit  (c+275,"v BFLY0 sub_o2r FPU ADD as",-1);
	vcdp->declBit  (c+276,"v BFLY0 sub_o2r FPU ADD bs",-1);
	vcdp->declBus  (c+277,"v BFLY0 sub_o2r FPU ADD ae",-1,7,0);
	vcdp->declBus  (c+278,"v BFLY0 sub_o2r FPU ADD be",-1,7,0);
	vcdp->declQuad (c+279,"v BFLY0 sub_o2r FPU ADD am",-1,47,0);
	vcdp->declQuad (c+281,"v BFLY0 sub_o2r FPU ADD bm",-1,47,0);
	vcdp->declBus  (c+283,"v BFLY0 sub_o2r FPU ADD ediff",-1,7,0);
	vcdp->declBit  (c+284,"v BFLY0 sub_o2r FPU ADD ignore_a",-1);
	vcdp->declBit  (c+285,"v BFLY0 sub_o2r FPU ADD ignore_b",-1);
	vcdp->declQuad (c+286,"v BFLY0 sub_o2r FPU ADD am_adj",-1,47,0);
	vcdp->declQuad (c+288,"v BFLY0 sub_o2r FPU ADD bm_adj",-1,47,0);
	vcdp->declBus  (c+290,"v BFLY0 sub_o2r FPU ADD ze",-1,7,0);
	vcdp->declQuad (c+291,"v BFLY0 sub_o2r FPU ADD am_plus_bm",-1,47,0);
	vcdp->declBus  (c+293,"v BFLY0 sub_o2r FPU ADD zm",-1,24,0);
	vcdp->declBus  (c+294,"v BFLY0 sub_o2r FPU ADD zm_final",-1,22,0);
	vcdp->declBus  (c+295,"v BFLY0 sub_o2r FPU ADD ze_final",-1,7,0);
	vcdp->declBus  (c+268,"v BFLY0 sub_o2r FPU SUB a",-1,31,0);
	vcdp->declBus  (c+269,"v BFLY0 sub_o2r FPU SUB b",-1,31,0);
	vcdp->declBus  (c+271,"v BFLY0 sub_o2r FPU SUB z",-1,31,0);
	vcdp->declBit  (c+275,"v BFLY0 sub_o2r FPU SUB as",-1);
	vcdp->declBit  (c+276,"v BFLY0 sub_o2r FPU SUB bs",-1);
	vcdp->declBus  (c+277,"v BFLY0 sub_o2r FPU SUB ae",-1,7,0);
	vcdp->declBus  (c+278,"v BFLY0 sub_o2r FPU SUB be",-1,7,0);
	vcdp->declQuad (c+279,"v BFLY0 sub_o2r FPU SUB am",-1,47,0);
	vcdp->declQuad (c+281,"v BFLY0 sub_o2r FPU SUB bm",-1,47,0);
	vcdp->declBus  (c+283,"v BFLY0 sub_o2r FPU SUB ediff",-1,7,0);
	vcdp->declBit  (c+284,"v BFLY0 sub_o2r FPU SUB ignore_a",-1);
	vcdp->declBit  (c+285,"v BFLY0 sub_o2r FPU SUB ignore_b",-1);
	vcdp->declQuad (c+296,"v BFLY0 sub_o2r FPU SUB am_adj",-1,47,0);
	vcdp->declQuad (c+298,"v BFLY0 sub_o2r FPU SUB bm_adj",-1,47,0);
	vcdp->declQuad (c+300,"v BFLY0 sub_o2r FPU SUB abs_am_minus_bm",-1,47,0);
	vcdp->declBus  (c+302,"v BFLY0 sub_o2r FPU SUB zm",-1,23,0);
	vcdp->declBus  (c+303,"v BFLY0 sub_o2r FPU SUB need_shift",-1,7,0);
	vcdp->declBus  (c+304,"v BFLY0 sub_o2r FPU SUB zm_final",-1,22,0);
	vcdp->declBus  (c+290,"v BFLY0 sub_o2r FPU SUB ze",-1,7,0);
	vcdp->declBus  (c+305,"v BFLY0 sub_o2r FPU SUB ze_final",-1,7,0);
	vcdp->declBus  (c+306,"v BFLY0 sub_o2i a",-1,31,0);
	vcdp->declBus  (c+135,"v BFLY0 sub_o2i b",-1,31,0);
	vcdp->declBus  (c+348,"v BFLY0 sub_o2i z",-1,31,0);
	vcdp->declBit  (c+410,"v BFLY0 sub_o2i FPU op",-1);
	vcdp->declBus  (c+306,"v BFLY0 sub_o2i FPU a",-1,31,0);
	vcdp->declBus  (c+135,"v BFLY0 sub_o2i FPU b",-1,31,0);
	vcdp->declBus  (c+348,"v BFLY0 sub_o2i FPU z",-1,31,0);
	vcdp->declBus  (c+308,"v BFLY0 sub_o2i FPU abs_a",-1,31,0);
	vcdp->declBus  (c+309,"v BFLY0 sub_o2i FPU abs_b",-1,31,0);
	vcdp->declBus  (c+310,"v BFLY0 sub_o2i FPU zadd",-1,31,0);
	vcdp->declBus  (c+311,"v BFLY0 sub_o2i FPU zsub",-1,31,0);
	vcdp->declBit  (c+312,"v BFLY0 sub_o2i FPU apos",-1);
	vcdp->declBit  (c+313,"v BFLY0 sub_o2i FPU bpos",-1);
	vcdp->declBus  (c+349,"v BFLY0 sub_o2i FPU zraw",-1,31,0);
	vcdp->declBus  (c+308,"v BFLY0 sub_o2i FPU ADD a",-1,31,0);
	vcdp->declBus  (c+309,"v BFLY0 sub_o2i FPU ADD b",-1,31,0);
	vcdp->declBus  (c+310,"v BFLY0 sub_o2i FPU ADD z",-1,31,0);
	vcdp->declBit  (c+315,"v BFLY0 sub_o2i FPU ADD as",-1);
	vcdp->declBit  (c+316,"v BFLY0 sub_o2i FPU ADD bs",-1);
	vcdp->declBus  (c+317,"v BFLY0 sub_o2i FPU ADD ae",-1,7,0);
	vcdp->declBus  (c+318,"v BFLY0 sub_o2i FPU ADD be",-1,7,0);
	vcdp->declQuad (c+319,"v BFLY0 sub_o2i FPU ADD am",-1,47,0);
	vcdp->declQuad (c+321,"v BFLY0 sub_o2i FPU ADD bm",-1,47,0);
	vcdp->declBus  (c+323,"v BFLY0 sub_o2i FPU ADD ediff",-1,7,0);
	vcdp->declBit  (c+324,"v BFLY0 sub_o2i FPU ADD ignore_a",-1);
	vcdp->declBit  (c+325,"v BFLY0 sub_o2i FPU ADD ignore_b",-1);
	vcdp->declQuad (c+326,"v BFLY0 sub_o2i FPU ADD am_adj",-1,47,0);
	vcdp->declQuad (c+328,"v BFLY0 sub_o2i FPU ADD bm_adj",-1,47,0);
	vcdp->declBus  (c+330,"v BFLY0 sub_o2i FPU ADD ze",-1,7,0);
	vcdp->declQuad (c+331,"v BFLY0 sub_o2i FPU ADD am_plus_bm",-1,47,0);
	vcdp->declBus  (c+333,"v BFLY0 sub_o2i FPU ADD zm",-1,24,0);
	vcdp->declBus  (c+334,"v BFLY0 sub_o2i FPU ADD zm_final",-1,22,0);
	vcdp->declBus  (c+335,"v BFLY0 sub_o2i FPU ADD ze_final",-1,7,0);
	vcdp->declBus  (c+308,"v BFLY0 sub_o2i FPU SUB a",-1,31,0);
	vcdp->declBus  (c+309,"v BFLY0 sub_o2i FPU SUB b",-1,31,0);
	vcdp->declBus  (c+311,"v BFLY0 sub_o2i FPU SUB z",-1,31,0);
	vcdp->declBit  (c+315,"v BFLY0 sub_o2i FPU SUB as",-1);
	vcdp->declBit  (c+316,"v BFLY0 sub_o2i FPU SUB bs",-1);
	vcdp->declBus  (c+317,"v BFLY0 sub_o2i FPU SUB ae",-1,7,0);
	vcdp->declBus  (c+318,"v BFLY0 sub_o2i FPU SUB be",-1,7,0);
	vcdp->declQuad (c+319,"v BFLY0 sub_o2i FPU SUB am",-1,47,0);
	vcdp->declQuad (c+321,"v BFLY0 sub_o2i FPU SUB bm",-1,47,0);
	vcdp->declBus  (c+323,"v BFLY0 sub_o2i FPU SUB ediff",-1,7,0);
	vcdp->declBit  (c+324,"v BFLY0 sub_o2i FPU SUB ignore_a",-1);
	vcdp->declBit  (c+325,"v BFLY0 sub_o2i FPU SUB ignore_b",-1);
	vcdp->declQuad (c+336,"v BFLY0 sub_o2i FPU SUB am_adj",-1,47,0);
	vcdp->declQuad (c+338,"v BFLY0 sub_o2i FPU SUB bm_adj",-1,47,0);
	vcdp->declQuad (c+340,"v BFLY0 sub_o2i FPU SUB abs_am_minus_bm",-1,47,0);
	vcdp->declBus  (c+342,"v BFLY0 sub_o2i FPU SUB zm",-1,23,0);
	vcdp->declBus  (c+343,"v BFLY0 sub_o2i FPU SUB need_shift",-1,7,0);
	vcdp->declBus  (c+344,"v BFLY0 sub_o2i FPU SUB zm_final",-1,22,0);
	vcdp->declBus  (c+330,"v BFLY0 sub_o2i FPU SUB ze",-1,7,0);
	vcdp->declBus  (c+345,"v BFLY0 sub_o2i FPU SUB ze_final",-1,7,0);
	vcdp->declBit  (c+398,"v fftram clk_i",-1);
	vcdp->declBus  (c+102,"v fftram BFLY0_op1_bnum_i",-1,1,0);
	vcdp->declBus  (c+85,"v fftram BFLY0_op2_bnum_i",-1,1,0);
	vcdp->declBus  (c+397,"v fftram BFLY0_op1_rnum_i",-1,0,0);
	vcdp->declBus  (c+394,"v fftram BFLY0_op2_rnum_i",-1,0,0);
	vcdp->declQuad (c+123,"v fftram BFLY0_in1_data_o",-1,63,0);
	vcdp->declQuad (c+125,"v fftram BFLY0_in2_data_o",-1,63,0);
	vcdp->declQuad (c+127,"v fftram BFLY0_out1_data_i",-1,63,0);
	vcdp->declQuad (c+129,"v fftram BFLY0_out2_data_i",-1,63,0);
	vcdp->declBus  (c+395,"v fftram suppress_wz_i",-1,3,0);
	vcdp->declBit  (c+350,"v fftram fft_started",-1);
	vcdp->declBus  (c+111,"v fftram SRAM000_ix",-1,0,0);
	vcdp->declQuad (c+351,"v fftram SRAM000_rd_data",-1,63,0);
	vcdp->declQuad (c+353,"v fftram SRAM000_wr_data",-1,63,0);
	vcdp->declBit  (c+355,"v fftram SRAM000_ez",-1);
	vcdp->declBit  (c+381,"v fftram SRAM000_wz",-1);
	vcdp->declBus  (c+112,"v fftram SRAM001_ix",-1,0,0);
	vcdp->declQuad (c+356,"v fftram SRAM001_rd_data",-1,63,0);
	vcdp->declQuad (c+358,"v fftram SRAM001_wr_data",-1,63,0);
	vcdp->declBit  (c+360,"v fftram SRAM001_ez",-1);
	vcdp->declBit  (c+382,"v fftram SRAM001_wz",-1);
	vcdp->declBus  (c+113,"v fftram SRAM002_ix",-1,0,0);
	vcdp->declQuad (c+361,"v fftram SRAM002_rd_data",-1,63,0);
	vcdp->declQuad (c+363,"v fftram SRAM002_wr_data",-1,63,0);
	vcdp->declBit  (c+365,"v fftram SRAM002_ez",-1);
	vcdp->declBit  (c+383,"v fftram SRAM002_wz",-1);
	vcdp->declBus  (c+114,"v fftram SRAM003_ix",-1,0,0);
	vcdp->declQuad (c+366,"v fftram SRAM003_rd_data",-1,63,0);
	vcdp->declQuad (c+368,"v fftram SRAM003_wr_data",-1,63,0);
	vcdp->declBit  (c+370,"v fftram SRAM003_ez",-1);
	vcdp->declBit  (c+384,"v fftram SRAM003_wz",-1);
	vcdp->declBus  (c+50,"v fftram cycle_num",-1,3,0);
	vcdp->declBit  (c+92,"v fftram bypass_time",-1);
	vcdp->declBit  (c+115,"v fftram SRAM000_active",-1);
	vcdp->declBit  (c+116,"v fftram SRAM001_active",-1);
	vcdp->declBit  (c+117,"v fftram SRAM002_active",-1);
	vcdp->declBit  (c+118,"v fftram SRAM003_active",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBit  (c+51+i*1,"v fftram bypass_valid",(i+0));}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+55+i*1,"v fftram bypassed_rnum",(i+0),0,0);}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declQuad (c+59+i*2,"v fftram bypassed_data",(i+0),63,0);}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declQuad (c+371+i*2,"v fftram sram_or_buf",(i+0),63,0);}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declBit  (c+119+i*1,"v fftram BFLY0_op1_match",(i+0));}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declBit  (c+103+i*1,"v fftram BFLY0_op2_match",(i+0));}}
	vcdp->declBit  (c+398,"v fftram SRAM000 clk_i",-1);
	vcdp->declBit  (c+355,"v fftram SRAM000 ez_i",-1);
	vcdp->declBit  (c+381,"v fftram SRAM000 wz_i",-1);
	vcdp->declBus  (c+111,"v fftram SRAM000 addr_i",-1,0,0);
	vcdp->declQuad (c+351,"v fftram SRAM000 rd_data_o",-1,63,0);
	vcdp->declQuad (c+353,"v fftram SRAM000 wr_data_i",-1,63,0);
	{int i; for (i=0; i<2; i++) {
		vcdp->declQuad (c+67+i*2,"v fftram SRAM000 mem",(i+0),63,0);}}
	vcdp->declBit  (c+398,"v fftram SRAM001 clk_i",-1);
	vcdp->declBit  (c+360,"v fftram SRAM001 ez_i",-1);
	vcdp->declBit  (c+382,"v fftram SRAM001 wz_i",-1);
	vcdp->declBus  (c+112,"v fftram SRAM001 addr_i",-1,0,0);
	vcdp->declQuad (c+356,"v fftram SRAM001 rd_data_o",-1,63,0);
	vcdp->declQuad (c+358,"v fftram SRAM001 wr_data_i",-1,63,0);
	{int i; for (i=0; i<2; i++) {
		vcdp->declQuad (c+71+i*2,"v fftram SRAM001 mem",(i+0),63,0);}}
	vcdp->declBit  (c+398,"v fftram SRAM002 clk_i",-1);
	vcdp->declBit  (c+365,"v fftram SRAM002 ez_i",-1);
	vcdp->declBit  (c+383,"v fftram SRAM002 wz_i",-1);
	vcdp->declBus  (c+113,"v fftram SRAM002 addr_i",-1,0,0);
	vcdp->declQuad (c+361,"v fftram SRAM002 rd_data_o",-1,63,0);
	vcdp->declQuad (c+363,"v fftram SRAM002 wr_data_i",-1,63,0);
	{int i; for (i=0; i<2; i++) {
		vcdp->declQuad (c+75+i*2,"v fftram SRAM002 mem",(i+0),63,0);}}
	vcdp->declBit  (c+398,"v fftram SRAM003 clk_i",-1);
	vcdp->declBit  (c+370,"v fftram SRAM003 ez_i",-1);
	vcdp->declBit  (c+384,"v fftram SRAM003 wz_i",-1);
	vcdp->declBus  (c+114,"v fftram SRAM003 addr_i",-1,0,0);
	vcdp->declQuad (c+366,"v fftram SRAM003 rd_data_o",-1,63,0);
	vcdp->declQuad (c+368,"v fftram SRAM003 wr_data_i",-1,63,0);
	{int i; for (i=0; i<2; i++) {
		vcdp->declQuad (c+79+i*2,"v fftram SRAM003 mem",(i+0),63,0);}}
	vcdp->declBit  (c+398,"v fftctl clk_i",-1);
	vcdp->declBit  (c+110,"v fftctl rst_n_i",-1);
	vcdp->declBit  (c+49,"v fftctl start_i",-1);
	vcdp->declBus  (c+396,"v fftctl BFLY0_op1_ix_o",-1,2,0);
	vcdp->declBus  (c+386,"v fftctl BFLY0_op2_ix_o",-1,2,0);
	vcdp->declBus  (c+387,"v fftctl BFLY0_access_type_o",-1,2,0);
	vcdp->declBus  (c+388,"v fftctl fftctl_cycle_num_o",-1,4,0);
	vcdp->declBit  (c+108,"v fftctl busy_o",-1);
	vcdp->declBit  (c+398,"v fftctl fftclk_o",-1);
	vcdp->declBus  (c+395,"v fftctl suppress_wz_o",-1,3,0);
	vcdp->declBus  (c+389,"v fftctl bypass_read_o",-1,3,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBit  (c+93+i*1,"v fftctl bufnum_o",(i+0));}}
	{int i; for (i=0; i<12; i++) {
		vcdp->declBus  (c+413+i*1,"v fftctl BFLY0_access_type",(i+0),2,0);}}
	{int i; for (i=0; i<12; i++) {
		vcdp->declBus  (c+1+i*1,"v fftctl precomputed_suppress_wz",(i+0),0,3);}}
	{int i; for (i=0; i<12; i++) {
		vcdp->declBus  (c+13+i*1,"v fftctl precomputed_bypass_read",(i+0),0,3);}}
	// Tracing: v fftctl precomputed_bufnum // Ignored: Wide memory > --trace-max-array ents at genesis_verif//fftctl_unq1.v:162
	vcdp->declBus  (c+379,"v fftctl cycle_num",-1,4,0);
	vcdp->declBus  (c+380,"v fftctl out2_offset",-1,3,0);
	vcdp->declBus  (c+97,"v fftctl stageno",-1,2,0);
	vcdp->declBit  (c+107,"v fftctl STARTED",-1);
	vcdp->declBit  (c+109,"v fftctl LAST",-1);
	vcdp->declBit  (c+398,"v fftctl LCLK clock_in",-1);
	vcdp->declBit  (c+398,"v fftctl LCLK clock_out",-1);
	vcdp->declBus  (c+388,"v twiddle cycle_num_i",-1,4,0);
	vcdp->declBus  (c+83,"v twiddle BFLY0_twiddle_cos_o",-1,31,0);
	vcdp->declBus  (c+84,"v twiddle BFLY0_twiddle_sin_o",-1,31,0);
	{int i; for (i=0; i<12; i++) {
		vcdp->declBus  (c+25+i*1,"v twiddle BFLY0_twiddle_mem_cos",(i+0),31,0);}}
	{int i; for (i=0; i<12; i++) {
		vcdp->declBus  (c+37+i*1,"v twiddle BFLY0_twiddle_mem_sin",(i+0),31,0);}}
    }
}

void Vtop_fft::traceFullThis__1(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[0]),4);
	vcdp->fullBus  (c+2,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[1]),4);
	vcdp->fullBus  (c+3,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[2]),4);
	vcdp->fullBus  (c+4,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[3]),4);
	vcdp->fullBus  (c+5,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[4]),4);
	vcdp->fullBus  (c+6,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[5]),4);
	vcdp->fullBus  (c+7,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[6]),4);
	vcdp->fullBus  (c+8,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[7]),4);
	vcdp->fullBus  (c+9,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[8]),4);
	vcdp->fullBus  (c+10,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[9]),4);
	vcdp->fullBus  (c+11,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[10]),4);
	vcdp->fullBus  (c+12,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[11]),4);
	vcdp->fullBus  (c+13,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[0]),4);
	vcdp->fullBus  (c+14,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[1]),4);
	vcdp->fullBus  (c+15,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[2]),4);
	vcdp->fullBus  (c+16,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[3]),4);
	vcdp->fullBus  (c+17,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[4]),4);
	vcdp->fullBus  (c+18,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[5]),4);
	vcdp->fullBus  (c+19,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[6]),4);
	vcdp->fullBus  (c+20,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[7]),4);
	vcdp->fullBus  (c+21,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[8]),4);
	vcdp->fullBus  (c+22,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[9]),4);
	vcdp->fullBus  (c+23,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[10]),4);
	vcdp->fullBus  (c+24,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[11]),4);
	vcdp->fullBus  (c+25,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[0]),32);
	vcdp->fullBus  (c+26,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[1]),32);
	vcdp->fullBus  (c+27,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[2]),32);
	vcdp->fullBus  (c+28,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[3]),32);
	vcdp->fullBus  (c+29,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[4]),32);
	vcdp->fullBus  (c+30,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[5]),32);
	vcdp->fullBus  (c+31,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[6]),32);
	vcdp->fullBus  (c+32,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[7]),32);
	vcdp->fullBus  (c+33,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[8]),32);
	vcdp->fullBus  (c+34,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[9]),32);
	vcdp->fullBus  (c+35,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[10]),32);
	vcdp->fullBus  (c+36,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[11]),32);
	vcdp->fullBus  (c+37,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[0]),32);
	vcdp->fullBus  (c+38,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[1]),32);
	vcdp->fullBus  (c+39,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[2]),32);
	vcdp->fullBus  (c+40,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[3]),32);
	vcdp->fullBus  (c+41,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[4]),32);
	vcdp->fullBus  (c+42,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[5]),32);
	vcdp->fullBus  (c+43,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[6]),32);
	vcdp->fullBus  (c+44,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[7]),32);
	vcdp->fullBus  (c+45,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[8]),32);
	vcdp->fullBus  (c+46,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[9]),32);
	vcdp->fullBus  (c+47,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[10]),32);
	vcdp->fullBus  (c+48,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[11]),32);
	vcdp->fullBit  (c+49,(vlTOPp->v__DOT__start));
	vcdp->fullBus  (c+50,(vlTOPp->v__DOT__fftram__DOT__cycle_num),4);
	vcdp->fullBit  (c+51,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[0]));
	vcdp->fullBit  (c+52,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[1]));
	vcdp->fullBit  (c+53,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[2]));
	vcdp->fullBit  (c+54,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[3]));
	vcdp->fullBus  (c+55,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[0]),1);
	vcdp->fullBus  (c+56,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[1]),1);
	vcdp->fullBus  (c+57,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[2]),1);
	vcdp->fullBus  (c+58,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[3]),1);
	vcdp->fullQuad (c+59,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[0]),64);
	vcdp->fullQuad (c+61,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[1]),64);
	vcdp->fullQuad (c+63,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[2]),64);
	vcdp->fullQuad (c+65,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[3]),64);
	vcdp->fullQuad (c+67,(vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[0]),64);
	vcdp->fullQuad (c+69,(vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[1]),64);
	vcdp->fullQuad (c+71,(vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[0]),64);
	vcdp->fullQuad (c+73,(vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[1]),64);
	vcdp->fullQuad (c+75,(vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[0]),64);
	vcdp->fullQuad (c+77,(vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[1]),64);
	vcdp->fullQuad (c+79,(vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[0]),64);
	vcdp->fullQuad (c+81,(vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[1]),64);
	vcdp->fullQuad (c+86,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0_twiddle_cos))))),48);
	vcdp->fullBus  (c+88,((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
					>> 0x17U))),9);
	vcdp->fullQuad (c+89,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0_twiddle_sin))))),48);
	vcdp->fullBus  (c+91,((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
					>> 0x17U))),9);
	vcdp->fullBus  (c+85,(vlTOPp->v__DOT__BFLY0_op2_bnum),2);
	vcdp->fullBit  (c+92,(vlTOPp->v__DOT__fftram__DOT__bypass_time));
	vcdp->fullBit  (c+93,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[0]));
	vcdp->fullBit  (c+94,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[1]));
	vcdp->fullBit  (c+95,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[2]));
	vcdp->fullBit  (c+96,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[3]));
	vcdp->fullBus  (c+97,(vlTOPp->v__DOT__fftctl__DOT__stageno),3);
	vcdp->fullBus  (c+83,(vlTOPp->v__DOT__BFLY0_twiddle_cos),32);
	vcdp->fullBus  (c+84,(vlTOPp->v__DOT__BFLY0_twiddle_sin),32);
	vcdp->fullBit  (c+98,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_cos 
				      >> 0x1fU) ^ (IData)(
							  (vlTOPp->v__DOT__BFLY0_in2_data 
							   >> 0x3fU))))));
	vcdp->fullBit  (c+99,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_sin 
				      >> 0x1fU) ^ (IData)(
							  (vlTOPp->v__DOT__BFLY0_in2_data 
							   >> 0x1fU))))));
	vcdp->fullBit  (c+100,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_sin 
				       >> 0x1fU) ^ (IData)(
							   (vlTOPp->v__DOT__BFLY0_in2_data 
							    >> 0x3fU))))));
	vcdp->fullBit  (c+101,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_cos 
				       >> 0x1fU) ^ (IData)(
							   (vlTOPp->v__DOT__BFLY0_in2_data 
							    >> 0x1fU))))));
	vcdp->fullBus  (c+102,(vlTOPp->v__DOT__BFLY0_op1_bnum),2);
	vcdp->fullBit  (c+103,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[0]));
	vcdp->fullBit  (c+104,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[1]));
	vcdp->fullBit  (c+105,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[2]));
	vcdp->fullBit  (c+106,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[3]));
	vcdp->fullBit  (c+107,(vlTOPp->v__DOT__fftctl__DOT__STARTED));
	vcdp->fullBit  (c+108,((1U & (~ (IData)(vlTOPp->v__DOT__fftctl__DOT__LAST)))));
	vcdp->fullBit  (c+109,(vlTOPp->v__DOT__fftctl__DOT__LAST));
	vcdp->fullBit  (c+110,(vlTOPp->v__DOT__rst_n));
	vcdp->fullBus  (c+111,(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),1);
	vcdp->fullBus  (c+112,(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),1);
	vcdp->fullBus  (c+113,(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),1);
	vcdp->fullBus  (c+114,(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),1);
	vcdp->fullBit  (c+115,(vlTOPp->v__DOT__fftram__DOT__SRAM000_active));
	vcdp->fullBit  (c+116,(vlTOPp->v__DOT__fftram__DOT__SRAM001_active));
	vcdp->fullBit  (c+117,(vlTOPp->v__DOT__fftram__DOT__SRAM002_active));
	vcdp->fullBit  (c+118,(vlTOPp->v__DOT__fftram__DOT__SRAM003_active));
	vcdp->fullBit  (c+119,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[0]));
	vcdp->fullBit  (c+120,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[1]));
	vcdp->fullBit  (c+121,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[2]));
	vcdp->fullBit  (c+122,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[3]));
	vcdp->fullBit  (c+131,(vlTOPp->v__DOT____Vcellinp__BFLY0__ready));
	vcdp->fullBus  (c+140,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd),32);
	vcdp->fullBus  (c+141,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub),32);
	vcdp->fullBit  (c+142,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					 >> 0x1fU)))));
	vcdp->fullBit  (c+143,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					 >> 0x1fU)))));
	vcdp->fullBus  (c+144,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw),32);
	vcdp->fullBit  (c+145,(0U));
	vcdp->fullBit  (c+146,(0U));
	vcdp->fullBus  (c+147,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					 >> 0x17U))),8);
	vcdp->fullBus  (c+148,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					 >> 0x17U))),8);
	vcdp->fullQuad (c+149,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1a))))),48);
	vcdp->fullQuad (c+151,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1b))))),48);
	vcdp->fullBus  (c+153,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff),8);
	vcdp->fullBit  (c+154,(((0U == (0x7fffffffU 
					& vlTOPp->v__DOT__BFLY0__DOT__t1a)) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
				   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						>> 0x17U)) 
				      > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						  >> 0x17U)))))));
	vcdp->fullBit  (c+155,(((0U == (0x7fffffffU 
					& vlTOPp->v__DOT__BFLY0__DOT__t1b)) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
				   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						>> 0x17U)) 
				      > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						  >> 0x17U)))))));
	vcdp->fullQuad (c+156,((VL_ULL(0xffffffffffff) 
				& (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					      >> 0x17U)) 
				    > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1a)))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0__DOT__t1a))))))),48);
	vcdp->fullQuad (c+158,((VL_ULL(0xffffffffffff) 
				& (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					      >> 0x17U)) 
				    > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1b)))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0__DOT__t1b))))))),48);
	vcdp->fullBus  (c+160,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze),8);
	vcdp->fullQuad (c+161,((VL_ULL(0xffffffffffff) 
				& ((((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						 >> 0x17U)))
				     ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					 ? ((VL_ULL(0x800000) 
					     | (QData)((IData)(
							       (0x7fffffU 
								& vlTOPp->v__DOT__BFLY0__DOT__t1a)))) 
					    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					 : VL_ULL(0))
				     : (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & vlTOPp->v__DOT__BFLY0__DOT__t1a))))) 
				   + (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						 >> 0x17U)) 
				       > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						   >> 0x17U)))
				       ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					   ? ((VL_ULL(0x800000) 
					       | (QData)((IData)(
								 (0x7fffffU 
								  & vlTOPp->v__DOT__BFLY0__DOT__t1b)))) 
					      << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					   : VL_ULL(0))
				       : (VL_ULL(0x800000) 
					  | (QData)((IData)(
							    (0x7fffffU 
							     & vlTOPp->v__DOT__BFLY0__DOT__t1b)))))))),48);
	vcdp->fullBus  (c+163,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->fullBus  (c+164,((0x7fffffU & ((0x1000000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
						 >> 1U)
					      : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->fullBus  (c+165,((0xffU & ((0x1000000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					  ? ((IData)(1U) 
					     + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))
					  : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze)))),8);
	vcdp->fullBus  (c+138,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)),32);
	vcdp->fullBus  (c+139,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)),32);
	vcdp->fullQuad (c+166,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->fullQuad (c+168,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->fullQuad (c+170,((VL_ULL(0xffffffffffff) 
				& ((vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				    >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    : (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->fullBus  (c+172,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->fullBus  (c+173,((0xffU & ((0x800000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					  ? 0U : ((0x400000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 1U
						   : 
						  ((0x200000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 2U
						    : 
						   ((0x100000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 3U
						     : 
						    ((0x80000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 4U
						      : 
						     ((0x40000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 5U
						       : 
						      ((0x20000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 6U
						        : 
						       ((0x10000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 7U
							 : 
							((0x8000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 8U
							  : 
							 ((0x4000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 9U
							   : 
							  ((0x2000U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 0xaU
							    : 
							   ((0x1000U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 0xbU
							     : 
							    ((0x800U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 0xcU
							      : 
							     ((0x400U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 0xdU
							       : 
							      ((0x200U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 0xeU
							        : 
							       ((0x100U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 0xfU
								 : 
								((0x80U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 0x10U
								  : 
								 ((0x40U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 0x11U
								   : 
								  ((0x20U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 0x12U
								    : 
								   ((0x10U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 0x13U
								     : 
								    ((8U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 0x14U
								      : 
								     ((4U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 0x15U
								       : 
								      ((2U 
									& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								        ? 0x16U
								        : 
								       ((1U 
									 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
									 ? 0x17U
									 : 0x18U)))))))))))))))))))))))))),8);
	vcdp->fullBus  (c+174,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->fullBus  (c+175,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->fullBus  (c+133,(vlTOPp->v__DOT__BFLY0__DOT__t1a),32);
	vcdp->fullQuad (c+177,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & (IData)(
									      (vlTOPp->v__DOT__BFLY0_in2_data 
									       >> 0x20U))))))),48);
	vcdp->fullQuad (c+179,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab),48);
	vcdp->fullBit  (c+181,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					      >> 0x2fU)))));
	vcdp->fullBus  (c+182,((0xffffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							 >> 0x17U))))),24);
	vcdp->fullBus  (c+183,((0x7fffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							 >> 0x17U))))),23);
	vcdp->fullBus  (c+184,((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
						 >> 0x37U)))),9);
	vcdp->fullBus  (c+185,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->fullBus  (c+186,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
					  - (IData)(0x7fU)))),9);
	vcdp->fullBus  (c+187,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm),9);
	vcdp->fullBus  (c+188,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm))),8);
	vcdp->fullBit  (c+189,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					       >> 0x2fU)))
				 ? (0x7fU > (0x1ffU 
					     & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))))
				 : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->fullBit  (c+190,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm) 
				      >> 8U))));
	vcdp->fullBus  (c+134,(vlTOPp->v__DOT__BFLY0__DOT__t1b),32);
	vcdp->fullQuad (c+192,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & (IData)(vlTOPp->v__DOT__BFLY0_in2_data)))))),48);
	vcdp->fullQuad (c+194,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab),48);
	vcdp->fullBit  (c+196,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					      >> 0x2fU)))));
	vcdp->fullBus  (c+197,((0xffffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							 >> 0x17U))))),24);
	vcdp->fullBus  (c+198,((0x7fffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							 >> 0x17U))))),23);
	vcdp->fullBus  (c+199,((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
						 >> 0x17U)))),9);
	vcdp->fullBus  (c+200,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->fullBus  (c+201,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
					  - (IData)(0x7fU)))),9);
	vcdp->fullBus  (c+202,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm),9);
	vcdp->fullBus  (c+203,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm))),8);
	vcdp->fullBit  (c+204,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					       >> 0x2fU)))
				 ? (0x7fU > (0x1ffU 
					     & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))))
				 : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->fullBit  (c+205,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm) 
				      >> 8U))));
	vcdp->fullBus  (c+208,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd),32);
	vcdp->fullBus  (c+209,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub),32);
	vcdp->fullBit  (c+210,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					 >> 0x1fU)))));
	vcdp->fullBit  (c+211,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					 >> 0x1fU)))));
	vcdp->fullBus  (c+212,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw),32);
	vcdp->fullBit  (c+213,(0U));
	vcdp->fullBit  (c+214,(0U));
	vcdp->fullBus  (c+215,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					 >> 0x17U))),8);
	vcdp->fullBus  (c+216,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					 >> 0x17U))),8);
	vcdp->fullQuad (c+217,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2a))))),48);
	vcdp->fullQuad (c+219,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2b))))),48);
	vcdp->fullBus  (c+221,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff),8);
	vcdp->fullBit  (c+222,(((0U == (0x7fffffffU 
					& vlTOPp->v__DOT__BFLY0__DOT__t2a)) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
				   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						>> 0x17U)) 
				      > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						  >> 0x17U)))))));
	vcdp->fullBit  (c+223,(((0U == (0x7fffffffU 
					& vlTOPp->v__DOT__BFLY0__DOT__t2b)) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
				   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						>> 0x17U)) 
				      > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						  >> 0x17U)))))));
	vcdp->fullQuad (c+224,((VL_ULL(0xffffffffffff) 
				& (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					      >> 0x17U)) 
				    > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2a)))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0__DOT__t2a))))))),48);
	vcdp->fullQuad (c+226,((VL_ULL(0xffffffffffff) 
				& (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					      >> 0x17U)) 
				    > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2b)))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0__DOT__t2b))))))),48);
	vcdp->fullBus  (c+228,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze),8);
	vcdp->fullQuad (c+229,((VL_ULL(0xffffffffffff) 
				& ((((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						 >> 0x17U)))
				     ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					 ? ((VL_ULL(0x800000) 
					     | (QData)((IData)(
							       (0x7fffffU 
								& vlTOPp->v__DOT__BFLY0__DOT__t2a)))) 
					    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					 : VL_ULL(0))
				     : (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & vlTOPp->v__DOT__BFLY0__DOT__t2a))))) 
				   + (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						 >> 0x17U)) 
				       > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						   >> 0x17U)))
				       ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					   ? ((VL_ULL(0x800000) 
					       | (QData)((IData)(
								 (0x7fffffU 
								  & vlTOPp->v__DOT__BFLY0__DOT__t2b)))) 
					      << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					   : VL_ULL(0))
				       : (VL_ULL(0x800000) 
					  | (QData)((IData)(
							    (0x7fffffU 
							     & vlTOPp->v__DOT__BFLY0__DOT__t2b)))))))),48);
	vcdp->fullBus  (c+231,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->fullBus  (c+232,((0x7fffffU & ((0x1000000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					      ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
						 >> 1U)
					      : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->fullBus  (c+233,((0xffU & ((0x1000000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					  ? ((IData)(1U) 
					     + (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))
					  : (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze)))),8);
	vcdp->fullBus  (c+206,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)),32);
	vcdp->fullBus  (c+207,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)),32);
	vcdp->fullQuad (c+234,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->fullQuad (c+236,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->fullQuad (c+238,((VL_ULL(0xffffffffffff) 
				& ((vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				    >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    : (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->fullBus  (c+240,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->fullBus  (c+241,((0xffU & ((0x800000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					  ? 0U : ((0x400000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 1U
						   : 
						  ((0x200000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 2U
						    : 
						   ((0x100000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 3U
						     : 
						    ((0x80000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 4U
						      : 
						     ((0x40000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 5U
						       : 
						      ((0x20000U 
							& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 6U
						        : 
						       ((0x10000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 7U
							 : 
							((0x8000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 8U
							  : 
							 ((0x4000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 9U
							   : 
							  ((0x2000U 
							    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 0xaU
							    : 
							   ((0x1000U 
							     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 0xbU
							     : 
							    ((0x800U 
							      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 0xcU
							      : 
							     ((0x400U 
							       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 0xdU
							       : 
							      ((0x200U 
								& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 0xeU
							        : 
							       ((0x100U 
								 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 0xfU
								 : 
								((0x80U 
								  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 0x10U
								  : 
								 ((0x40U 
								   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 0x11U
								   : 
								  ((0x20U 
								    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 0x12U
								    : 
								   ((0x10U 
								     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 0x13U
								     : 
								    ((8U 
								      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 0x14U
								      : 
								     ((4U 
								       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 0x15U
								       : 
								      ((2U 
									& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								        ? 0x16U
								        : 
								       ((1U 
									 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
									 ? 0x17U
									 : 0x18U)))))))))))))))))))))))))),8);
	vcdp->fullBus  (c+242,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->fullBus  (c+243,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->fullBus  (c+176,((IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					>> 0x20U))),32);
	vcdp->fullBus  (c+136,(vlTOPp->v__DOT__BFLY0__DOT__t2a),32);
	vcdp->fullQuad (c+244,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab),48);
	vcdp->fullBit  (c+246,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					      >> 0x2fU)))));
	vcdp->fullBus  (c+247,((0xffffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							 >> 0x17U))))),24);
	vcdp->fullBus  (c+248,((0x7fffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							 >> 0x17U))))),23);
	vcdp->fullBus  (c+249,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->fullBus  (c+250,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
					  - (IData)(0x7fU)))),9);
	vcdp->fullBus  (c+251,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm),9);
	vcdp->fullBus  (c+252,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm))),8);
	vcdp->fullBit  (c+253,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					       >> 0x2fU)))
				 ? (0x7fU > (0x1ffU 
					     & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))))
				 : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->fullBit  (c+254,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm) 
				      >> 8U))));
	vcdp->fullBus  (c+191,((IData)(vlTOPp->v__DOT__BFLY0_in2_data)),32);
	vcdp->fullBus  (c+137,(vlTOPp->v__DOT__BFLY0__DOT__t2b),32);
	vcdp->fullQuad (c+255,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab),48);
	vcdp->fullBit  (c+257,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					      >> 0x2fU)))));
	vcdp->fullBus  (c+258,((0xffffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							 >> 0x17U))))),24);
	vcdp->fullBus  (c+259,((0x7fffffU & ((1U & (IData)(
							   (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							    >> 0x2fU)))
					      ? (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							 >> 0x18U))
					      : (IData)(
							(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							 >> 0x17U))))),23);
	vcdp->fullBus  (c+260,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->fullBus  (c+261,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
					  - (IData)(0x7fU)))),9);
	vcdp->fullBus  (c+262,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm),9);
	vcdp->fullBus  (c+263,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm))),8);
	vcdp->fullBit  (c+264,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					       >> 0x2fU)))
				 ? (0x7fU > (0x1ffU 
					     & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))))
				 : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->fullBit  (c+265,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm) 
				      >> 8U))));
	vcdp->fullBus  (c+267,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
				 ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)),32);
	vcdp->fullBit  (c+272,((1U & (~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						 >> 0x3fU))))));
	vcdp->fullBit  (c+273,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1 
					 >> 0x1fU)))));
	vcdp->fullBus  (c+274,(vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw),32);
	vcdp->fullQuad (c+286,((VL_ULL(0xffffffffffff) 
				& (((0xffU & ((IData)(
						      (vlTOPp->v__DOT__BFLY0_in1_data 
						       >> 0x20U)) 
					      >> 0x17U)) 
				    > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & (IData)(
									 (vlTOPp->v__DOT__BFLY0_in1_data 
									  >> 0x20U)))))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(
								    (vlTOPp->v__DOT__BFLY0_in1_data 
								     >> 0x20U))))))))),48);
	vcdp->fullQuad (c+288,((VL_ULL(0xffffffffffff) 
				& (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
					      >> 0x17U)) 
				    > (0xffU & ((IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U)) 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0__DOT__t1))))))),48);
	vcdp->fullQuad (c+291,((VL_ULL(0xffffffffffff) 
				& ((((0xffU & ((IData)(
						       (vlTOPp->v__DOT__BFLY0_in1_data 
							>> 0x20U)) 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x17U)))
				     ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					 ? ((VL_ULL(0x800000) 
					     | (QData)((IData)(
							       (0x7fffffU 
								& (IData)(
									  (vlTOPp->v__DOT__BFLY0_in1_data 
									   >> 0x20U)))))) 
					    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					 : VL_ULL(0))
				     : (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(
								     (vlTOPp->v__DOT__BFLY0_in1_data 
								      >> 0x20U))))))) 
				   + (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x17U)) 
				       > (0xffU & ((IData)(
							   (vlTOPp->v__DOT__BFLY0_in1_data 
							    >> 0x20U)) 
						   >> 0x17U)))
				       ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					   ? ((VL_ULL(0x800000) 
					       | (QData)((IData)(
								 (0x7fffffU 
								  & vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
					      << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					   : VL_ULL(0))
				       : (VL_ULL(0x800000) 
					  | (QData)((IData)(
							    (0x7fffffU 
							     & vlTOPp->v__DOT__BFLY0__DOT__t1)))))))),48);
	vcdp->fullBus  (c+293,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->fullBus  (c+294,((0x7fffffU & ((0x1000000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						 >> 1U)
					      : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->fullBus  (c+295,((0xffU & ((0x1000000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					  ? ((IData)(1U) 
					     + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
					  : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze)))),8);
	vcdp->fullQuad (c+296,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->fullQuad (c+298,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->fullQuad (c+300,((VL_ULL(0xffffffffffff) 
				& ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				    >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->fullBus  (c+302,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->fullBus  (c+303,((0xffU & ((0x800000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					  ? 0U : ((0x400000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 1U
						   : 
						  ((0x200000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 2U
						    : 
						   ((0x100000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 3U
						     : 
						    ((0x80000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 4U
						      : 
						     ((0x40000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 5U
						       : 
						      ((0x20000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 6U
						        : 
						       ((0x10000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 7U
							 : 
							((0x8000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 8U
							  : 
							 ((0x4000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 9U
							   : 
							  ((0x2000U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 0xaU
							    : 
							   ((0x1000U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 0xbU
							     : 
							    ((0x800U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 0xcU
							      : 
							     ((0x400U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 0xdU
							       : 
							      ((0x200U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 0xeU
							        : 
							       ((0x100U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 0xfU
								 : 
								((0x80U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 0x10U
								  : 
								 ((0x40U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 0x11U
								   : 
								  ((0x20U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 0x12U
								    : 
								   ((0x10U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 0x13U
								     : 
								    ((8U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 0x14U
								      : 
								     ((4U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 0x15U
								       : 
								      ((2U 
									& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								        ? 0x16U
								        : 
								       ((1U 
									 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
									 ? 0x17U
									 : 0x18U)))))))))))))))))))))))))),8);
	vcdp->fullBus  (c+304,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->fullBus  (c+305,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->fullBus  (c+307,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
				 ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)),32);
	vcdp->fullBit  (c+312,((1U & (~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						 >> 0x1fU))))));
	vcdp->fullBit  (c+313,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2 
					 >> 0x1fU)))));
	vcdp->fullBus  (c+314,(vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw),32);
	vcdp->fullQuad (c+326,((VL_ULL(0xffffffffffff) 
				& (((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					      >> 0x17U)) 
				    > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))))),48);
	vcdp->fullQuad (c+328,((VL_ULL(0xffffffffffff) 
				& (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
					      >> 0x17U)) 
				    > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						>> 0x17U)))
				    ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				        ? ((VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
					   << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				        : VL_ULL(0))
				    : (VL_ULL(0x800000) 
				       | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0__DOT__t2))))))),48);
	vcdp->fullQuad (c+331,((VL_ULL(0xffffffffffff) 
				& ((((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x17U)))
				     ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					 ? ((VL_ULL(0x800000) 
					     | (QData)((IData)(
							       (0x7fffffU 
								& (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))) 
					    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					 : VL_ULL(0))
				     : (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))) 
				   + (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x17U)) 
				       > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						   >> 0x17U)))
				       ? ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					   ? ((VL_ULL(0x800000) 
					       | (QData)((IData)(
								 (0x7fffffU 
								  & vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
					      << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					   : VL_ULL(0))
				       : (VL_ULL(0x800000) 
					  | (QData)((IData)(
							    (0x7fffffU 
							     & vlTOPp->v__DOT__BFLY0__DOT__t2)))))))),48);
	vcdp->fullBus  (c+333,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->fullBus  (c+334,((0x7fffffU & ((0x1000000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						 >> 1U)
					      : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->fullBus  (c+335,((0xffU & ((0x1000000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					  ? ((IData)(1U) 
					     + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
					  : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze)))),8);
	vcdp->fullQuad (c+336,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->fullQuad (c+338,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->fullQuad (c+340,((VL_ULL(0xffffffffffff) 
				& ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				    >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				    : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
				       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->fullBus  (c+342,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->fullBus  (c+343,((0xffU & ((0x800000U 
					  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					  ? 0U : ((0x400000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 1U
						   : 
						  ((0x200000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 2U
						    : 
						   ((0x100000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 3U
						     : 
						    ((0x80000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 4U
						      : 
						     ((0x40000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 5U
						       : 
						      ((0x20000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 6U
						        : 
						       ((0x10000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 7U
							 : 
							((0x8000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 8U
							  : 
							 ((0x4000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 9U
							   : 
							  ((0x2000U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 0xaU
							    : 
							   ((0x1000U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 0xbU
							     : 
							    ((0x800U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 0xcU
							      : 
							     ((0x400U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 0xdU
							       : 
							      ((0x200U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 0xeU
							        : 
							       ((0x100U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 0xfU
								 : 
								((0x80U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 0x10U
								  : 
								 ((0x40U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 0x11U
								   : 
								  ((0x20U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 0x12U
								    : 
								   ((0x10U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 0x13U
								     : 
								    ((8U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 0x14U
								      : 
								     ((4U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 0x15U
								       : 
								      ((2U 
									& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								        ? 0x16U
								        : 
								       ((1U 
									 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
									 ? 0x17U
									 : 0x18U)))))))))))))))))))))))))),8);
	vcdp->fullBus  (c+344,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->fullBus  (c+345,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->fullBus  (c+346,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
				 ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)),32);
	vcdp->fullBus  (c+266,((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					>> 0x20U))),32);
	vcdp->fullBus  (c+132,(vlTOPp->v__DOT__BFLY0__DOT__t1),32);
	vcdp->fullBus  (c+347,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw),32);
	vcdp->fullBus  (c+270,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd),32);
	vcdp->fullBus  (c+268,((0x7fffffffU & (IData)(
						      (vlTOPp->v__DOT__BFLY0_in1_data 
						       >> 0x20U)))),32);
	vcdp->fullBus  (c+269,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)),32);
	vcdp->fullBus  (c+271,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub),32);
	vcdp->fullBit  (c+275,(0U));
	vcdp->fullBit  (c+276,(0U));
	vcdp->fullBus  (c+277,((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						  >> 0x20U)) 
					 >> 0x17U))),8);
	vcdp->fullBus  (c+278,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
					 >> 0x17U))),8);
	vcdp->fullQuad (c+279,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & (IData)(
									      (vlTOPp->v__DOT__BFLY0_in1_data 
									       >> 0x20U))))))),48);
	vcdp->fullQuad (c+281,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1))))),48);
	vcdp->fullBus  (c+283,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff),8);
	vcdp->fullBit  (c+284,(((0U == (0x7fffffffU 
					& (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)))) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
				   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x17U)) 
				      > (0xffU & ((IData)(
							  (vlTOPp->v__DOT__BFLY0_in1_data 
							   >> 0x20U)) 
						  >> 0x17U)))))));
	vcdp->fullBit  (c+285,(((0U == (0x7fffffffU 
					& vlTOPp->v__DOT__BFLY0__DOT__t1)) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
				   & ((0xffU & ((IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U)) 
						>> 0x17U)) 
				      > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						  >> 0x17U)))))));
	vcdp->fullBus  (c+290,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze),8);
	vcdp->fullBus  (c+348,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
				 ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)),32);
	vcdp->fullBus  (c+306,((IData)(vlTOPp->v__DOT__BFLY0_in1_data)),32);
	vcdp->fullBus  (c+135,(vlTOPp->v__DOT__BFLY0__DOT__t2),32);
	vcdp->fullBus  (c+349,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw),32);
	vcdp->fullBus  (c+310,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd),32);
	vcdp->fullBus  (c+308,((0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))),32);
	vcdp->fullBus  (c+309,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)),32);
	vcdp->fullBus  (c+311,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub),32);
	vcdp->fullBit  (c+315,(0U));
	vcdp->fullBit  (c+316,(0U));
	vcdp->fullBus  (c+317,((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					 >> 0x17U))),8);
	vcdp->fullBus  (c+318,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
					 >> 0x17U))),8);
	vcdp->fullQuad (c+319,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))),48);
	vcdp->fullQuad (c+321,((VL_ULL(0x800000) | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2))))),48);
	vcdp->fullBus  (c+323,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff),8);
	vcdp->fullBit  (c+324,(((0U == (0x7fffffffU 
					& (IData)(vlTOPp->v__DOT__BFLY0_in1_data))) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
				   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x17U)) 
				      > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						  >> 0x17U)))))));
	vcdp->fullBit  (c+325,(((0U == (0x7fffffffU 
					& vlTOPp->v__DOT__BFLY0__DOT__t2)) 
				| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
				   & ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						>> 0x17U)) 
				      > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						  >> 0x17U)))))));
	vcdp->fullBus  (c+330,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze),8);
	vcdp->fullQuad (c+123,(vlTOPp->v__DOT__BFLY0_in1_data),64);
	vcdp->fullQuad (c+125,(vlTOPp->v__DOT__BFLY0_in2_data),64);
	vcdp->fullQuad (c+127,(vlTOPp->v__DOT__BFLY0_out1_data),64);
	vcdp->fullQuad (c+129,(vlTOPp->v__DOT__BFLY0_out2_data),64);
	vcdp->fullBit  (c+350,(vlTOPp->v__DOT____Vcellinp__fftram__fft_started));
	vcdp->fullQuad (c+351,(vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data),64);
	vcdp->fullQuad (c+353,(vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data),64);
	vcdp->fullBit  (c+355,(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez));
	vcdp->fullQuad (c+356,(vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data),64);
	vcdp->fullQuad (c+358,(vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data),64);
	vcdp->fullBit  (c+360,(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez));
	vcdp->fullQuad (c+361,(vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data),64);
	vcdp->fullQuad (c+363,(vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data),64);
	vcdp->fullBit  (c+365,(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez));
	vcdp->fullQuad (c+366,(vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data),64);
	vcdp->fullQuad (c+368,(vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data),64);
	vcdp->fullBit  (c+370,(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez));
	vcdp->fullQuad (c+371,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[0]),64);
	vcdp->fullQuad (c+373,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[1]),64);
	vcdp->fullQuad (c+375,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[2]),64);
	vcdp->fullQuad (c+377,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[3]),64);
	vcdp->fullBus  (c+379,(vlTOPp->v__DOT__fftctl__DOT__cycle_num),5);
	vcdp->fullBus  (c+380,(vlTOPp->v__DOT__fftctl__DOT__out2_offset),4);
	vcdp->fullBit  (c+381,(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz));
	vcdp->fullBit  (c+382,(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz));
	vcdp->fullBit  (c+383,(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz));
	vcdp->fullBit  (c+384,(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz));
	vcdp->fullBus  (c+385,(vlTOPp->v__DOT__cycle_counter),32);
	vcdp->fullBus  (c+387,(vlTOPp->v__DOT__BFLY0_access_type),3);
	vcdp->fullBus  (c+389,(vlTOPp->v__DOT__bypass_read),4);
	vcdp->fullBit  (c+390,(vlTOPp->v__DOT__bufnum[0]));
	vcdp->fullBit  (c+391,(vlTOPp->v__DOT__bufnum[1]));
	vcdp->fullBit  (c+392,(vlTOPp->v__DOT__bufnum[2]));
	vcdp->fullBit  (c+393,(vlTOPp->v__DOT__bufnum[3]));
	vcdp->fullBus  (c+394,((1U & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
				      >> 2U))),1);
	vcdp->fullBus  (c+386,(vlTOPp->v__DOT__BFLY0_op2_ix),3);
	vcdp->fullBus  (c+388,(vlTOPp->v__DOT__fftctl_cycle_num),5);
	vcdp->fullBus  (c+395,(vlTOPp->v__DOT__suppress_wz),4);
	vcdp->fullBus  (c+397,((1U & ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
				      >> 2U))),1);
	vcdp->fullBus  (c+396,(vlTOPp->v__DOT__BFLY0_op1_ix),3);
	vcdp->fullBit  (c+399,(vlTOPp->done));
	vcdp->fullBit  (c+398,(vlTOPp->clk));
	vcdp->fullBus  (c+400,(vlTOPp->v__DOT__BFLY0__DOT__status_t1),8);
	vcdp->fullBus  (c+401,(vlTOPp->v__DOT__BFLY0__DOT__status_t1a),8);
	vcdp->fullBus  (c+402,(vlTOPp->v__DOT__BFLY0__DOT__status_t1b),8);
	vcdp->fullBus  (c+403,(vlTOPp->v__DOT__BFLY0__DOT__status_t2),8);
	vcdp->fullBus  (c+404,(vlTOPp->v__DOT__BFLY0__DOT__status_t2a),8);
	vcdp->fullBus  (c+405,(vlTOPp->v__DOT__BFLY0__DOT__status_t2b),8);
	vcdp->fullBus  (c+406,(vlTOPp->v__DOT__BFLY0__DOT__status_o1r),8);
	vcdp->fullBus  (c+407,(vlTOPp->v__DOT__BFLY0__DOT__status_o1i),8);
	vcdp->fullBus  (c+408,(vlTOPp->v__DOT__BFLY0__DOT__status_o2r),8);
	vcdp->fullBus  (c+409,(vlTOPp->v__DOT__BFLY0__DOT__status_o2i),8);
	vcdp->fullBus  (c+411,(0x7fU),9);
	vcdp->fullBit  (c+412,(0U));
	vcdp->fullBit  (c+410,(1U));
	vcdp->fullBus  (c+413,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[0]),3);
	vcdp->fullBus  (c+414,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[1]),3);
	vcdp->fullBus  (c+415,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[2]),3);
	vcdp->fullBus  (c+416,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[3]),3);
	vcdp->fullBus  (c+417,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[4]),3);
	vcdp->fullBus  (c+418,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[5]),3);
	vcdp->fullBus  (c+419,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[6]),3);
	vcdp->fullBus  (c+420,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[7]),3);
	vcdp->fullBus  (c+421,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[8]),3);
	vcdp->fullBus  (c+422,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[9]),3);
	vcdp->fullBus  (c+423,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[10]),3);
	vcdp->fullBus  (c+424,(vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type[11]),3);
    }
}
