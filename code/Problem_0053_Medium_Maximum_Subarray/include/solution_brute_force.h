#pragma once
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-force using nested loops
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Simple to understand, but too slow for the
    //              given constraints.
    /////////////////////////////////////////////////////////////////
    int maxSubArray(std::vector<int>& nums) {
        // Initialize with the smallest possible value, or nums[0]
        // Using nums[0] is fine because constraints say length >= 1
        int max_sum = nums[0]; 
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Start a new subarray sum for each new starting index 'i'
            int current_sum = 0; 
            for (int j = i; j < n; ++j) {
                // Extend the subarray to include element 'j'
                current_sum += nums[j];
                // Check if this new subarray sum is our global best
                max_sum = std::max(max_sum, current_sum);
            }
        }
        return max_sum;
    }
};