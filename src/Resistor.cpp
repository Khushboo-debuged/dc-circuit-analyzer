#include "Resistor.h"

Resistor::Resistor(std::string name, int node1, int node2, double resistance)
    : name(name), node1(node1), node2(node2), resistance(resistance) {}
