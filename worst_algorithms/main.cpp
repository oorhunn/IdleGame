#include <iostream>
#include <sstream>
#include "WorstBinaryTree.h"

// #include "WorstDoubleLinkedList.h"



template class WorstBinaryTree<int>;

int main()
{
    WorstBinaryTree<int> myTree;
    myTree.insert(6);
    myTree.insert(2);
    myTree.insert(8);
    myTree.insert(1);
    myTree.insert(4);
    myTree.insert(3);
    myTree.insert(5);
    myTree.insert(9);

    myTree.printTree();

    myTree.deleteElement(9);
    myTree.printTree();

    return 0;
}


