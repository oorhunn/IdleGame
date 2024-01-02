#include <vector>
#include "../include/WorstSearchAlgorithms.h"
template int worst_binary_search(const std::vector<int>& in_arr, const int& x);
template void insertionSort(std::vector<int> &array);
template void insertionSort(std::vector<double> &array);
template void shellSort(std::vector<int> &array);

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
		if (b == 0){
			return a;
		}
	}
	return a;
}

template <typename T>
void insertionSort(std::vector<T> &array) {
    for (int p = 1; p < array.size(); ++p) {
        T temp = std::move(array[p]);
        int j;
        for (j = p; j > 0 && temp < array[j - 1]; --j) {
            array[j] = std::move(array[j - 1]);
        }
        array[j] = std::move(temp);
    }
}

template <typename T>
void shellSort(std::vector<T> &array){
	for(int gap = array.size() / 2; gap > 0; gap /= 2){
		for (int i = gap; i < array.size(); ++i){
			T temp = std::move(array[i]);
			int j = i;
			for (;j >= gap && temp < array[j - gap]; j-=gap){
				array[j] = std::move(array[j - gap]);
			}
			array[j] = std::move(temp);
		}
	}
}