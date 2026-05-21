#pragma once

#include <string_view>
#include <utility>

#define ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
#include "solution.h"
#include "solution_alternative_disjoint_set_and_union_find.h"
#include "solution_baseline_sort_and_linear_scan.h"
#include "solution_optimal_hash_set_and_start_detection.h"
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
    fn(SolutionInfo{"alternative_disjoint_set_and_union_find", "alternative disjoint set and union find", true},
       solution_tag<alternative_disjoint_set_and_union_find_solution::Solution>{});
    fn(SolutionInfo{"baseline_sort_and_linear_scan", "baseline sort and linear scan", true},
       solution_tag<baseline_sort_and_linear_scan_solution::Solution>{});
    fn(SolutionInfo{"optimal_hash_set_and_start_detection", "optimal hash set and start detection", true},
       solution_tag<optimal_hash_set_and_start_detection_solution::Solution>{});
}

}  // namespace solutions
