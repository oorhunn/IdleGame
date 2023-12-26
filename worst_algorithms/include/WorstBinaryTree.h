#pragma once
#ifndef WORST_BINARY_TREE_H
#define WORST_BINARY_TREE_H
#include <iostream>
#include <vector>


template <typename nodeElementType>
class WorstBinaryTree {
public:
    WorstBinaryTree(); 
    ~WorstBinaryTree();
    WorstBinaryTree(const WorstBinaryTree& rhs);
    WorstBinaryTree(WorstBinaryTree&& rhs);
    WorstBinaryTree& operator=(const WorstBinaryTree& rhs);
    WorstBinaryTree& operator=(WorstBinaryTree&& rhs);

    
    // const BinaryNode* findMax() const;
    void printTree(std::ostream& out = std::cout) const;
    void insert(const nodeElementType& x);
    void makeEmpty();
    bool deleteElement(const nodeElementType& x);

    nodeElementType findMin();
    std::ostringstream traversePreOrder() const;
    int getDepth();
    bool contains(const nodeElementType& x) const;

private:
    struct BinaryNode{
        nodeElementType element;
        // nodeElementType isLessThan;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode(const nodeElementType& newElement, BinaryNode* lt, BinaryNode* rt) :
            element{newElement}, left{lt}, right{rt} {}

        BinaryNode(nodeElementType&& newElement, BinaryNode* lt, BinaryNode* rt) :
            element{std::move(newElement)}, left{lt}, right{rt} {}
    };

    BinaryNode* root;
    
    // const BinaryNode* _findMax(BinaryNode*& t);
    BinaryNode* _findMin(BinaryNode*& t);
    BinaryNode* _deleteElement(const nodeElementType& x, BinaryNode*& t);
    BinaryNode* _clone(BinaryNode* t) const;

    int _getDepth(int depth, BinaryNode*& t);
    void _insert(const nodeElementType& x, BinaryNode*& t);
    void _makeEmpty(BinaryNode*& t);
    bool _contains(const nodeElementType& x, BinaryNode* t ) const;
    void traverseNodes(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, BinaryNode* node, bool hasRightSibling) const;


};

#endif // WORST_BINARY_TREE_H
