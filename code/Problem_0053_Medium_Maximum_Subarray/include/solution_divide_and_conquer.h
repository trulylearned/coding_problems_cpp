#pragma once
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
private:
    // Helper to find the max sum of a subarray that crosses the middle
    int find_max_crossing_sum(const std::vector<int>& nums, int left, int mid, int right) {
        // Find max sum starting from mid and going left
        int left_sum = std::numeric_limits<int>::min();
        int sum = 0;
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            left_sum = std::max(left_sum, sum);
        }
        
        // Find max sum starting from mid+1 and going right
        int right_sum = std::numeric_limits<int>::min();
        sum = 0;
        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            right_sum = std::max(right_sum, sum);
        }
        
        // The crossing sum is the combination of the best left and right parts
        return left_sum + right_sum;
    }

    // The main recursive helper function
    int find_max_subarray_sum(const std::vector<int>& nums, int left, int right) {
        // Base case: Only one element
        if (left == right) {
            return nums[left];
        }
        
        // Find midpoint (prevents overflow vs. (left+right)/2)
        int mid = left + (right - left) / 2;
        
        // 1. Max sum in the left half
        int left_half_sum = find_max_subarray_sum(nums, left, mid);
        
        // 2. Max sum in the right half
        int right_half_sum = find_max_subarray_sum(nums, mid + 1, right);
        
        // 3. Max sum that crosses the middle
        int crossing_sum = find_max_crossing_sum(nums, left, mid, right);
        
        // The result is the max of all three
        return std::max({left_half_sum, right_half_sum, crossing_sum});
    }

public:
    /////////////////////////////////////////////////////////////////
    // Method:      Divide and Conquer
    // Time Cmplx:  O(N log N)
    // Space Cmplx: O(log N) (due to recursion stack)
    // Remarks:     A more complex, but valid, approach.
    //              Demonstrates a different problem-solving paradigm.
    /////////////////////////////////////////////////////////////////
    int maxSubArray(std::vector<int>& nums) {
        return find_max_subarray_sum(nums, 0, (int)nums.size() - 1);
    }
};