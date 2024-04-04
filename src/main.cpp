#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> /* for cos(), sin(), and sqrt() */
#include <GL/glut.h>
#include "draw.h"
// #include "input.h"
#include <iostream>

void redraw(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  myaxes();
  glutSwapBuffers();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("mechanism");
  glClearColor(1, 1, 1, 1.0);
  glutDisplayFunc(redraw);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0; /* ANSI C requires main to return int. */
}