#include "../include/WorstBinaryTree.h"
#include "WorstBinaryTree.h"
#include <iostream>
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
std::string WorstBinaryTree<nodeType>::traversePreOrder()
{

    std::string tree_str; 
    _traversePreOrder(tree_str, "", "", root);
    return tree_str;
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::_traversePreOrder(std::string& out_str, std::string padding, std::string pointer, BinaryNode*& t)
{
    if (t != nullptr){
        out_str.append(padding);
        out_str.append(pointer);
        out_str.append(std::to_string(t->element));
        out_str.append("\n");


        std::string paddingBuilder.append("│  ");
        std::string pointerForRight.append("└──");
        std::string temp = (t->right != nullptr) ? "├──" : "└──";
        out_str.append(temp);
// https://www.baeldung.com/java-print-binary-tree-diagram
        _traversePreOrder(out_str, p, ,  t->left);
        _traversePreOrder(out_str, t->right);
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

