#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      HashMap + Sorted Key
    // Time Cmplx:  O(N * K log K)
    // Space Cmplx: O(N * K)
    // Remarks:     Most common and elegant approach. Easy to explain
    //              and implement.
    /////////////////////////////////////////////////////////////////
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs)
    {
        // Key: sorted string, Value: list of its anagrams
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const auto& word : strs) {
            std::string sorted_word = word;
            std::sort(sorted_word.begin(), sorted_word.end());
            
            // Add the original word to the group for its sorted key
            groups[sorted_word].push_back(word);
        }

        std::vector<std::vector<std::string>> result;
        // Reserve space to avoid reallocations
        result.reserve(groups.size()); 
        
        // C++17 structured binding to unpack the map
        for (auto& [key, group] : groups) {
            // Use std::move to efficiently transfer ownership
            // of the group vector into the result vector
            result.push_back(std::move(group));
        }

        return result;
    }
};