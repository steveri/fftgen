// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_fft__Syms.h"


//======================

void Vtop_fft::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop_fft* t=(Vtop_fft*)userthis;
    Vtop_fft__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vtop_fft::traceChgThis(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 4U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 6U))))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 7U))))) {
	    vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 7U)) | (vlTOPp->__Vm_traceActivity 
					      >> 0xbU))))) {
	    vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 8U))))) {
	    vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 8U)) | (vlTOPp->__Vm_traceActivity 
					      >> 9U))))) {
	    vlTOPp->traceChgThis__11(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 9U)) | (vlTOPp->__Vm_traceActivity 
					      >> 0xaU))))) {
	    vlTOPp->traceChgThis__12(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 0xaU))))) {
	    vlTOPp->traceChgThis__13(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 0xbU))))) {
	    vlTOPp->traceChgThis__14(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 0xcU))))) {
	    vlTOPp->traceChgThis__15(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__16(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__17(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x80U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__18(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				>> 7U) | (vlTOPp->__Vm_traceActivity 
					  >> 9U))))) {
	    vlTOPp->traceChgThis__19(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x100U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__20(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__21(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop_fft::traceChgThis__2(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[0]),4);
	vcdp->chgBus  (c+2,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[1]),4);
	vcdp->chgBus  (c+3,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[2]),4);
	vcdp->chgBus  (c+4,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[3]),4);
	vcdp->chgBus  (c+5,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[4]),4);
	vcdp->chgBus  (c+6,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[5]),4);
	vcdp->chgBus  (c+7,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[6]),4);
	vcdp->chgBus  (c+8,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[7]),4);
	vcdp->chgBus  (c+9,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[8]),4);
	vcdp->chgBus  (c+10,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[9]),4);
	vcdp->chgBus  (c+11,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[10]),4);
	vcdp->chgBus  (c+12,(vlTOPp->v__DOT__fftctl__DOT__precomputed_suppress_wz[11]),4);
	vcdp->chgBus  (c+13,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[0]),4);
	vcdp->chgBus  (c+14,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[1]),4);
	vcdp->chgBus  (c+15,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[2]),4);
	vcdp->chgBus  (c+16,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[3]),4);
	vcdp->chgBus  (c+17,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[4]),4);
	vcdp->chgBus  (c+18,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[5]),4);
	vcdp->chgBus  (c+19,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[6]),4);
	vcdp->chgBus  (c+20,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[7]),4);
	vcdp->chgBus  (c+21,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[8]),4);
	vcdp->chgBus  (c+22,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[9]),4);
	vcdp->chgBus  (c+23,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[10]),4);
	vcdp->chgBus  (c+24,(vlTOPp->v__DOT__fftctl__DOT__precomputed_bypass_read[11]),4);
	vcdp->chgBus  (c+25,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[0]),32);
	vcdp->chgBus  (c+26,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[1]),32);
	vcdp->chgBus  (c+27,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[2]),32);
	vcdp->chgBus  (c+28,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[3]),32);
	vcdp->chgBus  (c+29,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[4]),32);
	vcdp->chgBus  (c+30,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[5]),32);
	vcdp->chgBus  (c+31,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[6]),32);
	vcdp->chgBus  (c+32,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[7]),32);
	vcdp->chgBus  (c+33,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[8]),32);
	vcdp->chgBus  (c+34,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[9]),32);
	vcdp->chgBus  (c+35,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[10]),32);
	vcdp->chgBus  (c+36,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_cos[11]),32);
	vcdp->chgBus  (c+37,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[0]),32);
	vcdp->chgBus  (c+38,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[1]),32);
	vcdp->chgBus  (c+39,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[2]),32);
	vcdp->chgBus  (c+40,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[3]),32);
	vcdp->chgBus  (c+41,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[4]),32);
	vcdp->chgBus  (c+42,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[5]),32);
	vcdp->chgBus  (c+43,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[6]),32);
	vcdp->chgBus  (c+44,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[7]),32);
	vcdp->chgBus  (c+45,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[8]),32);
	vcdp->chgBus  (c+46,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[9]),32);
	vcdp->chgBus  (c+47,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[10]),32);
	vcdp->chgBus  (c+48,(vlTOPp->v__DOT__twiddle__DOT__BFLY0_twiddle_mem_sin[11]),32);
    }
}

