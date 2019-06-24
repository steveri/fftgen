// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_fft.h for the primary calling header

#include "Vtop_fft.h"          // For This
#include "Vtop_fft__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop_fft) {
    Vtop_fft__Syms* __restrict vlSymsp = __VlSymsp = new Vtop_fft__Syms(this, name());
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    clk = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    v__DOT__rst_n = VL_RAND_RESET_I(1);
    v__DOT__start = VL_RAND_RESET_I(1);
    v__DOT__BFLY0_op1_ix = VL_RAND_RESET_I(3);
    v__DOT__BFLY0_op2_ix = VL_RAND_RESET_I(3);
    v__DOT__BFLY0_access_type = VL_RAND_RESET_I(3);
    v__DOT__fftctl_cycle_num = VL_RAND_RESET_I(5);
    v__DOT__suppress_wz = VL_RAND_RESET_I(4);
    v__DOT__bypass_read = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__bufnum[__Vi0] = VL_RAND_RESET_I(1);
    }}
    v__DOT__BFLY0_twiddle_cos = VL_RAND_RESET_I(32);
    v__DOT__BFLY0_twiddle_sin = VL_RAND_RESET_I(32);
    v__DOT__BFLY0_in1_data = VL_RAND_RESET_Q(64);
    v__DOT__BFLY0_in2_data = VL_RAND_RESET_Q(64);
    v__DOT__BFLY0_out1_data = VL_RAND_RESET_Q(64);
    v__DOT__BFLY0_out2_data = VL_RAND_RESET_Q(64);
    v__DOT__BFLY0_op1_bnum = VL_RAND_RESET_I(2);
    v__DOT__BFLY0_op2_bnum = VL_RAND_RESET_I(2);
    v__DOT____Vcellinp__BFLY0__ready = VL_RAND_RESET_I(1);
    v__DOT____Vcellinp__fftram__fft_started = VL_RAND_RESET_I(1);
    v__DOT__cycle_counter = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__t1 = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__t1a = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__t1b = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__t2 = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__t2a = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__t2b = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__status_t1 = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_t1a = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_t1b = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_t2 = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_t2a = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_t2b = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_o1r = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_o1i = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_o2r = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__status_o2i = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm = VL_RAND_RESET_I(25);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm = VL_RAND_RESET_I(24);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final = VL_RAND_RESET_I(23);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm = VL_RAND_RESET_I(25);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm = VL_RAND_RESET_I(24);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final = VL_RAND_RESET_I(23);
    v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm = VL_RAND_RESET_I(9);
    v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm = VL_RAND_RESET_I(25);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm = VL_RAND_RESET_I(24);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final = VL_RAND_RESET_I(23);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw = VL_RAND_RESET_I(32);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm = VL_RAND_RESET_I(25);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj = VL_RAND_RESET_Q(48);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm = VL_RAND_RESET_I(24);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final = VL_RAND_RESET_I(23);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze = VL_RAND_RESET_I(8);
    v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final = VL_RAND_RESET_I(8);
    v__DOT__fftram__DOT__SRAM000_ix = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM000_rd_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM000_wr_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM000_ez = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM000_wz = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM001_ix = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM001_rd_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM001_wr_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM001_ez = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM001_wz = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM002_ix = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM002_rd_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM002_wr_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM002_ez = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM002_wz = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM003_ix = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM003_rd_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM003_wr_data = VL_RAND_RESET_Q(64);
    v__DOT__fftram__DOT__SRAM003_ez = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM003_wz = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__cycle_num = VL_RAND_RESET_I(4);
    v__DOT__fftram__DOT__bypass_time = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM000_active = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM001_active = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM002_active = VL_RAND_RESET_I(1);
    v__DOT__fftram__DOT__SRAM003_active = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__fftram__DOT__bypass_valid[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__fftram__DOT__bypassed_rnum[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__fftram__DOT__bypassed_data[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__fftram__DOT__sram_or_buf[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__fftram__DOT__BFLY0_op1_match[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__fftram__DOT__BFLY0_op2_match[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    v__DOT__fftram__DOT__SRAM000__DOT__mem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    v__DOT__fftram__DOT__SRAM001__DOT__mem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    v__DOT__fftram__DOT__SRAM002__DOT__mem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    v__DOT__fftram__DOT__SRAM003__DOT__mem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__fftctl__DOT__bufnum_o[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<12; ++__Vi0) {
	    v__DOT__fftctl__DOT__BFLY0_access_type[__Vi0] = VL_RAND_RESET_I(3);
    }}
    { int __Vi0=0; for (; __Vi0<12; ++__Vi0) {
	    v__DOT__fftctl__DOT__precomputed_suppress_wz[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<12; ++__Vi0) {
	    v__DOT__fftctl__DOT__precomputed_bypass_read[__Vi0] = VL_RAND_RESET_I(4);
    }}
    v__DOT__fftctl__DOT__cycle_num = VL_RAND_RESET_I(5);
    v__DOT__fftctl__DOT__out2_offset = VL_RAND_RESET_I(4);
    v__DOT__fftctl__DOT__stageno = VL_RAND_RESET_I(3);
    v__DOT__fftctl__DOT__STARTED = VL_RAND_RESET_I(1);
    v__DOT__fftctl__DOT__LAST = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<12; ++__Vi0) {
	    v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<12; ++__Vi0) {
	    v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vdlyvset__v__DOT__bufnum__v0 = VL_RAND_RESET_I(1);
    __Vdlyvset__v__DOT__bufnum__v1 = VL_RAND_RESET_I(1);
    __Vdlyvset__v__DOT__bufnum__v2 = VL_RAND_RESET_I(1);
    __Vdlyvset__v__DOT__bufnum__v3 = VL_RAND_RESET_I(1);
    __Vdly__v__DOT__BFLY0_op1_ix = VL_RAND_RESET_I(3);
    __Vdly__v__DOT__BFLY0_op2_ix = VL_RAND_RESET_I(3);
    __Vdly__v__DOT__fftctl__DOT__stageno = VL_RAND_RESET_I(3);
    __Vdly__v__DOT__fftctl__DOT__out2_offset = VL_RAND_RESET_I(4);
    __Vdly__v__DOT__fftctl_cycle_num = VL_RAND_RESET_I(5);
    __Vdly__v__DOT__fftctl__DOT__cycle_num = VL_RAND_RESET_I(5);
    __Vdly__v__DOT__rst_n = VL_RAND_RESET_I(1);
    __Vdly__v__DOT__cycle_counter = VL_RAND_RESET_I(32);
    __VinpClk__TOP__v__DOT__rst_n = VL_RAND_RESET_I(1);
    __VinpClk__TOP__v__DOT__start = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP____VinpClk__TOP__v__DOT__rst_n = VL_RAND_RESET_I(1);
    __Vclklast__TOP__v__DOT__fftram__DOT__SRAM000_wz = VL_RAND_RESET_I(1);
    __Vclklast__TOP__v__DOT__fftram__DOT__SRAM001_wz = VL_RAND_RESET_I(1);
    __Vclklast__TOP__v__DOT__fftram__DOT__SRAM002_wz = VL_RAND_RESET_I(1);
    __Vclklast__TOP__v__DOT__fftram__DOT__SRAM003_wz = VL_RAND_RESET_I(1);
    __Vclklast__TOP____VinpClk__TOP__v__DOT__start = VL_RAND_RESET_I(1);
    __Vchglast__TOP__v__DOT__rst_n = VL_RAND_RESET_I(1);
    __Vchglast__TOP__v__DOT__start = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Vtop_fft::__Vconfigure(Vtop_fft__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop_fft::~Vtop_fft() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop_fft::eval() {
    Vtop_fft__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vtop_fft::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop_fft::_eval_initial_loop(Vtop_fft__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vtop_fft::_initial__TOP__1(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_initial__TOP__1\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at genesis_verif/top_fft.v:178
    VL_WRITEF("\nfftmem.vp: n_butterfly_units=1 and n_fft_points=8\n\n");
    // INITIAL at genesis_verif//twiddle_unq1.v:110
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[0U] = 0x3f800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[0U] = 0U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[1U] = 0x3f800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[1U] = 0U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[2U] = 0x3f800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[2U] = 0U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[3U] = 0x3f800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[3U] = 0U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[4U] = 0x3f800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[4U] = 0U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[5U] = 0x3f800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[5U] = 0U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[6U] = 0x248d3132U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[6U] = 0xbf800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[7U] = 0x248d3132U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[7U] = 0xbf800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[8U] = 0x3f800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[8U] = 0U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[9U] = 0x248d3132U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[9U] = 0xbf800000U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[0xaU] = 0x3f3504f3U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[0xaU] = 0xbf3504f3U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[0xbU] = 0xbf3504f3U;
    vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[0xbU] = 0xbf3504f3U;
    // INITIAL at genesis_verif/top_fft.v:139
    vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[0U] 
	= (VL_ULL(0x3f80000000000000) | (VL_ULL(0xffffffff) 
					 & vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem
					 [0U]));
    vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[0U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem
	   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[0U] 
	= (VL_ULL(0xffffffff) & vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem
	   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[0U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem
	   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[0U] 
	= (VL_ULL(0x3f80000000000000) | (VL_ULL(0xffffffff) 
					 & vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem
					 [0U]));
    vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[0U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem
	   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[0U] 
	= (VL_ULL(0xffffffff) & vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem
	   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[0U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem
	   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[1U] 
	= (VL_ULL(0x3f80000000000000) | (VL_ULL(0xffffffff) 
					 & vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem
					 [1U]));
    vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[1U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem
	   [1U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[1U] 
	= (VL_ULL(0xffffffff) & vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem
	   [1U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[1U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem
	   [1U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[1U] 
	= (VL_ULL(0x3f80000000000000) | (VL_ULL(0xffffffff) 
					 & vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem
					 [1U]));
    vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[1U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem
	   [1U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[1U] 
	= (VL_ULL(0xffffffff) & vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem
	   [1U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[1U] 
	= (VL_ULL(0xffffffff00000000) & vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem
	   [1U]);
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__2(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__2\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__v__DOT__cycle_counter = vlTOPp->v__DOT__cycle_counter;
    // ALWAYS at genesis_verif/top_fft.v:355
    vlTOPp->__Vdly__v__DOT__cycle_counter = ((IData)(vlTOPp->v__DOT__rst_n)
					      ? 0U : 
					     ((IData)(1U) 
					      + vlTOPp->v__DOT__cycle_counter));
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__3(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__3\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__fftram__DOT__cycle_num,3,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v0,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v1,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v2,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v2,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v2,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v3,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v3,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v3,0,0);
    //char	__VpadToAlign57[7];
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v0,63,0);
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v1,63,0);
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v2,63,0);
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v3,63,0);
    // Body
    __Vdly__v__DOT__fftram__DOT__cycle_num = vlTOPp->v__DOT__fftram__DOT__cycle_num;
    vlTOPp->__Vdly__v__DOT__fftctl__DOT__stageno = vlTOPp->v__DOT__fftctl__DOT__stageno;
    vlTOPp->__Vdly__v__DOT__fftctl_cycle_num = vlTOPp->v__DOT__fftctl_cycle_num;
    vlTOPp->__Vdly__v__DOT__BFLY0_op2_ix = vlTOPp->v__DOT__BFLY0_op2_ix;
    vlTOPp->__Vdly__v__DOT__BFLY0_op1_ix = vlTOPp->v__DOT__BFLY0_op1_ix;
    vlTOPp->__Vdly__v__DOT__rst_n = vlTOPp->v__DOT__rst_n;
    // ALWAYS at genesis_verif/top_fft.v:360
    VL_WRITEF("------------------------------------------------------------------------------\n");
    VL_WRITEF("clock.vp: reset=%1u, ncy=%4u, time=%6u ns\n",
	      1,vlTOPp->v__DOT__rst_n,32,vlTOPp->v__DOT__cycle_counter,
	      64,VL_TIME_Q());
    VL_WRITEF("------------------------------------------------------------------------------\n");
    vlTOPp->__Vdlyvset__v__DOT__bufnum__v0 = 0U;
    vlTOPp->__Vdlyvset__v__DOT__bufnum__v1 = 0U;
    vlTOPp->__Vdlyvset__v__DOT__bufnum__v2 = 0U;
    vlTOPp->__Vdlyvset__v__DOT__bufnum__v3 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v0 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v1 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v2 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v3 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v0 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v1 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v2 = 0U;
    __Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v3 = 0U;
    // ALWAYS at genesis_verif//fftram_unq1.v:170
    VL_WRITEF("fftctl %1u: cycle_num = %1u BOTF\n",
	      64,VL_TIME_Q(),4,(IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num));
    // ALWAYS at genesis_verif/top_fft.v:210
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->v__DOT__rst_n))))) {
	VL_WRITEF("\n");
	VL_WRITEF("top_fft %5u: BFLY0_twiddle_cos = %x (bsr'%08x)\n",
		  64,VL_TIME_Q(),32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos);
	VL_WRITEF("\n");
    }
    // ALWAYS at genesis_verif//fftram_unq1.v:474
    VL_WRITEF("\n");
    VL_WRITEF("fftram %1u: BFLY0_op1_match[0] = %1u\n",
	      64,VL_TIME_Q(),1,vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	      [0U]);
    VL_WRITEF("fftram %1u: BFLY0_out1_data_i = %16x\n",
	      64,VL_TIME_Q(),64,vlTOPp->v__DOT__BFLY0_out1_data);
    VL_WRITEF("\n");
    // ALWAYS at genesis_verif//fftram_unq1.v:207
    VL_WRITEF("fftram %6u bypass_valid[2]=%1u SRAM002_active=%1u bypassed_rnum[2]=%1u SRAM002_ix=%1u GLOOP\n",
	      64,VL_TIME_Q(),1,vlTOPp->v__DOT__fftram__DOT__bypass_valid
	      [2U],1,vlTOPp->v__DOT__fftram__DOT__SRAM002_active,
	      1,vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	      [2U],1,vlTOPp->v__DOT__fftram__DOT__SRAM002_ix);
    if (VL_UNLIKELY(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
		      [0U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_active)) 
		     & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix) 
			== vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			[0U])))) {
	VL_WRITEF("fftram %6u Bypassed SRAM 0, read  (bsr'%08x,bsr'%08x) from bypassed_data[0] BOTF\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__fftram__DOT__bypassed_data
					     [0U] >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__fftram__DOT__bypassed_data
			     [0U]));
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[0U] = 0U;
    }
    if (VL_UNLIKELY(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
		      [1U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_active)) 
		     & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix) 
			== vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			[1U])))) {
	VL_WRITEF("fftram %6u Bypassed SRAM 1, read  (bsr'%08x,bsr'%08x) from bypassed_data[1] BOTF\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__fftram__DOT__bypassed_data
					     [1U] >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__fftram__DOT__bypassed_data
			     [1U]));
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[1U] = 0U;
    }
    if (VL_UNLIKELY(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
		      [2U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_active)) 
		     & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix) 
			== vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			[2U])))) {
	VL_WRITEF("fftram %6u Bypassed SRAM 2, read  (bsr'%08x,bsr'%08x) from bypassed_data[2] BOTF\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__fftram__DOT__bypassed_data
					     [2U] >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__fftram__DOT__bypassed_data
			     [2U]));
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[2U] = 0U;
    }
    if (VL_UNLIKELY(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
		      [3U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_active)) 
		     & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix) 
			== vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			[3U])))) {
	VL_WRITEF("fftram %6u Bypassed SRAM 3, read  (bsr'%08x,bsr'%08x) from bypassed_data[3] BOTF\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__fftram__DOT__bypassed_data
					     [3U] >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__fftram__DOT__bypassed_data
			     [3U]));
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[3U] = 0U;
    }
    // ALWAYS at genesis_verif/top_fft.v:190
    if (VL_UNLIKELY((0U < (IData)(vlTOPp->v__DOT__fftctl_cycle_num)))) {
	VL_WRITEF("\n");
	VL_WRITEF("top_fft swizzle %5u: BFLY0_op1 ix%02u => SRAM%03u mem[%02u]\n",
		  64,VL_TIME_Q(),3,(IData)(vlTOPp->v__DOT__BFLY0_op1_ix),
		  2,vlTOPp->v__DOT__BFLY0_op1_bnum,
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
			   >> 2U)));
	VL_WRITEF("top_fft swizzle %5u: BFLY0_op2 ix%02u => SRAM%03u mem[%02u]\n",
		  64,VL_TIME_Q(),3,(IData)(vlTOPp->v__DOT__BFLY0_op2_ix),
		  2,vlTOPp->v__DOT__BFLY0_op2_bnum,
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
			   >> 2U)));
	VL_WRITEF("\n");
    }
    // ALWAYS at genesis_verif/top_fft.v:255
    if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->v__DOT__fftctl__DOT__LAST)) 
			   | (IData)(vlTOPp->v__DOT__start))))) {
	VL_WRITEF("top_fft t5\n");
	VL_WRITEF("top_fft t5 %5u: in1(r,i)= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					     >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data));
	VL_WRITEF("top_fft t5 %5u: in2(r,i)= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					     >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data));
	VL_WRITEF("top_fft t5\n");
	VL_WRITEF("top_fft t5 %5u: tw_cos  =     bsr'%08x\n",
		  64,VL_TIME_Q(),32,vlTOPp->v__DOT__BFLY0_twiddle_cos);
	VL_WRITEF("top_fft t5 %5u: tw_sin  =     bsr'%08x\n",
		  64,VL_TIME_Q(),32,vlTOPp->v__DOT__BFLY0_twiddle_sin);
	VL_WRITEF("top_fft t5\n");
	VL_WRITEF("top_fft t5 %5u: out1(r,i)= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__BFLY0_out1_data 
					     >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_out1_data));
	VL_WRITEF("top_fft t5 %5u: out2(r,i)= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),32,(IData)((vlTOPp->v__DOT__BFLY0_out2_data 
					     >> 0x20U)),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_out2_data));
	VL_WRITEF("top_fft t5\n");
    }
    // ALWAYS at genesis_verif//fftram_unq1.v:163
    __Vdly__v__DOT__fftram__DOT__cycle_num = (0xfU 
					      & ((IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)
						  ? 
						 ((IData)(1U) 
						  + (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))
						  : 0U));
    // ALWAYS at genesis_verif//fftram_unq1.v:260
    if ((0U == (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))) {
	vlTOPp->v__DOT__fftram__DOT__SRAM000_wz = 1U;
    } else {
	if (((IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started) 
	     & ((0U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
		| (0U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))))) {
	    vlTOPp->v__DOT__fftram__DOT__SRAM000_wz 
		= (1U & (IData)(vlTOPp->v__DOT__suppress_wz));
	    if (VL_UNLIKELY(vlTOPp->v__DOT__fftram__DOT__bypass_time)) {
		VL_WRITEF("FLOOF %1u prev was 1, swz is 0 (suppress) - I predicted it!!!\n",
			  64,VL_TIME_Q());
		__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v0 = 1U;
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v0 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data;
		VL_WRITEF("fftram %6u Bypassed SRAM 0, wrote (bsr'%08x,bsr'%08x) to bypassed_data[0] BTOF row %1u\n",
			  64,VL_TIME_Q(),32,(IData)(
						    (vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data 
						     >> 0x20U)),
			  32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data),
			  1,vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			  [0U]);
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v0 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM000_ix;
		__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v0 = 1U;
	    }
	} else {
	    vlTOPp->v__DOT__fftram__DOT__SRAM000_wz = 1U;
	}
    }
    // ALWAYS at genesis_verif//fftram_unq1.v:285
    if ((0U == (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))) {
	vlTOPp->v__DOT__fftram__DOT__SRAM001_wz = 1U;
    } else {
	if (((IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started) 
	     & ((1U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
		| (1U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))))) {
	    vlTOPp->v__DOT__fftram__DOT__SRAM001_wz 
		= (1U & ((IData)(vlTOPp->v__DOT__suppress_wz) 
			 >> 1U));
	    if (VL_UNLIKELY(vlTOPp->v__DOT__fftram__DOT__bypass_time)) {
		VL_WRITEF("FLOOF %1u prev was 1, swz is 0 (suppress) - I predicted it!!!\n",
			  64,VL_TIME_Q());
		__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v1 = 1U;
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v1 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data;
		VL_WRITEF("fftram %6u Bypassed SRAM 1, wrote (bsr'%08x,bsr'%08x) to bypassed_data[1] BTOF row %1u\n",
			  64,VL_TIME_Q(),32,(IData)(
						    (vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data 
						     >> 0x20U)),
			  32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data),
			  1,vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			  [1U]);
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v1 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM001_ix;
		__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v1 = 1U;
	    }
	} else {
	    vlTOPp->v__DOT__fftram__DOT__SRAM001_wz = 1U;
	}
    }
    // ALWAYS at genesis_verif//fftram_unq1.v:310
    if ((0U == (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))) {
	vlTOPp->v__DOT__fftram__DOT__SRAM002_wz = 1U;
    } else {
	if (((IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started) 
	     & ((2U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
		| (2U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))))) {
	    vlTOPp->v__DOT__fftram__DOT__SRAM002_wz 
		= (1U & ((IData)(vlTOPp->v__DOT__suppress_wz) 
			 >> 2U));
	    if (VL_UNLIKELY(vlTOPp->v__DOT__fftram__DOT__bypass_time)) {
		VL_WRITEF("FLOOF %1u prev was 1, swz is 0 (suppress) - I predicted it!!!\n",
			  64,VL_TIME_Q());
		__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v2 = 1U;
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v2 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data;
		VL_WRITEF("fftram %6u Bypassed SRAM 2, wrote (bsr'%08x,bsr'%08x) to bypassed_data[2] BTOF row %1u\n",
			  64,VL_TIME_Q(),32,(IData)(
						    (vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data 
						     >> 0x20U)),
			  32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data),
			  1,vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			  [2U]);
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v2 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM002_ix;
		__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v2 = 1U;
	    }
	} else {
	    vlTOPp->v__DOT__fftram__DOT__SRAM002_wz = 1U;
	}
    }
    // ALWAYS at genesis_verif//fftram_unq1.v:335
    if ((0U == (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))) {
	vlTOPp->v__DOT__fftram__DOT__SRAM003_wz = 1U;
    } else {
	if (((IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started) 
	     & ((3U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
		| (3U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))))) {
	    vlTOPp->v__DOT__fftram__DOT__SRAM003_wz 
		= (1U & ((IData)(vlTOPp->v__DOT__suppress_wz) 
			 >> 3U));
	    if (VL_UNLIKELY(vlTOPp->v__DOT__fftram__DOT__bypass_time)) {
		VL_WRITEF("FLOOF %1u prev was 1, swz is 0 (suppress) - I predicted it!!!\n",
			  64,VL_TIME_Q());
		__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v3 = 1U;
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v3 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data;
		VL_WRITEF("fftram %6u Bypassed SRAM 3, wrote (bsr'%08x,bsr'%08x) to bypassed_data[3] BTOF row %1u\n",
			  64,VL_TIME_Q(),32,(IData)(
						    (vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data 
						     >> 0x20U)),
			  32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data),
			  1,vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
			  [3U]);
		__Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v3 
		    = vlTOPp->v__DOT__fftram__DOT__SRAM003_ix;
		__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v3 = 1U;
	    }
	} else {
	    vlTOPp->v__DOT__fftram__DOT__SRAM003_wz = 1U;
	}
    }
    vlTOPp->v__DOT__fftram__DOT__cycle_num = __Vdly__v__DOT__fftram__DOT__cycle_num;
    // ALWAYSPOST at genesis_verif//fftram_unq1.v:275
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v0) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_data[0U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v0;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v1) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_data[1U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v1;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v2) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_data[2U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v2;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v3) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_data[3U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_data__v3;
    }
    // ALWAYSPOST at genesis_verif//fftram_unq1.v:274
    if (__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v0) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[0U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v0;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v1) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[1U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v1;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v2) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[2U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v2;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypassed_rnum__v3) {
	vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[3U] 
	    = __Vdlyvval__v__DOT__fftram__DOT__bypassed_rnum__v3;
    }
    // ALWAYSPOST at genesis_verif//fftram_unq1.v:273
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v0) {
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[0U] = 1U;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v1) {
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[1U] = 1U;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v2) {
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[2U] = 1U;
    }
    if (__Vdlyvset__v__DOT__fftram__DOT__bypass_valid__v3) {
	vlTOPp->v__DOT__fftram__DOT__bypass_valid[3U] = 1U;
    }
    // ALWAYS at genesis_verif/top_fft.v:339
    if (VL_UNLIKELY(vlTOPp->v__DOT__rst_n)) {
	VL_WRITEF("\nRESET!!!\n");
	vlTOPp->__Vdly__v__DOT__rst_n = 0U;
	vlTOPp->v__DOT__start = 1U;
    } else {
	vlTOPp->v__DOT__start = 0U;
    }
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__4(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__4\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__cycle_counter = vlTOPp->__Vdly__v__DOT__cycle_counter;
    vlTOPp->done = (0x12U == vlTOPp->v__DOT__cycle_counter);
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__5(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__5\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0,0,0);
    //char	__VpadToAlign138[6];
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0,63,0);
    // Body
    __Vdlyvset__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0 = 0U;
    // ALWAYS at genesis_verif//SRAM_unq1.v:136
    if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez)) 
			   & (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz)))))) {
	VL_WRITEF("%Nv.fftram.SRAM000 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM000_wz);
	__Vdlyvval__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data;
	__Vdlyvset__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0 = 1U;
	__Vdlyvdim0__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM000_ix;
	VL_WRITEF("%Nv.fftram.SRAM000 %1u: Wrote   wr_data_i mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data);
	VL_WRITEF("SRAM000 t5 %5u: Wrote(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data));
	VL_WRITEF("\n");
    }
    // ALWAYSPOST at genesis_verif//SRAM_unq1.v:140
    if (__Vdlyvset__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0) {
	vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[__Vdlyvdim0__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0] 
	    = __Vdlyvval__v__DOT__fftram__DOT__SRAM000__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__6(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__6\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0,0,0);
    //char	__VpadToAlign174[2];
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0,63,0);
    // Body
    __Vdlyvset__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0 = 0U;
    // ALWAYS at genesis_verif//SRAM_unq2.v:136
    if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez)) 
			   & (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz)))))) {
	VL_WRITEF("%Nv.fftram.SRAM001 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM001_wz);
	__Vdlyvval__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data;
	__Vdlyvset__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0 = 1U;
	__Vdlyvdim0__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM001_ix;
	VL_WRITEF("%Nv.fftram.SRAM001 %1u: Wrote   wr_data_i mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data);
	VL_WRITEF("SRAM001 t5 %5u: Wrote(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data));
	VL_WRITEF("\n");
    }
    // ALWAYSPOST at genesis_verif//SRAM_unq2.v:140
    if (__Vdlyvset__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0) {
	vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[__Vdlyvdim0__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0] 
	    = __Vdlyvval__v__DOT__fftram__DOT__SRAM001__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__7(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__7\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0,0,0);
    //char	__VpadToAlign206[2];
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0,63,0);
    // Body
    __Vdlyvset__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0 = 0U;
    // ALWAYS at genesis_verif//SRAM_unq3.v:136
    if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez)) 
			   & (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz)))))) {
	VL_WRITEF("%Nv.fftram.SRAM002 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM002_wz);
	__Vdlyvval__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data;
	__Vdlyvset__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0 = 1U;
	__Vdlyvdim0__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM002_ix;
	VL_WRITEF("%Nv.fftram.SRAM002 %1u: Wrote   wr_data_i mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data);
	VL_WRITEF("SRAM002 t5 %5u: Wrote(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data));
	VL_WRITEF("\n");
    }
    // ALWAYSPOST at genesis_verif//SRAM_unq3.v:140
    if (__Vdlyvset__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0) {
	vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[__Vdlyvdim0__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0] 
	    = __Vdlyvval__v__DOT__fftram__DOT__SRAM002__DOT__mem__v0;
    }
}

void Vtop_fft::_initial__TOP__8(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_initial__TOP__8\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at genesis_verif//fftram_unq1.v:146
    vlTOPp->v__DOT__fftram__DOT__cycle_num = 0U;
    // INITIAL at genesis_verif//fftram_unq1.v:153
    vlTOPp->v__DOT__fftram__DOT__bypass_valid[0U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[0U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_data[0U] = VL_ULL(0);
    vlTOPp->v__DOT__fftram__DOT__bypass_valid[1U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[1U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_data[1U] = VL_ULL(0);
    vlTOPp->v__DOT__fftram__DOT__bypass_valid[2U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[2U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_data[2U] = VL_ULL(0);
    vlTOPp->v__DOT__fftram__DOT__bypass_valid[3U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[3U] = 0U;
    vlTOPp->v__DOT__fftram__DOT__bypassed_data[3U] = VL_ULL(0);
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__9(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__9\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0,0,0);
    //char	__VpadToAlign258[6];
    VL_SIG64(__Vdlyvval__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0,63,0);
    // Body
    __Vdlyvset__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0 = 0U;
    // ALWAYS at genesis_verif//SRAM_unq4.v:136
    if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez)) 
			   & (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz)))))) {
	VL_WRITEF("%Nv.fftram.SRAM003 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM003_wz);
	__Vdlyvval__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data;
	__Vdlyvset__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0 = 1U;
	__Vdlyvdim0__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0 
	    = vlTOPp->v__DOT__fftram__DOT__SRAM003_ix;
	VL_WRITEF("%Nv.fftram.SRAM003 %1u: Wrote   wr_data_i mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data);
	VL_WRITEF("SRAM003 t5 %5u: Wrote(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data));
	VL_WRITEF("\n");
    }
    // ALWAYSPOST at genesis_verif//SRAM_unq4.v:140
    if (__Vdlyvset__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0) {
	vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[__Vdlyvdim0__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0] 
	    = __Vdlyvval__v__DOT__fftram__DOT__SRAM003__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__11(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__11\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__v__DOT__fftctl__DOT__out2_offset 
	= vlTOPp->v__DOT__fftctl__DOT__out2_offset;
    vlTOPp->__Vdly__v__DOT__fftctl__DOT__cycle_num 
	= vlTOPp->v__DOT__fftctl__DOT__cycle_num;
}

void Vtop_fft::_settle__TOP__12(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__12\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->done = (0x12U == vlTOPp->v__DOT__cycle_counter);
    vlTOPp->v__DOT__fftram__DOT__bypass_time = (((0U 
						  < (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num)) 
						 & (0xcU 
						    > (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))) 
						& (0U 
						   == 
						   (3U 
						    & (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))));
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__13(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__13\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__Vfuncout,5,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__CyNum,4,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__ii,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i_reordered,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op1,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op2,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__Vfuncout,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__i,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__StageNo,1,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__shifted_double_i,5,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__Vfuncout,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__ii,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__StageNo,1,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__low_T,1,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__shifted_double_t,3,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__Vfuncout,5,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__CyNum,4,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__ii,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i_reordered,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op1,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op2,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__Vfuncout,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__i,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__StageNo,1,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__shifted_double_i,5,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__Vfuncout,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__ii,2,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__StageNo,1,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__low_T,1,0);
    VL_SIG8(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__shifted_double_t,3,0);
    // Body
    vlTOPp->v__DOT__fftram__DOT__bypass_time = (((0U 
						  < (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num)) 
						 & (0xcU 
						    > (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))) 
						& (0U 
						   == 
						   (3U 
						    & (IData)(vlTOPp->v__DOT__fftram__DOT__cycle_num))));
    // ALWAYS at genesis_verif//fftctl_unq1.v:413
    if (VL_UNLIKELY(((IData)(vlTOPp->v__DOT__fftctl__DOT__STARTED) 
		     & (~ (IData)(vlTOPp->v__DOT__rst_n))))) {
	VL_WRITEF("fftctl %1u: cycle_num = %1u\n",64,
		  VL_TIME_Q(),5,(IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num));
	// Function: GenOps2 at genesis_verif//fftctl_unq1.v:422
	// Function: RotateLeft at genesis_verif//fftctl_unq1.v:240
	// Function: RotateSubword at genesis_verif//fftctl_unq1.v:241
	// Function: GenOps2 at genesis_verif//fftctl_unq1.v:422
	// Function: RotateLeft at genesis_verif//fftctl_unq1.v:240
	// Function: RotateSubword at genesis_verif//fftctl_unq1.v:241
	VL_WRITEF("fftctl %1u: fftctl_cycle_num_o = %1u\n",
		  64,VL_TIME_Q(),5,(IData)(vlTOPp->v__DOT__fftctl_cycle_num));
	vlTOPp->__Vdlyvset__v__DOT__bufnum__v0 = 1U;
	VL_WRITEF("fftctl %1u: out2_offset = %1u\n",
		  64,VL_TIME_Q(),4,(IData)(vlTOPp->v__DOT__fftctl__DOT__out2_offset));
	vlTOPp->__Vdlyvset__v__DOT__bufnum__v1 = 1U;
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo 
	    = vlTOPp->v__DOT__fftctl__DOT__stageno;
	vlTOPp->__Vdlyvset__v__DOT__bufnum__v2 = 1U;
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__CyNum 
	    = vlTOPp->v__DOT__fftctl__DOT__cycle_num;
	vlTOPp->__Vdlyvset__v__DOT__bufnum__v3 = 1U;
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__ii 
	    = (6U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__CyNum) 
		     << 1U));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__StageNo 
	    = (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__ii 
	    = __Vfunc_v__DOT__fftctl__DOT__GenOps2__0__ii;
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__low_T 
	    = (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__ii));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__shifted_double_t 
	    = (0xfU & ((3U >= ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__StageNo) 
			       - (IData)(1U))) ? ((
						   ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__low_T) 
						    << 2U) 
						   | (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__low_T)) 
						  << 
						  ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__StageNo) 
						   - (IData)(1U)))
		        : 0U));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__Vfuncout 
	    = ((6U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__shifted_double_t) 
		      >> 1U)) | (1U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__ii) 
				       >> 2U)));
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__StageNo 
	    = (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo));
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__i 
	    = __Vfunc_v__DOT__fftctl__DOT__GenOps2__0__ii;
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__shifted_double_i 
	    = (0x3fU & ((((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__i) 
			  << 3U) | (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__i)) 
			<< (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__StageNo)));
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__Vfuncout 
	    = (7U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__shifted_double_i) 
		     >> 3U));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i 
	    = ((1U >= (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo))
	        ? (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__1__Vfuncout)
	        : (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__2__Vfuncout));
	VL_WRITEF("GENOPS2 (t=%06u) ii,i: (%1u,%1u) => (%1u,%1u)\n",
		  64,VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__ii),
		  32,((IData)(1U) + (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__ii)),
		  3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i),
		  32,((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i) 
		      + VL_POWSS_III(32,32,3, (IData)(2U), (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo), 1,0)));
	VL_WRITEF("GENOPS2\n");
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P 
	    = ((6U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P)) 
	       | (1U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i) 
			^ ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i) 
			   >> 2U))));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P 
	    = ((5U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P)) 
	       | (2U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i)));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P 
	    = ((3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P)) 
	       | (4U & (((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i) 
			 << 2U) ^ (0xfffffffcU & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i)))));
	VL_WRITEF("GENOPS2 (t=%06u) > P = %08b\n",64,
		  VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P));
	if ((0U == (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo))) {
	    __Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i_reordered 
		= ((4U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i)) 
		   | (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P)));
	} else {
	    if ((1U == (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo))) {
		__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i_reordered 
		    = ((6U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P)) 
		       | (1U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i)));
	    } else {
		if ((2U == (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo))) {
		    __Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i_reordered 
			= ((6U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__P)) 
			   | (1U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i)));
		}
	    }
	}
	VL_WRITEF("GENOPS2 (t=%06u) > ir= %08b\n",64,
		  VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i_reordered));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op1 
	    = ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i_reordered) 
	       & (~ ((IData)(1U) << (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo))));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op2 
	    = (7U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__i_reordered) 
		     | ((IData)(1U) << (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__StageNo))));
	VL_WRITEF("GENOPS2\n");
	VL_WRITEF("GENOPS2 (t=%06u) > op1= %08b\n",
		  64,VL_TIME_Q(),11,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op1));
	VL_WRITEF("GENOPS2 (t=%06u) > op2= %08b\n",
		  64,VL_TIME_Q(),11,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op2));
	VL_WRITEF("GENOPS2\n");
	VL_WRITEF("GENOPS2 (t=%06u) ops=(%1u,%1u)\n",
		  64,VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op1),
		  3,__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op2);
	VL_WRITEF("GENOPS2 -----------------------------------------------------\n");
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__Vfuncout 
	    = (((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op1) 
		<< 3U) | (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__op2));
	vlTOPp->__Vdly__v__DOT__BFLY0_op1_ix = (7U 
						& ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__0__Vfuncout) 
						   >> 3U));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo 
	    = vlTOPp->v__DOT__fftctl__DOT__stageno;
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__CyNum 
	    = vlTOPp->v__DOT__fftctl__DOT__cycle_num;
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__ii 
	    = (6U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__CyNum) 
		     << 1U));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__StageNo 
	    = (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__ii 
	    = __Vfunc_v__DOT__fftctl__DOT__GenOps2__3__ii;
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__low_T 
	    = (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__ii));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__shifted_double_t 
	    = (0xfU & ((3U >= ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__StageNo) 
			       - (IData)(1U))) ? ((
						   ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__low_T) 
						    << 2U) 
						   | (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__low_T)) 
						  << 
						  ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__StageNo) 
						   - (IData)(1U)))
		        : 0U));
	__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__Vfuncout 
	    = ((6U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__shifted_double_t) 
		      >> 1U)) | (1U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__ii) 
				       >> 2U)));
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__StageNo 
	    = (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo));
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__i 
	    = __Vfunc_v__DOT__fftctl__DOT__GenOps2__3__ii;
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__shifted_double_i 
	    = (0x3fU & ((((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__i) 
			  << 3U) | (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__i)) 
			<< (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__StageNo)));
	__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__Vfuncout 
	    = (7U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__shifted_double_i) 
		     >> 3U));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i 
	    = ((1U >= (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo))
	        ? (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateLeft__4__Vfuncout)
	        : (IData)(__Vfunc_v__DOT__fftctl__DOT__RotateSubword__5__Vfuncout));
	VL_WRITEF("GENOPS2 (t=%06u) ii,i: (%1u,%1u) => (%1u,%1u)\n",
		  64,VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__ii),
		  32,((IData)(1U) + (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__ii)),
		  3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i),
		  32,((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i) 
		      + VL_POWSS_III(32,32,3, (IData)(2U), (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo), 1,0)));
	VL_WRITEF("GENOPS2\n");
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P 
	    = ((6U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P)) 
	       | (1U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i) 
			^ ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i) 
			   >> 2U))));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P 
	    = ((5U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P)) 
	       | (2U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i)));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P 
	    = ((3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P)) 
	       | (4U & (((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i) 
			 << 2U) ^ (0xfffffffcU & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i)))));
	VL_WRITEF("GENOPS2 (t=%06u) > P = %08b\n",64,
		  VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P));
	if ((0U == (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo))) {
	    __Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i_reordered 
		= ((4U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i)) 
		   | (3U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P)));
	} else {
	    if ((1U == (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo))) {
		__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i_reordered 
		    = ((6U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P)) 
		       | (1U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i)));
	    } else {
		if ((2U == (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo))) {
		    __Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i_reordered 
			= ((6U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__P)) 
			   | (1U & (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i)));
		}
	    }
	}
	VL_WRITEF("GENOPS2 (t=%06u) > ir= %08b\n",64,
		  VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i_reordered));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op1 
	    = ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i_reordered) 
	       & (~ ((IData)(1U) << (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo))));
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op2 
	    = (7U & ((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__i_reordered) 
		     | ((IData)(1U) << (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__StageNo))));
	VL_WRITEF("GENOPS2\n");
	VL_WRITEF("GENOPS2 (t=%06u) > op1= %08b\n",
		  64,VL_TIME_Q(),11,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op1));
	VL_WRITEF("GENOPS2 (t=%06u) > op2= %08b\n",
		  64,VL_TIME_Q(),11,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op2));
	VL_WRITEF("GENOPS2\n");
	VL_WRITEF("GENOPS2 (t=%06u) ops=(%1u,%1u)\n",
		  64,VL_TIME_Q(),3,(IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op1),
		  3,__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op2);
	VL_WRITEF("GENOPS2 -----------------------------------------------------\n");
	__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__Vfuncout 
	    = (((IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op1) 
		<< 3U) | (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__op2));
	vlTOPp->__Vdly__v__DOT__BFLY0_op2_ix = (7U 
						& (IData)(__Vfunc_v__DOT__fftctl__DOT__GenOps2__3__Vfuncout));
	vlTOPp->v__DOT__BFLY0_access_type = ((0xbU 
					      >= (0xfU 
						  & (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num)))
					      ? vlTOPp->v__DOT__fftctl__DOT__BFLY0_access_type
					     [(0xfU 
					       & (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num))]
					      : 0U);
	vlTOPp->v__DOT__suppress_wz = ((0xbU >= (0xfU 
						 & (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num)))
				        ? vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz
				       [(0xfU & (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num))]
				        : 0U);
	vlTOPp->v__DOT__bypass_read = ((0xbU >= (0xfU 
						 & (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num)))
				        ? vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read
				       [(0xfU & (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num))]
				        : 0U);
	VL_WRITEF("fftctl %1u: in(%2u,%2u), out(%2u, %2u)\n",
		  64,VL_TIME_Q(),3,(IData)(vlTOPp->v__DOT__BFLY0_op1_ix),
		  3,vlTOPp->v__DOT__BFLY0_op2_ix,3,
		  (IData)(vlTOPp->v__DOT__BFLY0_op1_ix),
		  3,vlTOPp->v__DOT__BFLY0_op2_ix);
	if (VL_UNLIKELY((3U == (3U & (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num))))) {
	    vlTOPp->__Vdly__v__DOT__fftctl__DOT__stageno 
		= (7U & ((IData)(1U) + (IData)(vlTOPp->v__DOT__fftctl__DOT__stageno)));
	    vlTOPp->__Vdly__v__DOT__fftctl__DOT__out2_offset 
		= (0xfU & ((IData)(vlTOPp->v__DOT__fftctl__DOT__out2_offset) 
			   << 1U));
	    VL_WRITEF("GENOPS2 (t=%06u) STAGE %1u\n",
		      64,VL_TIME_Q(),32,((IData)(1U) 
					 + (IData)(vlTOPp->v__DOT__fftctl__DOT__stageno)));
	}
	vlTOPp->__Vdly__v__DOT__fftctl_cycle_num = vlTOPp->v__DOT__fftctl__DOT__cycle_num;
	vlTOPp->__Vdly__v__DOT__fftctl__DOT__cycle_num 
	    = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num)));
	VL_WRITEF("fftctl %1u: cycle_num = %1u\n",64,
		  VL_TIME_Q(),5,(IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num));
    }
    vlTOPp->v__DOT__fftctl__DOT__stageno = vlTOPp->__Vdly__v__DOT__fftctl__DOT__stageno;
    // ALWAYSPOST at genesis_verif//fftctl_unq1.v:436
    if (vlTOPp->__Vdlyvset__v__DOT__bufnum__v0) {
	vlTOPp->v__DOT__bufnum[0U] = 0U;
    }
    if (vlTOPp->__Vdlyvset__v__DOT__bufnum__v1) {
	vlTOPp->v__DOT__bufnum[1U] = 0U;
    }
    if (vlTOPp->__Vdlyvset__v__DOT__bufnum__v2) {
	vlTOPp->v__DOT__bufnum[2U] = 0U;
    }
    if (vlTOPp->__Vdlyvset__v__DOT__bufnum__v3) {
	vlTOPp->v__DOT__bufnum[3U] = 0U;
    }
    vlTOPp->v__DOT__fftctl_cycle_num = vlTOPp->__Vdly__v__DOT__fftctl_cycle_num;
    vlTOPp->v__DOT__BFLY0_op2_ix = vlTOPp->__Vdly__v__DOT__BFLY0_op2_ix;
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[3U] = vlTOPp->v__DOT__bufnum
	[3U];
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[2U] = vlTOPp->v__DOT__bufnum
	[2U];
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[1U] = vlTOPp->v__DOT__bufnum
	[1U];
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[0U] = vlTOPp->v__DOT__bufnum
	[0U];
    vlTOPp->v__DOT__BFLY0_twiddle_cos = ((0xbU >= (0xfU 
						   & (IData)(vlTOPp->v__DOT__fftctl_cycle_num)))
					  ? vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos
					 [(0xfU & (IData)(vlTOPp->v__DOT__fftctl_cycle_num))]
					  : 0U);
    vlTOPp->v__DOT__BFLY0_twiddle_sin = ((0xbU >= (0xfU 
						   & (IData)(vlTOPp->v__DOT__fftctl_cycle_num)))
					  ? vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin
					 [(0xfU & (IData)(vlTOPp->v__DOT__fftctl_cycle_num))]
					  : 0U);
    vlTOPp->v__DOT__BFLY0_op2_bnum = ((2U & (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
				      | (1U & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
					       ^ ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						  >> 2U))));
    vlTOPp->v__DOT__BFLY0_op2_bnum = ((1U & (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
				      | (2U & (IData)(vlTOPp->v__DOT__BFLY0_op2_ix)));
}

void Vtop_fft::_initial__TOP__14(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_initial__TOP__14\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at genesis_verif//fftctl_unq1.v:352
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[0U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[0U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[1U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[1U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[2U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[2U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[3U] = 4U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[3U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[4U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[4U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[5U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[5U] = 8U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[6U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[6U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[7U] = 2U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[7U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[8U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[8U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[9U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[9U] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[0xaU] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[0xaU] = 1U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[0xbU] = 0U;
    vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[0xbU] = 0U;
}

void Vtop_fft::_settle__TOP__16(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__16\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[3U] = vlTOPp->v__DOT__bufnum
	[3U];
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[2U] = vlTOPp->v__DOT__bufnum
	[2U];
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[1U] = vlTOPp->v__DOT__bufnum
	[1U];
    vlTOPp->v__DOT__fftctl__DOT__bufnum_o[0U] = vlTOPp->v__DOT__bufnum
	[0U];
    vlTOPp->v__DOT__BFLY0_twiddle_cos = ((0xbU >= (0xfU 
						   & (IData)(vlTOPp->v__DOT__fftctl_cycle_num)))
					  ? vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos
					 [(0xfU & (IData)(vlTOPp->v__DOT__fftctl_cycle_num))]
					  : 0U);
    vlTOPp->v__DOT__BFLY0_twiddle_sin = ((0xbU >= (0xfU 
						   & (IData)(vlTOPp->v__DOT__fftctl_cycle_num)))
					  ? vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin
					 [(0xfU & (IData)(vlTOPp->v__DOT__fftctl_cycle_num))]
					  : 0U);
    vlTOPp->v__DOT__BFLY0_op2_bnum = ((2U & (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
				      | (1U & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
					       ^ ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						  >> 2U))));
    vlTOPp->v__DOT__BFLY0_op2_bnum = ((1U & (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
				      | (2U & (IData)(vlTOPp->v__DOT__BFLY0_op2_ix)));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[0U] 
	= (0U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[1U] 
	= (1U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[2U] 
	= (2U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[3U] 
	= (3U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__17(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__17\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at genesis_verif//fftctl_unq1.v:462
    if (vlTOPp->v__DOT__fftctl__DOT__LAST) {
	vlTOPp->v__DOT__fftctl__DOT__STARTED = 0U;
	vlTOPp->__Vdly__v__DOT__BFLY0_op1_ix = 0U;
    }
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[0U] 
	= (0U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[1U] 
	= (1U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[2U] 
	= (2U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[3U] 
	= (3U == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum));
    vlTOPp->v__DOT__BFLY0_op1_ix = vlTOPp->__Vdly__v__DOT__BFLY0_op1_ix;
    vlTOPp->v__DOT__BFLY0_op1_bnum = ((2U & (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
				      | (1U & ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
					       ^ ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						  >> 2U))));
    vlTOPp->v__DOT__BFLY0_op1_bnum = ((1U & (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
				      | (2U & (IData)(vlTOPp->v__DOT__BFLY0_op1_ix)));
}

void Vtop_fft::_settle__TOP__19(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__19\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0_op1_bnum = ((2U & (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
				      | (1U & ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
					       ^ ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						  >> 2U))));
    vlTOPp->v__DOT__BFLY0_op1_bnum = ((1U & (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
				      | (2U & (IData)(vlTOPp->v__DOT__BFLY0_op1_ix)));
    // ALWAYS at genesis_verif/top_fft.v:220
    if (VL_UNLIKELY(vlTOPp->clk)) {
	VL_WRITEF("top_fft %1u: BFLY0_op1 ix %02u comes from bank %2u row %3u\n",
		  64,VL_TIME_Q(),3,(IData)(vlTOPp->v__DOT__BFLY0_op1_ix),
		  2,vlTOPp->v__DOT__BFLY0_op1_bnum,
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
			   >> 2U)));
	VL_WRITEF("top_fft %1u: BFLY0_op2 ix %02u comes from bank %2u row %3u\n",
		  64,VL_TIME_Q(),3,(IData)(vlTOPp->v__DOT__BFLY0_op2_ix),
		  2,vlTOPp->v__DOT__BFLY0_op2_bnum,
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
			   >> 2U)));
	VL_WRITEF("top_fft\n");
    }
    vlTOPp->v__DOT__fftram__DOT__SRAM000_ix = (1U & 
					       ((0U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((0U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_ix = (1U & 
					       ((1U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((1U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_ix = (1U & 
					       ((2U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((2U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__SRAM003_ix = (1U & 
					       ((3U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((3U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[0U] 
	= (0U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[1U] 
	= (1U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[2U] 
	= (2U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[3U] 
	= (3U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__20(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__20\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at genesis_verif//fftctl_unq1.v:393
    if ((1U & (~ (IData)(vlTOPp->v__DOT__rst_n)))) {
	vlTOPp->__Vdly__v__DOT__fftctl__DOT__cycle_num = 0U;
	vlTOPp->v__DOT__fftctl__DOT__STARTED = 1U;
	vlTOPp->v__DOT__fftctl__DOT__LAST = 0U;
	vlTOPp->__Vdly__v__DOT__fftctl__DOT__out2_offset = 1U;
	vlTOPp->v__DOT__suppress_wz = 0U;
    }
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__21(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__21\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at genesis_verif//fftctl_unq1.v:460
    if ((0xcU == (IData)(vlTOPp->v__DOT__fftctl__DOT__cycle_num))) {
	vlTOPp->v__DOT__fftctl__DOT__LAST = 1U;
    }
    vlTOPp->v__DOT__fftram__DOT__SRAM000_ix = (1U & 
					       ((0U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((0U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_ix = (1U & 
					       ((1U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((1U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_ix = (1U & 
					       ((2U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((2U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__SRAM003_ix = (1U & 
					       ((3U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum))
						 ? 
						((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
						 >> 2U)
						 : 
						((3U 
						  == (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum)) 
						 & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
						    >> 2U))));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[0U] 
	= (0U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[1U] 
	= (1U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[2U] 
	= (2U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
    vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[3U] 
	= (3U == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
    vlTOPp->v__DOT__rst_n = vlTOPp->__Vdly__v__DOT__rst_n;
    vlTOPp->v__DOT__fftram__DOT__SRAM000_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [0U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM001_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [1U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [1U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM002_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [2U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [2U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM003_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [3U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [3U]);
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__22(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__22\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at genesis_verif/top_fft.v:220
    if (VL_UNLIKELY(vlTOPp->clk)) {
	VL_WRITEF("top_fft %1u: BFLY0_op1 ix %02u comes from bank %2u row %3u\n",
		  64,VL_TIME_Q(),3,(IData)(vlTOPp->v__DOT__BFLY0_op1_ix),
		  2,vlTOPp->v__DOT__BFLY0_op1_bnum,
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
			   >> 2U)));
	VL_WRITEF("top_fft %1u: BFLY0_op2 ix %02u comes from bank %2u row %3u\n",
		  64,VL_TIME_Q(),3,(IData)(vlTOPp->v__DOT__BFLY0_op2_ix),
		  2,vlTOPp->v__DOT__BFLY0_op2_bnum,
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
			   >> 2U)));
	VL_WRITEF("top_fft\n");
    }
}

VL_INLINE_OPT void Vtop_fft::_sequent__TOP__23(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_sequent__TOP__23\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__fftctl__DOT__out2_offset = vlTOPp->__Vdly__v__DOT__fftctl__DOT__out2_offset;
    vlTOPp->v__DOT__fftctl__DOT__cycle_num = vlTOPp->__Vdly__v__DOT__fftctl__DOT__cycle_num;
}

void Vtop_fft::_initial__TOP__24(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_initial__TOP__24\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at genesis_verif/top_fft.v:326
    vlTOPp->v__DOT__start = 0U;
    vlTOPp->v__DOT__rst_n = 1U;
    // INITIAL at genesis_verif//fftctl_unq1.v:342
    vlTOPp->v__DOT__fftctl__DOT__cycle_num = 0U;
    vlTOPp->v__DOT__fftctl__DOT__STARTED = 0U;
    vlTOPp->v__DOT__fftctl__DOT__LAST = 1U;
    vlTOPp->v__DOT__fftctl__DOT__stageno = 0U;
    vlTOPp->v__DOT__fftctl__DOT__out2_offset = 1U;
    VL_WRITEF("GENOPS2 -----------------------------------------------------\n");
    VL_WRITEF("GENOPS2 (t=%06u) STAGE 0\n",64,VL_TIME_Q());
}

void Vtop_fft::_settle__TOP__25(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__25\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__fftram__DOT__SRAM000_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [0U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [0U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM001_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [1U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [1U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM002_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [2U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [2U]);
    vlTOPp->v__DOT__fftram__DOT__SRAM003_active = (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [3U] 
						   | vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [3U]);
    vlTOPp->v__DOT____Vcellinp__BFLY0__ready = (1U 
						& ((~ (IData)(vlTOPp->v__DOT__rst_n)) 
						   & ((~ (IData)(vlTOPp->v__DOT__fftctl__DOT__LAST)) 
						      | (IData)(vlTOPp->v__DOT__start))));
    vlTOPp->v__DOT____Vcellinp__fftram__fft_started 
	= (1U & ((~ (IData)(vlTOPp->v__DOT__fftctl__DOT__LAST)) 
		 | (IData)(vlTOPp->v__DOT__start)));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__26(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__26\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT____Vcellinp__BFLY0__ready = (1U 
						& ((~ (IData)(vlTOPp->v__DOT__rst_n)) 
						   & ((~ (IData)(vlTOPp->v__DOT__fftctl__DOT__LAST)) 
						      | (IData)(vlTOPp->v__DOT__start))));
    vlTOPp->v__DOT____Vcellinp__fftram__fft_started 
	= (1U & ((~ (IData)(vlTOPp->v__DOT__fftctl__DOT__LAST)) 
		 | (IData)(vlTOPp->v__DOT__start)));
    vlTOPp->v__DOT__fftram__DOT__SRAM000_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((0U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (0U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz))))));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((1U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (1U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz))))));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((2U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (2U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz))))));
    vlTOPp->v__DOT__fftram__DOT__SRAM003_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((3U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (3U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz))))));
}

void Vtop_fft::_settle__TOP__27(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__27\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__fftram__DOT__SRAM000_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((0U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (0U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz))))));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((1U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (1U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz))))));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((2U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (2U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz))))));
    vlTOPp->v__DOT__fftram__DOT__SRAM003_ez = (1U & 
					       ((~ (IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) 
						| (~ 
						   (((3U 
						      == (IData)(vlTOPp->v__DOT__BFLY0_op1_bnum)) 
						     | (3U 
							== (IData)(vlTOPp->v__DOT__BFLY0_op2_bnum))) 
						    | (~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz))))));
    vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM000_ix] : VL_ULL(0));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM001_ix] : VL_ULL(0));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM002_ix] : VL_ULL(0));
    // ALWAYS at genesis_verif//fftram_unq1.v:361
    if (VL_UNLIKELY(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) {
	VL_WRITEF("\n");
	VL_WRITEF("fftram %1u: fft_started = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started));
	VL_WRITEF("fftram %1u: BFLY0_op1_bnum_i = %1u\n",
		  64,VL_TIME_Q(),2,(IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
	VL_WRITEF("\n");
	VL_WRITEF("fftram %1u: SRAM000_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez));
	VL_WRITEF("fftram %1u: SRAM001_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez));
	VL_WRITEF("fftram %1u: SRAM002_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez));
	VL_WRITEF("fftram %1u: SRAM003_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez));
	VL_WRITEF("\n");
	VL_WRITEF("fftram %1u: SRAM000_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz));
	VL_WRITEF("fftram %1u: SRAM001_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz));
	VL_WRITEF("fftram %1u: SRAM002_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz));
	VL_WRITEF("fftram %1u: SRAM003_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM003_ix] : VL_ULL(0));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__28(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__28\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM000_ix] : VL_ULL(0));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM001_ix] : VL_ULL(0));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM002_ix] : VL_ULL(0));
    // ALWAYS at genesis_verif//fftram_unq1.v:361
    if (VL_UNLIKELY(vlTOPp->v__DOT____Vcellinp__fftram__fft_started)) {
	VL_WRITEF("\n");
	VL_WRITEF("fftram %1u: fft_started = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT____Vcellinp__fftram__fft_started));
	VL_WRITEF("fftram %1u: BFLY0_op1_bnum_i = %1u\n",
		  64,VL_TIME_Q(),2,(IData)(vlTOPp->v__DOT__BFLY0_op1_bnum));
	VL_WRITEF("\n");
	VL_WRITEF("fftram %1u: SRAM000_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez));
	VL_WRITEF("fftram %1u: SRAM001_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez));
	VL_WRITEF("fftram %1u: SRAM002_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez));
	VL_WRITEF("fftram %1u: SRAM003_ez = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez));
	VL_WRITEF("\n");
	VL_WRITEF("fftram %1u: SRAM000_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz));
	VL_WRITEF("fftram %1u: SRAM001_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz));
	VL_WRITEF("fftram %1u: SRAM002_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz));
	VL_WRITEF("fftram %1u: SRAM003_wz = %1u\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data = 
	(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez)) 
	  & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz))
	  ? vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem
	 [vlTOPp->v__DOT__fftram__DOT__SRAM003_ix] : VL_ULL(0));
    // ALWAYS at genesis_verif//SRAM_unq1.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM000 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM000_wz);
	VL_WRITEF("%Nv.fftram.SRAM000 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data);
	VL_WRITEF("SRAM000 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[0U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [0U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [0U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [0U] : vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data);
    // ALWAYS at genesis_verif//SRAM_unq2.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM001 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM001_wz);
	VL_WRITEF("%Nv.fftram.SRAM001 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data);
	VL_WRITEF("SRAM001 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[1U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [1U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [1U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [1U] : vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data);
    // ALWAYS at genesis_verif//SRAM_unq3.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM002 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM002_wz);
	VL_WRITEF("%Nv.fftram.SRAM002 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data);
	VL_WRITEF("SRAM002 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[2U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [2U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [2U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [2U] : vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data);
    // ALWAYS at genesis_verif//SRAM_unq4.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM003 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM003_wz);
	VL_WRITEF("%Nv.fftram.SRAM003 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data);
	VL_WRITEF("SRAM003 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[3U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [3U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [3U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [3U] : vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data);
}

void Vtop_fft::_settle__TOP__29(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__29\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at genesis_verif//SRAM_unq1.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM000 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM000_wz);
	VL_WRITEF("%Nv.fftram.SRAM000 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data);
	VL_WRITEF("SRAM000 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[0U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [0U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [0U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [0U] : vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data);
    // ALWAYS at genesis_verif//SRAM_unq2.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM001 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM001_wz);
	VL_WRITEF("%Nv.fftram.SRAM001 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data);
	VL_WRITEF("SRAM001 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[1U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [1U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [1U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [1U] : vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data);
    // ALWAYS at genesis_verif//SRAM_unq3.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM002 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM002_wz);
	VL_WRITEF("%Nv.fftram.SRAM002 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data);
	VL_WRITEF("SRAM002 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[2U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [2U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [2U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [2U] : vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data);
    // ALWAYS at genesis_verif//SRAM_unq4.v:118
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez)) 
		     & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz)))) {
	VL_WRITEF("%Nv.fftram.SRAM003 %1u: ez_i=%1u and wz_i=%1u\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez),
		  1,vlTOPp->v__DOT__fftram__DOT__SRAM003_wz);
	VL_WRITEF("%Nv.fftram.SRAM003 %1u: Reading rd_data_o mem[%1u] <= %16x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),1,
		  (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),
		  64,vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data);
	VL_WRITEF("SRAM003 t5 %5u: Read(f) wr_data_i mem[%1u] <= (bsr'%08x,bsr'%08x)\n",
		  64,VL_TIME_Q(),1,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),
		  32,(IData)((vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data 
			      >> 0x20U)),32,(IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data));
	VL_WRITEF("\n");
    }
    vlTOPp->v__DOT__fftram__DOT__sram_or_buf[3U] = 
	(((vlTOPp->v__DOT__fftram__DOT__bypass_valid
	   [3U] & (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_active)) 
	  & ((IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix) 
	     == vlTOPp->v__DOT__fftram__DOT__bypassed_rnum
	     [3U])) ? vlTOPp->v__DOT__fftram__DOT__bypassed_data
	 [3U] : vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data);
    vlTOPp->v__DOT__BFLY0_in1_data = (vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
				      [0U] ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
				      [0U] : (vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
					      [1U] ? 
					      vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					      [1U] : 
					      (vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
					       [2U]
					        ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					       [2U]
					        : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [3U]
						    ? 
						   vlTOPp->v__DOT__fftram__DOT__sram_or_buf
						   [3U]
						    : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0_in2_data = (vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
				      [0U] ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
				      [0U] : (vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
					      [1U] ? 
					      vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					      [1U] : 
					      (vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
					       [2U]
					        ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					       [2U]
					        : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [3U]
						    ? 
						   vlTOPp->v__DOT__fftram__DOT__sram_or_buf
						   [3U]
						    : VL_ULL(0)))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__30(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__30\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0_in1_data = (vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
				      [0U] ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
				      [0U] : (vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
					      [1U] ? 
					      vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					      [1U] : 
					      (vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
					       [2U]
					        ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					       [2U]
					        : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
						   [3U]
						    ? 
						   vlTOPp->v__DOT__fftram__DOT__sram_or_buf
						   [3U]
						    : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0_in2_data = (vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
				      [0U] ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
				      [0U] : (vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
					      [1U] ? 
					      vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					      [1U] : 
					      (vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
					       [2U]
					        ? vlTOPp->v__DOT__fftram__DOT__sram_or_buf
					       [2U]
					        : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [3U]
						    ? 
						   vlTOPp->v__DOT__fftram__DOT__sram_or_buf
						   [3U]
						    : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_cos)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(
								     (vlTOPp->v__DOT__BFLY0_in2_data 
								      >> 0x20U))))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x37U)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_sin)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(vlTOPp->v__DOT__BFLY0_in2_data)))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x17U)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_sin)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(
								     (vlTOPp->v__DOT__BFLY0_in2_data 
								      >> 0x20U))))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x37U)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_cos)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(vlTOPp->v__DOT__BFLY0_in2_data)))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x17U)))));
}

void Vtop_fft::_settle__TOP__31(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__31\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_cos)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(
								     (vlTOPp->v__DOT__BFLY0_in2_data 
								      >> 0x20U))))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x37U)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_sin)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(vlTOPp->v__DOT__BFLY0_in2_data)))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x17U)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_sin)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(
								     (vlTOPp->v__DOT__BFLY0_in2_data 
								      >> 0x20U))))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x37U)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
	= (VL_ULL(0xffffffffffff) & ((VL_ULL(0x800000) 
				      | (QData)((IData)(
							(0x7fffffU 
							 & vlTOPp->v__DOT__BFLY0_twiddle_cos)))) 
				     * (VL_ULL(0x800000) 
					| (QData)((IData)(
							  (0x7fffffU 
							   & (IData)(vlTOPp->v__DOT__BFLY0_in2_data)))))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be 
	= (0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			       >> 0x17U)) + (0xffU 
					     & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in2_data 
							>> 0x17U)))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__32(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__32\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
    vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm 
	= (0x1ffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
				    >> 0x2fU))) ? ((IData)(1U) 
						   + 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU)))
		      : ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
			 - (IData)(0x7fU))));
    vlTOPp->v__DOT__BFLY0__DOT__t1a = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_cos)
				        ? 0U : ((0U 
						 == (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x20U)))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_cos) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x3fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__t1b = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_sin)
				        ? 0U : ((0U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_in2_data))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_sin) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x1fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__t2a = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_sin)
				        ? 0U : ((0U 
						 == (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x20U)))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_sin) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x3fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__t2b = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_cos)
				        ? 0U : ((0U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_in2_data))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_cos) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x1fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
}

void Vtop_fft::_settle__TOP__33(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__33\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__t1a = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_cos)
				        ? 0U : ((0U 
						 == (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x20U)))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_cos) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x3fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__t1b = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_sin)
				        ? 0U : ((0U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_in2_data))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_sin) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x1fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__t2a = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_sin)
				        ? 0U : ((0U 
						 == (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x20U)))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_sin) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x3fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__t2b = ((0U == vlTOPp->v__DOT__BFLY0_twiddle_cos)
				        ? 0U : ((0U 
						 == (IData)(vlTOPp->v__DOT__BFLY0_in2_data))
						 ? 0U
						 : 
						(((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? 
						  (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))))
						   : 
						  (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be)))
						  ? 0U
						  : 
						 ((0x100U 
						   & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm))
						   ? 0xffffffffU
						   : 
						  ((0x80000000U 
						    & ((0x80000000U 
							& vlTOPp->v__DOT__BFLY0_twiddle_cos) 
						       ^ 
						       ((IData)(
								(vlTOPp->v__DOT__BFLY0_in2_data 
								 >> 0x1fU)) 
							<< 0x1fU))) 
						   | ((0x7f800000U 
						       & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm) 
							  << 0x17U)) 
						      | (0x7fffffU 
							 & ((1U 
							     & (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
									>> 0x2fU)))
							     ? (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
									>> 0x18U))
							     : (IData)(
								       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
									>> 0x17U))))))))));
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_cos) 
		     & (0U != (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
				       >> 0x20U)))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,(IData)((vlTOPp->v__DOT__BFLY0_in2_data 
			      >> 0x20U)),32,(IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x20U)),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1a,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1a);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x3fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x37U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_cos)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(
								    (vlTOPp->v__DOT__BFLY0_in2_data 
								     >> 0x20U)))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_sin) 
		     & (0U != (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1b,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1b);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x1fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x17U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_sin)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						>> 0x17U)))
		     ? (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						 >> 0x17U)))
		     ? ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						   >> 0x17U)))));
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_sin) 
		     & (0U != (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
				       >> 0x20U)))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,(IData)((vlTOPp->v__DOT__BFLY0_in2_data 
			      >> 0x20U)),32,(IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x20U)),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2a,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2a);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x3fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x37U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_sin)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(
								    (vlTOPp->v__DOT__BFLY0_in2_data 
								     >> 0x20U)))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_cos) 
		     & (0U != (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2b,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2b);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x1fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x17U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_cos)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						>> 0x17U)))
		     ? (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						 >> 0x17U)))
		     ? ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						   >> 0x17U)))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__34(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__34\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_cos) 
		     & (0U != (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
				       >> 0x20U)))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,(IData)((vlTOPp->v__DOT__BFLY0_in2_data 
			      >> 0x20U)),32,(IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x20U)),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1a,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1a);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x3fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x37U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_cos)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(
								    (vlTOPp->v__DOT__BFLY0_in2_data 
								     >> 0x20U)))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_sin) 
		     & (0U != (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1b,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t1b);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x1fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x17U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_sin)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						>> 0x17U)))
		     ? (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						 >> 0x17U)))
		     ? ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						   >> 0x17U)))));
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_sin) 
		     & (0U != (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
				       >> 0x20U)))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_sin,
		  32,(IData)((vlTOPp->v__DOT__BFLY0_in2_data 
			      >> 0x20U)),32,(IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x20U)),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2a,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2a);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x3fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x37U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x37U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_sin)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(
								    (vlTOPp->v__DOT__BFLY0_in2_data 
								     >> 0x20U)))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    // ALWAYS at ../rtl/lib//srmul.v:73
    if (VL_UNLIKELY(((0U != vlTOPp->v__DOT__BFLY0_twiddle_cos) 
		     & (0U != (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))) {
	VL_WRITEF("srmul a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,vlTOPp->v__DOT__BFLY0_twiddle_cos,
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data),
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2b,
		  32,vlTOPp->v__DOT__BFLY0__DOT__t2b);
	VL_WRITEF("srmul as=%1x bs=%1x zs=%1x\n",1,
		  (1U & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			 >> 0x1fU)),1,(1U & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in2_data 
						     >> 0x1fU))),
		  1,(1U & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			   >> 0x1fU)));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ae8=%09b be8=%09b ze8=%09b\n",
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),8,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			      >> 0x17U)));
	VL_WRITEF("srmul ae9=%09b be9=%09b ze9=%09b\n",
		  9,(0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
			      >> 0x17U)),9,(0xffU & (IData)(
							    (vlTOPp->v__DOT__BFLY0_in2_data 
							     >> 0x17U))),
		  8,(0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm)));
	VL_WRITEF("srmul   ae_plus_be=%09b\n",9,vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be);
	VL_WRITEF("srmul   ze_prenorm=%09b\n",9,(0x1ffU 
						 & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
						    - (IData)(0x7fU))));
	VL_WRITEF("srmul   too_big=%1b ze_norm=%09b\n",
		  1,(1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
				   >> 0x2fU))),9,(IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm));
	VL_WRITEF("srmul aeb=%09b beb=%09b zeb=%09b\n",
		  9,(0x1ffU & ((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
					 >> 0x17U)) 
			       - (IData)(0x7fU))),9,
		  (0x1ffU & ((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
					       >> 0x17U))) 
			     - (IData)(0x7fU))),9,(0x1ffU 
						   & ((0xffU 
						       & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm)) 
						      - (IData)(0x7fU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul am=%06x bm=%06x zm=%06x\n",
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & vlTOPp->v__DOT__BFLY0_twiddle_cos)))),
		  48,(VL_ULL(0x800000) | (QData)((IData)(
							 (0x7fffffU 
							  & (IData)(vlTOPp->v__DOT__BFLY0_in2_data))))),
		  23,(0x7fffffU & ((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
						  >> 0x2fU)))
				    ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					       >> 0x18U))
				    : (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					       >> 0x17U)))));
	VL_WRITEF("srmul ab=%012x ab[47:46]=%02b\n",
		  48,vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab,
		  2,(3U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
				   >> 0x2eU))));
	VL_WRITEF("srmul   zm_true=%06x\n",24,(0xffffffU 
					       & ((1U 
						   & (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x2fU)))
						   ? (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x18U))
						   : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x17U)))));
	VL_WRITEF("srmul   zm_hidden=%06x\n",23,(0x7fffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
								>> 0x2fU)))
						     ? (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
								>> 0x18U))
						     : (IData)(
							       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
								>> 0x17U)))));
	VL_WRITEF("srmul   zm_true[23]=%1b ab[46]=%1b\n",
		  1,(1U & (((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					   >> 0x2fU)))
			     ? (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					>> 0x18U)) : (IData)(
							     (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							      >> 0x17U))) 
			   >> 0x17U)),1,(1U & (IData)(
						      (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
						       >> 0x2eU))));
	VL_WRITEF("srmul ----\n");
	VL_WRITEF("srmul ufw=%1b ofw=%1b\n",1,((1U 
						& (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					        ? (0x7fU 
						   > 
						   (0x1ffU 
						    & ((IData)(1U) 
						       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))))
					        : (0x7fU 
						   > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))),
		  1,(1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm) 
			   >> 8U)));
	VL_WRITEF("srmul \n");
    }
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						>> 0x17U)))
		     ? (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff 
	= (0xffU & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						 >> 0x17U)))
		     ? ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						   >> 0x17U)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t1a)))) 
						  << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						  : VL_ULL(0))
					      : (VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1a))))) 
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						    >> 0x17U)) 
						> (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t1b)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t1b))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1a))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1b))))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t2a)))) 
						  << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						  : VL_ULL(0))
					      : (VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2a))))) 
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						    >> 0x17U)) 
						> (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t2b)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t2b))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2a))))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2b))))));
}

