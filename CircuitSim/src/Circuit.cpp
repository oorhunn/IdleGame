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

void Circuit::identifyParallelSeriesResistors() {
    for (const auto& entry : componentsHashMap) {
        int componentID = entry.second;
        ComponentLinkedList& currentList = components[componentID];
        std::shared_ptr<Component> current = currentList.getHead();

        while (current && current->next) {
            int connectedComponentID = componentsHashMap[current->next->name];
            
            // Check if the resistors are in parallel
            if (current->type == ComponentType::RESISTOR && current->next->type == ComponentType::RESISTOR) {
                std::cout << "Resistors " << current->name << " and " << current->next->name << " are in parallel." << std::endl;
            }

            // Check if the resistors are in series
            if (connectedComponentID != -1 && current->type == ComponentType::RESISTOR && current->next->type == ComponentType::RESISTOR) {
                std::cout << "Resistors " << current->name << " and " << current->next->name << " are in series." << std::endl;
            }

            current = current->next;
        }
    }
}