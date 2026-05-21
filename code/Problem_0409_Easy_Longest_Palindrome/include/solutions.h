#pragma once

#include <string_view>
#include <utility>

#define ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
#include "solution.h"
#include "solution_brute_force.h"
#include "solution_optimal_frequence_counting_array_52.h"
#include "solution_optimal_frequency_counting_array.h"
#include "solution_optimal_frequency_counting_hash_map.h"
#include "solution_optimal_odd_count_trick.h"
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
    fn(SolutionInfo{"optimal_frequence_counting_array_52", "optimal frequence counting array 52", true},
       solution_tag<optimal_frequence_counting_array_52_solution::Solution>{});
    fn(SolutionInfo{"optimal_frequency_counting_array", "optimal frequency counting array", true},
       solution_tag<optimal_frequency_counting_array_solution::Solution>{});
    fn(SolutionInfo{"optimal_frequency_counting_hash_map", "optimal frequency counting hash map", true},
       solution_tag<optimal_frequency_counting_hash_map_solution::Solution>{});
    fn(SolutionInfo{"optimal_odd_count_trick", "optimal odd count trick", true},
       solution_tag<optimal_odd_count_trick_solution::Solution>{});
}

}  // namespace solutions
