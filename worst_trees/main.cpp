#include <iostream>
#include "BinaryTree.h"
#include "TreeBase.h"
#include "LeafBase.h"


int main() {

    BinaryTree<int> myTree;
    myTree.insert(1);
    myTree.insert(2);

    myTree.insert(9);
    myTree.printTree();



    return 0;
}