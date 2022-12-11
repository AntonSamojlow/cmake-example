#include <catch2/catch_test_macros.hpp>

import cache;

TEST_CASE("Test module 'cache'", "[cache-module]") {
	cache::Add({ .value = 11 });
	cache::Add({ .value = 2 });
	auto lookup_existing = cache::GetFirst(11);
	REQUIRE(lookup_existing.has_value() == true);
	REQUIRE(lookup_existing.value().value == 11);
	auto lookup_missing = cache::GetFirst(3);
	REQUIRE(lookup_missing.has_value() == false);
}

