#pragma once

#include <vector>
#include <algorithm> // Required for std::sort

namespace sorting_solution {

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Sorting + Adjacent Comparison
    // Time Cmplx:  O(N log N)
    // Space Cmplx: O(1) or O(log N) stack (for in-place sort)
    // Remarks:     A solid trade-off. Modifies the input array.
    /////////////////////////////////////////////////////////////////
    bool contains_duplicate(std::vector<int>& nums) {
        // 1. Sort the array. This is the dominant operation.
        std::sort(nums.begin(), nums.end());
        
        // 2. Scan for adjacent duplicates
        // We start at i = 1 to safely check nums[i - 1]
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

}  // namespace sorting_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using Solution = sorting_solution::Solution;
#endif
