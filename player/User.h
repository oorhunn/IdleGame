#pragma once
#include <string>
#include "PlayerBase.h"
#include "../weapon/weapon_base.h"

class User : public PlayerBase{

public:



    // constructor
    User(const std::string NAME, int HEALTH, int SHIELD);

    User& operator=(const User& user);
    
    bool wieldWeapon(Weapon weapon);
    
    virtual void Hit() override;
private:
    int weapon_id;

};

