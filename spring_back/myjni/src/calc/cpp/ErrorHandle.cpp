#include "ErrorHandle.h"

/**
 * Throws a BadExpression
 * @param s message to pass along with exception
*/
void expression_error(std::string s)
{
	throw BadExpression{ "Error: " + s };
}

/**
 * Throws a BracketCheck exception
 * @param d Val to pass along with exception
 * @param s message to pass along with exception
*/
void bracket_check(double d, std::string s)
{
	throw BracketCheck{d,  "Error: " + s };
}