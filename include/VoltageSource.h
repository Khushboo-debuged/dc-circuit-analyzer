#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H

#include <string>

class VoltageSource {
public:
    std::string name;
    int nodeMinus, nodePlus;
    double voltage;

    VoltageSource(std::string name, int nodeMinus, int nodePlus, double voltage);
};

#endif
