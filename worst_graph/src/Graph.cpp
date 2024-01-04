
#include "../include/Graph.h"
#include <list>
#include <iostream>

Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new std::list<int>[vertices];
  visited = new bool[vertices];
}
// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

void Graph::DFS(int vertex) {
  visited[vertex] = true;
  std::list<int> adjList = adjLists[vertex];

  std::cout << vertex << " ";

  std::list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}