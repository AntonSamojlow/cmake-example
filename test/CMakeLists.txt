# cmake file for test

# resolve external dependencies (vcpkg)
find_package(Catch2 REQUIRED)

# build target: test
add_executable(tests "factorial_test_example.cpp" "myclass_test.cpp")
target_include_directories(tests PRIVATE "./src/main/")
# main is provided by catch:
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
# link the code to be tested:
target_link_libraries(tests PRIVATE main_lib)

# use catch2 script to autodiscover all tests
include(CTest)
include(Catch)
catch_discover_tests(tests)
