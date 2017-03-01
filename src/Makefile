OPTS = -g -Wall -Wextra -g3 -O0 -std=gnu++0x 

OP2 = -lglut -lGLU -lGL

all : UserInterface.o main.o
	g++ $(OPTS) UserInterface.o main.o -o interGraph $(OP2)

main.o : main.cpp
	g++ $(OPTS) -c main.cpp

UserInterface.o : UserInterface.h UserInterface.cpp
	g++ $(OPTS) -c UserInterface.cpp

clean : 
	rm -rf *.o interGraph