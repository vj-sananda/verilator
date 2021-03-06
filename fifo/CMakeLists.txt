# rm -rf build && mkdir build && cd build
# cmake ..
# cmake --build .

cmake_minimum_required(VERSION 3.8)
project(hfifo)

find_package(verilator HINTS $ENV{VERILATOR_ROOT} ${VERILATOR_ROOT})
if (NOT verilator_FOUND)
  message(FATAL_ERROR "Verilator was not found. Either install it, or set the VERILATOR_ROOT environment variable")
endif()

# SystemC dependencies
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Find SystemC using SystemC's CMake integration
find_package(SystemCLanguage QUIET)

# Create a new executable target that will contain all your sources
add_executable(simx ./src/sc_main.cpp ./src/Stimulus.cpp)

# Add the Verilated circuit to the target
verilate(simx SYSTEMC COVERAGE TRACE
  INCLUDE_DIRS "./src"
  VERILATOR_ARGS -f ./input.vc -O2 -x-assign 0
  SOURCES ./src/fifo.sv)

verilator_link_systemc(simx)
