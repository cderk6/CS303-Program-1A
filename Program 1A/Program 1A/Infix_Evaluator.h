#ifndef INFIX_EVALUATOR_H
#define INFIX_EVALUATOR_H

#include <string>
#include "String_Tokenizer.h"
#include <stack>

using namespace std;

class Infix_Evaluator
{
private:
	int isOperator(string op);

public:
	int evaluate(string& expression);

};

#endif