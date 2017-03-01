#ifndef CUBE_H
#define CUBE_H

#include "UserInterface.h"
#include "Displayable.h"

class Cube : public Displayable
{
public:
  Cube(float x, float y, float z, float arr);
  ~Cube();

  inline const float ar();

  void virtual Display();

protected:
  float ar_;
  
};

//GETTER
  inline const float Cube::ar(){return ar_;}



#endif //CUBE_H