#ifndef __STACK_H__
#define __STACK_H__

class node {
public:
	node()
	{
		next = nullptr;
	}
	node( int d, node *n )
	{
		this->data = d;
		this->next = n;
	}
	int data;
	node *next;
};

class Stack {
	node *sp;
public:
	Stack()
	{
		sp = nullptr;
	}
	void push(int x)
	{
		sp = new node( x, sp );
	}
	int pop()
	{
		int d = sp->data;
		node *temp = sp;
		sp = sp->next;
		delete temp;
		return d;
	}
	~Stack()
	{
		while( sp != nullptr )
		{
			node *temp = sp;
			sp = sp->next;
			delete temp;
		}
	}
};

#endif
