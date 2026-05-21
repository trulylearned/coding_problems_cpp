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


// LeetCode Examples
TEST(ValidParentheses, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("()"));
    });
}

TEST(ValidParentheses, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("()[]{}"));
    });
}

TEST(ValidParentheses, Example3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("(]"));
    });
}

// Typical Valid Cases
TEST(ValidParentheses, NestedCorrectly) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("([{}])"));
    });
}

TEST(ValidParentheses, SequentialPairs) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("()(){}{}[][]"));
    });
}

TEST(ValidParentheses, ComplexValid) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("{[()]}{([])}"));
    });
}

// Typical Invalid Cases
TEST(ValidParentheses, NestedIncorrectly) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("([)]"));
    });
}

TEST(ValidParentheses, WrongClosureType) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("{[}"));
    });
}

TEST(ValidParentheses, ExtraClosingBracket) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("{[()]}}"));
    });
}

TEST(ValidParentheses, ComplexInvalid) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("{[(])}{([])}"));
    });
}

// Edge Cases
TEST(ValidParentheses, EmptyString) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid(""));
    });
}

TEST(ValidParentheses, SingleOpening) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("("));
    });
}

TEST(ValidParentheses, SingleClosing) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid(")"));
    });
}

TEST(ValidParentheses, AllOpening) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("(((([[[[{{{{"));
    });
}

TEST(ValidParentheses, AllClosing) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_FALSE(s.isValid("))))]]]]}}}}"));
    });
}

// Large/Special Cases
TEST(ValidParentheses, DeeplyNestedValid) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("(((([[[{{{}}}]]]))))"));
    });
}

TEST(ValidParentheses, LongValidSequence) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string long_valid(5000, '(');
        long_valid += std::string(5000, ')');
        EXPECT_TRUE(s.isValid(long_valid));
    });
}

TEST(ValidParentheses, LongInvalidSequence) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::string long_invalid(5000, '(');
        long_invalid += std::string(4999, ')');
        EXPECT_FALSE(s.isValid(long_invalid));
    });
}

TEST(ValidParentheses, InterleavedValid) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("[{()}([]{})]"));
    });
}

TEST(ValidParentheses, JustOnePair) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_TRUE(s.isValid("{}"));
    });
}