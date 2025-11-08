#include "solution.h" // Assumes solution is in "solution.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

// Helper function to compare two vectors of triplets
// This is crucial because the order of triplets and the order
// of numbers within a triplet doesn't matter.
void ExpectTripletsEqualUnordered(
    std::vector<std::vector<int>> expected,
    std::vector<std::vector<int>> actual) 
{
    // Sort numbers within each triplet
    auto sort_triplets = [](std::vector<std::vector<int>>& v) {
        for (auto& triplet : v) {
            std::sort(triplet.begin(), triplet.end());
        }
        // Sort the outer vector of triplets
        std::sort(v.begin(), v.end());
    };
    
    sort_triplets(expected);
    sort_triplets(actual);
    
    EXPECT_EQ(expected, actual);
}

// ---- LeetCode Examples ----
TEST(ThreeSum, LeetCodeExample1) {
    Solution s;
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, LeetCodeExample2) {
    Solution s;
    std::vector<int> nums{0, 1, 1};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, LeetCodeExample3) {
    Solution s;
    std::vector<int> nums{0, 0, 0};
    std::vector<std::vector<int>> expected = {{0, 0, 0}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

// ---- Edge Cases ----
TEST(ThreeSum, EmptyInput) {
    Solution s;
    std::vector<int> nums{};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, TwoElementsOnly) {
    Solution s;
    std::vector<int> nums{1, -1};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, MinSizeInput_Solution) {
    Solution s;
    std::vector<int> nums{1, -1, 0};
    std::vector<std::vector<int>> expected = {{-1, 0, 1}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, MinSizeInput_NoSolution) {
    Solution s;
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

// ---- All Zeros ----
TEST(ThreeSum, AllZerosSize3) {
    Solution s;
    std::vector<int> nums{0, 0, 0};
    std::vector<std::vector<int>> expected = {{0, 0, 0}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, AllZerosSize4) {
    Solution s;
    std::vector<int> nums{0, 0, 0, 0};
    std::vector<std::vector<int>> expected = {{0, 0, 0}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

// ---- No Solutions ----
TEST(ThreeSum, AllPositive) {
    Solution s;
    std::vector<int> nums{1, 2, 3, 4, 5};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, AllNegative) {
    Solution s;
    std::vector<int> nums{-1, -2, -3, -4, -5};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, MixedNoSolution) {
    Solution s;
    std::vector<int> nums{-1, -2, 4, 5, 6};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

// ---- Duplicate Handling ----
TEST(ThreeSum, Duplicates_OneSolution) {
    Solution s;
    std::vector<int> nums{-1, 0, 1, 0};
    std::vector<std::vector<int>> expected = {{-1, 0, 1}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, Duplicates_MultipleSolutions) {
    Solution s;
    std::vector<int> nums{-2, 0, 1, 1, 2};
    std::vector<std::vector<int>> expected = {{-2, 0, 2}, {-2, 1, 1}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, AllDuplicates_OneSolution) {
    Solution s;
    std::vector<int> nums{-1, -1, -1, 2, 2, 2};
    std::vector<std::vector<int>> expected = {{-1, -1, 2}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, AllDuplicates_NoSolution) {
    Solution s;
    std::vector<int> nums{-1, -1, 1, 1};
    std::vector<std::vector<int>> expected = {};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

// ---- General & Large Values ----
TEST(ThreeSum, MultipleSolutions) {
    Solution s;
    std::vector<int> nums{-5, 2, 3, 0, 1, -1};
    std::vector<std::vector<int>> expected = {{-5, 2, 3}, {-1, 0, 1}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, LargeValues) {
    Solution s;
    std::vector<int> nums{100000, -100000, 0};
    std::vector<std::vector<int>> expected = {{-100000, 0, 100000}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, LargeMixedValues) {
    Solution s;
    std::vector<int> nums{-100, -200, 300, 5, -10, 10};
    std::vector<std::vector<int>> expected = {{-200, -100, 300}, {-10, 0, 10}};
    // Test input had no zero, let's fix that.
    nums = {-100, -200, 300, 5, -10, 10, 0};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}

TEST(ThreeSum, MaxN_Solution) {
    Solution s;
    std::vector<int> nums(3000, 1);
    nums[0] = -2;
    nums[1] = 1; // Array is [-2, 1, 1, 1, ..., 1]
    std::vector<std::vector<int>> expected = {{-2, 1, 1}};
    ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
}