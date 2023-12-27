#include <iostream>
#include <thread>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "TreeBase.h"
#include "LeafBase.h"


int main() {

    AVLTree<int> myTree;

    for (int count = 10; 0 < count; --count){
        myTree.insert(count);
        myTree.printTree();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("cls"); // for Unix-based systems

    }

    std::cout << "done \n";
    return 0;
}