
#include "../include/BinaryTree.h"
#include "../include/LeafBase.h"  // You may need to adjust this include based on your project structure
#include <iostream>


template class BinaryTree<int>;

template <typename nodeElementType>
BinaryTree<nodeElementType>::BinaryTree() 
{

}

template <typename nodeElementType>
BinaryTree<nodeElementType>::~BinaryTree()
{
    if (this->root == nullptr) {
        return;
    }
    flushTree();
}

template <typename nodeElementType>
BinaryTree<nodeElementType>::BinaryTree(const BinaryTree &rhs)
{
    this->root = nullptr;
    this->root = _clone(rhs.root);
}
template <typename nodeElementType>
void BinaryTree<nodeElementType>::flushTree()
{
    if (this->root == nullptr) {
        return;
    }
    _flushTree(this->root->left);
    _flushTree(this->root->right);
    delete this->root;
    this->root = nullptr;

}
template <typename nodeElementType>
void BinaryTree<nodeElementType>::_insert(const nodeElementType &value, BinaryNode<nodeElementType>*& currentNode)
{
    if (currentNode == nullptr) {
        currentNode = new BinaryNode<nodeElementType>{value, nullptr, nullptr};
        return;
    } else if (currentNode->element > value) {
        _insert(value, currentNode->left);
    } else if (currentNode->element < value) {
        _insert(value, currentNode->right);
    }
}

template <typename nodeElementType>
BinaryNode<nodeElementType> *BinaryTree<nodeElementType>::_clone(BinaryNode<nodeElementType> *currentNode) const
{
    if(currentNode == nullptr){
        return nullptr;
    }
    return new BinaryNode(currentNode->element, _clone(currentNode->left), _clone(currentNode->right));
}

template <typename nodeElementType>
void BinaryTree<nodeElementType>::_flushTree(BinaryNode<nodeElementType> *currentNode)
{
    if (currentNode == nullptr) {
        return;
    }

    _flushTree(currentNode->left);
    _flushTree(currentNode->right);

    delete currentNode;
    currentNode = nullptr;
}


template<typename nodeElementType>
BinaryNode<nodeElementType>* BinaryTree<nodeElementType>::_remove(const nodeElementType& value, 
    BinaryNode<nodeElementType>*& currentNode)
{
    if (value < currentNode->element)
    {
        currentNode->left = _remove(value, currentNode->left);
    }
    else if (value > currentNode->element)
    {
        currentNode->right = _remove(value, currentNode->right);
    }
    // Found the node
    else
    {
        bool left_exists = currentNode->left != nullptr;
        bool right_exists = currentNode->right != nullptr;

        // Case 1: No children
        if (!left_exists && !right_exists)
        {
            delete currentNode;
            currentNode = nullptr;
            return nullptr;
        }
        // Case 2: One child (right)
        else if (!left_exists && right_exists)
        {
            BinaryNode<nodeElementType> *temp = currentNode->right;
            delete currentNode;
            currentNode = nullptr;
            return temp;
        }
        // Case 2: One child (left)
        else if (!right_exists && left_exists)
        {
            BinaryNode<nodeElementType> *temp = currentNode->left;
            delete currentNode;
            currentNode = nullptr;
            return temp;
        }
        // Case 3: Two children
        else
        {
            BinaryNode<nodeElementType> *temp = this->_findMin(currentNode->right);
            // BinaryNode<nodeElementType> *temp = nullptr;

            currentNode->element = temp->element;
            currentNode->right = _remove(temp->element, currentNode->right);
        }
    }
    return currentNode;
}
