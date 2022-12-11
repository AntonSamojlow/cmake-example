// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file
#include <optional>
#include "libclass.h"

module cache; // required. Identifies which named module this implementation unit belongs to

// implementation

static Container cache_instance;
namespace cache
{
	void Add(LibClass entry)
	{
		cache_instance.data.push_back(entry);
	}

	std::optional<LibClass> GetByMatchingCount(int count)
	{
		auto result = std::ranges::find(cache_instance.data, count, [&](const LibClass& mc) {return mc.count; });
		if (result == cache_instance.data.end())
			return std::nullopt;

		return *result;
	}
}