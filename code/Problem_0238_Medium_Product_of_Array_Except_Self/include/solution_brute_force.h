#pragma once
#include <vector>
#include <numeric> // Not used here, but good to include for numeric ops

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-force (two nested loops, no division)
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1) extra (excluding output)
    // Remarks:     Straightforward baseline. Will Time Limit Exceed.
    /////////////////////////////////////////////////////////////////
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> ans(n); // No need to init to 1 here

        for (int i = 0; i < n; ++i) {
            // Use long long for intermediate product for safety,
            // though constraint guarantees final answer fits in int.
            long long prod = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                prod *= nums[j];
            }
            ans[i] = static_cast<int>(prod);
        }
        return ans;
    }
};