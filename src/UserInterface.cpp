#include "UserInterface.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

GLfloat UserInterface::twist_ = 0.0f;
GLfloat UserInterface::incidence_ = 20.0f;
GLfloat UserInterface::azimuth_ = -20.0f;
GLfloat UserInterface::distance_ = 100.0f;

UserInterface::mouseInfo UserInterface::mouse_;

void UserInterface::Init(int argc, char* argv[], const string& title) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1200, 700);
  glutInitWindowPosition(10, 10);
  glutCreateWindow(title.c_str());

}
void UserInterface::Init2()
{
  glutReshapeFunc(Reshape);
  glutMouseFunc(MouseButtonHandler);
  glutMotionFunc(MouseMotionHandler);
}

void UserInterface::truc()
{
  glutDisplayFunc(Display);
}
void UserInterface::truc2()
{
  glutDisplayFunc(Display2);
}


void UserInterface::Display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  SetCamera();
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glShadeModel(GL_SMOOTH); 


  DrawCube(0,0,0,0.5);
  DrawCube(0,0,0,1);

  glutSwapBuffers();
}
void UserInterface::Display2(){
  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glClear(GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  SetCamera();
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glShadeModel(GL_SMOOTH); 


  DrawPyramid(0,0,1,1,2);
  DrawPyramid(0,0,1,1,-1);
  DrawCube(0,0,0,0.5);
  DrawCube(0,0,0,1);


  glutSwapBuffers();
}

float ra()
{
  
  float a =  (rand()%(100))/100.0;
  return a;
}

void UserInterface::DrawPlanes() {
  glPushMatrix();
  glScaled(10.0, 10.0, 10.0);
  // x=0 plane in RED
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_QUADS);
  glVertex3d(0.0,  0.0,  0.0);
  glVertex3d(0.0,  0.0, 1.0);
  glVertex3d(0.0, 1.0, 1.0);
  glVertex3d(0.0, 1.0,  0.0);
  glEnd();
  // y=0 plane in GREEN
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_QUADS);
  glVertex3d( 0.0, 0.0,  0.0);
  glVertex3d(1.0, 0.0,  0.0);
  glVertex3d(1.0, 0.0, 1.0);
  glVertex3d( 0.0, 0.0, 1.0);
  glEnd();
  // z=0 plane in BLUE
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
  glVertex3d( 0.0,  0.0, 0.0);
  glVertex3d( 0.0, 1.0, 0.0);
  glVertex3d(1.0, 1.0, 0.0);
  glVertex3d(1.0,  0.0, 0.0);
  glEnd();
  // Reset to WHITE
  glColor3f(1.0, 1.0, 1.0);
  glPopMatrix();
}

void UserInterface::DrawCube(float x, float y, float z, float arrete) {
  
  float ar = arrete/2;

  srand(time(0));

  glPushMatrix();
  glScaled(10.0, 10.0, 10.0);
  // x=0 plane in RED
  glBegin(GL_QUADS);

    glColor3f(ra(), ra(), ra());
    glVertex3d(x - ar, y - ar, z - ar);
    glVertex3d(x - ar, y - ar, z + ar);
    glVertex3d(x - ar, y + ar, z + ar);
    glVertex3d(x - ar, y + ar, z - ar);
  // y=0 plane in GREEN
    glColor3f(ra(), ra(), ra());
    glVertex3d(x - ar, y - ar, z - ar);
    glVertex3d(x + ar, y - ar, z - ar);
    glVertex3d(x + ar, y - ar, z + ar);
    glVertex3d(x - ar, y - ar, z + ar);
  // z=0 plane in BLUE
    glColor3f(ra(), ra(), ra());
    glVertex3d( x - ar, y - ar, z - ar);
    glVertex3d( x - ar, y + ar, z - ar);
    glVertex3d( x + ar, y + ar, z - ar);
    glVertex3d( x + ar, y - ar, z - ar);
  //front in pink
    glColor3f(ra(), ra(), ra());
    glVertex3d( x - ar, y - ar, z + ar);
    glVertex3d( x - ar, y + ar, z + ar);
    glVertex3d( x + ar, y + ar, z + ar);
    glVertex3d( x + ar, y - ar, z + ar);
  

  //top in yellow


  // glColor3f(1.0, 1.0, 0.0);
  // glBegin(GL_POLYGON);
  // glVertex3d( x - ar, y + ar, z + ar);
  // glVertex3d( x + ar, y + ar, z + ar);
  // glVertex3d( x + ar, y + ar, z - ar);
  // glVertex3d( x - ar, y + ar, z - ar);
  // glEnd();

  // glDisable(GL_DEPTH_TEST);

  // glColor3f(1.0, 0.0, 0.0);
  // glBegin(GL_LINE_LOOP);
  // glVertex3d( x - ar, y + ar, z - ar);
  // glVertex3d( x + ar, y + ar, z - ar);
  // glVertex3d( x + ar, y + ar, z + ar);
  // glVertex3d( x - ar, y + ar, z + ar);
  // glEnd();
  // glEnable(GL_DEPTH_TEST);

    glColor3f(ra(), ra(), ra());
    glVertex3d( x - ar, y + ar, z - ar);
    glVertex3d( x + ar, y + ar, z - ar);
    glVertex3d( x + ar, y + ar, z + ar);
    glVertex3d( x - ar, y + ar, z + ar);
    
    glEnd();

  // Reset to WHITE
  glColor3f(1.0, 1.0, 1.0);
  glPopMatrix();
}

