# cmake file for src

# resolve external dependencies (vcpkg)
find_package(spdlog REQUIRED)

# get all source files
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ixx)
set(SOURCES ${SOURCES})

# build target main: as executable
add_executable(main ${SOURCES})
target_link_libraries(main PRIVATE spdlog::spdlog)

# build target main_lin: as lib to be consumed by tests (is therre a better solution?)
add_library(main_lib ${SOURCES})
target_link_libraries(main_lib PRIVATE spdlog::spdlog)