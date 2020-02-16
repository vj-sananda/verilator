// -*- SystemC -*-
// DESCRIPTION: Verilator Example: fifo level main for invoking SystemC model
//
// This file ONLY is placed into the Public Domain, for any use,
// without warranty, 2017 by Wilson Snyder.
//======================================================================

// SystemC global header
#include <systemc.h>

// Include common routines
#include <verilated.h>
#if VM_TRACE
#include <verilated_vcd_sc.h>
#endif

#include <sys/stat.h>  // mkdir

// Include model header, generated from Verilating "fifo.v"
#include "Vfifo.h"

#include "Stimulus.h"

int sc_main(int argc, char* argv[]) {
    // This is a more complicated example, please also see the simpler examples/make_hello_c.

    // Prevent unused variable warnings
    if (0 && argc && argv) {}

    // Set debug level, 0 is off, 9 is highest presently used
    // May be overridden by commandArgs
    Verilated::debug(0);

    // Randomization reset policy
    // May be overridden by commandArgs
    Verilated::randReset(2);

    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    Verilated::commandArgs(argc, argv);

    // General logfile
    ios::sync_with_stdio();

    // Defaults time
#if (SYSTEMC_VERSION>20011000)
#else
    sc_time dut(1.0, sc_ns);
    sc_set_default_time_unit(dut);
#endif

    // Define clocks
#if (SYSTEMC_VERSION>=20070314)
    sc_clock clk     ("clk",    10,SC_NS, 0.5, 3,SC_NS, true);
#else
    sc_clock clk     ("clk",    10, 0.5, 3, true);
#endif

    // Define interconnect
    sc_signal<bool> rst;
    sc_signal<  uint32_t > dataout;
    sc_signal<  uint32_t > datain;

    sc_signal<bool> full;
    sc_signal<bool> empty;
    sc_signal<bool> push;
    sc_signal<bool> pop;

    // Construct the Verilated model, from inside Vfifo.h
    Vfifo* fifo = new Vfifo("fifo");
    Stimulus* stim = new Stimulus("stim");

    // Attach signals to the model
    fifo->clk       (clk);
    fifo->rst   (rst);
    fifo->full  (full);
    fifo->empty   (empty);
    fifo->push   (push);
    fifo->pop (pop);
    fifo->dataout  (dataout);
    fifo->datain  (datain);

    stim->clk(clk);
    stim->rst(rst);
    stim->full(full);
    stim->empty(empty);
    stim->push(push);
    stim->pop(pop);
    stim->datain(datain);

#if VM_TRACE
    // Before any evaluation, need to know to calculate those signals only used for tracing
    Verilated::traceEverOn(true);
#endif

    // You must do one evaluation before enabling waves, in order to allow
    // SystemC to interconnect everything for testing.
#if (SYSTEMC_VERSION>=20070314)
    sc_start(1,SC_NS);
#else
    sc_start(1);
#endif

#if VM_TRACE
    // If verilator was invoked with --trace argument,
    // and if at run time passed the +trace argument, turn on tracing
    VerilatedVcdSc* tfp = NULL;
    const char* flag = Verilated::commandArgsPlusMatch("trace");
    if (flag && 0==strcmp(flag, "+trace")) {
        cout << "Enabling waves into logs/vlt_dump.vcd...\n";
        tfp = new VerilatedVcdSc;
        fifo->trace(tfp, 99);  // Trace 99 levels of hierarchy
        Verilated::mkdir("logs");
        tfp->open("logs/vlt_dump.vcd");
    }
#endif

    sc_start();
    //sc_start(5000,SC_NS);

    cout << "@" << sc_time_stamp() << "::MAIN::Cleanup" << endl;
    if (tfp) tfp->flush();

    // Final model cleanup
    fifo->final();

    // Close trace if opened
#if VM_TRACE
    if (tfp) { tfp->close(); tfp = NULL; }
#endif

    //  Coverage analysis (since test passed)
#if VM_COVERAGE
    Verilated::mkdir("logs");
    VerilatedCov::write("logs/coverage.dat");
#endif

    // Destroy model
    delete fifo; fifo = NULL;

    // Fin
    return 0;
}
