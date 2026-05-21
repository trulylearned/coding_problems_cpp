# GoogleTest Upstream Record

- Dependency: `GoogleTest`
- Approved version: `1.17.0`
- Upstream project: `https://github.com/google/googletest`
- Source archive: `https://github.com/google/googletest/archive/refs/tags/v1.17.0.tar.gz`
- License: `BSD-3-Clause`
- Imported date: `2026-04-22`
- Archive SHA-256: `65fab701d9829d38cb77c14acdc431d2108bfdbf8979e40eb8ae567edf10b27c`
- Local patches: `none`

## Notes

- The upstream archive is hosted under `code/external/googletest/upstream/`.
- This dependency is intended for test-only use.
- Project-owned CMake code links through `algo::gtest_main` instead of depending directly on upstream target names.
