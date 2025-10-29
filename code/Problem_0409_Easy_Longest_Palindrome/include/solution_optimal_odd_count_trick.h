#pragma once
#include <string>
#include <unordered_set>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Odd Count Set Trick
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1) (or O(K))
    // Remarks:     A clever and concise one-pass solution.
    //              The set ends up holding all chars with
    //              odd frequencies.
    /////////////////////////////////////////////////////////////////
    int longest_palindrome(std::string s) {
        // This set will store all characters that
        // have appeared an odd number of times.
        std::unordered_set<char> odd_chars;

        for (char ch : s) {
            // contains() is C++20
            if (odd_chars.contains(ch)) {
                // We've seen this char an even # of times now.
                odd_chars.erase(ch);
            } else {
                // We've seen this char an odd # of times.
                odd_chars.insert(ch);
            }
        }

        // The size of the set is our total odd_count
        int odd_count = odd_chars.size();

        if (odd_count > 0) {
            // We lose one char for each odd group, but gain one back
            // for the center.
            return s.length() - odd_count + 1;
        } else {
            // All counts were even, so we can use the whole string.
            return s.length();
        }
    }
};