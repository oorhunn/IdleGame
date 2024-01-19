
#include "../include/CircuitResolver.h"



CircuitResolver::CircuitResolver(std::shared_ptr<std::vector<std::vector<int>>> listPtr) :
    circuitLoops(listPtr)
{

}


CircuitResolver::~CircuitResolver()
{
    
}
void CircuitResolver::simplfyTwoLinesLaterChangeName(){
    // TODO: make it select itself 
    _simplfyTwoLines(circuitLoops->data()[0], circuitLoops->data()[1]);
}

void CircuitResolver::_simplfyTwoLines(std::vector<int>& path1, std::vector<int>& path2) {
    std::unordered_set<int> set1(path1.begin(), path1.end());
    std::unordered_set<int> set2(path2.begin(), path2.end());

    std::vector<int> result;
    std::vector<int> result2;


    for (int element : set1) {
        if (set2.find(element) == set2.end()) {
            result.push_back(element);
        }
    }

    for (int element : set2) {
        if (set1.find(element) == set1.end()) {
            result2.push_back(element);
        }
    }

    // TODO: make it select itself later 
    reduceParallelResistors(result[0], result2[0]);
}


void CircuitResolver::reduceSeriesResistors(int CompIDS...){

}

void CircuitResolver::reduceParallelResistors(int compID1, int compID2){

    AdjacentComponentList<Component> temp = (*adjComponentsListPtr);
    std::list<std::shared_ptr<Component>> hel = temp[0];

    // std::shared_ptr<Component> hello = hel.begin();
    // for (const auto& list : *adjComponentsListPtr) {
    //     for (const auto& item : list) {

    //         auto resistorPtr = std::static_pointer_cast<Resistor>(item);
    //         if (resistorPtr) {
    //             std::cout << resistorPtr->getResistorValue() << std::endl;
    //         }
    //     }
    //     float a = list.data()[compID1]->getResistorValue();
    // }

}


void CircuitResolver::updateCircuitLoopsPtr(std::shared_ptr<std::vector<std::vector<int>>> loopPtr){
    circuitLoops = loopPtr;
}

void CircuitResolver::updateComponentAdjacentList(std::shared_ptr<AdjacentComponentList<Component>> adjComponentsList){
    adjComponentsListPtr = adjComponentsList;
}
