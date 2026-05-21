#include "solutions.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <numeric>
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


// -----------------------------------------------------------------------------
// Helper function to validate any correct Two Sum solution
// -----------------------------------------------------------------------------
void ExpectTwoSumSolution(const std::vector<int>& nums,
                          int target,
                          const std::vector<int>& ans)
{
    ASSERT_EQ(ans.size(), 2) << "Two Sum must return exactly two indices.";
    int i = ans[0], j = ans[1];

    ASSERT_NE(i, j) << "Indices must be distinct.";
    ASSERT_GE(i, 0); ASSERT_LT(i, static_cast<int>(nums.size()));
    ASSERT_GE(j, 0); ASSERT_LT(j, static_cast<int>(nums.size()));

    EXPECT_EQ(nums[i] + nums[j], target)
        << "Returned indices do not sum to target.";
}

// --- LeetCode Examples ---
TEST(TwoSum, Example1)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{2, 7, 11, 15};
        ExpectTwoSumSolution(nums, 9, s.two_sum(nums, 9));
    });
}

TEST(TwoSum, Example2)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{3, 2, 4};
        ExpectTwoSumSolution(nums, 6, s.two_sum(nums, 6));
    });
}

TEST(TwoSum, Example3)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{3, 3};
        ExpectTwoSumSolution(nums, 6, s.two_sum(nums, 6));
    });
}

// --- Edge Cases ---

// 4. Minimum size array
TEST(TwoSum, MinSizeArray)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5, 8};
        ExpectTwoSumSolution(nums, 13, s.two_sum(nums, 13));
    });
}

// 5. Large values that sum to a smaller value
TEST(TwoSum, LargeValues)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1000000000, -1000000000, 5};
        ExpectTwoSumSolution(nums, 0, s.two_sum(nums, 0));
    });
}

// 6. Large negative values
TEST(TwoSum, LargeNegativeValues)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1000000000, 5, -1000000000};
        ExpectTwoSumSolution(nums, -2000000000, s.two_sum(nums, -2000000000));
    });
}

// 7. Large target value
TEST(TwoSum, LargeTarget)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1000000000, 50, 1000000000};
        ExpectTwoSumSolution(nums, 2000000000, s.two_sum(nums, 2000000000));
    });
}

// --- Typical Cases ---

// 8. Negative numbers summing to a positive target
TEST(TwoSum, MixedSign)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-10, 7, 19, 15};
        ExpectTwoSumSolution(nums, 26, s.two_sum(nums, 26));
    });
}

// 9. Negative numbers summing to zero
TEST(TwoSum, NegativeNumbersSumToZero)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-3, 4, 3, 90};
        ExpectTwoSumSolution(nums, 0, s.two_sum(nums, 0));
    });
}

// 10. Pair is at the beginning of the array
TEST(TwoSum, FirstTwoElements)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{10, 20, 30, 40};
        ExpectTwoSumSolution(nums, 30, s.two_sum(nums, 30));
    });
}

// 11. Pair is at the end of the array
TEST(TwoSum, PairAtEnd)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 1, 2, 3, 9};
        ExpectTwoSumSolution(nums, 12, s.two_sum(nums, 12));
    });
}

// 12. Pair is in the middle of the array
TEST(TwoSum, MiddlePair)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{9, 1, 5, 3, 7};
        ExpectTwoSumSolution(nums, 8, s.two_sum(nums, 8));
    });
}

// 13. A scattered pair
TEST(TwoSum, ScatteredPair)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{11, 2, 15, 7};
        ExpectTwoSumSolution(nums, 9, s.two_sum(nums, 9));
    });
}

// 14. Another typical case
TEST(TwoSum, UnsortedLargeAndSmall)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{150, 24, 79, 50, 88, 345, 3};
        ExpectTwoSumSolution(nums, 200, s.two_sum(nums, 200));
    });
}

// --- Special Cases ---

// 15. Pair includes a zero
TEST(TwoSum, PairIncludesZero)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5, 2, 0, 8};
        ExpectTwoSumSolution(nums, 8, s.two_sum(nums, 8));
    });
}

// 16. Target is zero
TEST(TwoSum, ZeroTarget)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-5, 1, 10, 5};
        ExpectTwoSumSolution(nums, 0, s.two_sum(nums, 0));
    });
}

// 17. Duplicates exist, but the pair uses distinct values
TEST(TwoSum, ComplementIsSelfDistinctIndex)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{3, 5, 3};
        ExpectTwoSumSolution(nums, 6, s.two_sum(nums, 6));
    });
}

// 18. The pair is composed of two duplicate numbers
TEST(TwoSum, PairOfDuplicates)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 3, 3, 4};
        ExpectTwoSumSolution(nums, 6, s.two_sum(nums, 6));
    });
}

// 19. All elements are the same
TEST(TwoSum, AllElementsSame)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5, 5, 5, 5};
        ExpectTwoSumSolution(nums, 10, s.two_sum(nums, 10));
    });
}

// 20. Large array test case
TEST(TwoSum, ManyElements)
{
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(10000, 1);
        nums[4999] = 5000;
        nums[9999] = 5000;
        ExpectTwoSumSolution(nums, 10000, s.two_sum(nums, 10000));
    });
}
