template<typename nodeType>
struct BinaryNode{
    nodeType element;
    // nodeType isLessThan;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(const nodeType& newElement, BinaryNode* lt, BinaryNode* rt) :
        element{newElement}, left{lt}, right{rt} {}

    BinaryNode(nodeType&& newElement, BinaryNode* lt, BinaryNode* rt) :
        element{std::move(newElement)}, left{lt}, right{rt} {}
};


template<typename nodeType>
struct AVLNode{
    nodeType element;
    int height;
    AVLNode* left;
    AVLNode* right;
    AVLNode(const nodeType& newElement,
            AVLNode* lt, AVLNode* rt,
            int h) :
        element{newElement}, left{lt}, right{rt},
        height{h} {}
    AVLNode(nodeType&& newElement, AVLNode* lt, AVLNode* rt,int h) :
        element{std::move(newElement)}, left{lt}, right{rt},
        height{h} {}
};

