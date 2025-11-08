#include "solution.h" // Assumes all 3 solutions are in "solution.h" in a single Solution class
#include <gtest/gtest.h>
#include <vector>

// Test fixtures can be used if we want to test all 3 implementations
// For simplicity, we'll just test the main 'maxSubArray' public method.

TEST(MaximumSubarray, Example1_FromLeetCode) {
    Solution s;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(s.maxSubArray(nums), 6); // [4, -1, 2, 1]
}

TEST(MaximumSubarray, Example2_FromLeetCode) {
    Solution s;
    std::vector<int> nums = {1};
    EXPECT_EQ(s.maxSubArray(nums), 1);
}

TEST(MaximumSubarray, Example3_FromLeetCode) {
    Solution s;
    std::vector<int> nums = {5, 4, -1, 7, 8};
    EXPECT_EQ(s.maxSubArray(nums), 23); // The whole array
}

TEST(MaximumSubarray, AllNegative) {
    Solution s;
    std::vector<int> nums = {-3, -5, -1, -2};
    EXPECT_EQ(s.maxSubArray(nums), -1);
}

TEST(MaximumSubarray, MixedPositiveNegative_CustomExample) {
    Solution s;
    std::vector<int> nums = {-5, 2, 3, -1, 2, -4, 6};
    EXPECT_EQ(s.maxSubArray(nums), 8); // [2, 3, -1, 2, -4, 6]
}

TEST(MaximumSubarray, AllPositive) {
    Solution s;
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(s.maxSubArray(nums), 10);
}

TEST(MaximumSubarray, SingleNegative) {
    Solution s;
    std::vector<int> nums = {-10};
    EXPECT_EQ(s.maxSubArray(nums), -10);
}

TEST(MaximumSubarray, SinglePositive) {
    Solution s;
    std::vector<int> nums = {10};
    EXPECT_EQ(s.maxSubArray(nums), 10);
}

TEST(MaximumSubarray, AlternatingSigns) {
    Solution s;
    std::vector<int> nums = {1, -2, 3, -1, 2};
    EXPECT_EQ(s.maxSubArray(nums), 4); // [3, -1, 2]
}

TEST(MaximumSubarray, LongRunOfPositives) {
    Solution s;
    std::vector<int> nums(1000, 1);
    EXPECT_EQ(s.maxSubArray(nums), 1000);
}

TEST(MaximumSubarray, AllZeroes) {
    Solution s;
    std::vector<int> nums = {0, 0, 0};
    EXPECT_EQ(s.maxSubArray(nums), 0);
}

TEST(MaximumSubarray, IncreasingThenBigDrop) {
    Solution s;
    std::vector<int> nums = {1, 2, 3, -10, 5, 6};
    EXPECT_EQ(s.maxSubArray(nums), 11); // [5, 6]
}

TEST(MaximumSubarray, MixedWithZero) {
    Solution s;
    std::vector<int> nums = {-1, 0, -2};
    EXPECT_EQ(s.maxSubArray(nums), 0); // [0]
}

TEST(MaximumSubarray, LongRunOfNegatives) {
    Solution s;
    std::vector<int> nums(100000, -1);
    EXPECT_EQ(s.maxSubArray(nums), -1);
}

TEST(MaximumSubarray, MixedMinMaxValues) {
    Solution s;
    std::vector<int> nums = {-10000, 10000};
    EXPECT_EQ(s.maxSubArray(nums), 10000);
}

TEST(MaximumSubarray, DropAtEnd) {
    Solution s;
    std::vector<int> nums = {2, 3, -2, -1};
    EXPECT_EQ(s.maxSubArray(nums), 5); // [2, 3]
}

TEST(MaximumSubarray, BigFluctuation) {
    Solution s;
    std::vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    EXPECT_EQ(s.maxSubArray(nums), 7); // [4, -1, -2, 1, 5]
}

TEST(MaximumSubarray, LargeNegativeStart) {
    Solution s;
    std::vector<int> nums = {-100, 10, 20, 30};
    EXPECT_EQ(s.maxSubArray(nums), 60); // [10, 20, 30]
}

TEST(MaximumSubarray, LargePositivesWithSmallDip) {
    Solution s;
    std::vector<int> nums = {10, -2, 3, -1, 5};
    EXPECT_EQ(s.maxSubArray(nums), 15); // [10, -2, 3, -1, 5]
}

TEST(MaximumSubarray, AllSameNegative) {
    Solution s;
    std::vector<int> nums = {-5, -5, -5};
    EXPECT_EQ(s.maxSubArray(nums), -5);
}