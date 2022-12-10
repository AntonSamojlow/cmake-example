#include "myclass.h"

#include <format>

void myclass::recompute_flag()
{
	is_odd = value_is_odd();
}

std::string myclass::stringify()
{
	return std::format("value={}, is_odd={}", value, is_odd);
}

bool myclass::value_is_odd()
{
	return value % 2 == 1;
}
