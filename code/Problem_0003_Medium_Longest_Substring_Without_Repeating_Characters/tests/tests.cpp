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
TEST(LongestSubstring, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3); // "abc"
    });
}

TEST(LongestSubstring, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1); // "b"
    });
}

TEST(LongestSubstring, Example3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3); // "wke"
    });
}

// Edge Cases
TEST(LongestSubstring, EmptyString) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring(""), 0);
    });
}

TEST(LongestSubstring, SingleChar) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("a"), 1);
    });
}

TEST(LongestSubstring, TwoSameChars) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("aa"), 1);
    });
}

TEST(LongestSubstring, TwoDifferentChars) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("ab"), 2);
    });
}

// Typical Cases
TEST(LongestSubstring, RepeatingPattern) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("ababab"), 2); // "ab"
    });
}

TEST(LongestSubstring, NumbersAndLetters) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("a1b2c3a4"), 7); // "1b2c3a4"
    });
}

TEST(LongestSubstring, WithSpaces) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("a b c a b"), 3); // "a b", " b c", etc.
    });
}

TEST(LongestSubstring, Symbols) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("!@#!!@#"), 3); // "!@#"
    });
}

TEST(LongestSubstring, LongNoRepeats) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyz"), 26);
    });
}

TEST(LongestSubstring, RepeatsAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("abcddef"), 4); // "abcd"
    });
}

TEST(LongestSubstring, RepeatsAtStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("aabcde"), 5); // "abcde"
    });
}

TEST(LongestSubstring, MixedCase) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("AaBbCcAa"), 6); // "AaBbCc"
    });
}

// Special Cases
TEST(LongestSubstring, ComplexSymbols) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("a@b@c@d"), 3); // "a@b", "b@c", "c@d"
    });
}

TEST(LongestSubstring, RepeatsInside) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("abcdecfghi"), 7); // "decfghi"
    });
}

TEST(LongestSubstring, RepeatsWithGaps) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("abcadbbef"), 4); // "bcad" or "cadb"
    });
}

TEST(LongestSubstring, AllSameButOne) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.lengthOfLongestSubstring("aaaaabaaaaa"), 2); // "ab" or "ba"
    });
}

TEST(LongestSubstring, LargeInput) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string big(50000, 'a');
        EXPECT_EQ(s.lengthOfLongestSubstring(big), 1);
    });
}