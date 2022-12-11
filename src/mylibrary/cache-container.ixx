module;
#include <vector>
#include "libclass.h"

export module cache:container;

export struct Container
{
	std::vector<LibClass> data;
};
