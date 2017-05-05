#ifndef _my_WORD_in_cpp_
#define _my_WORD_in_cpp_

#include "Token.h"

#include <iostream>
using namespace std;

class Word : public Token {
public:
	string lexeme = "";
	int tg;
	Word(){};
	Word( string s, int tag ):lexeme( s ), Token( tag ), tg( tag ){}
	virtual string toString();
	
	bool operator==( Word w );
	
	static const Word 
		And,
		Or,
		eq,
		ne,
		le,
		ge,
		minus,
		True,
		False,
		temp;		
};







#endif