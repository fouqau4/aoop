#include<iostream>
#include<iomanip>
#include "Lexer.h"

#define MAX_WIDTH 3

using std::cout;
using std::endl;
using std::setw;

int main()
{
	Lexer lexer;	
	try
	{
		while(1)
		{
			Token *t = lexer.scan();			
			cout << "\033[1;30;m[ Line" << setw(MAX_WIDTH) << lexer.line << " ]\033[0m  " 
				 << "\tToken: " << t->toString()<< endl;
		}
		
	}
	catch( int e )
	{
		cout << "Reach Eof" << endl;
	}
		
	return 0;
}