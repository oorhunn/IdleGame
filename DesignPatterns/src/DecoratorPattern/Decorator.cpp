#include "../../include/DecoratorPattern/Decorator.h"



ConcreteComponent::ConcreteComponent() {
    std::cout << "concreate component here \n"; 
}

std::string ConcreteComponent::Operation() const {
    return "ConcreteComponent";
}

Decorator::Decorator(Component* component) :
    component_(component) 
{

}

std::string Decorator::Operation() const {
    return this->component_->Operation();
}

ConcreteDecoratorA::ConcreteDecoratorA(Component* component) : 
    Decorator(component) 
{

}

std::string ConcreteDecoratorA::Operation() const {
    std::cout << "decorator A is here  \n";
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
}

ConcreteDecoratorB::ConcreteDecoratorB(Component* component) :
    Decorator(component) 
{

}

std::string ConcreteDecoratorB::Operation() const {
    return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
}