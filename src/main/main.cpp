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
	cache::Add(classA);

	logger->info("stored in cache a copy of classA: {}", classA.stringify());
	classA.recompute_flag();
	logger->info("recomputed local classA: {}", classA.stringify());

	auto lookup = cache::GetFirst(1);
	logger->info("fetched cached classA: {}", lookup.value().stringify());

	LibClass libclass;
	logger->info("libclass default values: count={}, active={}", libclass.count, libclass.active);

	return 0;
}
