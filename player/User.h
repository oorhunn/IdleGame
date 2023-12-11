#pragma once
#include <string>
#include "Player.h"


class User : public Player{

public:



    // constructor
    User(const std::string NAME, int HEALTH, int SHIELD);

    User& operator=(const User& user);
    
    
    
    virtual void GetsAttacked() override;

};

