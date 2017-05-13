#include "Word.h"
#include "Tag.h"

const Word Word::And("&&", Tag::AND);
const Word Word::Or("||", Tag::OR);
const Word Word::eq("==", Tag::EQ);
const Word Word::ne("!=", Tag::NE);
const Word Word::le("<=", Tag::LE);
const Word Word::ge(">=", Tag::GE);
const Word Word::minus("minus", Tag::MINUS);
const Word Word::True("true", Tag::TRUE);
const Word Word::False("false", Tag::FALSE);
const Word Word::temp( "t", Tag::TEMP);

#include <iostream>
using namespace std;

string Word::toString()
{
	string type;
	
	switch( Word::tg )
	{
	case 256:
		type = "AND";
		break;
	case 257:
		type = "BASIC";
		break;
	case 258:
		type = "BREAK";
		break;
	case 259:
		type = "DO";
		break;
	case 260:
		type = "ELSE";
		break;
	case 261:
		type = "EQ";
		break;
	case 262:
		type = "FALSE";
		break;
	case 263:
		type = "GE";
		break;
	case 264:
		type = "ID";
		break;
	case 265:
		type = "IF";
		break;
	case 266:
		type = "INDEX";
		break;
	case 267:
		type = "LE";
		break;
	case 268:
		type = "MINUS";
		break;
	case 269:
		type = "NE";
		break;
	case 270:
		type = "NUM";
		break;
	case 271:
		type = "OR";
		break;
	case 272:
		type = "REAL";
		break;
	case 273:
		type = "TEMP";
		break;
	case 274:
		type = "TURE";
		break;
	case 275:
		type = "WHILE";
		break;
	default:
		type = "BASIC";
		break;
	}
	
	return lexeme + "\t\t(" + type + ")";
}

bool Word::operator==( Word w )
{
	return Token::operator==( w ) && this->lexeme == w.lexeme;
}