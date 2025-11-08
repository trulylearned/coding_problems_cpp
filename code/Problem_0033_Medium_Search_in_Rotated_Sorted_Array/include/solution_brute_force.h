#pragma once
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Linear Scan (Brute Force)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Straightforward but fails the O(log N) requirement.
    /////////////////////////////////////////////////////////////////
    int search(std::vector<int>& nums, int target) {
        // Iterate through every element in the vector
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] == target) {
                return i; // Found it
            }
        }
        return -1; // Did not find it
    }
};