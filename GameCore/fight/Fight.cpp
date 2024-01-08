#include "Fight.h"
#include <iostream>

Fight::Fight(std::vector<PlayerBase> FIGHTZONE)
{
    arena = FIGHTZONE;
    std::cout << arena << "\n";
}