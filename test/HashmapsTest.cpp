#include <gtest/gtest.h>
#include "../worst_hashmaps/include/SamePairHashmap.h"

template <typename T>
class SamePairHashmapTest : public ::testing::Test {
protected:
    SamePairHashmap<T> hashmap;

    void SetUp() override {
        // Common setup code if needed
    }

    void TearDown() override {

    }
};

TYPED_TEST_SUITE_P(SamePairHashmapTest);

TYPED_TEST_P(SamePairHashmapTest, CommutativeProperty) {
    this->hashmap.insert(1, 2, 42);

    EXPECT_EQ(this->hashmap.get(1, 4), 42);
    EXPECT_EQ(this->hashmap.get(4, 1), 42);
    EXPECT_NE(this->hashmap.get(3, 2), 42);
    EXPECT_NE(this->hashmap.get(2, 3), 42);
    EXPECT_EQ(this->hashmap.get(4, 4), -1);
    EXPECT_EQ(this->hashmap.get(0, 0), -1);

}

TYPED_TEST_P(SamePairHashmapTest, NonEqualKeyPairs) {
    this->hashmap.insert(1, 2, 42);

    EXPECT_NE(this->hashmap.get(3, 1), 42);
    EXPECT_NE(this->hashmap.get(1, 3), 42);
    EXPECT_NE(this->hashmap.get(3, 4), 42);
}


REGISTER_TYPED_TEST_SUITE_P(SamePairHashmapTest,
                           CommutativeProperty,
                           NonEqualKeyPairs
                           );

// List the types you want to test
typedef ::testing::Types<int> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(MyTestSuite, SamePairHashmapTest, MyTypes);
