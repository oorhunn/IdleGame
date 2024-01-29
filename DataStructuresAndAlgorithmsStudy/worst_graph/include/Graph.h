#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <string>
#include "LocalLinkedList.h"


class GraphMatr {
public:
    GraphMatr(int size = 5);
    ~GraphMatr();

    void addVertex(std::string source);
    void addEdge(std::string source, std::string target);

private:
    int matrixSize;
    int columnCount;
    std::unordered_map<std::string, int> columnNames;
    std::vector<std::vector<int>> adjacencyMatrix; 

};

class GraphList {
public:
    GraphList(int size = 5);
    ~GraphList();

    void addVertex(int source);
    void addEdge(int source, int target);

private:
    int listSize;
    int indexCount;
    std::vector<LocalLinkedList<int>> adjacencyList;

};

#endif