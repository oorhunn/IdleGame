#include "../include/Circuit.h"



Circuit::Circuit() :
    circuitSize(0)
{

}
Circuit::~Circuit(){

}



void Circuit::addComponent(Component comp){
    // set component id
    components.resize(circuitSize + 1);
    componentIDHashMap.insert(std::make_pair(comp.getComponentName(), circuitSize));
    comp.setComponentID(componentIDHashMap[comp.getComponentName()]);
    ++circuitSize;
}


void Circuit::addWire(Component target1, Component target2) {
    components[target1.getComponentID()].push_back(target2);
}