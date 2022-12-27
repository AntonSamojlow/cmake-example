#include "mylibrary/libclass.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 'LibClass' defaults", "[libclass]") {
  LibClass testclass;
  REQUIRE(testclass.count == 0);
  REQUIRE(testclass.active == false);
}

TEST_CASE("Test 'LibClass' id", "[libclass]") {
  LibClass testclass{.count = 7, .active = true};
  REQUIRE(testclass.id() == 7);
  testclass.active = false;
  REQUIRE(testclass.id() == -7);
}
