#pragma once
#include <string>
#include <stack>
#include <cctype>
#include <numeric> // For std::accumulate

using namespace std;

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Stack-based one-pass calculator
    // Time Cmplx:  O(N)
    // Space Cmplx: O(N)
    // Remarks:     Good, intuitive solution that correctly
    //              handles operator precedence.
    /////////////////////////////////////////////////////////////////
    int calculate_stack(string s) {
        stack<int> st;
        long num = 0;
        char op = '+';

        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            // Process the previous (num, op) pair when we hit
            // a new operator OR the end of the string.
            if ((!isdigit(c) && !isspace(c)) || i == s.size() - 1) {
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
    int calculate(string s) {
        return calculate_stack(s);
    }
};