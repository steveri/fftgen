// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_fft_H_
#define _Vtop_fft_H_

#include "verilated.h"
class Vtop_fft__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop_fft) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_OUT8(done,0,0);
    //char	__VpadToAlign2[2];
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__rst_n,0,0);
    VL_SIG8(v__DOT__start,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM000_wz,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM001_wz,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM002_wz,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM003_wz,0,0);
    VL_SIG8(v__DOT__BFLY0_op1_ix,2,0);
    VL_SIG8(v__DOT__BFLY0_op2_ix,2,0);
    VL_SIG8(v__DOT__BFLY0_access_type,2,0);
    VL_SIG8(v__DOT__fftctl_cycle_num,4,0);
    VL_SIG8(v__DOT__suppress_wz,3,0);
    VL_SIG8(v__DOT__bypass_read,3,0);
    VL_SIG8(v__DOT__BFLY0_op1_bnum,1,0);
    VL_SIG8(v__DOT__BFLY0_op2_bnum,1,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_t1,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_t1a,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_t1b,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_t2,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_t2a,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_t2b,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_o1r,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_o1i,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_o2r,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__status_o2i,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze,7,0);
    VL_SIG8(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final,7,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM000_ix,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM000_ez,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM001_ix,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM001_ez,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM002_ix,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM002_ez,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM003_ix,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM003_ez,0,0);
    VL_SIG8(v__DOT__fftram__DOT__cycle_num,3,0);
    VL_SIG8(v__DOT__fftram__DOT__bypass_time,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM000_active,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM001_active,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM002_active,0,0);
    VL_SIG8(v__DOT__fftram__DOT__SRAM003_active,0,0);
    VL_SIG8(v__DOT__fftctl__DOT__cycle_num,4,0);
    VL_SIG8(v__DOT__fftctl__DOT__out2_offset,3,0);
    VL_SIG8(v__DOT__fftctl__DOT__stageno,2,0);
    VL_SIG8(v__DOT__fftctl__DOT__STARTED,0,0);
    VL_SIG8(v__DOT__fftctl__DOT__LAST,0,0);
    //char	__VpadToAlign63[1];
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be,8,0);
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm,8,0);
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be,8,0);
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm,8,0);
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be,8,0);
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm,8,0);
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be,8,0);
    VL_SIG16(v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm,8,0);
    VL_SIG(v__DOT__BFLY0_twiddle_cos,31,0);
    VL_SIG(v__DOT__BFLY0_twiddle_sin,31,0);
    VL_SIG(v__DOT__cycle_counter,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__t1,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__t1a,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__t1b,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__t2,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__t2a,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__t2b,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm,24,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm,23,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final,22,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm,24,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm,23,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final,22,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm,24,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm,23,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final,22,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw,31,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm,24,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm,23,0);
    VL_SIG(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final,22,0);
    //char	__VpadToAlign220[4];
    VL_SIG64(v__DOT__BFLY0_in1_data,63,0);
    VL_SIG64(v__DOT__BFLY0_in2_data,63,0);
    VL_SIG64(v__DOT__BFLY0_out1_data,63,0);
    VL_SIG64(v__DOT__BFLY0_out2_data,63,0);
    VL_SIG64(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj,47,0);
    VL_SIG64(v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj,47,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM000_rd_data,63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM000_wr_data,63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM001_rd_data,63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM001_wr_data,63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM002_rd_data,63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM002_wr_data,63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM003_rd_data,63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM003_wr_data,63,0);
    VL_SIG8(v__DOT__bufnum[4],0,0);
    VL_SIG8(v__DOT__fftram__DOT__bypass_valid[4],0,0);
    VL_SIG8(v__DOT__fftram__DOT__bypassed_rnum[4],0,0);
    //char	__VpadToAlign428[4];
    VL_SIG64(v__DOT__fftram__DOT__bypassed_data[4],63,0);
    VL_SIG64(v__DOT__fftram__DOT__sram_or_buf[4],63,0);
    VL_SIG8(v__DOT__fftram__DOT__BFLY0_op1_match[4],0,0);
    VL_SIG8(v__DOT__fftram__DOT__BFLY0_op2_match[4],0,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM000__DOT__mem[2],63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM001__DOT__mem[2],63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM002__DOT__mem[2],63,0);
    VL_SIG64(v__DOT__fftram__DOT__SRAM003__DOT__mem[2],63,0);
    VL_SIG8(v__DOT__fftctl__DOT__bufnum_o[4],0,0);
    //char	__VpadToAlign572[4];
    VL_SIG8(v__DOT__fftctl__DOT__BFLY0_access_type[12],2,0);
    //char	__VpadToAlign588[4];
    VL_SIG8(v__DOT__fftctl__DOT__precomputed_suppress_wz[12],3,0);
    //char	__VpadToAlign604[4];
    VL_SIG8(v__DOT__fftctl__DOT__precomputed_bypass_read[12],3,0);
    //char	__VpadToAlign620[4];
    VL_SIG(v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[12],31,0);
    VL_SIG(v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[12],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT____Vcellinp__BFLY0__ready,0,0);
    VL_SIG8(v__DOT____Vcellinp__fftram__fft_started,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__bufnum__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__bufnum__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__bufnum__v2,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__bufnum__v3,0,0);
    VL_SIG8(__Vdly__v__DOT__BFLY0_op1_ix,2,0);
    VL_SIG8(__Vdly__v__DOT__BFLY0_op2_ix,2,0);
    VL_SIG8(__Vdly__v__DOT__fftctl__DOT__stageno,2,0);
    VL_SIG8(__Vdly__v__DOT__fftctl__DOT__out2_offset,3,0);
    VL_SIG8(__Vdly__v__DOT__fftctl_cycle_num,4,0);
    VL_SIG8(__Vdly__v__DOT__fftctl__DOT__cycle_num,4,0);
    VL_SIG8(__Vdly__v__DOT__rst_n,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__rst_n,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__start,0,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__rst_n,0,0);
    VL_SIG8(__Vclklast__TOP__v__DOT__fftram__DOT__SRAM000_wz,0,0);
    VL_SIG8(__Vclklast__TOP__v__DOT__fftram__DOT__SRAM001_wz,0,0);
    VL_SIG8(__Vclklast__TOP__v__DOT__fftram__DOT__SRAM002_wz,0,0);
    VL_SIG8(__Vclklast__TOP__v__DOT__fftram__DOT__SRAM003_wz,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__start,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__rst_n,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__start,0,0);
    VL_SIG(__Vdly__v__DOT__cycle_counter,31,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop_fft__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vtop_fft& operator= (const Vtop_fft&);	///< Copying not allowed
    Vtop_fft(const Vtop_fft&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vtop_fft(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop_fft();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop_fft__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop_fft__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vtop_fft__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__22(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__26(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__28(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__30(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__32(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__34(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__36(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__38(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__40(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__42(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__44(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__46(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_combo__TOP__48(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_eval(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_initial__TOP__14(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_initial__TOP__24(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_initial__TOP__8(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__11(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__13(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__17(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__20(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__21(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__23(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__5(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__6(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__7(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__9(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__12(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__16(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__19(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__25(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__27(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__29(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__31(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__33(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__35(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__37(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__39(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__41(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__43(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__45(Vtop_fft__Syms* __restrict vlSymsp);
    static void	_settle__TOP__47(Vtop_fft__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__10(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__11(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__12(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__13(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__14(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__15(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__16(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__17(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__18(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__19(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__20(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__21(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__6(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__7(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__8(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__9(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
