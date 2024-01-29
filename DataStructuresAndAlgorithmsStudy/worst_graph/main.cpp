

#include<iostream>
#include "../include/Graph.h"
// #include "../include/LocalLinkedList.h"


int main(){

    GraphList hell;

    hell.addVertex(0);
    hell.addVertex(1);
    hell.addVertex(2);
    hell.addVertex(3);
    hell.addVertex(4);

    hell.addEdge(0, 3);
    hell.addEdge(0, 1);


    return 0;
}

