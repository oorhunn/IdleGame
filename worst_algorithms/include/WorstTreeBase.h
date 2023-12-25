// #pragma once

// #include "WorstNodes.h"


// template <typename nodeType, typename nodePtr>
// class WorstTreeBase {
// public:
//     WorstTreeBase();
//     virtual ~WorstTreeBase();

//     virtual void printTree(std::ostream& out = std::cout) const;
    
//     virtual void insert(const nodeType& x) = 0;
//     virtual void makeEmpty() = 0;
//     virtual bool deleteElement(const nodeType& x) = 0;

//     nodeType findMin();
//     std::ostringstream traversePreOrder() const;
//     int getDepth();
//     bool contains(const nodeType& x) const;

// protected:
//     nodePtr root;

//     virtual void _insert(const nodeType& x, nodePtr& t) = 0;
//     virtual void _makeEmpty(nodePtr& t) = 0;

//     int _getDepth(int depth, nodePtr& t);
//     void _traversePreOrder(std::ostringstream &out_str, const std::string &padding, const std::string &pointer, nodePtr t) const;
//     void traverseNodes(std::ostringstream& out_str, const std::string& padding, const std::string& pointer, nodePtr node, bool hasRightSibling);


//     bool _contains(const nodeType& x, nodePtr t ) const;

// private:


// };
