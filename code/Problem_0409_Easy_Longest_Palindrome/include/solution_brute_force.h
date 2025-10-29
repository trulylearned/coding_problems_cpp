#pragma once
#include <string>
#include <unordered_map>
#include <algorithm> // For std::max
#include <vector>    // Included for recursion, though not in final class

class Solution {
private:
    /**
     * @brief Helper function to check if a string's letters
     * can be rearranged into a palindrome.
     * @param sub The string subsequence to check.
     * @return true if it can form a palindrome, false otherwise.
     */
    bool can_form_palindrome(const std::string& sub) {
        if (sub.empty()) {
            return true;
        }
        
        std::unordered_map<char, int> freq;
        for (char ch : sub) {
            ++freq[ch];
        }

        int odd_count = 0;
        for (auto& [character, count] : freq) {
            if (count % 2 != 0) {
                ++odd_count;
            }
        }
        // A string can form a palindrome if at most
        // one of its characters has an odd frequency.
        return odd_count <= 1;
    }

    /**
     * @brief Recursive helper to generate all subsequences
     * and check them.
     * @param s The original input string.
     * @param index The current character we are considering.
     * @param current_sub The subsequence built so far.
     * @param max_len Reference to the longest valid palindrome length found.
     */
    void find_max_palindrome_subsequence(const std::string& s, 
                                          int index, 
                                          std::string current_sub, 
                                          int& max_len) {
        
        // Base Case: We've considered all characters
        if (index == s.length()) {
            // Check if the subsequence we just built
            // can be turned into a palindrome.
            if (can_form_palindrome(current_sub)) {
                max_len = std::max(max_len, (int)current_sub.length());
            }
            return;
        }

        // --- Recursive Step ---

        // Case 1: Don't include s[index] in the subsequence
        find_max_palindrome_subsequence(s, index + 1, current_sub, max_len);

        // Case 2: Include s[index] in the subsequence
        current_sub.push_back(s[index]);
        find_max_palindrome_subsequence(s, index + 1, current_sub, max_len);
    }

public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force (All Subsequences Check)
    // Time Cmplx:  O(2^N * N)
    // Space Cmplx: O(N)
    // Remarks:     This is the *correct* brute-force logic,
    //              but it is far too slow and will TLE.
    /////////////////////////////////////////////////////////////////
    int longest_palindrome(std::string s) {
        int max_len = 0;
        std::string current_sub = "";
        
        // Start the recursive process
        find_max_palindrome_subsequence(s, 0, current_sub, max_len);
        
        return max_len;
    }
};