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

  void Stimulus::source_data( ) {
    wait(this->reset_done);
    wait();

    for(int i=0;i<this->num;i++) {
      keep_alive();
      push = 0;
      while ( full.read() == 1 ) {
        wait();
      }
      push = 1;
      datain = ++data;
      wait();
      cout << "@" << sc_time_stamp() << "::Push::" << data << endl;
    }
    cout << "@" << sc_time_stamp() << "::Source data thread done::" << this->num << endl;
  }

  void Stimulus::sink_data( ) {

      wait(this->reset_done);
      wait(10);

      for (int i=0;i<this->num;i++) {
        keep_alive();
        pop=0;
        while( empty == 1)
          wait();
        pop=1;
        wait();
        cout << "@" << sc_time_stamp() << "::Pop::"  << endl;
      }
      cout << "@" << sc_time_stamp() << "::Sink data thread done::" << this->num << endl;

  }
