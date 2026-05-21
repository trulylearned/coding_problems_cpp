#pragma once

#include <string_view>
#include <utility>

#define ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
#include "solution.h"
#include "solution_brute_force_check_all_substrings.h"
#include "solution_brute_force_optimized_expanding_window.h"
#include "solution_optimal_hash_map_jump.h"
#include "solution_optimal_sliding_window_fixed_size_array.h"
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
    fn(SolutionInfo{"brute_force_check_all_substrings", "brute force check all substrings", false},
       solution_tag<brute_force_check_all_substrings_solution::Solution>{});
    fn(SolutionInfo{"brute_force_optimized_expanding_window", "brute force optimized expanding window", false},
       solution_tag<brute_force_optimized_expanding_window_solution::Solution>{});
    fn(SolutionInfo{"optimal_hash_map_jump", "optimal hash map jump", true},
       solution_tag<optimal_hash_map_jump_solution::Solution>{});
    fn(SolutionInfo{"optimal_sliding_window_fixed_size_array", "optimal sliding window fixed size array", true},
       solution_tag<optimal_sliding_window_fixed_size_array_solution::Solution>{});
}

}  // namespace solutions
