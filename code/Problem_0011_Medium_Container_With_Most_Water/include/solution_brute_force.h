#pragma once
#include <vector>
#include <algorithm>
#include <cmath> // For std::min, std::max

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force using nested loops
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(1)
    // Remarks:     Correct, but too slow. Will Time Limit Exceed.
    /////////////////////////////////////////////////////////////////
    int maxArea(std::vector<int>& height) {
        int max_area = 0;
        int n = static_cast<int>(height.size());
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate height: limited by the shorter line
                int h = std::min(height[i], height[j]);
                // Calculate width: distance between indices
                int w = j - i;
                // Calculate area
                int area = h * w;
                // Update max
                max_area = std::max(max_area, area);
            }
        }
        return max_area;
    }
};