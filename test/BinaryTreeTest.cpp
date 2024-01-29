#include "../worst_trees/include/BinaryTree.h"
#include <gtest/gtest.h>
#include <iostream>

// Define a fixture class for BinaryTree tests
template <typename T>
class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree<T> tree;

    // Helper function to insert values into the tree
    void insertValues(const std::vector<T>& values) {
        for (const auto& value : values) {
            tree.insert(value);
        }
    }

    // Helper function to remove values from the tree
    void removeValues(const std::vector<T>& values) {
        for (const auto& value : values) {
            tree.remove(value);
        }
    }

    // SetUp function to be called before each test case
    void SetUp() override {
        // Perform any setup steps needed for the tests
    }

    // TearDown function to be called after each test case
    void TearDown() override {
        // Perform any cleanup steps needed for the tests
        // tree.flushTree();  // Ensure the tree is empty after each test
    }
};

// Test case for inserting values into the tree
TYPED_TEST_SUITE_P(BinaryTreeTest);

TYPED_TEST_P(BinaryTreeTest, InsertTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Act
    this->insertValues(values);

    // Assert
    // Add your assertions based on the expected structure or properties of the tree
    ASSERT_TRUE(this->tree.search(5));
    ASSERT_TRUE(this->tree.search(3));
    ASSERT_TRUE(this->tree.search(7));
    ASSERT_TRUE(this->tree.search(2));
    ASSERT_TRUE(this->tree.search(4));
    ASSERT_TRUE(this->tree.search(6));
    ASSERT_TRUE(this->tree.search(8));
    ASSERT_FALSE(this->tree.search(13));
}

TYPED_TEST_P(BinaryTreeTest, RemoveTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Insert values into the tree
    this->insertValues(values);

    // Act
    this->removeValues({4, 6});

    // Assert
    // Add your assertions based on the expected structure or properties of the tree after removal
    ASSERT_TRUE(this->tree.search(5));
    ASSERT_TRUE(this->tree.search(3));
    ASSERT_TRUE(this->tree.search(7));
    ASSERT_TRUE(this->tree.search(2));
    ASSERT_FALSE(this->tree.search(4));
    ASSERT_FALSE(this->tree.search(6));
    ASSERT_TRUE(this->tree.search(8));
    ASSERT_FALSE(this->tree.search(13));
}

TYPED_TEST_P(BinaryTreeTest, FlushTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Insert values into the tree
    this->insertValues(values);

    // Act
    this->tree.flushTree();

    // Assert
    // Add your assertions based on the expected state of the tree after flushing
    ASSERT_FALSE(this->tree.search(5));
    ASSERT_FALSE(this->tree.search(3));
    ASSERT_FALSE(this->tree.search(7));
    ASSERT_FALSE(this->tree.search(2));
    ASSERT_FALSE(this->tree.search(4));
    ASSERT_FALSE(this->tree.search(6));
    ASSERT_FALSE(this->tree.search(8));
    ASSERT_FALSE(this->tree.search(13));
}

// Register the test cases
REGISTER_TYPED_TEST_SUITE_P(BinaryTreeTest, InsertTest, RemoveTest, FlushTest);

// Specify the types you want to test with
typedef ::testing::Types<int> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(MyBinaryTreeTypes, BinaryTreeTest, MyTypes);
