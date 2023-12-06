#pragma once 
#include <string>


class Competitor { 

public:
    Competitor(const std::string NAME, int HEALTH, int SHIELD);

    std::string GetName();
    int GetHealth();
    int GetShield();

    bool IsDefeated();

    virtual void GetsAttacked() = 0;

protected:
    std::string name;
    int health;
    int shield;

};