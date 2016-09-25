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
	//makes sure the next character is valid by deciding
	//if it can follow the previous character that was 
	//in the string (last_pushed)...takes in the string stream
	//and deciphers the expression in order to decide what the
	//next character is meant to be
	string nextToken(istringstream& tokens, string last_pushed);
private:

};

#endif