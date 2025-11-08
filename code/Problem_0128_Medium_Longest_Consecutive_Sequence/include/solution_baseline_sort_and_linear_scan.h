#pragma once
// IMPORTANT: Include all necessary modules for this specific solution here.
#include <vector>
#include <algorithm> // For std::sort and std::max

class Solution {
private:
    // Helper methods can be defined here if needed.
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Baseline via sorting + single pass
    // Time Cmplx:  O(N log N)
    // Space Cmplx: O(log N)
    // Remarks:     Simple to write and understand. A good first
    //              pass, but fails the O(N) time requirement.
    /////////////////////////////////////////////////////////////////
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Sort the array, which costs O(N log N)
        std::sort(nums.begin(), nums.end());

        int best_streak = 1;
        int current_streak = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                continue; // Skip duplicates, they don't extend the streak
            }
            
            if (nums[i] == nums[i - 1] + 1) {
                // This number continues the streak
                ++current_streak;
            } else {
                // The streak is broken
                best_streak = std::max(best_streak, current_streak);
                current_streak = 1; // Start a new streak
            }
        }
        
        // Final check in case the longest streak ended at the last element
        best_streak = std::max(best_streak, current_streak);
        
        return best_streak;
    }
};