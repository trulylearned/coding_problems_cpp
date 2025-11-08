#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility> // For std::pair

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Sort by Frequency
    // Time Complexity:  O(N log N) (Worst-case)
    // Space Complexity: O(N) (Worst-case)
    // Remarks:     Simple and passes, but doesn't meet the O(N log N)
    //              follow-up requirement.
    /////////////////////////////////////////////////////////////////
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count frequencies
        std::unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        // Step 2: Copy map to vector of pairs
        std::vector<std::pair<int, int>> items;
        for (auto& pair : freq_map) {
            items.push_back(pair); // Pushes {number, frequency}
        }

        // Step 3: Sort the vector by frequency (descending)
        std::sort(items.begin(), items.end(),
                  [](auto& a, auto& b) {
                      // We sort by the second element (frequency)
                      return a.second > b.second; 
                  });

        // Step 4: Extract the top k elements
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(items[i].first); // items[i].first is the number
        }
        return result;
    }
};