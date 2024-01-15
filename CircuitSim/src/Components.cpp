
#include "../include/Components.h"



Component::Component(std::string componentName, float val, ComponentType type) : 
type(type), voltage(0), current(0), value(val), componentName(componentName), componentID(0)


{

}

Component::~Component()
{

}

int Component::getComponentID(){
    return componentID;
}

std::string Component::getComponentName(){
    return componentName;
}

void Component::setComponentID(int compID){
    componentID = compID;
}