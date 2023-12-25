#include "../include/WorstTreeBase.h"
#include <sstream>
#include <ostream>
#include "WorstTreeBase.h"


template <typename nodeElementType, typename nodeType>
WorstTreeBase<nodeElementType, nodeType>::WorstTreeBase()
{
}

template <typename nodeElementType, typename nodeType>
WorstTreeBase<nodeElementType, nodeType>::~WorstTreeBase()
{
}

template <typename nodeElementType, typename nodeType>
bool WorstTreeBase<nodeElementType, nodeType>::contains(const nodeElementType &x) const
{
    return _contains(x, root);
}

template <typename nodeElementType, typename nodeType>
inline bool WorstTreeBase<nodeElementType, nodeType>::_contains(const nodeElementType &x, nodeType* t) const {
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

template <typename nodeElementType, typename nodeType>
nodeElementType WorstTreeBase<nodeElementType, nodeType>::findMin() {
    if (root == nullptr) {
        return nodeElementType();
    }
    nodeType minNode = _findMin(root);
    return minNode->element;
}


template <typename nodeElementType, typename nodeType>
int WorstTreeBase<nodeElementType, nodeType>::getDepth() {
    if (root == nullptr){
        return 0;
    }
    int depth = _getDepth(0, root);
    return depth;
}

template <typename nodeElementType, typename nodeType>
inline int WorstTreeBase<nodeElementType, nodeType>::_getDepth(int depth, nodeType *&t) {
    if (t == nullptr) {
        return depth;
    }
    int rigth_depth = _getDepth(depth + 1, t->right);
    int left_depth = _getDepth(depth + 1, t->left);


    return std::max(rigth_depth, left_depth);
}


