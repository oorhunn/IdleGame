#include "Player.h"
#include <iostream>

Player::Player(const std::string NAME, int HEALTH, int SHIELD)
    : name(NAME),
      health(HEALTH),
      shield(SHIELD)
      {
    // dps = weapon.damage / weapon.speed * 60;
}

Player::Player(const Player &player)
    : name(player.name),
      health(player.health),
      shield(player.shield)
{

}

Player& Player::operator=(const Player &player)
{
    // TODO: insert return statement here
    if (this != &player) {
        name = player.name;
        health = player.health;
        shield = player.shield;
    }
    return *this;
}

Player::~Player()
{
    // delete weapon;
}

std::string Player::GetName()
{
    return name;
}

void Player::SetName(std::string inname)
{
    name = inname;
}

int Player::GetHealth()
{
    return health;
}

int Player::GetShield()
{
    return shield;
}

float Player::GetAttackSpeed() { 
    // return weapon.speed; 
    return 0;   
}

bool Player::IsDefeated()
{
    if (health <= 0)
        return true;
    return false;
}