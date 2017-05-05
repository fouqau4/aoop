TGT := my_scanner

CC := gcc
CXX := g++
CFLAGS := -g -Wall -o3 -std=gnu99
CXXFLAGS :=  -std=c++11
LDFLAGS := -g
LDLIBS := -lstdc++

SRC := 	my_scanner.cpp \
		Lexer.cpp \
		Word.cpp \
		Num.cpp \
		Real.cpp \
		Token.cpp \
		Type.cpp \
		Tag.cpp
OBJ := $(SRC:.cpp=.o)		

all: $(TGT)

$(TGT): $(OBJ)

.PHONY: dep clean
dep:
	$(CC) -M main.cpp Lexer.cpp Word.cpp Num.cpp Real.cpp Token.cpp Type.cpp Tag.h > depend
clean:
	@rm -f $(OBJ) $(TGT) depend
