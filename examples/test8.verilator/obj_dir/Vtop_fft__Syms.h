// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vtop_fft__Syms_H_
#define _Vtop_fft__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vtop_fft.h"

// SYMS CLASS
class Vtop_fft__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool	__Vm_activity;		///< Used by trace routines to determine change occurred
    bool	__Vm_didInit;
    //char	__VpadToAlign10[6];
    
    // SUBCELL STATE
    Vtop_fft*                      TOPp;
    
    // COVERAGE
    
    // SCOPE NAMES
    VerilatedScope __Vscope_v__BFLY0;
    VerilatedScope __Vscope_v__BFLY0__add_o1i__FPU;
    VerilatedScope __Vscope_v__BFLY0__add_o1i__FPU__ADD;
    VerilatedScope __Vscope_v__BFLY0__add_o1i__FPU__SUB;
    VerilatedScope __Vscope_v__BFLY0__add_o1r__FPU;
    VerilatedScope __Vscope_v__BFLY0__add_o1r__FPU__ADD;
    VerilatedScope __Vscope_v__BFLY0__add_o1r__FPU__SUB;
    VerilatedScope __Vscope_v__BFLY0__add_t2__FPU;
    VerilatedScope __Vscope_v__BFLY0__add_t2__FPU__ADD;
    VerilatedScope __Vscope_v__BFLY0__add_t2__FPU__SUB;
    VerilatedScope __Vscope_v__BFLY0__sub_o2i__FPU;
    VerilatedScope __Vscope_v__BFLY0__sub_o2i__FPU__ADD;
    VerilatedScope __Vscope_v__BFLY0__sub_o2i__FPU__SUB;
    VerilatedScope __Vscope_v__BFLY0__sub_o2r__FPU;
    VerilatedScope __Vscope_v__BFLY0__sub_o2r__FPU__ADD;
    VerilatedScope __Vscope_v__BFLY0__sub_o2r__FPU__SUB;
    VerilatedScope __Vscope_v__BFLY0__sub_t1__FPU;
    VerilatedScope __Vscope_v__BFLY0__sub_t1__FPU__ADD;
    VerilatedScope __Vscope_v__BFLY0__sub_t1__FPU__SUB;
    VerilatedScope __Vscope_v__fftram__SRAM000;
    VerilatedScope __Vscope_v__fftram__SRAM001;
    VerilatedScope __Vscope_v__fftram__SRAM002;
    VerilatedScope __Vscope_v__fftram__SRAM003;
    
    // CREATORS
    Vtop_fft__Syms(Vtop_fft* topp, const char* namep);
    ~Vtop_fft__Syms() {};
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r;}
    
} VL_ATTR_ALIGNED(64);

#endif  /*guard*/
