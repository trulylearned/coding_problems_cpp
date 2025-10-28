#pragma once
#include <vector>
#include <unordered_map>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Hash Map (Single Pass)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(N)
    // Remarks:     The most efficient and common solution.
    /////////////////////////////////////////////////////////////////
    std::vector<int> two_sum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen_numbers; // Key: number, Value: index
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int complement = target - nums[i];
            if (seen_numbers.contains(complement)) {  // C++20 feature, could also use count()
                return {seen_numbers[complement], i};
            }
            seen_numbers[nums[i]] = i;
        }
        return {}; // Should not be reached
    }
};