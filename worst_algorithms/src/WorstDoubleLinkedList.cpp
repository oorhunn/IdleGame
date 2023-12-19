#include "../include/WorstDoubleLinkedList.h"
#include <iostream>
template class WorstDoubleLinkedList<int>;



template <typename nodeType>
inline WorstDoubleLinkedList<nodeType>::WorstDoubleLinkedList() :
    head(nullptr)
{
}

template <typename nodeType>
WorstDoubleLinkedList<nodeType>::~WorstDoubleLinkedList()
{
    DoubleNode<nodeType>* current = head;
    DoubleNode<nodeType>* next;
    while (current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <typename nodeType>
void WorstDoubleLinkedList<nodeType>::worstAppend(nodeType val)
{
    DoubleNode<nodeType>* newNode = new DoubleNode<nodeType>(val);
    if(!head){
        head = newNode;
        head->prev = nullptr;
        return;
    }
    DoubleNode<nodeType>* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}
template <typename nodeType>
void WorstDoubleLinkedList<nodeType>::worstDisplay()
{
    DoubleNode<nodeType>* current = head;
    while(current){
        std::cout << current->data << " \n"; 
        current = current->next;
    }
}
