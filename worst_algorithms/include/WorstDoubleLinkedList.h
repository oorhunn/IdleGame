


template<typename nodeType>
class DoubleNode {
public:
    nodeType data;
    class DoubleNode* next;
    class DoubleNode* prev;
    DoubleNode() : next(nullptr), prev(nullptr) {};
    DoubleNode(nodeType val) : data(val), next(nullptr), prev(this) {} ;
};

template<typename nodeType>
class WorstDoubleLinkedList : public DoubleNode<nodeType>{
public:
    WorstDoubleLinkedList();
    ~WorstDoubleLinkedList();

    void worstAppend(nodeType val);
    void worstDisplay();
private:
    DoubleNode<nodeType>* head;
};

