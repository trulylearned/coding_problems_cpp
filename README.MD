# 🧩 LeetCode C++ Solutions — Cross-Platform, VS Code Friendly

> 🎥 **Video explanations available:** Each solution in this repository is accompanied by a detailed walkthrough on my YouTube channel — [@TrulyLearnedMe](https://www.youtube.com/@TrulyLearnedMe).
> The videos focus on reasoning, trade-offs, and clean Modern C++ implementation.

A fully reproducible Modern C++ project template for solving and testing **LeetCode problems**.
All problem directories are stored under the top-level **`code/`** folder, each following an identical structure designed for clarity, testing, and IDE integration.

---

## 📁 Repository Structure

```
code/
 ├── 0001_LC_1_Easy_Two_Sum/
 │    ├── .vscode/
 │    │    ├── c_cpp_properties.json
 │    │    ├── launch.json
 │    │    ├── settings.json
 │    │    └── tasks.json
 │    ├── include/
 │    │    ├── solution.h                 # Primary, tested solution
 │    │    ├── solution_brute_force.h     # Alternative approach
 │    │    └── solution_optimal.h         # Alternative approach
 │    ├── src/
 │    │    └── main.cpp                   # Optional demo entry point
 │    ├── tests/
 │    │    └── tests.cpp                  # GoogleTest unit tests
 │    └── CMakeLists.txt
 ├── 0002_LC_20_Easy_Valid_Parentheses/
 │    └── ...
 └── ...
```

* Every folder inside `code/` is independent and self-contained.
* Alternative solutions follow the naming pattern `solution_<description>.h`.
* `main.cpp` is only for manual debugging; automated tests are run via GoogleTest.

---

## ⚙️ Toolchain & Compatibility

*(Tested with C++23 — fully compatible with C++20)*

| Platform       | Compiler    | C++ Standard    | Status |
| -------------- | ----------- | --------------- | ------ |
| macOS 14 +     | Clang 17 +  | C++23 (✓ C++20) | ✅      |
| Windows 11     | MSVC 2022 + | C++23 (✓ C++20) | ✅      |
| Ubuntu 24.04 + | GCC 15 +    | C++23 (✓ C++20) | ✅      |

All builds use strict warnings (`-Wall -Wextra -Wpedantic` or `/W4`) and contain no platform-specific code.
The same project compiles cleanly and behaves identically across macOS, Windows, and Linux.

---

## 🧪 Testing with GoogleTest

Each problem folder contains its own test suite (`tests/tests.cpp`).
GoogleTest is automatically fetched by CMake.

Build and run tests:

```bash
cmake -S . -B build
cmake --build build
cd build
ctest --output-on-failure
```

---

## 💻 Recommended IDE Setup (Visual Studio Code)

1. Install the following extensions:

   * **C/C++** (Microsoft)
   * **CMake Tools**
   * **CTest Adapter** (optional)
2. Open the problem folder (e.g., `code/0001_LC_1_Easy_Two_Sum`) as a VS Code workspace.
3. Configure with CMake (`Ctrl + Shift + P → CMake: Configure`).
4. Run or debug either:

   * the dummy `app` target (for quick manual runs), or
   * the `problem_tests` target (for unit testing).

All `.vscode/*.json` files are pre-configured for convenient IntelliSense, build, and debugging.

---

## 🧠 Design Notes

* Each problem defines a small **`solution_lib`** (INTERFACE library) so headers can be shared between the runner and tests.

  * This library is header-only — it doesn’t compile code itself.
  * It simply exports include paths, C++ standard settings, and compiler flags to any target that links against it.
  * Both the executable (`app`) and the test binary (`problem_tests`) link to this same library, ensuring consistent configuration and zero duplication.
* CMake enables `CTest` and registers all GoogleTests automatically.
* Every solution header documents algorithmic complexity and design remarks.

---

## 🧰 Extending the Repository

To add a new problem:

1. Duplicate any existing numbered folder inside `code/`.
2. Update the name and `CMakeLists.txt` `project()` line.
3. Replace contents of `include/solution.h` and adjust `tests/tests.cpp`.
4. Re-run CMake and tests.

Optionally, a root-level `CMakeLists.txt` can be created to include all subprojects in the `code/` folder automatically.

---

## 📜 License

MIT — free to fork, learn from, and adapt.
