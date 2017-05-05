all: my_scanner

my_scanner: main.o Lexer.o Word.o Num.o Real.o Token.o Type.o
	g++ -std=c++11 -o my_scanner main.o Lexer.o Word.o Num.o Real.o Token.o Type.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Lexer.o: Lexer.cpp
	g++ -std=c++11 -c Lexer.cpp
Word.o: Word.cpp
	g++ -std=c++11 -c Word.cpp
Num.o: Num.cpp
	g++ -std=c++11 -c Num.cpp
Real.o: Real.cpp
	g++ -std=c++11 -c Real.cpp
Token.o: Token.cpp
	g++ -std=c++11 -c Token.cpp
Type.o: Type.cpp
	g++ -std=c++11 -c Type.cpp

dep:
	g++ -M main.cpp Lexer.cpp Word.cpp Num.cpp Real.cpp Token.cpp Type.cpp Tag.h > depend
clean:
	@rm -f *.o my_scanner depend
