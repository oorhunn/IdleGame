#include "Boov.h"

Boov::Boov(const std::string NAME, int HEALTH, int SHIELD, float WEAPON_DAMAGE, float WEAPON_SPEED) 
    : Competitor(NAME, HEALTH, SHIELD, Weapon(WEAPON_DAMAGE, WEAPON_SPEED)) {
    // Constructor body (if needed)
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
        health -= (5 + rand() % 5);
    }
}