void Vtop_fft::_settle__TOP__35(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__35\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t1a)))) 
						  << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						  : VL_ULL(0))
					      : (VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1a))))) 
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						    >> 0x17U)) 
						> (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t1b)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t1b))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1a))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1b))))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t2a)))) 
						  << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						  : VL_ULL(0))
					      : (VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2a))))) 
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						    >> 0x17U)) 
						> (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t2b)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t2b))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2a))))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2b))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			    >> 0x17U)) > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
		   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						 >> 0x17U)))))
	        ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				    : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			    >> 0x17U)) > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
		   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						 >> 0x17U)))))
	        ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				    : VL_ULL(0)))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__36(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__36\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			    >> 0x17U)) > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
		   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						 >> 0x17U)))))
	        ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
				    : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			    >> 0x17U)) > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
		   & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						 >> 0x17U)))))
	        ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
				    : VL_ULL(0)))));
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t1a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1b)))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1a)))))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1b)))))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1b)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1b))))))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t2a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2b)))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2a)))))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2b)))))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2b)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2b))))))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
}

void Vtop_fft::_settle__TOP__37(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__37\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t1a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1b)))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1a)))))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1b)))))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1b)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1b))))))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t2a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2b)))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2a)))))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2b)))))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2b)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2b))))))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a) 
	    == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
			& ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						      >> 0x17U)))))
		     ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)
		     : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					 >> 0x17U)) 
			       > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t1b))
			 : (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final))))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a) 
	    == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
			& ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						      >> 0x17U)))))
		     ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)
		     : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					 >> 0x17U)) 
			       > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t2b))
			 : (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final))))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__38(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__38\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a) 
	    == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
			& ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						      >> 0x17U)))))
		     ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)
		     : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					 >> 0x17U)) 
			       > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t1b))
			 : (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final))))));
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a) 
	    == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
			& ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						      >> 0x17U)))))
		     ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)
		     : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					 >> 0x17U)) 
			       > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t2b))
			 : (((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final))))));
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t1a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1b)))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t1a 
		      >> 0x1fU)) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				       >> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub
	    : ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			  >> 0x1fU)) & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					>> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd
	        : ((1U & ((vlTOPp->v__DOT__BFLY0__DOT__t1a 
			   >> 0x1fU) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					   >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd)
		    : ((0x80000000U & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				       & vlTOPp->v__DOT__BFLY0__DOT__t1b))
		        ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub)
		        : 0xffffffffU))));
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t2a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2b)))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t2a 
		      >> 0x1fU)) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				       >> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd
	    : ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			  >> 0x1fU)) & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					>> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub
	        : ((1U & ((vlTOPp->v__DOT__BFLY0__DOT__t2a 
			   >> 0x1fU) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					   >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub)
		    : ((0x80000000U & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				       & vlTOPp->v__DOT__BFLY0__DOT__t2b))
		        ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd)
		        : 0xffffffffU))));
}

