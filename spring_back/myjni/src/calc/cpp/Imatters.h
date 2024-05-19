#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map>

/**
 * Used for categorizing tokens in types
*/
enum class Type {number, oprator , strng};	// Either a number(literal or variable) of an operator

/**
 * Constants used to represent trigonometric and logarithmic tokens
*/
enum class Trig {rsin, rcos, rtan, rasin, racos, ratan, mlog, mlog2, mlog10};

/**
 * Token definition
*/
class Token
{
	union Value  // Either a number or an operator or a trig/log constant
	{
		double realVal;
		char charVal;
		Trig strVal;
	};
	Value val;
	
	std::map<std::string, Trig> varList {{"cos", Trig::rcos}, {"sin", Trig::rsin},
	{"tan", Trig::rtan}, {"acos", Trig::racos}, {"asin", Trig::rasin},
	{"atan", Trig::ratan}, {"log", Trig::mlog}, {"log2", Trig::mlog2}, {"log10", Trig::mlog10}};

	Type typ;

public:
	Token(double d) : typ{ Type::number } { val.realVal = d; }
	Token(char c) : typ{ Type::oprator } { val.charVal = c; }
	Token(std::string);

	Type getType() { return typ; }
	Value getValue(){ return val; }
};

void takeIn(std::vector<Token>&, std::istream&);			// Take in input and convert to Tokens
