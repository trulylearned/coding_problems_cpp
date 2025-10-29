#include "solution.h" // Assumes our class is in this header
#include <gtest/gtest.h>
#include <string>

// ---- Longest Palindrome Tests ----

// Examples from LeetCode
TEST(LongestPalindrome, Example1) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("abccccdd"), 7);
}

TEST(LongestPalindrome, Example2) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("a"), 1);
}

// Edge Case: Empty String
TEST(LongestPalindrome, NoLetters) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome(""), 0);
}

// Edge Case: Single Character (Repeated)
TEST(LongestPalindrome, AllSameEven) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("zzzz"), 4);
}

// Edge Case: Single Character (Repeated)
TEST(LongestPalindrome, AllSameOdd) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("zzzzz"), 5);
}

// Edge Case: All unique characters (only one can be used)
TEST(LongestPalindrome, AllUnique) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("abcdef"), 1);
}

// Case-Sensitive Tests
TEST(LongestPalindrome, CaseSensitivePair) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("Aa"), 1);
}

TEST(LongestPalindrome, CaseSensitiveMixed) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("AaBbCcDdEeFfGgHhIi"), 1);
}

TEST(LongestPalindrome, UpperLowerCombo) {
    Solution s;
    // Freqs: Z:2, z:2. All pairs.
    EXPECT_EQ(s.longest_palindrome("ZzZz"), 4);
}

// Typical Cases
TEST(LongestPalindrome, MixedEvenOdd) {
    Solution s;
    // a:2, b:2, c:2, d:1 -> (2+2+2) + 1 = 7
    EXPECT_EQ(s.longest_palindrome("aabbccd"), 7);
}

TEST(LongestPalindrome, AllEvenPairs) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("aabbccddeeff"), 12);
}

TEST(LongestPalindrome, MultipleOdds) {
    Solution s;
    // a:1, b:1, c:1 -> (0) + 1 = 1
    EXPECT_EQ(s.longest_palindrome("abc"), 1);
}

TEST(LongestPalindrome, OneOddMultipleEven) {
    Solution s;
    // a:2, b:2, c:3 -> (2+2+2) + 1 = 7
    EXPECT_EQ(s.longest_palindrome("aabbccc"), 7);
}

TEST(LongestPalindrome, MultipleOddsMixed) {
    Solution s;
    // Input: "aaabbbc"
    // Freqs: a:3, b:3, c:1
    // Pairs: (2 from a) + (2 from b) + (0 from c) = 4
    // Center: +1
    // Total: 5
    EXPECT_EQ(s.longest_palindrome("aaabbbc"), 5);
}

// More Complex Mixes
TEST(LongestPalindrome, ComplexMix) {
    Solution s;
    // a:2, b:2, c:2, X:1, Y:1, Z:1
    // Pairs: a:2, b:2, c:2 (length 6)
    // Odds: X, Y, Z. Use one as center.
    // Total: 6 + 1 = 7.
    EXPECT_EQ(s.longest_palindrome("abccbaXYZ"), 7);
}

TEST(LongestPalindrome, LongOddSet) {
    Solution s;
    // a:3, b:4, c:2 -> (2+4+2) + 1 = 9
    EXPECT_EQ(s.longest_palindrome("aaabbbbcc"), 9);
}

TEST(LongestPalindrome, RandomMix1) {
    Solution s;
    // a:3, b:3, c:3, d:3
    // Pairs: (2+2+2+2) = 8
    // Odds: a,b,c,d. Use one as center.
    // Total: 8 + 1 = 9
    EXPECT_EQ(s.longest_palindrome("abcdabcdabcd"), 9);
}

TEST(LongestPalindrome, PerfectPalindrome) {
    Solution s;
    EXPECT_EQ(s.longest_palindrome("qwertyytrewq"), 12);
}

// Large Constraint Tests
TEST(LongestPalindrome, LargeEvenCase) {
    Solution s;
    std::string input(2000, 'a');
    EXPECT_EQ(s.longest_palindrome(input), 2000);
}

TEST(LongestPalindrome, LargeInputWithTwoOdds) {
    Solution s;
    std::string input(1999, 'a');
    input.push_back('b');
    // Freqs: a:1999, b:1
    // Pairs: 1998 from 'a'
    // Odds: 'a', 'b'. Use one as center.
    // Total: 1998 + 1 = 1999
    EXPECT_EQ(s.longest_palindrome(input), 1999);
}