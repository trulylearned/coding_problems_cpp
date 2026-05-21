#pragma once

#include <string>
#include <array>

namespace brute_force_solution {

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute-Force using string replacements
    // Time Cmplx:  O(N^2)
    // Space Cmplx: O(N)
    // Remarks:     Simple to understand but very inefficient. Will
    //              likely time out on larger inputs.
    /////////////////////////////////////////////////////////////////
    bool isValid(std::string s) {
        const std::array<std::string, 3> paren_pairs {"()", "[]", "{}"};
        bool changed = true;
        std::string::size_type pos; // The alternative is std::size_t

        while (changed) {
            changed = false;
            for (const auto& paren_pair: paren_pairs) {
                while ((pos = s.find(paren_pair)) != std::string::npos) {
                    changed = true;
                    s.erase(pos, 2);
                }
            }
        }
        return s.empty();
    }
};

}  // namespace brute_force_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using Solution = brute_force_solution::Solution;
#endif
