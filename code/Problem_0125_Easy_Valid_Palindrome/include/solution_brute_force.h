#pragma once
#include <string>
#include <cctype>
#include <algorithm>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force by cleaning and reversing
    // Time Cmplx:  O(N)
    // Space Cmplx: O(N)
    // Remarks:     Straightforward and readable. Uses extra memory
    //              to build the filtered and reversed strings.
    /////////////////////////////////////////////////////////////////
    bool is_palindrome(std::string s) {
        std::string filtered_string;
        // Pre-allocating memory can be a nice, minor optimization
        // to avoid multiple reallocations as the string grows.
        filtered_string.reserve(s.size());

        for (char c : s) {
            if (std::isalnum(static_cast<unsigned char>(c))) {
                filtered_string.push_back(std::tolower(static_cast<unsigned char>(c)));
            }
        }

        // Now, check if the new string is a palindrome
        std::string reversed_string = filtered_string;
        std::reverse(reversed_string.begin(), reversed_string.end());
        
        return filtered_string == reversed_string;
    }
};