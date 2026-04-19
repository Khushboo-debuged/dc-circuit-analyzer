#include <iostream>
#include <vector>
#include "Parser.h"
#include "MatrixBuilder.h"
#include "solver.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: dc_analyzer <netlist_file>" << std::endl;
        return 1;
    }

    Parser parser;
    parser.parse(argv[1]);

    if (parser.nodeCount == 0) {
        std::cerr << "Error: No nodes found in netlist." << std::endl;
        return 1;
    }

    MatrixBuilder mb(parser.nodeCount);
    mb.build(parser.resistors, parser.voltageSources);

    int n = mb.size;

    double** A = new double*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new double[n];
        for (int j = 0; j < n; j++)
            A[i][j] = mb.G[i][j];
    }

    double* b = new double[n];
    double* x = new double[n];
    for (int i = 0; i < n; i++)
        b[i] = mb.I[i];

    int result = gaussian_elimination(A, b, x, n);

    if (result != 0) {
        std::cerr << "Error: Singular matrix, circuit cannot be solved." << std::endl;
        return 1;
    }

    std::cout << "\n===== DC Circuit Analysis Results =====" << std::endl;
    std::cout << "\nNode Voltages:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << "  V" << (i + 1) << " = " << x[i] << " V" << std::endl;

    std::cout << "\nBranch Currents:" << std::endl;
    for (const auto& r : parser.resistors) {
        double v1 = (r.node1 > 0) ? x[r.node1 - 1] : 0.0;
        double v2 = (r.node2 > 0) ? x[r.node2 - 1] : 0.0;
        double current = (v1 - v2) / r.resistance;
        std::cout << "  I(" << r.name << ") = " << current << " A" << std::endl;
    }

    std::cout << "\n=======================================" << std::endl;

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
    delete[] b;
    delete[] x;

    return 0;
}