void Vtop_fft::traceChgThis__3(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+49,(vlTOPp->v__DOT__start));
	vcdp->chgBus  (c+50,(vlTOPp->v__DOT__fftram__DOT__cycle_num),4);
	vcdp->chgBit  (c+51,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[0]));
	vcdp->chgBit  (c+52,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[1]));
	vcdp->chgBit  (c+53,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[2]));
	vcdp->chgBit  (c+54,(vlTOPp->v__DOT__fftram__DOT__bypass_valid[3]));
	vcdp->chgBus  (c+55,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[0]),1);
	vcdp->chgBus  (c+56,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[1]),1);
	vcdp->chgBus  (c+57,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[2]),1);
	vcdp->chgBus  (c+58,(vlTOPp->v__DOT__fftram__DOT__bypassed_rnum[3]),1);
	vcdp->chgQuad (c+59,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[0]),64);
	vcdp->chgQuad (c+61,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[1]),64);
	vcdp->chgQuad (c+63,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[2]),64);
	vcdp->chgQuad (c+65,(vlTOPp->v__DOT__fftram__DOT__bypassed_data[3]),64);
    }
}

void Vtop_fft::traceChgThis__4(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+67,(vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[0]),64);
	vcdp->chgQuad (c+69,(vlTOPp->v__DOT__fftram__DOT__SRAM000__DOT__mem[1]),64);
    }
}

void Vtop_fft::traceChgThis__5(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+71,(vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[0]),64);
	vcdp->chgQuad (c+73,(vlTOPp->v__DOT__fftram__DOT__SRAM001__DOT__mem[1]),64);
    }
}

void Vtop_fft::traceChgThis__6(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+75,(vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[0]),64);
	vcdp->chgQuad (c+77,(vlTOPp->v__DOT__fftram__DOT__SRAM002__DOT__mem[1]),64);
    }
}

void Vtop_fft::traceChgThis__7(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+79,(vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[0]),64);
	vcdp->chgQuad (c+81,(vlTOPp->v__DOT__fftram__DOT__SRAM003__DOT__mem[1]),64);
    }
}

void Vtop_fft::traceChgThis__8(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+86,((VL_ULL(0x800000) | (QData)((IData)(
								 (0x7fffffU 
								  & vlTOPp->v__DOT__BFLY0_twiddle_cos))))),48);
	vcdp->chgBus  (c+88,((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_cos 
				       >> 0x17U))),9);
	vcdp->chgQuad (c+89,((VL_ULL(0x800000) | (QData)((IData)(
								 (0x7fffffU 
								  & vlTOPp->v__DOT__BFLY0_twiddle_sin))))),48);
	vcdp->chgBus  (c+91,((0xffU & (vlTOPp->v__DOT__BFLY0_twiddle_sin 
				       >> 0x17U))),9);
	vcdp->chgBus  (c+85,(vlTOPp->v__DOT__BFLY0_op2_bnum),2);
	vcdp->chgBit  (c+92,(vlTOPp->v__DOT__fftram__DOT__bypass_time));
	vcdp->chgBit  (c+93,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[0]));
	vcdp->chgBit  (c+94,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[1]));
	vcdp->chgBit  (c+95,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[2]));
	vcdp->chgBit  (c+96,(vlTOPp->v__DOT__fftctl__DOT__bufnum_o[3]));
	vcdp->chgBus  (c+97,(vlTOPp->v__DOT__fftctl__DOT__stageno),3);
	vcdp->chgBus  (c+83,(vlTOPp->v__DOT__BFLY0_twiddle_cos),32);
	vcdp->chgBus  (c+84,(vlTOPp->v__DOT__BFLY0_twiddle_sin),32);
    }
}

