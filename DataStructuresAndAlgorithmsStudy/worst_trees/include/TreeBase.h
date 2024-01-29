#pragma once
#ifndef TREEBASE_H
#define TREEBASE_H

#include<ostream>
#include <iostream>

template<typename nodeElementType, template<typename> class nodeType>
class TreeBase {
public:
    TreeBase() : root(nullptr) {};
    virtual ~TreeBase() {} // Virtual destructor for polymorphism

    virtual void insert(const nodeElementType& value);
    void remove(const nodeElementType& value);
    bool search(const nodeElementType& value) const;
    nodeElementType findMin();

    void printTree(std::ostream& out = std::cout) const;
    std::ostringstream traversePreOrder() const;


protected:
    nodeType<nodeElementType>* root;
    virtual void traverseNodes(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, nodeType<nodeElementType>* node, bool hasRightSibling) const;
    
    virtual bool _search(const nodeElementType& value, 
                        const nodeType<nodeElementType>* currentNode) const;


    virtual void _insert(const nodeElementType& value, nodeType<nodeElementType>*& currentNode) = 0;
    virtual nodeType<nodeElementType>* _remove(const nodeElementType& value, 
        nodeType<nodeElementType>*& currentNode) = 0;
    virtual nodeType<nodeElementType>* _findMin(nodeType<nodeElementType>*& currentNode);



};



#endif