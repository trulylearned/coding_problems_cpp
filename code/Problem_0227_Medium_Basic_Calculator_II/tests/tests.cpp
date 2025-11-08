#include "solution.h"
#include <gtest/gtest.h>

// 1. Example from LeetCode
TEST(BasicCalculatorII, Example1) {
    Solution s;
    EXPECT_EQ(s.calculate("3+2*2"), 7);
}

// 2. Example from LeetCode
TEST(BasicCalculatorII, Example2) {
    Solution s;
    EXPECT_EQ(s.calculate("3/2"), 1);
}

// 3. Example from LeetCode
TEST(BasicCalculatorII, Example3) {
    Solution s;
    EXPECT_EQ(s.calculate("3+5 / 2"), 5);
}

// 4. Custom example from our walkthrough
TEST(BasicCalculatorII, Custom1) {
    Solution s;
    EXPECT_EQ(s.calculate("10+2*3"), 16);
}

// 5. Custom example from our walkthrough
TEST(BasicCalculatorII, Custom2) {
    Solution s;
    EXPECT_EQ(s.calculate("14-3/2"), 13);
}

// 6. Test with spaces
TEST(BasicCalculatorII, Spaces) {
    Solution s;
    EXPECT_EQ(s.calculate("  4 + 5 * 2  "), 14);
}

// 7. Test all addition
TEST(BasicCalculatorII, AllAdd) {
    Solution s;
    EXPECT_EQ(s.calculate("1+2+3+4+5"), 15);
}

// 8. Test all subtraction
TEST(BasicCalculatorII, AllSubtract) {
    Solution s;
    EXPECT_EQ(s.calculate("10-2-3"), 5);
}

// 9. Mixed precedence
TEST(BasicCalculatorII, Mixed1) {
    Solution s;
    EXPECT_EQ(s.calculate("10-2*3"), 4);
}

// 10. Mixed precedence
TEST(BasicCalculatorII, Mixed2) {
    Solution s;
    EXPECT_EQ(s.calculate("8+4/2"), 10);
}

// 11. Truncation test (positive)
TEST(BasicCalculatorII, TruncationTest) {
    Solution s;
    EXPECT_EQ(s.calculate("10/3"), 3);
}

// 12. Truncation test (mixed)
TEST(BasicCalculatorII, TruncationMixed) {
    Solution s;
    EXPECT_EQ(s.calculate("7-10/3"), 4);
}

// 13. Long expression - **CORRECTED**
TEST(BasicCalculatorII, LongExpression) {
    Solution s;
    // 2*3=6, 4*5=20, 6/2=3
    // 6 + 20 - 3 + 10 = 33
    EXPECT_EQ(s.calculate("2*3+4*5-6/2+10"), 33);
}

// 14. Multiple spaces
TEST(BasicCalculatorII, MultipleSpaces) {
    Solution s;
    EXPECT_EQ(s.calculate(" 2 * 3 +   5 "), 11);
}

// 15. Division truncation (simpler)
TEST(BasicCalculatorII, DivisionTruncate) {
    Solution s;
    EXPECT_EQ(s.calculate("7/2"), 3);
}

// 16. Chained multiplication/division (should be left-to-right)
TEST(BasicCalculatorII, ChainMultDiv) {
    Solution s;
    // 100/5 = 20
    // 20/2 = 10
    EXPECT_EQ(s.calculate("100/5/2"), 10);
}

// 17. Big numbers
TEST(BasicCalculatorII, BigNumbers) {
    Solution s;
    EXPECT_EQ(s.calculate("100000+200000*2"), 500000);
}

// 18. Edge case: single number
TEST(BasicCalculatorII, OnlyNumber) {
    Solution s;
    EXPECT_EQ(s.calculate("42"), 42);
}

// 19. Edge case: starts with space
TEST(BasicCalculatorII, StartWithSpace) {
    Solution s;
    EXPECT_EQ(s.calculate("   8/2+1"), 5);
}

// 20. Edge case: Zero values
TEST(BasicCalculatorII, ZeroTest) {
    Solution s;
    EXPECT_EQ(s.calculate("0*10 + 0/5 - 0"), 0);
}