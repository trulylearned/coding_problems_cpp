#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace optimal_solution {

class {{SOLUTION_CLASS_NAME}} {
public:
    /////////////////////////////////////////////////////////////////
    // Method:      Optimal
    // Time Cmplx:  TODO
    // Space Cmplx: TODO
    // Remarks:     Replace with the intended interview-ready approach.
    /////////////////////////////////////////////////////////////////
    {{FUNCTION_SIGNATURE}}
    {
        {{OPTIMAL_IMPLEMENTATION}}
    }
};

}  // namespace optimal_solution

#ifndef ALGO_SUPPRESS_GLOBAL_SOLUTION_ALIAS
using {{SOLUTION_CLASS_NAME}} = optimal_solution::{{SOLUTION_CLASS_NAME}};
#endif
