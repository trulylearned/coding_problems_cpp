#pragma once
#include <vector>
#include <algorithm>
#include <set> // Using a set to handle duplicate triplets easily

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force using Triple Nested Loops
    // Time Cmplx:  O(N^3)
    // Space Cmplx: O(K)
    // Remarks:     Will Time Limit Exceeded (TLE).
    //              Demonstrates the core logic but is too slow.
    /////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (n < 3) {
            return {};
        }

        // A set will automatically handle duplicate triplets.
        // We sort the input nums to make duplicate triplets
        // identical (e.g., [1, -1, 0] and [0, -1, 1] both
        // become [-1, 0, 1] after the inner sort).
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> result_set;

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        // No need to sort the triplet {i, j, k}
                        // because the main array `nums` is already sorted.
                        result_set.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        // Convert the set back to a vector for the return type
        return std::vector<std::vector<int>>(result_set.begin(), result_set.end());
    }
};