#include <iostream>
#include "WorstBinaryTree.h"
// #include "WorstDoubleLinkedList.h"




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


    // std::string to_print = myTree.traversePreOrder();
    // std::cout << to_print << "\n";

    return 0;
}


