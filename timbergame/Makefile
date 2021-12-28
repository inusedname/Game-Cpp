# This is makefile for SFML C++

path = D:\bin\sfml
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
CXXFLAGS = -g
SFMLFLAGS =
SOURCE = main.cpp
OBJ = main.o
SFML_INCLUDE = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d 
#=======================================================================================#

all: link clean
link: compile
	g++ $(CXXFLAGS) $(OBJ) -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
compile:
	g++ -c $(SOURCE) -I $(INCLUDE)
clean: 
	del *.o