#include <gtest/gtest.h>
#include "../worst_priority_queues/include/BinaryHeap.h"

// Define a fixture class for BinaryHeap tests
template <typename T>
class BinaryHeapTest : public ::testing::Test {
protected:
    BinaryHeap<T> heap;

    // Helper function to insert values into the heap
    void insertValues(const std::vector<T>& values) {
        for (const auto& value : values) {
            heap.insert(value);
        }
    }
};

// Test case for inserting values into the heap
TYPED_TEST_SUITE_P(BinaryHeapTest);

TYPED_TEST_P(BinaryHeapTest, InsertTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Act
    this->insertValues(values);

    // Assert
    ASSERT_EQ(this->heap.findMin(), 2);
}

// Test case for deleting the minimum element
TYPED_TEST_P(BinaryHeapTest, DeleteMinTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};
    this->insertValues(values);

    // Act
    this->heap.deleteMin();

    // Assert
    ASSERT_EQ(this->heap.findMin(), 3);
}

// Test case for making the heap empty
TYPED_TEST_P(BinaryHeapTest, MakeEmptyTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};
    this->insertValues(values);

    // Act
    this->heap.makeEmpty();

    // Assert
    ASSERT_TRUE(this->heap.isEmpty());
}

// Register the test cases
REGISTER_TYPED_TEST_SUITE_P(BinaryHeapTest, InsertTest, DeleteMinTest, MakeEmptyTest);

// Specify the types you want to test with
typedef ::testing::Types<int> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(MyBinaryHeapTypes, BinaryHeapTest, MyTypes);
