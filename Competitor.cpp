#include "Competitor.h"

Competitor::Competitor(const std::string NAME, int HEALTH, int SHIELD) 
            : name(NAME),
            health(HEALTH),
            shield(SHIELD)
{
    // Nothenn
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

bool Competitor::IsDefeated()
{
    if (health <= 0)
        return true;
    return false;
}