#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

Parser::Parser() : nodeCount(0) {}

void Parser::parse(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    std::string line;
    int maxNode = 0;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        size_t commentPos = line.find('#');
        if (commentPos != std::string::npos)
            line = line.substr(0, commentPos);

        std::istringstream ss(line);
        std::string name;
        ss >> name;

        if (name.empty()) continue;

        char type = toupper(name[0]);

        if (type == 'R') {
            int n1, n2;
            double resistance;
            ss >> n1 >> n2 >> resistance;
            resistors.push_back(Resistor(name, n1, n2, resistance));
            maxNode = std::max(maxNode, std::max(n1, n2));
        } else if (type == 'V') {
            int nMinus, nPlus;
            double voltage;
            ss >> nMinus >> nPlus >> voltage;
            voltageSources.push_back(VoltageSource(name, nMinus, nPlus, voltage));
            maxNode = std::max(maxNode, std::max(nMinus, nPlus));
        }
    }

    nodeCount = maxNode;
    file.close();
}
