#include "solution.h"
#include <gtest/gtest.h>
#include <string>

// Example 1 from LeetCode
TEST(ValidPalindrome, Example1) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("A man, a plan, a canal: Panama"));
}

// Example 2 from LeetCode
TEST(ValidPalindrome, Example2) {
    Solution s;
    EXPECT_FALSE(s.is_palindrome("race a car"));
}

// Example 3 from LeetCode (empty after filtering)
TEST(ValidPalindrome, Example3) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome(" "));
}

// Custom tests
TEST(ValidPalindrome, MixedCase) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("WasItACarOrACatISaw"));
}

TEST(ValidPalindrome, PunctuationOnly) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("!!!???.,,"));
}

TEST(ValidPalindrome, DigitsPalindrome) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("12321"));
}

TEST(ValidPalindrome, DigitsNonPalindrome) {
    Solution s;
    EXPECT_FALSE(s.is_palindrome("123421"));
}

TEST(ValidPalindrome, LongSpaces) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("     "));
}

TEST(ValidPalindrome, SingleCharacter) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("Z"));
}

TEST(ValidPalindrome, TwoDifferentCharacters) {
    Solution s;
    EXPECT_FALSE(s.is_palindrome("ab"));
}

TEST(ValidPalindrome, CaseInsensitive) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("Aa"));
}

TEST(ValidPalindrome, EmbeddedSymbols) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("No 'x' in Nixon"));
}

TEST(ValidPalindrome, SentencePalindrome) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("Never odd or even"));
}

TEST(ValidPalindrome, RandomLetters) {
    Solution s;
    EXPECT_FALSE(s.is_palindrome("abcdefg"));
}

TEST(ValidPalindrome, DigitsAndLetters) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("1a2b3b2a1"));
}

TEST(ValidPalindrome, EdgeMaxLengthSameChar) {
    Solution s;
    std::string large(200000, 'a');
    EXPECT_TRUE(s.is_palindrome(large));
}

TEST(ValidPalindrome, EdgeMaxLengthDifferentEnd) {
    Solution s;
    std::string large(199999, 'a');
    large.push_back('b');
    EXPECT_FALSE(s.is_palindrome(large));
}

TEST(ValidPalindrome, SpecialCharactersAndSpaces) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome(".,; @#  a!!a  #@ ;,."));
}

TEST(ValidPalindrome, OnlyNumbersSpaces) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome(" 12 21 "));
}

TEST(ValidPalindrome, LongPhrase) {
    Solution s;
    EXPECT_TRUE(s.is_palindrome("No lemon, no melon!!"));
}