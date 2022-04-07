CXX=g++

ifeq ($(OS), Windows_NT)
	GENERATOR := generator.exe
	ANGLES  := angles.exe
else
	GENERATOR := ./generator
	ANGLES := ./angles
endif

all: generator angles


generator: 
	$(CXX) generator.cpp -o generator
	
second: 
	$(CXX) angles.cpp -o angles

run: all
	$(GENERATOR)
	$(ANGLES)
	
