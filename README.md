# DC Circuit Analyzer 

A command-line tool to analyze DC circuits using **Node-Voltage Analysis**.

Built with **C++** (OOP + parsing) and **C** (Gaussian elimination math engine).

## How It Works
1. You provide a netlist file describing your circuit
2. The parser creates circuit objects in memory
3. A conductance matrix [G] is built from Kirchhoff's laws
4. The C math engine solves [G][V] = [I] using Gaussian Elimination
5. Node voltages and branch currents are printed to terminal

## Netlist Format
V1 0 1 9       # Voltage source: name, node-, node+, volts
R1 1 2 100     # Resistor: name, node1, node2, ohms
R2 2 0 200

## Build
mkdir build && cd build
cmake ..
make

## Run
./dc_analyzer ../examples/simple.netlist

## Tech Stack
- **C++17** — OOP, classes, STL
- **C** — High-performance Gaussian elimination
- **CMake** — Cross-platform build system
