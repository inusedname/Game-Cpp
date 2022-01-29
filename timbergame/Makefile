# This is makefile for SFML C++

path = D:\bin\sfml
srcPath = src
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
CXXFLAGS = -g
SFMLFLAGS =
SOURCE = main.cpp
OBJ = branch.o cloud.o hud.o bee.o main.o
SFML_INCLUDE = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d 
#=======================================================================================#

all: build
build: $(OBJ)
	g++ $(CXXFLAGS) $(OBJ) -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
branch.o: $(srcPath)/branch.cpp $(srcPath)/branch.h
	g++ -c $(srcPath)/branch.cpp -I $(INCLUDE)
cloud.o: $(srcPath)/cloud.cpp $(srcPath)/cloud.h
	g++ -c $(srcPath)/cloud.cpp -I $(INCLUDE)
hud.o: $(srcPath)/hud.cpp $(srcPath)/hud.h
	g++ -c $(srcPath)/hud.cpp -I $(INCLUDE)
bee.o: $(srcPath)/bee.cpp $(srcPath)/bee.h
	g++ -c $(srcPath)/bee.cpp -I $(INCLUDE)
main.o: main.cpp
	g++ -c main.cpp -I $(INCLUDE)
clean: 
	del *.o