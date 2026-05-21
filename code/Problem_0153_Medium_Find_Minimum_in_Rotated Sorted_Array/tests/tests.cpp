#include "solutions.h"
#include <gtest/gtest.h>
#include <vector>
#include <numeric>   // For std::iota
#include <algorithm> // For std::rotate
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


// Test 1: LeetCode Example 1
TEST(FindMinRotatedSortedArray, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{3, 4, 5, 1, 2};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 2: LeetCode Example 2
TEST(FindMinRotatedSortedArray, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
        EXPECT_EQ(s.findMin(nums), 0);
    });
}

// Test 3: LeetCode Example 3 (Not rotated)
TEST(FindMinRotatedSortedArray, Example3_NotRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{11, 13, 15, 17};
        EXPECT_EQ(s.findMin(nums), 11);
    });
}

// Test 4: Edge Case - Single Element
TEST(FindMinRotatedSortedArray, SingleElement) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 5: Edge Case - Two Elements, Rotated
TEST(FindMinRotatedSortedArray, TwoElementsRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{2, 1};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 6: Edge Case - Two Elements, Not Rotated
TEST(FindMinRotatedSortedArray, TwoElementsNotRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 7: Three Elements, Pivot on Left
TEST(FindMinRotatedSortedArray, ThreeElementsPivotLeft) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{3, 1, 2};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 8: Three Elements, Pivot on Right
TEST(FindMinRotatedSortedArray, ThreeElementsPivotRight) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{2, 3, 1};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 9: Three Elements, Not Rotated
TEST(FindMinRotatedSortedArray, ThreeElementsNotRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 3};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 10: Typical Case - Pivot at End
TEST(FindMinRotatedSortedArray, PivotAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{2, 3, 4, 5, 1};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 11: Typical Case - Pivot at Start
TEST(FindMinRotatedSortedArray, PivotAtStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5, 1, 2, 3, 4};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 12: Typical Case - Pivot in Middle
TEST(FindMinRotatedSortedArray, PivotInMiddle) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5, 6, 7, 1, 2, 3, 4};
        EXPECT_EQ(s.findMin(nums), 1);
    });
}

// Test 13: Special Case - All Negative, Rotated
TEST(FindMinRotatedSortedArray, AllNegativeRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-5, -4, -1, -10, -9, -8};
        EXPECT_EQ(s.findMin(nums), -10);
    });
}

// Test 14: Special Case - All Negative, Not Rotated
TEST(FindMinRotatedSortedArray, AllNegativeNotRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-10, -9, -8, -5, -4, -1};
        EXPECT_EQ(s.findMin(nums), -10);
    });
}

// Test 15: Special Case - Mixed Values, Rotated
TEST(FindMinRotatedSortedArray, MixedValuesRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{10, 20, 30, -5, 0, 5};
        EXPECT_EQ(s.findMin(nums), -5);
    });
}

// Test 16: Special Case - Mixed Values, Not Rotated
TEST(FindMinRotatedSortedArray, MixedValuesNotRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-5, 0, 5, 10, 20, 30};
        EXPECT_EQ(s.findMin(nums), -5);
    });
}

// Test 17: Large Size - Not Rotated (Max constraints)
TEST(FindMinRotatedSortedArray, LargeSizeNotRotated) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(5000);
        std::iota(nums.begin(), nums.end(), 0); // Fills with 0, 1, 2, ..., 4999
        EXPECT_EQ(s.findMin(nums), 0);
    });
}

// Test 18: Large Size - Rotated by N (Full Rotation)
TEST(FindMinRotatedSortedArray, LargeSizeRotatedFull) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(5000);
        std::iota(nums.begin(), nums.end(), 0);
        // Rotating by N is equivalent to 0 rotations
        std::rotate(nums.begin(), nums.begin() + 5000, nums.end());
        EXPECT_EQ(s.findMin(nums), 0);
    });
}

// Test 19: Large Size - Rotated by Half
TEST(FindMinRotatedSortedArray, LargeSizeRotatedHalf) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(5000);
        std::iota(nums.begin(), nums.end(), 0);
        std::rotate(nums.begin(), nums.begin() + 2500, nums.end()); // 2500..4999, 0..2499
        EXPECT_EQ(s.findMin(nums), 0);
    });
}

// Test 20: Large Size - Rotated by One
TEST(FindMinRotatedSortedArray, LargeSizeRotatedOne) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(5000);
        std::iota(nums.begin(), nums.end(), 0);
        std::rotate(nums.begin(), nums.begin() + 4999, nums.end()); // [4999, 0, 1, ..., 4998]
        EXPECT_EQ(s.findMin(nums), 0);
    });
}
