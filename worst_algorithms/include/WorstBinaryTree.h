#pragma once
#include <iostream>
#include <vector>

template <typename nodeType>
class WorstBinaryTree{
public:
    WorstBinaryTree();
    ~WorstBinaryTree();
    WorstBinaryTree(const WorstBinaryTree& rhs);
    WorstBinaryTree(WorstBinaryTree&& rhs);
    WorstBinaryTree& operator=(const WorstBinaryTree& rhs);
    WorstBinaryTree& operator=(WorstBinaryTree&& rhs);

    bool contains(const nodeType& x) const;
    const nodeType& findMin() const;
    const nodeType& findMax() const;
    // void printTree(std::ostream& out = std::cout) const;

    
    
    void insert(const nodeType& x);
    void makeEmpty();
    

    std::string traversePreOrder();
    int getDepth();

private:
    struct BinaryNode{
        nodeType element;
        nodeType isLessThan;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode(const nodeType& newElement, BinaryNode* lt, BinaryNode* rt) :
            element{newElement}, left{lt}, right{rt} {}

        BinaryNode(nodeType&& newElement, BinaryNode* lt, BinaryNode* rt) :
            element{std::move(newElement)}, left{lt}, right{rt} {}
    };

    BinaryNode* root;
    int _getDepth(int depth, BinaryNode*& t);
    void _insert(const nodeType& x, BinaryNode*& t);
    void _makeEmpty(BinaryNode*& t);
    // void _printTree(BinaryNode*& t, int tabLength = 0, std::ostream& out = std::cout);
    bool _contains(const nodeType& x, BinaryNode* t ) const;
    void _traversePreOrder(std::string& out_str, std::string padding, std::string pointer, BinaryNode*& t);
    // void WorstBinaryTree<nodeType>::_traversePreOrder(std::string& out_str, std::string padding, std::string pointer, BinaryNode*& t)

};

