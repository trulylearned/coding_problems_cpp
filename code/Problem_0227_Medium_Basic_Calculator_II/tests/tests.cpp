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
TEST(BasicCalculatorII, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("3+2*2"), 7);
    });
}

// 2. Example from LeetCode
TEST(BasicCalculatorII, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("3/2"), 1);
    });
}

// 3. Example from LeetCode
TEST(BasicCalculatorII, Example3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("3+5 / 2"), 5);
    });
}

// 4. Custom example from our walkthrough
TEST(BasicCalculatorII, Custom1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("10+2*3"), 16);
    });
}

// 5. Custom example from our walkthrough
TEST(BasicCalculatorII, Custom2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("14-3/2"), 13);
    });
}

// 6. Test with spaces
TEST(BasicCalculatorII, Spaces) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("  4 + 5 * 2  "), 14);
    });
}

// 7. Test all addition
TEST(BasicCalculatorII, AllAdd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("1+2+3+4+5"), 15);
    });
}

// 8. Test all subtraction
TEST(BasicCalculatorII, AllSubtract) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("10-2-3"), 5);
    });
}

// 9. Mixed precedence
TEST(BasicCalculatorII, Mixed1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("10-2*3"), 4);
    });
}

// 10. Mixed precedence
TEST(BasicCalculatorII, Mixed2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("8+4/2"), 10);
    });
}

// 11. Truncation test (positive)
TEST(BasicCalculatorII, TruncationTest) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("10/3"), 3);
    });
}

// 12. Truncation test (mixed)
TEST(BasicCalculatorII, TruncationMixed) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("7-10/3"), 4);
    });
}

// 13. Long expression - **CORRECTED**
TEST(BasicCalculatorII, LongExpression) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // 2*3=6, 4*5=20, 6/2=3
        // 6 + 20 - 3 + 10 = 33
        EXPECT_EQ(s.calculate("2*3+4*5-6/2+10"), 33);
    });
}

// 14. Multiple spaces
TEST(BasicCalculatorII, MultipleSpaces) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate(" 2 * 3 +   5 "), 11);
    });
}

// 15. Division truncation (simpler)
TEST(BasicCalculatorII, DivisionTruncate) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("7/2"), 3);
    });
}

// 16. Chained multiplication/division (should be left-to-right)
TEST(BasicCalculatorII, ChainMultDiv) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // 100/5 = 20
        // 20/2 = 10
        EXPECT_EQ(s.calculate("100/5/2"), 10);
    });
}

// 17. Big numbers
TEST(BasicCalculatorII, BigNumbers) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("100000+200000*2"), 500000);
    });
}

// 18. Edge case: single number
TEST(BasicCalculatorII, OnlyNumber) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("42"), 42);
    });
}

// 19. Edge case: starts with space
TEST(BasicCalculatorII, StartWithSpace) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("   8/2+1"), 5);
    });
}

// 20. Edge case: Zero values
TEST(BasicCalculatorII, ZeroTest) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        EXPECT_EQ(s.calculate("0*10 + 0/5 - 0"), 0);
    });
}