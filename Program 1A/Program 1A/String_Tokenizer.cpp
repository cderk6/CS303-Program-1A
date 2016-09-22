#include "String_Tokenizer.h"

string String_Tokenizer::nextToken(istringstream& tokens)
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
	if (next_char == '+')
	{
		return "+";
	}
	if (next_char == '-')
	{
		return "-";
	}
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
			cerr << next_char << " not allowed.";
			return "";
		}
	}
}