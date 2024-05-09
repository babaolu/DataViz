#include "ErrorHandle.h"

void expression_error(std::string s)
{
	throw BadExpression{ "Error: " + s };
}

void bracket_check(double d, std::string s)
{
	throw BracketCheck{d,  "Error: " + s };
}