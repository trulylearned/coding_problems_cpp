#pragma once
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force using nested loops
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Easy to understand, but too slow for large inputs.
    /////////////////////////////////////////////////////////////////
    std::vector<int> two_sum(std::vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // Should not be reached based on problem constraints
    }
};