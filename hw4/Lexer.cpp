#include "Lexer.h"
#include <cctype>

using std::pair;
using std::cout;
using std::cin;
using std::endl;

int Lexer::line = 1;

Lexer::Lexer()
{		
	reserve( mm( new Word( "if"	, Tag::IF 	) ) );
	reserve( mm( new Word( "else"	, Tag::ELSE 	) ) );
	reserve( mm( new Word( "while"	, Tag::WHILE	) ) );
	reserve( mm( new Word( "do"		, Tag::DO		) ) );
	reserve( mm( new Word( "break"	, Tag::BREAK 	) ) );
	reserve( (Word*)&Word::True	 );
	reserve( (Word*)&Word::False );
	reserve( (Word*)&Type::Int	 );
	reserve( (Word*)&Type::Char	 );
	reserve( (Word*)&Type::Bool	 );
	reserve( (Word*)&Type::Float );
}

Lexer::~Lexer()
{
	while( !collector.empty() )
	{
		//cout << "Free : " << collector.back()->toString() <<endl;
		delete collector.back();
		collector.pop_back();
	}
}

Token* Lexer::scan()
{
	// skip white space
	for(;;readch())
	{
		if( peek == ' ' || peek == '\t' || peek == '\r' )
			continue;
		else if( peek == '\n' )
			line++;
		else
			break;			
	}
	
	switch( peek )
	{
	case '&':
		if( readch('&') )
			return ( Token* )&Word::And;
		else
			return mm( new Token('&') );
	case '|':
		if (readch('|'))
			return ( Token* )&Word::Or;
		else
			return mm( new Token('|') );
	case '=':
		if (readch('='))
			return ( Token* )&Word::eq;
		else
			return mm( new Token('=') );
	case '!':
		if (readch('='))
			return ( Token* )&Word::ne;
		else
			return mm( new Token('!') );
	case '<':
		if (readch('='))
			return ( Token* )&Word::le;
		else
			return mm( new Token('<') );
	case '>':
		if (readch('='))
			return ( Token* )&Word::ge;
		else
			return mm( new Token('>') );
	}
	
	if( isdigit( peek ) )
	{
		int v = 0;
		do
		{
			v = 10 * v + peek - '0';
			readch();
		}while( isdigit( peek ) );
		if( peek != '.' )
			return mm( new Num( v ) );
		float x = v;
		float d = 10;
		for(;;)
		{
			readch();
			if( !isdigit( peek ) )
				break;
			x = x + ( peek - '0' ) / d;
			d *= 10;
		}
		return mm( new Real( x ) );
	}
	
	if( isalpha( peek ) )
	{
		string s = "";
		do
		{
			s += peek;
			readch();
		}while( isalpha( peek ) || isdigit( peek ) );
		
		if( words[s] != nullptr )
			return words[s];
		Word *w = mm( new Word( s, Tag::ID ) );
		words.insert( pair<string,Word*>( s, w ) );
		return w;
	}
	
	Token *tok = mm( new Token( peek ) );
	peek = ' ';
	return tok;
}


Word* Lexer::mm( Word* w )
{
	collector.push_back( w );
	return w;
}

Token* Lexer::mm( Token* t )
{
	collector.push_back( t );
	return t;
}
	
Num* Lexer::mm( Num* t )
{
	collector.push_back( t );
	return t;
}
Real* Lexer::mm( Real* t )
{
	collector.push_back( t );
	return t;
}
	
void Lexer::readch()
{
	int i = cin.get();
	if( i != -1 )
		peek = ( char )i;
	else
	{		
		throw 87;	
	}
}
bool Lexer::readch( char c )
{
	readch();
	if( peek != c )
		return false;
	peek = ' ';
	return true;
}
	
void Lexer::reserve(Word* w)
{
	words.insert( pair<string,Word*>( w->lexeme, w ));
}
