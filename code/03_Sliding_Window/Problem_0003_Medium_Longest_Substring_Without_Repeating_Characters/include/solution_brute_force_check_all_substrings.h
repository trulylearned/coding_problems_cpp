#pragma once

#include <string>
#include <unordered_set>
#include <algorithm> // for std::max

namespace brute_force_check_all_substrings_solution {

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-force check of all substrings
    // Time Cmplx:  O(N^3)
    // Space Cmplx: O(K), where K = unique characters
    // Remarks:     Educational but will Time Limit Exceed.
    /////////////////////////////////////////////////////////////////
    int lengthOfLongestSubstring(std::string s) {
        int n = static_cast<int>(s.size());
        int max_length = 0;

        // Loop 1: Iterate over all possible start points
        for (int i = 0; i < n; ++i) {
            // Loop 2: Iterate over all possible end points
            for (int j = i; j < n; ++j) {
                // Now we check the substring s[i...j]
                std::unordered_set<char> chars_in_substring;
                bool is_unique = true;

                // Loop 3: Check for uniqueness
                for (int k = i; k <= j; ++k) {
                    if (chars_in_substring.count(s[k])) {
                        // Duplicate found
                        is_unique = false;
                        break;
                    }
                    chars_in_substring.insert(s[k]);
                }

                if (is_unique) {
                    max_length = std::max(max_length, j - i + 1);
                }
            }
        }
        return max_length;
    }
};

}  // namespace brute_force_check_all_substrings_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using Solution = brute_force_check_all_substrings_solution::Solution;
#endif
