#include "Token.h"

string Token::toString()
{
	return string( 1, (char)tag ) + "\t(" + (char)tag + ")";
}
	
bool Token::operator==( Token t )
{
	return this->tag == t.tag;
}