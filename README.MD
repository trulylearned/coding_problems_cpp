# LeetCode C++ Solutions

This repo contains small, standalone C++ projects for LeetCode-style problem
solving. Each problem directory under a `code/<topic>/` folder owns its own
CMake project, debug app, solution headers, and GoogleTest suite.

The `code/` directory itself is shared infrastructure, not an aggregate CMake
project. Open, configure, build, and test one problem folder at a time.

## Layout

```text
code/
  AlgoProjectOptions.cmake
  external/
    CMakeLists.txt
    googletest/
      UPSTREAM.md
      upstream/
  templates/
    problem_project/
  test_cmake/
  01_Arrays_Strings_and_Hashing/
    Problem_0001_Easy_Two_Sum/
      .vscode/
      CMakeLists.txt
      include/
        solution.h
        solution_brute_force.h
        solution_optimal.h
        solutions.h
      src/main.cpp
      tests/tests.cpp
```

The topic folders mirror the 65-topic course organization. Each problem remains
independent. Shared CMake code is discovered by walking upward from the problem
folder until `code/AlgoProjectOptions.cmake` is found.

## Build And Test One Problem

From a problem directory, for example
`code/01_Arrays_Strings_and_Hashing/Problem_0001_Easy_Two_Sum`:

```bash
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure
./build/app
./build/app optimal
```

The app target is a small debug runner. With no argument it runs every registered
solution variant. With a solution id argument, it runs only that variant.

## C++ Standard

The shared CMake option is `ALGO_CXX_STANDARD`. The current default is C++23.

Allowed values:

- `20`
- `23`
- `26`

Default: `23`.

Override the standard for one build directory:

```bash
cmake -S . -B build -DALGO_CXX_STANDARD=26
```

Change the repo-wide default by editing this line in
`code/AlgoProjectOptions.cmake`:

```cmake
set(ALGO_CXX_STANDARD "23" CACHE STRING "C++ standard for standalone algorithm projects")
```

CMake caches this value per build directory. If a `build/` directory already
exists, reconfigure it with `-DALGO_CXX_STANDARD=<20|23|26>` or recreate the
build directory after changing the repo-wide default.

## GoogleTest

GoogleTest is vendored once under `code/external/googletest/upstream/` and
exposed to problem projects as `algo::gtest_main`. Problem projects should not
use `FetchContent` to download GoogleTest.

## Solution Organization

Each concrete solution header keeps the global `Solution` alias when included
directly. When `include/solutions.h` includes all variants together, it
suppresses those global aliases and refers to the namespaced classes instead.

Examples:

- `solution.h` -> `default_solution::Solution`
- `solution_brute_force.h` -> `brute_force_solution::Solution`
- `solution_optimal.h` -> `optimal_solution::Solution`

Tests use `solutions::for_each_solution` so the same cases run against every
registered variant. Slow brute-force variants skip stress-shaped tests.

## Adding A Problem

Copy `code/templates/problem_project/` into the appropriate `code/<topic>/`
folder, rename the folder, replace all placeholders, and keep the same
standalone CMake structure.

Do not add a root-level aggregate `CMakeLists.txt` just to build every problem.
For broad validation, iterate over the standalone problem folders.

## License

MIT - free to fork, learn from, and adapt.
