#pragma once
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force using nested loops
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Simple to understand but inefficient. Will TLE.
    /////////////////////////////////////////////////////////////////
    bool contains_duplicate(std::vector<int>& nums) {
        // We use snake_case for the LeetCode function name
        // as per our project's coding standards.
        for (size_t i = 0; i < nums.size(); ++i) {
            // Start j from i + 1 to avoid comparing an element with itself
            // and to avoid redundant (j, i) comparisons.
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};