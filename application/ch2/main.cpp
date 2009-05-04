#include <iostream>

#define WINDOWS
#ifdef WINDOWS
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "FiniteStateMachine.hpp"

#include "World.hpp"

static World world = World();


void Reshape(int w, int h)
{
   glClearColor(0,0.5,0.5,0);
  
   if(h==0)
      h=1;

   glViewport(0,0,w,h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45,w/h,1,1000);
  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0,0,30,0,0,0,0,1,0);
}

void Update(int discriptor)
{
   world.Update(1.0/World::fps);

   glutPostRedisplay();
   glutTimerFunc(1000.0 / World::fps, Update, discriptor);
}

void Render()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//   glBegin(GL_TRIANGLES);
//   glVertex3f(0,1,1);
//   glVertex3f(1,0,1);
//   glVertex3f(0,0,1);
//   glEnd();
   glutSwapBuffers();
}

void MainIdle()
{
}

void HandleKeyDownEvent(unsigned char key, int x, int y)
{
   if(key == 't')
   {
   }
}

void HandleKeyUpEvent(unsigned char key, int x, int y)
{
  
}

int main(int argc,char* argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(800,600);
   glutCreateWindow("Boost.Build+Git GameDev");

   glutReshapeFunc(Reshape);
   glutTimerFunc(1000.0 / World::fps, Update, 0);
   glutDisplayFunc(Render);
//   glutIdleFunc(MainIdle);
   glutKeyboardFunc(HandleKeyDownEvent);
   glutKeyboardUpFunc(HandleKeyUpEvent);

   world.Init();

   glutMainLoop();
}
