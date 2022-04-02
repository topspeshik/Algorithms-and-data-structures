CXX=g++

ifeq ($(OS), Windows_NT)
	RM := del
	GENERATOR := generator.exe
	ANGLES  := angles.exe
else
	RM := rm
	GENERATOR := ./generator.exe
	ANGLES := ./angles.exe
endif

all: generator angles


generator: 
	$(CXX) generator.cpp -o generator
	
second: 
	$(CXX) angles.cpp -o angles


	
clean:
	$(RM) *.o *.gch main.exe

run: all
	$(GENERATOR)
	$(ANGLES)
	