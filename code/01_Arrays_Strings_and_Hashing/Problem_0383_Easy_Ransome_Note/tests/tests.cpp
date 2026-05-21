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
TEST(RansomNote, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("a", "b"));
    });
}

TEST(RansomNote, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("aa", "ab"));
    });
}

TEST(RansomNote, Example3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("aa", "aab"));
    });
}

// ---- Custom & Edge Cases ----

TEST(RansomNote, SingleLetterTrue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("a", "a"));
    });
}

TEST(RansomNote, SingleLetterFalse) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("a", "b"));
    });
}

TEST(RansomNote, MixedLettersTrue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("abc", "cbad"));
    });
}

TEST(RansomNote, MixedLettersFalse) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("abc", "ac"));
    });
}

TEST(RansomNote, RepeatedLettersTrue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("aabb", "ababa"));
    });
}

TEST(RansomNote, RepeatedLettersFalse) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("aabbc", "aab"));
    });
}

TEST(RansomNote, LargeInputTrue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::string ransom(100000, 'a');
        std::string magazine(100000, 'a');
        EXPECT_TRUE(solution.canConstruct(ransom, magazine));
    });
}

TEST(RansomNote, LargeInputFalse) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::string ransom(100000, 'a');
        std::string magazine(99999, 'a');
        EXPECT_FALSE(solution.canConstruct(ransom, magazine));
    });
}

TEST(RansomNote, UnequalLengths1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("a", "aaaa"));
    });
}

TEST(RansomNote, UnequalLengths2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("aaaa", "a"));
    });
}

TEST(RansomNote, ComplexFalse1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("hello", "billionaire"));
    });
}

TEST(RansomNote, ComplexTrue1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("note", "ransomnote"));
    });
}

TEST(RansomNote, ComplexTrue2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("aa", "aaa"));
    });
}

TEST(RansomNote, ComplexFalse2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("zzz", "yyz"));
    });
}

TEST(RansomNote, AllUniqueLetters) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("xyz", "zyx"));
    });
}

TEST(RansomNote, OverlappingCharacters) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_FALSE(solution.canConstruct("aabbcc", "abc"));
    });
}

TEST(RansomNote, AllMagazineLettersUsedExactly) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        EXPECT_TRUE(solution.canConstruct("aabbc", "acbab"));
    });
}