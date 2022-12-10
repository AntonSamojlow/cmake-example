cmake_minimum_required (VERSION 3.8)

project ("cmake-example")

# set global c++ standard to c++20
set(CMAKE_CXX_STANDARD 20)

# allows test and other libs to reference src folder directly 
# (else all includes must start with 'src/' or '../')
include_directories(src)

# include sub-projects
add_subdirectory (src/main)
add_subdirectory (src/mylibrary)

# set up testing
enable_testing()
# include test projects
add_subdirectory (test)

