# cmake file for src/main

# resolve external dependencies (vcpkg)
find_package(spdlog REQUIRED)

# get all source files
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ixx)
set(SOURCES ${SOURCES})

# combine dependencies in a variable
set(DEPENDENCIES spdlog::spdlog mylibrary)

# build target main: as executable
add_executable(main ${SOURCES})
target_link_libraries(main PRIVATE ${DEPENDENCIES})

enable_sanitizers(main
  "${ENABLE_SANITIZER_ADDRESS}"
  "${ENABLE_SANITIZER_LEAK}"
  "${ENABLE_SANITIZER_UNDEFINED_BEHAVIOR}"
  "${ENABLE_SANITIZER_THREAD}"
  "${ENABLE_SANITIZER_MEMORY}")

# build target main_lib: as lib to be consumed by tests (is there a better solution?)
add_library(main_lib ${SOURCES})
target_link_libraries(main_lib PRIVATE ${DEPENDENCIES})
 