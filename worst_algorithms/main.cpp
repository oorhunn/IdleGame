#include <iostream>
#include <sstream>
#include <vector>
// #include "WorstDoubleLinkedList.h"
#include "../include/WorstSearchAlgorithms.h"



int main()
{
    std::vector tobeosrtted = {9, 5, 11, 14, 4, 18, 7, 21, 33, 1};


    for (auto i:tobeosrtted){
        std::cout << i << ", ";
    }

    mergeSort(tobeosrtted);
    std::cout << std::endl;
    for (auto i:tobeosrtted){
        std::cout << i << ", ";
    }

    return 0;
}


