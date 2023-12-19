#include "WorstBasicDataStructures.h"

template <typename nodeType>
class Node {
public:
    nodeType data;
    class Node* next;
    Node() : next(nullptr) {};
    Node(nodeType val): data(val), next(nullptr) {};
};

template <typename nodeType>
class WorstLinkedList : public WorstBasicDataStructures, public Node<nodeType> {
public:
    WorstLinkedList();
    ~WorstLinkedList();
    

    void worstAppend(nodeType val);
    void worstDisplay();
    void worstDeleteNode(nodeType node);
    void worstInsertafter();

private:
    Node<nodeType>* head;
};

