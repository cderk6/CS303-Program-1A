#include "String_Tokenizer.h"

string String_Tokenizer::nextToken(istringstream& tokens, string last_pushed)
{
	char next_char;
	tokens >> next_char;
	//read in entire integer
	if (isdigit(next_char))
	{
		tokens.putback(next_char);
		int operand;
		tokens >> operand;
		//convert int to string to be returned
		return to_string(operand);
	}
	if (next_char == '*' || next_char == '/' || next_char == '%' ||
		next_char == '^' || next_char == '(' || next_char == ')')
	{
		if (next_char != '(')
		{
			if (last_pushed == "")
				throw logic_error("Cant start with closing parens or binary operator");
		}
		string return_string;
		return_string = next_char;
		return return_string;
	}
	if (next_char == '!')
	{
		char next_next_char;
		tokens >> next_next_char;
		if (next_next_char == '=')
		{
			string first_char, second_char;
			first_char = next_char, second_char = next_next_char;
			string return_string = first_char + second_char;
			return return_string;
		}
		else
		{
			tokens.putback(next_next_char);
			string return_string;
			return_string = next_char;
			return return_string;
		}
	}
	if (next_char == '+' || next_char == '-')
	{
		int count = 0;
		char next_next_char;
		tokens.putback(next_char);
		next_next_char = next_char;
		//count # of + signs in a row to know whether odd or even
		while (!tokens.eof() && next_next_char == next_char)
		{
			tokens >> next_next_char;
			if (next_next_char == next_char)
			{
				++count;
			}
		}
		//expression ends with a +
		if (next_next_char == next_char)
		{
			throw logic_error("Expression cannot end with an operator.");
		}
		if (isdigit(last_pushed[0]) || last_pushed == ")")
		{
			if (count % 2 == 1)
			{
				tokens.putback(next_next_char);
				for (int i = 1; i < count; i++)
				{
					tokens.putback(next_char);
				}
				string return_string;
				return_string = next_char;
				return return_string;
			}
			else
			{
				throw logic_error("Cannot have consecutive binary operators.");
			}
		}
		else
		{
			if (count % 2 == 0)
			{
				tokens.putback(next_next_char);
				for (int i = 2; i < count; i++)
				{
					tokens.putback(next_char);
				}
				string first_char;
				first_char = next_char;
				string return_string = first_char + first_char;
				return return_string;
			}
			else
			{
				throw logic_error("Need both lhs and rhs around binary operators.");
			}
		}
	}
	//if (next_char == '-')
	//{
	//	return "-";
	//}
	if (next_char == '<' || next_char == '>')
	{
		char next_next_char;
		tokens >> next_next_char;
		if (next_next_char == '=')
		{
			string first_char, second_char;
			first_char = next_char, second_char = next_next_char;
			string return_string = first_char + second_char;
			return return_string;
		}
		else
		{
			tokens.putback(next_next_char);
			string return_string;
			return_string = next_char;
			return return_string;
		}
	}
	if (next_char == '=' || next_char == '&' || next_char == '|')
	{
		char next_next_char;
		tokens >> next_next_char;
		if (next_next_char == next_char)
		{
			string first_char, second_char;
			first_char = next_char, second_char = next_next_char;
			string return_string = first_char + second_char;
			return return_string;
		}
		else
		{
			throw logic_error("Invalid operator.");
			return "";
		}
	}
	else
		throw logic_error("Invalid character");
}