#pragma once



#include "PlayerBase.h"



class Monster : public PlayerBase  {
public:
    Monster();
    ~Monster();



    virtual void Hit(PlayerBase& enemy) override;


private:
    

};