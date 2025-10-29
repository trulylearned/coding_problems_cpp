#pragma once
#include <string>
#include <array>
#include <numeric>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Frequency Counting (Array)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     A small optimization on Approach 2.
    //              Uses a fixed-size array, which is faster
    //              than a hash map when the key set is small and known.
    /////////////////////////////////////////////////////////////////
    int longest_palindrome(std::string s) {
        // 1. Count frequencies using a fixed-size array
        // Initialize all counts to 0
        std::array<int, 128> freq = {}; 
        
        for (char ch : s) {
            // 'ch' is implicitly cast to int, acting as the index
            ++freq[ch];
        }

        int length = 0;
        bool has_odd = false;

        // 2. Iterate through frequencies (only 128 spots)
        for (int count : freq) {
            if (count > 0) { // Check if this char was in the string
                if (count % 2 == 0) {
                    length += count;
                } else {
                    length += count - 1;
                    has_odd = true;
                }
            }
        }

        // 3. Add the center
        if (has_odd) {
            ++length;
        }

        return length;
    }
};