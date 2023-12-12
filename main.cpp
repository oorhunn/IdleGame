#include <iostream>
#include <memory>
#include <typeinfo>
#include <thread>
#include <vector>
#include <chrono>
#include <typeinfo>

#include "player/User.h"
#include "player/Monster.h"
#include "weapon/weapon_base.h"
#include "map/Map.h"
#include "math_utils/WorstMathUtils.h"
#include "fight/Fight.h"


int main()
{
	// std::vector<std::vector<int>> mat(4, std::vector<int>(4, 0));

	
	// mat[1][2] = 1;
	// for (auto it : mat){
	// 	for (auto it2 : it) {
	// 		// if (mat[it][it2])
	// 		std::cout << it2 << ' ';
	// 	}
	// 	std::cout << '\n';
	// }    
	User me1("necati", 100, 100);
	Map hello(2, 2);

	hello.Spawn(me1);

	return 0;
}

