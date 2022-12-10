#include <catch2/catch_test_macros.hpp>

#include "main/mainclass.h"

TEST_CASE("Test 'MainClass'", "[mainclass]") {
	MainClass testclass = { .value = 1, .is_odd = false };
	testclass.recompute_flag();
	REQUIRE(testclass.is_odd == true);
}