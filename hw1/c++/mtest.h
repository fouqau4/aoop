#ifndef __MEM_LEAK_CHECK__
#define __MEM_LEAK_CHECK__

#include <stddef.h>

#define malloc(X) mymalloc(X,__FILE__,__LINE__,__FUNCTION__)
#define free(X) myfree(X,__FILE__,__LINE__,__FUNCTION__)

extern void* mymalloc( size_t size, const char *file, int line, const char *func );
extern void myfree( void *ptr, const char *file, int line, const char *func );


#endif
