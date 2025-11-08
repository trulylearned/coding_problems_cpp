#pragma once
#include <vector>
#include <unordered_map>
#include <queue> // For std::priority_queue
#include <utility> // For std::pair

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Min-Heap (Priority Queue)
    // Time Complexity:  O(N log k)
    // Space Complexity: O(N + k) (Worst-case)
    // Remarks:     Efficient. Meets the follow-up requirement.
    //              Ideal when N is large and k is small.
    /////////////////////////////////////////////////////////////////
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Step 1: Count frequencies
        std::unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        // We will store pairs of (frequency, number)
        using FreqPair = std::pair<int, int>;

        // Step 2: Define a min-heap.
        // By default, std::priority_queue is a max-heap.
        // We provide std::greater to make it a min-heap.
        std::priority_queue<
            FreqPair,
            std::vector<FreqPair>,
            std::greater<FreqPair>
        > min_heap;

        // Step 3 & 4: Iterate map and maintain heap size
        for (auto& [num, count] : freq_map) {
            min_heap.push({count, num}); // Push (frequency, number)
            
            // Step 5: If heap size exceeds k, pop the smallest
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // Step 6: Extract elements from the heap
        std::vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second); // .second is the number
            min_heap.pop();
        }
        
        // Note: The result will not be sorted by frequency.
        // If sorting is needed, an extra O(k log k) step is required.
        // But the problem says "any order" is fine.
        return result;
    }
};