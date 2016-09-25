#ifndef INFIX_EVALUATOR_H
#define INFIX_EVALUATOR_H

#include <string>
#include "String_Tokenizer.h"
#include <stack>
#include <iostream>

using namespace std;

class Infix_Evaluator
{
private:
	//stacks to hold operands and operators
	stack<int> operands;
	stack<string> operators;

	//returns the precedence of a passed in operator
	int getPrecedence(string op);
	//performs operation determined by top item on operator stack
	void operate();

public:
	//evaluates (if possible) a string of an infix expression
	int evaluate(string expression);

};

#endif