#include "MatrixBuilder.h"
#include <iostream>

MatrixBuilder::MatrixBuilder(int nodeCount) : size(nodeCount) {
    G.assign(size, std::vector<double>(size, 0.0));
    I.assign(size, 0.0);
}

void MatrixBuilder::build(const std::vector<Resistor>& resistors, const std::vector<VoltageSource>& sources) {
    for (const auto& r : resistors) {
        double conductance = 1.0 / r.resistance;
        int n1 = r.node1 - 1;
        int n2 = r.node2 - 1;

        if (n1 >= 0) G[n1][n1] += conductance;
        if (n2 >= 0) G[n2][n2] += conductance;
        if (n1 >= 0 && n2 >= 0) {
            G[n1][n2] -= conductance;
            G[n2][n1] -= conductance;
        }
    }

    for (const auto& v : sources) {
        int nPlus = v.nodePlus - 1;
        int nMinus = v.nodeMinus - 1;

        if (nPlus >= 0) I[nPlus] += v.voltage;
        if (nMinus >= 0) I[nMinus] -= v.voltage;
    }
}
