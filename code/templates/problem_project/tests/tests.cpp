#include "solutions.h"

#include <gtest/gtest.h>

#include <string>
#include <string_view>
#include <vector>

namespace {

bool CurrentTestIsStress() {
    const auto* test_info = ::testing::UnitTest::GetInstance()->current_test_info();
    if (test_info == nullptr) {
        return false;
    }

    constexpr std::string_view stress_markers[] = {
        "Large", "Long", "Many", "MaxN", "Largest", "Stress", "Performance",
        "Constraint", "RandomValidity", "LongSequence"
    };

    const std::string_view suite_name = test_info->test_suite_name();
    const std::string_view test_name = test_info->name();

    for (std::string_view marker : stress_markers) {
        if (suite_name.find(marker) != std::string_view::npos ||
            test_name.find(marker) != std::string_view::npos) {
            return true;
        }
    }

    return false;
}

template <typename Fn>
void ForEachSolutionForCurrentTest(Fn&& fn) {
    solutions::for_each_solution([&](const solutions::SolutionInfo& solution_info,
                                     auto solution_type) {
        if (!solution_info.run_stress_tests && CurrentTestIsStress()) {
            return;
        }

        SCOPED_TRACE(std::string(solution_info.id));
        fn(solution_type);
    });
}

}  // namespace

// Tests for {{PROBLEM_DISPLAY_NAME}}.
{{TEST_CASES}}
