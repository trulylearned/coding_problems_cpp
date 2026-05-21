#pragma once

#include <string_view>
#include <utility>

#define ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
#include "solution.h"
#include "solution_brute_force.h"
#include "solution_optimal_layer_by_layer_swaps.h"
#include "solution_optimal_transpose.h"
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
    fn(SolutionInfo{"optimal_layer_by_layer_swaps", "optimal layer by layer swaps", true},
       solution_tag<optimal_layer_by_layer_swaps_solution::Solution>{});
    fn(SolutionInfo{"optimal_transpose", "optimal transpose", true},
       solution_tag<optimal_transpose_solution::Solution>{});
}

}  // namespace solutions
