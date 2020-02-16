	// verilator_coverage annotation
	// Code your design here
	//Write in verilog, not sure of system verilog support
	//in FPGA synthesis
	
	module fifo (/*AUTOARG*/
	   // Outputs
	   full, empty, dataout,
	   // Inputs
	   clk, rst, push, pop, datain
	   );
	
	   //------------------------------
	   parameter width=8;
	   parameter depth=4;
	   parameter log2depth=2;
	   //------------------------------
 004003	   input     clk,rst;
%000005	   input     push,pop;
 000201	   input [width-1:0] datain;
	
%000008	   output    full,empty;
 000204	   output [width-1:0] dataout;
	   //------------------------------
 000225	   reg [width-1:0]    mem[0:depth-1];
	   //------------------------------
	
 005824	   reg [log2depth-1:0]  rd_ptr,wr_ptr;
 000032	   reg [log2depth:0] 	cnt ,cnt_w ;
	   reg 			full, empty;
	
	   always @(posedge clk)
 000050	     if (rst)
	       begin
		  cnt <= 0;
		  rd_ptr <=0 ;
		  wr_ptr <=0 ;
	       end
	     else
 001950	       begin
		  cnt <= cnt_w;
	
 001942		  if (push)
		    begin
		       mem[wr_ptr] <= datain;
		       wr_ptr <= wr_ptr + 1;
		    end
	
 001939		  if (pop)
		    rd_ptr <= rd_ptr + 1 ;
	
	       end // else: !if(rst)
	
	   always @*
	     case({push,pop})
 004091	       2'b00,2'b11:begin
		  cnt_w = cnt ;
		  full = (cnt_w == depth);
		  empty = (cnt_w == 0);
	       end
	
 000012	       2'b10: begin
		  cnt_w = cnt + 1;
		  full = (cnt_w == depth);
		  empty = 0;
	       end
	
%000003	       2'b01: begin
		  cnt_w = cnt - 1;
		  full = 0;
		  empty = (cnt_w == 0);
	       end
	     endcase // case({push,pop})
	
	   wire [width-1:0]	       dataout = mem[rd_ptr] ;
	
	endmodule // fifo
	
