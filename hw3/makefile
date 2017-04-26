all:complex

complex: Complex.o main.o 
	g++ -std=c++11 -o complex_test main.o Complex.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
Complex.o:Complex.cpp
	g++ -std=c++11 -c Complex.cpp	
dep:
	g++ -M main.cpp Complex.cpp > depend
clean:
	rm -f *.o complex_test depend
