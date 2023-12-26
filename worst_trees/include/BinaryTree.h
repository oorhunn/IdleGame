

#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeBase.h"
#include "LeafBase.h"   

template<typename nodeElementType>
class BinaryTree : public TreeBase<nodeElementType, BinaryNode> {

public:
    BinaryTree();
    ~BinaryTree() override;
    BinaryTree(const BinaryTree& rhs);
    BinaryTree(BinaryTree&& rhs);
    BinaryTree& operator=(const BinaryTree& rhs);
    BinaryTree& operator=(BinaryTree&& rhs);
    

    void flushTree();

   



protected:    


private:

    void _flushTree(BinaryNode<nodeElementType>* currentNode);

    virtual void print() const override;
    virtual BinaryNode<nodeElementType>* _remove(const nodeElementType& value, 
        BinaryNode<nodeElementType>*& currentNode) override;
    virtual void _insert(const nodeElementType& value, 
                        BinaryNode<nodeElementType>*& currentNode) override; 

};

#endif 
