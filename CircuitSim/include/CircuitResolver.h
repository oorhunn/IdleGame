#ifndef CIRCUITRESOLVER_H
#define CIRCUITRESOLVER_H
#include <vector>
#include <memory>

#include "AdjacentList.h"

class CircuitResolver {

public:
    CircuitResolver(std::vector<std::vector<int>> listPtr);
    ~CircuitResolver();

    void simplfyTwoLines(std::vector<int>& path1, std::vector<int>& path2); // driver

private:
    std::vector<std::vector<int>> circuitLoops;
    

};


// void Circuit::isParallel(std::vector<int>& path1, std::vector<int>& path2) const {

//     std::unordered_set<int> set1(path1.begin(), path1.end());
//     std::unordered_set<int> set2(path2.begin(), path2.end());

//     std::vector<int> result;
//     std::vector<int> result2;


//     for (int element : set1) {
//         if (set2.find(element) == set2.end()) {
//             result.push_back(element);
//         }
//     }

//     for (int element : set2) {
//         if (set1.find(element) == set1.end()) {
//             result2.push_back(element);
//         }
//     }
//     // need for delete element will come back 

// }

#endif