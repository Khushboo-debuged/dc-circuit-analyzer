cmake_minimum_required(VERSION 3.10)
project(dc_circuit_analyzer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(dc_analyzer
    src/main.cpp
    src/Parser.cpp
    src/Node.cpp
    src/Resistor.cpp
    src/VoltageSource.cpp
    src/MatrixBuilder.cpp
    src/solver.c
)

target_link_libraries(dc_analyzer m)
