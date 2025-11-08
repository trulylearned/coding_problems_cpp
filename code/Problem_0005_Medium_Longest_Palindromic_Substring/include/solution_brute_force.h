#pragma once
#include <string>
#include <string_view> // Use string_view for efficient checking

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force by Checking All Substrings
    // Time Cmplx:  O(N^3)
    // Space Cmplx: O(1) (or O(N) for the substring, though C++ substr can be O(N))
    // Remarks:     Simple to understand but impractical for N=1000.
    //              Will Time Limit Exceed (TLE).
    /////////////////////////////////////////////////////////////////
    
    // Helper function to check if a substring is a palindrome
    bool is_palindrome(const std::string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    std::string longest_palindrome(std::string s) {
        int n = static_cast<int>(s.size());
        if (n <= 1) {
            return s;
        }
        
        std::string longest_sub;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int current_len = j - i + 1;
                if (is_palindrome(s, i, j) && current_len > static_cast<int>(longest_sub.size())) {
                    longest_sub = s.substr(i, current_len);
                }
            }
        }
        return longest_sub;
    }
};