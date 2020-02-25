#ifndef __OP_XACTION_H__
#define __OP_XACTION_H__

#include <scv.h>

#define LOAD  0x00
#define CLEAR 0x01
#define INC   0x02
#define DEC   0x03
#define READ  0x04

struct op_transaction_t {
  sc_uint<8> id;
  sc_uint<8> data;
  sc_uint<3> op;
};

// Create packet extension
template<>
class scv_extensions<op_transaction_t> : public scv_extensions_base<op_transaction_t> {
public:
  scv_extensions<sc_uint<8> > id;
  scv_extensions<sc_uint<8> > data;
  scv_extensions<sc_uint<3> > op;

  SCV_EXTENSIONS_CTOR(op_transaction_t) {
    //must be in order
    SCV_FIELD(id);
    SCV_FIELD(data);
    SCV_FIELD(op);
  }
};

//Create a basic default constraint for the packet generator
struct transaction_base_constraint : public scv_constraint_base {
  //create a packet object
  scv_smart_ptr<op_transaction_t> xaction ;
  //put the base constraints on the packet variables
  SCV_CONSTRAINT_CTOR(transaction_base_constraint) {
    // Soft Constraint
    SCV_CONSTRAINT ( xaction->op() <= 4 ); // Max Frame Size
    SCV_CONSTRAINT ( xaction->op() >= 0 );   // Mix Frame Size
    // Hard Constraint
    //SCV_CONSTRAINT ( packet->data() != packet->dest_addr());
    // Hard limit on min frame size
    //SCV_CONSTRAINT ( packet->id() > 20 );
  }
};

// Create a actual contraint for the testcase
struct transaction_basic_constraint : public transaction_base_constraint {
  //add config variable
  scv_smart_ptr<sc_uint<8> > id_fix;
  scv_smart_ptr<sc_uint<3> > op_fix;

  SCV_CONSTRAINT_CTOR(transaction_basic_constraint) {
    //use the base constraint
    SCV_BASE_CONSTRAINT(transaction_base_constraint);
    //add extra constraints
    SCV_CONSTRAINT ( xaction->id() == id_fix() );
    SCV_CONSTRAINT ( xaction->op() == op_fix() );
  }
};

#endif