void Vtop_fft::traceChgThis__9(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+98,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_cos 
				     >> 0x1fU) ^ (IData)(
							 (vlTOPp->v__DOT__BFLY0_in2_data 
							  >> 0x3fU))))));
	vcdp->chgBit  (c+99,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_sin 
				     >> 0x1fU) ^ (IData)(
							 (vlTOPp->v__DOT__BFLY0_in2_data 
							  >> 0x1fU))))));
	vcdp->chgBit  (c+100,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_sin 
				      >> 0x1fU) ^ (IData)(
							  (vlTOPp->v__DOT__BFLY0_in2_data 
							   >> 0x3fU))))));
	vcdp->chgBit  (c+101,((1U & ((vlTOPp->v__DOT__BFLY0_twiddle_cos 
				      >> 0x1fU) ^ (IData)(
							  (vlTOPp->v__DOT__BFLY0_in2_data 
							   >> 0x1fU))))));
    }
}

void Vtop_fft::traceChgThis__10(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+102,(vlTOPp->v__DOT__BFLY0_op1_bnum),2);
	vcdp->chgBit  (c+103,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[0]));
	vcdp->chgBit  (c+104,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[1]));
	vcdp->chgBit  (c+105,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[2]));
	vcdp->chgBit  (c+106,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op2_match[3]));
    }
}

void Vtop_fft::traceChgThis__11(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+107,(vlTOPp->v__DOT__fftctl__DOT__STARTED));
    }
}

void Vtop_fft::traceChgThis__12(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+108,((1U & (~ (IData)(vlTOPp->v__DOT__fftctl__DOT__LAST)))));
	vcdp->chgBit  (c+109,(vlTOPp->v__DOT__fftctl__DOT__LAST));
    }
}

void Vtop_fft::traceChgThis__13(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+110,(vlTOPp->v__DOT__rst_n));
	vcdp->chgBus  (c+111,(vlTOPp->v__DOT__fftram__DOT__SRAM000_ix),1);
	vcdp->chgBus  (c+112,(vlTOPp->v__DOT__fftram__DOT__SRAM001_ix),1);
	vcdp->chgBus  (c+113,(vlTOPp->v__DOT__fftram__DOT__SRAM002_ix),1);
	vcdp->chgBus  (c+114,(vlTOPp->v__DOT__fftram__DOT__SRAM003_ix),1);
	vcdp->chgBit  (c+115,(vlTOPp->v__DOT__fftram__DOT__SRAM000_active));
	vcdp->chgBit  (c+116,(vlTOPp->v__DOT__fftram__DOT__SRAM001_active));
	vcdp->chgBit  (c+117,(vlTOPp->v__DOT__fftram__DOT__SRAM002_active));
	vcdp->chgBit  (c+118,(vlTOPp->v__DOT__fftram__DOT__SRAM003_active));
	vcdp->chgBit  (c+119,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[0]));
	vcdp->chgBit  (c+120,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[1]));
	vcdp->chgBit  (c+121,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[2]));
	vcdp->chgBit  (c+122,(vlTOPp->v__DOT__fftram__DOT__BFLY0_op1_match[3]));
    }
}

