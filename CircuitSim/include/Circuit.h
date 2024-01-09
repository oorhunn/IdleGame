#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <string>
#include <vector>
#include "Components.h"
#include <unordered_map>

class Circuit {

public:
    Circuit(int size = 0);
    ~Circuit();
    
    void addComponent(Component& comp); // addVertex in graphs
    void addWire(Component& comp1, Component& comp2); // addEdge in graphs


private:
    int circuitSize;
    // adjacecny list graph for representing circuit 
    std::unordered_map<std::string, int> componentsHashMap;
    std::vector<ComponentLinkedList> components;

};

#endif