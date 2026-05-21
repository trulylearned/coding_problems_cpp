#include "solutions.h"
#include <gtest/gtest.h>
#include <vector>
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


TEST(ProductExceptSelf, LC_Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{1, 2, 3, 4};
        std::vector<int> expected{24, 12, 8, 6};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, LC_Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{-1, 1, 0, -3, 3};
        std::vector<int> expected{0, 0, 9, 0, 0};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, Custom_A_AllPositive) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{2, 3, 4, 5};
        std::vector<int> expected{60, 40, 30, 24};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, Custom_B_WithOneZero) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{0, 1, 2, 3};
        std::vector<int> expected{6, 0, 0, 0};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, MinLengthTwo_Positive) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{5, 7};
        std::vector<int> expected{7, 5};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, AllOnes) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{1, 1, 1, 1, 1};
        std::vector<int> expected{1, 1, 1, 1, 1};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, AllNegatives_EvenCount) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{-2, -3, -4, -5};
        std::vector<int> expected{-60, -40, -30, -24};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, AllNegatives_OddCount) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{-2, -3, -4};
        std::vector<int> expected{12, 8, 6};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, ContainsTwoZeros) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{0, 2, 0, 3};
        std::vector<int> expected{0, 0, 0, 0};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, ZeroAtStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{0, 2, 3, 4};
        std::vector<int> expected{24, 0, 0, 0};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, ZeroAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{2, 3, 4, 0};
        std::vector<int> expected{0, 0, 0, 24};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, MixedSigns) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{-1, 2, -3, 4};
        std::vector<int> expected{-24, 12, -8, 6};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, IncludesOneAndMinusOne) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{-1, 1, -1, 1};
        std::vector<int> expected{-1, 1, -1, 1};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, LargeButWithinRange) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{30, -30, 2, -2};
        std::vector<int> expected{120, -120, 1800, -1800};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, AlternatingSmall) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{2, -1, 2, -1, 2};
        std::vector<int> expected{4, -8, 4, -8, 4};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, RepeatedNumbers) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{3, 3, 3};
        std::vector<int> expected{9, 9, 9};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, ContainsZeroMiddle) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{5, 0, 2};
        std::vector<int> expected{0, 10, 0};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, ManyOnesAndZero) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{1, 1, 0, 1, 1, 1};
        std::vector<int> expected{0, 0, 1, 0, 0, 0};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, IncreasingSequence) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{1, 2, 3, 4, 5, 6};
        std::vector<int> expected{720, 360, 240, 180, 144, 120};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}

TEST(ProductExceptSelf, RandomSmallWithMultipleZeros) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;
        std::vector<int> input_nums{-2, 0, 1, -3, 0, 4};
        std::vector<int> expected{0, 0, 0, 0, 0, 0};
        EXPECT_EQ(solution.productExceptSelf(input_nums), expected);
    });
}