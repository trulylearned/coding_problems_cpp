# Shared C++ standard selection for every standalone problem project.
# Include this file from a problem CMakeLists.txt after ALGO_CODE_ROOT is found.
#
# Allowed ALGO_CXX_STANDARD values:
#   20 - Build with C++20.
#   23 - Build with C++23.
#   26 - Build with C++26.
#
# Default: 23
#
# Override per build, for example:
#   cmake -S . -B build -DALGO_CXX_STANDARD=26

# Cache the selected standard so users can override it per build directory with
# -DALGO_CXX_STANDARD=<20|23|26>.
set(ALGO_CXX_STANDARD "23" CACHE STRING "C++ standard for standalone algorithm projects")
set_property(CACHE ALGO_CXX_STANDARD PROPERTY STRINGS 20 23 26)

# Fail early on unsupported values instead of letting target_compile_features
# produce a compiler-dependent error later.
if(NOT ALGO_CXX_STANDARD STREQUAL "20"
    AND NOT ALGO_CXX_STANDARD STREQUAL "23"
    AND NOT ALGO_CXX_STANDARD STREQUAL "26")
  message(FATAL_ERROR "ALGO_CXX_STANDARD must be one of: 20, 23, 26")
endif()

# Apply the selected standard globally for vendored dependencies and expose the
# matching compile feature for repo targets.
set(CMAKE_CXX_STANDARD "${ALGO_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ALGO_CXX_COMPILE_FEATURE "cxx_std_${ALGO_CXX_STANDARD}")

# Apple SDK headers use C11 _Static_assert in some system headers. Apple Clang
# accepts that in C++ mode, but Homebrew GCC does not. Map it to C++ static_assert
# for Apple+GNU C++ builds so vendored GoogleTest and any project code can include
# those SDK headers cleanly.
if(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_definitions($<$<COMPILE_LANGUAGE:CXX>:_Static_assert=static_assert>)
endif()
