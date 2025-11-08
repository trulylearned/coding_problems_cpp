#pragma once
#include <string>
#include <vector>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Dynamic Programming
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(N^2)
    // Remarks:     A classic DP pattern. Good to know, but the O(1)
    //              space solution is usually preferred in interviews.
    /////////////////////////////////////////////////////////////////
    std::string longest_palindrome(std::string s) {
        int n = static_cast<int>(s.size());
        if (n <= 1) {
            return s;
        }

        // dp[i][j] = true if s[i...j] is a palindrome
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        int start = 0;
        int max_len = 1;

        // Base Case: All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Base Case: Check for substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                max_len = 2;
            }
        }

        // Fill the table for lengths 3 and greater
        // 'len' is the length of the substring
        for (int len = 3; len <= n; ++len) {
            // 'i' is the starting index
            for (int i = 0; i <= n - len; ++i) {
                // 'j' is the ending index
                int j = i + len - 1;

                // Check the transition:
                // 1. Outer chars must match
                // 2. Inner substring must be a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    
                    if (len > max_len) {
                        max_len = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, max_len);
    }
};