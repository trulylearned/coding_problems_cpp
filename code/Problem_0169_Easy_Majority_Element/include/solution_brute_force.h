#pragma once
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force with Nested Loops
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Simple to understand, but will fail due to
    //              Time Limit Exceeded (TLE) on large inputs.
    /////////////////////////////////////////////////////////////////
    int majority_element(std::vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 2;

        for (int i = 0; i < n; ++i) {
            int current_num = nums[i];
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] == current_num) {
                    count++;
                }
            }
            
            if (count > threshold) {
                return current_num;
            }
        }
        
        return -1; // Should not be reached, as a majority element always exists.
    }
};