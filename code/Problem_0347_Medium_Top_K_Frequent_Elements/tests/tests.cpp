#include "solution.h"
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_set>

// Helper function to compare two vectors as sets
bool vectors_are_equal_as_sets(std::vector<int> v1, std::vector<int> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    std::unordered_set<int> s1(v1.begin(), v1.end());
    std::unordered_set<int> s2(v2.begin(), v2.end());
    return s1 == s2;
}

TEST(TopKFrequent, Example1) {
    Solution s;
    std::vector<int> nums{1,1,1,2,2,3};
    int k = 2;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {1,2}));
}

TEST(TopKFrequent, Example2) {
    Solution s;
    std::vector<int> nums{1};
    int k = 1;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {1}));
}

TEST(TopKFrequent, Example3FromLeetCode) {
    Solution s;
    std::vector<int> nums{1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {1,2}));
}

TEST(TopKFrequent, AllSame) {
    Solution s;
    std::vector<int> nums(10, 7);
    int k = 1;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {7}));
}

TEST(TopKFrequent, NegativeNumbers) {
    Solution s;
    std::vector<int> nums{-1,-1,-2,-2,-2,-3};
    int k = 2;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {-1,-2}));
}

TEST(TopKFrequent, KEqualsAllUnique) {
    Solution s;
    std::vector<int> nums{4,1,2,2,3,3,3,4,4,4,5};
    int k = 5; // 5 unique elements: 1,2,3,4,5
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {1,2,3,4,5}));
}

TEST(TopKFrequent, SingleElementArray) {
    Solution s;
    std::vector<int> nums{42};
    int k = 1;
    EXPECT_EQ(s.topKFrequent(nums, k), std::vector<int>({42}));
}

TEST(TopKFrequent, FrequenciesTiedButKIncludesAllTies) {
    Solution s;
    std::vector<int> nums{5,6,5,6}; // 5:2, 6:2
    int k = 2;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {5,6}));
}

TEST(TopKFrequent, LargeInputAllSame) {
    Solution s;
    std::vector<int> nums(100000, 1);
    int k = 1;
    EXPECT_EQ(s.topKFrequent(nums, k), std::vector<int>({1}));
}

TEST(TopKFrequent, MixedWithClearWinner) {
    Solution s;
    std::vector<int> nums{1,2,2,3,3,3,4,4,4,4};
    int k = 2; // Top 2 are 4 (freq 4) and 3 (freq 3)
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {3,4}));
}

TEST(TopKFrequent, AllUniqueKIs2) {
    Solution s;
    std::vector<int> nums{5,5,4,4,3,2,1}; // 5:2, 4:2, 3:1, 2:1, 1:1
    int k = 2; // Top 2 are 5 and 4
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {4,5}));
}

TEST(TopKFrequent, KIsOneWithTieForFirst) {
    Solution s;
    std::vector<int> nums{1,1,1,2,2,2,3}; // 1:3, 2:3, 3:1
    // int k = 1; // Fails guarantee, but test case is from LC Ex 3 logic
    // Wait, no. The guarantee is the *answer* is unique.
    // If k=1, the answer could be {1} or {2}. This test is invalid.
    // A valid test would be:
    std::vector<int> nums_valid{1,1,1,2,2,3}; // 1:3, 2:2, 3:1
    int k_valid = 1;
    auto res = s.topKFrequent(nums_valid, k_valid);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {1}));
}

TEST(TopKFrequent, LargeK) {
    Solution s;
    std::vector<int> nums{4,1,2,2,3,3,3,4,4,4}; // 4:4, 3:3, 2:2, 1:1
    int k = 3;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {2,3,4}));
}

TEST(TopKFrequent, MixedPositiveNegative) {
    Solution s;
    std::vector<int> nums{1,1,1, -5,-5, 100, 100, 100, 100, -5, 2};
    // 1:3, -5:3, 100:4, 2:1
    int k = 3; // Top 3 are 100, 1, -5
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {100, 1, -5}));
}

TEST(TopKFrequent, ZerosAndNegatives) {
    Solution s;
    std::vector<int> nums{0,0,0, -1, -2, -2, 0};
    // 0:4, -2:2, -1:1
    int k = 2;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {0, -2}));
}

TEST(TopKFrequent, AllUniqueKIsOne) {
    Solution s;
    std::vector<int> nums{10,20,30,40,40}; // 40:2, 10:1, 20:1, 30:1
    int k = 1;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {40}));
}

TEST(TopKFrequent, LargeNumbers) {
    Solution s;
    std::vector<int> nums{10000, -10000, 10000, 5, 5, 5};
    // 5:3, 10000:2, -10000:1
    int k = 2;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {5, 10000}));
}

TEST(TopKFrequent, LongArrayScattered) {
    Solution s;
    std::vector<int> nums{9,1,9,2,9,3,9,4,9,5,1,2,1,3,1,4,1};
    // 9:5, 1:5, 2:2, 3:2, 4:2, 5:1
    int k = 2;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {1, 9}));
}

TEST(TopKFrequent, FrequenciesTiedKDoesNotIncludeTies) {
    Solution s;
    std::vector<int> nums{1,1,1, 2,2, 3,3, 4,4, 5,5,5,5};
    // 5:4, 1:3, 2:2, 3:2, 4:2
    int k = 2; // Top 2 are 5 (freq 4) and 1 (freq 3)
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {1, 5}));
}

TEST(TopKFrequent, KIsOne) {
    Solution s;
    std::vector<int> nums{1,2,3,4,4,5,5,5};
    // 5:3, 4:2, 1:1, 2:1, 3:1
    int k = 1;
    auto res = s.topKFrequent(nums, k);
    EXPECT_TRUE(vectors_are_equal_as_sets(res, {5}));
}