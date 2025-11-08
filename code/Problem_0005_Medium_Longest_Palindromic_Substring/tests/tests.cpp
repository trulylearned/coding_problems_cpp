#include "solution.h" // Assumes our class is in "solution.h"
#include <gtest/gtest.h>

// Examples from LeetCode
TEST(LongestPalindrome, Example1) {
    Solution s;
    // For "babad", both "bab" and "aba" are valid.
    // Our 'expand' solution finds "bab" first and keeps it.
    std::string result = s.longest_palindrome("babad");
    ASSERT_TRUE(result == "bab" || result == "aba");
    ASSERT_EQ(result.length(), 3);
}

TEST(LongestPalindrome, Example2) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("cbbd"), "bb");
}

// Edge Cases
TEST(LongestPalindrome, SingleChar) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("a"), "a");
}

TEST(LongestPalindrome, SingleCharZ) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("z"), "z");
}

// Typical Cases
TEST(LongestPalindrome, TwoCharsSame) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("aa"), "aa");
}

TEST(LongestPalindrome, TwoCharsDiff) {
    Solution s;
    // Any single char is a valid 1-length palindrome
    EXPECT_EQ(s.longest_palindrome("ab").length(), 1);
}

TEST(LongestPalindrome, MixedPalindrome) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("forgeeksskeegfor"), "geeksskeeg");
}

TEST(LongestPalindrome, PalindromeAtStart) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("racecarxyz"), "racecar");
}

TEST(LongestPalindrome, PalindromeAtEnd) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("xyzracecar"), "racecar");
}

TEST(LongestPalindrome, FullPalindromeOdd) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("level"), "level");
}

TEST(LongestPalindrome, FullPalindromeEven) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("abba"), "abba");
}

TEST(LongestPalindrome, NoPalindromeLong) {
    Solution s;
    // Any single char is a valid 1-length palindrome
    EXPECT_EQ(s.longest_palindrome("abcdef").length(), 1);
}

TEST(LongestPalindrome, Numeric) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("12321"), "12321");
}

TEST(LongestPalindrome, NumericEven) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("1221"), "1221");
}

// Special Cases
TEST(LongestPalindrome, CenteredPalindrome) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("xyzracecarxyz"), "racecar");
}

TEST(LongestPalindrome, CaseMixed) {
    // Per constraints, 'a' and 'A' are different chars
    Solution s;
    EXPECT_EQ(s.longest_palindrome("aBcBa"), "aBcBa");
}

TEST(LongestPalindrome, RepeatedChars) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("aaaa"), "aaaa");
}

TEST(LongestPalindrome, LongOdd) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("madamimadam"), "madamimadam");
}

TEST(LongestPalindrome, RandomMix) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("banana"), "anana");
}

TEST(LongestPalindrome, ToughCase) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("aaabaaaa"), "aaabaaa");
}