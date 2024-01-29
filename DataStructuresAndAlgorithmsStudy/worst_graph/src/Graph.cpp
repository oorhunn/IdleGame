
#include "../include/Graph.h"
#include <list>
#include <iostream>
#include <vector>

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
GraphList::GraphList(int size){
    adjacencyList.resize(size, LocalLinkedList<int>());
    listSize = size;
    indexCount = 0;
}

GraphList::~GraphList(){

}

void GraphList::addVertex(int source){
    LocalLinkedList<int> temp;
    adjacencyList[indexCount];
    ++indexCount;
}

void GraphList::addEdge(int source, int target){
    adjacencyList[source].append(target);
}


