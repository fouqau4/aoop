#include<iostream>
#include "Lexer.h"

using std::cout;
using std::endl;

int main()
{
	Lexer lexer;
	try
	{
		while(1)
		{
			Token *t = lexer.scan();
			cout << "Token: " << t->toString()<< endl;
		}
		
	}
	catch( int e )
	{
		cout << "Reach Eof" << endl;
	}
		
	return 0;
}