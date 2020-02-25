#include "Stimulus.h"

void Stimulus::terminate() {
  while(this->alive) {
    this->alive = false;
    wait(1000);
  }
  cout << "@" << sc_time_stamp() << "::Terminate" << endl;
  sc_stop();
}

  void Stimulus::keep_alive() {
    this->alive=true;
  }

  void Stimulus::reset() {
      rst = 1;
      wait(50);
      rst = 0;
      wait();
      (this->reset_done).notify();
      cout << "@" << sc_time_stamp() << "::Reset  done"  << endl;
  }

  void Stimulus::init_counter( int _id, int _data , bool b2b) {
    transaction_basic_constraint basic("basic-constraint") ;
    basic.id_fix->disable_randomization();
    basic.op_fix->disable_randomization();
    //basic.op_fix = LOAD ;
    basic.next();

    wait();
    if (_data == -1)
      data = _id + 0x10;
    else
      data = _data ;

    //id = basic.xaction->id();
    id = _id;
    valid = 1;
    cmd = LOAD;

    if (!b2b) {
      wait();
      valid = 0;
    }
  }

  void Stimulus::read_counter( int _id, bool b2b) {
    transaction_basic_constraint basic("basic-constraint") ;
    basic.id_fix->disable_randomization();
    basic.op_fix->disable_randomization();
    //basic.op_fix = LOAD ;
    basic.next();

    wait();
    //id = basic.xaction->id();
    id = _id;
    valid = 1;
    cmd = READ;

    if (!b2b) {
      wait();
      valid = 0;
    }
  }

  void Stimulus::dec_counter( int _id, bool b2b) {
    transaction_basic_constraint basic("basic-constraint") ;
    basic.id_fix->disable_randomization();
    basic.op_fix->disable_randomization();
    //basic.op_fix = LOAD ;
    basic.next();

    wait();
    //id = basic.xaction->id();
    id = _id;
    valid = 1;
    cmd = DEC;

    if (!b2b) {
      wait();
      valid = 0;
    }
  }

  void Stimulus::inc_counter( int _id, bool b2b) {
    transaction_basic_constraint basic("basic-constraint") ;
    basic.id_fix->disable_randomization();
    basic.op_fix->disable_randomization();
    //basic.op_fix = LOAD ;
    basic.next();

    wait();
    //id = basic.xaction->id();
    id = _id;
    valid = 1;
    cmd = INC;

    if (!b2b) {
      wait();
      valid = 0;
    }
  }

  // This run_test is like a verilog initial block
  void Stimulus::run_test( ) {
    wait(this->reset_done);
    wait();

    for(int i=0;i<this->num;i++) {
      keep_alive();
      init_counter( i, -1, true);
      cout << "@" << sc_time_stamp() << "::init_counter::" << i << endl;
    }

    for(int i=0;i<this->num;i++) {
      keep_alive();
      read_counter( i,  true);
      cout << "@" << sc_time_stamp() << "::read_counter::" << i << endl;
    }

    for(int i=0;i<this->num;i++) {
      keep_alive();
      inc_counter( i,  true);
      cout << "@" << sc_time_stamp() << "::inc_counter::" << i << endl;
    }

    for(int i=0;i<this->num;i++) {
      keep_alive();
      read_counter( i,  true);
      cout << "@" << sc_time_stamp() << "::read_counter::" << i << endl;
    }

    for(int i=0;i<this->num;i++) {
      keep_alive();
      dec_counter( i, true);
      cout << "@" << sc_time_stamp() << "::dec_counter::" << i << endl;
    }

    for(int i=0;i<this->num;i++) {
      keep_alive();
      read_counter( i,  true);
      cout << "@" << sc_time_stamp() << "::read_counter::" << i << endl;
    }

    cout << "@" << sc_time_stamp() << "::Source data thread done::" << this->num << endl;
  }
