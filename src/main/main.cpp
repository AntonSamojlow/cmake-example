#include <iostream>
#include <optional>
#include <spdlog/spdlog.h>

#include "main/mainclass.h"
#include "mylibrary/libclass.h"

import cache;

int main()
{
	auto logger = spdlog::default_logger();
	logger->info("This is a CMake test project");
	MainClass classA = { .value = 1 };
	logger->info("created local classA: {}", classA.stringify());
	classA.recompute_flag();
	logger->info("recomputed local classA: {}", classA.stringify());


	LibClass libclass = { .count = 2, .active = true };
	cache::Add(libclass);
	logger->info("stored in cache a copy of libclass with count={}, active=",
		libclass.count, libclass.active);
	auto lookup = cache::GetByMatchingCount(2);
	logger->info("fetched cached of libclass with count={}, active=",
		lookup.value().count, lookup.value().active);

	return 0;
}
