// Justin Orpin & Connor Eaton
// Program 1A

#include "Infix_Evaluator.h"
#include <string>

int main()
{
	Infix_Evaluator evaluate;
	int result;
	//evaluate passed in string infix expression
	//catch and output bad logic input by user
	try
	{
		result = evaluate.evaluate("5+++++5");
	}
	catch (const logic_error e)
	{
		cerr << e.what() << endl;
		system("pause");
		exit(0);
	}
	cout << "The answer is " << result << endl;
	system("pause");
	return 0;
}