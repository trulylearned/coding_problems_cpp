# Shared third-party dependencies for standalone problem projects.
# Problem CMakeLists.txt files add this directory through ALGO_CODE_ROOT.

# Keep GoogleTest static on Windows and avoid installing vendored targets from
# this learning repo's builds.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

# Build the vendored GoogleTest checkout from code/external/googletest/upstream.
# The binary dir is kept under the caller's build tree.
add_subdirectory(
  googletest/upstream
  "${CMAKE_BINARY_DIR}/external/googletest"
  EXCLUDE_FROM_ALL
)

# Provide one stable repo-local target name. This keeps problem projects from
# depending on GoogleTest's exact exported target spelling.
add_library(algo_gtest_main INTERFACE)
add_library(algo::gtest_main ALIAS algo_gtest_main)

# Recent GoogleTest exports GTest::gtest_main; older builds may expose
# gtest_main. Support either target behind algo::gtest_main.
if(TARGET GTest::gtest_main)
  target_link_libraries(algo_gtest_main INTERFACE GTest::gtest_main)
elseif(TARGET gtest_main)
  target_link_libraries(algo_gtest_main INTERFACE gtest_main)
else()
  message(FATAL_ERROR "Vendored GoogleTest target gtest_main was not created.")
endif()
