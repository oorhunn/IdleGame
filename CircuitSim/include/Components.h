#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string>
#include <memory>
#include <iostream>
class Resistor;

enum class ComponentType{
    RESISTOR,
    VOLTAGE_SOURCE
};


class Component{
public:
    Component(std::string componentName, ComponentType type);
    virtual ~Component();

    int getComponentID() const;
    void setComponentID(int compID);

    std::string getComponentName() const;

private:
    int componentID;
    ComponentType type;
    std::string componentName;

};

class Resistor : public Component{

public:
    Resistor(std::string componentName, int resistorValue);
    ~Resistor() override;

    float getResistorValue() const;

private:
    float resistorValue;
    float voltage;
    float current;
};
#endif