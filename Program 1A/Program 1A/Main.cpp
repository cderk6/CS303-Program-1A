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
<<<<<<< HEAD
		result = evaluate.evaluate("3+++ 2");
=======
		result = evaluate.evaluate("-++---5");
>>>>>>> 9d4912adeb114eb12835a31a32e8ecbcbc8e931e
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