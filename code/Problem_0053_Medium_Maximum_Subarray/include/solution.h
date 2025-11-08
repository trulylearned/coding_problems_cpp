#pragma once
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Kadane’s Algorithm (Dynamic Running Sum)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Elegant, optimal, and a very common
    //              interview pattern.
    /////////////////////////////////////////////////////////////////
    int maxSubArray(std::vector<int>& nums) {
        // We must start with the first element, as the
        // subarray must have at least one element.
        int current_sum = nums[0];
        int max_sum = nums[0];

        // Start from the second element (index 1)
        for (size_t i = 1; i < nums.size(); ++i) {
            // The "Aha!" moment:
            // Do we start a new subarray, or extend the old one?
            // 1. Start new: nums[i]
            // 2. Extend old: current_sum + nums[i]
            current_sum = std::max(nums[i], current_sum + nums[i]);
            
            // Did our local best just beat our global best?
            max_sum = std::max(max_sum, current_sum);
        }
        return max_sum;
    }
};