#pragma once
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Binary Search in Rotated Sorted Array
    // Time Cmplx:  O(log N)
    // Space Cmplx: O(1)
    // Remarks:     Classic interview question. The key is to find
    //              the sorted half in each iteration.
    /////////////////////////////////////////////////////////////////
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            // Use this form to prevent overflow for very large arrays
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check which half is sorted
            // Case 1: The left half (from left to mid) is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target is within this sorted left half
                if (nums[left] <= target && target < nums[mid]) {
                    // Target is in the left half, discard the right
                    right = mid - 1;
                } else {
                    // Target is in the right half, discard the left
                    left = mid + 1;
                }
            } 
            // Case 2: The right half (from mid to right) is sorted
            else {
                // Check if target is within this sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    // Target is in the right half, discard the left
                    left = mid + 1;
                } else {
                    // Target is in the left half, discard the right
                    right = mid - 1;
                }
            }
        }
        
        // Target was not found
        return -1;
    }
};