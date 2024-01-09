#include "../include/Circuit.h"



Circuit::Circuit(int size) :
    circuitSize(size)
{

}
Circuit::~Circuit(){

}

void Circuit::addComponent(Component& comp){
    components.resize(circuitSize + 1, ComponentLinkedList());
    // set component id
    componentsHashMap.insert(std::make_pair(comp.name, circuitSize));
    comp.componentID = componentsHashMap[comp.name];
    components[componentsHashMap[comp.name]].appendComponent(comp);
    ++circuitSize;
}


void Circuit::addWire(Component& comp1, Component& comp2){
    components[componentsHashMap[comp1.name]].appendComponent(comp2);
}

bool Circuit::hasCycle() {
    std::unordered_set<int> visited;
    std::unordered_set<int> recursionStack;

    for (const auto& entry : componentsHashMap) {
        int componentID = entry.second;
        if (visited.find(componentID) == visited.end()) {
            if (hasCycleUtil(componentID, visited, recursionStack)) {
                return true;
            }
        }
    }

    return false;
}

// Helper function to check for cycles using DFS
bool Circuit::hasCycleUtil(int componentID, std::unordered_set<int>& visited, std::unordered_set<int>& recursionStack) {
    visited.insert(componentID);
    recursionStack.insert(componentID);

    // Get the linked list associated with the componentID
    ComponentLinkedList& currentList = components[componentID];

    // Traverse the linked list and perform DFS on connected components
    std::shared_ptr<Component> current = currentList.getHead();
    while (current) {
        int connectedComponentID = componentsHashMap[current->name];
        if (visited.find(connectedComponentID) == visited.end()) {
            if (hasCycleUtil(connectedComponentID, visited, recursionStack)) {
                return true;
            }
        } else if (recursionStack.find(connectedComponentID) != recursionStack.end()) {
            return true;
        }
        current = current->next;
    }

    recursionStack.erase(componentID);

    return false;
}