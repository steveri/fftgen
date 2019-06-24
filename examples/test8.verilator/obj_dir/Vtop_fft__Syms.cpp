// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop_fft__Syms.h"
#include "Vtop_fft.h"

// FUNCTIONS
Vtop_fft__Syms::Vtop_fft__Syms(Vtop_fft* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_activity(false)
	, __Vm_didInit(false)
	// Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scope names
    __Vscope_v__BFLY0.configure(this,name(),"v.BFLY0");
    __Vscope_v__BFLY0__add_o1i__FPU.configure(this,name(),"v.BFLY0.add_o1i.FPU");
    __Vscope_v__BFLY0__add_o1i__FPU__ADD.configure(this,name(),"v.BFLY0.add_o1i.FPU.ADD");
    __Vscope_v__BFLY0__add_o1i__FPU__SUB.configure(this,name(),"v.BFLY0.add_o1i.FPU.SUB");
    __Vscope_v__BFLY0__add_o1r__FPU.configure(this,name(),"v.BFLY0.add_o1r.FPU");
    __Vscope_v__BFLY0__add_o1r__FPU__ADD.configure(this,name(),"v.BFLY0.add_o1r.FPU.ADD");
    __Vscope_v__BFLY0__add_o1r__FPU__SUB.configure(this,name(),"v.BFLY0.add_o1r.FPU.SUB");
    __Vscope_v__BFLY0__add_t2__FPU.configure(this,name(),"v.BFLY0.add_t2.FPU");
    __Vscope_v__BFLY0__add_t2__FPU__ADD.configure(this,name(),"v.BFLY0.add_t2.FPU.ADD");
    __Vscope_v__BFLY0__add_t2__FPU__SUB.configure(this,name(),"v.BFLY0.add_t2.FPU.SUB");
    __Vscope_v__BFLY0__sub_o2i__FPU.configure(this,name(),"v.BFLY0.sub_o2i.FPU");
    __Vscope_v__BFLY0__sub_o2i__FPU__ADD.configure(this,name(),"v.BFLY0.sub_o2i.FPU.ADD");
    __Vscope_v__BFLY0__sub_o2i__FPU__SUB.configure(this,name(),"v.BFLY0.sub_o2i.FPU.SUB");
    __Vscope_v__BFLY0__sub_o2r__FPU.configure(this,name(),"v.BFLY0.sub_o2r.FPU");
    __Vscope_v__BFLY0__sub_o2r__FPU__ADD.configure(this,name(),"v.BFLY0.sub_o2r.FPU.ADD");
    __Vscope_v__BFLY0__sub_o2r__FPU__SUB.configure(this,name(),"v.BFLY0.sub_o2r.FPU.SUB");
    __Vscope_v__BFLY0__sub_t1__FPU.configure(this,name(),"v.BFLY0.sub_t1.FPU");
    __Vscope_v__BFLY0__sub_t1__FPU__ADD.configure(this,name(),"v.BFLY0.sub_t1.FPU.ADD");
    __Vscope_v__BFLY0__sub_t1__FPU__SUB.configure(this,name(),"v.BFLY0.sub_t1.FPU.SUB");
    __Vscope_v__fftram__SRAM000.configure(this,name(),"v.fftram.SRAM000");
    __Vscope_v__fftram__SRAM001.configure(this,name(),"v.fftram.SRAM001");
    __Vscope_v__fftram__SRAM002.configure(this,name(),"v.fftram.SRAM002");
    __Vscope_v__fftram__SRAM003.configure(this,name(),"v.fftram.SRAM003");
}
