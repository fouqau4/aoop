#ifndef _my_TYPE_in_cpp_
#define _my_TYPE_in_cpp_

#include "Word.h"

class Type : public Word
{
public:
	int width = 0;
	Type( string s, int tag, int w ) : Word( s, tag ), width(w){}
	static const Type
		Int,
		Float,
		Char,
		Bool;
		
	bool operator==( Type t );
	
	static bool numeric( Type p );
	static Type max( Type p1, Type p2 );
};





#endif