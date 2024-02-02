#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <string>


class Component {
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    ConcreteComponent();
    std::string Operation() const override;
};

class Decorator : public Component {
public:
    Decorator(Component* component);
    std::string Operation() const override;

protected:
    Component* component_;

};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component);
    std::string Operation() const override;
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component);

    std::string Operation() const override;
};



// void ClientCode(Component* component) {
//     std::cout << "RESULT: " << component->Operation();
// }

// int main()
// {

//     Component* simple = new ConcreteComponent;
//     std::cout << "Client: I've got a simple component:\n";
//     ClientCode(simple);
//     std::cout << "\n\n";

//     Component* decorator1 = new ConcreteDecoratorA(simple);
//     ClientCode(decorator1);

//     Component* decorator2 = new ConcreteDecoratorB(decorator1);
//     std::cout << "Client: Now I've got a decorated component:\n";
//     ClientCode(decorator2);
//     std::cout << "\n";

//     delete simple;
//     delete decorator1;
//     delete decorator2;


//     return 0;
// }


#endif