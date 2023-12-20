#pragma once  // Include guard to prevent multiple inclusions

#include "WorstListBase.h"



template<typename nodeType>
class WorstDoubleLinkedList : public WorstListBase<nodeType>, public DoubleNode<nodeType> {
public:
    WorstDoubleLinkedList();
    ~WorstDoubleLinkedList();

    virtual void worstAppend(nodeType val) override;
    virtual void worstDeleteNode(nodeType val) override;
private:
    DoubleNode<nodeType>* head;
};
