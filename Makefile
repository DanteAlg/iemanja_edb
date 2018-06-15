# Compiler
CC = g++

INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/main.o $(OBJ)/expressao_validador.o
PROG = iemanja

all: dirs $(PROG)
	
$(OBJ)/main.o:$(OBJ)/expressao_validador.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

$(OBJ)/expressao_validador.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/expressao_validador.cpp -o $@

$(PROG): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $(BIN)/$@

dirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)
clean:
	rm -r $(OBJ)
	rm -r $(BIN)
