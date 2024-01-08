#pragma once

#include <vector>
#include <iostream>
#include "../math_utils/WorstMathUtils.h"
#include "../player/PlayerBase.h"


class Fight : public WorstMathUtils, public PlayerBase {

public:

Fight(std::vector<PlayerBase> FIGHTZONE);
~Fight();


private:
    std::vector<PlayerBase> arena;

};