#include <iostream>

#include <spdlog/spdlog.h>


#include "main/mainclass.h"
#include "mylibrary/libclass.h"

int main()
{
	auto logger = spdlog::default_logger();
	logger->info("This is a CMake test project");
	MainClass classA = { .value = 1 };
	
	logger->info("classA: {}", classA.stringify());
	classA.recompute_flag();
	logger->info("classA: {}", classA.stringify());

	LibClass libclass;
	logger->info("libclass default values: count={}, active={}", libclass.count, libclass.active);

	return 0;
}
