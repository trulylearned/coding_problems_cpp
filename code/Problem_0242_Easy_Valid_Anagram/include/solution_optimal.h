#pragma once
#include <string>
#include <array>     // Using std::array for a fixed-size counter

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Frequency Counting (Array as Hash Map)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Optimal solution. Blazingly fast and efficient.
    /////////////////////////////////////////////////////////////////
    // We pass by const reference (const std::string&) to avoid
    // making O(N) copies of the strings. This is how we
    // achieve true O(1) space complexity.
    bool is_anagram(const std::string& s, const std::string& t) {
        if (s.size() != t.size()) {
            return false;
        }

        // Use std::array for a fixed-size, stack-allocated counter.
        // Initialize all 26 counts to zero.
        std::array<int, 26> counts{};

        // Increment counts for string s
        for (const char c : s) {
            counts[c - 'a']++;
        }

        // Decrement counts for string t
        for (const char c : t) {
            counts[c - 'a']--;
            
            // Early exit optimization:
            // If a count ever goes below zero, it means t has a 
            // character that s doesn't (or has more of them).
            // We can stop and return false immediately.
            if (counts[c - 'a'] < 0) {
                return false;
            }
        }

        // If we finished the second loop without any count
        // going negative, and since s.size() == t.size(),
        // we know it *must* be an anagram.
        return true;
    }
};