module;
// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file
#include <optional>
#include "mainclass.h"

module cache; // required. Identifies which named module this implementation unit belongs to

// implementation

static Container cache_instance;
namespace cache
{
	void Add(MainClass entry)
	{
		cache_instance.data.push_back(entry);
	}

	std::optional<MainClass> GetFirst(int value)
	{
		auto result = std::ranges::find(cache_instance.data, value, [&](const MainClass& mc) {return mc.value; });
		if (result == cache_instance.data.end())
			return std::nullopt;

		return *result;
	}
}