#include "solution.h" // Assumes solution is in solution.h
#include <gtest/gtest.h>
#include <vector>

// Helper to create an empty board
std::vector<std::vector<char>> get_empty_board() {
    return std::vector<std::vector<char>>(9, std::vector<char>(9, '.'));
}

// 1. Example 1 from LeetCode (Valid)
TEST(ValidSudoku, Example1) {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    EXPECT_TRUE(s.is_valid_sudoku(board));
}

// 2. Example 2 from LeetCode (Invalid, Col Conflict)
TEST(ValidSudoku, Example2) {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 3. Edge Case: Empty Board
TEST(ValidSudoku, EmptyBoard) {
    Solution s;
    auto board = get_empty_board();
    EXPECT_TRUE(s.is_valid_sudoku(board));
}

// 4. Basic Case: Single Row Conflict
TEST(ValidSudoku, SingleRowConflict) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '1';
    board[0][8] = '1';
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 5. Basic Case: Single Column Conflict
TEST(ValidSudoku, SingleColumnConflict) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '2';
    board[8][0] = '2';
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 6. Basic Case: Sub-Box Conflict
TEST(ValidSudoku, SubBoxConflict) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '3';
    board[1][1] = '3'; // Same 3x3 box
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 7. Typical Case: Valid Partial Board
TEST(ValidSudoku, ValidPartial) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '9';
    board[4][4] = '8';
    board[8][8] = '7';
    EXPECT_TRUE(s.is_valid_sudoku(board));
}

// 8. Typical Case: Valid Edge Digits
TEST(ValidSudoku, EdgeDigits) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '1';
    board[0][1] = '9';
    EXPECT_TRUE(s.is_valid_sudoku(board));
}

// 9. Special Case: A fully valid board
TEST(ValidSudoku, FullValidBoard) {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };
    EXPECT_TRUE(s.is_valid_sudoku(board));
}

// 10. Special Case: Full board, one row conflict
TEST(ValidSudoku, FullBoardRowConflict) {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'5','3','4','6','7','8','9','1','5'}, // 5 is duplicated
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 11. Special Case: Full board, one col conflict
TEST(ValidSudoku, FullBoardColConflict) {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'5','4','5','2','8','6','1','7','9'} // 5 conflicts with board[0][0]
    };
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 12. Special Case: Full board, one box conflict
TEST(ValidSudoku, FullBoardBoxConflict) {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','1'} // 1 conflicts with board[6][8]
    };
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 13. Box Conflict: Corners of box 0
TEST(ValidSudoku, BoxConflictCorners) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '8';
    board[2][2] = '8';
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 14. Box Conflict: Same row in box 0
TEST(ValidSudoku, BoxConflictSameRow) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '8';
    board[0][2] = '8';
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 15. Box Conflict: Same col in box 0
TEST(ValidSudoku, BoxConflictSameCol) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '8';
    board[2][0] = '8';
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 16. Special Case: All '1's in a row
TEST(ValidSudoku, AllOnesInRow) {
    Solution s;
    auto board = get_empty_board();
    for(int j = 0; j < 9; ++j) {
        board[0][j] = '1';
    }
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 17. Special Case: All '2's in a col
TEST(ValidSudoku, AllTwosInCol) {
    Solution s;
    auto board = get_empty_board();
    for(int i = 0; i < 9; ++i) {
        board[i][0] = '2';
    }
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 18. Special Case: All '3's in a box
TEST(ValidSudoku, AllThreesInBox) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '3'; board[0][1] = '3'; board[0][2] = '3';
    board[1][0] = '3'; board[1][1] = '3'; board[1][2] = '3';
    board[2][0] = '3'; board[2][1] = '3'; board[2][2] = '3';
    EXPECT_FALSE(s.is_valid_sudoku(board));
}

// 19. Valid: No conflict between different boxes
// (This test was flawed and is now corrected)
TEST(ValidSudoku, NoConflictBetweenBoxes) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '1'; // Box 0
    board[1][3] = '1'; // Box 1 (different row/col)
    board[3][1] = '1'; // Box 3 (different row/col)
    EXPECT_TRUE(s.is_valid_sudoku(board));
}

// 20. Valid: Only '1's, but all valid
TEST(ValidSudoku, ValidOnes) {
    Solution s;
    auto board = get_empty_board();
    board[0][0] = '1';
    board[1][3] = '1';
    board[2][6] = '1';
    board[3][1] = '1';
    board[4][4] = '1';
    board[5][7] = '1';
    board[6][2] = '1';
    board[7][5] = '1';
    board[8][8] = '1';
    EXPECT_TRUE(s.is_valid_sudoku(board));
}