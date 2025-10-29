#pragma once
#include <string>
#include <cctype>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Two-Pointer Palindrome Check
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Optimal memory usage. This is a very common
    //              and expected interview pattern for this problem.
    /////////////////////////////////////////////////////////////////
    bool is_palindrome(std::string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
                ++left;
            }
            
            // Move right pointer to the previous alphanumeric character
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
                --right;
            }

            // Now, compare the two alphanumeric characters
            if (std::tolower(static_cast<unsigned char>(s[left])) != 
                std::tolower(static_cast<unsigned char>(s[right]))) {
                // If they don't match, it's not a palindrome
                return false;
            }

            // If they match, move pointers inward and continue
            ++left;
            --right;
        }

        // If the loop completes, the string is a palindrome
        return true;
    }
};