void Vtop_fft::_settle__TOP__39(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__39\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t1a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1b)))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t1a 
		      >> 0x1fU)) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1b 
				       >> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub
	    : ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t1a 
			  >> 0x1fU)) & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					>> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd
	        : ((1U & ((vlTOPp->v__DOT__BFLY0__DOT__t1a 
			   >> 0x1fU) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					   >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd)
		    : ((0x80000000U & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
				       & vlTOPp->v__DOT__BFLY0__DOT__t1b))
		        ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub)
		        : 0xffffffffU))));
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b),
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & vlTOPp->v__DOT__BFLY0__DOT__t2a)))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2b)))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t2a 
		      >> 0x1fU)) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2b 
				       >> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd
	    : ((1U & ((~ (vlTOPp->v__DOT__BFLY0__DOT__t2a 
			  >> 0x1fU)) & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					>> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub
	        : ((1U & ((vlTOPp->v__DOT__BFLY0__DOT__t2a 
			   >> 0x1fU) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					   >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub)
		    : ((0x80000000U & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
				       & vlTOPp->v__DOT__BFLY0__DOT__t2b))
		        ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd)
		        : 0xffffffffU))));
    vlTOPp->v__DOT__BFLY0__DOT__t1 = ((0x80000000U 
				       == vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw)
				       ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw);
    vlTOPp->v__DOT__BFLY0__DOT__t2 = ((0x80000000U 
				       == vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw)
				       ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw);
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__40(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__40\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__t1 = ((0x80000000U 
				       == vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw)
				       ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw);
    vlTOPp->v__DOT__BFLY0__DOT__t2 = ((0x80000000U 
				       == vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw)
				       ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw);
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU..SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,vlTOPp->v__DOT__BFLY0__DOT__t1a,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1a,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t1b,32,vlTOPp->v__DOT__BFLY0__DOT__t1b,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t1);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze 
	= (0xffU & (((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					>> 0x20U)) 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x17U)))
		     ? (0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)) 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff 
	= (0xffU & (((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					>> 0x20U)) 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x17U)))
		     ? ((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					   >> 0x20U)) 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t1 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				  >> 0x17U)) - (0xffU 
						& ((IData)(
							   (vlTOPp->v__DOT__BFLY0_in1_data 
							    >> 0x20U)) 
						   >> 0x17U)))));
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU..ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,vlTOPp->v__DOT__BFLY0__DOT__t2a,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2a,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2b,32,vlTOPp->v__DOT__BFLY0__DOT__t2b,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze 
	= (0xffU & (((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x17U)))
		     ? (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff 
	= (0xffU & (((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x17U)))
		     ? ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t2 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				  >> 0x17U)) - (0xffU 
						& ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						   >> 0x17U)))));
}

