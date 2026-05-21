# Standalone CMake project for one algorithm problem.
# Configure this directory directly; the repo intentionally has no root aggregate build.
cmake_minimum_required(VERSION 3.30)

# Keep generated CMake files out of source directories.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR
    "In-source builds are disabled. Use: cmake -S . -B build -G Ninja")
endif()

# The project name is problem-specific, but every problem shares the same target layout.
project(LC_1_Two_Sum LANGUAGES CXX)

# Locate code/AlgoProjectOptions.cmake by walking upward from this standalone
# problem directory. This keeps copied or nested problem projects independent.
set(ALGO_CODE_ROOT "${CMAKE_CURRENT_LIST_DIR}")
while(NOT EXISTS "${ALGO_CODE_ROOT}/AlgoProjectOptions.cmake")
  get_filename_component(ALGO_PARENT_DIR "${ALGO_CODE_ROOT}" DIRECTORY)
  if(ALGO_PARENT_DIR STREQUAL ALGO_CODE_ROOT)
    message(FATAL_ERROR "Could not find code/AlgoProjectOptions.cmake.")
  endif()
  set(ALGO_CODE_ROOT "${ALGO_PARENT_DIR}")
endwhile()

# Imports ALGO_CXX_STANDARD and ALGO_CXX_COMPILE_FEATURE.
include("${ALGO_CODE_ROOT}/AlgoProjectOptions.cmake")

# ----- Header-only interface library so app + tests share config -----
add_library(solution_lib INTERFACE)
target_include_directories(solution_lib INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Require the selected C++ standard for both the debug app and tests.
target_compile_features(solution_lib INTERFACE ${ALGO_CXX_COMPILE_FEATURE})

# Keep compiler diagnostics consistent across app and test targets.
if(MSVC)
  target_compile_options(solution_lib INTERFACE /W4 /permissive- /EHsc /utf-8)
  add_compile_options(/Zc:__cplusplus)
else()
  target_compile_options(solution_lib INTERFACE -Wall -Wextra -Wpedantic)
endif()

# ----- Debug runner -----
# The app target is for local debugging and can run one or all registered solutions.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
  add_executable(app src/main.cpp)
  target_link_libraries(app PRIVATE solution_lib)
endif()

# Emit compile_commands.json for editor integration and language servers.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default single-config generators such as Ninja and Makefiles to Debug builds.
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# =========================
# GoogleTest + CTest
# =========================
include(CTest)
enable_testing()

set(CMAKE_CTEST_ARGUMENTS "-V --output-on-failure")

# Pull vendored GoogleTest through the repo-local alias target without network access.
if(NOT TARGET algo::gtest_main)
  add_subdirectory(
    "${ALGO_CODE_ROOT}/external"
    "${CMAKE_BINARY_DIR}/external"
  )
endif()

# Tests include solutions.h and run every registered implementation variant.
add_executable(problem_tests tests/tests.cpp)
target_link_libraries(problem_tests PRIVATE solution_lib algo::gtest_main)

include(GoogleTest)
gtest_discover_tests(problem_tests)
