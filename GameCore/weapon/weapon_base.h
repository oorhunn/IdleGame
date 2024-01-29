#pragma once

class Weapon {
public:
    Weapon(int WEAPON_ID, float DAMAGE, float SPEED);

    float getWeaponSpeed();
    float getWeaponDamage();
    int getWeaponID();

private:
    int weapon_id;
    float damage;
    float speed;
    
};
