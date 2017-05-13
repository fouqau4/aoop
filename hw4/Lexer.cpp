#include "Lexer.h"
//#define _show_free_msg_
#include <cctype>

using std::pair;
using std::cout;
using std::cin;
using std::endl;

int Lexer::line = 1;

Lexer::Lexer()
{		
	reserve( mm( rsv, new Word( "if"	, Tag::IF 		) ) );
	reserve( mm( rsv, new Word( "else"	, Tag::ELSE 	) ) );
	reserve( mm( rsv, new Word( "while"	, Tag::WHILE	) ) );
	reserve( mm( rsv, new Word( "do"	, Tag::DO		) ) );
	reserve( mm( rsv, new Word( "break"	, Tag::BREAK 	) ) );
	reserve( (Word*)&Word::True	 );
	reserve( (Word*)&Word::False );
	reserve( (Word*)&Type::Int	 );
	reserve( (Word*)&Type::Char	 );
	reserve( (Word*)&Type::Bool	 );
	reserve( (Word*)&Type::Float );
}

Lexer::~Lexer()
{
	free_all();
}

Token* Lexer::scan()
{
	free_collector( collector );
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
			return mm( collector, new Token('&') );
	case '|':
		if (readch('|'))
			return ( Token* )&Word::Or;
		else
			return mm( collector, new Token('|') );
	case '=':
		if (readch('='))
			return ( Token* )&Word::eq;
		else
			return mm( collector, new Token('=') );
	case '!':
		if (readch('='))
			return ( Token* )&Word::ne;
		else
			return mm( collector, new Token('!') );
	case '<':
		if (readch('='))
			return ( Token* )&Word::le;
		else
			return mm( collector, new Token('<') );
	case '>':
		if (readch('='))
			return ( Token* )&Word::ge;
		else
			return mm( collector, new Token('>') );
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
			return mm( collector, new Num( v ) );
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
		return mm( collector, new Real( x ) );
	}
	
	if( isalpha( peek ) )
	{
		string s = "";
		do
		{
			s += peek;
			readch();
		}while( isalpha( peek ) || isdigit( peek ) );
			
		if( words.find(s) != words.end() )
			return words[s];
		Word *w = mm( rsv, new Word( s, Tag::ID ) );
		reserve( w );		
		return w;
	}
	
	Token *tok = mm( collector, new Token( peek ) );
	peek = ' ';
	return tok;
}

void Lexer::free_all()
{
	free_collector( collector );
	free_collector( rsv );
}
void Lexer::free_collector( vector<Token*>& v )
{
	while( !v.empty() )
	{
		if( v.back() != nullptr )
		{
			#ifdef _show_free_msg_
			cout << "\033[1;31;m\t\tFree : " << v.back()->toString() << "\033[0m" << endl;
			#endif
			delete v.back();
			v.back() = nullptr;
			v.pop_back();			
		}
	}
}
Word* Lexer::mm( vector<Token*>& v, Word* w )
{
	v.push_back( w );
	return w;
}

Token* Lexer::mm( vector<Token*>& v, Token* t )
{
	v.push_back( t );
	return t;
}
	
Num* Lexer::mm( vector<Token*>& v, Num* t )
{
	v.push_back( t );
	return t;
}
Real* Lexer::mm( vector<Token*>& v, Real* t )
{
	v.push_back( t );
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
