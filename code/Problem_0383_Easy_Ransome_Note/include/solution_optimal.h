#pragma once
#include <string>
#include <vector>
#include <array> // A more modern C++23 alternative to the vector

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Frequency counting with an array
    // Time Cmplx:  O(N + M)
    // Space Cmplx: O(1)
    // Remarks:     Extremely
    //              efficient and the optimal approach.
    /////////////////////////////////////////////////////////////////
    bool canConstruct(std::string ransom_note, std::string magazine) {
        // We can use std::vector or std::array. An array is slightly
        // more performant as it's a fixed-size stack allocation.
        std::array<int, 26> freq{}; // Initialize all 26 counts to 0
        
        // 1. Count all letters in the magazine
        for (char mag_char : magazine) {
            freq[mag_char - 'a']++;
        }
        
        // 2. Check and "use" letters for the ransom note
        for (char note_char : ransom_note) {
            // The expression (note_char - 'a') gives the index (0-25)
            // We pre-decrement (--), which means we "use" the letter
            // first, and *then* check the new value.
            if (--freq[note_char - 'a'] < 0) {
                // If the new value is negative, it means we needed
                // a letter we didn't have (the count was 0).
                return false;
            }
        }
        
        // We got through the whole note without any count going negative.
        return true;
    }
};