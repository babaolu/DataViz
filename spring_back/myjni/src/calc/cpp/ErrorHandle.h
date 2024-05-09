#pragma once

#include "IOmatters.h"

struct BadExpression
{
	std::string message;
};

struct BracketCheck : BadExpression
{
	double val;
	BracketCheck(double d, std::string s)
		: BadExpression{ s }, val{ d }{}
};

void expression_error(std::string);
void bracket_check(double, std::string);