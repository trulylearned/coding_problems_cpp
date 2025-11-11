#pragma once
#include <string>
#include <array>
#include <numeric>

class Solution {
private:
    static inline int idx(char c)
    {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A';           // 0..25
        }
        return 26 + (c - 'a');        // 26..51
        // return (c <= 'Z') ? (c - 'A') : (26 + c - 'a'); // works for ASCII where uppercase letters come before lowercase ones
    }
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Frequency Counting (Array)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     A small optimization on Approach 2.
    //              Uses a fixed-size array, which is faster
    //              than a hash map when the key set is small and known.
    /////////////////////////////////////////////////////////////////
    int longest_palindrome(std::string s) {
        std::array<int, 52> freq{};
        for (char c : s) {
            ++freq[idx(c)];
        }

        int length = 0;
        bool hasOdd = false;

        for (int i = 0; i < 52; ++i) {
            length += (freq[i] / 2) * 2;
            if (freq[i] % 2 == 1) {
                hasOdd = true;
            }
        }

        return hasOdd ? length + 1 : length;
    }
};