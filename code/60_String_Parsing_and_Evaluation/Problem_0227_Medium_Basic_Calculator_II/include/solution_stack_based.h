#pragma once

#include <string>
#include <stack>
#include <cctype>
#include <numeric> // For std::accumulate

namespace stack_based_solution {

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Stack-based one-pass calculator
    // Time Cmplx:  O(N)
    // Space Cmplx: O(N)
    // Remarks:     Good, intuitive solution that correctly
    //              handles operator precedence.
    /////////////////////////////////////////////////////////////////
    int calculate_stack(std::string s) {
        std::stack<int> st;
        long num = 0;
        char op = '+';

        for (std::size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            // Process the previous (num, op) pair when we hit
            // a new operator OR the end of the std::string.
            if ((!std::isdigit(c) && !std::isspace(c)) || i == s.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int top = st.top(); 
                    st.pop();
                    st.push(top * num);
                } else if (op == '/') {
                    int top = st.top(); 
                    st.pop();
                    st.push(top / num);
                }
                // Update op and reset num for the next operand
                op = c;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
    
    // Helper to call the method we want to test
    int calculate(std::string s) {
        return calculate_stack(s);
    }
};

}  // namespace stack_based_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using Solution = stack_based_solution::Solution;
#endif
