#include "solution.h" // Or "solution.h"
#include <iostream>
#include <vector>
#include <string>

// To build and run with this main:
// 1. Make sure your solution is in "solution.h" or "solution.h"
// 2. Compile: g++ -std=c++23 -o main main.cpp
// 3. Run: ./main
//
// To run tests (if you have GoogleTest setup):
// 1) CMake: Configure
// 2) CMake: Build
// 3) CTest: Run Tests
// or from terminal: ctest --output-on-failure

void print_groups(const std::vector<std::vector<std::string>>& groups) {
    std::cout << "Found " << groups.size() << " groups:\n";
    for (const auto& group : groups) {
        std::cout << "[ ";
        for (const auto& word : group) {
            std::cout << "\"" << word << "\" ";
        }
        std::cout << "]\n";
    }
}

int main() {
    // Solution solution;

    // // --- Example 1 ---
    // std::vector<std::string> strs1 = {"eat","tea","tan","ate","nat","bat"};
    // std::cout << "--- Running Example 1 --- \n";
    // auto groups1 = solution.groupAnagrams(strs1);
    // print_groups(groups1);
    
    /*
    // --- Example 2 ---
    std::vector<std::string> strs2 = {"abc", "bca", "xyz", "zyx"};
    std::cout << "\n--- Running Example 2 --- \n";
    auto groups2 = solution.groupAnagrams(strs2);
    print_groups(groups2);

    // --- Example 3 (Edge Case) ---
    std::vector<std::string> strs3 = {"", "a", ""};
    std::cout << "\n--- Running Example 3 --- \n";
    auto groups3 = solution.groupAnagrams(strs3);
    print_groups(groups3);
    */

    return 0;
}