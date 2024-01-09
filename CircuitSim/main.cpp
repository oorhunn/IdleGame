#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "./include/Components.h"
#include "./include/Circuit.h"
#include <string>

int main() {
    Component r1("R1", ComponentType::RESISTOR);
    Component r2("R2", ComponentType::RESISTOR);
    Component r3("R3", ComponentType::RESISTOR);

    Component v1("V1", ComponentType::VOLTAGE_SOURCE);


    Circuit myCir;
    myCir.addComponent(r1);
    myCir.addComponent(r2);
    myCir.addComponent(r3);

    myCir.addComponent(v1);

    myCir.addWire(v1, r1);
    return 0;
}
