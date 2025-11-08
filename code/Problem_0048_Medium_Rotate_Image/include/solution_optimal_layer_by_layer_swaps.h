#pragma once
// IMPORTANT: Include all necessary modules for this specific solution here.
#include <vector>
#include <utility> // For std::swap

class Solution {
private:
    // No extra helpers required; we'll do direct 4-way swaps by layer.
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Layer-by-layer 4-way cyclic swaps
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Clear control over swaps; good for interviews.
    /////////////////////////////////////////////////////////////////
    void rotate(std::vector<std::vector<int>>& matrix) {
        const int n = static_cast<int>(matrix.size());
        
        // Iterate through the "layers" of the matrix, from outside in
        // We only need to go to n/2 because the inner layers meet at the center
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer;          // The first row/col index of this layer
            int last = n - 1 - layer; // The last row/col index of this layer

            // Iterate through the elements on one side of the layer
            // We go from 'first' to 'last-1' (i.e., 'i' from 0 to 'last - first - 1')
            for (int i = 0; i < (last - first); ++i) {
                // These are the 4 elements in the cycle
                // (r, c)
                int r_top = first;
                int c_top = first + i;

                // (c, n-1-r)
                int r_right = first + i;
                int c_right = last;

                // (n-1-r, n-1-c)
                int r_bottom = last;
                int c_bottom = last - i;

                // (n-1-c, r)
                int r_left = last - i;
                int c_left = first;

                // Save top
                int top_val = matrix[r_top][c_top];

                // left -> top
                matrix[r_top][c_top] = matrix[r_left][c_left];

                // bottom -> left
                matrix[r_left][c_left] = matrix[r_bottom][c_bottom];

                // right -> bottom
                matrix[r_bottom][c_bottom] = matrix[r_right][c_right];

                // top -> right
                matrix[r_right][c_right] = top_val;
            }
        }
    }
};