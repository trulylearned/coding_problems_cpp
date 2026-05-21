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


// 1. LeetCode Example 1
TEST(ContainerWithMostWater, Example1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{1,8,6,2,5,4,8,3,7};
        EXPECT_EQ(s.maxArea(height), 49);
    });
}

// 2. LeetCode Example 2
TEST(ContainerWithMostWater, Example2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{1,1};
        EXPECT_EQ(s.maxArea(height), 1);
    });
}

// 3. Typical Case: Strictly increasing heights
TEST(ContainerWithMostWater, IncreasingHeights) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{1,2,3,4,5}; // (4-1)*min(2,5) = 3*2 = 6
        EXPECT_EQ(s.maxArea(height), 6);
    });
}

// 4. Typical Case: Strictly decreasing heights
TEST(ContainerWithMostWater, DecreasingHeights) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{5,4,3,2,1}; // (1-0)*min(5,4) = 4, (2-0)*min(5,3)=6
        EXPECT_EQ(s.maxArea(height), 6);
    });
}

// 5. Typical Case: All same height (plateau)
TEST(ContainerWithMostWater, Plateau) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{3,3,3,3,3}; // (4-0)*min(3,3) = 4*3 = 12
        EXPECT_EQ(s.maxArea(height), 12);
    });
}

// 6. Edge Case: Zeros mixed in
TEST(ContainerWithMostWater, ZerosAndHeights) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{0,0,10,0,0,0,10,0}; // (6-2)*min(10,10) = 4*10 = 40
        EXPECT_EQ(s.maxArea(height), 40);
    });
}

// 7. Typical Case: Alternating low/high
TEST(ContainerWithMostWater, AlternateHeights) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{1,0,1,0,1}; // (4-0)*min(1,1) = 4*1 = 4
        EXPECT_EQ(s.maxArea(height), 4);
    });
}

// 8. Typical Case: Tallest in the middle
TEST(ContainerWithMostWater, SingleTallInMiddle) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{1,100,1}; // (2-0)*min(1,1) = 2*1 = 2
        EXPECT_EQ(s.maxArea(height), 2);
    });
}

// 9. Constraint Test: Large values, medium N
TEST(ContainerWithMostWater, LargeValues) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height(1000, 10000); // (999-0)*10000 = 9,990,000
        EXPECT_EQ(s.maxArea(height), 9990000);
    });
}

// 10. Typical Case: Tallest on ends
TEST(ContainerWithMostWater, SparseTallHeights) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{10,0,0,0,10}; // (4-0)*min(10,10) = 4*10 = 40
        EXPECT_EQ(s.maxArea(height), 40);
    });
}

// 11. Custom Example from lesson
TEST(ContainerWithMostWater, RandomPattern1) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{2,3,4,5,18,17,6}; // (5-4)*min(18,17) = 1*17 = 17
        EXPECT_EQ(s.maxArea(height), 17);
    });
}

// 12. Typical Case: "U" shape
TEST(ContainerWithMostWater, RandomPattern2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{4,3,2,1,4}; // (4-0)*min(4,4) = 4*4 = 16
        EXPECT_EQ(s.maxArea(height), 16);
    });
}

// 13. Edge Case: All zeros
TEST(ContainerWithMostWater, AllZeros) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{0,0,0,0};
        EXPECT_EQ(s.maxArea(height), 0);
    });
}

// 14. Typical Case: Tallest at one end
TEST(ContainerWithMostWater, OneLargeAtEnd) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{1,2,3,4,100}; // (3-1)*min(2,4) = 2*2=4, (2-1)*min(2,3)=2. (4-1)*min(2,100)=3*2=6
        EXPECT_EQ(s.maxArea(height), 6);
    });
}

// 15. Typical Case: Multiple peaks
TEST(ContainerWithMostWater, AlternatingPeaks) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{1,10,1,10,1,10}; // (5-1)*min(10,10) = 4*10=40, (3-1)*min(10,10)=20. (5-3)*min(10,10)=20. (4-1)*min(10,10)=30. (5-0)*min(1,10)=5
        EXPECT_EQ(s.maxArea(height), 40); // (5-1)*min(10,10) is 40. Wait, (3-1)*10=20. (5-3)*10=20. (5-1)*10=40. (4-1)*10=30. (5-0)*1=5.
        // Let's re-trace 1,10,1,10,1,10
        // l=0(1), r=5(10). A=5*1=5. max=5. l++
        // l=1(10), r=5(10). A=4*10=40. max=40. r-- (or l++)
        // l=1(10), r=4(1). A=3*1=3. max=40. r--
        // l=1(10), r=3(10). A=2*10=20. max=40. r-- (or l++)
        // l=1(10), r=2(1). A=1*1=1. max=40. r--
        // l=1(10), r=1(10). stop.
        // The test in the file said 50, which is wrong. (4-1)*min(10,10) = 3*10=30. (3-1)*min(10,10)=20.
        // My trace gives 40.
        // Let's re-trace again. `[1,10,1,10,1,10]`
        // 0, 5: min(1,10)*5 = 5. max=5. ++l
        // 1, 5: min(10,10)*4 = 40. max=40. --r (arbitrary)
        // 1, 4: min(10,1)*3 = 3. max=40. --r
        // 1, 3: min(10,10)*2 = 20. max=40. --r (arbitrary)
        // 1, 2: min(10,1)*1 = 1. max=40. --r
        // 1, 1: stop.
        // What if we ++l at 1,5?
        // 1, 5: min(10,10)*4 = 40. max=40. ++l
        // 2, 5: min(1,10)*3 = 3. max=40. ++l
        // 3, 5: min(10,10)*2 = 20. max=40. ++l (arbitrary)
        // 4, 5: min(1,10)*1 = 1. max=40. ++l
        // 5, 5: stop.
        // The max area is 40. The original test was 50, which is incorrect.
        EXPECT_EQ(s.maxArea(height), 40);
    });
}

// 16. Edge Case: Minimum size N=2, decreasing
TEST(ContainerWithMostWater, ShortArray) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{2,1};
        EXPECT_EQ(s.maxArea(height), 1);
    });
}

// 17. Edge Case: Handles empty vector (though constraint is N>=2)
TEST(ContainerWithMostWater, EmptyHeights) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{};
        EXPECT_EQ(s.maxArea(height), 0);
    });
}

// 18. Constraint Test: Max N, medium values
TEST(ContainerWithMostWater, LargeRandom) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height(100000, 1000); // (99999-0)*1000 = 99,999,000
        EXPECT_EQ(s.maxArea(height), 99999000);
    });
}

// 19. Constraint Test: N=2, Max height
TEST(ContainerWithMostWater, EdgeCaseMaxHeights) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{10000,10000}; // (1-0)*10000 = 10000
        EXPECT_EQ(s.maxArea(height), 10000);
    });
}

// 20. Edge Case: Minimum size N=2
TEST(ContainerWithMostWater, EdgeCaseNEquals2) {
    for_each_solution_for_current_test([](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution s;
        std::vector<int> height{10,5}; // (1-0)*min(10,5) = 5
        EXPECT_EQ(s.maxArea(height), 5);
    });
}