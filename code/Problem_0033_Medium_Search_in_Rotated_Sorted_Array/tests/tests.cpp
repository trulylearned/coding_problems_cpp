#include "solution.h"
#include <gtest/gtest.h>
#include <vector>

// 1. Example 1 from LeetCode
TEST(SearchInRotatedSortedArray, Example1) {
    Solution s;
    std::vector<int> nums{4,5,6,7,0,1,2};
    EXPECT_EQ(s.search(nums, 0), 4);
}

// 2. Example 2 from LeetCode
TEST(SearchInRotatedSortedArray, Example2) {
    Solution s;
    std::vector<int> nums{4,5,6,7,0,1,2};
    EXPECT_EQ(s.search(nums, 3), -1);
}

// 3. Example 3 from LeetCode (Single element)
TEST(SearchInRotatedSortedArray, Example3) {
    Solution s;
    std::vector<int> nums{1};
    EXPECT_EQ(s.search(nums, 0), -1);
}

// 4. Custom example 1
TEST(SearchInRotatedSortedArray, Custom1) {
    Solution s;
    std::vector<int> nums{6,7,0,1,2,4,5};
    EXPECT_EQ(s.search(nums, 4), 5);
}

// 5. Custom example 2 (larger rotation)
TEST(SearchInRotatedSortedArray, Custom2) {
    Solution s;
    std::vector<int> nums{3,4,5,6,7,8,1,2};
    EXPECT_EQ(s.search(nums, 8), 5);
}

// 6. No rotation (standard binary search)
TEST(SearchInRotatedSortedArray, NotRotated) {
    Solution s;
    std::vector<int> nums{1,2,3,4,5,6,7,8};
    EXPECT_EQ(s.search(nums, 5), 4);
}

// 7. No rotation, target is last element
TEST(SearchInRotatedSortedArray, NotRotatedTargetLast) {
    Solution s;
    std::vector<int> nums{1,2,3,4,5,6,7,8};
    EXPECT_EQ(s.search(nums, 8), 7);
}

// 8. Target in the "left" sorted part
TEST(SearchInRotatedSortedArray, LeftSideTarget) {
    Solution s;
    std::vector<int> nums{5,6,7,8,1,2,3,4};
    EXPECT_EQ(s.search(nums, 6), 1);
}

// 9. Target in the "right" sorted part
TEST(SearchInRotatedSortedArray, RightSideTarget) {
    Solution s;
    std::vector<int> nums{5,6,7,8,1,2,3,4};
    EXPECT_EQ(s.search(nums, 3), 6);
}

// 10. Edge Case: Single element, target found
TEST(SearchInRotatedSortedArray, SingleElementFound) {
    Solution s;
    std::vector<int> nums{10};
    EXPECT_EQ(s.search(nums, 10), 0);
}

// 11. Edge Case: Two elements, rotated, target found
TEST(SearchInRotatedSortedArray, TwoElementsFound) {
    Solution s;
    std::vector<int> nums{2,1};
    EXPECT_EQ(s.search(nums, 1), 1);
}

// 12. Edge Case: Two elements, not found
TEST(SearchInRotatedSortedArray, TwoElementsNotFound) {
    Solution s;
    std::vector<int> nums{2,1};
    EXPECT_EQ(s.search(nums, 3), -1);
}

// 13. Large input, not rotated, target first
TEST(SearchInRotatedSortedArray, LargeInputTargetFirst) {
    Solution s;
    std::vector<int> nums(5000);
    for (int i = 0; i < 5000; ++i) nums[i] = i;
    EXPECT_EQ(s.search(nums, 0), 0);
}

// 14. Large input, not rotated, target last
TEST(SearchInRotatedSortedArray, LargeInputTargetLast) {
    Solution s;
    std::vector<int> nums(5000);
    for (int i = 0; i < 5000; ++i) nums[i] = i;
    EXPECT_EQ(s.search(nums, 4999), 4999);
}

// 15. Large input, rotated
TEST(SearchInRotatedSortedArray, RotatedLarge) {
    Solution s;
    std::vector<int> nums;
    for (int i = 2500; i < 5000; ++i) nums.push_back(i);
    for (int i = 0; i < 2500; ++i) nums.push_back(i);
    // nums is [2500, ..., 4999, 0, ..., 2499]
    EXPECT_EQ(s.search(nums, 1250), 3750); // 1250 is at index (5000-2500) + 1250
}

// 16. Negative numbers, not rotated
TEST(SearchInRotatedSortedArray, NegativeNumbers) {
    Solution s;
    std::vector<int> nums{-4,-3,-2,-1,0,1,2,3};
    EXPECT_EQ(s.search(nums, -3), 1);
}

// 17. Negative numbers, rotated
TEST(SearchInRotatedSortedArray, RotatedNegatives) {
    Solution s;
    std::vector<int> nums{0,1,2,3,-4,-3,-2,-1};
    EXPECT_EQ(s.search(nums, -3), 5);
}

// 18. Target does not exist, various rotations
TEST(SearchInRotatedSortedArray, TargetNotExist) {
    Solution s;
    std::vector<int> nums{10,12,14,2,4,6,8};
    EXPECT_EQ(s.search(nums, 5), -1);
}

// 19. Target at the pivot point (largest element)
TEST(SearchInRotatedSortedArray, TargetAtPivot) {
    Solution s;
    std::vector<int> nums{4,5,6,7,0,1,2};
    EXPECT_EQ(s.search(nums, 7), 3);
}

// 20. Edge Case: Empty array
TEST(SearchInRotatedSortedArray, EmptyArray) {
    Solution s;
    std::vector<int> nums{};
    EXPECT_EQ(s.search(nums, 5), -1);
}