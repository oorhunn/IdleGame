#include "../include/WorstTreeBase.h"
#include <sstream>
#include <ostream>


template <typename nodeType, typename nodePtr>
WorstTreeBase<nodeType, nodePtr>::WorstTreeBase()
{
}

template <typename nodeType, typename nodePtr>
WorstTreeBase<nodeType, nodePtr>::~WorstTreeBase()
{
}

template <typename nodeType, typename nodePtr>
bool WorstTreeBase<nodeType, nodePtr>::contains(const nodeType &x) const
{
    return false;
}

template <typename nodeType, typename nodePtr>
inline bool WorstTreeBase<nodeType, nodePtr>::_contains(const nodeType &x, nodePtr t) const {
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


template <typename nodeType, typename nodePtr>
nodeType WorstTreeBase<nodeType, nodePtr>::findMin() {
    if (root == nullptr) {
        return nodeType();
    }
    nodePtr minNode = _findMin(root);
    return minNode->element;
}


template <typename nodeType, typename nodePtr>
int WorstTreeBase<nodeType, nodePtr>::getDepth() {
    if (root == nullptr){
        return 0;
    }
    int depth = _getDepth(0, root);
    return depth;
}

template <typename nodeType, typename nodePtr>
inline int WorstTreeBase<nodeType, nodePtr>::_getDepth(int depth, nodePtr &t) {
    if (t == nullptr) {
        return depth;
    }
    int rigth_depth = _getDepth(depth + 1, t->right);
    int left_depth = _getDepth(depth + 1, t->left);


    return std::max(rigth_depth, left_depth);
}


