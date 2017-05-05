#include "Type.h"
#include "Tag.h"

const Type Type::Int("int", Tag::BASIC, 4);
const Type Type::Float("float", Tag::BASIC, 8);
const Type Type::Char("char", Tag::BASIC, 1);
const Type Type::Bool("bool", Tag::BASIC, 1);

bool Type::numeric( Type p )
{
	if( p == Char || p == Int || p == Float )
		return true;
	else
		return false;
}

Type Type::max( Type p1, Type p2 )
{
	if( !numeric(p1) || !numeric(p2) )
		return Type( "NULL", -1, -1 );
	else if( p1 == Float || p2 == Float )
		return Float;
	else if( p1 == Int || p2 == Int )
		return Int;
	else
		return Char;
}

bool Type::operator==( Type t )
{
	return Word::operator==( t ) && this->width == t.width;
}