#include "solution.h" // Contains the Solution class
#include <iostream>
#include <vector>

// To run this main function for manual testing:
// 1. Make sure "solution.h" is in the same directory.
// 2. Uncomment the code inside main().
// 3. Compile and run:
//    g++ main.cpp -o main_runner -std=c++23
//    ./main_runner

// To run the automated tests (recommended):
// Use the "Run CTest" button in VS Code, or run from terminal:
// cmake: Configure -> Build -> CTest: Run Tests

int main() {
    /*
    // --- Example of how to manually test your solution ---
    
    Solution solution;

    // Test with Example 1
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    std::cout << "Input: [-1, 0, 1, 2, -1, -4]\n";
    auto result = solution.threeSum(nums);

    std::cout << "Triplets summing to zero:\n";
    if (result.empty()) {
        std::cout << "(No triplets found)\n";
    } else {
        for (const auto& triplet : result) {
            std::cout << "[";
            for (size_t i = 0; i < triplet.size(); ++i) {
                std::cout << triplet[i];
                if (i + 1 < triplet.size()) {
                    std::cout << ", ";
                }
            }
            std::cout << "]\n";
        }
    }
    
    // Expected output for this example:
    // (Order of triplets and numbers may vary)
    // [-1, -1, 2]
    // [-1, 0, 1]
    */

    std::cout << "Main function complete. Uncomment code to run manual tests.\n";
    std::cout << "Otherwise, please run the GoogleTests.\n";

    return 0;
}