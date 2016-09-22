#include "Infix_Evaluator.h"

const string OPERATORS[] = { "||", "&&", "==", "!=", "<", ">", ">=", "<=", "+", "-", "*", "/" , "%", "^", "-", "--", "++", "!" };
const int PRECEDENCE[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8 };

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
	}
	return 0;
}

int Infix_Evaluator::isOperator(string op)
{
	//for (int i = 0; i < 18; i++)
	return 0;
}