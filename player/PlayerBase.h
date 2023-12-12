#pragma once 
#include <string>
#include <vector>
// #include "../weapon/weapon_base.h"

// MyStruct(int m1, double m2, char m3) : member1(m1), member2(m2), member3(m3) {}


class PlayerBase { 

public:


    PlayerBase(const std::string NAME, int HEALTH, int SHIELD);
    
    PlayerBase(const PlayerBase& player);
    PlayerBase& operator=(const PlayerBase& player);
    
    
    ~PlayerBase();



    std::string GetName();
    void SetName(std::string inname);
    int GetHealth();
    int GetShield();

    float GetAttackSpeed();

    bool IsDefeated();

    void EatDamage(int damage);
    virtual void Hit(PlayerBase& enemy) = 0;

protected:
    std::string name;
    // Weapon* weapon;
    float dps;
    int health;
    int shield;
    std::vector<int> position;

};