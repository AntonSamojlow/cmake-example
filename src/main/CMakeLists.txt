# cmake file for src

# resolve external dependencies (vcpkg)
find_package(spdlog REQUIRED)

# get all source files
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ixx)
set(SOURCES ${SOURCES})

# build target main: as executable
add_executable (main ${SOURCES})
target_link_libraries(main PRIVATE spdlog::spdlog)