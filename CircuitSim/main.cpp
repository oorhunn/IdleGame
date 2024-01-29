#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "./include/Components.h"
#include "./include/Circuit.h"
#include "./include/AdjacentList.h"
#include <string>
#include <memory>

int main() {

    Circuit myCirc; 

    std::shared_ptr<Resistor> res1 = std::make_shared<Resistor>("R1", 1);
    std::shared_ptr<Resistor> res2 = std::make_shared<Resistor>("R2", 1);
    std::shared_ptr<Resistor> res3 = std::make_shared<Resistor>("R3", 1);
    std::shared_ptr<Resistor> res4 = std::make_shared<Resistor>("R4", 1);
    
    myCirc.addComponent(res1);
    myCirc.addComponent(res2);
    myCirc.addComponent(res3);
    myCirc.addComponent(res4);

    myCirc.addWire(res1, res2);
    myCirc.addWire(res1, res3);
    myCirc.addWire(res3, res4);
    myCirc.addWire(res2, res4);



    std::vector<std::vector<int>> temp = myCirc.getCircuitLoops(res1, res4);
    myCirc.circuitResolverCaller();
    return 0;
}
