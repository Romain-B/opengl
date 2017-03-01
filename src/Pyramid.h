#ifndef PYRAMID_H
#define PYRAMID_H

#include "UserInterface.h"
#include "Displayable.h"

class Pyramid : public Displayable
{
public:
  Pyramid(float x, float y, float z, float arr);
  ~Pyramid();

  inline const float ar();

  void virtual Display();


protected:
  float ar_;

};

//GETTER
  inline const float Pyramid::ar(){return ar_;}


#endif //PYRAMID_H