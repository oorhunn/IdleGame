#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "TreeBase.h"
#include "LeafBase.h"


int main() {

    AVLTree<int> myTree;

    for (int count = 5; 0 < count; --count){
        myTree.insert(count);
    }
    myTree.flushAVLTree();

    return 0;
}