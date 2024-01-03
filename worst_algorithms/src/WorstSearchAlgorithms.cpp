#include <vector>
#include "../include/WorstSearchAlgorithms.h"




template int WorstSortLibrary::worst_binary_search(const std::vector<int>& in_arr, const int& x);
template void WorstSortLibrary::insertionSort(std::vector<int> &array);
template void WorstSortLibrary::insertionSort(std::vector<double> &array);
template void WorstSortLibrary::shellSort(std::vector<int> &array);
template void WorstSortLibrary::mergeSort(std::vector<int> &firstArr);
template void WorstSortLibrary::mergeSort(std::vector<int> &firstArr, std::vector<int> &tempArr, int left, int right);
template void WorstSortLibrary::merge(std::vector<int> &firstArr, std::vector<int> &tempArr, int left, int right, int rightEnd);
template class WorstSortLibrary::QuickSort<int>;

namespace WorstSortLibrary {
	// needs a input that already sorted
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
	template <typename T>
	void mergeSort(std::vector<T> &firstArr)
	{
		std::vector<T> tempArray(firstArr.size());
		mergeSort(firstArr, tempArray, 0, firstArr.size() - 1);
	}

	template <typename T>
	void mergeSort(std::vector<T> &firstArr, std::vector<T> &tempArr, int left, int right)
	{
		if (left < right){
			int center = (left + right) / 2;
			mergeSort(firstArr, tempArr, left, center);
			mergeSort( firstArr, tempArr, center + 1, right );
			merge( firstArr, tempArr, left, center + 1, right );
		}
	}

	template <typename T>
	void merge(std::vector<T> &firstArr, std::vector<T> &tempArr, int left, int right, int rightEnd)
	{
		int leftEnd = right - 1;
		int tempPos = left;
		int elemCount = rightEnd - left + 1;

		while (left <= leftEnd && right <= rightEnd){
			if (firstArr[left] <= firstArr[right]) {
				tempArr[tempPos++] = std::move(firstArr[left++]);
			}
			else{
				tempArr[tempPos++] = std::move(firstArr[right++]);
			}
		}
		while (left <= leftEnd){
			tempArr[tempPos++] = std::move(firstArr[left++]);
		}
		while (right <= rightEnd){
			tempArr[tempPos++] = std::move(firstArr[right++]);
		}
		for (int i = 0; i < elemCount; ++i, --rightEnd) {
			firstArr[rightEnd] = std::move(tempArr[rightEnd]);
		}
	}


	template <typename T>
	inline void QuickSort<T>::quickSort(std::vector<T> &arr) // driver func
	{
		quickSort(arr, 0, arr.size() - 1);
	}
	template <typename T>
	void QuickSort<T>::quickSort(std::vector<T> &arr, int left, int right)
	{
		if (left + 10 <= right){
			const T & pivot = median3( arr, left, right );
			int i = left, j = right - 1;
			for( ; ; ) {
				while( arr[ ++i ] < pivot ) { }
				while( pivot < arr[ --j ] ) { }
				if( i < j )
					std::swap( arr[ i ], arr[ j ] );
				else
					break;
			}
			std::swap( arr[ i ], arr[ right - 1 ] );
			quickSort( arr, left, i - 1 ); 
			quickSort( arr, i + 1, right ); 
		}
		else {
			for (int p = left + 1; p <= right; ++p) {
				T temp = std::move(arr[p]);
				int j;
				for (j = p; j > left && temp < arr[j - 1]; --j) {
					arr[j] = std::move(arr[j - 1]);
				}
				arr[j] = std::move(temp);
			}
		}
	}

	template <typename T>
	const T &QuickSort<T>::median3(std::vector<T> &arr, int left, int right)
	{
		int center = (left + right) / 2;
		if (arr[center] < arr[left]) {
			std::swap(arr[left], arr[center]);
		}
		if (arr[right] < arr[left]) {
			std::swap(arr[left], arr[right]);
		}
		if (arr[right] < arr[center]) {
			std::swap(arr[center], arr[right]);
		}

		std::swap(arr[center], arr[right - 1]);

		return arr[right - 1];
	}


}


