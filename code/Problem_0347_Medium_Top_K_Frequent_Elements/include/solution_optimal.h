#pragma once
#include <vector>
#include <unordered_map>
#include <utility> // For std::pair

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Bucket Sort
    // Time Complexity:  O(N)
    // Space Complexity: O(N)
    // Remarks:     Optimal linear time solution. Very fast.
    /////////////////////////////////////////////////////////////////
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count frequencies
        std::unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        // Step 2: Create buckets. Index = frequency.
        // Size is n+1 to handle indices 0 through n.
        int n = nums.size();
        std::vector<std::vector<int>> buckets(n + 1);

        // Step 3: Populate buckets
        // O(U) time, where U is number of unique elements
        for (auto& [num, count] : freq_map) {
            buckets[count].push_back(num);
        }

        // Step 4: Iterate backwards and collect k elements
        std::vector<int> result;
        for (int i = n; i >= 0 && result.size() < static_cast<size_t>(k); --i) {
            // i is the frequency
            // buckets[i] is the list of numbers with that frequency
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    if (result.size() == static_cast<size_t>(k)) {
                        break; // Found all k elements
                    }
                }
            }
        }
        
        return result;
    }
};