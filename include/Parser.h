#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "Resistor.h"
#include "VoltageSource.h"

class Parser {
public:
    std::vector<Resistor> resistors;
    std::vector<VoltageSource> voltageSources;
    int nodeCount;

    Parser();
    void parse(const std::string& filename);
};

#endif
