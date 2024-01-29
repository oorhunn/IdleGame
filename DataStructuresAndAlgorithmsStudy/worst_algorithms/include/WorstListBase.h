#pragma once
template<typename nodeType>
class DoubleNode {
public:
    nodeType data;
    class DoubleNode* next;
    class DoubleNode* prev;
    DoubleNode() : next(nullptr), prev(nullptr) {};
    DoubleNode(nodeType val) : data(val), next(nullptr), prev(this) {};


};


template <typename nodeType>
class NodeBase {
public:
    nodeType data;
    class NodeBase* next;
    NodeBase() : next(nullptr) {};
    NodeBase(nodeType val): data(val), next(nullptr) {};
};


template <typename nodeType>
class WorstListBase {
public:
    WorstListBase();  // constructor
    virtual ~WorstListBase();   // destructor


    virtual void worstAppend(nodeType val) = 0;
    virtual void worstDeleteNode(nodeType val) = 0;


    virtual void worstDisplay();
    virtual void worstInsertAfter();


protected:
    NodeBase<nodeType>* head;
};

