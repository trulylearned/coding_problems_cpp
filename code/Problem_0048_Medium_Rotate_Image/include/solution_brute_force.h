#pragma once
// IMPORTANT: Include all necessary modules for this specific solution here.
#include <vector>
#include <utility>

class Solution {
private:
    // No helpers needed for this baseline.
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-force using an auxiliary n x n matrix
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(N^2)  // NOT ALLOWED, for learning only
    // Remarks:     Easiest to reason about the coordinate mapping.
    /////////////////////////////////////////////////////////////////
    void rotate(std::vector<std::vector<int>>& matrix) {
        const int n = static_cast<int>(matrix.size());
        if (n == 0) {
            return;
        }
        
        // 1. Create an auxiliary matrix (violates O(1) space)
        std::vector<std::vector<int>> rot(n, std::vector<int>(n));

        // 2. Place elements in their new, rotated positions
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // matrix[n - 1 - j][i] is the source for new (i, j)
                rot[i][j] = matrix[n - 1 - j][i];
            }
        }

        // 3. Copy the rotated matrix back to the original
        //    (This step is also part of the disallowed approach)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = rot[i][j];
            }
        }
    }
};