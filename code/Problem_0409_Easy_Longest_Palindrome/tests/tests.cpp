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


// ---- Longest Palindrome Tests ----

// Examples from LeetCode
TEST(LongestPalindrome, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("abccccdd"), 7);
    });
}

TEST(LongestPalindrome, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("a"), 1);
    });
}

// Edge Case: Empty String
TEST(LongestPalindrome, NoLetters) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome(""), 0);
    });
}

// Edge Case: Single Character (Repeated)
TEST(LongestPalindrome, AllSameEven) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("zzzz"), 4);
    });
}

// Edge Case: Single Character (Repeated)
TEST(LongestPalindrome, AllSameOdd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("zzzzz"), 5);
    });
}

// Edge Case: All unique characters (only one can be used)
TEST(LongestPalindrome, AllUnique) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("abcdef"), 1);
    });
}

// Case-Sensitive Tests
TEST(LongestPalindrome, CaseSensitivePair) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("Aa"), 1);
    });
}

TEST(LongestPalindrome, CaseSensitiveMixed) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("AaBbCcDdEeFfGgHhIi"), 1);
    });
}

TEST(LongestPalindrome, UpperLowerCombo) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // Freqs: Z:2, z:2. All pairs.
        EXPECT_EQ(s.longest_palindrome("ZzZz"), 4);
    });
}

// Typical Cases
TEST(LongestPalindrome, MixedEvenOdd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // a:2, b:2, c:2, d:1 -> (2+2+2) + 1 = 7
        EXPECT_EQ(s.longest_palindrome("aabbccd"), 7);
    });
}

TEST(LongestPalindrome, AllEvenPairs) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("aabbccddeeff"), 12);
    });
}

TEST(LongestPalindrome, MultipleOdds) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // a:1, b:1, c:1 -> (0) + 1 = 1
        EXPECT_EQ(s.longest_palindrome("abc"), 1);
    });
}

TEST(LongestPalindrome, OneOddMultipleEven) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // a:2, b:2, c:3 -> (2+2+2) + 1 = 7
        EXPECT_EQ(s.longest_palindrome("aabbccc"), 7);
    });
}

TEST(LongestPalindrome, MultipleOddsMixed) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // Input: "aaabbbc"
        // Freqs: a:3, b:3, c:1
        // Pairs: (2 from a) + (2 from b) + (0 from c) = 4
        // Center: +1
        // Total: 5
        EXPECT_EQ(s.longest_palindrome("aaabbbc"), 5);
    });
}

// More Complex Mixes
TEST(LongestPalindrome, ComplexMix) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // a:2, b:2, c:2, X:1, Y:1, Z:1
        // Pairs: a:2, b:2, c:2 (length 6)
        // Odds: X, Y, Z. Use one as center.
        // Total: 6 + 1 = 7.
        EXPECT_EQ(s.longest_palindrome("abccbaXYZ"), 7);
    });
}

TEST(LongestPalindrome, LongOddSet) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // a:3, b:4, c:2 -> (2+4+2) + 1 = 9
        EXPECT_EQ(s.longest_palindrome("aaabbbbcc"), 9);
    });
}

TEST(LongestPalindrome, RandomMix1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // a:3, b:3, c:3, d:3
        // Pairs: (2+2+2+2) = 8
        // Odds: a,b,c,d. Use one as center.
        // Total: 8 + 1 = 9
        EXPECT_EQ(s.longest_palindrome("abcdabcdabcd"), 9);
    });
}

TEST(LongestPalindrome, PerfectPalindrome) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.longest_palindrome("qwertyytrewq"), 12);
    });
}

// Large Constraint Tests
TEST(LongestPalindrome, LargeEvenCase) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string input(2000, 'a');
        EXPECT_EQ(s.longest_palindrome(input), 2000);
    });
}

TEST(LongestPalindrome, LargeInputWithTwoOdds) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string input(1999, 'a');
        input.push_back('b');
        // Freqs: a:1999, b:1
        // Pairs: 1998 from 'a'
        // Odds: 'a', 'b'. Use one as center.
        // Total: 1998 + 1 = 1999
        EXPECT_EQ(s.longest_palindrome(input), 1999);
    });
}