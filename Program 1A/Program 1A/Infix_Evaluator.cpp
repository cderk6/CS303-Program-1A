#include "Infix_Evaluator.h"

const string OPERATORS[] = { "||", "&&", "==", "!=", "<", ">", ">=", "<=", "+", "-",
								"*", "/" , "%", "^", "-", "--", "++", "!", "(", ")" };
const int PRECEDENCE[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, 0, 0 };

int Infix_Evaluator::evaluate(string expression)
{
	stack<int> operands;
	stack<string> operators;
	istringstream tokens(expression);
	String_Tokenizer tokenizer;
	string token, last_pushed = "";
	while (!tokens.eof())
	{
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
					else if (operators.top() == "++")
					{
						operands.push(lhs);
						operands.push(++rhs);
					}
					operators.pop();
					// If it's empty, no matching opening paranthesis was found
					if (operators.empty())
						break;
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
					else if (operators.top() == "++")
					{
						operands.push(lhs);
						operands.push(++rhs);
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
		else if (operators.top() == "++")
		{
			operands.push(lhs);
			operands.push(++rhs);
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