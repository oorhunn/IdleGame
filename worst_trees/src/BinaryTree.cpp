
#include "../include/BinaryTree.h"
#include "../include/LeafBase.h"  // You may need to adjust this include based on your project structure
#include <iostream>
#include "BinaryTree.h"


template class BinaryTree<int>;

template <typename nodeElementType>
BinaryTree<nodeElementType>::BinaryTree() 
{

}

template <typename nodeElementType>
BinaryTree<nodeElementType>::~BinaryTree()
{
    flushTree();
}

template <typename nodeElementType>
void BinaryTree<nodeElementType>::flushTree()
{
    _flushTree(this->root);
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

template <typename nodeElementType>
void BinaryTree<nodeElementType>::print() const
{
    std::cout << "Binary tree print not implemented \n";
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
            return nullptr;
        }
        // Case 2: One child (right)
        else if (!left_exists && right_exists)
        {
            BinaryNode<nodeElementType> *temp = currentNode->right;
            delete currentNode;
            return temp;
        }
        // Case 2: One child (left)
        else if (!right_exists && left_exists)
        {
            BinaryNode<nodeElementType> *temp = currentNode->left;
            delete currentNode;
            return temp;
        }
        // Case 3: Two children
        else
        {
            // BinaryNode<nodeElementType> *temp = _findMin(currentNode->right);
            BinaryNode<nodeElementType> *temp = nullptr;

            currentNode->element = temp->element;
            currentNode->right = _remove(temp->element, currentNode->right);
        }
    }
    return currentNode;
}

