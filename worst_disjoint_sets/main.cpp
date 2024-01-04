

#include "../include/DisjSets.h"
#include <iostream>

int main() {
    // Create a Disjoint Set with 5 elements
    DisjSets disjointSets(5);


    // Perform union operation to merge sets
    disjointSets.unionSets(0, 1);
    disjointSets.unionSets(2, 3);
    disjointSets.unionSets(0, 4);

    // Find representatives after union operations

    return 0;
}
