cmake_minimum_required(VERSION 3.20)
project(LC_Problem LANGUAGES CXX)

# ---- Make the whole project C++23 (helps IntelliSense, MSVC, etc.) ----
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----- Header-only "library" so app + tests share config -----
add_library(solution_lib INTERFACE)
target_include_directories(solution_lib INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# Also advertise C++23 to dependents of solution_lib
target_compile_features(solution_lib INTERFACE cxx_std_23)

if (MSVC)
  target_compile_options(solution_lib INTERFACE /W4 /permissive- /EHsc /utf-8)
  # Report correct __cplusplus value with MSVC (useful for some libs)
  add_compile_options(/Zc:__cplusplus)
else()
  target_compile_options(solution_lib INTERFACE -Wall -Wextra -Wpedantic)
endif()

# ----- Optional runner (delete src/main.cpp if you don't need it) -----
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
  add_executable(app src/main.cpp)
  target_link_libraries(app PRIVATE solution_lib)
endif()

# Editor helpers + sensible default build type
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# =========================
# GoogleTest + CTest
# =========================
include(CTest)
enable_testing()

# Verbose, color-friendly output when you run `ctest`
set(CMAKE_CTEST_ARGUMENTS "-V --output-on-failure")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For MSVC runtime
FetchContent_MakeAvailable(googletest)

# ----- Test binary (always tests/tests.cpp) -----
add_executable(problem_tests tests/tests.cpp)
target_link_libraries(problem_tests PRIVATE solution_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(problem_tests)
