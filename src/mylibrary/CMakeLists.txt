# cmake file for src/mylibrary

# resolve external dependencies (vcpkg)
find_package(spdlog REQUIRED)

# get all source files
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ixx)
set(SOURCES ${SOURCES})

# build target main: as library
add_library(mylibrary ${SOURCES})
target_link_libraries(mylibrary PRIVATE spdlog::spdlog)
