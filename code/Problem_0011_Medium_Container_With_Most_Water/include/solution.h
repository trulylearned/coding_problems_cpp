#pragma once
#include <vector>
#include <algorithm>
#include <cmath> // For std::min, std::max

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Two-Pointer technique
    // Time Cmplx:  O(N)
    // Space Cmplx: O(1)
    // Remarks:     Optimal solution. Very common and elegant.
    /////////////////////////////////////////////////////////////////
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate height, limited by the shorter line
            int h = std::min(height[left], height[right]);
            // Calculate width, the distance between pointers
            int w = right - left;
            // Calculate and update max area
            int area = h * w;
            max_area = std::max(max_area, area);

            // The "Aha!" move:
            // We move the pointer of the shorter line,
            // as this is the only way we might find a taller
            // line to compensate for the decrease in width.
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_area;
    }
};