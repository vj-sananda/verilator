#include <scv.h>



int sc_main(int argc, char** argv) {
  // Set the Seed to 1
  scv_random::set_global_seed(1);
  //instatiate test specific constraints
  transaction_basic_constraint OpXaction("Constrained Transaction");
  // Disable randomization
  OpXaction.id_min->disable_randomization();
  OpXaction.id_max->disable_randomization();

  for(int i=0; i<5; ++i) {
    Xaction.next();
    cout << OpXaction.xaction->get_name() << *(OpXaction.xaction) << endl;
  }
  cout << endl;
  return (0);
}
