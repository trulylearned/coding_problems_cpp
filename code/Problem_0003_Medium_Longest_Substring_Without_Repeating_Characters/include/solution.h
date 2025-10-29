#pragma once
#include <string>
#include <vector>
#include <algorithm> // for std::max

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Optimal Sliding Window (Array as Map)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(K), where K = 128 (ASCII set size)
    // Remarks:     Fastest approach. Assumes a limited
    //              character set (e.g., ASCII).
    /////////////////////////////////////////////////////////////////
    int lengthOfLongestSubstring(std::string s) {
        // Use a vector as a fixed-size array for the ASCII set (128 chars)
        // Initialize all to -1 (or any value < 0) to indicate "not seen"
        std::vector<int> last_seen_index(128, -1);
        int max_length = 0;
        int left_pointer = 0;

        for (int right_pointer = 0; right_pointer < static_cast<int>(s.size()); ++right_pointer) {
            // C++ automatically casts char to its int (ASCII) value
            char current_char = s[right_pointer];
            
            // Check if we've seen this char and its last index is in our window
            if (last_seen_index[current_char] >= left_pointer) {
                // Jump the left pointer
                left_pointer = last_seen_index[current_char] + 1;
            }

            // Update the last seen index for this character
            last_seen_index[current_char] = right_pointer;

            // Update max length
            max_length = std::max(max_length, right_pointer - left_pointer + 1);
        }
        return max_length;
    }
};