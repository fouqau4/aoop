#ifndef _my_lexer_in_cpp_
#define _my_lexer_in_cpp_

#include "Token.h"
#include "Word.h"
#include "Type.h"
#include "Tag.h"
#include "Num.h"
#include "Real.h"

#include <map>
#include <vector>
#include <iostream>

using std::vector;
using std::map;



class Lexer {
public:
	static int line;

	Lexer();
	~Lexer();
	Token* scan();
	
private:
	char peek = ' ';
	map<string,Word*> words;
	
	// memory management
	vector<Token*> collector;
	
	Word* mm( Word* w );
	Token* mm( Token* t );
	Num* mm( Num* t );
	Real* mm( Real* t );	

	void readch();
	bool readch( char c );	
	void reserve(Word* w);
};


#endif