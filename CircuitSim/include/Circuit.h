#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <string>
#include <vector>
#include "Components.h"
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class Circuit {

public:
    Circuit(int size = 0);
    ~Circuit();
    
    void addComponent(Component& comp); // addVertex in graphs
    void addWire(Component& comp1, Component& comp2); // addEdge in graphs
    bool hasCycle();
private:
    int circuitSize;
    // adjacecny list graph for representing circuit 
    std::unordered_map<std::string, int> componentsHashMap;
    std::vector<ComponentLinkedList> components;
    bool hasCycleUtil(int componentID, std::unordered_set<int>& visited, std::unordered_set<int>& recursionStack);
};

#endif    
// bool isCyclicUtil(int vertex, std::unordered_set<int>& visited, std::unordered_set<int>& recursionStack);
