all: stack_1 stack_2

stack_2: stack.o main2.o
	g++ stack.o main2.o -o stack2
main2.o: main2.c
	g++ -std=c++11 -c main2.c

stack_1: stack.o main.o
	g++ stack.o main.o -o stack1
main.o: main.c
	g++ -std=c++11 -c main.c

stack.o: stack.c
	g++ -std=c++11 -c stack.c

clean:
	rm -f *.o stack1 stack2
