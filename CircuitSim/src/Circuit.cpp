#include "../include/Circuit.h"


Circuit::Circuit() : 
    circuitSize(0),
    components(std::make_shared<AdjacentList<Component>>())
     
{

}


Circuit::~Circuit(){

}



void Circuit::addComponent(std::shared_ptr<Component> comp){
    components->addVertex(comp);
}


void Circuit::addWire(std::shared_ptr<Component> target1, std::shared_ptr<Component> target2) {
    components->addEdge(target1, target2);
}


std::vector<std::vector<int>> Circuit::getCircuitLoops(std::shared_ptr<Component> src, std::shared_ptr<Component> dest){
    components->findAllPaths(src, dest);
    return components->getAllPaths();


}

int Circuit::getCircuitSize() {
    circuitSize = components->getListSize();
    return circuitSize;
}

// float Circuit::calculateSeriesResistor(int CompIDS...){
//     float sum = 0;
//     va_list args;
//     va_start(args, CompIDS);

//     for (int i = CompIDS; i != -1; i = va_arg(args, int)) {
//         sum += i; // unfinished 
//     }

//     va_end(args);
//     return sum;
// }



