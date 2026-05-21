#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace brute_force_solution {

class {{SOLUTION_CLASS_NAME}} {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Brute force
    // Time Cmplx:  TODO
    // Space Cmplx: TODO
    // Remarks:     Start with the simplest correct approach.
    /////////////////////////////////////////////////////////////////
    {{FUNCTION_SIGNATURE}}
    {
        {{BRUTE_FORCE_IMPLEMENTATION}}
    }
};

}  // namespace brute_force_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using {{SOLUTION_CLASS_NAME}} = brute_force_solution::{{SOLUTION_CLASS_NAME}};
#endif