void Vtop_fft::traceChgThis__14(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+131,(vlTOPp->v__DOT____Vcellinp__BFLY0__ready));
	vcdp->chgBus  (c+140,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zadd),32);
	vcdp->chgBus  (c+141,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zsub),32);
	vcdp->chgBit  (c+142,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					>> 0x1fU)))));
	vcdp->chgBit  (c+143,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					>> 0x1fU)))));
	vcdp->chgBus  (c+144,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__zraw),32);
	vcdp->chgBit  (c+145,(0U));
	vcdp->chgBit  (c+146,(0U));
	vcdp->chgBus  (c+147,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					>> 0x17U))),8);
	vcdp->chgBus  (c+148,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					>> 0x17U))),8);
	vcdp->chgQuad (c+149,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0__DOT__t1a))))),48);
	vcdp->chgQuad (c+151,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0__DOT__t1b))))),48);
	vcdp->chgBus  (c+153,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff),8);
	vcdp->chgBit  (c+154,(((0U == (0x7fffffffU 
				       & vlTOPp->v__DOT__BFLY0__DOT__t1a)) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
				  & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
						 >> 0x17U)))))));
	vcdp->chgBit  (c+155,(((0U == (0x7fffffffU 
				       & vlTOPp->v__DOT__BFLY0__DOT__t1b)) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ediff)) 
				  & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1a 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1b 
						 >> 0x17U)))))));
	vcdp->chgQuad (c+156,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgQuad (c+158,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgBus  (c+160,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze),8);
	vcdp->chgQuad (c+161,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgBus  (c+163,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->chgBus  (c+164,((0x7fffffU & ((0x1000000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					     ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm 
						>> 1U)
					     : vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->chgBus  (c+165,((0xffU & ((0x1000000U 
					 & vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__ADD__DOT__zm)
					 ? ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze))
					 : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze)))),8);
	vcdp->chgBus  (c+138,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1a)),32);
	vcdp->chgBus  (c+139,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1b)),32);
	vcdp->chgQuad (c+166,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->chgQuad (c+168,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->chgQuad (c+170,((VL_ULL(0xffffffffffff) 
			       & ((vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				   >= vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   ? (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   : (vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__bm_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->chgBus  (c+172,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->chgBus  (c+173,((0xffU & ((0x800000U 
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
	vcdp->chgBus  (c+174,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->chgBus  (c+175,(vlTOPp->v__DOT__BFLY0__DOT__sub_t1__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->chgBus  (c+133,(vlTOPp->v__DOT__BFLY0__DOT__t1a),32);
	vcdp->chgQuad (c+177,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & (IData)(
									     (vlTOPp->v__DOT__BFLY0_in2_data 
									      >> 0x20U))))))),48);
	vcdp->chgQuad (c+179,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab),48);
	vcdp->chgBit  (c+181,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					     >> 0x2fU)))));
	vcdp->chgBus  (c+182,((0xffffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							>> 0x17U))))),24);
	vcdp->chgBus  (c+183,((0x7fffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
							>> 0x17U))))),23);
	vcdp->chgBus  (c+184,((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
						>> 0x37U)))),9);
	vcdp->chgBus  (c+185,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->chgBus  (c+186,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be) 
					 - (IData)(0x7fU)))),9);
	vcdp->chgBus  (c+187,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm),9);
	vcdp->chgBus  (c+188,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm))),8);
	vcdp->chgBit  (c+189,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ab 
					      >> 0x2fU)))
			        ? (0x7fU > (0x1ffU 
					    & ((IData)(1U) 
					       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be))))
			        : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->chgBit  (c+190,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1a__DOT__MUL__DOT__ze_norm) 
				     >> 8U))));
	vcdp->chgBus  (c+134,(vlTOPp->v__DOT__BFLY0__DOT__t1b),32);
	vcdp->chgQuad (c+192,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & (IData)(vlTOPp->v__DOT__BFLY0_in2_data)))))),48);
	vcdp->chgQuad (c+194,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab),48);
	vcdp->chgBit  (c+196,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					     >> 0x2fU)))));
	vcdp->chgBus  (c+197,((0xffffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							>> 0x17U))))),24);
	vcdp->chgBus  (c+198,((0x7fffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
							>> 0x17U))))),23);
	vcdp->chgBus  (c+199,((0xffU & (IData)((vlTOPp->v__DOT__BFLY0_in2_data 
						>> 0x17U)))),9);
	vcdp->chgBus  (c+200,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->chgBus  (c+201,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be) 
					 - (IData)(0x7fU)))),9);
	vcdp->chgBus  (c+202,(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm),9);
	vcdp->chgBus  (c+203,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm))),8);
	vcdp->chgBit  (c+204,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ab 
					      >> 0x2fU)))
			        ? (0x7fU > (0x1ffU 
					    & ((IData)(1U) 
					       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be))))
			        : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->chgBit  (c+205,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t1b__DOT__MUL__DOT__ze_norm) 
				     >> 8U))));
	vcdp->chgBus  (c+208,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zadd),32);
	vcdp->chgBus  (c+209,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zsub),32);
	vcdp->chgBit  (c+210,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					>> 0x1fU)))));
	vcdp->chgBit  (c+211,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					>> 0x1fU)))));
	vcdp->chgBus  (c+212,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__zraw),32);
	vcdp->chgBit  (c+213,(0U));
	vcdp->chgBit  (c+214,(0U));
	vcdp->chgBus  (c+215,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					>> 0x17U))),8);
	vcdp->chgBus  (c+216,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					>> 0x17U))),8);
	vcdp->chgQuad (c+217,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0__DOT__t2a))))),48);
	vcdp->chgQuad (c+219,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0__DOT__t2b))))),48);
	vcdp->chgBus  (c+221,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff),8);
	vcdp->chgBit  (c+222,(((0U == (0x7fffffffU 
				       & vlTOPp->v__DOT__BFLY0__DOT__t2a)) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
				  & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
						 >> 0x17U)))))));
	vcdp->chgBit  (c+223,(((0U == (0x7fffffffU 
				       & vlTOPp->v__DOT__BFLY0__DOT__t2b)) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ediff)) 
				  & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2a 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2b 
						 >> 0x17U)))))));
	vcdp->chgQuad (c+224,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgQuad (c+226,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgBus  (c+228,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze),8);
	vcdp->chgQuad (c+229,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgBus  (c+231,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->chgBus  (c+232,((0x7fffffU & ((0x1000000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					     ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm 
						>> 1U)
					     : vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->chgBus  (c+233,((0xffU & ((0x1000000U 
					 & vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__zm)
					 ? ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze))
					 : (IData)(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__ADD__DOT__ze)))),8);
	vcdp->chgBus  (c+206,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2a)),32);
	vcdp->chgBus  (c+207,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2b)),32);
	vcdp->chgQuad (c+234,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->chgQuad (c+236,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->chgQuad (c+238,((VL_ULL(0xffffffffffff) 
			       & ((vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				   >= vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   ? (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   : (vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__bm_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->chgBus  (c+240,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->chgBus  (c+241,((0xffU & ((0x800000U 
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
	vcdp->chgBus  (c+242,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->chgBus  (c+243,(vlTOPp->v__DOT__BFLY0__DOT__add_t2__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->chgBus  (c+176,((IData)((vlTOPp->v__DOT__BFLY0_in2_data 
				       >> 0x20U))),32);
	vcdp->chgBus  (c+136,(vlTOPp->v__DOT__BFLY0__DOT__t2a),32);
	vcdp->chgQuad (c+244,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab),48);
	vcdp->chgBit  (c+246,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					     >> 0x2fU)))));
	vcdp->chgBus  (c+247,((0xffffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							>> 0x17U))))),24);
	vcdp->chgBus  (c+248,((0x7fffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
							>> 0x17U))))),23);
	vcdp->chgBus  (c+249,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->chgBus  (c+250,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be) 
					 - (IData)(0x7fU)))),9);
	vcdp->chgBus  (c+251,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm),9);
	vcdp->chgBus  (c+252,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm))),8);
	vcdp->chgBit  (c+253,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ab 
					      >> 0x2fU)))
			        ? (0x7fU > (0x1ffU 
					    & ((IData)(1U) 
					       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be))))
			        : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->chgBit  (c+254,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2a__DOT__MUL__DOT__ze_norm) 
				     >> 8U))));
	vcdp->chgBus  (c+191,((IData)(vlTOPp->v__DOT__BFLY0_in2_data)),32);
	vcdp->chgBus  (c+137,(vlTOPp->v__DOT__BFLY0__DOT__t2b),32);
	vcdp->chgQuad (c+255,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab),48);
	vcdp->chgBit  (c+257,((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					     >> 0x2fU)))));
	vcdp->chgBus  (c+258,((0xffffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							>> 0x17U))))),24);
	vcdp->chgBus  (c+259,((0x7fffffU & ((1U & (IData)(
							  (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							   >> 0x2fU)))
					     ? (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							>> 0x18U))
					     : (IData)(
						       (vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
							>> 0x17U))))),23);
	vcdp->chgBus  (c+260,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be),9);
	vcdp->chgBus  (c+261,((0x1ffU & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be) 
					 - (IData)(0x7fU)))),9);
	vcdp->chgBus  (c+262,(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm),9);
	vcdp->chgBus  (c+263,((0xffU & (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm))),8);
	vcdp->chgBit  (c+264,(((1U & (IData)((vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ab 
					      >> 0x2fU)))
			        ? (0x7fU > (0x1ffU 
					    & ((IData)(1U) 
					       + (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be))))
			        : (0x7fU > (IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ae_plus_be)))));
	vcdp->chgBit  (c+265,((1U & ((IData)(vlTOPp->v__DOT__BFLY0__DOT__mult_t2b__DOT__MUL__DOT__ze_norm) 
				     >> 8U))));
	vcdp->chgBus  (c+267,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)
			        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw)),32);
	vcdp->chgBit  (c+272,((1U & (~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						>> 0x3fU))))));
	vcdp->chgBit  (c+273,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t1 
					>> 0x1fU)))));
	vcdp->chgBus  (c+274,(vlTOPp->v__DOT__BFLY0__DOT__add_o1r__DOT__FPU__DOT__zraw),32);
	vcdp->chgQuad (c+286,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgQuad (c+288,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgQuad (c+291,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgBus  (c+293,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->chgBus  (c+294,((0x7fffffU & ((0x1000000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					     ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm 
						>> 1U)
					     : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->chgBus  (c+295,((0xffU & ((0x1000000U 
					 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__ADD__DOT__zm)
					 ? ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze))
					 : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze)))),8);
	vcdp->chgQuad (c+296,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->chgQuad (c+298,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->chgQuad (c+300,((VL_ULL(0xffffffffffff) 
			       & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				   >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__bm_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->chgBus  (c+302,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->chgBus  (c+303,((0xffU & ((0x800000U 
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
	vcdp->chgBus  (c+304,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->chgBus  (c+305,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->chgBus  (c+307,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)
			        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw)),32);
	vcdp->chgBit  (c+312,((1U & (~ (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						>> 0x1fU))))));
	vcdp->chgBit  (c+313,((1U & (~ (vlTOPp->v__DOT__BFLY0__DOT__t2 
					>> 0x1fU)))));
	vcdp->chgBus  (c+314,(vlTOPp->v__DOT__BFLY0__DOT__add_o1i__DOT__FPU__DOT__zraw),32);
	vcdp->chgQuad (c+326,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgQuad (c+328,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgQuad (c+331,((VL_ULL(0xffffffffffff) 
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
	vcdp->chgBus  (c+333,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm),25);
	vcdp->chgBus  (c+334,((0x7fffffU & ((0x1000000U 
					     & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					     ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm 
						>> 1U)
					     : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm))),23);
	vcdp->chgBus  (c+335,((0xffU & ((0x1000000U 
					 & vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__ADD__DOT__zm)
					 ? ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze))
					 : (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze)))),8);
	vcdp->chgQuad (c+336,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj),48);
	vcdp->chgQuad (c+338,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj),48);
	vcdp->chgQuad (c+340,((VL_ULL(0xffffffffffff) 
			       & ((vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				   >= vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   ? (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj)
				   : (vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__bm_adj 
				      - vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__am_adj)))),48);
	vcdp->chgBus  (c+342,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm),24);
	vcdp->chgBus  (c+343,((0xffU & ((0x800000U 
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
	vcdp->chgBus  (c+344,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__zm_final),23);
	vcdp->chgBus  (c+345,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze_final),8);
	vcdp->chgBus  (c+346,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)
			        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw)),32);
	vcdp->chgBus  (c+266,((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
				       >> 0x20U))),32);
	vcdp->chgBus  (c+132,(vlTOPp->v__DOT__BFLY0__DOT__t1),32);
	vcdp->chgBus  (c+347,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zraw),32);
	vcdp->chgBus  (c+270,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zadd),32);
	vcdp->chgBus  (c+268,((0x7fffffffU & (IData)(
						     (vlTOPp->v__DOT__BFLY0_in1_data 
						      >> 0x20U)))),32);
	vcdp->chgBus  (c+269,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t1)),32);
	vcdp->chgBus  (c+271,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__zsub),32);
	vcdp->chgBit  (c+275,(0U));
	vcdp->chgBit  (c+276,(0U));
	vcdp->chgBus  (c+277,((0xffU & ((IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						 >> 0x20U)) 
					>> 0x17U))),8);
	vcdp->chgBus  (c+278,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
					>> 0x17U))),8);
	vcdp->chgQuad (c+279,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & (IData)(
									     (vlTOPp->v__DOT__BFLY0_in1_data 
									      >> 0x20U))))))),48);
	vcdp->chgQuad (c+281,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0__DOT__t1))))),48);
	vcdp->chgBus  (c+283,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff),8);
	vcdp->chgBit  (c+284,(((0U == (0x7fffffffU 
				       & (IData)((vlTOPp->v__DOT__BFLY0_in1_data 
						  >> 0x20U)))) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
				  & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
					       >> 0x17U)) 
				     > (0xffU & ((IData)(
							 (vlTOPp->v__DOT__BFLY0_in1_data 
							  >> 0x20U)) 
						 >> 0x17U)))))));
	vcdp->chgBit  (c+285,(((0U == (0x7fffffffU 
				       & vlTOPp->v__DOT__BFLY0__DOT__t1)) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ediff)) 
				  & ((0xffU & ((IData)(
						       (vlTOPp->v__DOT__BFLY0_in1_data 
							>> 0x20U)) 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t1 
						 >> 0x17U)))))));
	vcdp->chgBus  (c+290,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2r__DOT__FPU__DOT__SUB__DOT__ze),8);
	vcdp->chgBus  (c+348,(((0x80000000U == vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)
			        ? 0U : vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw)),32);
	vcdp->chgBus  (c+306,((IData)(vlTOPp->v__DOT__BFLY0_in1_data)),32);
	vcdp->chgBus  (c+135,(vlTOPp->v__DOT__BFLY0__DOT__t2),32);
	vcdp->chgBus  (c+349,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zraw),32);
	vcdp->chgBus  (c+310,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zadd),32);
	vcdp->chgBus  (c+308,((0x7fffffffU & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))),32);
	vcdp->chgBus  (c+309,((0x7fffffffU & vlTOPp->v__DOT__BFLY0__DOT__t2)),32);
	vcdp->chgBus  (c+311,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__zsub),32);
	vcdp->chgBit  (c+315,(0U));
	vcdp->chgBit  (c+316,(0U));
	vcdp->chgBus  (c+317,((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					>> 0x17U))),8);
	vcdp->chgBus  (c+318,((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
					>> 0x17U))),8);
	vcdp->chgQuad (c+319,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & (IData)(vlTOPp->v__DOT__BFLY0_in1_data)))))),48);
	vcdp->chgQuad (c+321,((VL_ULL(0x800000) | (QData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->v__DOT__BFLY0__DOT__t2))))),48);
	vcdp->chgBus  (c+323,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff),8);
	vcdp->chgBit  (c+324,(((0U == (0x7fffffffU 
				       & (IData)(vlTOPp->v__DOT__BFLY0_in1_data))) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
				  & ((0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
					       >> 0x17U)) 
				     > (0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
						 >> 0x17U)))))));
	vcdp->chgBit  (c+325,(((0U == (0x7fffffffU 
				       & vlTOPp->v__DOT__BFLY0__DOT__t2)) 
			       | ((0x16U < (IData)(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ediff)) 
				  & ((0xffU & ((IData)(vlTOPp->v__DOT__BFLY0_in1_data) 
					       >> 0x17U)) 
				     > (0xffU & (vlTOPp->v__DOT__BFLY0__DOT__t2 
						 >> 0x17U)))))));
	vcdp->chgBus  (c+330,(vlTOPp->v__DOT__BFLY0__DOT__sub_o2i__DOT__FPU__DOT__SUB__DOT__ze),8);
	vcdp->chgQuad (c+123,(vlTOPp->v__DOT__BFLY0_in1_data),64);
	vcdp->chgQuad (c+125,(vlTOPp->v__DOT__BFLY0_in2_data),64);
	vcdp->chgQuad (c+127,(vlTOPp->v__DOT__BFLY0_out1_data),64);
	vcdp->chgQuad (c+129,(vlTOPp->v__DOT__BFLY0_out2_data),64);
	vcdp->chgBit  (c+350,(vlTOPp->v__DOT____Vcellinp__fftram__fft_started));
	vcdp->chgQuad (c+351,(vlTOPp->v__DOT__fftram__DOT__SRAM000_rd_data),64);
	vcdp->chgQuad (c+353,(vlTOPp->v__DOT__fftram__DOT__SRAM000_wr_data),64);
	vcdp->chgBit  (c+355,(vlTOPp->v__DOT__fftram__DOT__SRAM000_ez));
	vcdp->chgQuad (c+356,(vlTOPp->v__DOT__fftram__DOT__SRAM001_rd_data),64);
	vcdp->chgQuad (c+358,(vlTOPp->v__DOT__fftram__DOT__SRAM001_wr_data),64);
	vcdp->chgBit  (c+360,(vlTOPp->v__DOT__fftram__DOT__SRAM001_ez));
	vcdp->chgQuad (c+361,(vlTOPp->v__DOT__fftram__DOT__SRAM002_rd_data),64);
	vcdp->chgQuad (c+363,(vlTOPp->v__DOT__fftram__DOT__SRAM002_wr_data),64);
	vcdp->chgBit  (c+365,(vlTOPp->v__DOT__fftram__DOT__SRAM002_ez));
	vcdp->chgQuad (c+366,(vlTOPp->v__DOT__fftram__DOT__SRAM003_rd_data),64);
	vcdp->chgQuad (c+368,(vlTOPp->v__DOT__fftram__DOT__SRAM003_wr_data),64);
	vcdp->chgBit  (c+370,(vlTOPp->v__DOT__fftram__DOT__SRAM003_ez));
	vcdp->chgQuad (c+371,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[0]),64);
	vcdp->chgQuad (c+373,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[1]),64);
	vcdp->chgQuad (c+375,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[2]),64);
	vcdp->chgQuad (c+377,(vlTOPp->v__DOT__fftram__DOT__sram_or_buf[3]),64);
    }
}

