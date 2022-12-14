#include <catch2/catch_test_macros.hpp>

namespace {
// suppress misc-no-recursion
// NOLINTBEGIN
unsigned int Factorial(unsigned int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}
// NOLINTEND

}  // namespace

TEST_CASE("Factorial Example Test", "[factorial]") {
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(10) == 3628800);
}

// TEST_CASE("Factorial Example Test Failing", "[factorial-fail]") {
//   REQUIRE(Factorial(1) == 0);
// }
