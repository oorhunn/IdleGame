#include <iostream>
#include <memory>
#include <typeinfo>
#include <thread>
#include <vector>
#include <chrono>

#include "player/User.h"
#include "player/Monster.h"
#include "weapon/weapon_base.h"
#include "math_utils/WorstMathUtils.h"
#include "fight/Fight.h"



int main()
{
	User user1("necmi", 100, 100);
	Weapon wep1(1, 10, 10);
	Monster m1;
	user1.wieldWeapon(wep1);
	user1.Hit();
	int a;	




	return 0;
}

