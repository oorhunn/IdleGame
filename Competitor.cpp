#include "Competitor.h"

Competitor::Competitor(const std::string NAME, int HEALTH, int SHIELD, Weapon weapon)
    : name(NAME),
      health(HEALTH),
      shield(SHIELD),
      weapon(weapon)
{
    dps = weapon.damage / weapon.speed * 60;
}

std::string Competitor::GetName()
{
    return name;
}

int Competitor::GetHealth()
{
    return health;
}

int Competitor::GetShield()
{
    return shield;
}

float Competitor::GetAttackSpeed() { 
    return weapon.speed; 
}

bool Competitor::IsDefeated()
{
    if (health <= 0)
        return true;
    return false;
}