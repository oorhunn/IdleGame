#include "../include/AdjacentList.h"

template class AdjacentList<Component>;
template class AdjacentList<Resistor>;



template <typename T>
AdjacentList<T>::AdjacentList() :
    listSize(),   
    adjComponentsList(),
    allPaths(),
    componentIDHashMap(),
    circuitPathObservers(),
    circuitLoopsPtr(nullptr)
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
    addNewComponent(comp);
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
    updatePath(std::make_shared<std::vector<std::vector<int>>>(allPaths));
}


template <typename T>
std::vector<std::vector<int>> AdjacentList<T>::getAllPaths(){
    return allPaths;
}

template <typename T>
int AdjacentList<T>::getListSize() const{
    return listSize;
}


template <typename T>
void AdjacentList<T>::registerPathObserver(std::shared_ptr<CircuitPathObserver> observer){    
    circuitPathObservers.push_back(observer);
}


template <typename T>
void AdjacentList<T>::removeObserver(std::shared_ptr<CircuitPathObserver> observer){
    for (auto it = circuitPathObservers.begin(); it != circuitPathObservers.end(); ) {
        if (*it == observer) {
            it = circuitPathObservers.erase(it);
            circuitPathObservers.resize(circuitPathObservers.size() - 1);
        } else {
            ++it;
        }
    }
}



template <typename T>
void AdjacentList<T>::notifyPathObservers() {
    for (const auto& observer : circuitPathObservers){
        observer->update(circuitLoopsPtr);
    }
}

template <typename T>
void AdjacentList<T>::updatePath(std::shared_ptr<std::vector<std::vector<int>>> loopPtr){
    if(!circuitLoopsPtr){
        circuitLoopsPtr = std::make_shared<std::vector<std::vector<int>>>();
    }
    circuitLoopsPtr = loopPtr;
    notifyPathObservers();
}



template <typename T>
void AdjacentList<T>::notifyCatalogObservers(){
    for (const auto& observer : componentCatalogObservers){
        observer->update(componentCatalogPtr);
    }
}

template <typename T>
void AdjacentList<T>::registerCatalogObserver(std::shared_ptr<ComponentCatalogObserver> observer){
    componentCatalogObservers.push_back(observer);
}


template <typename T>
void AdjacentList<T>::removeObserver(std::shared_ptr<ComponentCatalogObserver> observer){
    for (auto it = componentCatalogObservers.begin(); it != componentCatalogObservers.end(); ) {
        if (*it == observer) {
            it = componentCatalogObservers.erase(it);
            componentCatalogObservers.resize(componentCatalogObservers.size() - 1);
        } else {
            ++it;
        }
    }
}


template <typename T>
void AdjacentList<T>::addNewComponent(std::shared_ptr<Component> newComp){
    if (!componentCatalogPtr){
        componentCatalogPtr = std::make_shared<ComponentsCatalogHashMap>();
    }
    componentCatalogPtr->insert(std::make_pair(newComp->getComponentID(), newComp));
    notifyCatalogObservers();

}

