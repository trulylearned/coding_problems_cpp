#pragma once
#include <vector>
#include <algorithm>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force using nested loops
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Simple to understand, but too slow for the
    //              given constraints. It will time out.
    /////////////////////////////////////////////////////////////////
    int maxProfit(std::vector<int>& prices) {
        int size {static_cast<int>(prices.size())};
        int max_profit {};

        for (int i {}; i < size; ++i) { // i = buy_day
            for (int j = i + 1; j < size; ++j) { // j = sell_day
                const int profit = {prices[j] - prices[i]};
                // We only care about positive profit
                if (profit > max_profit) {
                    max_profit = profit;
                }
            }
        }
        return max_profit;
    }
};