void UserInterface::DrawPyramid(float x, float y, float z, float arrete, int mod) {
  
  float ar = arrete/2;

  glPushMatrix();
  glScaled(10.0, 10.0, 10.0);
  // x=0 plane in RED

  float ztop = z + mod*(0.5*arrete*(pow(2,0.5)));
  glBegin(GL_TRIANGLES);

    //front

    glColor3f(ra(), ra(), ra());
    glVertex3d(x, y, ztop);
    glVertex3d(x - ar, y + ar, z);
    glVertex3d(x + ar, y + ar, z);

    //left
    glColor3f(ra(), ra(), ra());
    glVertex3d(x, y, ztop);
    glVertex3d(x - ar, y + ar, z);
    glVertex3d(x - ar, y - ar, z);
    

    //back
    glColor3f(ra(), ra(), ra());
    glVertex3d(x, y, ztop);
    glVertex3d(x - ar, y - ar, z);
    glVertex3d(x + ar, y - ar, z);
  //front in pink
    glColor3f(ra(), ra(), ra());
    glVertex3d(x, y, ztop);
    glVertex3d(x + ar, y - ar, z);
    glVertex3d(x + ar, y + ar, z);
    
    glEnd();

  // Reset to WHITE
  glColor3f(1.0, 1.0, 1.0);
  glPopMatrix();
}

void UserInterface::Reshape(int w, int h) {
  glViewport (0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(30.0f, static_cast<float>(w) / h, 1.0, 1000.0);
  glMatrixMode (GL_MODELVIEW);
}

void UserInterface::SetCamera() {
  glTranslatef(-5.0f, -5.0f, -distance_);
  glRotatef(twist_, 0.0f, 0.0f, 1.0f);
  glRotatef(incidence_, 1.0f, 0.0f, 0.0f);
  glRotatef(azimuth_, 0.0f, 1.0f, 0.0f);
}

void UserInterface::MainLoop() {
  glutMainLoop();
}

GLvoid UserInterface::MouseButtonHandler(GLint button, GLint state,
                                         GLint x, GLint y) {
  if (state == GLUT_DOWN) {
    switch (button) {
      case GLUT_LEFT_BUTTON:
        mouse_.action = MOVE_EYE;
        break;
      case GLUT_MIDDLE_BUTTON:
        mouse_.action = TWIST_EYE;
        break;
      case GLUT_RIGHT_BUTTON:
        mouse_.action = ZOOM;
        break;
      default:
        mouse_.action = MOVE_NONE;
        break;
    }

    /* Update the saved mouse position */
    mouse_.x0 = x;
    mouse_.y0 = y;
  }
  else {
    mouse_.action = MOVE_NONE;
  }
}

GLvoid UserInterface::MouseMotionHandler(GLint x, GLint y) {
  switch (mouse_.action)
  {
    case MOVE_EYE:
      /* Adjust the eye position based on the mouse position */
      azimuth_ += (GLdouble) (x - mouse_.x0);
      incidence_ += (GLdouble) (y - mouse_.y0);
      break;
    case TWIST_EYE:
      /* Adjust the eye twist based on the mouse position */
      twist_ = fmod(twist_ + (x - mouse_.x0), 360.0);
      break;
    case ZOOM:
      /* Adjust the eye distance based on the mouse position */
      distance_ -= (GLdouble) (y - mouse_.y0)/10.0;
      break;
  }

  /* Update the stored mouse position for later use */
  mouse_.x0 = x;
  mouse_.y0 = y;

  glutPostRedisplay();
}
