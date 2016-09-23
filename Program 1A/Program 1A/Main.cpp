// Justin Orpin & Connor Eaton
// Program 1A

#include "Infix_Evaluator.h"
#include <string>

int main()
{
	Infix_Evaluator evaluate;
	int result;
	result = evaluate.evaluate("++3");
	cout << "The answer is " << result << endl;
	system("pause");
	return 0;
}