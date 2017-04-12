#ifndef _SW_MY_TAR_
#define _SW_MY_TAR_

#include "tarheader.h"
#include <string>
#include <fstream>

using std::ifstream;
using std::string;

extern void list_content( char* filename );

class T
{
public:
	T()
	{
		info = "";
    	filesize = -1;
	}
	void read_header( ifstream& i );	
	int is_tar();
	int is_padding();
	void parse_header();
	unsigned int get_filesize();
	const char* get_filename();
	const char* get_username();
	const char* get_groupname();
	void show_info();
private:
	struct TarHeader header;
	string info;
	unsigned int filesize;

	char which_type();
	void parse_filemode();
	void parse_name_n_size();
	void parse_time();

};

#endif
