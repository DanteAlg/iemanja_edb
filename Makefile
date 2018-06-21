# Compiler
CC = g++

INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/main.o $(OBJ)/expressao_validador.o $(OBJ)/expressao_executor.o
PROG = iemanja

all: prepare $(PROG)

$(OBJ)/expressao_validador.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/expressao_validador.cpp -o $@

$(OBJ)/expressao_executor.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/expressao_executor.cpp -o $@

$(OBJ)/main.o: $(OBJ)/expressao_validador.o $(OBJ)/expressao_executor.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

$(PROG): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $(BIN)/$@

prepare:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)
	@echo "Criação dos diretórios bin e obj executada!!" 

clean:
	rm -r $(OBJ)
	rm -r $(BIN)
	@echo "Remoção dos objetos e binários executada!!"