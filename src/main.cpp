#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> /* for cos(), sin(), and sqrt() */
#include <GL/glut.h>
// #include "draw.h"
// #include "input.h"
#include <iostream>
float phi0 = -5.f;
float phi = 0;
float delta_angle = 0.2f;
// /float angle2 = 0.0f;
float deltax = 0.f;
float x_step;
float ax = 0.f;
float ay = 0.f;
float bx = 1.0f;
float by = 0.f;
float cx = 0.2f;
float cy = 0.2f;
// float length = sqrt(2) * 0.5;
float length = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
float polzun_size = 0.05f;

// static void motion(int x, int y);
// void animation(int phi);
void Timer(int value);
void drawMechanism();
void keyboard(unsigned char, int, int);
void redraw(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawMechanism();
  glutSwapBuffers();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("mechanism");
  glClearColor(1, 1, 1, 1.0);
  glTranslatef(-0.5f, 0.0f, 0.f);
  glutDisplayFunc(redraw);
  Timer(0);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0; /* ANSI C requires main to return int. */
}
void drawMechanism() {
  // glPushMatrix();
  // grey
  glColor3f(0.9, 0.9, 0.9);
  glBegin(GL_LINES);
  glVertex2f(ax, ay);
  glVertex2f(bx, by);
  glEnd();
  // red
  glColor3f(1, 0, 0);
  glBegin(GL_LINES);
  // change the vertex
  glVertex2f(bx, by);
  glVertex2f(cx, cy);
  glEnd();

  // quad
  glColor3f(0, 0.9, 0.7);
  glBegin(GL_QUADS);
  glVertex2f(bx - polzun_size, by - polzun_size);
  glVertex2f(bx + polzun_size, by - polzun_size);
  glVertex2f(bx + polzun_size, by + polzun_size);
  glVertex2f(bx - polzun_size, by + polzun_size);

  glEnd();
  glColor3f(0, 0, 1);
  // blue
  glLineWidth(5);
  glBegin(GL_LINES);
  // const vertex
  glVertex2f(ax, ay);
  // change
  glVertex2f(cx, cy);
  glEnd();
}

void keyboard(unsigned char ch, int x, int y) {
  switch (ch) {
    case 'a':
      phi = phi + delta_angle;
      x_step = cx;
      cx = length * (cos(phi + phi0));
      cy = length * (sin(phi + phi0));
      x_step = (x_step - cx);
      bx -= x_step;
      glutPostRedisplay();
      break;
    case 'd':
      phi = phi - delta_angle;
      x_step = cx;
      cx = length * (cos(phi + phi0));
      cy = length * (sin(phi + phi0));
      x_step = (x_step - cx);
      bx -= x_step;
      glutPostRedisplay();
      break;
    case 'w':
      phi += 10;
      break;
    case 's':
      phi -= 10;
      break;
    case 27:
      exit(0);
    default:
      break;
  }
}
void calc() {
  phi = phi + delta_angle;
  x_step = cx;
  cx = length * (cos(phi + phi0));
  cy = length * (sin(phi + phi0));
  x_step = (x_step - cx);
  bx -= x_step;
  glutPostRedisplay();
}
void Timer(int value) {
  calc();
  glutTimerFunc(10, Timer, 0);
  glutPostRedisplay();
}