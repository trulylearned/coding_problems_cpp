#include "solution.h" // Assumes 'solution.h' contains one of the Solution classes
#include <gtest/gtest.h>
#include <vector>

// Make sure all tests use the snake_case function name
TEST(MajorityElement, Example1) {
    Solution s;
    std::vector<int> nums{3, 2, 3};
    EXPECT_EQ(s.majority_element(nums), 3);
}

TEST(MajorityElement, Example2) {
    Solution s;
    std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    EXPECT_EQ(s.majority_element(nums), 2);
}

// Custom tests
TEST(MajorityElement, SingleElement) {
    Solution s;
    std::vector<int> nums{42};
    EXPECT_EQ(s.majority_element(nums), 42);
}

TEST(MajorityElement, TwoElementsSame) {
    Solution s;
    std::vector<int> nums{7, 7};
    EXPECT_EQ(s.majority_element(nums), 7);
}

TEST(MajorityElement, MajorityAtEnd) {
    Solution s;
    std::vector<int> nums{1, 2, 3, 4, 4, 4, 4};
    EXPECT_EQ(s.majority_element(nums), 4);
}

// THIS TEST IS NOW FIXED
TEST(MajorityElement, MajorityAtStart) {
    Solution s;
    // Old invalid test: {9, 9, 9, 2, 2, 3} (n=6, threshold=3, count=3. Not majority)
    std::vector<int> nums{9, 9, 9, 1, 2}; // (n=5, threshold=2, count=3. Is majority)
    EXPECT_EQ(s.majority_element(nums), 9);
}

TEST(MajorityElement, Alternating) {
    Solution s;
    std::vector<int> nums{5, 1, 5, 1, 5, 1, 5};
    EXPECT_EQ(s.majority_element(nums), 5);
}

TEST(MajorityElement, NegativeNumbers) {
    Solution s;
    std::vector<int> nums{-1, -1, -1, 2, 3};
    EXPECT_EQ(s.majority_element(nums), -1);
}

TEST(MajorityElement, MixedSigns) {
    Solution s;
    std::vector<int> nums{-2, -2, 3, -2, 3, -2};
    EXPECT_EQ(s.majority_element(nums), -2);
}

TEST(MajorityElement, LargeInputSameValue) {
    Solution s;
    std::vector<int> nums(10000, 8);
    EXPECT_EQ(s.majority_element(nums), 8);
}

TEST(MajorityElement, HalfBoundary) {
    Solution s;
    std::vector<int> nums{1, 1, 2, 2, 2};
    EXPECT_EQ(s.majority_element(nums), 2);
}

TEST(MajorityElement, Interleaved) {
    Solution s;
    std::vector<int> nums{3, 4, 3, 4, 3, 3, 4, 3};
    EXPECT_EQ(s.majority_element(nums), 3);
}

TEST(MajorityElement, LargeDeterministic) {
    Solution s;
    std::vector<int> nums;
    // Creates 8000 '6's and 2000 '7's. Majority is 6.
    for (int i = 0; i < 10000; ++i)
        nums.push_back(i % 5 == 0 ? 7 : 6); 
    EXPECT_EQ(s.majority_element(nums), 6);
}

TEST(MajorityElement, WithZeros) {
    Solution s;
    std::vector<int> nums{0, 0, 1, 0, 2, 0, 3, 0, 0};
    EXPECT_EQ(s.majority_element(nums), 0);
}

TEST(MajorityElement, BoundaryCaseSmall) {
    Solution s;
    std::vector<int> nums{1, 1, 2};
    EXPECT_EQ(s.majority_element(nums), 1);
}

TEST(MajorityElement, OddCountMajority) {
    Solution s;
    std::vector<int> nums{4, 4, 5, 4, 5, 4, 4};
    EXPECT_EQ(s.majority_element(nums), 4);
}

TEST(MajorityElement, SparseDistribution) {
    Solution s;
    std::vector<int> nums{9, 1, 9, 2, 9, 3, 9, 4, 9};
    EXPECT_EQ(s.majority_element(nums), 9);
}

TEST(MajorityElement, DifferentMajorities) {
    Solution s;
    std::vector<int> nums{10, 10, 10, 2, 2, 2, 10};
    EXPECT_EQ(s.majority_element(nums), 10);
}

TEST(MajorityElement, CheckPerformance) {
    Solution s;
    std::vector<int> nums(50000, 1);
    EXPECT_EQ(s.majority_element(nums), 1);
}