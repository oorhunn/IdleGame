#include "User.h"

User::User(const std::string NAME, int HEALTH, int SHIELD) 
    : PlayerBase(NAME, HEALTH, SHIELD) {
    // Constructor body (if needed)
}

User &User::operator=(const User &user)
{
    PlayerBase::operator=(user);
    return *this;
}

bool User::wieldWeapon(Weapon weapon)
{
    dps = weapon.getWeaponDamage() * weapon.getWeaponSpeed();
    weapon_id = weapon.getWeaponID();
    if (dps != 0.0){
        return true;
    }
    return false;
}

void User::Hit(PlayerBase& enemy) {
    int roll = rand() % 100;
    if (roll == 0) {
        enemy.EatDamage(enemy.GetHealth());
    } 
    enemy.EatDamage(dps);
}


