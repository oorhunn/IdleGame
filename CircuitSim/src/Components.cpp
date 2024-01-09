
#include "../include/Components.h"


Component::Component(std::string name, ComponentType type) :
    name(name), type(type), next(nullptr)
{
    //
}

Component::Component() :
    next(nullptr)
{

}

ComponentLinkedList::ComponentLinkedList() :
    head(nullptr)
{

}

ComponentLinkedList::~ComponentLinkedList(){

}

void ComponentLinkedList::appendComponent(Component& comp){
    if (!head){
        head = std::make_shared<Component>(comp);
    } else {
        std::shared_ptr<Component> current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = std::make_shared<Component>(comp);
    }
}

void ComponentLinkedList::deleteComponent(Component& comp){
    if (!head) {
        return;
    }
    if (head->name == comp.name) {
        head = head->next; 
        return;
    }

    std::shared_ptr<Component> current = head;
    while (current->next && current->next->name != comp.name) {
        current = current->next;
    }

    if (current->next) {
        current->next = current->next->next;
    }

}

std::shared_ptr<Component> ComponentLinkedList::getHead() const {
    return head;
}