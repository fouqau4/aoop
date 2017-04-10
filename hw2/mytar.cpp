#include "mytar.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::ifstream;
using std::string;
using std::ios;

using std::endl;
using std::cout;

unsigned int parse_header( const struct TarHeader& tar_file );
unsigned int parse_name_n_size( string& r,
							    const struct TarHeader& tar_file );
string parse_filemode( const char* filemode );
const char* which_mode( char c );
char which_type( char c );

void list_content( const char* filename )
{
	ifstream tar( filename, ios::binary );
	struct TarHeader tar_file;
	unsigned int size, blocks;
	while( !tar.eof() )
	{
		tar.read( (char*)&tar_file, sizeof( struct TarHeader ) );
		if( tar_file.filename[0] == 0 )
			continue;		
		size = parse_header( tar_file );
		blocks = size / 512;
		if( (size %= 512) > 0 )
			blocks++;
		tar.seekg( blocks*512, tar.cur );
	}
	tar.close();
}

unsigned int parse_header( const struct TarHeader& tar_file )
{

	string r = "";
	unsigned int size;
		
	r += which_type( tar_file.type );
	r += parse_filemode( tar_file.filemode );
	size = parse_name_n_size( r, tar_file );
	r += " ";
	time_t t;
	sscanf( tar_file.mtime, "%lo", (unsigned long int*)&t);
	struct tm *timeinfo = localtime(&t);
	char arr[20];
	strftime( arr, 20, "%Y-%m-%d %R", timeinfo );
	r += arr;
	r += " ";
	r += tar_file.filename;
	cout << r << endl;
	return size;
}

unsigned int parse_name_n_size( string& r, const struct TarHeader& tar_file )
{
	unsigned nlen = r.length(), slen;

	r += tar_file.username;	
	r += "/"; 
	r += tar_file.groupname;
	nlen = r.length() - nlen;
	
	unsigned int size;
	sscanf( tar_file.filesize, "%o", &size );
	char fs[15];
	sprintf( fs, "%u", size );
	string fsize = fs;
	slen = fsize.length();

	for( int i = 0 ; i < 19 - nlen - slen ; i++ )
		r += " ";

	r += fsize;

	return size;
}

string parse_filemode( const char* filemode )
{
	string r = "";	
	for( int i = 4 ; i < 7 ; i++ )
		r += which_mode( filemode[i] );
	return r + " ";
}

char which_type( char c )
{
	switch( c )
	{
	// Normal file
	case 0:
	case '0':
	// Hard link
	case '1':
		return '-';
	// Symbolic link
	case '2':
		return 'l';
	// Character special
	case '3':
		return '-';
	// Block special
	case '4':
		return '-';
	// Directory
	case '5':
		return 'd';
	// FIFO
	case '6':
		return '-';
	// Contiguous file
	case '7':
		return '-';
	// global extend header with meta data
	case 'g':
		return '-';
	/* extended header with meta data for the next file in the
		archive */
	case 'x':
		return '-';
	}
}

const char* which_mode( char c )
{
	switch( c )
	{
	case '0':
		return "---";
	case '1':
		return "--x";
	case '3':
		return "-wx";
	case '4':
		return "r--";
	case '5':
		return "r-x";
	case '6':
		return "rw-";
	case '7':
		return "rwx";
	default:
		return "???";
	}

}
