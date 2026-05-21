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


// Make sure all tests use the snake_case function name
TEST(MajorityElement, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{3, 2, 3};
        EXPECT_EQ(s.majority_element(nums), 3);
    });
}

TEST(MajorityElement, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
        EXPECT_EQ(s.majority_element(nums), 2);
    });
}

// Custom tests
TEST(MajorityElement, SingleElement) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{42};
        EXPECT_EQ(s.majority_element(nums), 42);
    });
}

TEST(MajorityElement, TwoElementsSame) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{7, 7};
        EXPECT_EQ(s.majority_element(nums), 7);
    });
}

TEST(MajorityElement, MajorityAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 2, 3, 4, 4, 4, 4};
        EXPECT_EQ(s.majority_element(nums), 4);
    });
}

// THIS TEST IS NOW FIXED
TEST(MajorityElement, MajorityAtStart) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        // Old invalid test: {9, 9, 9, 2, 2, 3} (n=6, threshold=3, count=3. Not majority)
        std::vector<int> nums{9, 9, 9, 1, 2}; // (n=5, threshold=2, count=3. Is majority)
        EXPECT_EQ(s.majority_element(nums), 9);
    });
}

TEST(MajorityElement, Alternating) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{5, 1, 5, 1, 5, 1, 5};
        EXPECT_EQ(s.majority_element(nums), 5);
    });
}

TEST(MajorityElement, NegativeNumbers) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-1, -1, -1, 2, 3};
        EXPECT_EQ(s.majority_element(nums), -1);
    });
}

TEST(MajorityElement, MixedSigns) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{-2, -2, 3, -2, 3, -2};
        EXPECT_EQ(s.majority_element(nums), -2);
    });
}

TEST(MajorityElement, LargeInputSameValue) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(10000, 8);
        EXPECT_EQ(s.majority_element(nums), 8);
    });
}

TEST(MajorityElement, HalfBoundary) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 1, 2, 2, 2};
        EXPECT_EQ(s.majority_element(nums), 2);
    });
}

TEST(MajorityElement, Interleaved) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{3, 4, 3, 4, 3, 3, 4, 3};
        EXPECT_EQ(s.majority_element(nums), 3);
    });
}

TEST(MajorityElement, LargeDeterministic) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums;
        // Creates 8000 '6's and 2000 '7's. Majority is 6.
        for (int i = 0; i < 10000; ++i)
            nums.push_back(i % 5 == 0 ? 7 : 6);
        EXPECT_EQ(s.majority_element(nums), 6);
    });
}

TEST(MajorityElement, WithZeros) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{0, 0, 1, 0, 2, 0, 3, 0, 0};
        EXPECT_EQ(s.majority_element(nums), 0);
    });
}

TEST(MajorityElement, BoundaryCaseSmall) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{1, 1, 2};
        EXPECT_EQ(s.majority_element(nums), 1);
    });
}

TEST(MajorityElement, OddCountMajority) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{4, 4, 5, 4, 5, 4, 4};
        EXPECT_EQ(s.majority_element(nums), 4);
    });
}

TEST(MajorityElement, SparseDistribution) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{9, 1, 9, 2, 9, 3, 9, 4, 9};
        EXPECT_EQ(s.majority_element(nums), 9);
    });
}

TEST(MajorityElement, DifferentMajorities) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums{10, 10, 10, 2, 2, 2, 10};
        EXPECT_EQ(s.majority_element(nums), 10);
    });
}

TEST(MajorityElement, CheckPerformance) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> nums(50000, 1);
        EXPECT_EQ(s.majority_element(nums), 1);
    });
}
