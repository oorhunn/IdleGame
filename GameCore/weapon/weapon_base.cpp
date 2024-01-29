#include "weapon_base.h"

Weapon::Weapon(int WEAPON_ID, float DAMAGE, float SPEED):
    weapon_id(WEAPON_ID),
    damage(DAMAGE),
    speed(SPEED)
{
}

float Weapon::getWeaponSpeed()
{
    return speed;
}

float Weapon::getWeaponDamage()
{
    return damage;
}

int Weapon::getWeaponID()
{
    return weapon_id;
}
