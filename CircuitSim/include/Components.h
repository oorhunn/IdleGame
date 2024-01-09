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
    Component();
    Component(std::string name, ComponentType type);

    std::string name;
    float voltage;
    float current;
    float resistance;
    ComponentType type;
    int componentID;
    std::shared_ptr<Component> next;

private:

};

class ComponentLinkedList {
public:
    ComponentLinkedList();
    ~ComponentLinkedList();

    void appendComponent(Component& comp);
    void deleteComponent(Component& comp);
    std::shared_ptr<Component> getHead() const;

private:
    std::shared_ptr<Component> head;
};
#endif