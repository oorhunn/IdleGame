#ifndef ADJACENTLIST_H
#define ADJACENTLIST_H
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <memory>

#include "CircuitPaths.h"
#include "Components.h"

using ComponentHashMap = std::unordered_map<std::string, int>;
template <typename T>
using AdjacentComponentList = std::vector<std::list<std::shared_ptr<T>>>;

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

    std::shared_ptr<std::vector<std::vector<int>>> getAllPathsPtr();
    std::shared_ptr<std::vector<std::list<std::shared_ptr<T>>>> getAdjacentListPtr();

protected:

private:
    int listSize;
    std::vector<std::vector<int>> allPaths;
    AdjacentComponentList<T> adjComponentsList;
    ComponentHashMap componentIDHashMap;
    std::shared_ptr<CircuitPath> circuitPathSubjectInstance;



    void _findAllPaths(int u, int dest, std::vector<bool>& visited, std::vector<int>& path);
    void savePath(const std::vector<int>& path);
};

#endif