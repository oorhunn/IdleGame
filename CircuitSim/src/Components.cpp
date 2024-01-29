
#include "../include/Components.h"



Component::Component(std::string componentName, ComponentType type) : 
type(type), componentName(componentName), componentID(0)

{

}

Component::~Component()
{

}

int Component::getComponentID() const{
    return componentID;
}

std::string Component::getComponentName() const {
    return componentName;
}

void Component::setComponentID(int compID){
    componentID = compID;
}

float Resistor::getResistorValue() const {
    return resistorValue;
}


Resistor::Resistor(std::string componentName, int resistorValue) :
    Component(componentName, ComponentType::RESISTOR), 
    resistorValue(resistorValue),
    voltage(0),
    current(0)
{

}

Resistor::~Resistor(){

}

void Resistor::setResistorValue(float newResistorVal) {
    resistorValue = newResistorVal;
}
