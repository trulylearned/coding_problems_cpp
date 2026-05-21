#include "solutions.h"
#include <gtest/gtest.h>
#include <string>
#include <string_view>

namespace {

bool is_stress_test() {
    const auto* test_info = ::testing::UnitTest::GetInstance()->current_test_info();
    if (test_info == nullptr) {
        return false;
    }

    const std::string_view test_name = test_info->name();
    return test_name.find("Large") != std::string_view::npos ||
           test_name.find("Stress") != std::string_view::npos ||
           test_name.find("MaxN") != std::string_view::npos ||
           test_name.find("Largest") != std::string_view::npos;
}

template <typename Fn>
void for_each_solution_for_current_test(Fn&& fn) {
    solutions::for_each_solution([&](const solutions::SolutionInfo& info,
                                     auto solution_type) {
        if (!info.run_stress_tests && is_stress_test()) {
            return;
        }

        SCOPED_TRACE(std::string(info.id));
        fn(solution_type);
    });
}

}  // namespace


// Examples from LeetCode
TEST(LongestPalindrome, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // For "babad", both "bab" and "aba" are valid.
        // Our 'expand' solution finds "bab" first and keeps it.
        std::string result = s.longest_palindrome("babad");
        ASSERT_TRUE(result == "bab" || result == "aba");
        ASSERT_EQ(result.length(), 3);
    });
}

TEST(LongestPalindrome, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("cbbd"), "bb");
    });
}

// Edge Cases
TEST(LongestPalindrome, SingleChar) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("a"), "a");
    });
}

TEST(LongestPalindrome, SingleCharZ) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("z"), "z");
    });
}

// Typical Cases
TEST(LongestPalindrome, TwoCharsSame) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("aa"), "aa");
    });
}

TEST(LongestPalindrome, TwoCharsDiff) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // Any single char is a valid 1-length palindrome
        EXPECT_EQ(s.longest_palindrome("ab").length(), 1);
    });
}

TEST(LongestPalindrome, MixedPalindrome) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("forgeeksskeegfor"), "geeksskeeg");
    });
}

TEST(LongestPalindrome, PalindromeAtStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("racecarxyz"), "racecar");
    });
}

TEST(LongestPalindrome, PalindromeAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("xyzracecar"), "racecar");
    });
}

TEST(LongestPalindrome, FullPalindromeOdd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("level"), "level");
    });
}

TEST(LongestPalindrome, FullPalindromeEven) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("abba"), "abba");
    });
}

TEST(LongestPalindrome, NoPalindromeLong) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // Any single char is a valid 1-length palindrome
        EXPECT_EQ(s.longest_palindrome("abcdef").length(), 1);
    });
}

TEST(LongestPalindrome, Numeric) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("12321"), "12321");
    });
}

TEST(LongestPalindrome, NumericEven) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("1221"), "1221");
    });
}

// Special Cases
TEST(LongestPalindrome, CenteredPalindrome) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("xyzracecarxyz"), "racecar");
    });
}

TEST(LongestPalindrome, CaseMixed) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        // Per constraints, 'a' and 'A' are different chars
        Solution s;
        EXPECT_EQ(s.longest_palindrome("aBcBa"), "aBcBa");
    });
}

TEST(LongestPalindrome, RepeatedChars) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("aaaa"), "aaaa");
    });
}

TEST(LongestPalindrome, LongOdd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("madamimadam"), "madamimadam");
    });
}

TEST(LongestPalindrome, RandomMix) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("banana"), "anana");
    });
}

TEST(LongestPalindrome, ToughCase) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("aaabaaaa"), "aaabaaa");
    });
}