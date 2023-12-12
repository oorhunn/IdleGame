#include "PlayerBase.h"
#include <iostream>

PlayerBase::PlayerBase(const std::string NAME, int HEALTH, int SHIELD)
    : name(NAME),
      health(HEALTH),
      shield(SHIELD)
      {
    // dps = weapon.damage / weapon.speed * 60;
}

PlayerBase::PlayerBase(const PlayerBase &player)
    : name(player.name),
      health(player.health),
      shield(player.shield)
{

}

PlayerBase& PlayerBase::operator=(const PlayerBase &player)
{
    // TODO: insert return statement here
    if (this != &player) {
        name = player.name;
        health = player.health;
        shield = player.shield;
    }
    return *this;
}

PlayerBase::~PlayerBase()
{
    // delete weapon;
}

std::string PlayerBase::GetName()
{
    return name;
}

void PlayerBase::SetName(std::string inname)
{
    name = inname;
}

int PlayerBase::GetHealth()
{
    return health;
}

int PlayerBase::GetShield()
{
    return shield;
}

float PlayerBase::GetAttackSpeed() { 
    // return weapon.speed; 
    return 0;   
}

bool PlayerBase::IsDefeated()
{
    if (health <= 0)
        return true;
    return false;
}