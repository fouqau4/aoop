TGT := test

CC := g++
CXXFLAGS := -g -Wall -o3 -std=c++11

SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)


all: $(TGT)

$(TGT): $(OBJ)

clean:
	rm -f $(TGT) *.o
