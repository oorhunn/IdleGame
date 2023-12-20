#pragma once
#include <iostream>

template <typename nodeType>
class WorstBinaryTree{
public:
    WorstBinaryTree();
    ~WorstBinaryTree();
    WorstBinaryTree(const WorstBinaryTree& rhs);
    WorstBinaryTree(WorstBinaryTree&& rhs);
    WorstBinaryTree& operator=(const WorstBinaryTree& rhs);
    WorstBinaryTree& operator=(WorstBinaryTree&& rhs);


    const nodeType& findMin() const;
    const nodeType& findMax() const;
    bool contains(const nodeType& x) const;
    bool isEmpty() const;
    void printTree(std::ostream& out = std::cout) const;

    void makeEmpty();
    void insert(const nodeType& x);
    void insert(nodeType&& x);
    void remove(const nodeType& x);


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
    void insert(const nodeType & x, BinaryNode * & t );
    void insert(nodeType && x, BinaryNode * & t );
    void remove(const nodeType & x, BinaryNode * & t );
    BinaryNode * findMin(BinaryNode *t ) const;
    BinaryNode * findMax(BinaryNode *t ) const;
    bool contains(const nodeType & x, BinaryNode *t ) const;
    void makeEmpty(BinaryNode * & t );
    void printTree(BinaryNode *t, std::ostream& out ) const;
    BinaryNode * clone(BinaryNode *t ) const;
};

