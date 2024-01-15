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


class Circuit {
public:
    Circuit();
    ~Circuit();

    void addWire(Component target1, Component target2);
    void addComponent(Component comp);

    void findAllPaths(int src, int dest);

private:

    int circuitSize;
    std::vector<std::list<Component>> components;
    std::unordered_map<std::string, int> componentIDHashMap;

    void _findAllPaths(int u, int dest, std::vector<bool>& visited, std::vector<int>& path);
    void printPath(const std::vector<int>& path);

};

#endif // CIRCUIT_H
