#pragma once
#include <vector>
#include <unordered_set>

class Solution {
private:
    // Using static constexpr for a compile-time constant is good practice.
    static constexpr int n_size = 9;

public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-force validation using sets
    // Time Complexity:  O(N^2) [or O(1) since N=9]
    // Space Complexity: O(N)   [or O(1) since N=9]
    // Remarks:     Clear and easy to understand. It's repetitive
    //              but directly models the problem's rules.
    /////////////////////////////////////////////////////////////////
    bool is_valid_sudoku(std::vector<std::vector<char>>& board) {
        // 1. Check each row
        for (int i = 0; i < n_size; ++i) {
            std::unordered_set<char> row_seen;
            for (int j = 0; j < n_size; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                if (row_seen.count(c)) return false; // Found duplicate
                row_seen.insert(c);
            }
        }

        // 2. Check each column
        for (int j = 0; j < n_size; ++j) {
            std::unordered_set<char> col_seen;
            for (int i = 0; i < n_size; ++i) {
                char c = board[i][j];
                if (c == '.') continue;
                if (col_seen.count(c)) return false; // Found duplicate
                col_seen.insert(c);
            }
        }

        // 3. Check each 3x3 sub-box
        for (int box_row = 0; box_row < 3; ++box_row) {
            for (int box_col = 0; box_col < 3; ++box_col) {
                std::unordered_set<char> box_seen;
                // Iterate 3x3 cells within this box
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        // Calculate the actual board coordinates
                        int r = box_row * 3 + i;
                        int c = box_col * 3 + j;
                        char val = board[r][c];
                        
                        if (val == '.') continue;
                        if (box_seen.count(val)) return false; // Found duplicate
                        box_seen.insert(val);
                    }
                }
            }
        }
        
        // If all checks passed
        return true;
    }
};