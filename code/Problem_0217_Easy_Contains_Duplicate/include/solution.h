#pragma once
#include <vector>
#include <unordered_set> // Required for std::unordered_set

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Hash Set Lookup
    // Time Cmplx:  O(N) (Average)
    // Space Cmplx: O(N) (Worst-Case)
    // Remarks:     Fastest time complexity, but trades space for speed.
    /////////////////////////////////////////////////////////////////
    bool contains_duplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen_elements;
        
        for (int num : nums) {
            // .contains() is a C++20/23 feature.
            // In C++17, we'd write: if (seen_elements.find(num) != seen_elements.end())
            if (seen_elements.contains(num)) {
                return true;
            }
            // If not seen, add it to the set for future checks.ˇ
            seen_elements.insert(num);
        }
        
        // Looped through the whole array, no duplicates found.
        return false;
    }
};