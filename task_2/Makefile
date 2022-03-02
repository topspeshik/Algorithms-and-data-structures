CXX=g++

ifeq ($(OS), Windows_NT)
	RM := del
	BINARY := main.exe
else
	RM := rm
	BINARY := ./main
endif

all:
	$(CXX) main.cpp -o main

clean:
	$(RM) *.o *.gch 

run: all
	main.exe > out.txt
	Python main.py < out.txt
