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


// 1. Example from LeetCode
TEST(ValidAnagram, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("anagram", "nagaram"));
    });
}

// 2. Example from LeetCode
TEST(ValidAnagram, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("rat", "car"));
    });
}

// 3. Same word
TEST(ValidAnagram, SameWord) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("abc", "abc"));
    });
}

// 4. Different length (s longer)
TEST(ValidAnagram, DifferentLength) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("abcd", "abc"));
    });
}

// 5. Empty strings (edge case)
TEST(ValidAnagram, EmptyStrings) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("", ""));
    });
}

// 6. One char, same
TEST(ValidAnagram, OneCharSame) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("a", "a"));
    });
}

// 7. One char, different
TEST(ValidAnagram, OneCharDifferent) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("a", "b"));
    });
}

// 8. Simple false case
TEST(ValidAnagram, RandomFalse) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("abc", "abd"));
    });
}

// 9. Repeated chars, true
TEST(ValidAnagram, RepeatedCharsTrue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("aabbcc", "ccbbaa"));
    });
}

// 10. Repeated chars, false (length mismatch)
TEST(ValidAnagram, RepeatedCharsFalse) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("aabbcc", "aabbc"));
    });
}

// 11. Large input, true
TEST(ValidAnagram, LargeTrue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string a(50000, 'x');
        std::string b(50000, 'x');
        EXPECT_TRUE(s.is_anagram(a, b));
    });
}

// 12. Large input, false (content mismatch)
TEST(ValidAnagram, LargeFalseContent) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string a(50000, 'x');
        std::string b(49999, 'x');
        b.push_back('y');
        EXPECT_FALSE(s.is_anagram(a, b));
    });
}

// 13. Mixed letters, true
TEST(ValidAnagram, MixedLettersTrue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("abcdabcd", "dcbaabcd"));
    });
}

// 14. Mixed letters, false
TEST(ValidAnagram, MixedLettersFalse) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("abcdabcd", "dcbaabce"));
    });
}

// 15. Replaced test: Different frequencies
TEST(ValidAnagram, DifferentCounts) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("aab", "abb"));
    });
}

// 16. Single character, but same
TEST(ValidAnagram, SingleCharacter) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("z", "z"));
    });
}

// 17. Long strings with repeats, true
TEST(ValidAnagram, LongRepeats) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string a = std::string(25000, 'a') + std::string(25000, 'b');
        std::string b = std::string(25000, 'b') + std::string(25000, 'a');
        EXPECT_TRUE(s.is_anagram(a, b));
    });
}

// 18. Classic anagram example
TEST(ValidAnagram, MixedOrder) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.is_anagram("debitcard", "badcredit"));
    });
}

// 19. Replaced test: All same char, length mismatch
TEST(ValidAnagram, AllSameCharFalseLength) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("zzzz", "zzzza"));
    });
}

// 20. Partial overlap but false
TEST(ValidAnagram, PartialOverlap) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.is_anagram("abc", "abz"));
    });
}