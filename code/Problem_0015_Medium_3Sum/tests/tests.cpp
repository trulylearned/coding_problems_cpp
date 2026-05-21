#include "solutions.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
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


// Helper function to compare two vectors of triplets
// This is crucial because the order of triplets and the order
// of numbers within a triplet doesn't matter.
void ExpectTripletsEqualUnordered(
    std::vector<std::vector<int>> expected,
    std::vector<std::vector<int>> actual) 
{
    // Sort numbers within each triplet
    auto sort_triplets = [](std::vector<std::vector<int>>& v) {
        for (auto& triplet : v) {
            std::sort(triplet.begin(), triplet.end());
        }
        // Sort the outer vector of triplets
        std::sort(v.begin(), v.end());
    };
    
    sort_triplets(expected);
    sort_triplets(actual);
    
    EXPECT_EQ(expected, actual);
}

// ---- LeetCode Examples ----
TEST(ThreeSum, LeetCodeExample1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, 0, 1, 2, -1, -4};
        std::vector<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, LeetCodeExample2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 1, 1};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, LeetCodeExample3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 0, 0};
        std::vector<std::vector<int>> expected = {{0, 0, 0}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

// ---- Edge Cases ----
TEST(ThreeSum, EmptyInput) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, TwoElementsOnly) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, -1};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, MinSizeInput_Solution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, -1, 0};
        std::vector<std::vector<int>> expected = {{-1, 0, 1}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, MinSizeInput_NoSolution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 3};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

// ---- All Zeros ----
TEST(ThreeSum, AllZerosSize3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 0, 0};
        std::vector<std::vector<int>> expected = {{0, 0, 0}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, AllZerosSize4) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 0, 0, 0};
        std::vector<std::vector<int>> expected = {{0, 0, 0}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

// ---- No Solutions ----
TEST(ThreeSum, AllPositive) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 3, 4, 5};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, AllNegative) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, -2, -3, -4, -5};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, MixedNoSolution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, -2, 4, 5, 6};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

// ---- Duplicate Handling ----
TEST(ThreeSum, Duplicates_OneSolution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, 0, 1, 0};
        std::vector<std::vector<int>> expected = {{-1, 0, 1}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, Duplicates_MultipleSolutions) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-2, 0, 1, 1, 2};
        std::vector<std::vector<int>> expected = {{-2, 0, 2}, {-2, 1, 1}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, AllDuplicates_OneSolution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, -1, -1, 2, 2, 2};
        std::vector<std::vector<int>> expected = {{-1, -1, 2}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, AllDuplicates_NoSolution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, -1, 1, 1};
        std::vector<std::vector<int>> expected = {};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

// ---- General & Large Values ----
TEST(ThreeSum, MultipleSolutions) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-5, 2, 3, 0, 1, -1};
        std::vector<std::vector<int>> expected = {{-5, 2, 3}, {-1, 0, 1}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, LargeValues) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{100000, -100000, 0};
        std::vector<std::vector<int>> expected = {{-100000, 0, 100000}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, LargeMixedValues) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-100, -200, 300, 5, -10, 10};
        std::vector<std::vector<int>> expected = {{-200, -100, 300}, {-10, 0, 10}};
        // Test input had no zero, let's fix that.
        nums = {-100, -200, 300, 5, -10, 10, 0};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}

TEST(ThreeSum, MaxN_Solution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(3000, 1);
        nums[0] = -2;
        nums[1] = 1; // Array is [-2, 1, 1, 1, ..., 1]
        std::vector<std::vector<int>> expected = {{-2, 1, 1}};
        ExpectTripletsEqualUnordered(expected, s.threeSum(nums));
    });
}