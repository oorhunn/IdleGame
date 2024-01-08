
#include "../include/WorstDoubleLinkedList.h"
#include <iostream>


template class WorstDoubleLinkedList<int>;



template <typename nodeType>
inline WorstDoubleLinkedList<nodeType>::WorstDoubleLinkedList() :
    head(nullptr)
{
    std::cout << "WorstDoubleLinkedList constructor here \n";

}

template <typename nodeType>
WorstDoubleLinkedList<nodeType>::~WorstDoubleLinkedList()
{
    std::cout << "WorstDoubleLinkedList destructor here \n";

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
void WorstDoubleLinkedList<nodeType>::worstDeleteNode(nodeType val)
{
    if(!this->head){
        return;
    }
    if (this->head->data == val) {
        DoubleNode<nodeType>* temp = this->head;
        this->head = this->head->next;
        delete temp;
        return;
    }
    DoubleNode<nodeType>* current = this->head;
    DoubleNode<nodeType>* prev = nullptr;

    while (current && current->data != val) {
        prev = current;
        current = current->next;
    }
    if (current) {
        prev->next = current->next;
        delete current;
    }
}