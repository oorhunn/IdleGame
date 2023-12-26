#include <iostream>
#include <ostream>
#include <sstream>

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
void TreeBase<nodeElementType, nodeType>::traverseNodes(std::ostringstream &out_str, const std::string &padding, const std::string &pointer, nodeType<nodeElementType> *node, bool hasRightSibling) const
{
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

template <typename nodeElementType,  template <typename> class nodeType>
void TreeBase<nodeElementType, nodeType>::printTree(std::ostream &out) const
{
    std::ostringstream str_stream = traversePreOrder(); 
    out << str_stream.str();
}

template <typename nodeElementType,  template <typename> class nodeType>
std::ostringstream TreeBase<nodeElementType, nodeType>::traversePreOrder() const
{
    std::ostringstream str_stream;
    traverseNodes(str_stream, "", "", root, (root != nullptr) && (root->right != nullptr));
    return str_stream;
}

template <typename nodeElementType, template <typename> class nodeType>
nodeType<nodeElementType> *TreeBase<nodeElementType, nodeType>::_findMin(nodeType<nodeElementType> *&currentNode)
{
    if (currentNode == nullptr) {
        return nullptr; 
    }

    while (currentNode->left != nullptr) {
        currentNode = currentNode->left;
    }

    return currentNode;
}
