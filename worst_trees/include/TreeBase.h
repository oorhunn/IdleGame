#pragma once

template<typename nodeElementType, template<typename> class nodeType>
class TreeBase {
public:
    TreeBase() : root(nullptr) {};
    virtual ~TreeBase() {} // Virtual destructor for polymorphism

    void insert(const nodeElementType& value);
    void remove(const nodeElementType& value);
    bool search(const nodeElementType& value) const;
    nodeElementType findMin();

    virtual void print() const = 0;
protected:
    nodeType<nodeElementType>* root;
    virtual bool _search(const nodeElementType& value, 
                        const nodeType<nodeElementType>* currentNode) const;


    virtual void _insert(const nodeElementType& value, nodeType<nodeElementType>*& currentNode) = 0;
    virtual nodeType<nodeElementType>* _remove(const nodeElementType& value, 
        nodeType<nodeElementType>*& currentNode) = 0;
    virtual nodeType<nodeElementType>* _findMin(nodeType<nodeElementType>*& currentNode);

};

