OPTS = -g -Wall -Wextra -g3 -O0 -std=gnu++0x 

OP2 = -lglut -lGLU -lGL

all : UserInterface.o main.o Displayable.o Pyramid.o Cube.o 
	g++ $(OPTS) UserInterface.o Displayable.o Cube.o Pyramid.o main.o -o interGraph $(OP2)

main.o : main.cpp
	g++ $(OPTS) -c main.cpp

UserInterface.o : UserInterface.h UserInterface.cpp
	g++ $(OPTS) -c UserInterface.cpp

Displayable.o : Displayable.h Displayable.cpp
	g++ $(OPTS) -c Displayable.cpp

Pyramid.o : Pyramid.cpp Pyramid.h
	g++ $(OPTS) -c Pyramid.cpp

Cube.o : Cube.h Cube.cpp Pyramid.cpp Pyramid.h
	g++ $(OPTS) -c Cube.cpp

clean : 
	rm -rf *.o interGraph