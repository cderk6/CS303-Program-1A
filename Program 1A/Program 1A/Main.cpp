// Justin Orpin & Connor Eaton
// Program 1A

#include "Infix_Evaluator.h"
#include <string>

int main()
{
	Infix_Evaluator evaluate;
	int result;
	try
	{
		result = evaluate.evaluate("a");
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