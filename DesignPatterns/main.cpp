#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <unordered_map>
#include "./include/BridgePattern/Bridge.h"

int main() {
    Implementation* implementation = new ConcreteImplementationA;
    Abstraction* abstraction = new Abstraction(implementation);
    ClientCode(*abstraction);
    std::cout << std::endl;
    delete implementation;
    delete abstraction;

    implementation = new ConcreteImplementationB;
    abstraction = new ExtendedAbstraction(implementation);
    ClientCode(*abstraction);
    delete implementation;
    delete abstraction;

    return 0;
}