#include <iostream>
#include <sstream>
#include <vector>
// #include "WorstDoubleLinkedList.h"
#include "../include/WorstSearchAlgorithms.h"



int main()
{
    std::vector tobeosrtted = {9, 5, 11, 14, 18, 21, 33};


    for (auto i:tobeosrtted){
        std::cout << i << ", ";
    }

    insertionSort(tobeosrtted);
    std::cout << std::endl;
    for (auto i:tobeosrtted){
        std::cout << i << ", ";
    }

    return 0;
}


