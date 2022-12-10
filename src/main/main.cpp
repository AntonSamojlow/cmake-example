#include <iostream>
#include "myclass.h"

#include <spdlog/spdlog.h>

int main()
{
	auto logger = spdlog::default_logger();
	logger->info("This is a CMake test project");
	myclass classA = { .value = 1 };
	
	logger->info("classA: {}", classA.stringify());
	classA.recompute_flag();
	logger->info("classA: {}", classA.stringify());

	return 0;
}
