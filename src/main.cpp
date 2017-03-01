#include <cstdlib>

#include <iostream>
#include <unistd.h>

#include "UserInterface.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

  UserInterface::Init(argc, argv, "TP OpenGL");

;
  //UserInterface::DrawCube(0,0,0,1);
  UserInterface::truc();
  UserInterface::truc2();

  UserInterface::Init2();
  UserInterface::MainLoop();

  //sleep(10);





  return EXIT_SUCCESS;
}
