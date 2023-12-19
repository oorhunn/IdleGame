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


template <typename MyType>
int worst_binary_search(const std::vector<MyType>& in_arr, const MyType& x){
	int low = 0;
	int high = in_arr.size() - 1;
	while (low <= high){
		int mid = (low + high) / 2;
		int temp = in_arr[mid];
		if (temp < x) {
			low = mid + 1;
		}
		else if (temp > x) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}


int main()
{
	std::vector<int> myArr;
	for (int i = 0; i < 1000000000000; ++i){
		myArr.resize(myArr.size() + 1);
		myArr[i] = i;
	}

	int mInd = worst_binary_search<int>(myArr, 3);

	std::cout << mInd << "\n";
	return 0;
}

