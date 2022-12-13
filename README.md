# cmake-example
A CMake example project: using c++20, modules and tests (via catch2) 

This is repository is wip, a test-bed to learn using CMake.

The long term goal is to first get it fully up and running on Windows.
And then add linux build support by moving the build to docker. 

## Requirements & dependencies
- cmake + VS2022 (catch2 test adapter extension recommended but not required)
- vcpkg installed and configure for cmake (env variable CMAKE_TOOLCHAIN_FILE set) 
    - or another package manager, with corresponding config: see [vcpkg.json](/vcpkg.json) for the used dependencies
- due to [this bug](https://github.com/microsoft/vcpkg/issues/15623), on Windows it is recommended to set environment variable `VcpkgAutoLink` to `false`

## Current goals
- a good repo structure
- use cmake to build and test
- use c++20 source code, incl. modules
- unittests via catch2
- external dependencies may be installed via vcpkg (using 'manifest mode')
- 'multiplatform' fro now means:
    - compiles with MSVC and clang **on Windows**
    - clang tools (format, tidy, sanitizers) integrated



