#ifndef CIRCUITRESOLVER_H
#define CIRCUITRESOLVER_H
#include <vector>
#include <memory>
#include <iostream>
#include <cstdarg>

#include "AdjacentList.h"

class CircuitResolver : public CircuitPathObserver, public ComponentCatalogObserver {

public:
    CircuitResolver();
    ~CircuitResolver() override;

    void simplfyTwoLinesLaterChangeName(); // driver

    void updateCircuitLoopsPtr(std::shared_ptr<std::vector<std::vector<int>>> loopPtr);
    void updateComponentAdjacentList(std::shared_ptr<AdjacentComponentList<Component>> adjComponentsList);

    void update(std::shared_ptr<std::vector<std::vector<int>>> newPtr) override;  // adding the missing update function
    void update(std::shared_ptr<ComponentsCatalogHashMap> newComponentCatalogPtr) override;


private:
    std::shared_ptr<std::vector<std::vector<int>>> circuitLoops;
    std::shared_ptr<ComponentsCatalogHashMap> componentCatalogPtr;
    std::shared_ptr<AdjacentComponentList<Component>> adjComponentsListPtr;

    
    void _simplfyTwoLines(std::vector<int>& path1, std::vector<int>& path2); // driver

    float reduceSeriesResistors(std::vector<int> inputPath, std::vector<int>& path);
    // void reduceSeriesResistors(int CompIDS...) = delete;

    float reduceParallelResistors(int compID1, int compID2);

    void updateComponentValue(int compID, float newVal);

};


#endif