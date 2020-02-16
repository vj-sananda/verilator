#ifndef __STIMULUS_H__
#define __STIMULUS_H__

#include "systemc.h"

SC_MODULE(Stimulus) {
  sc_in<bool> clk;
  sc_out<bool> rst;
  sc_out<bool> push;
  sc_out<bool> pop;
  sc_in<bool> full;
  sc_in<bool> empty;
  sc_out< uint32_t > datain ;
  uint32_t data;
  int num ;
  bool alive ;
  sc_event reset_done ;

  void reset() ;
  void source_data() ;
  void sink_data() ;
  void terminate();
  void keep_alive();

  SC_CTOR(Stimulus) : data(0), num(100) , alive(true) {

    SC_THREAD(source_data);
    sensitive << clk.pos();

    SC_THREAD(sink_data);
    sensitive << clk.pos();

    SC_THREAD(reset);
    sensitive << clk.pos();

    SC_THREAD(terminate);
    sensitive << clk.pos();

  }

};

#endif
