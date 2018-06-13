# Compiler
CC = g++

INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/main.o

PROG = $(BIN)/iemanjao

$(OBJ)/main.o: 
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

all: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJECTS)

clean:
	rm -f $(PROG) $(OBJECTS)
