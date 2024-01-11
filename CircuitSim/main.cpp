#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "./include/Components.h"
#include "./include/Circuit.h"
#include <string>


// case for component is not connected to anythin
// case for parallel resistors
// case for series resistors
// 
int main() {
    Component r1("R1", ComponentType::RESISTOR);
    Component r2("R2", ComponentType::RESISTOR);
    Component r3("R3", ComponentType::RESISTOR);


    Component r4("R4", ComponentType::RESISTOR);


    Component v1("V1", ComponentType::VOLTAGE_SOURCE);
// https://github.com/IrfanJames/CircuitSimulator_SFML/tree/main/Study%20Papers
// https://www-h.eng.cam.ac.uk/help/tpl/talks/C++graphs.html#GraphTraversal
    Circuit myCir;
    myCir.addComponent(r1);
    myCir.addComponent(r2);
    myCir.addComponent(r3);

    myCir.addComponent(v1);

    myCir.addComponent(r4);

    myCir.addWire(v1, r1);
    myCir.addWire(r1, r2);
    myCir.addWire(r2, r3);
    myCir.addWire(r3, v1);

    myCir.identifyParallelSeriesResistors();
    return 0;
}
