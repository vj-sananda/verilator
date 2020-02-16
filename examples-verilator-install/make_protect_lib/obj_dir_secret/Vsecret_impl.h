// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSECRET_IMPL_H_
#define _VSECRET_IMPL_H_  // guard

#include "verilated_heavy.h"

//==========

class Vsecret_impl_PSfnzb;

//----------

VL_MODULE(Vsecret_impl) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(x,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    IData PSbV2W;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData PSQvFf;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vsecret_impl_PSfnzb* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vsecret_impl);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vsecret_impl(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vsecret_impl();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void PSE61r(Vsecret_impl_PSfnzb* __restrict vlSymsp);
  public:
    void PSoh6I(Vsecret_impl_PSfnzb* symsp, bool first);
  private:
    static QData PSKnmm(Vsecret_impl_PSfnzb* __restrict vlSymsp);
    void PSKR5X() VL_ATTR_COLD;
  public:
    static void PS2krC(Vsecret_impl_PSfnzb* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void PSwpVR();
#endif  // VL_DEBUG
  public:
    static void PSWGDA(Vsecret_impl_PSfnzb* __restrict vlSymsp) VL_ATTR_COLD;
    static void PSvzj7(Vsecret_impl_PSfnzb* __restrict vlSymsp) VL_ATTR_COLD;
    static void PSMiDd(Vsecret_impl_PSfnzb* __restrict vlSymsp) VL_ATTR_COLD;
    static void PSaqN5(Vsecret_impl_PSfnzb* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
