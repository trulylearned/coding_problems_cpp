#pragma once
#include <string>
#include <unordered_map>
#include <algorithm> // for std::max
#include <concepts>  // for C++20 .contains()

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Optimal Sliding Window (Hash Map Jump)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(K), where K = unique characters
    // Remarks:     Industry-standard optimal approach.
    /////////////////////////////////////////////////////////////////
    int lengthOfLongestSubstring(std::string s) {
        // Map to store the last seen index of each character
        std::unordered_map<char, int> last_seen_index;
        int max_length = 0;
        int left_pointer = 0;

        for (int right_pointer = 0; right_pointer < static_cast<int>(s.size()); ++right_pointer) {
            char current_char = s[right_pointer];

            // Check if we've seen this character before
            // .contains() is C++20
            if (last_seen_index.contains(current_char)) {
                // Check if the last seen index is *within* our current window
                if (last_seen_index[current_char] >= left_pointer) {
                    // If yes, we have a duplicate in the window.
                    // We must "jump" the left pointer to the position
                    // *after* the previous occurrence.
                    left_pointer = last_seen_index[current_char] + 1;
                }
            }

            // Update the last seen index for this character to its current position
            last_seen_index[current_char] = right_pointer;
            
            // Calculate the length of the current window and update max
            max_length = std::max(max_length, right_pointer - left_pointer + 1);
        }

        return max_length;
    }
};