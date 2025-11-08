#include "solution.h"
#include <iostream>
#include <vector>

// This is just a simple main to illustrate usage and manual testing and debugging.
// It is not needed beyond manual debugging, that's why the code is commented out.
//
// To run tests do execute the following from the VS code command palette:
// 1) CMake: Configure
// 2) CMake: Build
// 3) CTest: Run Tests
//
// After building you can also run tests from the terminal. 
// You have to be in the 'build' directory and then run 'ctest --output-on-failure'
//
// Alternatively you can run ctest and point it to the folder with the tests:
// For example if you are in the root folder of the project you can run tests
// by executing: 'ctest --test-dir build --output-on-failure'
//
// FYI. To see the Command Palette in VS code you can use the shortcut: 
// Shift+Cmd+P (on Mac) or Shift+Ctrl+P (on Windows).

int main() {
    // --- Manual Test ---
    // 1. Create an instance of the Solution class.
    // Solution solution;
    
    // 2. Define your input vector.
    // std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    
    // 3. Call the function.
    // int result = solution.findMin(nums);
    
    // 4. Print the result.
    // std::cout << "Minimum element: " << result << std::endl; // Expected: 0

    // --- Another Test ---
    // std::vector<int> nums2 = {3, 4, 5, 1, 2};
    // int result2 = solution.findMin(nums2);
    // std::cout << "Minimum element: " << result2 << std::endl; // Expected: 1
    
    return 0;
}