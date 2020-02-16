// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsecret_impl_PSfnzb.h"
#include "Vsecret_impl.h"



// FUNCTIONS
Vsecret_impl_PSfnzb::Vsecret_impl_PSfnzb(Vsecret_impl* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->PSoh6I(this, true);
    // Setup scopes
    PSFC6p.configure(this, name(), "PSnw9R", "PSnw9R", VerilatedScope::SCOPE_OTHER);
}
