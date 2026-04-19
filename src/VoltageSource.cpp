#include "VoltageSource.h"

VoltageSource::VoltageSource(std::string name, int nodeMinus, int nodePlus, double voltage)
    : name(name), nodeMinus(nodeMinus), nodePlus(nodePlus), voltage(voltage) {}
