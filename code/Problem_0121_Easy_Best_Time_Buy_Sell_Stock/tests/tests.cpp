#include "solution.h" // Assumes solution.h contains one of the Solution classes
#include <gtest/gtest.h>
#include <vector>

// 1. Example from LeetCode
TEST(BestTimeToBuyAndSellStock, Example1) {
    Solution s;
    std::vector<int> prices{7,1,5,3,6,4};
    EXPECT_EQ(s.maxProfit(prices), 5);
}

// 2. Example from LeetCode
TEST(BestTimeToBuyAndSellStock, Example2) {
    Solution s;
    std::vector<int> prices{7,6,4,3,1};
    EXPECT_EQ(s.maxProfit(prices), 0);
}

// 3. Typical Case: Strictly Increasing
TEST(BestTimeToBuyAndSellStock, Increasing) {
    Solution s;
    std::vector<int> prices{1,2,3,4,5};
    EXPECT_EQ(s.maxProfit(prices), 4);
}

// 4. Typical Case: Strictly Decreasing (Same as Example 2)
TEST(BestTimeToBuyAndSellStock, Decreasing) {
    Solution s;
    std::vector<int> prices{9,8,7,6,5};
    EXPECT_EQ(s.maxProfit(prices), 0);
}

// 5. Edge Case: Single Element
TEST(BestTimeToBuyAndSellStock, SingleElement) {
    Solution s;
    std::vector<int> prices{5};
    EXPECT_EQ(s.maxProfit(prices), 0);
}

// 6. Edge Case: Two Elements (Profit)
TEST(BestTimeToBuyAndSellStock, TwoElementsProfit) {
    Solution s;
    std::vector<int> prices{3,7};
    EXPECT_EQ(s.maxProfit(prices), 4);
}

// 7. Edge Case: Two Elements (Loss)
TEST(BestTimeToBuyAndSellStock, TwoElementsLoss) {
    Solution s;
    std::vector<int> prices{7,3};
    EXPECT_EQ(s.maxProfit(prices), 0);
}

// 8. Typical Case: Zigzag
TEST(BestTimeToBuyAndSellStock, Zigzag) {
    Solution s;
    std::vector<int> prices{2,4,1,5,7}; // Buy 1, Sell 7
    EXPECT_EQ(s.maxProfit(prices), 6);
}

// 9. Typical Case: Multiple Local Minima/Maxima
TEST(BestTimeToBuyAndSellStock, MultipleLocalMinima) {
    Solution s;
    std::vector<int> prices{3,2,6,1,4}; // Buy 2, Sell 6 = 4. Buy 1, Sell 4 = 3. Max is 4.
    EXPECT_EQ(s.maxProfit(prices), 4);
}

// 10. Edge Case: Flat Prices
TEST(BestTimeToBuyAndSellStock, FlatPrices) {
    Solution s;
    std::vector<int> prices{5,5,5,5};
    EXPECT_EQ(s.maxProfit(prices), 0);
}

// 11. Typical Case: Spike at End
TEST(BestTimeToBuyAndSellStock, SpikeAtEnd) {
    Solution s;
    std::vector<int> prices{5,4,3,2,10}; // Buy 2, Sell 10
    EXPECT_EQ(s.maxProfit(prices), 8);
}

// 12. Typical Case: Spike in Middle
TEST(BestTimeToBuyAndSellStock, SpikeInMiddle) {
    Solution s;
    std::vector<int> prices{1,10,1,10,1}; // Buy 1, Sell 10
    EXPECT_EQ(s.maxProfit(prices), 9);
}

// 13. Typical Case: Early Peak, then Drop
TEST(BestTimeToBuyAndSellStock, EarlyPeakThenDrop) {
    Solution s;
    std::vector<int> prices{10,9,8,7,6,7}; // Buy 6, Sell 7
    EXPECT_EQ(s.maxProfit(prices), 1);
}

// 14. Typical Case: Random 1
TEST(BestTimeToBuyAndSellStock, Random1) {
    Solution s;
    std::vector<int> prices{4,1,2,7,3,6,1,9}; // Buy 1 (day 2), Sell 9
    EXPECT_EQ(s.maxProfit(prices), 8);
}

// 15. Typical Case: Random 2
TEST(BestTimeToBuyAndSellStock, Random2) {
    Solution s;
    std::vector<int> prices{8,3,6,1,5}; // Buy 3, Sell 6 = 3. Buy 1, Sell 5 = 4. Max is 4.
    EXPECT_EQ(s.maxProfit(prices), 4);
}

// 16. Special Case: Large Values (near constraint max)
TEST(BestTimeToBuyAndSellStock, LargeValues) {
    Solution s;
    std::vector<int> prices{10000, 9999, 10000}; // Buy 9999, Sell 10000
    EXPECT_EQ(s.maxProfit(prices), 1);
}

// 17. Typical Case: Plateau then Rise
TEST(BestTimeToBuyAndSellStock, PlateauThenRise) {
    Solution s;
    std::vector<int> prices{3,3,3,5}; // Buy 3, Sell 5
    EXPECT_EQ(s.maxProfit(prices), 2);
}

// 18. Typical Case: Long Decline with One Bump
TEST(BestTimeToBuyAndSellStock, LongDeclineWithOneBump) {
    Solution s;
    std::vector<int> prices{9,8,2,8,1}; // Buy 2, Sell 8
    EXPECT_EQ(s.maxProfit(prices), 6);
}

// 19. Special Case: All Zeros
TEST(BestTimeToBuyAndSellStock, AllZero) {
    Solution s;
    std::vector<int> prices{0,0,0,0,0};
    EXPECT_EQ(s.maxProfit(prices), 0);
}

// 20. Edge Case: Empty (defensive check, though constraints say 1 <= N)
TEST(BestTimeToBuyAndSellStock, Empty) {
    Solution s;
    std::vector<int> prices;
    EXPECT_EQ(s.maxProfit(prices), 0);
}