#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <string>
#include <vector>
#include "Components.h"
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <list>
#include <map>
#include <cstdarg>



class Circuit {
public:
    Circuit();
    ~Circuit();

    void addWire(Component& target1, Component& target2);
    void addComponent(Component& comp);
    void removeComponent(Component& comp);
    void removeWires(Component& target1, Component& target2);


    void findAllPaths(Component src, Component dest); // driver

    void parallelstuff();// driver

private:
    // variables and containers start
    int circuitSize;
    std::vector<std::list<Component>> components;
    std::unordered_map<std::string, int> componentIDHashMap;
    std::vector<std::vector<int>> allPaths;
    // variables and containers end

    float calculateSeriesResistor(int compIDS...);
    
    
    void isParallel(std::vector<int>& path1, std::vector<int>& path2) const;
    
    void _findAllPaths(int u, int dest, std::vector<bool>& visited, std::vector<int>& path);
    void savePath(const std::vector<int>& path);

};

#endif // CIRCUIT_H
