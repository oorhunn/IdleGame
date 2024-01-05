
#include "../include/Graph.h"
#include <list>
#include <iostream>
#include <vector>
template class GraphList<int>;

GraphMatr::GraphMatr(int size) : matrixSize(size), columnCount(0)
{
    adjacencyMatrix.resize(size, std::vector<int>(size, -1));
}

GraphMatr::~GraphMatr()
{

}

void GraphMatr::addVertex(std::string source){
    if (columnCount >= matrixSize){
        return;
    } 
    columnNames.insert(std::make_pair(source, columnCount));
    ++columnCount;
}

void GraphMatr::addEdge(std::string source, std::string target){
    int i = columnNames[source];
    int j = columnNames[target];
    adjacencyMatrix[i][j] = 1;
}
template <typename nodeType>
GraphList<nodeType>::GraphList(int size){
    adjacencyList.resize(size, LocalLinkedList<nodeType>);
}