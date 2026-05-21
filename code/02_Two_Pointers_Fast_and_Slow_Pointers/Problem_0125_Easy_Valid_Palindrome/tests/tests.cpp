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


// Example 1 from LeetCode
TEST(ValidPalindrome, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("A man, a plan, a canal: Panama"));
    });
}

// Example 2 from LeetCode
TEST(ValidPalindrome, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_palindrome("race a car"));
    });
}

// Example 3 from LeetCode (empty after filtering)
TEST(ValidPalindrome, Example3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome(" "));
    });
}

// Custom tests
TEST(ValidPalindrome, MixedCase) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("WasItACarOrACatISaw"));
    });
}

TEST(ValidPalindrome, PunctuationOnly) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("!!!???.,,"));
    });
}

TEST(ValidPalindrome, DigitsPalindrome) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("12321"));
    });
}

TEST(ValidPalindrome, DigitsNonPalindrome) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_palindrome("123421"));
    });
}

TEST(ValidPalindrome, LongSpaces) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("     "));
    });
}

TEST(ValidPalindrome, SingleCharacter) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("Z"));
    });
}

TEST(ValidPalindrome, TwoDifferentCharacters) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_palindrome("ab"));
    });
}

TEST(ValidPalindrome, CaseInsensitive) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("Aa"));
    });
}

TEST(ValidPalindrome, EmbeddedSymbols) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("No 'x' in Nixon"));
    });
}

TEST(ValidPalindrome, SentencePalindrome) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("Never odd or even"));
    });
}

TEST(ValidPalindrome, RandomLetters) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_palindrome("abcdefg"));
    });
}

TEST(ValidPalindrome, DigitsAndLetters) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("1a2b3b2a1"));
    });
}

TEST(ValidPalindrome, EdgeMaxLengthSameChar) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string large(200000, 'a');
        EXPECT_TRUE(s.is_palindrome(large));
    });
}

TEST(ValidPalindrome, EdgeMaxLengthDifferentEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string large(199999, 'a');
        large.push_back('b');
        EXPECT_FALSE(s.is_palindrome(large));
    });
}

TEST(ValidPalindrome, SpecialCharactersAndSpaces) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome(".,; @#  a!!a  #@ ;,."));
    });
}

TEST(ValidPalindrome, OnlyNumbersSpaces) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome(" 12 21 "));
    });
}

TEST(ValidPalindrome, LongPhrase) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_palindrome("No lemon, no melon!!"));
    });
}