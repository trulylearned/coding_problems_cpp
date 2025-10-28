#pragma once
#include <vector>
#include <algorithm>
#include <limits> // Required for std::numeric_limits

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Single Pass Min-Tracking (Optimal)
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     This is the efficient, standard interview solution.
    /////////////////////////////////////////////////////////////////
    int maxProfit(std::vector<int>& prices) {
        // Initialize min_price to the largest possible int value
        // This robustly handles all cases, including single-element
        // or empty lists (though constraints say list is non-empty).
        int min_price_so_far {std::numeric_limits<int>::max()};
        int max_profit_so_far {};

        for (const int current_price : prices) {
            // 1. Is this a new lowest price to buy at?
            min_price_so_far = std::min(min_price_so_far, current_price);
            
            // 2. What's our profit if we bought at the minimum and sell today?
            const int potential_profit = {current_price - min_price_so_far};
            
            // 3. Is this the best profit we've seen?
            max_profit_so_far = std::max(max_profit_so_far, potential_profit);
        }
        
        return max_profit_so_far;
    }
};