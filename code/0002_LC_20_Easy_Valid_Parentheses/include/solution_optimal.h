#pragma once
#include <string>
#include <stack>

class Solution {
private:
    constexpr char matching_bracket(char c) {
        switch (c)
        {
            case '(': return ')';
            case '[': return ']';
            case '{': return '}';
            default:  return '\0';
        }
    };

public:
    /////////////////////////////////////////////////////////////////
    // Method:      Stack-Based Parentheses Validation
    // Time Cmplx:  O(N)
    // Space Cmplx: O(N)
    // Remarks:     Efficient, elegant, and the standard industry
    //              solution. This is the expected approach in an interview.
    /////////////////////////////////////////////////////////////////
    bool isValid(const std::string& s) {
        std::stack<char> open_brackets;

        for (const char current_char : s) {
            // Check if it's an OPENING bracket by checking if it's a key in the map
            if (matching_bracket(current_char)) {   // C++23 feature, alternative to count()
                open_brackets.push(current_char);
            } else {
                // It's a CLOSING bracket
                if (open_brackets.empty()) {
                    return false; // Closing bracket with no matching opener
                }
                
                const char last_opener {open_brackets.top()};
                // Check if the current closer matches the expected closer for the last opener
                if (matching_bracket(last_opener) != current_char) {
                    return false; // Mismatch
                }
                
                open_brackets.pop(); // Match, pop the opener
            }
        }
        
        // At the end, a valid string will have an empty stack
        return open_brackets.empty();
    }
};