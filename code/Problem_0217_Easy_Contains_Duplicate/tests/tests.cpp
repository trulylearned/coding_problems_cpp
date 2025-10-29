#include "solution.h" // Assumes solution is in "solution.h"
#include <gtest/gtest.h>
#include <vector>

// Make sure to use solution.contains_duplicate (snake_case)
// to match our enhanced solution file.

TEST(ContainsDuplicate, Example1) {
    Solution s;
    std::vector<int> nums{1, 2, 3, 1};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, Example2) {
    Solution s;
    std::vector<int> nums{1, 2, 3, 4};
    EXPECT_FALSE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, Example3) {
    Solution s;
    std::vector<int> nums{1, 1, 1, 3, 4, 3, 2, 4, 2};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

// ---- Custom Tests ----
TEST(ContainsDuplicate, CustomA_FromWalkthrough) {
    Solution s;
    std::vector<int> nums{4, 2, 7, 1, 9, 7};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, CustomB_FromWalkthrough) {
    Solution s;
    std::vector<int> nums{10, 5, -3, 8, 2};
    EXPECT_FALSE(s.contains_duplicate(nums));
}

// ---- Edge Cases ----
TEST(ContainsDuplicate, EmptyInput) {
    Solution s;
    std::vector<int> nums{}; // Empty vector
    EXPECT_FALSE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, SingleElement) {
    Solution s;
    std::vector<int> nums{5};
    EXPECT_FALSE(s.contains_duplicate(nums));
}

// ---- Typical Cases ----
TEST(ContainsDuplicate, TwoSameElements) {
    Solution s;
    std::vector<int> nums{42, 42};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, TwoDifferentElements) {
    Solution s;
    std::vector<int> nums{42, 43};
    EXPECT_FALSE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, AllDistinctLargeRange) {
    Solution s;
    std::vector<int> nums;
    for (int i = 0; i < 1000; ++i) nums.push_back(i);
    EXPECT_FALSE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, LargeInputWithDuplicateAtEnd) {
    Solution s;
    std::vector<int> nums;
    for (int i = 0; i < 10000; ++i) nums.push_back(i);
    nums.push_back(9999); // Duplicate at the very end
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, LargeInputWithDuplicateAtStart) {
    Solution s;
    std::vector<int> nums{0};
    for (int i = 1; i < 10000; ++i) nums.push_back(i);
    nums.push_back(0); // Duplicate of the first element
    EXPECT_TRUE(s.contains_duplicate(nums));
}

// ---- Special Cases (Negatives, Zeros, Large Values) ----
TEST(ContainsDuplicate, NegativeNumbers) {
    Solution s;
    std::vector<int> nums{-1, -2, -3, -1};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, MixedPosNeg) {
    Solution s;
    std::vector<int> nums{-1, 1, -2, 2, -1};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, ZerosAndOthers) {
    Solution s;
    std::vector<int> nums{0, 1, 2, 3, 0};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, DistantDuplicates) {
    Solution s;
    std::vector<int> nums{100, 200, 300, 400, 100};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, LargeAllSame) {
    Solution s;
    std::vector<int> nums(10000, 5);
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, AlternatingPattern) {
    Solution s;
    std::vector<int> nums{1, 2, 1, 2, 3, 4, 5};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, EdgeMinMaxValues) {
    Solution s;
    std::vector<int> nums{-1000000000, 0, 1000000000, -1000000000};
    EXPECT_TRUE(s.contains_duplicate(nums));
}

TEST(ContainsDuplicate, EdgeMaxValuesNoDuplicate) {
    Solution s;
    std::vector<int> nums{1000000000, -1000000000, 0};
    EXPECT_FALSE(s.contains_duplicate(nums));
}