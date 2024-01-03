#include <iostream>
#include <vector>
#include "BinaryHeap.h"
template class BinaryHeap<int>;

int main() 
{

    std::vector<int> baban;
    for (int i = 10; i > 0; --i){
        baban.push_back(i);
    }
    BinaryHeap<int> hell(baban);
    hell.heapSort();
    // hell.insert(9);
    // hell.insert(10);




    return 0;
}


