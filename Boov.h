#pragma once
#include <string>
#include "Competitor.h"


class Boov : public Competitor{

public:

    // constructor
    Boov(const std::string NAME, int HEALTH, int SHIELD, float WEAPON_DAMAGE, float WEAPON_SPEED);

    virtual void GetsAttacked() override;

};

