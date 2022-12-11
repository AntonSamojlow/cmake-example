#include "libclass.h"

#include <format>

import libmodule;

int LibClass::id() const
{
	return count * (-1 +2*int(active));
}

void LibClass::log() const
{
	lib::log(std::format("LibClass::log (count={}, active={})", count, active));
}