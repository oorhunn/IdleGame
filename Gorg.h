#pragma once
#include "Competitor.h"

class Gorg : public Competitor{

public:

    // constructor
    Gorg();
    ~Gorg();
    virtual void GetsAttacked() override;
private:

    int max_shield;


};
