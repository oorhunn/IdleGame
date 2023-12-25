#pragma once
#include "WorstTreeBase.h"
#include "WorstLeafBase.h"

template<typename nodeElementType, typename nodeType>
class WorstTree : public WorstTreeBase<nodeElementType, nodeType>
{

public:
    WorstTree();
    ~WorstTree() override;
    
    virtual void insert(const nodeElementType& x) override;
    virtual void makeEmpty() override;
    virtual bool deleteElement(const nodeElementType& x) override;

private:
    

};

