#include <iostream>
#include "include/WorstDoubleLinkedList.h"
template class WorstDoubleLinkedList<int>;  // Instantiate with int


int main()
{

    WorstDoubleLinkedList<int> mymy = WorstDoubleLinkedList<int>();

    mymy.worstAppend(1);
    mymy.worstAppend(2);
    mymy.worstAppend(3);
    mymy.worstAppend(4);
    mymy.worstAppend(5);
    mymy.worstAppend(6);
    mymy.worstAppend(7);

    mymy.worstDisplay();
    return 0;
}