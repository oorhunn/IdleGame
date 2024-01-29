#include "Monster.h"

Monster::Monster():
    PlayerBase("faruk", 10, 5)
{
}

Monster::~Monster()
{
}

void Monster::Hit(PlayerBase &enemy)
{
    int roll = rand() % 100;
    if (roll == 0) {
        enemy.EatDamage(enemy.GetHealth());
    } 
    enemy.EatDamage(dps);
}

