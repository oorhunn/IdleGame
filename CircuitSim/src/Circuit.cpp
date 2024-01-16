#include "../include/Circuit.h"



Circuit::Circuit() :
    circuitSize(0)
{

}
Circuit::~Circuit(){

}



void Circuit::addComponent(Component& comp){
    // set component id
    components.resize(circuitSize + 1);
    componentIDHashMap.insert(std::make_pair(comp.getComponentName(), circuitSize));
    comp.setComponentID(componentIDHashMap[comp.getComponentName()]);
    ++circuitSize;
}


void Circuit::addWire(Component& target1, Component& target2) {
    components[target1.getComponentID()].push_back(target2);
}


void Circuit::findAllPaths(Component src, Component dest) {
    std::vector<bool> visited(circuitSize, false);
    std::vector<int> path;
    _findAllPaths(src.getComponentID(), dest.getComponentID(), visited, path);
}

void Circuit::_findAllPaths(int u, int dest, std::vector<bool>& visited, std::vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if (u == dest) {
        savePath(path);
    } else {
        for (const Component& v : components[u]) {
            if (!visited[v.getComponentID()]) {
                _findAllPaths(v.getComponentID(), dest, visited, path);
            }
        }
    }

    // backtrack
    visited[u] = false;
    path.pop_back();
}



void Circuit::savePath(const std::vector<int>& path) {
    allPaths.push_back(path);
}


void Circuit::isParallel(std::vector<int>& path1, std::vector<int>& path2) const {

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
    // need for delete element will come back 

}


void Circuit::parallelstuff() {
    isParallel(allPaths[0], allPaths[1]);
}

float Circuit::calculateSeriesResistor(int CompIDS...){
    float sum = 0;
    va_list args;
    va_start(args, CompIDS);

    for (int i = CompIDS; i != -1; i = va_arg(args, int)) {
        sum += i;
    }

    va_end(args);
    return sum;
}