#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> /* for cos(), sin(), and sqrt() */
#include <GL/glut.h>
void display();
void output(GLfloat x, GLfloat y, char *text);
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("gurevich");

  // glutInitWindowSize(800, 800);
  //   glClearColor(1, 1, 1, 1.0);
  glutDisplayFunc(display);
  // glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0; /* ANSI C requires main to return int. */
}
void display() {
  //   glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLineWidth(2.0);
  output(200, 225, "This is antialiased.");
  glutSwapBuffers();
}
void output(GLfloat x, GLfloat y, char *text) {
  char *p;

  glPushMatrix();
  glTranslatef(x, y, 0);
  glColor3f(0.3, 1., 0.8);
  for (p = text; *p; p++) glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
  //   glutPostRedisplay();
}