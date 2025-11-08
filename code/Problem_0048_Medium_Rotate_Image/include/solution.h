#pragma once
// IMPORTANT: Include all necessary modules for this specific solution here.
#include <vector>
#include <algorithm> // For std::reverse
#include <utility>   // For std::swap

class Solution {
private:
    // Helper: in-place transpose of a square matrix.
    static void transpose(std::vector<std::vector<int>>& a) {
        const int n = static_cast<int>(a.size());
        for (int i = 0; i < n; ++i) {
            // We only loop j from i + 1 to avoid double-swapping
            for (int j = i + 1; j < n; ++j) {
                std::swap(a[i][j], a[j][i]);
            }
        }
    }

public:
    /////////////////////////////////////////////////////////////////
    // Method:      In-place transpose then reverse each row
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Idiomatic, short, and very reliable.
    /////////////////////////////////////////////////////////////////
    void rotate(std::vector<std::vector<int>>& matrix) {
        // Step 1: Transpose the matrix in-place
        transpose(matrix);
        
        const int n = static_cast<int>(matrix.size());
        
        // Step 2: Reverse each row in-place
        for (int i = 0; i < n; ++i) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};