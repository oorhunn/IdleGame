#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <string>
#include <memory>
#include<iostream>

class Resistor;

enum class ComponentType{
    RESISTOR,
    VOLTAGE_SOURCE
};

class Component{

public:
    Component(std::string COMPONENT_NAME, ComponentType TYPE);
    virtual ~Component();

    int getComponentID() const;
    void setComponentID(int compID);
    std::string getComponentName() const;

    virtual float getVolate() const = 0; // later to be implemented it math stuff

protected:
    int* componentID;
    ComponentType* type;
    std::string* componentName;

private:


};

class Resistor{

public:
    Resistor(std::string COMPONENT_NAME, int RESISTOR_VALUE);
    ~Resistor();

private:

};


#endif