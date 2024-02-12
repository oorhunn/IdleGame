#include "../../include/AbstractPattern/Abstract.h"




std::string ConcreteProductA1::UsefulFunctionA() const {
    return "The result of the product A1.";
}

std::string ConcreteProductA2::UsefulFunctionA() const {
    return "The result of the product A2.";
}


std::string ConcreteProductB1::UsefulFunctionB() const {
    return "The result of the product B1.";

}

std::string ConcreteProductB1::AnotherUsefulFunctionB(const AbstractProductA &collaborator) const {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B1 collaborating with ( " + result + " )";
}


std::string ConcreteProductB2::UsefulFunctionB() const {
    return "The result of the product B2.";

}



std::string ConcreteProductB2::AnotherUsefulFunctionB(const AbstractProductA &collaborator) const {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
}



void ClientCode(const AbstractFactory &factory) {
    const AbstractProductA *product_a = factory.CreateProductA();
    const AbstractProductB *product_b = factory.CreateProductB();
    std::cout << product_b->UsefulFunctionB() << "\n";
    std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}


// std::cout << "Client: Testing client code with the first factory type:\n";
// ConcreteFactory1 *f1 = new ConcreteFactory1();
// ClientCode(*f1);
// delete f1;
// std::cout << std::endl;
// std::cout << "Client: Testing the same client code with the second factory type:\n";
// ConcreteFactory2 *f2 = new ConcreteFactory2();
// ClientCode(*f2);
// delete f2;
// return 0;