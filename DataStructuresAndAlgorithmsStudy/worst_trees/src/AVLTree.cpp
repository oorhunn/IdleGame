

#include "../include/AVLTree.h"
#include "../include/LeafBase.h"
#include <iostream>
#include "AVLTree.h"

template class AVLTree<int>;

template <typename nodeElementType>
AVLTree<nodeElementType>::AVLTree()
{
}

template <typename nodeElementType>
AVLTree<nodeElementType>::~AVLTree()
{
    if (this->root == nullptr) {
        return;
    }
    flushAVLTree();
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::insert(const nodeElementType &value)
{
    _insert(value, this->root);
    balance(this->root);
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::flushAVLTree()
{
    _flushAVLTree(this->root->right);
    _flushAVLTree(this->root->left);
    delete this-> root;
    this->root = nullptr;
    return;

}

template <typename nodeElementType>
int AVLTree<nodeElementType>::height(AVLNode<nodeElementType> *currentNode) const
{
    return currentNode == nullptr ? -1 : currentNode->height;
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::_flushAVLTree(AVLNode<nodeElementType> *currentNode)
{
    if (currentNode == nullptr) {
        return;
    }

    _flushAVLTree(currentNode->left);
    _flushAVLTree(currentNode->right);

    delete currentNode;
    currentNode = nullptr;

}

template <typename nodeElementType>
void AVLTree<nodeElementType>::balance(AVLNode<nodeElementType> *&currentNode)
{
    if (currentNode == nullptr) {
        return;
    }
    if (height(currentNode->left) - height(currentNode->right) > ALLOWED_IMBALANCE) {
        if (height(currentNode->left->left) >= height(currentNode->left->right)){
            rotateWithLeftChild(currentNode);
        } else {
            doubleWithLeftChild(currentNode);
        }
    } else {
        if (height(currentNode->right) - height(currentNode->left) > ALLOWED_IMBALANCE){
            if (height(currentNode->right->right) >= height(currentNode->right->left)) {
                rotateWithRightChild(currentNode);
            } else {
                doubleWithRightChild(currentNode);
            }
        }
    }
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::rotateWithLeftChild(AVLNode<nodeElementType> *&currentNode)
{
    AVLNode<nodeElementType>* k1 = currentNode->left;
    currentNode->left = k1->right;
    k1->right = currentNode;
    currentNode->height = std::max(height(currentNode->left), height(currentNode->right)) + 1;
    k1->height = std::max(height(k1->left), currentNode->height) + 1;
    currentNode = k1;
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::doubleWithLeftChild(AVLNode<nodeElementType> *&currentNode)
{
    rotateWithRightChild(currentNode->left);
    rotateWithLeftChild(currentNode);
}
template <typename nodeElementType>
void AVLTree<nodeElementType>::rotateWithRightChild(AVLNode<nodeElementType> *&currentNode)
{
    AVLNode<nodeElementType>* k1 = currentNode->right;
    currentNode->right = k1->left;
    k1->left = currentNode;
    currentNode->height = std::max(height(currentNode->left), height(currentNode->right)) + 1;
    k1->height = std::max(height(k1->right), currentNode->height) + 1;
    currentNode = k1;
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::doubleWithRightChild(AVLNode<nodeElementType> *&currentNode)
{
    rotateWithLeftChild(currentNode->right);
    rotateWithRightChild(currentNode);
}

template <typename nodeElementType>
AVLNode<nodeElementType> *AVLTree<nodeElementType>::_remove(const nodeElementType &value, AVLNode<nodeElementType> *&currentNode)
{
    if (currentNode == nullptr) {
        return nullptr;
    } 
    if (value < currentNode->element){
        currentNode->left = _remove(value, currentNode->left);
    } else if (value > currentNode->element) { 
        currentNode->right = _remove(value, currentNode->right);
    } else if (currentNode->left != nullptr && currentNode->right != nullptr) {
        currentNode->element = this->_findMin(currentNode->right)->element;
        currentNode->right = _remove(currentNode->element, currentNode->right);
    } else {
        AVLNode<nodeElementType>* oldNode = currentNode;
        currentNode = (currentNode->left != nullptr) ? currentNode->left : currentNode->right;
        delete oldNode;
        oldNode = nullptr;
    }

    balance(currentNode);
    return nullptr;
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::_insert(const nodeElementType &value, AVLNode<nodeElementType> *&currentNode)
{
    if (currentNode == nullptr) {
        currentNode = new AVLNode<nodeElementType>{value, nullptr, nullptr};
    }
    else if (value < currentNode->element) {
        _insert(value, currentNode->left, currentNode->height);
    }
    else if (value > currentNode->element) {
        _insert(value, currentNode->right, currentNode->height);
    }
    balance(currentNode);
}

template <typename nodeElementType>
void AVLTree<nodeElementType>::_insert(const nodeElementType &value, AVLNode<nodeElementType> *&currentNode, int height)
{
    if (currentNode == nullptr) {
        currentNode = new AVLNode<nodeElementType>{value, nullptr, nullptr, height};
    } else if (value < currentNode->element) {
        _insert(value, currentNode->left, currentNode->height + 1);
    }
    else if (value > currentNode->element) {
        _insert(value, currentNode->right, currentNode->height + 1);
    }
    balance(currentNode);
}