void Vtop_fft::_settle__TOP__41(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__41\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU..SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,vlTOPp->v__DOT__BFLY0__DOT__t1a,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1a,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t1b,32,vlTOPp->v__DOT__BFLY0__DOT__t1b,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t1);
    VL_WRITEF("%Nv.BFLY0.sub_t1.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze 
	= (0xffU & (((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					>> 0x20U)) 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x17U)))
		     ? (0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)) 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff 
	= (0xffU & (((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					>> 0x20U)) 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x17U)))
		     ? ((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					   >> 0x20U)) 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t1 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				  >> 0x17U)) - (0xffU 
						& ((IData)(
							   (vlTOPp->v__DOT__BFLY0_in1_data 
							    >> 0x20U)) 
						   >> 0x17U)))));
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU..ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,vlTOPp->v__DOT__BFLY0__DOT__t2a,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2a,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2b,32,vlTOPp->v__DOT__BFLY0__DOT__t2b,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2);
    VL_WRITEF("%Nv.BFLY0.add_t2.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze 
	= (0xffU & (((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
			       >> 0x17U)) > (0xffU 
					     & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x17U)))
		     ? (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				 >> 0x17U)) : (0xffU 
					       & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						  >> 0x17U))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff 
	= (0xffU & (((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
			       >> 0x17U)) >= (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x17U)))
		     ? ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				  >> 0x17U)) - (0xffU 
						& (vlTOPp->v__DOT__BFLY0__DOT__t2 
						   >> 0x17U)))
		     : ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				  >> 0x17U)) - (0xffU 
						& ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						   >> 0x17U)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & ((IData)(
							  (vlTOPp->v__DOT__BFLY0_in1_data 
							   >> 0x20U)) 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
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
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						    >> 0x17U)) 
						> (0xffU 
						   & ((IData)(
							      (vlTOPp->v__DOT__BFLY0_in1_data 
							       >> 0x20U)) 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t1))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & ((IData)(
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
								       >> 0x20U))))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))) 
						  << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						  : VL_ULL(0))
					      : (VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))) 
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						    >> 0x17U)) 
						> (0xffU 
						   & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t2))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
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
							    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2))))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__42(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__42\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & ((IData)(
							  (vlTOPp->v__DOT__BFLY0_in1_data 
							   >> 0x20U)) 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
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
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						    >> 0x17U)) 
						> (0xffU 
						   & ((IData)(
							      (vlTOPp->v__DOT__BFLY0_in1_data 
							       >> 0x20U)) 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t1))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & ((IData)(
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
								       >> 0x20U))))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
	= (0x1ffffffU & (IData)((VL_ULL(0xffffffffffff) 
				 & ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				     ? ((VL_ULL(0xffffffffffff) 
					 & ((((0xffU 
					       & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						  >> 0x17U)) 
					      > (0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						    >> 0x17U)))
					      ? ((0x2fU 
						  >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						  ? 
						 ((VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))) 
						  << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						  : VL_ULL(0))
					      : (VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))) 
					    + (((0xffU 
						 & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						    >> 0x17U)) 
						> (0xffU 
						   & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						      >> 0x17U)))
					        ? (
						   (0x2fU 
						    >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						    ? 
						   ((VL_ULL(0x800000) 
						     | (QData)((IData)(
								       (0x7fffffU 
									& vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
						    << (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
						    : VL_ULL(0))
					        : (VL_ULL(0x800000) 
						   | (QData)((IData)(
								     (0x7fffffU 
								      & vlTOPp->v__DOT__BFLY0__DOT__t2))))))) 
					>> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				     : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
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
							    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
	= (VL_ULL(0xffffffffffff) & (((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					   >> 0x20U)))) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			    >> 0x17U)) > (0xffU & ((IData)(
							   (vlTOPp->v__DOT__BFLY0_in1_data 
							    >> 0x20U)) 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
		   & ((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U)) 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x17U)))))
	        ? (0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)))
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				    : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			    >> 0x17U)) > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
		   & ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x17U)))))
	        ? (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				    : VL_ULL(0)))));
}

