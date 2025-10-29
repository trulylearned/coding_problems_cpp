#pragma once
#include <string>
#include <unordered_map>
#include <numeric> // For std::accumulate

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Frequency Counting (Hash Map)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1) (or O(K) for unbounded char set)
    // Remarks:     The most straightforward optimal solution.
    //              Uses a hash map to count frequencies.
    /////////////////////////////////////////////////////////////////
    int longest_palindrome(std::string s) {
        // 1. Count frequencies
        std::unordered_map<char, int> freq;
        for (char ch : s) {
            ++freq[ch];
        }

        int length = 0;
        bool has_odd = false;

        // 2. Iterate through frequencies to build pairs
        for (auto& [character, count] : freq) {
            if (count % 2 == 0) {
                // If count is even, add it all
                length += count;
            } else {
                // If count is odd, add the even part (count - 1)
                length += count - 1;
                has_odd = true; // Mark that we have a leftover
            }
        }

        // 3. Add the center character if we had any leftovers
        if (has_odd) {
            ++length;
        }

        return length;
    }
};