#include "solution.h"
#include <gtest/gtest.h>
#include <string>

// LeetCode Examples
TEST(ValidParentheses, Example1) {
    Solution s;
    EXPECT_TRUE(s.isValid("()"));
}

TEST(ValidParentheses, Example2) {
    Solution s;
    EXPECT_TRUE(s.isValid("()[]{}"));
}

TEST(ValidParentheses, Example3) {
    Solution s;
    EXPECT_FALSE(s.isValid("(]"));
}

// Typical Valid Cases
TEST(ValidParentheses, NestedCorrectly) {
    Solution s;
    EXPECT_TRUE(s.isValid("([{}])"));
}

TEST(ValidParentheses, SequentialPairs) {
    Solution s;
    EXPECT_TRUE(s.isValid("()(){}{}[][]"));
}

TEST(ValidParentheses, ComplexValid) {
    Solution s;
    EXPECT_TRUE(s.isValid("{[()]}{([])}"));
}

// Typical Invalid Cases
TEST(ValidParentheses, NestedIncorrectly) {
    Solution s;
    EXPECT_FALSE(s.isValid("([)]"));
}

TEST(ValidParentheses, WrongClosureType) {
    Solution s;
    EXPECT_FALSE(s.isValid("{[}"));
}

TEST(ValidParentheses, ExtraClosingBracket) {
    Solution s;
    EXPECT_FALSE(s.isValid("{[()]}}"));
}

TEST(ValidParentheses, ComplexInvalid) {
    Solution s;
    EXPECT_FALSE(s.isValid("{[(])}{([])}"));
}

// Edge Cases
TEST(ValidParentheses, EmptyString) {
    Solution s;
    EXPECT_TRUE(s.isValid(""));
}

TEST(ValidParentheses, SingleOpening) {
    Solution s;
    EXPECT_FALSE(s.isValid("("));
}

TEST(ValidParentheses, SingleClosing) {
    Solution s;
    EXPECT_FALSE(s.isValid(")"));
}

TEST(ValidParentheses, AllOpening) {
    Solution s;
    EXPECT_FALSE(s.isValid("(((([[[[{{{{"));
}

TEST(ValidParentheses, AllClosing) {
    Solution s;
    EXPECT_FALSE(s.isValid("))))]]]]}}}}"));
}

// Large/Special Cases
TEST(ValidParentheses, DeeplyNestedValid) {
    Solution s;
    EXPECT_TRUE(s.isValid("(((([[[{{{}}}]]]))))"));
}

TEST(ValidParentheses, LongValidSequence) {
    Solution s;
    std::string long_valid(5000, '(');
    long_valid += std::string(5000, ')');
    EXPECT_TRUE(s.isValid(long_valid));
}

TEST(ValidParentheses, LongInvalidSequence) {
    Solution s;
    std::string long_invalid(5000, '(');
    long_invalid += std::string(4999, ')');
    EXPECT_FALSE(s.isValid(long_invalid));
}

TEST(ValidParentheses, InterleavedValid) {
    Solution s;
    EXPECT_TRUE(s.isValid("[{()}([]{})]"));
}

TEST(ValidParentheses, JustOnePair) {
    Solution s;
    EXPECT_TRUE(s.isValid("{}"));
}