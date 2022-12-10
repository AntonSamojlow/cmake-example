# cmake-example
A CMake example project: using c++20, modules and tests (via catch2) 

This is repository is wip, a test-bed to learn using CMake.

## Goals
The current goal is:
- Set up a good repo structure
- use cmake to build and test
- use c++20 source code, incl. modules
- unittests via catch2
- external dependencies may be installed via vcpkg (using 'manifest mode')
- 'multiplatform' fro now means:
    - compiles with MSVC and clang **on Windows**
    - clang tools (format, tidy, sanitizers) integrated
    - compiling on Linux should be tackled later by moving the cmake build to docker


