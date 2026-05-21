#include "solutions.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>      // For std::mt19937, std::shuffle
#include <numeric>     // For std::iota
#include <climits>     // For INT_MAX
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


// 1. LeetCode Example 1
TEST(LongestConsecutive, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{100, 4, 200, 1, 3, 2};
        EXPECT_EQ(s.longestConsecutive(nums), 4);
    });
}

// 2. LeetCode Example 2
TEST(LongestConsecutive, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        EXPECT_EQ(s.longestConsecutive(nums), 9);
    });
}

// 3. Custom example from LeetCode
TEST(LongestConsecutive, Example3) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 0, 1, 2};
        EXPECT_EQ(s.longestConsecutive(nums), 3);
    });
}

// 4. Edge Case: Empty
TEST(LongestConsecutive, Empty) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{};
        EXPECT_EQ(s.longestConsecutive(nums), 0);
    });
}

// 5. Edge Case: Single Element
TEST(LongestConsecutive, Single) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{42};
        EXPECT_EQ(s.longestConsecutive(nums), 1);
    });
}

// 6. Edge Case: All Duplicates
TEST(LongestConsecutive, AllDuplicates) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5, 5, 5, 5};
        EXPECT_EQ(s.longestConsecutive(nums), 1);
    });
}

// 7. Special Case: Negative Numbers Run
TEST(LongestConsecutive, NegativesRun) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-2, -1, 0};
        EXPECT_EQ(s.longestConsecutive(nums), 3);
    });
}

// 8. Typical Case: No Runs
TEST(LongestConsecutive, NoRuns) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{10, 30, 20};
        EXPECT_EQ(s.longestConsecutive(nums), 1);
    });
}

// 9. Typical Case: Longest run at the start
TEST(LongestConsecutive, LongAtStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 3, 10};
        EXPECT_EQ(s.longestConsecutive(nums), 3);
    });
}

// 10. Special Case: Large Negative Numbers
TEST(LongestConsecutive, WithLargeNegatives) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1000000000, -999999999, -999999998};
        EXPECT_EQ(s.longestConsecutive(nums), 3);
    });
}

// 11. Typical Case: Reverse Order
TEST(LongestConsecutive, ReverseOrder) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{4, 3, 2, 1};
        EXPECT_EQ(s.longestConsecutive(nums), 4);
    });
}

// 12. Typical Case: Scrambled Negatives
TEST(LongestConsecutive, NonConsecutiveNegatives) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-3, -1, -2, -4};
        EXPECT_EQ(s.longestConsecutive(nums), 4);
    });
}

// 13. Special Case: Duplicates Inside a Run
TEST(LongestConsecutive, DuplicatesInsideRun) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 2, 3};
        EXPECT_EQ(s.longestConsecutive(nums), 3);
    });
}

// 14. Typical Case: Mixed Gaps
TEST(LongestConsecutive, MixedGaps) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{100, 101, 102, 50, 51};
        EXPECT_EQ(s.longestConsecutive(nums), 3);
    });
}

// 15. Typical Case: Alternating Order
TEST(LongestConsecutive, AlternatingOrder) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 3, 2, 5, 4};
        EXPECT_EQ(s.longestConsecutive(nums), 5);
    });
}

// 16. Typical Case: Single Gap Inside
TEST(LongestConsecutive, SingleGapInside) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 4, 5, 6};
        EXPECT_EQ(s.longestConsecutive(nums), 3); // [4,5,6]
    });
}

// 17. Typical Case: Two Runs, Choose Longer
TEST(LongestConsecutive, TwoRunsChooseLonger) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{10, 11, 12, 1, 2, 3, 4};
        EXPECT_EQ(s.longestConsecutive(nums), 4);
    });
}

// 18. Special Case: Run Crosses Zero
TEST(LongestConsecutive, CrossZero) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, 0, 1, 2, 2};
        EXPECT_EQ(s.longestConsecutive(nums), 4);
    });
}

// 19. Large Case: 10,000 sequential numbers
TEST(LongestConsecutive, LargeSequential) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(10000);
        std::iota(nums.begin(), nums.end(), 0);
        // Shuffle to ensure unsorted input logic is tested
        std::mt19937 rng(123); // Fixed seed for reproducible tests
        std::shuffle(nums.begin(), nums.end(), rng);
        EXPECT_EQ(s.longestConsecutive(nums), 10000);
    });
}

// 20. Special Case: Near INT_MAX
TEST(LongestConsecutive, NearIntMax) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{INT_MAX - 2, INT_MAX - 1, INT_MAX};
        EXPECT_EQ(s.longestConsecutive(nums), 3);
    });
}