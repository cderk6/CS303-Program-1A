#include "String_Tokenizer.h"

string String_Tokenizer::nextToken(istringstream& tokens, string last_pushed)
{
	char next_char;
	tokens >> next_char;
	if (isdigit(next_char))
	{
		//put back single number and read in entire integer
		tokens.putback(next_char);
		int operand;
		tokens >> operand;
		//convert int to string to be returned
		return to_string(operand);
	}
	//can simply return these characters if they arent the first item in expression
	if (next_char == '*' || next_char == '/' || next_char == '%' ||
		next_char == '^' || next_char == '(' || next_char == ')')
	{
		//cant start with binary operator or closing parenthesis
		if (next_char != '(')
		{
			if (last_pushed == "")
				throw logic_error("Expression can't start with a closing parenthesis or binary operator");
			if (last_pushed == "!" || last_pushed == "++" || last_pushed == "--" || last_pushed == "neg")
				throw logic_error("A unary operator can't be followed by a binary operator");
		}
		string return_string;
		return_string = next_char;
		return return_string;
	}
	if (next_char == '!' || next_char == '<' || next_char == '>')
	{
		if (next_char == '<' || next_char == '>')
		{
			if (last_pushed == "")
				throw logic_error("Expression can't start with a binary operator");
			if (last_pushed[0] == next_char)
				throw logic_error("Two binary operators in a row");
			if (last_pushed == "!" || last_pushed == "++" || last_pushed == "--" || last_pushed == "neg")
				throw logic_error("A unary operator can't be followed by a binary operator");
		}
		//if followed by a =, return them as a combined token
		char next_next_char;
		tokens >> next_next_char;
		if (next_next_char == '=')
		{
			if (last_pushed == "!" || last_pushed == "++" || last_pushed == "--" || last_pushed == "neg")
				throw logic_error("A unary operator can't be followed by a binary operator");
			string first_char, second_char;
			first_char = next_char, second_char = next_next_char;
			string return_string = first_char + second_char;
			return return_string;
		}
		//if not, just return the single character
		else
		{
			tokens.putback(next_next_char);
			string return_string;
			return_string = next_char;
			return return_string;
		}
	}
	if (next_char == '+')
	{
		//if it follows an operand, return binary + sign
		if (isdigit(last_pushed[0]) || last_pushed == ")")
		{
			char next_next_char;
			//if its not the last character in the expression
			if (tokens >> next_next_char)
			{
				tokens.putback(next_next_char);
				return "+";
			}
			else
				throw logic_error("Expression cannot end with an operator");
		}
		//it is either ++ or an error
		else
		{
			char next_next_char;
			if (tokens >> next_next_char)
			{
				if (next_next_char == next_char)
					return "++";
				tokens.putback(next_next_char);
				throw logic_error("Binary operators need a lhs and rhs operand");
			}
			else
				throw logic_error("Expression cannot end with an operator");
		}
	}
	if (next_char == '-')
	{
		//if it follows an operand, return binary - sign
		if (isdigit(last_pushed[0]) || last_pushed == ")")
		{
			char next_next_char;
			if (tokens >> next_next_char)
			{
				tokens.putback(next_next_char);
				return "-";
			}
			else
				throw logic_error("Expression cannot end with an operator");
		}
		//has to be one of two unary operators "neg" or "--"
		else
		{
			char next_next_char;
			if (tokens >> next_next_char)
			{
				if (next_next_char == next_char)
					return "--";
				tokens.putback(next_next_char);
				return "neg";
			}
			else
				throw logic_error("Expression cannot end with an operator");
		}
	}
	if (next_char == '=' || next_char == '&' || next_char == '|')
	{
		if (last_pushed[0] == next_char)
			throw logic_error("Two binary operators in a row");
		if (last_pushed == "!" || last_pushed == "++" || last_pushed == "--" || last_pushed == "neg")
			throw logic_error("A unary operator can't be followed by a binary operator");

		//if character is followed by itself, combine characters and return as single token
		char next_next_char;
		tokens >> next_next_char;
		if (next_next_char == next_char)
		{
			string first_char, second_char;
			first_char = next_char, second_char = next_next_char;
			string return_string = first_char + second_char;
			return return_string;
		}
		//these characters are not valid if they aren't followed by themselves
		else
		{
			throw logic_error("Invalid operator");
			return "";
		}
	}
	//entered character is not accepted by this program
	else
		throw logic_error("Invalid character");
}