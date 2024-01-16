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
    Component res4("R4", 0, ComponentType::RESISTOR);
    Component res5("R5", 0, ComponentType::RESISTOR);



    myCirc.addComponent(res1);
    myCirc.addComponent(res2);
    myCirc.addComponent(res3);
    myCirc.addComponent(res4);


    myCirc.addWire(res1, res2);
    myCirc.addWire(res1, res3);
    myCirc.addWire(res3, res4);
    myCirc.addWire(res2, res4);



    myCirc.findAllPaths(res1, res3);
    myCirc.findAllPaths(res1, res4);

    return 0;
}
