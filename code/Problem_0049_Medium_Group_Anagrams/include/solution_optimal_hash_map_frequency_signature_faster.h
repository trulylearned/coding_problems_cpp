#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <array> // For std::array

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      HashMap + Frequency Signature
    // Time Cmplx:  O(N * K)
    // Space Cmplx: O(N * K)
    // Remarks:     Fastest solution. Avoids sorting, which is
    //              theoretically better for very large K.
    /////////////////////////////////////////////////////////////////
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs) 
    {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const auto& word : strs) {
            // Create a frequency array for 'a' through 'z',
            // initialized to all zeros.
            std::array<int, 26> freq{};
            
            // Count characters (O(K) operation)
            for (char c : word) {
                freq[c - 'a']++;
            }

            // Build the signature key (O(26) = O(1) operation)
            std::string key;
            // Reserve space. A count could be 100 ("100#"),
            // so 4 chars * 26 letters = 104. 
            // We'll reserve a reasonable amount.
            key.reserve(78); // e.g., 26 * 3
            
            for (int count : freq) {
                key += std::to_string(count) + '#';
            }

            // Add the original word to the group
            groups[key].push_back(word);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(groups.size());
        for (auto& [_, group] : groups) {
            result.push_back(std::move(group));
        }

        return result;
    }
};