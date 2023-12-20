#include "../include/WorstBinaryTree.h"
#include "WorstBinaryTree.h"
template class WorstBinaryTree<int>;


template <typename nodeType>
inline WorstBinaryTree<nodeType>::WorstBinaryTree()
{
}

template <typename nodeType>
WorstBinaryTree<nodeType>::~WorstBinaryTree()
{
}
template <typename nodeType>
void WorstBinaryTree<nodeType>::insert(const nodeType& x) {
    insert(x, root);
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::insert(nodeType&& x) {
    insert(std::move(x), root);
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::insert(const nodeType& x, BinaryNode*& t) {
    if (t == nullptr)
        t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element) // Assuming a comparison function exists for nodeType
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    // else x already exists in the tree; do nothing
}

template <typename nodeType>
void WorstBinaryTree<nodeType>::insert(nodeType&& x, BinaryNode*& t) {
    if (t == nullptr)
        t = new BinaryNode{std::move(x), nullptr, nullptr};
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);
    // else x already exists in the tree; do nothing
}

// template <typename nodeType>
// const nodeType &WorstBinaryTree<nodeType>::findMin() const
// {
//     return 1;
// }

template <typename nodeType>
inline bool WorstBinaryTree<nodeType>::contains(const nodeType &x) const
{
    return contains(x, root);
}


template <typename nodeType>
void WorstBinaryTree<nodeType>::remove(const nodeType &x)
{
    remove(x, root);
}

template <typename nodeType>
inline bool WorstBinaryTree<nodeType>::contains(const nodeType &x, BinaryNode *t) const
{
    if(t == nullptr) {
        return false;
    }
    else if (x < t->element){
        return contains(x, t->left);
    }
    else if (x > t->element){
        return contains(x, t->right);
    }
    return true;
}