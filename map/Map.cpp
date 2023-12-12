#include "Map.h"
#include <iostream>
#include <vector> 
Map::Map(int ROW, int COL) :
    row(ROW),
    col(COL)
{
    this_map.resize(row, std::vector<char>(col, '0'));

}

Map::~Map()
{
}

std::vector<int> Map::Spawn(User npc)
{
    if(spawned_units.empty()){
        int x;

    } 
    spawned_units.resize()
    return std::vector<int>(1,2);
}
