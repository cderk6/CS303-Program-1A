#include "Infix_Evaluator.h"

const string OPERATORS[] = { "||", "&&", "==", "!=", "<", ">", ">=", "<=", "+", "-", "*", "/" , "%", "^", "-", "--", "++", "!" };
const int PRECEDENCE[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8 };

int Infix_Evaluator::evaluate(string& expression)
{
	stack<int> operands;
	stack<string> operators;
	while (!expression.empty())
	{
		// String_Tokenizer tokenizer;
		// string token = tokenizer.nextToken(expression);
		// if (!token.isOperator())
		//	

	}
}

int Infix_Evaluator::isOperator(string op)
{
	for (int i = 0; i < 18; i++)

}