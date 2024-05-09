#include "ProcessComp.h"


double add_sub(std::vector<Token>& tokVec, unsigned int& i)
{
	double val = div_mult(tokVec, i);
	static int brack = 0;
	
	while (i < (tokVec.size() - 1))					// excluding the terminator (;)
	{
		switch (tokVec[i].getValue().charVal)
		{
		case '+':	case '-':
			val += div_mult(tokVec, i);
			break;

		case ')':
			bracket_check(val, "Opening bracket '(' missing");

		default:
			//return val;
			expression_error("Unknown identifier(s)");
		}
	}
	return val;
}

double div_mult(std::vector<Token>& tokVec, unsigned int& i)
{
	double val = primary(tokVec, i);

	while (i < (tokVec.size() - 1))					// excluding the terminator (;)
	{
		switch (tokVec[i].getValue().charVal)
		{
		case '*':
			val *= primary(tokVec, ++i);
			break;

		case '/':
			val /= primary(tokVec, ++i);
			break;

		case '%':
			val = (int) val % (int) primary(tokVec, ++i);
			break;

		case'(':						// bracket without any sign added infront automatically evaluates as multipication
			val *= primary(tokVec, i);
			break;

		default:
			return val;
		}
			//val = primary(tokVec, i);
	}
	return val;
}

double primary(std::vector<Token>& tokVec, unsigned int& i)
{
	double val;
	if (i < (tokVec.size() - 1))					// excluding the terminator (;)
	{
		if ((tokVec[i].getType() == Type::oprator))
		{
			switch (tokVec[i].getValue().charVal)
			{
			case '+':
				val = primary(tokVec, ++i);
				return val;

			case '-':
				val = -primary(tokVec, ++i);
				return val;

			case '(':
				try
				{
					add_sub(tokVec, ++i);
				}
				catch (BracketCheck& bc)
				{
					++i;
					return bc.val;
				}
				//if (tokVec[i].getValue().charVal == ')') ++i;
				expression_error("Enclosing bracket ')' missing");
				//return val;

			default:
				expression_error("Incorrect expression");
			}
		}
		else
		{
			val = tokVec[i].getValue().realVal;
			++i;
		}
	}
	return val;
}

































