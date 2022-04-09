CC=g++

MAIN = ./Source
RM = rm
ifeq ($(OS), Windows_NT)
	MAIN:= Source.exe
	RM:=del
endif

all: Source

Source: Source.o NDArray.o 
	$(CC) Source.o NDArray.o -o Source

Source.o: Source.cpp
	$(CC) -c Source.cpp

NDArray.o: NDArray.cpp
	$(CC) -c NDArray.h NDArray.cpp


clean:
	$(RM) *.o *.gch Source.exe

run: all
	$(MAIN)