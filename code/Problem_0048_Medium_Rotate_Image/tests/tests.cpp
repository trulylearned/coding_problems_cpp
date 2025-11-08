#include "solution.h"
#include <gtest/gtest.h>
#include <vector>

// Helper function to compare two matrices
static void expect_matrix_eq(
    const std::vector<std::vector<int>>& a,
    const std::vector<std::vector<int>>& b) {
    ASSERT_EQ(a.size(), b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        ASSERT_EQ(a[i].size(), b[i].size());
        for (size_t j = 0; j < a[i].size(); ++j) {
            EXPECT_EQ(a[i][j], b[i][j]) << "Mismatch at (" << i << "," << j << ")";
        }
    }
}

// 1. Example 1 from LeetCode (3x3)
TEST(RotateImage, Example1_3x3) {
    Solution s;
    std::vector<std::vector<int>> m{{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> want{{7,4,1},{8,5,2},{9,6,3}};
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 2. Example 2 from LeetCode (4x4)
TEST(RotateImage, Example2_4x4) {
    Solution s;
    std::vector<std::vector<int>> m{
        {5, 1, 9,11},
        {2, 4, 8,10},
        {13,3, 6, 7},
        {15,14,12,16}
    };
    std::vector<std::vector<int>> want{
        {15,13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7,10,11}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 3. Edge Case: 1x1 matrix (Smallest valid input)
TEST(RotateImage, OneByOne) {
    Solution s;
    std::vector<std::vector<int>> m{{42}};
    std::vector<std::vector<int>> want{{42}};
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 4. Typical Case: 2x2 matrix
TEST(RotateImage, TwoByTwo_Positive) {
    Solution s;
    std::vector<std::vector<int>> m{{1,2},{3,4}};
    std::vector<std::vector<int>> want{{3,1},{4,2}};
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 5. Special Case: Negative numbers
TEST(RotateImage, TwoByTwo_Negatives) {
    Solution s;
    std::vector<std::vector<int>> m{{-1,-2},{-3,-4}};
    std::vector<std::vector<int>> want{{-3,-1},{-4,-2}};
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 6. Special Case: With zeroes
TEST(RotateImage, WithZeroes) {
    Solution s;
    std::vector<std::vector<int>> m{{0,1,0},{2,0,2},{3,0,3}};
    std::vector<std::vector<int>> want{{3,2,0},{0,0,1},{3,2,0}};
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 7. Special Case: All repeated values
TEST(RotateImage, RepeatedValues) {
    Solution s;
    std::vector<std::vector<int>> m{{7,7,7},{7,7,7},{7,7,7}};
    std::vector<std::vector<int>> want{{7,7,7},{7,7,7},{7,7,7}};
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 8. Typical Case: 5x5 sequential numbers
TEST(RotateImage, IncreasingRows_5x5) {
    Solution s;
    std::vector<std::vector<int>> m{
        { 0, 1, 2, 3, 4},
        { 5, 6, 7, 8, 9},
        {10,11,12,13,14},
        {15,16,17,18,19},
        {20,21,22,23,24}
    };
    std::vector<std::vector<int>> want{
        {20,15,10, 5,0},
        {21,16,11, 6,1},
        {22,17,12, 7,2},
        {23,18,13, 8,3},
        {24,19,14, 9,4}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 9. Typical Case: 5x5 odd size, random values
TEST(RotateImage, OddSize_5x5_Random) {
    Solution s;
    std::vector<std::vector<int>> m{
        { 5,  1, -2,  3,  0},
        { 4,  8,  6, -1, 10},
        { 7,  9, 11, 12, 13},
        {-5, -6, -7, -8, -9},
        {99, 98, 97, 96, 95}
    };
    std::vector<std::vector<int>> want{
        {99, -5,  7, 4, 5},
        {98, -6,  9, 8, 1},
        {97, -7, 11, 6,-2},
        {96, -8, 12,-1, 3},
        {95, -9, 13,10, 0}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 10. Typical Case: 6x6 even size, check corners
TEST(RotateImage, EvenSize_6x6_CheckCorners) {
    Solution s;
    std::vector<std::vector<int>> m{
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30},
        {31,32,33,34,35,36}
    };
    // Check just the corners for this large test
    s.rotate(m);
    EXPECT_EQ(m[0][0], 31); // bottom-left -> top-left
    EXPECT_EQ(m[0][5], 1);  // top-left -> top-right
    EXPECT_EQ(m[5][0], 36); // bottom-right -> bottom-left
    EXPECT_EQ(m[5][5], 6);  // top-right -> bottom-right
}

// 11. Property Test: Four rotations return to original
TEST(RotateImage, FourRotationsReturnOriginal_3x3) {
    Solution s;
    std::vector<std::vector<int>> orig{{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> m = orig;
    for (int k = 0; k < 4; ++k) {
        s.rotate(m);
    }
    expect_matrix_eq(m, orig);
}

// 12. Special Case: Identity-like matrix
TEST(RotateImage, IdentityLike) {
    Solution s;
    std::vector<std::vector<int>> m{
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    // Should rotate to the anti-diagonal
    std::vector<std::vector<int>> want{
        {0,0,1},
        {0,1,0},
        {1,0,0}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 13. Special Case: Mix of negative and positive
TEST(RotateImage, NegativesAndPositives) {
    Solution s;
    std::vector<std::vector<int>> m{
        {-1, 2,-3},
        { 4,-5, 6},
        {-7, 8,-9}
    };
    std::vector<std::vector<int>> want{
        {-7, 4,-1},
        { 8,-5, 2},
        {-9, 6,-3}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 14. Constraint Test: Boundary values (-1000, 1000)
TEST(RotateImage, LargeValuesBoundary) {
    Solution s;
    std::vector<std::vector<int>> m{
        {1000, -1000},
        {-1000, 1000}
    };
    std::vector<std::vector<int>> want{
        {-1000, 1000},
        {1000, -1000}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 15. Special Case: Palindromic rows
TEST(RotateImage, PalindromeRows_4x4) {
    Solution s;
    std::vector<std::vector<int>> m{
        {1,2,3,1},
        {4,5,5,4},
        {7,8,8,7},
        {2,3,2,2}
    };
    std::vector<std::vector<int>> want{
        {2,7,4,1},
        {3,8,5,2},
        {2,8,5,3},
        {2,7,4,1}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 16. Special Case: Sparse-like matrix
TEST(RotateImage, SparseLike) {
    Solution s;
    std::vector<std::vector<int>> m{
        {0,0,0,5},
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0}
    };
    std::vector<std::vector<int>> want{
        {1,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,5}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 17. Special Case: Checkerboard (symmetric)
TEST(RotateImage, Checkerboard_5x5) {
    Solution s;
    std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            m[i][j] = ((i + j) % 2 == 0) ? 1 : 0;
        }
    }
    // A 5x5 checkerboard is rotationally symmetric
    std::vector<std::vector<int>> want = m; 
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 18. Typical Case: Another random 3x3
TEST(RotateImage, Random3x3Two) {
    Solution s;
    std::vector<std::vector<int>> m{
        {2, -1, 4},
        {0,  5, 3},
        {-2, 7, 6}
    };
    std::vector<std::vector<int>> want{
        {-2, 0, 2},
        { 7, 5,-1},
        { 6, 3, 4}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 19. Constraint Test: Min/Max values mixed
TEST(RotateImage, MinMaxValuesMixed_3x3) {
    Solution s;
    std::vector<std::vector<int>> m{
        {1000,    0,  500},
        {  50, -1000, -50},
        {-500,    0, 1000}
    };
    std::vector<std::vector<int>> want{
        {-500,   50, 1000},
        {   0, -1000,    0},
        {1000,  -50,  500}
    };
    s.rotate(m);
    expect_matrix_eq(m, want);
}

// 20. Constraint Test: Largest size (n=20)
TEST(RotateImage, LargestSize_20x20_Identity) {
    Solution s;
    int n = 20;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> want(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        m[i][i] = 1;         // Input is identity matrix
        want[i][n - 1 - i] = 1; // Output is anti-diagonal matrix
    }
    s.rotate(m);
    expect_matrix_eq(m, want);
}