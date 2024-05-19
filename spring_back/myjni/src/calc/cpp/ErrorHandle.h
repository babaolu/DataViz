#pragma once

#include "IOmatters.h"

/**
 * A class used for throwing expression errors
*/
struct BadExpression
{
	std::string message;
};

/**
 * A class used for throwing exceptions errors
*/
struct BracketCheck : BadExpression
{
	double val;
	BracketCheck(double d, std::string s)
		: BadExpression{ s }, val{ d }{}
};

void expression_error(std::string);
void bracket_check(double, std::string);