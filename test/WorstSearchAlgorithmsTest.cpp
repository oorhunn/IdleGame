#include "../worst_algorithms/include/WorstSearchAlgorithms.h"

#include <gtest/gtest.h>
#include <vector>


TEST(IdlegameTests, worst_binary_search) {
    std::vector<int> test_arr;
    for (int i = 0; i < 100; ++i) {
        test_arr.push_back(i);
    }
    EXPECT_EQ(
        worst_binary_search(test_arr, 3),
        3);
    EXPECT_EQ(
        worst_binary_search(test_arr, 98),
        98);
}


TEST(IdlegameTests, worst_gcd) {

    EXPECT_EQ(
        worst_gcd(6, 3),
        3);

}
