#pragma once
// IMPORTANT: Include all necessary modules for this specific solution here.
#include <vector>
#include <unordered_set>
#include <algorithm> // For std::max

class Solution {
private:
    // Helper methods can be defined here if needed.
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Hash set with "start of streak" check
    // Time Cmplx:  O(N) average
    // Space Cmplx: O(N)
    // Remarks:     Standard optimal approach required by problem.
    //              Uses C++20's .contains() for clarity.
    /////////////////////////////////////////////////////////////////
    int longestConsecutive(std::vector<int>& nums) {
        // 1. Build the set. O(N) on average.
        //    Using a set automatically handles all duplicates.
        std::unordered_set<int> num_set(nums.begin(), nums.end());

        int best_streak = 0;

        // 2. Iterate through the unique numbers.
        for (int x : num_set) {
            // 3. The "Aha!" insight: only start counting if 'x' is the
            //    true start of a sequence (i.e., x-1 is not present).
            //    .contains() is O(1) on average.
            if (!num_set.contains(x - 1)) {
                // We found a start, now count upwards
                int current_num = x;
                int current_streak = 1;

                // 4. Inner loop. This only runs once per sequence.
                while (num_set.contains(current_num + 1)) {
                    ++current_num;
                    ++current_streak;
                }
                
                best_streak = std::max(best_streak, current_streak);
            }
        }
        return best_streak;
    }
};