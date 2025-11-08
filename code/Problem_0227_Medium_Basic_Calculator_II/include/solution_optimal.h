#pragma once
#include <string>
#include <stack>
#include <cctype>
#include <numeric>

using namespace std;

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Optimized one-pass calculator
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Truly optimal. Uses a clever trick to
    //              track the "last" value for precedence.
    /////////////////////////////////////////////////////////////////
    int calculate(string s) {
        long num = 0;
        long result = 0;
        long last_num = 0; // The last number we evaluated
        char op = '+';

        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && !isspace(c)) || i == s.size() - 1) {
                if (op == '+') {
                    result += num;
                    last_num = num;
                } else if (op == '-') {
                    result -= num;
                    last_num = -num;
                } else if (op == '*') {
                    // 1. Undo the previous operation (which was adding last_num)
                    result -= last_num;
                    // 2. Perform the high-precedence operation
                    long new_last_num = last_num * num;
                    // 3. Add the new value to the result
                    result += new_last_num;
                    // 4. Update last_num for the *next* potential *, /
                    last_num = new_last_num;
                } else if (op == '/') {
                    result -= last_num;
                    long new_last_num = last_num / num;
                    result += new_last_num;
                    last_num = new_last_num;
                }
                op = c;
                num = 0;
            }
        }
        // We don't need a final sum, 'result' has been accumulating
        // the answer all along.
        return (int)result;
    }

    // You can uncomment this to test the stack-based solution
    // int calculate(string s) {
    //     return calculate_stack(s);
    // }
};