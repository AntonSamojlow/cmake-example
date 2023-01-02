# this file and its sub-includes are inspired by https://github.com/aminya/cpp_vcpkg_project

cmake_minimum_required (VERSION 3.24)

project ("cmake-example")

# set global c++ standard to c++20
set(CMAKE_CXX_STANDARD 20)

# log base compiler info
if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "CMAKE_CXX_COMPILER='${CMAKE_CXX_COMPILER}'")
  message(STATUS "CMAKE_CXX_COMPILER_ID='${CMAKE_CXX_COMPILER_ID}'")
  message(STATUS 
  "CMAKE_CXX_COMPILER_VERSION='${CMAKE_CXX_COMPILER_VERSION}'")
  message(STATUS 
  "CMAKE_COMPILER_IS_GNUCXX='${CMAKE_COMPILER_IS_GNUCXX}'")
endif()


include("${CMAKE_CURRENT_LIST_DIR}/cmake/Sanitizers.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/StaticAnalysis.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/Warnings.cmake")

# disabled module support since it is still experimental -> references:
# https://gitlab.kitware.com/cmake/cmake/-/issues/18355
# https://github.com/Kitware/CMake/blob/master/Help/dev/experimental.rst
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 9629ab6c-6c0e-423f-bb9d-cc5ac4a22041)
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)


# allows test and other libs to reference src folder directly 
# (else all cross-project includes must start with 'src/' or '../')
include_directories(src)

enable_clang_tidy()

# include sub-projects
add_subdirectory (src/mylibrary)
add_subdirectory (src/main)

# set up testing
enable_testing()
# include test projects
add_subdirectory (test)

