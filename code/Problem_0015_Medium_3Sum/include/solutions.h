#pragma once

#include <string_view>
#include <utility>

#define ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
#include "solution.h"
#include "solution_brute_force.h"
#include "solution_hash_set.h"
#include "solution_optimal_two_pointer_after_sorting.h"
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
    fn(SolutionInfo{"hash_set", "hash set", true},
       solution_tag<hash_set_solution::Solution>{});
    fn(SolutionInfo{"optimal_two_pointer_after_sorting", "optimal two pointer after sorting", true},
       solution_tag<optimal_two_pointer_after_sorting_solution::Solution>{});
}

}  // namespace solutions
