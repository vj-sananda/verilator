// Code your design here
//command defines
`define LOAD  3'b000
`define CLEAR 3'b001
`define INC   3'b010
`define DEC   3'b011
`define READ  3'b100

`include "dpsram.sv"

module sram_multi_counter (
  input logic clk,rst,
  input logic valid,
  input logic [7:0] id,
  input logic [7:0] data,
  input logic [2:0] cmd ,
  output logic [7:0] output_data,
  output logic output_valid
);
  
  //Wires for dual port sram
  logic read_enable,write_enable;
  logic [7:0] read_data,write_data,read_addr,write_addr;
  
  //Port 0, read port
  //Port 1, write port
  dpsram #(256,8) mem
  (.clk0(clk),
   .clk1(clk),
   
   .en0(read_enable),
   .en1(write_enable),
   
   .wen0(1'b0), //port 0 is always read
   .wen1(1'b1), //port 1 is always write
  
   .din0(8'b0),
   .din1(write_data),
   
   .addr0(read_addr),
   .addr1(write_addr),
   
   .dout0(read_data)
   
  );
  
  logic hazard_p0, hazard_p1;
  logic [7:0] data_fwd;
  
  logic valid_p1;
  logic [7:0] data_p1;
  logic [7:0] id_p1;
  logic [2:0] cmd_p1;
  
  //Cycle p0, always dispatch read
  always_comb begin
    read_addr = 0;
    read_enable = 0 ;
    
    if (valid) begin
      read_addr = id;
      read_enable = 1;
    end
    
    hazard_p0 = (id == id_p1) & valid_p1 & valid ;
  end
  
  always @(posedge clk)
    if (rst) begin
      hazard_p1 <= 0;
      valid_p1 <= 0;
      id_p1 <= 0;
    end
  else
    begin
      valid_p1 <= valid;
      if (valid) begin
         hazard_p1 <= hazard_p0;
		 id_p1 <= id ;
         data_p1 <= data;
         cmd_p1 <= cmd ;
      end
    end
  
  //cycle p1
  always_comb begin
    write_enable = 0;
    output_valid = 0;
    
    if (valid_p1) begin
      write_enable = 1;
      write_addr = id_p1;
      
      case(cmd_p1)
        `LOAD: write_data = data_p1;
        `CLEAR: write_data = 0;
        `INC: begin
          if (hazard_p1)
            write_data = data_fwd + 1'b1;
          else
			write_data = read_data + 1'b1;
         end
        `DEC: begin
          if (hazard_p1)
         	 write_data = data_fwd - 1'b1;
          else
        	 write_data = read_data - 1'b1;
          end
        `READ: begin
           write_enable = 0;
           output_valid = 1;
          if (hazard_p1)
            output_data = data_fwd;
          else
           output_data = read_data;
          end
       endcase
      
    end
  end
  
  always @(posedge clk)
    if (rst) begin
      data_fwd <= 0;
    end
  else begin
    if (valid_p1)
  	  data_fwd <= write_data;
  end
  
  
  
  
  
  
  
  
endmodule