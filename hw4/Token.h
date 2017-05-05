#ifndef _my_TOKEN_in_cpp_
#define _my_TOKEN_in_cpp_

#include <string>

using std::string;

class Token {
public:
	Token():tag(-1){};
	Token( int t ):tag(t){};
	virtual string toString();
	bool operator==( Token t );
private:	
	const int tag;
};



#endif