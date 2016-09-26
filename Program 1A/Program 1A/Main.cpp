// Justin Orpin & Connor Eaton
// Program 1A

#include "Infix_Evaluator.h"
#include <string>

int main()
{
	Infix_Evaluator evaluate;
	int result;
	int index = 0;
	//evaluate passed in string infix expression
	//catch and output bad logic input by user
	try
	{
		result = evaluate.evaluate("1+2*3", index);
	}
	catch (const logic_error e)
	{
		cerr << e.what() << " @ char " << index - 1 << endl;
		system("pause");
		exit(0);
	}
	cout << "The answer is " << result << endl;
	system("pause");
	return 0;
}