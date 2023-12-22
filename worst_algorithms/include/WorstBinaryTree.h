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
    void printTree(std::ostream& out = std::cout) const;

    
    
    void insert(const nodeType& x);
    void makeEmpty();
    

    std::ostringstream traversePreOrder();
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
    bool _contains(const nodeType& x, BinaryNode* t ) const;
    void _traversePreOrder(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, BinaryNode* t);
    void traverseNodes(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, BinaryNode* node, bool hasRightSibling);
    // void WorstBinaryTree<nodeType>::_traversePreOrder(std::string& out_str, std::string padding, std::string pointer, BinaryNode*& t)

};

