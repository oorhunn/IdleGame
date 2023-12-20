#pragma once
#include "WorstListBase.h"

template <typename nodeType>
class WorstLinkedList : public WorstListBase<nodeType>, public NodeBase<nodeType> {
public:
    WorstLinkedList();
    ~WorstLinkedList();
    

    virtual void worstAppend(nodeType val) override;
    virtual void worstDeleteNode(nodeType val) override;

};

