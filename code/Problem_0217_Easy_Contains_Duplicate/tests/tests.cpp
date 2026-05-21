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


// Make sure to use solution.contains_duplicate (snake_case)
// to match our enhanced solution file.

TEST(ContainsDuplicate, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 3, 1};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 3, 4};
        EXPECT_FALSE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, Example3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 1, 1, 3, 4, 3, 2, 4, 2};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

// ---- Custom Tests ----
TEST(ContainsDuplicate, CustomA_FromWalkthrough) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{4, 2, 7, 1, 9, 7};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, CustomB_FromWalkthrough) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{10, 5, -3, 8, 2};
        EXPECT_FALSE(s.contains_duplicate(nums));
    });
}

// ---- Edge Cases ----
TEST(ContainsDuplicate, EmptyInput) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{}; // Empty vector
        EXPECT_FALSE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, SingleElement) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5};
        EXPECT_FALSE(s.contains_duplicate(nums));
    });
}

// ---- Typical Cases ----
TEST(ContainsDuplicate, TwoSameElements) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{42, 42};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, TwoDifferentElements) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{42, 43};
        EXPECT_FALSE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, AllDistinctLargeRange) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums;
        for (int i = 0; i < 1000; ++i) nums.push_back(i);
        EXPECT_FALSE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, LargeInputWithDuplicateAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums;
        for (int i = 0; i < 10000; ++i) nums.push_back(i);
        nums.push_back(9999); // Duplicate at the very end
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, LargeInputWithDuplicateAtStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0};
        for (int i = 1; i < 10000; ++i) nums.push_back(i);
        nums.push_back(0); // Duplicate of the first element
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

// ---- Special Cases (Negatives, Zeros, Large Values) ----
TEST(ContainsDuplicate, NegativeNumbers) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, -2, -3, -1};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, MixedPosNeg) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, 1, -2, 2, -1};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, ZerosAndOthers) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 1, 2, 3, 0};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, DistantDuplicates) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{100, 200, 300, 400, 100};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, LargeAllSame) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(10000, 5);
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, AlternatingPattern) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 1, 2, 3, 4, 5};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, EdgeMinMaxValues) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1000000000, 0, 1000000000, -1000000000};
        EXPECT_TRUE(s.contains_duplicate(nums));
    });
}

TEST(ContainsDuplicate, EdgeMaxValuesNoDuplicate) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1000000000, -1000000000, 0};
        EXPECT_FALSE(s.contains_duplicate(nums));
    });
}