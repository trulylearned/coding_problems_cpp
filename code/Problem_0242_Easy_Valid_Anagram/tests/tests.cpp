#include "solution.h"
#include <gtest/gtest.h>

// 1. Example from LeetCode
TEST(ValidAnagram, Example1) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("anagram", "nagaram"));
}

// 2. Example from LeetCode
TEST(ValidAnagram, Example2) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("rat", "car"));
}

// 3. Same word
TEST(ValidAnagram, SameWord) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("abc", "abc"));
}

// 4. Different length (s longer)
TEST(ValidAnagram, DifferentLength) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("abcd", "abc"));
}

// 5. Empty strings (edge case)
TEST(ValidAnagram, EmptyStrings) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("", ""));
}

// 6. One char, same
TEST(ValidAnagram, OneCharSame) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("a", "a"));
}

// 7. One char, different
TEST(ValidAnagram, OneCharDifferent) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("a", "b"));
}

// 8. Simple false case
TEST(ValidAnagram, RandomFalse) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("abc", "abd"));
}

// 9. Repeated chars, true
TEST(ValidAnagram, RepeatedCharsTrue) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("aabbcc", "ccbbaa"));
}

// 10. Repeated chars, false (length mismatch)
TEST(ValidAnagram, RepeatedCharsFalse) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("aabbcc", "aabbc"));
}

// 11. Large input, true
TEST(ValidAnagram, LargeTrue) {
    Solution s;
    std::string a(50000, 'x');
    std::string b(50000, 'x');
    EXPECT_TRUE(s.is_anagram(a, b));
}

// 12. Large input, false (content mismatch)
TEST(ValidAnagram, LargeFalseContent) {
    Solution s;
    std::string a(50000, 'x');
    std::string b(49999, 'x');
    b.push_back('y');
    EXPECT_FALSE(s.is_anagram(a, b));
}

// 13. Mixed letters, true
TEST(ValidAnagram, MixedLettersTrue) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("abcdabcd", "dcbaabcd"));
}

// 14. Mixed letters, false
TEST(ValidAnagram, MixedLettersFalse) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("abcdabcd", "dcbaabce"));
}

// 15. Replaced test: Different frequencies
TEST(ValidAnagram, DifferentCounts) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("aab", "abb"));
}

// 16. Single character, but same
TEST(ValidAnagram, SingleCharacter) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("z", "z"));
}

// 17. Long strings with repeats, true
TEST(ValidAnagram, LongRepeats) {
    Solution s;
    std::string a = std::string(25000, 'a') + std::string(25000, 'b');
    std::string b = std::string(25000, 'b') + std::string(25000, 'a');
    EXPECT_TRUE(s.is_anagram(a, b));
}

// 18. Classic anagram example
TEST(ValidAnagram, MixedOrder) {
    Solution s;
    EXPECT_TRUE(s.is_anagram("debitcard", "badcredit"));
}

// 19. Replaced test: All same char, length mismatch
TEST(ValidAnagram, AllSameCharFalseLength) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("zzzz", "zzzza"));
}

// 20. Partial overlap but false
TEST(ValidAnagram, PartialOverlap) {
    Solution s;
    EXPECT_FALSE(s.is_anagram("abc", "abz"));
}