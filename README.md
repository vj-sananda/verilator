Verilator examples with systemc
===============================

counter-sysc : Counter in systemc.

fifo : With SystemC and cmake build

sram-multi-counter : Uses SystemC Verification Library (SCV) and cmake build

examples-verilator-install

hello_world_c++

try

Running with docker:
Use image from hub.docker.com : vjsananda/verilator-sysc:latest

git clone https://github.com/vj-sananda/verilator
cd verilator
docker run -it --entrypoint bash -v $PWD:/work vjsananda/verilator-sysc:latest 
#-v option maps current local working directory to /work in container
#--entrypoint bash : starts a bash script instead of running verilator
