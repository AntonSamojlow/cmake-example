module;
#include <vector>
#include "mainclass.h"

export module cache:container;

export struct Container
{
	std::vector<MainClass> data;
};
