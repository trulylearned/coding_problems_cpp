#include "solution.h"
#include <iostream>
#include <vector>

// Helper to print a matrix
void print_matrix(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        std::cout << "[]\n";
        return;
    }
    for (const auto& row : matrix) {
        std::cout << "[ ";
        for (int x : row) {
            // Add padding for alignment
            std::cout.width(4);
            std::cout << x << " ";
        }
        std::cout << "]\n";
    }
    std::cout << "---------------------\n";
}

// This is just a simple main to illustrate usage and manual testing.
// It is not needed for the tests to run.
//
// To run tests from the VS Code command palette:
// 1) CMake: Configure
// 2) CMake: Build
// 3) CTest: Run Tests
//
// To run from the terminal (after building):
// 1) cd build
// 2) ctest --output-on-failure

int main() {
    // Solution solution;

    // // Example 1 from the prompt (3x3):
    // std::vector<std::vector<int>> matrix1{
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };

    // std::cout << "Original Matrix 1:\n";
    // print_matrix(matrix1);
    // solution.rotate(matrix1);
    // std::cout << "Rotated Matrix 1:\n";
    // print_matrix(matrix1);
    // // Expected:
    // // [   7    4    1 ]
    // // [   8    5    2 ]
    // // [   9    6    3 ]

    // // Example 2 from prompt (4x4):
    // std::vector<std::vector<int>> matrix2{
    //     { 5,  1,  9, 11},
    //     { 2,  4,  8, 10},
    //     {13,  3,  6,  7},
    //     {15, 14, 12, 16}
    // };
    
    // std::cout << "Original Matrix 2:\n";
    // print_matrix(matrix2);
    // solution.rotate(matrix2);
    // std::cout << "Rotated Matrix 2:\n";
    // print_matrix(matrix2);
    // // Expected:
    // // [  15   13    2    5 ]
    // // [  14    3    4    1 ]
    // // [  12    6    8    9 ]
    // // [  16    7   10   11 ]

    return 0;
}