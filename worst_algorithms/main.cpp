#include <iostream>
#include <sstream>
#include <vector>
#include <random>
#include <chrono>
// #include "WorstDoubleLinkedList.h"
#include "../include/WorstSearchAlgorithms.h"
std::vector<int> generateRandomVector(int length);


int main()
{
    std::vector<int> tobeosrtted = generateRandomVector(10000);

    WorstQuickSort<int> sorter;

    auto start_time = std::chrono::high_resolution_clock::now();

    sorter.quickSort(tobeosrtted);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << std::endl;
    std::vector<int> hell = generateRandomVector(10000);


    auto start_time2 = std::chrono::high_resolution_clock::now();

    insertionSort(hell);
    auto end_time2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time2 - start_time2);
  
    std::cout << "\n" <<duration.count() << "\n";
    std::cout << "\n" <<duration2.count() << "\n";

    return 0;
}


std::vector<int> generateRandomVector(int length) {
    // Seed for the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Distribution for integers (adjust range as needed)
    std::uniform_int_distribution<int> dist(1, 100);

    // Generate the random vector
    std::vector<int> randomVector;
    randomVector.reserve(length);

    for (int i = 0; i < length; ++i) {
        randomVector.push_back(dist(gen));
    }

    return randomVector;
}
