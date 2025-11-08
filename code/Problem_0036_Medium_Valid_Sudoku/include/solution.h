#pragma once
#include <vector>
#include <array> // For std::array

class Solution {
private:
    static constexpr int n_size = 9;

public:
    /////////////////////////////////////////////////////////////////
    // Method:      One-pass validation using hash grids
    // Time Complexity:  O(N^2) [or O(1) since N=9]
    // Space Complexity: O(N^2) [or O(1) since N=9]
    // Remarks:     Elegant, efficient, and the standard optimal
    //              approach. Uses a clever box-indexing trick.
    /////////////////////////////////////////////////////////////////
    bool is_valid_sudoku(std::vector<std::vector<char>>& board) {
        // We use std::array for fixed-size, stack-allocated arrays.
        // rows[i][num] is true if row 'i' has number 'num+1'
        std::array<std::array<bool, n_size>, n_size> rows{}; // {} initializes all to false
        // cols[j][num] is true if col 'j' has number 'num+1'
        std::array<std::array<bool, n_size>, n_size> cols{};
        // boxes[k][num] is true if box 'k' has number 'num+1'
        std::array<std::array<bool, n_size>, n_size> boxes{};

        for (int i = 0; i < n_size; ++i) {
            for (int j = 0; j < n_size; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                
                // Map char '1'..'9' to index 0..8
                int num_index = c - '1'; 
                
                // Calculate the box index (0-8)
                int box_index = (i / 3) * 3 + (j / 3);

                // Check if this number has been seen in its row, col, or box
                if (rows[i][num_index] || cols[j][num_index] || boxes[box_index][num_index]) {
                    return false; // Found a duplicate
                }

                // Mark this number as seen for this row, col, and box
                rows[i][num_index] = true;
                cols[j][num_index] = true;
                boxes[box_index][num_index] = true;
            }
        }
        
        return true;
    }
};