cmake_minimum_required (VERSION 3.8)

project ("cmake-example")

# set global c++ standard to c++20
set(CMAKE_CXX_STANDARD 20)

# current module support is experimental, references:
# https://gitlab.kitware.com/cmake/cmake/-/issues/18355
# https://github.com/Kitware/CMake/blob/master/Help/dev/experimental.rst
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 9629ab6c-6c0e-423f-bb9d-cc5ac4a22041)
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

# allows test and other libs to reference src folder directly 
# (else all cross-project includes must start with 'src/' or '../')
include_directories(src)

# include sub-projects
add_subdirectory (src/mylibrary)
add_subdirectory (src/main)

# set up testing
enable_testing()
# include test projects
add_subdirectory (test)

