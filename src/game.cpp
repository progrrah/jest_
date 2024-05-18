#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> /* for cos(), sin(), and sqrt() */
#include <GL/glut.h>
#include "game_lib.hpp"
// float WIDTH = 1. / 20;
float ax = 0.f;
float ay = 0.f;
float bx = 1.0f;
float by = 0.f;
// float x0 = 0;
// float y0 = 0;
// int map[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
//              10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
int map[] = {10, 7, 8, 10, 5};
int N = sizeof(map) / sizeof(map[0]);
void display();
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("gurevich");
  // glutInitWindowSize(800, 800);
  glClearColor(1, 1, 1, 1.0);
  glutDisplayFunc(display);
  // glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0; /* ANSI C requires main to return int. */
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  drawMap(map, N, WIDTH);
  drawGurevich(map);
  glutSwapBuffers();
}
