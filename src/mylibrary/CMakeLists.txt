# cmake file for src

# resolve external dependencies (vcpkg)
find_package(spdlog REQUIRED)

# get all source files
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ixx)
set(SOURCES ${SOURCES})

# build target main: as executable
add_library(mylibrary ${SOURCES})
target_link_libraries(mylibrary PRIVATE spdlog::spdlog)
