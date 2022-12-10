cmake_minimum_required (VERSION 3.8)

project ("cmake-example")

# set global c++ standard to c++20
set(CMAKE_CXX_STANDARD 20)

# include sub-projects
add_subdirectory (src/main)

# set up testing
enable_testing()
# allows test to reference src dir (else all includes must start with 'src/')
include_directories(src)
# include test projects
add_subdirectory (test)

