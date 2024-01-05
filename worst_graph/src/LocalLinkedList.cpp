
#include "../include/LocalLinkedList.h"
#include <memory>


template class LocalLinkedList<int>;
template class NodeBase<int>;

template <typename nodeType>
inline LocalLinkedList<nodeType>::LocalLinkedList() : head(nullptr)
{


}

template <typename nodeType>
LocalLinkedList<nodeType>::~LocalLinkedList(){
    
}

template <typename nodeType>
void LocalLinkedList<nodeType>::append(nodeType val) {
    if (!head) {
        head = std::make_shared<NodeBase<nodeType>>(val);
    } 
    else {
        std::shared_ptr<NodeBase<nodeType>> current = head;
        while (current->next){
            current = current->next;
        }
        current->next = std::make_shared<NodeBase<nodeType>>(val);;
    }
}

template <typename nodeType>
void LocalLinkedList<nodeType>::deleteNode(nodeType val) {
    if (!head) {
        return;
    }
    if (head->data == val) {
        head = head->next; 
        return;
    }

    std::shared_ptr<NodeBase<nodeType>> current = head;
    while (current->next && current->next->data != val) {
        current = current->next;
    }

    if (current->next) {
        current->next = current->next->next;
    }
}