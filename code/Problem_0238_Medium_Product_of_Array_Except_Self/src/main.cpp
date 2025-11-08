#include "solution.h"
#include <iostream>
#include <vector>

// Helper function to print a vector
void printVector(const std::string& title, const std::vector<int>& vec) {
    std::cout << title;
    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}

int main() {
    // Solution solution;
    //
    // // Example 1
    // std::vector<int> nums_example_1{1, 2, 3, 4};
    // printVector("Input 1:  ", nums_example_1);
    // std::vector<int> result_1 = solution.productExceptSelf(nums_example_1);
    // printVector("Output 1: ", result_1); // Expected: 24 12 8 6
    //
    // std::cout << "---" << std::endl;
    //
    // // Example 2 (with zero)
    // std::vector<int> nums_example_2{-1, 1, 0, -3, 3};
    // printVector("Input 2:  ", nums_example_2);
    // std::vector<int> result_2 = solution.productExceptSelf(nums_example_2);
    // printVector("Output 2: ", result_2); // Expected: 0 0 9 0 0

    return 0;
}