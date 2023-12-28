#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "TreeBase.h"
#include "LeafBase.h"


#include <chrono>
#include <iostream>
#include <thread>
 
void independentThread() 
{
    std::cout << "Starting concurrent thread.\n";
    while (1){
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout << "Exiting concurrent thread.\n";
}
 
void threadCaller() 
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}
 
int main() 
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}