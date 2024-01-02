#include <gtest/gtest.h>
#include "../include/WorstSearchAlgorithms.h"  // Update the path as needed

class WorstAlgorithmsTest : public ::testing::Test {
protected:
    // Helper function to check if a vector is sorted
    template <typename T>
    bool isSorted(const std::vector<T>& array) {
        for (size_t i = 1; i < array.size(); ++i) {
            if (array[i] < array[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

TEST_F(WorstAlgorithmsTest, BinarySearch) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(worst_binary_search(arr, 3), 2);
    EXPECT_EQ(worst_binary_search(arr, 6), -1);
}

TEST_F(WorstAlgorithmsTest, GCD) {
    EXPECT_EQ(worst_gcd(6, 3), 3);
    EXPECT_EQ(worst_gcd(15, 25), 5);
}

TEST_F(WorstAlgorithmsTest, InsertionSortInt) {
    std::vector<int> arr = {5, 2, 7, 1, 3};
    insertionSort(arr);
    EXPECT_TRUE(isSorted(arr));
}

TEST_F(WorstAlgorithmsTest, InsertionSortDouble) {
    std::vector<double> arr = {5.5, 2.2, 7.7, 1.1, 3.3};
    insertionSort(arr);
    EXPECT_TRUE(isSorted(arr));
}

TEST_F(WorstAlgorithmsTest, ShellSortInt){
    std::vector<int> arr = {5, 2, 7, 1, 3};
    shellSort(arr);
    EXPECT_TRUE(isSorted(arr));
}

// Add more tests as needed

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
