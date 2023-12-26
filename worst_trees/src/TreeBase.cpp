#include <iostream>
#include <ostream>

#include "../include/TreeBase.h"
#include "../include/LeafBase.h"


template class TreeBase<int, BinaryNode>;
template class TreeBase<int, AVLNode>;


template<typename nodeElementType, template<typename> class nodeType>
void TreeBase<nodeElementType, nodeType>::insert(const nodeElementType& value){
    _insert(value, root);
}

template<typename nodeElementType, template<typename> class nodeType>
void TreeBase<nodeElementType, nodeType>::remove(const nodeElementType& value) {
    _remove(value, root);
}

template<typename nodeElementType, template<typename> class nodeType>
bool TreeBase<nodeElementType, nodeType>::search(const nodeElementType& value) const {
    return _search(value, root);
}


template <typename nodeElementType, template <typename> class nodeType>
bool TreeBase<nodeElementType, nodeType>::_search(const nodeElementType &value, const nodeType<nodeElementType> *currentNode) const
{
    if(currentNode == nullptr) {
        return false;
    }
    else if (value < currentNode->element){
        return _search(value, currentNode->left);
    }
    else if (value > currentNode->element){
        return _search(value, currentNode->right);
    }
    return true;
}
template <typename nodeElementType, template <typename> class nodeType>
nodeElementType TreeBase<nodeElementType, nodeType>::findMin(){
    if (root == nullptr){
        return nodeElementType();
    }
    nodeType<nodeElementType>* minNode = _findMin(root);
    return nodeElementType(minNode->element);
}

template <typename nodeElementType, template <typename> class nodeType>
nodeType<nodeElementType>* TreeBase<nodeElementType, nodeType>::_findMin(nodeType<nodeElementType>*& currentNode)
{
    if (currentNode == nullptr) {
        return nullptr; 
    }

    while (currentNode->left != nullptr) {
        currentNode = currentNode->left;
    }

    return currentNode;
}
