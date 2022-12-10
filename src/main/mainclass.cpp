#include "mainclass.h"

#include <format>

void MainClass::recompute_flag()
{
	is_odd = value_is_odd();
}

std::string MainClass::stringify()
{
	return std::format("value={}, is_odd={}", value, is_odd);
}

bool MainClass::value_is_odd()
{
	return value % 2 == 1;
}
