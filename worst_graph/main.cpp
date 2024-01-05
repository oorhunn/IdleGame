

#include<iostream>
// #include "../include/Graph.h"
#include "../include/LocalLinkedList.h"


int main(){

    LocalLinkedList<int> holla;

    
    holla.append(1);
    holla.append(2);
    holla.append(3);

    holla.deleteNode(2);


    return 0;
}

