#include "mylibrary/libclass.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 'LibClass' defaults", "[libclass]") {
  LibClass const testclass;
  REQUIRE(testclass.count == 0);
  REQUIRE(testclass.active == false);
}

const int FixedTestCount = 7;
TEST_CASE("Test 'LibClass' id", "[libclass]") {
  LibClass testclass{.count = FixedTestCount, .active = true};
  REQUIRE(testclass.id() == FixedTestCount);
  testclass.active = false;
  REQUIRE(testclass.id() == -FixedTestCount);
}
