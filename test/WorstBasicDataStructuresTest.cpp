#include "../worst_algorithms/include/WorstLinkedList.h"

#include <gtest/gtest.h>
#include <vector>


TEST(IdlegameTests, worstAppend) {

    WorstLinkedList<int> testList;
    testList.worstAppend(1);
    testList.worstAppend(2);
    testList.worstAppend(1);
    testing::internal::CaptureStdout();
    testList.worstDisplay();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 \n2 \n1 \n");

}


TEST(IdlegameTests, worstDeleteNode) {
    WorstLinkedList<int> testList;
    testList.worstAppend(1);
    testList.worstAppend(2);
    testList.worstAppend(3);
    testing::internal::CaptureStdout();
    testList.worstDeleteNode(1);
    testList.worstDisplay();
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "2 \n3 \n");


    testList.worstAppend(4);
    testList.worstAppend(5);
    testing::internal::CaptureStdout();
    testList.worstDeleteNode(3);
    testList.worstDisplay();
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "2 \n4 \n5 \n");

    testList.worstDeleteNode(5);
    testing::internal::CaptureStdout();
    testList.worstDisplay();
    std::string output3 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output3, "2 \n4 \n");

}
