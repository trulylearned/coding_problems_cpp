#pragma once

#include <string_view>
#include <utility>

#define ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
#include "solution.h"
#include "solution_brute_force.h"
#include "solution_optimal.h"
#include "solution_sorting.h"
#undef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS

namespace solutions {

struct SolutionInfo {
    std::string_view id;
    std::string_view method;
    bool run_stress_tests;
};

template <typename T>
struct solution_tag {
    using type = T;
};

template <typename Fn>
void for_each_solution(Fn&& fn) {
    fn(SolutionInfo{"default", "Current default implementation", true},
       solution_tag<default_solution::Solution>{});
    fn(SolutionInfo{"brute_force", "brute force", false},
       solution_tag<brute_force_solution::Solution>{});
    fn(SolutionInfo{"optimal", "optimal", true},
       solution_tag<optimal_solution::Solution>{});
    fn(SolutionInfo{"sorting", "sorting", true},
       solution_tag<sorting_solution::Solution>{});
}

}  // namespace solutions
