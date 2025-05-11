all: gravity-simulation

CXX = clang++
CXXFLAGS = -Wall -std=c++20
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

gravity-simulation: main.cpp
	$(CXX) $(CXXFLAGS) $(SFMLFLAGS) -o $@ main.cpp

clean:
	rm gravity-simulation