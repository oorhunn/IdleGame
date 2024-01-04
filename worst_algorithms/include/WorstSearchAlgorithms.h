#include <vector>


namespace WorstSortLibrary{
    

    template <typename MyType>
    int worst_binary_search(const std::vector<MyType>& in_arr, const MyType& x);

    // euclids algorithm for calculating greatest common divisor
    int worst_gcd(int a, int b);

    template <typename T>
    void insertionSort(std::vector<T> &array);

    template <typename T>
    void shellSort(std::vector<T> &array);

    template <typename T>
    void mergeSort(std::vector<T> &firstArr);

    template <typename T>
    void mergeSort(std::vector<T> &firstArr, std::vector<T> &tempArr, int left, int right);


    template <typename T>
    void merge(std::vector<T> &firstArr, std::vector<T> &tempArr, int left, int right, int rightEnd);

    template <typename T>
    class QuickSort{
    public:
        void quickSort(std::vector<T> &arr); // driver

    private:
        void quickSort(std::vector<T> &arr, int left, int right); // internal
        const T& median3(std::vector<T> &arr, int left, int right);
    };

}



