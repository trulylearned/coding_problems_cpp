# Problem Project Template

This template lives at `code/templates/problem_project/`. Copy it into the
appropriate topic category under `code/`, then rename the copied folder to the
problem id/name format used by this repo.

Replace every `{{...}}` placeholder before building.

## Required Placeholders

- `{{PROBLEM_PROJECT_NAME}}`: CMake project name, for example `LC_1_Two_Sum`.
- `{{PROBLEM_DISPLAY_NAME}}`: Human-readable problem name for comments/docs.
- `{{SOLUTION_CLASS_NAME}}`: Usually `Solution`; use the LeetCode class name.
- `{{FUNCTION_SIGNATURE}}`: The LeetCode method signature without the body.
- `{{BRUTE_FORCE_IMPLEMENTATION}}`: Body statements for the brute-force method.
- `{{OPTIMAL_IMPLEMENTATION}}`: Body statements for the optimal method.
- `{{DEBUG_INPUT_SETUP}}`: Variables to create in `src/main.cpp`.
- `{{DEBUG_CALL_AND_PRINT}}`: The call and output code for manual debugging.
- `{{TEST_CASES}}`: GoogleTest cases that call `ForEachSolutionForCurrentTest`.

## Solution Files

- `include/solution_brute_force.h`: simplest correct approach.
- `include/solution_optimal.h`: interview-ready approach.
- `include/solution.h`: default global alias to the optimal solution.
- `include/solutions.h`: registry used by tests and the debug app to run every solution.

Each concrete solution header keeps the configured solution class name available
at global scope when included by itself, while `solutions.h` suppresses those
aliases so all implementations can be included together.

## Build

After replacing placeholders:

```bash
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure
./build/app
./build/app brute_force
./build/app optimal
```

The template `CMakeLists.txt` walks upward until it finds
`code/AlgoProjectOptions.cmake`, then uses that `code/` root for shared C++
options and vendored dependencies.
