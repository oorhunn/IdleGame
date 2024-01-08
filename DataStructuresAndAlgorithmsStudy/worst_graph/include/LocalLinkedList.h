#ifndef LOCALLINKEDLIST_H
#define LOCALLINKEDLIST_H

#include <memory>

template <typename nodeType>
class NodeBase {
public:
    nodeType data;
    std::shared_ptr<NodeBase<nodeType>> next;
    NodeBase() : next(nullptr) {};
    NodeBase(nodeType val): data(val), next(nullptr) {};
};


template <typename nodeType>
class LocalLinkedList : public NodeBase<nodeType> {
public:
    LocalLinkedList();
    ~LocalLinkedList();
    

    void append(nodeType val);
    void deleteNode(nodeType val);

private:
    std::shared_ptr<NodeBase<nodeType>> head;


};
#endif