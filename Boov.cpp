#include "Boov.h"

Boov::Boov(const std::string NAME, int HEALTH, int SHIELD) 
    : name(NAME), health(HEALTH), shield(SHIELD) {
    // Constructor body (if needed)
}

std::string Boov::GetName()
{
    return name;
}

int Boov::GetHealth()
{
    return health;
}

int Boov::GetShield()
{
    return shield;
}

bool Boov::IsDefeated()
{
    if (health <= 0)
        return true;
    return false;
    return false;
}

void Boov::GetsAttacked() {
    int roll = rand() % 100;

    if (roll == 0) {
        health = 0;
    } 
    else if ( roll <= 50) {
        shield -= (2 + rand() % 4);
        if (shield < 0) {
            health += shield;
            shield = 0;
        }
    }

    else if (roll <= 79) {
        health -= (4 + rand() % 5);
    }
}
