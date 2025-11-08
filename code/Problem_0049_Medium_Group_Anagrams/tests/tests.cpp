#include "solution.h" 
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <string>
#include <random> // For std::shuffle, std::random_device, std::mt19937

// Helper function to normalize the output for stable comparison
void normalize(std::vector<std::vector<std::string>>& groups) {
    // Sort strings within each group
    for (auto& group : groups) {
        std::sort(group.begin(), group.end());
    }
    // Sort the groups themselves (e.g., by the first element)
    std::sort(groups.begin(), groups.end());
}

TEST(GroupAnagrams, Example1_FromProblem) {
    Solution s;
    std::vector<std::string> input = {"eat","tea","tan","ate","nat","bat"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {
        {"bat"},
        {"eat", "tea", "ate"},
        {"nat", "tan"}
    };
    normalize(expected);
    
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Edge_EmptyInput) {
    Solution s;
    std::vector<std::string> input = {};
    auto res = s.groupAnagrams(input);
    EXPECT_TRUE(res.empty());
}

TEST(GroupAnagrams, Edge_SingleEmptyString) {
    Solution s;
    std::vector<std::string> input = {""};
    auto res = s.groupAnagrams(input);
    
    std::vector<std::vector<std::string>> expected = {{""}};
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Edge_MultipleEmptyStrings) {
    Solution s;
    std::vector<std::string> input = {"", ""};
    auto res = s.groupAnagrams(input);
    
    std::vector<std::vector<std::string>> expected = {{"", ""}};
    normalize(res);
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Edge_SingleCharString) {
    Solution s;
    std::vector<std::string> input = {"a"};
    auto res = s.groupAnagrams(input);
    
    std::vector<std::vector<std::string>> expected = {{"a"}};
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_SingleCharsMixed) {
    Solution s;
    std::vector<std::string> input = {"a", "b", "a"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{"a", "a"}, {"b"}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_NoAnagrams) {
    Solution s;
    std::vector<std::string> input = {"one", "two", "three"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{"one"}, {"three"}, {"two"}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_AllAnagrams) {
    Solution s;
    std::vector<std::string> input = {"listen", "silent", "enlist"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{"enlist", "listen", "silent"}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_IdenticalStrings) {
    Solution s;
    std::vector<std::string> input = {"hello", "hello", "hello"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{"hello", "hello", "hello"}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_ComplexCase) {
    Solution s;
    std::vector<std::string> input = {"abc", "bca", "xyz", "zyx", "acb", "foo"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {
        {"abc", "acb", "bca"},
        {"foo"},
        {"xyz", "zyx"}
    };
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_MixedLengths) {
    Solution s;
    std::vector<std::string> input = {"a", "ab", "ba", "abc", "bca"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {
        {"a"},
        {"ab", "ba"},
        {"abc", "bca"}
    };
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_Subsets) {
    Solution s;
    std::vector<std::string> input = {"car", "arc", "race", "care"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {
        {"arc", "car"},
        {"care", "race"}
    };
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_AllSameLetter) {
    Solution s;
    std::vector<std::string> input = {"a", "aa", "aaa"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{"a"}, {"aa"}, {"aaa"}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_PermutationsOfTwoLetters) {
    Solution s;
    std::vector<std::string> input = {"ab", "ba", "ab"};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{"ab", "ab", "ba"}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Edge_SingleLongWord) {
    Solution s;
    std::vector<std::string> input = {"abcdefghijklmnopqrstuvwxyz"};
    auto res = s.groupAnagrams(input);
    
    std::vector<std::vector<std::string>> expected = {{"abcdefghijklmnopqrstuvwxyz"}};
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_LongWordsAnagrams) {
    Solution s;
    std::string s1 = "pneumonoultramicroscopicsilicovolcanoconiosis";
    std::string s2 = s1;
    
    // Use modern C++ std::shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(s2.begin(), s2.end(), g);
    
    std::vector<std::string> input = {s1, s2};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{s1, s2}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Typical_LongWordsNotAnagrams) {
    Solution s;
    std::string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac";
    std::vector<std::string> input = {s1, s2};
    auto res = s.groupAnagrams(input);
    normalize(res);
    
    std::vector<std::vector<std::string>> expected = {{s1}, {s2}};
    normalize(expected);
    EXPECT_EQ(res, expected);
}

TEST(GroupAnagrams, Large_IdenticalInput) {
    Solution s;
    std::vector<std::string> input(1000, "abc");
    auto res = s.groupAnagrams(input);
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0].size(), 1000);
}

TEST(GroupAnagrams, Large_TwoGroups) {
    Solution s;
    std::vector<std::string> input;
    for (int i=0; i < 500; ++i) input.push_back("abc");
    for (int i=0; i < 500; ++i) input.push_back("bca");
    auto res = s.groupAnagrams(input);
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0].size(), 1000);
}

TEST(GroupAnagrams, Large_NoAnagrams) {
    Solution s;
    std::vector<std::string> input;
    input.reserve(1000); 

    // Start loop at 1 to avoid an empty string (length 0)
    for (int i = 1; i <= 1000; ++i) {
        // Creates "a", "aa", "aaa", ...
        // These can never be anagrams as they have different lengths.
        input.emplace_back(std::string(i, 'a')); 
    }
    
    auto res = s.groupAnagrams(input);
    
    // This assertion will now be correct.
    ASSERT_EQ(res.size(), 1000);
}