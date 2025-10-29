#pragma once
#include <string>
#include <unordered_set>
#include <algorithm> // for std::max

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Optimized Brute-force (Expanding Window)
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(K), where K = unique characters
    // Remarks:     Better, but still TLE. Shows a step
    //              towards the optimal solution.
    /////////////////////////////////////////////////////////////////
    int lengthOfLongestSubstring(std::string s) {
        int n = static_cast<int>(s.size());
        int max_length = 0;

        for (int i = 0; i < n; ++i) {
            std::unordered_set<char> chars_in_window;
            // Note: We update max_length *inside* the inner loop
            // because "abc" is valid, and so is "ab".
            for (int j = i; j < n; ++j) {
                if (chars_in_window.count(s[j])) {
                    // Duplicate found. The longest window starting at 'i'
                    // ended at j-1. Break and move to i+1.
                    break;
                }
                // No duplicate, add to our window
                chars_in_window.insert(s[j]);
                // This window s[i..j] is valid, check its length
                max_length = std::max(max_length, j - i + 1);
            }
            // After the inner loop (break or end), chars_in_window
            // is destroyed and remade for the next 'i'.
        }
        return max_length;
    }
};