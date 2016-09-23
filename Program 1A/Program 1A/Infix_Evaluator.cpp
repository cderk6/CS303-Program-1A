#include "Infix_Evaluator.h"
#include <algorithm>

const string OPERATORS[] = { "||", "&&", "==", "!=", "<", ">", ">=", "<=", "+", "-",
								"*", "/" , "%", "^", "-", "--", "++", "!", "(", ")" };
const int PRECEDENCE[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, 0, 0 };

int Infix_Evaluator::evaluate(string expression)
{
	stack<int> operands;
	stack<string> operators;
	// Remove all whitespace from expression
	expression.erase(remove_if(expression.begin(), expression.end(), isspace), expression.end());
	istringstream tokens(expression);
	String_Tokenizer tokenizer;
	string token, last_pushed = "";
	char test;
	while (tokens >> test)
	{
		tokens.putback(test);
		token = tokenizer.nextToken(tokens, last_pushed);
		cout << token;
		// If operand, convert to int and push onto operand stack
		if (getPrecedence(token) < 0)
			operands.push(atoi(token.c_str()));
		// Handle parentheses
		else if (getPrecedence(token) == 0)
		{
			if (token == "(")
				operators.push(token);
			else
			{
				while (operators.top() != "(")
				{
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
							operands.push(lhs / rhs);
						else if (operators.top() == "%")
							operands.push(lhs % rhs);
						else if (operators.top() == "^")
							operands.push(pow(lhs, rhs));
					}
					operators.pop();
					// If it's empty, no matching opening paranthesis was found
					if (operators.empty())
						throw logic_error("No opening parenthesis found to match closing");
				}
				operators.pop(); // pop opening paranthesis
			}

		}
		// Else, it's an operator
		else
		{
			bool operator_pushed = false;
			do
			{
				if (operators.empty() || getPrecedence(token) == 8)
				{
					operators.push(token);
					operator_pushed = true;
				}
				else if (getPrecedence(token) > getPrecedence(operators.top()))
				{
					operators.push(token);
					operator_pushed = true;
				}
				else
				{
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
							operands.push(lhs / rhs);
						else if (operators.top() == "%")
							operands.push(lhs % rhs);
						else if (operators.top() == "^")
							operands.push(pow(lhs, rhs));
					}
					operators.pop();
				}
			} while (!operator_pushed);
		}
		if (!operands.empty())
			cout << "   Top: " << operands.top();
		if (!operators.empty())
			cout << " and " << operators.top();
		cout << endl;
		last_pushed = token;
	}
	while (!operands.empty() && !operators.empty())
	{
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
				operands.push(lhs / rhs);
			else if (operators.top() == "%")
				operands.push(lhs % rhs);
			else if (operators.top() == "^")
				operands.push(pow(lhs, rhs));
		}
		operators.pop();

		if (!operands.empty())
			cout << "   Top: " << operands.top();
		if (!operators.empty())
			cout << " and " << operators.top();
		cout << endl;
	}
	return operands.top();
}

int Infix_Evaluator::getPrecedence(string op)
{
	for (int i = 0; i < 20; i++)
	{
		if (OPERATORS[i] == op)
			return PRECEDENCE[i];
	}
	return -1;
}