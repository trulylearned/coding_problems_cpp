#include "solution.h" // Assumes solution.h contains one of the Solution classes
#include <gtest/gtest.h>
#include <vector>

TEST(ProductExceptSelf, LC_Example1) {
    Solution solution;
    std::vector<int> input_nums{1, 2, 3, 4};
    std::vector<int> expected{24, 12, 8, 6};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, LC_Example2) {
    Solution solution;
    std::vector<int> input_nums{-1, 1, 0, -3, 3};
    std::vector<int> expected{0, 0, 9, 0, 0};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, Custom_A_AllPositive) {
    Solution solution;
    std::vector<int> input_nums{2, 3, 4, 5};
    std::vector<int> expected{60, 40, 30, 24};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, Custom_B_WithOneZero) {
    Solution solution;
    std::vector<int> input_nums{0, 1, 2, 3};
    std::vector<int> expected{6, 0, 0, 0};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, MinLengthTwo_Positive) {
    Solution solution;
    std::vector<int> input_nums{5, 7};
    std::vector<int> expected{7, 5};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, AllOnes) {
    Solution solution;
    std::vector<int> input_nums{1, 1, 1, 1, 1};
    std::vector<int> expected{1, 1, 1, 1, 1};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, AllNegatives_EvenCount) {
    Solution solution;
    std::vector<int> input_nums{-2, -3, -4, -5};
    std::vector<int> expected{-60, -40, -30, -24};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, AllNegatives_OddCount) {
    Solution solution;
    std::vector<int> input_nums{-2, -3, -4};
    std::vector<int> expected{12, 8, 6};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, ContainsTwoZeros) {
    Solution solution;
    std::vector<int> input_nums{0, 2, 0, 3};
    std::vector<int> expected{0, 0, 0, 0};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, ZeroAtStart) {
    Solution solution;
    std::vector<int> input_nums{0, 2, 3, 4};
    std::vector<int> expected{24, 0, 0, 0};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, ZeroAtEnd) {
    Solution solution;
    std::vector<int> input_nums{2, 3, 4, 0};
    std::vector<int> expected{0, 0, 0, 24};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, MixedSigns) {
    Solution solution;
    std::vector<int> input_nums{-1, 2, -3, 4};
    std::vector<int> expected{-24, 12, -8, 6};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, IncludesOneAndMinusOne) {
    Solution solution;
    std::vector<int> input_nums{-1, 1, -1, 1};
    std::vector<int> expected{-1, 1, -1, 1};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, LargeButWithinRange) {
    Solution solution;
    std::vector<int> input_nums{30, -30, 2, -2};
    std::vector<int> expected{120, -120, 1800, -1800};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, AlternatingSmall) {
    Solution solution;
    std::vector<int> input_nums{2, -1, 2, -1, 2};
    std::vector<int> expected{4, -8, 4, -8, 4};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, RepeatedNumbers) {
    Solution solution;
    std::vector<int> input_nums{3, 3, 3};
    std::vector<int> expected{9, 9, 9};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, ContainsZeroMiddle) {
    Solution solution;
    std::vector<int> input_nums{5, 0, 2};
    std::vector<int> expected{0, 10, 0};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, ManyOnesAndZero) {
    Solution solution;
    std::vector<int> input_nums{1, 1, 0, 1, 1, 1};
    std::vector<int> expected{0, 0, 1, 0, 0, 0};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, IncreasingSequence) {
    Solution solution;
    std::vector<int> input_nums{1, 2, 3, 4, 5, 6};
    std::vector<int> expected{720, 360, 240, 180, 144, 120};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}

TEST(ProductExceptSelf, RandomSmallWithMultipleZeros) {
    Solution solution;
    std::vector<int> input_nums{-2, 0, 1, -3, 0, 4};
    std::vector<int> expected{0, 0, 0, 0, 0, 0};
    EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
}