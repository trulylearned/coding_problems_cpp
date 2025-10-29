#pragma once
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Boyer-Moore Majority Vote
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Elegant and optimal. The standard solution.
    /////////////////////////////////////////////////////////////////
    int majority_element(std::vector<int>& nums) {
        int candidate = 0; // or nums[0], value doesn't matter
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                // We have a new candidate
                candidate = num;
            }
            
            // Add to count if 'num' is our candidate,
            // subtract if it's not.
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};