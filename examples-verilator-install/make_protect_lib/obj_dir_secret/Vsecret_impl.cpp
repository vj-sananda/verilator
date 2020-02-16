// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsecret_impl.h for the primary calling header

#include "Vsecret_impl.h"
#include "Vsecret_impl_PSfnzb.h"

//==========

VL_CTOR_IMP(Vsecret_impl) {
    Vsecret_impl_PSfnzb* __restrict vlSymsp = __VlSymsp = new Vsecret_impl_PSfnzb(this, name());
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    PSKR5X();
}

void Vsecret_impl::PSoh6I(Vsecret_impl_PSfnzb* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsecret_impl::~Vsecret_impl() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vsecret_impl::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsecret_impl::eval\n"); );
    Vsecret_impl_PSfnzb* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    PSwpVR();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) PSE61r(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        PS2krC(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = PSKnmm(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("PSiHml", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = PSKnmm(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsecret_impl::PSE61r(Vsecret_impl_PSfnzb* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    PSWGDA(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        PSvzj7(vlSymsp);
        PS2krC(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = PSKnmm(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("PSiHml", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = PSKnmm(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsecret_impl::PSMiDd(Vsecret_impl_PSfnzb* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSMiDd\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("%Nsecret_impl: initialized\n",vlSymsp->name());
    vlTOPp->PSbV2W = 0U;
}

VL_INLINE_OPT void Vsecret_impl::PSaqN5(Vsecret_impl_PSfnzb* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSaqN5\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData PS9B7d;
    // Body
    PS9B7d = vlTOPp->PSbV2W;
    PS9B7d = (vlTOPp->PSbV2W + vlTOPp->a);
    vlTOPp->x = ((0xaU < vlTOPp->PSbV2W) ? vlTOPp->b
                  : ((IData)(9U) + (vlTOPp->a + vlTOPp->b)));
    vlTOPp->PSbV2W = PS9B7d;
}

void Vsecret_impl::PS2krC(Vsecret_impl_PSfnzb* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PS2krC\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->PSQvFf)))) {
        vlTOPp->PSaqN5(vlSymsp);
    }
    // Final
    vlTOPp->PSQvFf = vlTOPp->clk;
}

void Vsecret_impl::PSWGDA(Vsecret_impl_PSfnzb* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSWGDA\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PSMiDd(vlSymsp);
    vlTOPp->PSQvFf = vlTOPp->clk;
}

void Vsecret_impl::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::final\n"); );
    // Variables
    Vsecret_impl_PSfnzb* __restrict vlSymsp = this->__VlSymsp;
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsecret_impl::PSvzj7(Vsecret_impl_PSfnzb* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSvzj7\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vsecret_impl::PSKnmm(Vsecret_impl_PSfnzb* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSKnmm\n"); );
    Vsecret_impl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsecret_impl::PSwpVR() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSwpVR\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG

void Vsecret_impl::PSKR5X() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsecret_impl::PSKR5X\n"); );
    // Body
    a = VL_RAND_RESET_I(32);
    b = VL_RAND_RESET_I(32);
    x = VL_RAND_RESET_I(32);
    clk = VL_RAND_RESET_I(1);
    PSbV2W = VL_RAND_RESET_I(32);
}
