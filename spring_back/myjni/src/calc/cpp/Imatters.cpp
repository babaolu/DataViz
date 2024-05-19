#include "Imatters.h"
#include "ErrorHandle.h"

/**
 * A constructor for Token with string as input
 * 
 * This constructor attempts to create a Token out of a string if that string
 * is a recognized keyword. If the string is not recognized, it throws and
 * expression error
*/
Token::Token(std::string s)
	: typ{ Type::strng }
{
	auto Var = varList.find(s);
	if (Var != varList.end())
		val.strVal = Var->second;
	else 
		expression_error("Nonexisting identifier: '" + s + "'");
}

/**
 * This functions collects characters from the input stream ist and converts
 * them into Tokens based on their property which is then stored Token vector
 * @param tokenVec Token vector
 * @param ist Input stream
*/
void takeIn(std::vector<Token>& tokenVec, std::istream& ist)
{
	char charVal;
	double numVal;

	while (ist >> charVal)
	{
		if (charVal == ';')
		{
			tokenVec.push_back(Token{ charVal });
			break;
		}

		if (isdigit(charVal))			// If at the beginning of a number
		{
			ist.putback(charVal);
			ist >> numVal;
			tokenVec.push_back(Token{ numVal });
		}
		else if (isalpha(charVal))
		{										// get the identifier name
			std::string varVal{ charVal };
			while (ist >> charVal && isalnum(charVal))		// identifier can only be alphanumeric
			{
				varVal += charVal;
			}
			ist.putback(charVal);
			tokenVec.push_back(Token{ varVal });
		}
		else
			tokenVec.push_back(Token{ charVal });
	}
}