#include "../include/WorstBinaryTree.h"
#include "WorstBinaryTree.h"
#include <iostream>
#include <sstream>

template class WorstBinaryTree<int>;


template <typename nodeType>
inline WorstBinaryTree<nodeType>::WorstBinaryTree() :
    root(nullptr)
{

}

template <typename nodeType>
WorstBinaryTree<nodeType>::~WorstBinaryTree()
{
    makeEmpty();
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::insert(const nodeType& x) {
    if (root == nullptr) {
        root = new BinaryNode{x, nullptr, nullptr};
        return;
    }
    _insert(x, root);
}


template <typename nodeType>
void WorstBinaryTree<nodeType>::_insert(const nodeType &x, BinaryNode *&t)
{
    if (t == nullptr){
        t = new BinaryNode{x, nullptr, nullptr};
        return;
    }
    else if (t->element > x) { 
        _insert(x, t->left);
    }
    else if(t->element < x){
        _insert(x, t->right);
    }
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::makeEmpty()
{
    _makeEmpty(root);
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::_makeEmpty(BinaryNode *&t)
{
    if (t == nullptr) {
        return;
    }

    _makeEmpty(t->left);
    _makeEmpty(t->right);

    delete t;
    t = nullptr;
}

template <typename nodeType>
std::ostringstream WorstBinaryTree<nodeType>::traversePreOrder()
{
    std::ostringstream str_stream;
    _traversePreOrder(str_stream, "", "", root);
    return str_stream;
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::_traversePreOrder(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, BinaryNode* t) {
    if (t != nullptr) {
        out_str << padding << pointer << t->element << "\n";

        std::string paddingForBoth = padding + "│  ";
        std::string pointerRight = "└──";
        std::string pointerLeft = (t->right != nullptr) ? "├──" : "└──";

        traverseNodes(out_str, paddingForBoth, pointerLeft, t->left, t->right != nullptr);
        traverseNodes(out_str, paddingForBoth, pointerRight, t->right, false);
    }
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::traverseNodes(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, BinaryNode* node, bool hasRightSibling) {
    if (node != nullptr) {
        out_str << "\n" << padding << pointer << node->element;

        std::string paddingBuilder = padding;
        if (hasRightSibling) {
            paddingBuilder += "│  ";
        } else {
            paddingBuilder += "   ";
        }

        std::string paddingForBoth = paddingBuilder;
        std::string pointerRight = "└──";
        std::string pointerLeft = (node->right != nullptr) ? "├──" : "└──";

        traverseNodes(out_str, paddingForBoth, pointerLeft, node->left, node->right != nullptr);
        traverseNodes(out_str, paddingForBoth, pointerRight, node->right, false);
    }
}

template <typename nodeType>
int WorstBinaryTree<nodeType>::getDepth()
{   
    if (root == nullptr){
        return 0;
    }
    int depth = _getDepth(0, root);
    return depth;
}

template <typename nodeType>
int WorstBinaryTree<nodeType>::_getDepth(int depth, BinaryNode *&t)
{
    if (t == nullptr) {
        return depth;
    }
    int rigth_depth = _getDepth(depth + 1, t->right);
    int left_depth = _getDepth(depth + 1, t->left);


    return std::max(rigth_depth, left_depth);
}

// template <typename nodeType>
// void WorstBinaryTree<nodeType>::printTree(std::ostream &out) const
// {
//     _printTree(root);
// }

// template <typename nodeType>
// void WorstBinaryTree<nodeType>::_printTree(BinaryNode *&t, int tabLength = 0, std::ostream &out)
// {
//     std::cout << "not implemented yet \n";
// }

template <typename nodeType>
inline bool WorstBinaryTree<nodeType>::contains(const nodeType &x) const
{
    return _contains(x, root);
}

template <typename nodeType>
inline bool WorstBinaryTree<nodeType>::_contains(const nodeType &x, BinaryNode *t) const
{
    if(t == nullptr) {
        return false;
    }
    else if (x < t->element){
        return _contains(x, t->left);
    }
    else if (x > t->element){
        return _contains(x, t->right);
    }
    return true;
}

