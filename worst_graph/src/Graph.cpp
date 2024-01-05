
#include "../include/Graph.h"
#include <list>
#include <iostream>
#include <vector>



Graph::Graph(int size) : matrixSize(size), columnCount(0)
{
    adjacencyMatrix.resize(size, std::vector<int>(size, -1));
}

Graph::~Graph()
{

}

void Graph::addVertex(std::string source){
    if (columnCount >= matrixSize){
        return;
    } 
    columnNames.insert(std::make_pair(source, columnCount));
    ++columnCount;
}

void Graph::addEdge(std::string source, std::string target){
    int i = columnNames[source];
    int j = columnNames[target];
    adjacencyMatrix[i][j] = 1;
}