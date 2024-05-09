#include "ProcessComp.h"


double add_sub(std::vector<Token>& tokVec, unsigned int& i)
{
	double val = div_mult(tokVec, i);
	static int brack = 0;

	while (i < (tokVec.size() - 1))		 // excluding the terminator (;)
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
	double val = expo(tokVec, i);

	while (i < (tokVec.size() - 1))	// excluding the terminator (;)
	{
		switch (tokVec[i].getValue().charVal)
		{
		case '*':
			val *= expo(tokVec, ++i);
			break;

		case '/':
			val /= expo(tokVec, ++i);
			break;

		case '%':
			val = (int) val % (int) expo(tokVec, ++i);
			break;

		case'(': // bracket without any sign added infront automatically
			//evaluates as multipication
			val *= expo(tokVec, i);
			break;

		default:
			return val;
		}
			//val = primary(tokVec, i);
	}
	return val;
}

double expo(std::vector<Token>& tokVec, unsigned int& i)
{
	double val = primary(tokVec, i);

	while (i < (tokVec.size() - 1))	// excluding the terminator (;)
	{
		switch (tokVec[i].getValue().charVal)
		{
		case '^':
			val = pow(val, primary(tokVec, ++i));
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
	if (i < (tokVec.size() - 1))   	// excluding the terminator (;)
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
		else if((tokVec[i].getType() == Type::strng))
		{
			switch (tokVec[i].getValue().strVal)
			{
			case Trig::rsin:
					val = primary(tokVec, ++i);
					return sin(val);

			case Trig::rcos:
					val = primary(tokVec, ++i);
					return cos(val);

			case Trig::rtan:
					val = primary(tokVec, ++i);
					return tan(val);

			case Trig::rasin:
					val = primary(tokVec, ++i);
					return asin(val);

			case Trig::racos:
					val = primary(tokVec, ++i);
					return acos(val);

			case Trig::ratan:
					val = primary(tokVec, ++i);
					return atan(val);

			case Trig::mlog:
					val = primary(tokVec, ++i);
					return log(val);

			case Trig::mlog10:
					val = primary(tokVec, ++i);
					return log10(val);

			case Trig::mlog2:
					val = primary(tokVec, ++i);
					return log2(val);

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
