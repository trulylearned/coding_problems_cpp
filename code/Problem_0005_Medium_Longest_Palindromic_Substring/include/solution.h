#pragma once
#include <string>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Expand Around Center
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Clean, elegant, and the standard interview approach.
    //              Vastly superior to brute-force.
    /////////////////////////////////////////////////////////////////
    std::string longest_palindrome(std::string s) {
        int n = static_cast<int>(s.size());
        if (n <= 1) {
            return s;
        }

        int start = 0;
        int max_len = 1; // A single char is the min palindrome

        // Helper lambda for expanding
        auto expand_around_center = [&](int left, int right) {
            // Expand as long as we are in bounds and chars match
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            
            // We exit the loop when the match fails.
            // The valid palindrome is *inside* the current (l, r).
            // Its length is (right - 1) - (left + 1) + 1 = right - left - 1
            int current_len = right - left - 1;
            
            if (current_len > max_len) {
                max_len = current_len;
                // The start of this new longest palindrome is at left + 1
                start = left + 1;
            }
        };

        for (int i = 0; i < n; ++i) {
            // 1. Check for odd-length palindromes (center is at i)
            expand_around_center(i, i);
            
            // 2. Check for even-length palindromes (center is between i and i+1)
            expand_around_center(i, i + 1);
        }

        return s.substr(start, max_len);
    }
};