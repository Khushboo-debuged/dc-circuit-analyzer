#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

#include <vector>
#include "Resistor.h"
#include "VoltageSource.h"

class MatrixBuilder {
public:
    int size;
    std::vector<std::vector<double>> G;
    std::vector<double> I;

    MatrixBuilder(int nodeCount);
    void build(const std::vector<Resistor>& resistors, const std::vector<VoltageSource>& sources);
};

#endif
