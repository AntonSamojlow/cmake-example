#include <catch2/catch_test_macros.hpp>

#include "main/myclass.h"

TEST_CASE("Test 'myclass'", "[myclass]") {
	myclass testclass = { .value = 1, .is_odd = false };
	testclass.recompute_flag();
	REQUIRE(testclass.is_odd == true);
}