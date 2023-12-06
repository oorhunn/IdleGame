#include "Gorg.h"

Gorg::Gorg(const std::string NAME, int HEALTH, int SHIELD) 
    : name(NAME), health(HEALTH), shield(SHIELD)
{

}

std::string Gorg::GetName() { 
    
    
    return name; 
}

int Gorg::GetHealth() { return 0; }

int Gorg::GetShield() { return 0; }

bool Gorg::IsDefeated() { return false; }

void Gorg::GetsAttacked() {}
