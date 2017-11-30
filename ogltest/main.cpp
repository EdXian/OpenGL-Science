#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "glm/glm.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "GL/gl.h"
#define OUTPUT_MODE 1
using namespace std;
using namespace glm;
GLFWwindow* window;



void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(15.0);
   glBegin(GL_POLYGON);
   glVertex2f(-0.6,-0.6);
   glVertex2f(-0.6,0.6);
   glVertex2f(0.6,0.6);
   glVertex2f(0.6,-0.6);
   glVertex2f(0.7,0.7);

   glEnd();
   glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("plot");
    glClearColor(1.0,1.0,1.0,0.8);
    glColor3f(0,0,1.0);
    glutDisplayFunc(display);
    //glClearColor(1.0,1.0,1.0,0);
    glutMainLoop();


}
