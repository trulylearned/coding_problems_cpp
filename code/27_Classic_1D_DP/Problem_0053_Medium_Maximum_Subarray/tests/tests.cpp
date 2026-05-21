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


// Test fixtures can be used if we want to test all 3 implementations
// For simplicity, we'll just test the main 'maxSubArray' public method.

TEST(MaximumSubarray, Example1_FromLeetCode) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        EXPECT_EQ(s.maxSubArray(nums), 6); // [4, -1, 2, 1]
    });
}

TEST(MaximumSubarray, Example2_FromLeetCode) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {1};
        EXPECT_EQ(s.maxSubArray(nums), 1);
    });
}

TEST(MaximumSubarray, Example3_FromLeetCode) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {5, 4, -1, 7, 8};
        EXPECT_EQ(s.maxSubArray(nums), 23); // The whole array
    });
}

TEST(MaximumSubarray, AllNegative) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-3, -5, -1, -2};
        EXPECT_EQ(s.maxSubArray(nums), -1);
    });
}

TEST(MaximumSubarray, MixedPositiveNegative_CustomExample) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-5, 2, 3, -1, 2, -4, 6};
        EXPECT_EQ(s.maxSubArray(nums), 8); // [2, 3, -1, 2, -4, 6]
    });
}

TEST(MaximumSubarray, AllPositive) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {1, 2, 3, 4};
        EXPECT_EQ(s.maxSubArray(nums), 10);
    });
}

TEST(MaximumSubarray, SingleNegative) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-10};
        EXPECT_EQ(s.maxSubArray(nums), -10);
    });
}

TEST(MaximumSubarray, SinglePositive) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {10};
        EXPECT_EQ(s.maxSubArray(nums), 10);
    });
}

TEST(MaximumSubarray, AlternatingSigns) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {1, -2, 3, -1, 2};
        EXPECT_EQ(s.maxSubArray(nums), 4); // [3, -1, 2]
    });
}

TEST(MaximumSubarray, LongRunOfPositives) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(1000, 1);
        EXPECT_EQ(s.maxSubArray(nums), 1000);
    });
}

TEST(MaximumSubarray, AllZeroes) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {0, 0, 0};
        EXPECT_EQ(s.maxSubArray(nums), 0);
    });
}

TEST(MaximumSubarray, IncreasingThenBigDrop) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {1, 2, 3, -10, 5, 6};
        EXPECT_EQ(s.maxSubArray(nums), 11); // [5, 6]
    });
}

TEST(MaximumSubarray, MixedWithZero) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-1, 0, -2};
        EXPECT_EQ(s.maxSubArray(nums), 0); // [0]
    });
}

TEST(MaximumSubarray, LongRunOfNegatives) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(100000, -1);
        EXPECT_EQ(s.maxSubArray(nums), -1);
    });
}

TEST(MaximumSubarray, MixedMinMaxValues) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-10000, 10000};
        EXPECT_EQ(s.maxSubArray(nums), 10000);
    });
}

TEST(MaximumSubarray, DropAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {2, 3, -2, -1};
        EXPECT_EQ(s.maxSubArray(nums), 5); // [2, 3]
    });
}

TEST(MaximumSubarray, BigFluctuation) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
        EXPECT_EQ(s.maxSubArray(nums), 7); // [4, -1, -2, 1, 5]
    });
}

TEST(MaximumSubarray, LargeNegativeStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-100, 10, 20, 30};
        EXPECT_EQ(s.maxSubArray(nums), 60); // [10, 20, 30]
    });
}

TEST(MaximumSubarray, LargePositivesWithSmallDip) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {10, -2, 3, -1, 5};
        EXPECT_EQ(s.maxSubArray(nums), 15); // [10, -2, 3, -1, 5]
    });
}

TEST(MaximumSubarray, AllSameNegative) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums = {-5, -5, -5};
        EXPECT_EQ(s.maxSubArray(nums), -5);
    });
}