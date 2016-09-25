#include "Infix_Evaluator.h"
#include <algorithm>

const string OPERATORS[] = { "||", "&&", "==", "!=", "<", ">", ">=", "<=", "+", "-",
								"*", "/" , "%", "^", "neg", "--", "++", "!", "(", ")" };
const int PRECEDENCE[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, 0, 0 };

int Infix_Evaluator::evaluate(string expression)
{
	// Remove all whitespace from expression
	expression.erase(remove_if(expression.begin(), expression.end(), isspace), expression.end());
	//convert string to string stream object in order to easily manipulate the expression
	istringstream tokens(expression);
	String_Tokenizer tokenizer;
	string token, last_pushed = "";
	char test;
	while (tokens >> test)
	{
		//there was another character, now replace the character to properly tokenize it
		tokens.putback(test);
		token = tokenizer.nextToken(tokens, last_pushed);
		cout << token;
		// handle operands, convert to int and push onto operand stack
		if (getPrecedence(token) < 0)
			operands.push(atoi(token.c_str()));
		// handle parentheses
		else if (getPrecedence(token) == 0)
		{
			if (token == "(")
				operators.push(token);
			//token is a closing parenthesis...evaluate until hitting opening parenthesis
			else
			{
				while (operators.top() != "(")
				{
					//operate using top operator of operator stack
					operate();
					// If it's empty, no matching opening paranthesis was found
					if (operators.empty())
						throw logic_error("No opening parenthesis found to match closing");
				}
				//pop opening paranthesis
				operators.pop();
			}
		}
		//handle all other operators
		else
		{
			bool operator_pushed = false;
			//evaluate top operator until able to push current operator
			do
			{
				//push if operator stack is empty or operator has highest possible precedence
				if (operators.empty() || getPrecedence(token) == 8)
				{
					operators.push(token);
					operator_pushed = true;
				}
				//push if token has higher precedence than current top of operator stack
				else if (getPrecedence(token) > getPrecedence(operators.top()))
				{
					operators.push(token);
					operator_pushed = true;
				}
				//evaluate the top operator
				else
				{
					//operate using top operator of operator stack
					operate();
				}
			} while (!operator_pushed);
		}
		if (!operands.empty())
			cout << "   Top: " << operands.top();
		if (!operators.empty())
			cout << " and " << operators.top();
		cout << endl;
		//save the token to pass to tokenizer as the last token pushed
		last_pushed = token;
	}
	//when here, there is no more characters to read from expression,
	//so evaluate until both stacks are empty
	while (!operands.empty() && !operators.empty())
	{
		//operate using top operator of operator stack
		operate();
		if (!operands.empty())
			cout << "   Top: " << operands.top();
		if (!operators.empty())
			cout << " and " << operators.top();
		cout << endl;
	}
	//one number left in operand stack is the answer
	return operands.top();
}

int Infix_Evaluator::getPrecedence(string op)
{
	//iterate through OPERATORS array, return corresponding
	//precedence in PRECEDENCE array
	for (int i = 0; i < 20; i++)
	{
		if (OPERATORS[i] == op)
			return PRECEDENCE[i];
	}
	//op is actually an operand
	return -1;
}

void Infix_Evaluator::operate()
{
	//handle unary operators
	if (getPrecedence(operators.top()) == 8)
	{
		int rhs = operands.top();
		operands.pop();
		if (operators.top() == "++")
			operands.push(++rhs);
		else if (operators.top() == "--")
			operands.push(--rhs);
		else if (operators.top() == "neg")
			operands.push(-rhs);
		else if (operators.top() == "!")
			operands.push(!rhs);
	}
	//handle binary operators
	else
	{
		int rhs = operands.top();
		operands.pop();
		int lhs = operands.top();
		operands.pop();
		if (operators.top() == "||")
			operands.push(lhs || rhs);
		else if (operators.top() == "&&")
			operands.push(lhs && rhs);
		else if (operators.top() == "!=")
			operands.push(lhs != rhs);
		else if (operators.top() == "==")
			operands.push(lhs == rhs);
		else if (operators.top() == "<")
			operands.push(lhs < rhs);
		else if (operators.top() == ">")
			operands.push(lhs > rhs);
		else if (operators.top() == ">=")
			operands.push(lhs >= rhs);
		else if (operators.top() == "<=")
			operands.push(lhs <= rhs);
		else if (operators.top() == "+")
			operands.push(lhs + rhs);
		else if (operators.top() == "-")
			operands.push(lhs - rhs);
		else if (operators.top() == "*")
			operands.push(lhs * rhs);
		else if (operators.top() == "/")
		{
			if (rhs == 0)
			{
				throw logic_error("Can't divide by zero.");
			}
			operands.push(lhs / rhs);
		}
		else if (operators.top() == "%")
			operands.push(lhs % rhs);
		else if (operators.top() == "^")
			operands.push(pow(lhs, rhs));
	}
	operators.pop();
}