# cmake-example
A CMake example project: using c++20, multi-compiler support (clang, msvc, gcx) and tests (via catch2) 

**This is repository is work in progress and a test-bed to learn using CMake.**

The long term goal is to first get it fully up and running on Windows.
And then add linux build support by moving the build to docker. 

## Requirements & dependencies
- cmake 3.24 + Ninja 1.11 (and optionally VS2022) 
- due to [this bug](https://github.com/microsoft/vcpkg/issues/15623), on Windows it is recommended to set environment variable `VcpkgAutoLink` to `false`
- when using vscode with cmake and ninja as generator on windows: open vscode from the corresponding dev command prompt,
    this would be the "x64 native tools command prompt" (currently no x86 build configured). 
    Reasons/references:
    - [https://github.com/microsoft/vscode-cmake-tools/blob/HEAD/docs/cmake-presets.md#cmake-configure](https://github.com/microsoft/vscode-cmake-tools/blob/HEAD/docs/cmake-presets.md#cmake-configure)
    - [https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line?redirectedfrom=MSDN&view=msvc-170#developer_command_file_locations](https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line?redirectedfrom=MSDN&view=msvc-170#developer_command_file_locations)

## How to build, test and run locally
- Ensure cmake, ninja and at least one from gccclang/msvc are set up
- Checkout and run:
    - `cmake --list-presets`to list the desired presets
    - `cmake --preset DESIRED_PRESET` to configure
    - `cmake --build out/build/DESIRED_PRESET` to build 
        - alternative, if a *build* preset exists for your configuration: `cmake --build --preset DESIRED_PRESET`
    - `ctest out/build/DESIRED_PRESET` to run the tests
        - alternative, if a *test* preset exists for your configuration: `ctest --preset DESIRED_PRESET`
    - `out/build/src/main/main.exe` to run the example console program  

## Current goals
### Remaining
- implement a dockerbuild, both for win and linux containers
- add module support once supported by at least msvc and clang both on linux and windows

### Done
- compile on windows with both clang and msvc, and ninja as build-generator
    - currently, without module support since this is still lacking support, i.p. when using clang or msvc with ninja
- setup github ci
- add preset for sanitizers and all warnings enabled
