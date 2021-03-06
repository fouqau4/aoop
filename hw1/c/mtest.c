#include <stdio.h>
#include <stdlib.h>

static int remained = 0;

void* mymalloc( size_t size, const char *file, int line, const char *func )
{
	void *r = ( void * )malloc( size );
	remained++;
	printf("\tAllocated = %s, %i, %s, %p[%li]\n", file, line, func, r, size );
	return r;
}
void myfree( void* ptr, const char *file, int line, const char *func )
{
	printf("\tDeallocated = %s, %i, %s, %p\n \
			\tStill %d remained !! \n", file, line, func, ptr, --remained );
	free( ptr );
}
