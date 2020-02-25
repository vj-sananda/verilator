#ifndef __STIMULUS_H__
#define __STIMULUS_H__

#include "systemc.h"
#include "op_xaction.h"

SC_MODULE(Stimulus) {
  sc_in<bool> clk;
  sc_out<bool> rst;
  sc_out<bool> valid;
  sc_in<bool> output_valid;
  sc_out< uint32_t > data ;
  sc_out< uint32_t > id ;
  sc_out< uint32_t > cmd ;
  sc_in< uint32_t > output_data;

  int num ;
  bool alive ;
  sc_event reset_done ;

  void reset() ;
  void run_test() ;
  void terminate();

  //These are like verilog tasks that get called
  //inside the threads.
  //Cannot call them directly.
  void keep_alive();
  void init_counter( int _id, int _data, bool b2b) ;
  void read_counter( int _id, bool b2b) ;
  void inc_counter( int _id, bool b2b) ;
  void dec_counter( int _id, bool b2b) ;

  SC_CTOR(Stimulus) : num(10) , alive(true) {

    // The threads are like verilog procedural blocks.

    SC_THREAD(run_test);
    sensitive << clk.pos();

    SC_THREAD(reset);
    sensitive << clk.pos();

    SC_THREAD(terminate);
    sensitive << clk.pos();
  }

};

#endif
