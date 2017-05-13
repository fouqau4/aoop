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
	vector<Token*> collector, rsv;
	
	Word* mm( vector<Token*>& v, Word* w );
	Token* mm( vector<Token*>& v, Token* t );
	Num* mm( vector<Token*>& v, Num* t );
	Real* mm( vector<Token*>& v, Real* t );
	void free_all();
	void free_collector( vector<Token*>& v );

	void readch();
	bool readch( char c );	
	void reserve(Word* w);
};


#endif