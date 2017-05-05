#ifndef _my_NUM_in_cpp_
#define _my_NUM_in_cpp_

#include "Token.h"
#include "Tag.h"

class Num : public Token
{
public:
	const int value;
	Num( int v ):Token( Tag::NUM ),value(v){}
	string toString();
};

#endif