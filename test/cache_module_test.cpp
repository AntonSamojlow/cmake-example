#include <catch2/catch_test_macros.hpp>

import cache;

TEST_CASE("Test module 'cache'", "[cache-module]") {
	cache::Add({ .count = 11 });
	cache::Add({ .count = 2 });
	auto lookup_existing = cache::GetByMatchingCount(11);
	REQUIRE(lookup_existing.has_value() == true);
	REQUIRE(lookup_existing.value().count == 11);
	auto lookup_missing = cache::GetByMatchingCount(1);
	REQUIRE(lookup_missing.has_value() == false);
}

