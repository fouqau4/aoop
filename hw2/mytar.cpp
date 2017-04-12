#include "mytar.h"

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using std::ios;
using std::endl;
using std::cout;

const char* which_mode( char c );

void list_content( char* filename )
{
	if( filename[0] == '/' )
		filename++; 
	ifstream tar( filename, ios::binary );

    class T tar_file;
	unsigned int size, blocks;
	while( !tar.eof() )
	{

        tar_file.read_header( tar );
		if( tar_file.is_padding() == 0 )
			continue;
		if( tar_file.is_tar() != 0 )
		{
			cout << "Not a ustar file" << endl 
				 << "File opening error." << endl;
			break;
		}

        tar_file.parse_header();
        tar_file.show_info();

		size = tar_file.get_filesize();
		blocks = size / 512;
		if( (size %= 512) > 0 )
			blocks++;
		tar.seekg( blocks*512, tar.cur );

	}
	tar.close();
}

int T::is_tar()
{
	string s = header.USTAR_id;
	return s.compare( "ustar  " );
}

int T::is_padding()
{
	unsigned int s = sizeof( struct TarHeader );
	char z[s];
	memset( z, 0, s );
	return memcmp( &header, z, s );
}

void T::read_header( ifstream& i )
{
    i.read( (char*)&header,
            sizeof( struct TarHeader ) );
}

void T::parse_header()
{

	info = "";
		
	info += which_type();
	parse_filemode();
    parse_name_n_size();
    parse_time();
	info += get_filename();

}

unsigned int T::get_filesize()
{
    sscanf( header.filesize, "%o", &this->filesize );
    return this->filesize;
}

const char* T::get_filename()
{
    return header.filename;
}

const char* T::get_username()
{
    return header.username;
}

const char* T::get_groupname()
{
    return header.groupname;
}

char T::which_type()
{
	switch( header.type )
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

void T::parse_filemode()
{
	for( int i = 4 ; i < 7 ; i++ )
		info += which_mode( header.filemode[i] );
	info += " ";
}

void T::parse_name_n_size()
{
	unsigned nlen = this->info.length(), slen;

	this->info += get_username();	
	info += "/"; 
	info += get_groupname();
	nlen = info.length() - nlen;
	
	char fs[15];
	sprintf( fs, "%u", get_filesize() );
	string fsize = fs;
	slen = fsize.length();

	for( int i = 0 ; i < 19 - nlen - slen ; i++ )
		info += " ";

	info += fsize + " ";

}

void T::parse_time()
{
    time_t t;
	t = strtol( header.mtime, NULL, 8 );
	struct tm *timeinfo = localtime(&t);
	char arr[20];
	strftime( arr, 20, "%Y-%m-%d %R", timeinfo );
    info += arr;
    info += " ";
}

void T::show_info()
{
    cout << info << endl;
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
