#include "myclass.h"

#include <format>

void MyClass::recompute_flag()
{
	is_odd = value_is_odd();
}

std::string MyClass::stringify()
{
	return std::format("value={}, is_odd={}", value, is_odd);
}

bool MyClass::value_is_odd()
{
	return value % 2 == 1;
}
