#pragma once

#include <string_view>
#include <utility>

#define ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
#include "solution.h"
#include "solution_brute_force_sort_and_compare.h"
#include "solution_optimal.h"
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
    fn(SolutionInfo{"brute_force_sort_and_compare", "brute force sort and compare", false},
       solution_tag<brute_force_sort_and_compare_solution::Solution>{});
    fn(SolutionInfo{"optimal", "optimal", true},
       solution_tag<optimal_solution::Solution>{});
}

}  // namespace solutions
