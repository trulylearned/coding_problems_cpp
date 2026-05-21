#pragma once

#include <vector>
#include <string>
#include <algorithm>

namespace brute_force_solution {

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-force grouping by comparing every pair
    // Time Cmplx:  O(N^2 * K log K)
    // Space Cmplx: O(N * K)
    // Remarks:     Conceptually simple but too slow for the given
    //              constraints. Will cause Time Limit Exceeded (TLE).
    /////////////////////////////////////////////////////////////////
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs)
    {
        int n = strs.size();
        std::vector<bool> used(n, false);
        std::vector<std::vector<std::string>> result;

        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            std::vector<std::string> group{strs[i]};
            used[i] = true;

            std::string sorted_i = strs[i];
            std::sort(sorted_i.begin(), sorted_i.end());

            for (int j = i + 1; j < n; ++j) {
                if (used[j]) {
                    continue;
                }
                std::string sorted_j = strs[j];
                std::sort(sorted_j.begin(), sorted_j.end());
                
                if (sorted_i == sorted_j) {
                    group.push_back(strs[j]);
                    used[j] = true;
                }
            }
            result.push_back(group);
        }

        return result;
    }
};

}  // namespace brute_force_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using Solution = brute_force_solution::Solution;
#endif
