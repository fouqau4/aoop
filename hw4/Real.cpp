#include "Real.h"

using std::to_string;

string Real::toString()
{		
	return to_string(value) + "\t(REAL)";
}