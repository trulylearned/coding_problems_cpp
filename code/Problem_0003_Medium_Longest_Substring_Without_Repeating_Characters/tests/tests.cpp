#include "solution.h" // Assumes one of the Solution classes is in this header
#include <gtest/gtest.h>
#include <string>

// Examples from LeetCode
TEST(LongestSubstring, Example1) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3); // "abc"
}

TEST(LongestSubstring, Example2) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1); // "b"
}

TEST(LongestSubstring, Example3) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3); // "wke"
}

// Edge Cases
TEST(LongestSubstring, EmptyString) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring(""), 0);
}

TEST(LongestSubstring, SingleChar) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("a"), 1);
}

TEST(LongestSubstring, TwoSameChars) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("aa"), 1);
}

TEST(LongestSubstring, TwoDifferentChars) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("ab"), 2);
}

// Typical Cases
TEST(LongestSubstring, RepeatingPattern) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("ababab"), 2); // "ab"
}

TEST(LongestSubstring, NumbersAndLetters) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("a1b2c3a4"), 7); // "1b2c3a4"
}

TEST(LongestSubstring, WithSpaces) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("a b c a b"), 3); // "a b", " b c", etc.
}

TEST(LongestSubstring, Symbols) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("!@#!!@#"), 3); // "!@#"
}

TEST(LongestSubstring, LongNoRepeats) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyz"), 26);
}

TEST(LongestSubstring, RepeatsAtEnd) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcddef"), 4); // "abcd"
}

TEST(LongestSubstring, RepeatsAtStart) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("aabcde"), 5); // "abcde"
}

TEST(LongestSubstring, MixedCase) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("AaBbCcAa"), 6); // "AaBbCc"
}

// Special Cases
TEST(LongestSubstring, ComplexSymbols) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("a@b@c@d"), 3); // "a@b", "b@c", "c@d"
}

TEST(LongestSubstring, RepeatsInside) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcdecfghi"), 7); // "decfghi"
}

TEST(LongestSubstring, RepeatsWithGaps) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("abcadbbef"), 4); // "bcad" or "cadb"
}

TEST(LongestSubstring, AllSameButOne) {
    Solution s;
    EXPECT_EQ(s.lengthOfLongestSubstring("aaaaabaaaaa"), 2); // "ab" or "ba"
}

TEST(LongestSubstring, LargeInput) {
    Solution s;
    std::string big(50000, 'a');
    EXPECT_EQ(s.lengthOfLongestSubstring(big), 1);
}