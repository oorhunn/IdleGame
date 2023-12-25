#pragma once

#include "WorstNodes.h"


template <typename nodeElementType, typename nodeType>
class WorstTreeBase {
public:
    WorstTreeBase();
    virtual ~WorstTreeBase();

    virtual void printTree(std::ostream& out = std::cout) const;
    
    virtual void insert(const nodeElementType& x) = 0;
    virtual void makeEmpty() = 0;
    virtual bool deleteElement(const nodeElementType& x) = 0;

    nodeElementType findMin();
    std::ostringstream traversePreOrder() const;
    int getDepth();
    bool contains(const nodeElementType& x) const;

protected:
    nodeType* root;

    virtual void _insert(const nodeElementType& x, nodeType*& t) = 0;
    virtual void _makeEmpty(nodeType*& t) = 0;

    int _getDepth(int depth, nodeType*& t);
    void _traversePreOrder(std::ostringstream &out_str, const std::string &padding, const std::string &pointer, nodeType* t) const;
    void traverseNodes(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, nodeType* node, bool hasRightSibling);


    bool _contains(const nodeElementType& x, nodeType* t ) const;

private:


};
