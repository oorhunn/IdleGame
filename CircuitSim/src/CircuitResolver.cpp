
#include "../include/CircuitResolver.h"



CircuitResolver::CircuitResolver() :
    circuitLoops(nullptr),
    componentCatalogPtr(nullptr)
{

}


CircuitResolver::~CircuitResolver()
{
    
}
void CircuitResolver::simplfyTwoLinesLaterChangeName(){
    // TODO: make it select itself 
    _simplfyTwoLines(circuitLoops->data()[0], circuitLoops->data()[1]);
}

void CircuitResolver::updateCircuitLoopsPtr(std::shared_ptr<std::vector<std::vector<int>>> loopPtr){
    circuitLoops = loopPtr;
}

void CircuitResolver::updateComponentAdjacentList(std::shared_ptr<AdjacentComponentList<Component>> adjComponentsList){
    adjComponentsListPtr = adjComponentsList;
}

void CircuitResolver::update(std::shared_ptr<std::vector<std::vector<int>>> newPtr) {
    circuitLoops = newPtr;
}

void CircuitResolver::update(std::shared_ptr<ComponentsCatalogHashMap> newComponentCatalogPtr) {
    componentCatalogPtr = newComponentCatalogPtr;
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
    if (result.size() > 1) {
        float res1_res = reduceSeriesResistors(result, path1);
    }
    if (result2.size() > 1) {
        float res2_res = reduceSeriesResistors(result2, path2);
    }
    // replace the resistor in the path
    float reducedResVal = reduceParallelResistors(result[0], result2[0]);
    updateComponentValue(path1[1], reducedResVal);
    auto it = componentCatalogPtr->find(path1[1]);
    float aaa = std::dynamic_pointer_cast<Resistor>(it->second)->getResistorValue();
    std::cout << aaa << "\n";
}


// void CircuitResolver::reduceSeriesResistors(int CompIDS...){
//     float totalResistance = 0;
//     va_list args;
//     va_start(args, CompIDS);

//     for (int compID = CompIDS; compID != -1; compID = va_arg(args, int)) {
//         auto it = componentCatalogPtr->find(compID);
//         if (it != componentCatalogPtr->end()) {
//             std::shared_ptr<Component> component = it->second;

//             if (auto resistor = std::dynamic_pointer_cast<Resistor>(component)) {
//                 totalResistance += resistor->getResistorValue();
//             }
//         }
//     }
//     va_end(args);
// }

float CircuitResolver::reduceParallelResistors(int compID1, int compID2){
    float res1 = 0;
    float res2 = 0;
    auto itComp1 = componentCatalogPtr->find(compID1);
    if (itComp1 != componentCatalogPtr->end()) {
        std::shared_ptr<Component> component1 = itComp1->second;
        if (auto resistor1 = std::dynamic_pointer_cast<Resistor>(component1)) {
            res1 = resistor1->getResistorValue();
        }
    }
    auto itComp2 = componentCatalogPtr->find(compID2);
    if (itComp2 != componentCatalogPtr->end()) {
        std::shared_ptr<Component> component2 = itComp2->second;
        if (auto resistor2 = std::dynamic_pointer_cast<Resistor>(component2)) {
            res2 = resistor2->getResistorValue();
        }
    }
    return 1 / (1 / res1 + 1 / res2);
}


float CircuitResolver::reduceSeriesResistors(std::vector<int> inputPath, std::vector<int>& path) {
    float totalResistance = 0;
    for(const auto& res : inputPath){
        auto it = componentCatalogPtr->find(res);
            if (it != componentCatalogPtr->end()) {
                std::shared_ptr<Component> component = it->second;

                if (auto resistor = std::dynamic_pointer_cast<Resistor>(component)) {
                    totalResistance += resistor->getResistorValue();
            }
        }
    }
    return totalResistance;
}


void CircuitResolver::updateComponentValue(int compID, float newVal) {
    auto itComp = componentCatalogPtr->find(compID);
    if (itComp != componentCatalogPtr->end()){
        std::shared_ptr<Component> temp = itComp->second;
        std::dynamic_pointer_cast<Resistor>(temp)->setResistorValue(newVal);
        std::cout << std::dynamic_pointer_cast<Resistor>(temp)->getResistorValue() << std::endl;
    }
}
