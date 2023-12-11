#pragma once 
#include <string>
// #include "../weapon/weapon_base.h"

// MyStruct(int m1, double m2, char m3) : member1(m1), member2(m2), member3(m3) {}


class Player { 

public:


    Player(const std::string NAME, int HEALTH, int SHIELD);
    
    Player(const Player& player);
    Player& operator=(const Player& player);
    
    
    ~Player();



    std::string GetName();
    void SetName(std::string inname);
    int GetHealth();
    int GetShield();

    float GetAttackSpeed();

    bool IsDefeated();

    virtual void GetsAttacked() = 0;

protected:
    std::string name;
    // Weapon* weapon;
    float dps;
    int health;
    int shield;

};