void Vtop_fft::traceChgThis__15(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+379,(vlTOPp->v__DOT__fftctl__DOT__cycle_num),5);
	vcdp->chgBus  (c+380,(vlTOPp->v__DOT__fftctl__DOT__out2_offset),4);
    }
}

void Vtop_fft::traceChgThis__16(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+381,(vlTOPp->v__DOT__fftram__DOT__SRAM000_wz));
	vcdp->chgBit  (c+382,(vlTOPp->v__DOT__fftram__DOT__SRAM001_wz));
	vcdp->chgBit  (c+383,(vlTOPp->v__DOT__fftram__DOT__SRAM002_wz));
	vcdp->chgBit  (c+384,(vlTOPp->v__DOT__fftram__DOT__SRAM003_wz));
    }
}

void Vtop_fft::traceChgThis__17(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+385,(vlTOPp->v__DOT__cycle_counter),32);
    }
}

void Vtop_fft::traceChgThis__18(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+387,(vlTOPp->v__DOT__BFLY0_access_type),3);
	vcdp->chgBus  (c+389,(vlTOPp->v__DOT__bypass_read),4);
	vcdp->chgBit  (c+390,(vlTOPp->v__DOT__bufnum[0]));
	vcdp->chgBit  (c+391,(vlTOPp->v__DOT__bufnum[1]));
	vcdp->chgBit  (c+392,(vlTOPp->v__DOT__bufnum[2]));
	vcdp->chgBit  (c+393,(vlTOPp->v__DOT__bufnum[3]));
	vcdp->chgBus  (c+394,((1U & ((IData)(vlTOPp->v__DOT__BFLY0_op2_ix) 
				     >> 2U))),1);
	vcdp->chgBus  (c+386,(vlTOPp->v__DOT__BFLY0_op2_ix),3);
	vcdp->chgBus  (c+388,(vlTOPp->v__DOT__fftctl_cycle_num),5);
    }
}

void Vtop_fft::traceChgThis__19(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+395,(vlTOPp->v__DOT__suppress_wz),4);
    }
}

void Vtop_fft::traceChgThis__20(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+397,((1U & ((IData)(vlTOPp->v__DOT__BFLY0_op1_ix) 
				     >> 2U))),1);
	vcdp->chgBus  (c+396,(vlTOPp->v__DOT__BFLY0_op1_ix),3);
    }
}

void Vtop_fft::traceChgThis__21(Vtop_fft__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop_fft* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+399,(vlTOPp->done));
	vcdp->chgBit  (c+398,(vlTOPp->clk));
    }
}
