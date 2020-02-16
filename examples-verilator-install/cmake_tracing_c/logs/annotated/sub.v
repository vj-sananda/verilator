	// verilator_coverage annotation
	// DESCRIPTION: Verilator: Verilog Test module
	//
	// This file ONLY is placed into the Public Domain, for any use,
	// without warranty, 2003 by Wilson Snyder.
	// ======================================================================
	
	module sub
	  (
 000010	   input clk,
 000042	   input fastclk,
%000002	   input reset_l
	   );
	
	   // Example counter/flop
 000058	   reg [31:0] count_f;
	   always_ff @ (posedge fastclk) begin
%000004	      if (!reset_l) begin
	         /*AUTORESET*/
	         // Beginning of autoreset for uninitialized flops
	         count_f <= 32'h0;
	         // End of automatics
	      end
 000017	      else begin
	         count_f <= count_f + 1;
	      end
	   end
	
	   // Another example flop
%000042	   reg [31:0] count_c;
	   always_ff @ (posedge clk) begin
%000001	      if (!reset_l) begin
	         /*AUTORESET*/
	         // Beginning of autoreset for uninitialized flops
	         count_c <= 32'h0;
	         // End of automatics
	      end
%000004	      else begin
	         count_c <= count_c + 1;
%000001	         if (count_c >= 3) begin
	            $display("[%0t] fastclk is %0d times faster than clk\n",
	                     $time, count_f/count_c);
	            // This write is a magic value the Makefile uses to make sure the
	            // test completes successfully.
	            $write("*-* All Finished *-*\n");
	            $finish;
	         end
	      end
	   end
	
	   // An example assertion
	   always_ff @ (posedge clk) begin
	      AssertionExample: assert (!reset_l || count_c<100);
	   end
	
	   // And example coverage analysis
%000001	   cover property (@(posedge clk) count_c==3);
	
	endmodule
	
