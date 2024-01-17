#include "../include/AdjacentList.h"

template class AdjacentList<Component>;



template <typename T>
AdjacentList<T>::AdjacentList() :
    listSize(0),
    adjComponentsList(),
    allPathsPtr(std::make_shared<std::vector<std::vector<int>>>(allPaths))
{
    
}
template <typename T>
AdjacentList<T>::~AdjacentList() {

}

template <typename T>
void AdjacentList<T>::addVertex(std::shared_ptr<T> comp) {
    adjComponentsList.resize(++listSize);
    componentIDHashMap.insert(std::make_pair(comp->getComponentName(), listSize));
    int newCompID = componentIDHashMap[comp->getComponentName()];
    comp->setComponentID(newCompID);
    
}

template <typename T>
void AdjacentList<T>::addEdge(std::shared_ptr<T> target1, std::shared_ptr<T> target2) {
    adjComponentsList[target1->getComponentID()].push_back(target2);
}


template <typename T>
void AdjacentList<T>::findAllPaths(std::shared_ptr<T> src, std::shared_ptr<T> dest) {
    std::vector<bool> visited(listSize, false);
    std::vector<int> path;
    _findAllPaths(src->getComponentID(), dest->getComponentID(), visited, path);
}

template <typename T>
void AdjacentList<T>::_findAllPaths(int u, int dest, std::vector<bool>& visited, std::vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if (u == dest) {
        savePath(path);
    } else {
        for (std::shared_ptr<T> v : adjComponentsList[u]) {
            if (!visited[v->getComponentID()]) {
                _findAllPaths(v->getComponentID(), dest, visited, path);
            }
        }
    }

    // backtrack
    visited[u] = false;
    path.pop_back();
}



template <typename T>
void AdjacentList<T>::savePath(const std::vector<int>& path) {
    allPaths.push_back(path);
}


template <typename T>
std::vector<std::vector<int>> AdjacentList<T>::getAllPaths(){
    return allPaths;
}

template <typename T>
int AdjacentList<T>::getListSize() const{
    return listSize;
}