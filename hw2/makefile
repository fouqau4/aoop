all: mytar

mytar: main.o mytar.o
	g++ -std=c++11 -o mytar main.o mytar.o
main.o: main.cpp 
	g++ -std=c++11 -c main.cpp
mytar.o: mytar.cpp
	g++ -std=c++11 -c mytar.cpp
dep:
	g++ -M main.cpp mytar.cpp > depend
clean:
	rm -f *.o mytar depend

