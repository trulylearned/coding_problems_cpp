#include "solution.h" // Assumes our class is in "solution.h"
#include <gtest/gtest.h>
#include <string>

// Examples from LeetCode
TEST(RansomNote, Example1) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("a", "b"));
}

TEST(RansomNote, Example2) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("aa", "ab"));
}

TEST(RansomNote, Example3) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("aa", "aab"));
}

// ---- Custom & Edge Cases ----

TEST(RansomNote, SingleLetterTrue) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("a", "a"));
}

TEST(RansomNote, SingleLetterFalse) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("a", "b"));
}

TEST(RansomNote, MixedLettersTrue) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("abc", "cbad"));
}

TEST(RansomNote, MixedLettersFalse) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("abc", "ac"));
}

TEST(RansomNote, RepeatedLettersTrue) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("aabb", "ababa"));
}

TEST(RansomNote, RepeatedLettersFalse) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("aabbc", "aab"));
}

TEST(RansomNote, LargeInputTrue) {
    Solution solution;
    std::string ransom(100000, 'a');
    std::string magazine(100000, 'a');
    EXPECT_TRUE(solution.canConstruct(ransom, magazine));
}

TEST(RansomNote, LargeInputFalse) {
    Solution solution;
    std::string ransom(100000, 'a');
    std::string magazine(99999, 'a');
    EXPECT_FALSE(solution.canConstruct(ransom, magazine));
}

TEST(RansomNote, UnequalLengths1) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("a", "aaaa"));
}

TEST(RansomNote, UnequalLengths2) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("aaaa", "a"));
}

TEST(RansomNote, ComplexFalse1) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("hello", "billionaire"));
}

TEST(RansomNote, ComplexTrue1) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("note", "ransomnote"));
}

TEST(RansomNote, ComplexTrue2) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("aa", "aaa"));
}

TEST(RansomNote, ComplexFalse2) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("zzz", "yyz"));
}

TEST(RansomNote, AllUniqueLetters) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("xyz", "zyx"));
}

TEST(RansomNote, OverlappingCharacters) {
    Solution solution;
    EXPECT_FALSE(solution.canConstruct("aabbcc", "abc"));
}

TEST(RansomNote, AllMagazineLettersUsedExactly) {
    Solution solution;
    EXPECT_TRUE(solution.canConstruct("aabbc", "acbab"));
}