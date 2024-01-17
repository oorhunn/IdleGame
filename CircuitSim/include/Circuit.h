#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <list>
#include <map>
#include <cstdarg>
#include <memory>

#include "Components.h"
#include "AdjacentList.h"
#include "CircuitResolver.h"

class Circuit {
public:
    Circuit();
    ~Circuit();

    void addWire(std::shared_ptr<Component> target1, std::shared_ptr<Component> target2);
    void addComponent(std::shared_ptr<Component> comp);
    void removeComponent(std::shared_ptr<Component> comp);
    void removeWires(std::shared_ptr<Component> target1, std::shared_ptr<Component> target2);

    int getCircuitSize();

    std::vector<std::vector<int>> getCircuitLoops(std::shared_ptr<Component> src, std::shared_ptr<Component> dest);

private:
    // variables and containers start
    int circuitSize;
    std::shared_ptr<AdjacentList<Component>> components;
    std::shared_ptr<CircuitResolver> circuitResolverInsantce;

    // variables and containers end

    float calculateSeriesResistor(int compIDS...) = delete;
    
    

};



#endif // CIRCUIT_H
