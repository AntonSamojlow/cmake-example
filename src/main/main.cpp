#include <iostream>
#include <optional>
#include <spdlog/spdlog.h>

#include "main/mainclass.h"
#include "mylibrary/libclass.h"

int main()
{
	auto logger = spdlog::default_logger();
	MainClass classA = { .value = 1 };

	logger->info("stored in cache a copy of classA: {}", classA.stringify());
	classA.recompute_flag();
	logger->info("recomputed local classA: {}", classA.stringify());

	LibClass libclass;
	libclass.log();
	logger->info("libclass default values: count={}, active={}", libclass.count, libclass.active);

	return 0;
}
