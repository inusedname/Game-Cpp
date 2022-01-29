# This is makefile for SFML C++
syspath = D:\bin\sfml
INCLUDE = "$(syspath)\include"
LIBRARY = "$(syspath)\lib"
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXXFLAGS = -g
SFMLFLAGS =
#=======================================================================================#
MAIN = ..\main.cpp
GAMEMANAGER = ..\GameManager
OBJECTS = ..\Objects
OFILE = ResourceManager.o Car.o Lane.o Player.o main.o

#=======================================================================================#

all: link
ResourceManager.o: $(GAMEMANAGER)\ResourceManager.h $(GAMEMANAGER)\ResourceManager.cpp
	g++ -c $(GAMEMANAGER)\ResourceManager.cpp -I $(INCLUDE)
Car.o: $(OBJECTS)\Car.h $(OBJECTS)\Car.cpp
	g++ -c $(OBJECTS)\Car.cpp -I $(INCLUDE)
Lane.o: $(OBJECTS)\Lane.h $(OBJECTS)\Lane.cpp
	g++ -c $(OBJECTS)\Lane.cpp -I $(INCLUDE)
Player.o: $(OBJECTS)\Player.h $(OBJECTS)\Player.cpp
	g++ -c $(OBJECTS)\Player.cpp -I $(INCLUDE)
main.o: $(MAIN)
	g++ -c $(MAIN) -I $(INCLUDE)
link: $(OFILE)
	g++ $(CXXFLAGS) $(OFILE) -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)
clean: 
	del *.o