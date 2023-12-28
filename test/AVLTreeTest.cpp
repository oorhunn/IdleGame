#include "../worst_trees/include/AVLTree.h"
#include <gtest/gtest.h>

// Define a fixture class for AVLTree tests
template <typename T>
class AVLTreeTest : public ::testing::Test {
protected:
    AVLTree<T> avlTree;

    // Helper function to insert values into the AVL tree
    void insertValues(const std::vector<T>& values) {
        for (const auto& value : values) {
            avlTree.insert(value);
        }
    }

    // Helper function to remove values from the AVL tree
    void removeValues(const std::vector<T>& values) {
        for (const auto& value : values) {
            avlTree.remove(value);
        }
    }
};

// Test case for inserting values into the AVL tree
TYPED_TEST_SUITE_P(AVLTreeTest);

TYPED_TEST_P(AVLTreeTest, InsertTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Act
    this->insertValues(values);

    // Assert
    // Add your assertions based on the expected structure or properties of the tree
    // You might want to check the height of nodes or other properties specific to your AVLTree implementation
}

TYPED_TEST_P(AVLTreeTest, RemoveTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Insert values into the AVL tree
    this->insertValues(values);

    // Act
    this->removeValues({4, 6});

    // Assert
    // Add your assertions based on the expected structure or properties of the tree
}

TYPED_TEST_P(AVLTreeTest, FlushTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Insert values into the AVL tree
    this->insertValues(values);

    // Act
    this->avlTree.flushAVLTree();

    // Assert
    // Add your assertions based on the expected structure or properties of the tree after flushing
}

TYPED_TEST_P(AVLTreeTest, HeightTest) {
    // Arrange
    std::vector<TypeParam> values = {5, 3, 7, 2, 4, 6, 8};

    // Insert values into the AVL tree
    this->insertValues(values);

    // Act
    int treeHeight; /* calculate height using your AVLTree implementation */;

    // Assert
    // Add your assertions based on the expected height of the tree
}

// Register the test cases
REGISTER_TYPED_TEST_SUITE_P(AVLTreeTest, InsertTest, RemoveTest, FlushTest, HeightTest);

// Specify the types you want to test with
typedef ::testing::Types<int> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(MyAVLTreeTypes, AVLTreeTest, MyTypes);
