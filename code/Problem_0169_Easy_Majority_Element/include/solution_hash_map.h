#pragma once

#include <vector>
#include <unordered_map>

namespace hash_map_solution {

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Hash Map (Frequency Counting)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(N)
    // Remarks:     Very common and intuitive. Fast, but does not
    //              meet the O(1) space follow-up.
    /////////////////////////////////////////////////////////////////
    int majority_element(std::vector<int>& nums) {
        std::unordered_map<int, int> frequencies;
        int threshold = nums.size() / 2;

        for (int num : nums) {
            frequencies[num]++;
            if (frequencies[num] > threshold) {
                return num;
            }
        }
        
        return -1; // Should not be reached.
    }
};

}  // namespace hash_map_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using Solution = hash_map_solution::Solution;
#endif
