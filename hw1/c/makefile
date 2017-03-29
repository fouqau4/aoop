all: stack_1 stack_2

stack_1: stack.o main.o mtest.o
	gcc mtest.o stack.o main.o -o stack1
main.o: main.c
	gcc -c -Wall main.c

stack_2: stack.o main2.o mtest.o
	gcc mtest.o stack.o main2.o -o stack2
main2.o: main2.c
	gcc -c -Wall main2.c

stack.o: mtest.o stack.c
	gcc -c -Wall stack.c
mtest.o: mtest.c
	gcc -c -Wall mtest.c

dep:
	gcc -M stack.c mtest.c main.c main2.c > depend
clean:
	rm -f *.o stack1 stack2 depend
