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
	
	//performs operation determined by top item on operator stack
	void operate();
	//returns the precedence of a passed in operator
	int getPrecedence(string op);

public:
	//evaluates (if possible) a string of an infix expression
	int evaluate(string expression, int& index);

};

#endif