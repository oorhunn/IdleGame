#include "../include/WorstListBase.h"
#include <iostream>
template class WorstListBase<int>;

template <typename nodeType>
inline WorstListBase<nodeType>::WorstListBase()
{
}

template <typename nodeType>
WorstListBase<nodeType>::~WorstListBase()
{   

}


template <typename nodeType>
void WorstListBase<nodeType>::worstDisplay()
{
    NodeBase<nodeType>* current = head;
    while(current){
        std::cout << current->data << " \n"; 
        current = current->next;
    }
}
template <typename nodeType>
void WorstListBase<nodeType>::worstInsertAfter()
{
    std::cout << "worst insert after not implemented yet \n";
}
