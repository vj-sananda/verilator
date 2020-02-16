// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VSECRET_IMPL_PSFNZB_H_
#define _VSECRET_IMPL_PSFNZB_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vsecret_impl.h"

// SYMS CLASS
class Vsecret_impl_PSfnzb : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vsecret_impl*                  TOPp;
    
    // SCOPE NAMES
    VerilatedScope PSFC6p;
    
    // CREATORS
    Vsecret_impl_PSfnzb(Vsecret_impl* topp, const char* namep);
    ~Vsecret_impl_PSfnzb() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
