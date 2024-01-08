#include "../include/WorstLinkedList.h"
#include <iostream>
template class WorstLinkedList<int>;

template <typename nodeType>
inline WorstLinkedList<nodeType>::WorstLinkedList() 
{
    this->head = nullptr;
}

template <typename nodeType>
WorstLinkedList<nodeType>::~WorstLinkedList()
{   
    NodeBase<nodeType>* current = this->head;
    NodeBase<nodeType>* next;
    while (current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    this->head = nullptr;
}

template <typename nodeType>
void WorstLinkedList<nodeType>::worstAppend(nodeType val) {
    NodeBase<nodeType>* newNode = new NodeBase<nodeType>(val);
    if (!this->head) {
        this->head = newNode;
        return;
    }
    NodeBase<nodeType>* current = this->head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}


template <typename nodeType>
void WorstLinkedList<nodeType>::worstDeleteNode(nodeType val)
{
    if(!this->head){
        return;
    }
    if (this->head->data == val) {
        NodeBase<nodeType>* temp = this->head;
        this->head = this->head->next;
        delete temp;
        return;
    }
    NodeBase<nodeType>* current = this->head;
    NodeBase<nodeType>* prev = nullptr;

    while (current && current->data != val) {
        prev = current;
        current = current->next;
    }
    if (current) {
        prev->next = current->next;
        delete current;
    }
}
