#include "solution.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>      // For std::mt19937, std::shuffle
#include <numeric>     // For std::iota
#include <climits>     // For INT_MAX

// 1. LeetCode Example 1
TEST(LongestConsecutive, Example1) {
    Solution s;
    std::vector<int> nums{100, 4, 200, 1, 3, 2};
    EXPECT_EQ(s.longestConsecutive(nums), 4);
}

// 2. LeetCode Example 2
TEST(LongestConsecutive, Example2) {
    Solution s;
    std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    EXPECT_EQ(s.longestConsecutive(nums), 9);
}

// 3. Custom example from LeetCode
TEST(LongestConsecutive, Example3) {
    Solution s;
    std::vector<int> nums{1, 0, 1, 2};
    EXPECT_EQ(s.longestConsecutive(nums), 3);
}

// 4. Edge Case: Empty
TEST(LongestConsecutive, Empty) {
    Solution s;
    std::vector<int> nums{};
    EXPECT_EQ(s.longestConsecutive(nums), 0);
}

// 5. Edge Case: Single Element
TEST(LongestConsecutive, Single) {
    Solution s;
    std::vector<int> nums{42};
    EXPECT_EQ(s.longestConsecutive(nums), 1);
}

// 6. Edge Case: All Duplicates
TEST(LongestConsecutive, AllDuplicates) {
    Solution s;
    std::vector<int> nums{5, 5, 5, 5};
    EXPECT_EQ(s.longestConsecutive(nums), 1);
}

// 7. Special Case: Negative Numbers Run
TEST(LongestConsecutive, NegativesRun) {
    Solution s;
    std::vector<int> nums{-2, -1, 0};
    EXPECT_EQ(s.longestConsecutive(nums), 3);
}

// 8. Typical Case: No Runs
TEST(LongestConsecutive, NoRuns) {
    Solution s;
    std::vector<int> nums{10, 30, 20};
    EXPECT_EQ(s.longestConsecutive(nums), 1);
}

// 9. Typical Case: Longest run at the start
TEST(LongestConsecutive, LongAtStart) {
    Solution s;
    std::vector<int> nums{1, 2, 3, 10};
    EXPECT_EQ(s.longestConsecutive(nums), 3);
}

// 10. Special Case: Large Negative Numbers
TEST(LongestConsecutive, WithLargeNegatives) {
    Solution s;
    std::vector<int> nums{-1000000000, -999999999, -999999998};
    EXPECT_EQ(s.longestConsecutive(nums), 3);
}

// 11. Typical Case: Reverse Order
TEST(LongestConsecutive, ReverseOrder) {
    Solution s;
    std::vector<int> nums{4, 3, 2, 1};
    EXPECT_EQ(s.longestConsecutive(nums), 4);
}

// 12. Typical Case: Scrambled Negatives
TEST(LongestConsecutive, NonConsecutiveNegatives) {
    Solution s;
    std::vector<int> nums{-3, -1, -2, -4};
    EXPECT_EQ(s.longestConsecutive(nums), 4);
}

// 13. Special Case: Duplicates Inside a Run
TEST(LongestConsecutive, DuplicatesInsideRun) {
    Solution s;
    std::vector<int> nums{1, 2, 2, 3};
    EXPECT_EQ(s.longestConsecutive(nums), 3);
}

// 14. Typical Case: Mixed Gaps
TEST(LongestConsecutive, MixedGaps) {
    Solution s;
    std::vector<int> nums{100, 101, 102, 50, 51};
    EXPECT_EQ(s.longestConsecutive(nums), 3);
}

// 15. Typical Case: Alternating Order
TEST(LongestConsecutive, AlternatingOrder) {
    Solution s;
    std::vector<int> nums{1, 3, 2, 5, 4};
    EXPECT_EQ(s.longestConsecutive(nums), 5);
}

// 16. Typical Case: Single Gap Inside
TEST(LongestConsecutive, SingleGapInside) {
    Solution s;
    std::vector<int> nums{1, 2, 4, 5, 6};
    EXPECT_EQ(s.longestConsecutive(nums), 3); // [4,5,6]
}

// 17. Typical Case: Two Runs, Choose Longer
TEST(LongestConsecutive, TwoRunsChooseLonger) {
    Solution s;
    std::vector<int> nums{10, 11, 12, 1, 2, 3, 4};
    EXPECT_EQ(s.longestConsecutive(nums), 4);
}

// 18. Special Case: Run Crosses Zero
TEST(LongestConsecutive, CrossZero) {
    Solution s;
    std::vector<int> nums{-1, 0, 1, 2, 2};
    EXPECT_EQ(s.longestConsecutive(nums), 4);
}

// 19. Large Case: 10,000 sequential numbers
TEST(LongestConsecutive, LargeSequential) {
    Solution s;
    std::vector<int> nums(10000);
    std::iota(nums.begin(), nums.end(), 0);
    // Shuffle to ensure unsorted input logic is tested
    std::mt19937 rng(123); // Fixed seed for reproducible tests
    std::shuffle(nums.begin(), nums.end(), rng);
    EXPECT_EQ(s.longestConsecutive(nums), 10000);
}

// 20. Special Case: Near INT_MAX
TEST(LongestConsecutive, NearIntMax) {
    Solution s;
    std::vector<int> nums{INT_MAX - 2, INT_MAX - 1, INT_MAX};
    EXPECT_EQ(s.longestConsecutive(nums), 3);
}