#include <iostream>
#include <ostream>

#include "../include/WorstTreeBase.h"


template class WorstTreeBase<int, int>;

template <typename nodeElementType, typename nodeType>
inline void WorstTreeBase<nodeElementType, nodeType>::printTree()
{
    std::cout << "print tree from base tree \n";
}
