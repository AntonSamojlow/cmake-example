#include "libclass.h"

int LibClass::id() const
{
	return count * (-1 +2*int(active));
}
