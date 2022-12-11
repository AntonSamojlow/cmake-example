module; // optional. Defines the beginning of the global module fragment; 
// can be ommitted if no #includes are followed (file starts then with the 'module preamble' below)

#include "mainclass.h"
#include <optional>
// #include directives go here but only apply to this file and
// aren't shared with other module implementation files.
// Macro definitions aren't visible outside this file, or to importers.
// import statements aren't allowed here. They go in the module preamble, below.

export module cache; // Required. Marks the beginning of the 'module preamble'

// import statements go here. They're available to all files that belong to the named module
// Put #includes in in the global module fragment, above
import :container;

// After any import statements, the module purview begins here
// Put exported functions, types, and templates here
export namespace cache
{
	export void Add(MainClass entry);
	export std::optional<MainClass> GetFirst(int value);
}

module :private; // optional. Everything after this point is visible only within this file, and isn't 
// visible to any of the other files that belong to the named module.

