#pragma once
#include <vector>
#include <numeric>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Prefix products + running suffix multiplier
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1) extra (excluding output)
    // Remarks:     Standard optimal approach; handles zeros naturally.
    /////////////////////////////////////////////////////////////////
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        // Initialize the answer array with 1s
        std::vector<int> ans(n, 1);

        // === Prefix Pass ===
        // ans[i] will contain the product of all elements to the left of i
        // ans[0] remains 1 because there are no elements to its left.
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // === Suffix Pass ===
        // We use a single variable to store the running product of suffixes
        int suffix_product = 1;
        // Iterate from right-to-left
        for (int i = n - 1; i >= 0; --i) {
            // 1. Multiply the current (left) product by the suffix product
            ans[i] *= suffix_product;
            // 2. Update the suffix product for the next (left) element
            suffix_product *= nums[i];
        }

        return ans;
    }
};