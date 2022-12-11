# cmake file for test

# resolve external dependencies (vcpkg)
find_package(Catch2 REQUIRED)

# get all source files
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.ixx)
set(SOURCES ${SOURCES})
set(LIBRARIESUNDERTEST main_lib mylibrary)

# build target: test
add_executable(tests ${SOURCES})
# main is provided by catch:
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
# link the code to be tested:
target_link_libraries(tests PRIVATE ${LIBRARIESUNDERTEST})

# use catch2 script to autodiscover all tests
include(CTest)
include(Catch)
catch_discover_tests(tests)
