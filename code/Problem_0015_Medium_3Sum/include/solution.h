#pragma once
#include <vector>
#include <algorithm>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Two-Pointer after Sorting
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(log N) or O(N) (plus result)
    // Remarks:     Standard industry solution; elegant and efficient.
    /////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        const int n = static_cast<int>(nums.size());
        
        // We must have at least 3 numbers to form a triplet.
        if (n < 3) {
            return result;
        }

        // Sort the array. This is O(N log N).
        std::sort(nums.begin(), nums.end());

        // Outer loop for the first element 'i'.
        // We only need to go up to n-2 because we need at least
        // two more elements (left and right) after it.
        for (int i = 0; i < n - 2; ++i) {
            
            // **Duplicate Handling for 'i'**
            // If the current element is the same as the previous one,
            // we've already processed it. Skip to avoid duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Optimization: If the smallest number (nums[i]) is already
            // positive, the sum of three positive numbers can never be zero.
            if (nums[i] > 0) {
                break;
            }

            // Now we solve the "Two Sum" problem for the remainder
            // of the array, looking for a target sum of -nums[i].
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int two_sum = nums[left] + nums[right];

                if (two_sum == target) {
                    // Found a triplet!
                    result.push_back({nums[i], nums[left], nums[right]});

                    // **Duplicate Handling for 'left' and 'right'**
                    // Move left pointer forward as long as it's a duplicate
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    // Move right pointer backward as long as it's a duplicate
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    
                    // Move pointers to the next new element
                    ++left;
                    --right;

                } else if (two_sum < target) {
                    // Sum is too small, need a larger number
                    ++left;
                } else { // two_sum > target
                    // Sum is too large, need a smaller number
                    --right;
                }
            }
        }
        return result;
    }
};