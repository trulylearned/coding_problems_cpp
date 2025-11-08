#pragma once
#include <vector>
#include <algorithm> // For std::min

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Linear Scan
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Simple and correct, but does *not* meet the
    //              problem's O(log N) time requirement.
    /////////////////////////////////////////////////////////////////
    int findMin(std::vector<int>& nums) {
        int min_val = nums[0];
        // Start from the second element (index 1)
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < min_val) {
                min_val = nums[i];
            }
        }
        return min_val;
    }
};