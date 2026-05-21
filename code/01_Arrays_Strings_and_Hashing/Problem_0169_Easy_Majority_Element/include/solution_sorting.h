#pragma once

#include <vector>
#include <algorithm>

namespace sorting_solution {

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Sorting-Based Detection
    // Time Cmplx:  O(N log N)
    // Space Cmplx: O(1) (or O(log N) for stack space)
    // Remarks:     Clever insight, but slower than linear.
    //              Modifies the input array.
    /////////////////////////////////////////////////////////////////
    int majority_element(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

}  // namespace sorting_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using Solution = sorting_solution::Solution;
#endif
