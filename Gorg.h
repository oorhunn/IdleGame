#pragma once
#include <string>


class Gorg {

public:

    // constructor
    Gorg(const std::string NAME, int HEALTH, int SHIELD);


    std::string GetName();
    int GetHealth();
    int GetShield();

    bool IsDefeated();

    void GetsAttacked();

private:
    std::string name;
    int health;
    int shield;


};

