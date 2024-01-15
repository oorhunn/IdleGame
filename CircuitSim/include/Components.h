#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string>
#include <memory>


enum class ComponentType{
    RESISTOR,
    VOLTAGE_SOURCE
};


class Component {
public:
    Component(std::string componentName, float val, ComponentType type);
    ~Component();

    int getComponentID();
    std::string getComponentName();
    void setComponentID(int compID);

private:
    int componentID;
    ComponentType type;
    std::string componentName;
    float voltage;
    float current;
    float value; // will be different if resistor or not 
};
#endif