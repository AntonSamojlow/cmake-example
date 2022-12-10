cmake_minimum_required (VERSION 3.8)

project ("CMakeExampleProject")

# set global c++ standard to c++20
set(CMAKE_CXX_STANDARD 20)

# include sub-projects
add_subdirectory (src/main)