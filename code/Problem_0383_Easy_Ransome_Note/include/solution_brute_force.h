#pragma once
#include <string>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-force character search
    // Time Cmplx:  O(N * M)
    // Space Cmplx: O(M)
    // Remarks:     Simple to understand but will time out (TLE)
    //              on large inputs due to O(N*M) complexity.
    ////////////////////////////////As////////////////////////////////
    bool canConstruct(std::string ransom_note, std::string magazine) {
        // Note: 'magazine' is a copy because it's passed by value.
        // We are free to modify it without affecting the caller.
        
        for (char note_char : ransom_note) {
            // Find the first occurrence of the character we need
            size_t pos = magazine.find(note_char);
            
            if (pos == std::string::npos) {
                // Not found. We can't build the note.
                return false; 
            }
            
            // Found it. Erase it so we can't use it again.
            magazine.erase(pos, 1);
        }
        
        // If we finished the loop, we found every character.
        return true;
    }
};