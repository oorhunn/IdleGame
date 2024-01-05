#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <string>

class Graph {


public:
    Graph(int size = 5);
    ~Graph();

    void addVertex(std::string source);
    void addEdge(std::string source, std::string target);


private:
    int matrixSize;
    int columnCount;
    std::unordered_map<std::string, int> columnNames;
    std::vector<std::vector<int>> adjacencyMatrix; 


};

#endif