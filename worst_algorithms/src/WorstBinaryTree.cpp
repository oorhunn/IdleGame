#include <iostream>
#include <sstream>
#include "../include/WorstBinaryTree.h"
#include "WorstBinaryTree.h"

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
std::ostringstream WorstBinaryTree<nodeType>::traversePreOrder() const
{
    std::ostringstream str_stream;
    _traversePreOrder(str_stream, "", "", root);
    return str_stream;
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::_traversePreOrder(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, BinaryNode* t) const {
    if (t != nullptr) {
        out_str << padding << pointer << t->element << "\n";

        std::string paddingForBoth = padding + "│  ";
        std::string pointerRight = "└──";
        std::string pointerLeft = (t->right != nullptr) ? "├──" : "└──";

        _traversePreOrder(out_str, paddingForBoth, pointerLeft, t->left);
        _traversePreOrder(out_str, paddingForBoth, pointerRight, t->right);
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

template <typename nodeType>
void WorstBinaryTree<nodeType>::printTree(std::ostream &out) const
{
    std::ostringstream str_stream = traversePreOrder(); // Assuming traversePreOrder returns std::ostringstream
    out << str_stream.str();
}

template <typename nodeType>
bool WorstBinaryTree<nodeType>::deleteElement(const nodeType& x)
{
    if (root == nullptr) {
        return false;
    }
    else if (contains(x) == false) {
        return false;
    }
    _deleteElement(x, root);
    return true;
}
template <typename nodeType>
typename WorstBinaryTree<nodeType>::BinaryNode* WorstBinaryTree<nodeType>::_deleteElement(const nodeType &x, BinaryNode *&t)
{
    // move until the node
    if (x < t->element){
        t->left = _deleteElement(x, t->left);
    }
    else if (x > t->element){
        t->right = _deleteElement(x, t->right);
    }
    // found the node

    // case 1: no children
    else {
        bool left_exists = t->left != nullptr;
        bool right_exists = t->right != nullptr;
        // case 1 no child 
        if (!left_exists && !right_exists){
            delete t;
            return nullptr;
        }
        // case 2: one child
        else if (!left_exists && right_exists){
            BinaryNode* temp = t->right;
            delete t;
            return temp;
        }
        // case 2: one child
        else if (!right_exists && left_exists){
            BinaryNode* temp = t->left;
            delete t;
            return temp;
        }
        // case 3: two children
        else {
            BinaryNode* temp = _findMin(t->right);
            t->element = temp->element;
            t->right = _deleteElement(temp->element, t->right);
        
        }
    }
    return t;
}
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

template <typename nodeType>
nodeType WorstBinaryTree<nodeType>::findMin()  {
    if (root == nullptr) {
        return nodeType();
    }
    BinaryNode* minNode = _findMin(root);
    return minNode->element;
}

template<typename nodeType>
typename WorstBinaryTree<nodeType>::BinaryNode* WorstBinaryTree<nodeType>::_findMin(BinaryNode*& t) 
{
    if (t == nullptr) {
        return nullptr;
    }
    else if (t->left == nullptr) {
        return t;
    }
    return _findMin(t->left);
}