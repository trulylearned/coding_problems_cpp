#pragma once
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Hash Set Optimization
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(N + K)
    // Remarks:     Another O(N^2) approach, but higher space
    //              overhead than the two-pointer method.
    /////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (n < 3) {
            return {};
        }

        // We sort to easily skip the outer 'i' duplicate.
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> result_set; // To handle result duplicates

        for (int i = 0; i < n - 2; ++i) {
            // **Duplicate Handling for 'i'**
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] > 0) {
                break;
            }

            // Use a hash set for the inner "Two Sum" problem
            std::unordered_set<int> seen;
            
            for (int j = i + 1; j < n; ++j) {
                int complement = -nums[i] - nums[j];
                
                // Check if we've seen the complement before
                if (seen.count(complement)) {
                    // We found a triplet.
                    // The set takes care of ordering and duplicates.
                    result_set.insert({nums[i], complement, nums[j]});
                }
                
                // Add the current number to our 'seen' set
                seen.insert(nums[j]);
            }
        }
        
        return std::vector<std::vector<int>>(result_set.begin(), result_set.end());
    }
};