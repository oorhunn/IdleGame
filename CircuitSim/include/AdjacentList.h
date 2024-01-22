#ifndef ADJACENTLIST_H
#define ADJACENTLIST_H
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <memory>
#include "Components.h"

using ComponentHashMap = std::unordered_map<std::string, int>;

template <typename T>
using AdjacentComponentList = std::vector<std::list<std::shared_ptr<T>>>;
using ComponentsCatalogHashMap = std::unordered_map<int, std::shared_ptr<Component>>;


class CircuitPathObserver;
class ComponentCatalogObserver;
// subject class for paths and components
template <typename T>
class AdjacentList{
public:
    AdjacentList();
    ~AdjacentList();

    void findAllPaths(std::shared_ptr<T> src, std::shared_ptr<T> dest); // driver
    std::vector<std::vector<int>> getAllPaths();

    void addVertex(std::shared_ptr<T> comp);
    void addEdge(std::shared_ptr<T> target1, std::shared_ptr<T> target2);

    int getListSize() const;

    // subject class for circuit loop functions start
    void registerPathObserver(std::shared_ptr<CircuitPathObserver> observer);
    void removeObserver(std::shared_ptr<CircuitPathObserver> observer);
    void notifyPathObservers();
    void updatePath(std::shared_ptr<std::vector<std::vector<int>>> loopPtr); 
    // subject class for circuit loop functions end

    // subject class for component catalog functions start
    void registerCatalogObserver(std::shared_ptr<ComponentCatalogObserver> observer);
    void removeObserver(std::shared_ptr<ComponentCatalogObserver> observer);
    void notifyCatalogObservers();
    void addNewComponent(std::shared_ptr<Component> newComp);
    // subject class for component catalog functions end


protected:

private:
    int listSize;
    std::vector<std::vector<int>> allPaths;
    AdjacentComponentList<T> adjComponentsList;
    ComponentHashMap componentIDHashMap;

    // subject class for circuit loop containers start
    std::vector<std::shared_ptr<CircuitPathObserver>> circuitPathObservers;
    std::shared_ptr<std::vector<std::vector<int>>> circuitLoopsPtr;
    // subject class for circuit loop containers end

    // subject class for component catalog containers start
    std::shared_ptr<ComponentsCatalogHashMap> componentCatalogPtr;
    std::vector<std::shared_ptr<ComponentCatalogObserver>> componentCatalogObservers;
    // subject class for component catalog containers end



    void _findAllPaths(int u, int dest, std::vector<bool>& visited, std::vector<int>& path);
    void savePath(const std::vector<int>& path);
};


class CircuitPathObserver { 
public:
    virtual void update(std::shared_ptr<std::vector<std::vector<int>>> newPtr) = 0;
    virtual ~CircuitPathObserver() = default;
};

class ComponentCatalogObserver { 
public:
    virtual void update(std::shared_ptr<ComponentsCatalogHashMap> newComponentCatalogPtr) = 0;
    virtual ~ComponentCatalogObserver() = default;
};

#endif