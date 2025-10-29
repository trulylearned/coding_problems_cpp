#pragma once
#include <string>
#include <algorithm> // for std::sort

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Sort and Compare
    // Time Cmplx:  O(N log N)
    // Space Cmplx: O(N)
    // Remarks:     Simple and intuitive. Not the fastest, but easy
    //              to reason about.
    /////////////////////////////////////////////////////////////////
    bool is_anagram(std::string s, std::string t) {
        // 1. Check length
        if (s.size() != t.size()) {
            return false;
        }

        // 2. Sort both strings
        // We sort the copies 's' and 't' that were
        // passed by value.
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        // 3. Compare
        return s == t;
    }
};