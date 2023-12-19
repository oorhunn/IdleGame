#include "../include/WorstLinkedList.h"
#include <iostream>
template class WorstLinkedList<int>;




template <typename nodeType>
inline WorstLinkedList<nodeType>::WorstLinkedList() :
    head(nullptr)
{
}

template <typename nodeType>
WorstLinkedList<nodeType>::~WorstLinkedList()
{
    Node<nodeType>* current = head;
    Node<nodeType>* next;
    while (current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <typename nodeType>
void WorstLinkedList<nodeType>::worstAppend(nodeType val)
{
    Node<nodeType>* newNode = new Node<nodeType>(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node<nodeType>* current = head;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
}

template <typename nodeType>
void WorstLinkedList<nodeType>::worstDisplay()
{
    Node<nodeType>* current = head;
    while(current){
        std::cout << current->data << " \n"; 
        current = current->next;
    }
}

template <typename nodeType>
void WorstLinkedList<nodeType>::worstDeleteNode(nodeType node)
{
    if(!head){
        return;
    }
    if (head->data == node) {
        Node<nodeType>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node<nodeType>* current = head;
    Node<nodeType>* prev = nullptr;

    while (current && current->data != node) {
        prev = current;
        current = current->next;
    }
    if (current) {
        prev->next = current->next;
        delete current;
    }
}