void Vtop_fft::_settle__TOP__43(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__43\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					   >> 0x20U)))) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			    >> 0x17U)) > (0xffU & ((IData)(
							   (vlTOPp->v__DOT__BFLY0_in1_data 
							    >> 0x20U)) 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
		   & ((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U)) 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x17U)))))
	        ? (0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)))
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
				    : VL_ULL(0)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd 
	= (((0U == (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))) 
	    | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
	       & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			    >> 0x17U)) > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						   >> 0x17U)))))
	    ? (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)
	    : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)) 
		| ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
		   & ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				>> 0x17U)) > (0xffU 
					      & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x17U)))))
	        ? (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))
	        : ((0x7f800000U & (((0x1000000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
				     ? ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
				     : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze)) 
				   << 0x17U)) | (0x7fffffU 
						 & ((0x1000000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
						     ? 
						    (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						     >> 1U)
						     : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm 
	= (0xffffffU & (IData)((VL_ULL(0xffffffffffff) 
				& ((0x2fU >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				    ? ((VL_ULL(0xffffffffffff) 
					& ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					    >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
					    : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
					       - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj))) 
				       >> (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
				    : VL_ULL(0)))));
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
								       >> 0x20U)))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1)))))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(
						     (vlTOPp->v__DOT__BFLY0_in1_data 
						      >> 0x20U)) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
								       >> 0x20U)))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1)))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(
						     (vlTOPp->v__DOT__BFLY0_in1_data 
						      >> 0x20U)) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2)))))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2)))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__44(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__44\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
								       >> 0x20U)))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1)))))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(
						     (vlTOPp->v__DOT__BFLY0_in1_data 
						      >> 0x20U)) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.ADD \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
								       >> 0x20U)))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t1)))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(
						     (vlTOPp->v__DOT__BFLY0_in1_data 
						      >> 0x20U)) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t1)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t1))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2)))))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2))))))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.ADD \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//sradd.v:92
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   am_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   bm_adj=%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
							    & vlTOPp->v__DOT__BFLY0__DOT__t2)))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   am+bm =%012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
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
					 > (0xffU & 
					    ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					     >> 0x17U)))
					 ? ((0x2fU 
					     >= (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     ? ((VL_ULL(0x800000) 
						 | (QData)((IData)(
								   (0x7fffffU 
								    & vlTOPp->v__DOT__BFLY0__DOT__t2)))) 
						<< (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff))
					     : VL_ULL(0))
					 : (VL_ULL(0x800000) 
					    | (QData)((IData)(
							      (0x7fffffU 
							       & vlTOPp->v__DOT__BFLY0__DOT__t2))))))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   ze_final=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((0x1000000U 
					   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					   ? ((IData)(1U) 
					      + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
					   : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   zm      =%06x\n",
	      vlSymsp->name(),25,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD   zm_final=%06x\n",
	      vlSymsp->name(),23,(0x7fffffU & ((0x1000000U 
						& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					        ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						   >> 1U)
					        : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.ADD \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final 
	= (0x7fffffU & ((0x17U >= (0xffU & ((0x800000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					     ? 0U : 
					    ((0x400000U 
					      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					      ? 1U : 
					     ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					       ? 2U
					       : ((0x100000U 
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
								       : 0x18U))))))))))))))))))))))))))
			 ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm 
			    << (0xffU & ((0x800000U 
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
									 : 0x18U))))))))))))))))))))))))))
			 : 0U));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final 
	= (0xffU & ((0x800000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
		     ? (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze)
		     : ((0x400000U & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
			 ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
			    - (IData)(1U)) : ((0x200000U 
					       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
					       ? ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						  - (IData)(2U))
					       : ((0x100000U 
						   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						   ? 
						  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						   - (IData)(3U))
						   : 
						  ((0x80000U 
						    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						    ? 
						   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						    - (IData)(4U))
						    : 
						   ((0x40000U 
						     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						     ? 
						    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						     - (IData)(5U))
						     : 
						    ((0x20000U 
						      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						      ? 
						     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						      - (IData)(6U))
						      : 
						     ((0x10000U 
						       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						       ? 
						      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
						       - (IData)(7U))
						       : 
						      ((0x8000U 
							& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
						        ? 
						       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							- (IData)(8U))
						        : 
						       ((0x4000U 
							 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							 ? 
							((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							 - (IData)(9U))
							 : 
							((0x2000U 
							  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							  ? 
							 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							  - (IData)(0xaU))
							  : 
							 ((0x1000U 
							   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							   ? 
							  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							   - (IData)(0xbU))
							   : 
							  ((0x800U 
							    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							    ? 
							   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							    - (IData)(0xcU))
							    : 
							   ((0x400U 
							     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							     ? 
							    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							     - (IData)(0xdU))
							     : 
							    ((0x200U 
							      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							      ? 
							     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							      - (IData)(0xeU))
							      : 
							     ((0x100U 
							       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							       ? 
							      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
							       - (IData)(0xfU))
							       : 
							      ((0x80U 
								& vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
							        ? 
							       ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								- (IData)(0x10U))
							        : 
							       ((0x40U 
								 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								 ? 
								((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								 - (IData)(0x11U))
								 : 
								((0x20U 
								  & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								  ? 
								 ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								  - (IData)(0x12U))
								  : 
								 ((0x10U 
								   & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								   ? 
								  ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								   - (IData)(0x13U))
								   : 
								  ((8U 
								    & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								    ? 
								   ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								    - (IData)(0x14U))
								    : 
								   ((4U 
								     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								     ? 
								    ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								     - (IData)(0x15U))
								     : 
								    ((2U 
								      & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								      ? 
								     ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								      - (IData)(0x16U))
								      : 
								     ((1U 
								       & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm)
								       ? 
								      ((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze) 
								       - (IData)(0x17U))
								       : 0U)))))))))))))))))))))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				    >> 0x20U))) == 
	    (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
			& ((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					      >> 0x20U)) 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						      >> 0x17U)))))
		     ? (0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					       >> 0x20U)))
		     : (((0U == (0x7fffffffU & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in1_data 
							>> 0x20U)))) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
					 >> 0x17U)) 
			       > (0xffU & ((IData)(
						   (vlTOPp->v__DOT__BFLY0_in1_data 
						    >> 0x20U)) 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t1))
			 : (((0x7fffffffU & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U))) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)) 
	    == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
			& ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						      >> 0x17U)))))
		     ? (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))
		     : (((0U == (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
					 >> 0x17U)) 
			       > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t2))
			 : (((0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final))))));
}

