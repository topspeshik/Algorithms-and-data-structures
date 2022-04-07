CXX=g++


ifeq ($(OS), Windows_NT)
	MAIN:= main.exe
	RM:=del
else
	MAIN=: ./main
	RM:=rm
endif

all: 
	$(CXX)  main.cpp -o main

	
clean:
	$(RM) *.o *.gch main.exe

run: all
	$(MAIN) > out.txt
	python main.py > out2.txt
	python graph.py < out.txt
	python graph.py < out2.txt
