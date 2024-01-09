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