void Vtop_fft::_settle__TOP__45(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__45\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				    >> 0x20U))) == 
	    (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
			& ((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					      >> 0x20U)) 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						      >> 0x17U)))))
		     ? (0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					       >> 0x20U)))
		     : (((0U == (0x7fffffffU & (IData)(
						       (vlTOPp->v__DOT__BFLY0_in1_data 
							>> 0x20U)))) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
					 >> 0x17U)) 
			       > (0xffU & ((IData)(
						   (vlTOPp->v__DOT__BFLY0_in1_data 
						    >> 0x20U)) 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t1))
			 : (((0x7fffffffU & (IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U))) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final))))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub 
	= (((0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)) 
	    == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2))
	    ? 0U : (((0U == (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)) 
		     | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
			& ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
				     >> 0x17U)) > (0xffU 
						   & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						      >> 0x17U)))))
		     ? (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))
		     : (((0U == (0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))) 
			 | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
			    & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
					 >> 0x17U)) 
			       > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					   >> 0x17U)))))
			 ? (0x80000000U | (0x7fffffffU 
					   & vlTOPp->v__DOT__BFLY0__DOT__t2))
			 : (((0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)) 
			     > (0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2))
			     ? (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final) 
				 << 0x17U) | vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final)
			     : (0x80000000U | (((IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final) 
						<< 0x17U) 
					       | vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final))))));
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB  \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x3fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x3fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x3fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t1 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x3fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t1 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd)
		        : 0xffffffffU))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x3fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x3fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x3fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t1 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x3fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t1 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub)
		        : 0xffffffffU))));
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB  \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x1fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x1fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x1fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t2 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x1fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t2 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd)
		        : 0xffffffffU))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x1fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x1fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x1fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t2 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x1fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t2 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub)
		        : 0xffffffffU))));
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__46(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__46\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU.SUB  \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(
							(vlTOPp->v__DOT__BFLY0_in1_data 
							 >> 0x20U))),
	      32,(0x7fffffffU & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					 >> 0x20U))),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						   >> 0x20U)) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(
						    (vlTOPp->v__DOT__BFLY0_in1_data 
						     >> 0x20U)) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(
							       (vlTOPp->v__DOT__BFLY0_in1_data 
								>> 0x20U)))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t1)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x3fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x3fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x3fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t1 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x3fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t1 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd)
		        : 0xffffffffU))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x3fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x3fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x3fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t1 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x3fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t1 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub)
		        : 0xffffffffU))));
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU.SUB  \n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//srsub.v:212
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,(0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2),
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub,
	      32,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ae=%02x be=%02x\n",
	      vlSymsp->name(),8,(0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					  >> 0x17U)),
	      8,(0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
			  >> 0x17U)));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ae+bias=%1u be+bias=%1u\n",
	      vlSymsp->name(),8,(0xffU & ((0xffU & 
					   ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					    >> 0x17U)) 
					  - (IData)(0x7fU))),
	      8,(0xffU & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
				    >> 0x17U)) - (IData)(0x7fU))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ediff=%2u\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    am=%06x bm=%06x\n",
	      vlSymsp->name(),48,(VL_ULL(0x800000) 
				  | (QData)((IData)(
						    (0x7fffffU 
						     & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))))),
	      48,(VL_ULL(0x800000) | (QData)((IData)(
						     (0x7fffffU 
						      & vlTOPp->v__DOT__BFLY0__DOT__t2)))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    am_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    bm_adj=%012x\n",
	      vlSymsp->name(),48,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    a>b = %1b\n",
	      vlSymsp->name(),1,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				 >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    |am-bm| == %012x\n",
	      vlSymsp->name(),48,(VL_ULL(0xffffffffffff) 
				  & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				      >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				      : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
					 - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj))));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ze      =%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    ze_final=%02x\n",
	      vlSymsp->name(),8,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    zm      =%06x\n",
	      vlSymsp->name(),24,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB    zm_final=%06x\n",
	      vlSymsp->name(),23,vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final);
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU.SUB  \n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x1fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x1fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x1fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t2 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x1fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t2 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd)
		        : 0xffffffffU))));
    vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw 
	= ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			      >> 0x1fU))) & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2 
						>> 0x1fU))))
	    ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub
	    : ((1U & ((~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				  >> 0x1fU))) & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x1fU)))
	        ? vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd
	        : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				   >> 0x1fU)) & (~ 
						 (vlTOPp->v__DOT__BFLY0__DOT__t2 
						  >> 0x1fU))))
		    ? (0x80000000U ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd)
		    : ((1U & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x1fU)) & 
			      (vlTOPp->v__DOT__BFLY0__DOT__t2 
			       >> 0x1fU))) ? (0x80000000U 
					      ^ vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub)
		        : 0xffffffffU))));
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU..ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)),
	      32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			  >> 0x20U)),32,vlTOPp->v__DOT__BFLY0__DOT__t1,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1,32,
	      ((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
	        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU\n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU..SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)),
	      32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			  >> 0x20U)),32,vlTOPp->v__DOT__BFLY0__DOT__t1,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1,32,
	      ((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
	        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU\n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU..ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2,32,((0x80000000U 
						  == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
						  ? 0U
						  : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0_out1_data = (((QData)((IData)(
							((0x80000000U 
							  == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
							  ? 0U
							  : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw))) 
					<< 0x20U) | (QData)((IData)(
								    ((0x80000000U 
								      == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
								      ? 0U
								      : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw))));
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU..SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2,32,((0x80000000U 
						  == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
						  ? 0U
						  : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0_out2_data = (((QData)((IData)(
							((0x80000000U 
							  == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
							  ? 0U
							  : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw))) 
					<< 0x20U) | (QData)((IData)(
								    ((0x80000000U 
								      == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
								      ? 0U
								      : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw))));
}

void Vtop_fft::_settle__TOP__47(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_settle__TOP__47\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU..ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)),
	      32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			  >> 0x20U)),32,vlTOPp->v__DOT__BFLY0__DOT__t1,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1,32,
	      ((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
	        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.add_o1r.FPU\n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU..SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
					  >> 0x20U)),
	      32,(IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			  >> 0x20U)),32,vlTOPp->v__DOT__BFLY0__DOT__t1,
	      32,vlTOPp->v__DOT__BFLY0__DOT__t1,32,
	      ((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
	        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.sub_o2r.FPU\n",vlSymsp->name());
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU..ADD a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2,32,((0x80000000U 
						  == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
						  ? 0U
						  : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.add_o1i.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0_out1_data = (((QData)((IData)(
							((0x80000000U 
							  == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
							  ? 0U
							  : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw))) 
					<< 0x20U) | (QData)((IData)(
								    ((0x80000000U 
								      == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
								      ? 0U
								      : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw))));
    // ALWAYS at ../rtl/lib//addsub.v:79
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU\n",vlSymsp->name());
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU..SUB a=bsr'%08x (%08x) b=bsr'%08x (%08x) z=bsr'%08x (%08x)\n",
	      vlSymsp->name(),32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data),
	      32,vlTOPp->v__DOT__BFLY0__DOT__t2,32,
	      vlTOPp->v__DOT__BFLY0__DOT__t2,32,((0x80000000U 
						  == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
						  ? 0U
						  : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw),
	      32,((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
		   ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw));
    VL_WRITEF("%Nv.BFLY0.sub_o2i.FPU\n",vlSymsp->name());
    vlTOPp->v__DOT__BFLY0_out2_data = (((QData)((IData)(
							((0x80000000U 
							  == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
							  ? 0U
							  : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw))) 
					<< 0x20U) | (QData)((IData)(
								    ((0x80000000U 
								      == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
								      ? 0U
								      : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw))));
    vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [0U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [0U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [1U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [1U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [2U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [2U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [3U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [3U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    // ALWAYS at genesis_verif//butterfly_unq1.v:135
    if (VL_UNLIKELY(vlTOPp->v__DOT____Vcellinp__BFLY0__ready)) {
	VL_WRITEF("%Nv.BFLY0 t5 ------------------------\n",
		  vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: in1(r,i)= (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data));
	VL_WRITEF("%Nv.BFLY0 t5 %5u: in2(r,i)= (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data));
	VL_WRITEF("%Nv.BFLY0 t5\n",vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t1  = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t1);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t1a = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t1a);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t1b = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t1b);
	VL_WRITEF("%Nv.BFLY0 t5\n",vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t2  = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t2);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t2a = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t2a);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t2b = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t2b);
	VL_WRITEF("%Nv.BFLY0 t5\n",vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: out1(r,i)= (in1_real+t1, in1_imag+t2) = (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_out1_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_out1_data));
	VL_WRITEF("%Nv.BFLY0 t5 %5u: out2(r,i)= (in1_real-t1, in1_imag-t2) = (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_out2_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_out2_data));
	VL_WRITEF("%Nv.BFLY0 t5 ------------------------\n",
		  vlSymsp->name());
    }
}

VL_INLINE_OPT void Vtop_fft::_combo__TOP__48(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_combo__TOP__48\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [0U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [0U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [1U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [1U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [2U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [2U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data = 
	(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match
	 [3U] ? vlTOPp->v__DOT__BFLY0_out1_data : (
						   vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match
						   [3U]
						    ? vlTOPp->v__DOT__BFLY0_out2_data
						    : VL_ULL(0)));
    // ALWAYS at genesis_verif//butterfly_unq1.v:135
    if (VL_UNLIKELY(vlTOPp->v__DOT____Vcellinp__BFLY0__ready)) {
	VL_WRITEF("%Nv.BFLY0 t5 ------------------------\n",
		  vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: in1(r,i)= (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_in1_data));
	VL_WRITEF("%Nv.BFLY0 t5 %5u: in2(r,i)= (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_in2_data));
	VL_WRITEF("%Nv.BFLY0 t5\n",vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t1  = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t1);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t1a = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t1a);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t1b = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t1b);
	VL_WRITEF("%Nv.BFLY0 t5\n",vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t2  = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t2);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t2a = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t2a);
	VL_WRITEF("%Nv.BFLY0 t5 %5u: t2b = bsr'%08x\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  vlTOPp->v__DOT__BFLY0__DOT__t2b);
	VL_WRITEF("%Nv.BFLY0 t5\n",vlSymsp->name());
	VL_WRITEF("%Nv.BFLY0 t5 %5u: out1(r,i)= (in1_real+t1, in1_imag+t2) = (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_out1_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_out1_data));
	VL_WRITEF("%Nv.BFLY0 t5 %5u: out2(r,i)= (in1_real-t1, in1_imag-t2) = (bsr'%08x,bsr'%08x)\n",
		  vlSymsp->name(),64,VL_TIME_Q(),32,
		  (IData)((vlTOPp->v__DOT__BFLY0_out2_data 
			   >> 0x20U)),32,(IData)(vlTOPp->v__DOT__BFLY0_out2_data));
	VL_WRITEF("%Nv.BFLY0 t5 ------------------------\n",
		  vlSymsp->name());
    }
}

void Vtop_fft::_eval(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_eval\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__v__DOT__rst_n)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__rst_n)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__v__DOT__rst_n)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__rst_n)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz)) 
	 & (IData)(vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM000_wz))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
	vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz)) 
	 & (IData)(vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM001_wz))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz)) 
	 & (IData)(vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM002_wz))) {
	vlTOPp->_sequent__TOP__7(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz)) 
	 & (IData)(vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM003_wz))) {
	vlTOPp->_sequent__TOP__9(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x40U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__start))))) {
	vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__13(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x80U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__17(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x100U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__v__DOT__start) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__start)))) {
	vlTOPp->_sequent__TOP__20(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x200U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__21(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x400U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__22(vlSymsp);
    vlTOPp->__Vm_traceActivity = (0x800U | vlTOPp->__Vm_traceActivity);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__start))))) {
	vlTOPp->_sequent__TOP__23(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x1000U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__26(vlSymsp);
    vlTOPp->_combo__TOP__28(vlSymsp);
    vlTOPp->_combo__TOP__30(vlSymsp);
    vlTOPp->_combo__TOP__32(vlSymsp);
    vlTOPp->_combo__TOP__34(vlSymsp);
    vlTOPp->_combo__TOP__36(vlSymsp);
    vlTOPp->_combo__TOP__38(vlSymsp);
    vlTOPp->_combo__TOP__40(vlSymsp);
    vlTOPp->_combo__TOP__42(vlSymsp);
    vlTOPp->_combo__TOP__44(vlSymsp);
    vlTOPp->_combo__TOP__46(vlSymsp);
    vlTOPp->_combo__TOP__48(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__rst_n 
	= vlTOPp->__VinpClk__TOP__v__DOT__rst_n;
    vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM000_wz 
	= vlTOPp->v__DOT__fftram__DOT__SRAM000_wz;
    vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM001_wz 
	= vlTOPp->v__DOT__fftram__DOT__SRAM001_wz;
    vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM002_wz 
	= vlTOPp->v__DOT__fftram__DOT__SRAM002_wz;
    vlTOPp->__Vclklast__TOP__v__DOT__fftram__DOT__SRAM003_wz 
	= vlTOPp->v__DOT__fftram__DOT__SRAM003_wz;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__start 
	= vlTOPp->__VinpClk__TOP__v__DOT__start;
    vlTOPp->__VinpClk__TOP__v__DOT__rst_n = vlTOPp->v__DOT__rst_n;
    vlTOPp->__VinpClk__TOP__v__DOT__start = vlTOPp->v__DOT__start;
}

void Vtop_fft::_eval_initial(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_eval_initial\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_initial__TOP__8(vlSymsp);
    vlTOPp->_initial__TOP__14(vlSymsp);
    vlTOPp->_initial__TOP__24(vlSymsp);
}

void Vtop_fft::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::final\n"); );
    // Variables
    Vtop_fft__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop_fft::_eval_settle(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_eval_settle\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__12(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__16(vlSymsp);
    vlTOPp->_settle__TOP__19(vlSymsp);
    vlTOPp->_settle__TOP__25(vlSymsp);
    vlTOPp->_settle__TOP__27(vlSymsp);
    vlTOPp->_settle__TOP__29(vlSymsp);
    vlTOPp->_settle__TOP__31(vlSymsp);
    vlTOPp->_settle__TOP__33(vlSymsp);
    vlTOPp->_settle__TOP__35(vlSymsp);
    vlTOPp->_settle__TOP__37(vlSymsp);
    vlTOPp->_settle__TOP__39(vlSymsp);
    vlTOPp->_settle__TOP__41(vlSymsp);
    vlTOPp->_settle__TOP__43(vlSymsp);
    vlTOPp->_settle__TOP__45(vlSymsp);
    vlTOPp->_settle__TOP__47(vlSymsp);
}

VL_INLINE_OPT QData Vtop_fft::_change_request(Vtop_fft__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop_fft::_change_request\n"); );
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->v__DOT__rst_n ^ vlTOPp->__Vchglast__TOP__v__DOT__rst_n)
	 | (vlTOPp->v__DOT__start ^ vlTOPp->__Vchglast__TOP__v__DOT__start));
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__rst_n ^ vlTOPp->__Vchglast__TOP__v__DOT__rst_n))) VL_PRINTF("	CHANGE: genesis_verif/top_fft.v:82: v.rst_n\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__start ^ vlTOPp->__Vchglast__TOP__v__DOT__start))) VL_PRINTF("	CHANGE: genesis_verif/top_fft.v:83: v.start\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__v__DOT__rst_n = vlTOPp->v__DOT__rst_n;
    vlTOPp->__Vchglast__TOP__v__DOT__start = vlTOPp->v__DOT__start;
    return __req;
}
