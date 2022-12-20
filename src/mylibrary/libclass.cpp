#include "libclass.h"

#include <format>
#include <spdlog/spdlog.h>


int LibClass::id() const
{
	return count * (-1 +2*int(active));
}

void LibClass::log() const
{
	spdlog::default_logger()->info(std::format("LibClass::log (count={}, active={})", count, active));
}