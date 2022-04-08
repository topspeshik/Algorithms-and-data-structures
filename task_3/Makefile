CXX=g++


GENERATOR := ./generator
ANGLES := ./angles
ifeq ($(OS), Windows_NT)
	GENERATOR := generator.exe
	ANGLES  := angles.exe
endif

all: generator angles


generator: 
	$(CXX) generator.cpp -o generator
	
second: 
	$(CXX) angles.cpp -o angles

run: all
	$(GENERATOR)
	$(ANGLES)
	
