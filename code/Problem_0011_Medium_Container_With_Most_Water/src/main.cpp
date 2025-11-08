#include "solution.h"
#include <iostream>
#include <vector>

// This is just a simple main to illustrate usage and manual testing and debugging.
// It is not needed beyond manual debugging, that's why the code is commented out.
// To run tests do execute the following from the VS code command palette:
// 1) CMake: Configure
// 2) CMake: Build
// 3) CTest: Run Tests
// After building you can also run tests from the terminal. 
// You have to be in the build directory and then run ctest --output-on-failure
// Alternatively you can run ctest and point it to the folder with the tests:
// For example if you are in the root folder of the project you can run tests
// by executing: ctest --test-dir build --output-on-failure
// FYI. To see the Command Palette in VS code you can use the shortcut: 
// Shift+Cmd+P (on Mac) or Shift+Ctrl+P (on Windows).

int main() {
    // Create an instance of the Solution class
    // Solution s;
    
    // Example 1 from LeetCode
    // std::vector<int> height{1,8,6,2,5,4,8,3,7};
    // int result = s.maxArea(height);
    // std::cout << "Max water area for Example 1: " << result << std::endl; // Expected: 49

    // Example 2 from LeetCode
    // std::vector<int> height2{1,1};
    // int result2 = s.maxArea(height2);
    // std::cout << "Max water area for Example 2: " << result2 << std::endl; // Expected: 1

    // Custom Example from this lesson
    // std::vector<int> height3{2,3,4,5,18,17,6};
    // int result3 = s.maxArea(height3);
    // std::cout << "Max water area for Custom Example 1: " << result3 << std::endl; // Expected: 17

    return 0;
}