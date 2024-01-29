#pragma once

#include <vector>

#include "../player/User.h"


class Map {

public:
    Map(int ROW, int COL);


    ~Map();
    std::vector<int> Spawn(User npc);

private:
    int row;
    int col;
    std::vector<std::vector<char>> this_map;

    std::vector<std::vector<int>> spawned_units;


};