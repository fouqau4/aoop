#include <stdlib.h>
#include "stack.h"
#include "mtest.h"

void push(struct stack* this, int x)
{
	struct stack *node = malloc( sizeof( struct stack ) );
	node->data = x;
	node->next = this->next;
	this->next = node;
}

int pop(struct stack* this)
{
	struct stack *temp = this->next;
	int r = temp->data;
	this->next = temp->next;
	free( temp );
	return r;
}

struct stack* new_stack()
{
	struct stack *node = ( struct stack* )malloc( sizeof( struct stack ) );
	node->next = NULL;
	return node;
}

void delete_stack(struct stack* stk)
{
	struct stack *temp;
	while( stk != NULL )
	{
		temp = stk;
		stk = stk->next;
		free( temp );
	}
}
