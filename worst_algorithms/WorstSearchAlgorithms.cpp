#include <vector>
#include "WorstSearchAlgorithms.h"
template int worst_binary_search(const std::vector<int>& in_arr, const int& x);



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

int worst_gcd(int a, int b){
	while (a != 0) {
		int rem = a % b;
		a = b;
		b = rem;
	}
	return a;
}

template <typename MyType>
inline MyType worst_pow(const MyType &num, int power)
{	return 0;
	// if(power == 0)
	// 	return 1;
	// if(power == 1)
	// 	return num
	// if(isEven(power))
	// 	return worst_pow(num * num, power / 2);
	// else
	// 	return worst_pow(num * num, n /2) * num;
}
