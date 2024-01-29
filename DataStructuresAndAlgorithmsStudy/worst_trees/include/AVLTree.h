#pragma once

#ifndef AVLTREE_H
#define AVLTREE_H

#include "TreeBase.h"
#include "LeafBase.h"


template <typename nodeElementType>
class AVLTree : public TreeBase<nodeElementType, AVLNode> {

public:
    static const int ALLOWED_IMBALANCE = 1;

    AVLTree();
    ~AVLTree() override;
    AVLTree(const AVLTree& avl);
    AVLTree(AVLTree&& avl) = delete;
    AVLTree& operator=(const AVLTree& avl);
    AVLTree& operator=(AVLTree&& avl) = delete;

    virtual void insert(const nodeElementType& value) override;

    void flushAVLTree();
    int height(AVLNode<nodeElementType>* currentNode) const;




private:
    void _flushAVLTree(AVLNode<nodeElementType>* currentNode);
    void balance(AVLNode<nodeElementType>*& currentNode);

    void rotateWithLeftChild(AVLNode<nodeElementType>*& currentNode);
    void doubleWithLeftChild(AVLNode<nodeElementType>*& currentNode);
    void rotateWithRightChild(AVLNode<nodeElementType>*& currentNode);
    void doubleWithRightChild(AVLNode<nodeElementType>*& currentNode);


    AVLNode<nodeElementType>* _clone(AVLNode<nodeElementType>* currentNode) const;

    virtual AVLNode<nodeElementType>* _remove(const nodeElementType& value,
        AVLNode<nodeElementType>*& currentNode) override;

    virtual void _insert(const nodeElementType& value,
        AVLNode<nodeElementType>*& currentNode) override;

    void _insert(const nodeElementType& value, 
        AVLNode<nodeElementType>*& currentNode, int height);

};


#endif
