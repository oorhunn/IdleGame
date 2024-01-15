#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "./include/Components.h"
#include "./include/Circuit.h"
#include <string>

int main() {

    Circuit myCirc; 

    Component res1("R1", 0, ComponentType::RESISTOR);
    Component res2("R2", 0, ComponentType::RESISTOR);
    Component res3("R3", 0, ComponentType::RESISTOR);


    myCirc.addComponent(res1);
    myCirc.addComponent(res2);
    myCirc.addComponent(res3);

    myCirc.addWire(res1, res2);

    return 0;
}
