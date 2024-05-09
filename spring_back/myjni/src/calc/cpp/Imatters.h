#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map>


enum class Type { number, oprator };	// Either a number(literal or variable) of an operator

class Token
{
	union Value					// Either a number or an operator
	{
		double realVal;
		char charVal;
	};
	Value val;

	Type typ;

public:
	Token(double d) : typ{ Type::number } { val.realVal = d; }
	Token(char c) : typ{ Type::oprator } { val.charVal = c; }
	Token(std::string);

	Type getType() { return typ; }
	Value getValue(){ return val; }
};

void add_to_var(std::string, double);				// insert variable to varList
void takeIn(std::vector<Token>&, std::istream&);			// Take in input and convert to Tokens
