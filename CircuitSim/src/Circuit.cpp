#include "../include/Circuit.h"



Circuit::Circuit() :
    circuitSize(0)
{

}
Circuit::~Circuit(){

}



void Circuit::addComponent(Component comp){
    // set component id
    components.resize(circuitSize + 1);
    componentIDHashMap.insert(std::make_pair(comp.getComponentName(), circuitSize));
    comp.setComponentID(componentIDHashMap[comp.getComponentName()]);
    ++circuitSize;
}


void Circuit::addWire(Component target1, Component target2) {
    components[target1.getComponentID()].push_back(target2);
}

void Circuit::findAllPaths(int src, int dest) {
    std::vector<bool> visited(circuitSize, false);
    std::vector<int> path;
    _findAllPaths(src, dest, visited, path);
}


void Circuit::_findAllPaths(int u, int dest, std::vector<bool>& visited, std::vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if (u == dest) {
        // Print or process the path
        printPath(path);
    } else {
        for (const Component& v : components[u]) {
            if (!visited[v.getComponentID()]) {
                _findAllPaths(v.getComponentID(), dest, visited, path);
            }
        }
    }

    // Backtrack
    visited[u] = false;
    path.pop_back();
}

void Circuit::printPath(const std::vector<int>& path) {
    std::cout << "Path: ";
    for (int vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}