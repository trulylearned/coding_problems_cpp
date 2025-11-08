#pragma once
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Binary Search on Rotated Sorted Array
    // Time Cmplx:  O(log N)
    // Space Cmplx: O(1)
    // Remarks:     This is the standard, optimal solution that
    //              meets the problem's time requirement.
    /////////////////////////////////////////////////////////////////
    int findMin(std::vector<int>& nums) {
        int left = 0;
        // Use a safe cast for size(), though with n <= 5000 it's not strictly needed
        int right = static_cast<int>(nums.size()) - 1;

        // We use 'left < right' because we want the loop to
        // terminate when the search space is 1 element (left == right).
        while (left < right) {
            // Standard overflow-preventing mid calculation
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Case 1: mid is in the "large" part.
                // The minimum must be to the right of mid.
                left = mid + 1;
            } else {
                // Case 2: mid is in the "small" part.
                // The minimum is at mid or to its left.
                // We keep 'mid' as a potential answer.
                right = mid;
            }
        }

        // When the loop ends, left == right, and this
        // index points to the smallest element.
        return nums[left];
    }
};