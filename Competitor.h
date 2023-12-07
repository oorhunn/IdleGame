#pragma once 
#include <string>


// MyStruct(int m1, double m2, char m3) : member1(m1), member2(m2), member3(m3) {}

struct Weapon {
    float damage;
    float speed;
    
    Weapon(float DAMAGE, float SPEED) : damage(DAMAGE), speed(SPEED) {}
};

class Competitor { 

public:
    Competitor(const std::string NAME, int HEALTH, int SHIELD, Weapon weapon);

    std::string GetName();
    int GetHealth();
    int GetShield();

    float GetAttackSpeed();

    bool IsDefeated();

    virtual void GetsAttacked() = 0;

protected:
    std::string name;
    Weapon weapon;
    float dps;
    int health;
    int shield;

};