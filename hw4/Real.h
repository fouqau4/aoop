#ifndef _my_REAL_in_cpp_
#define _my_REAL_in_cpp_

#include "Token.h"
#include "Tag.h"

class Real : public Token
{
public:
	const float value;
	Real( float v ): Token( Tag::REAL ), value( v ){}
	string toString();
	
};

#endif