#include "Monster.h"

Monster::Monster():
    PlayerBase("faruk", 10, 5)
{
}

Monster::~Monster()
{
}

void Monster::Hit()
{
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