# cmake-example
A CMake example project: using c++20, multi-compiler support (clang, msvc) and tests (via catch2) 

**This is repository is work in progress and a test-bed to learn using CMake.**

The long term goal is to first get it fully up and running on Windows.
And then add linux build support by moving the build to docker. 

## Requirements & dependencies
- cmake 3.24 + VS2022
- vcpkg installed and configure for cmake (env variable CMAKE_TOOLCHAIN_FILE set) 
    - or another package manager, with corresponding config: see [vcpkg.json](/vcpkg.json) for the used dependencies
- due to [this bug](https://github.com/microsoft/vcpkg/issues/15623), on Windows it is recommended to set environment variable `VcpkgAutoLink` to `false`

## Current goals
- compile on windows with both clang and msvc, and ninja as build-generator
    - currently, without module support since this is tioll lacking when using clang or msvc with ninja
- setup github ci
- add preset for sanitizers and all warnings enabled
- move build to docker, both for win and linux containers


