#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

class String_Tokenizer
{
public: 
	string nextToken(istringstream& tokens, string last_pushed);
private:

};

#endif