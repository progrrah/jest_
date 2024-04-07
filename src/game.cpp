#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> /* for cos(), sin(), and sqrt() */
#include <GL/glut.h>

float ax = 0.f;
float ay = 0.f;
float bx = 1.0f;
float by = 0.f;
void display();
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("gurevich");
  glClearColor(1, 1, 1, 1.0);
  glutDisplayFunc(display);
  //   glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0; /* ANSI C requires main to return int. */
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.5, 0.5, 0.5, 0.5);
  glColor3f(0.9, 0.9, 0.9);
  glBegin(GL_LINES);
  glVertex2f(ax, ay);
  glVertex2f(bx, by);
  glEnd();
  glutSwapBuffers();
}