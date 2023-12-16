CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Grafo.o $(OBJ)/Sorts.o 
HDRS = $(INC)/Grafo.hpp $(INC)/Node.hpp $(INC)/Sorts.hpp
CFLAGS = -Wall -g -c -I$(INC) -std=c++11

EXE = $(BIN)/tp2.out

.PHONY: all clean

run: all
	$(EXE)

all: $(EXE)

$(BIN)/tp2.out: $(OBJS)
	$(CC) -std=c++11 -g -o $(BIN)/tp2.out $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Grafo.o: $(HDRS) $(SRC)/Grafo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Grafo.o $(SRC)/Grafo.cpp

$(OBJ)/Sorts.o: $(HDRS) $(SRC)/Sorts.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Sorts.o $(SRC)/Sorts.cpp


clean:
	rm -f $(EXE) $(OBJS) gmon.out
