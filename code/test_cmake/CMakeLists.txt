cmake_minimum_required(VERSION 3.30)

# This smoke project verifies the shared CMake helpers independently from any
# LeetCode problem directory.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR
    "In-source builds are disabled. Use: cmake -S . -B build -G Ninja")
endif()

# ---- Project ----
project(TestCmake LANGUAGES CXX)

# Locate code/AlgoProjectOptions.cmake by walking upward from this directory.
# This matches the discovery logic used by every problem project.
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

# ---- Target ----
add_executable(test
  src/main.cpp
  src/message.cpp
)

# Header search path (explicit = friendlier to IntelliSense)
target_include_directories(test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Require the selected C++ standard (portable way)
target_compile_features(test PRIVATE ${ALGO_CXX_COMPILE_FEATURE})

# ---- Warnings per compiler (portable) ----
if (MSVC)
  # /W4: high warnings, /EHsc: C++ exceptions, /permissive-: stricter C++
  target_compile_options(test PRIVATE /W4 /EHsc /permissive- /Zc:preprocessor /utf-8)
  # Nice-to-have defs on Windows
  target_compile_definitions(test PRIVATE
    _CRT_SECURE_NO_WARNINGS
    NOMINMAX            # avoid std::min/max clashes with Windows headers
  )
else()
  # GCC/Clang
  target_compile_options(test PRIVATE -Wall -Wextra -Wpedantic)
  # (Optional) stricter checks you can uncomment if you like
  # target_compile_options(test PRIVATE -Wconversion -Wsign-conversion -Wshadow)
endif()

# ---- Build type default (for single-config generators) ----
# Visual Studio/Xcode are multi-config; Ninja/Makefiles are single-config.
if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# ---- Helpful for VS Code C/C++ extension ----
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Platform-specific tweaks (optional) ----
if (APPLE)
  # macOS-specific settings can go here if needed later.
elseif (WIN32)
  # Force static runtime example (OFF by default, turn ON if you want it):
  # set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
