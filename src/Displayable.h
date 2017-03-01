#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "UserInterface.h"

class Displayable
{
public:
  Displayable(float x, float y, float z);
  ~Displayable();

  inline const float x();
  inline const float y();
  inline const float z();

  void virtual Display() = 0;

protected:
  float x_, y_, z_;
  
};

//GETTERS

inline const float Displayable::x(){return x_;}
inline const float Displayable::y(){return y_;}
inline const float Displayable::z(){return z_;}

#endif //DISPLAYABLE_H