#include "Infix_Evaluator.h"

const string OPERATORS[] = { "||", "&&", "==", "!=", "<", ">", ">=", "<=", "+", "-", "*", "/" , "%", "^", "-", "--", "++", "!", "(", ")" };
const int PRECEDENCE[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8, 0, 0 };

int Infix_Evaluator::evaluate(string expression)
{
	stack<int> operands;
	stack<string> operators;
	istringstream tokens(expression);
	String_Tokenizer tokenizer;
	string token;
	while (!tokens.eof())
	{
		token = tokenizer.nextToken(tokens);
		cout << token << endl;
		if (getPrecedence(token) < 0)
			operands.push(atoi(token.c_str()));
		cout << operands.top();
	}
	return 0;
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