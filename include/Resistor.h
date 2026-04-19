#ifndef RESISTOR_H
#define RESISTOR_H

#include <string>

class Resistor {
public:
    std::string name;
    int node1, node2;
    double resistance;

    Resistor(std::string name, int node1, int node2, double resistance);
};

#endif
