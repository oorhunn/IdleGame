#ifndef CIRCUITRESOLVER_H
#define CIRCUITRESOLVER_H
#include <vector>
#include <memory>
#include <iostream>
#include <cstdarg>

#include "AdjacentList.h"
#include "ComponentHashMapObserver.h"


class CircuitResolver : public CircuitPathObserver {

public:
    CircuitResolver(std::shared_ptr<std::vector<std::vector<int>>> listPtr);
    ~CircuitResolver() override;

    void simplfyTwoLinesLaterChangeName(); // driver

    void updateCircuitLoopsPtr(std::shared_ptr<std::vector<std::vector<int>>> loopPtr);
    void updateComponentAdjacentList(std::shared_ptr<AdjacentComponentList<Component>> adjComponentsList);

    void update(std::shared_ptr<std::vector<std::vector<int>>> newPtr) override;  // Adding the missing update function

    void tempStuff() = delete;

private:
    std::shared_ptr<std::vector<std::vector<int>>> circuitLoops;
    std::shared_ptr<AdjacentComponentList<Component>> adjComponentsListPtr;

    
    void _simplfyTwoLines(std::vector<int>& path1, std::vector<int>& path2); // driver

    void reduceSeriesResistors(int CompIDS...);
    void reduceParallelResistors(int compID1, int compID2);
};


// void Circuit::isParallel(std::vector<int>& path1, std::vector<int>& path2) const {

//     std::unordered_set<int> set1(path1.begin(), path1.end());
//     std::unordered_set<int> set2(path2.begin(), path2.end());

//     std::vector<int> result;
//     std::vector<int> result2;


//     for (int element : set1) {
//         if (set2.find(element) == set2.end()) {
//             result.push_back(element);
//         }
//     }

//     for (int element : set2) {
//         if (set1.find(element) == set1.end()) {
//             result2.push_back(element);
//         }
//     }
//     // need for delete element will come back 

// }

#endif