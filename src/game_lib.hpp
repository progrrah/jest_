#pragma once
#include <GL/glut.h>
float WIDTH = 1. / 10;
void draw();
void changeSize(int w, int h);
// void drawGurevich();
// void drawMap();
// void drawQuads();

// void changeSize(int w, int h) {
// //   if (h == 0) h = 1;
// //   float ratio = (float)w / h;
// //   glMatrixMode(GL_PROJECTION);
// //     gluPerspective(ratio, 1)
// //   glLoadIdentity();
// // }
struct Gurevich {
  float x, y;

  Gurevich(float x0, float y0) {
    x = x0;
    y = y0;
  };
  //   WITH PHOTO
  //   Gurevich();
  void up();
  void down();
  void right();
  void left();
};
void Gurevich::up() { y += WIDTH; }
void Gurevich::down() { y -= WIDTH; }
void Gurevich::right() { x += WIDTH; }
void Gurevich::left() { x -= WIDTH; }
float def_color[3] = {0.7f, 0.5f, 0.2f};
float gur_color[3] = {0.5f, 0.3f, 0.6f};
void drawQuads(float width = WIDTH, float color[3] = def_color) {
  glColor3f(color[0], color[1], color[2]);
  glBegin(GL_QUADS);
  glVertex2f(-1, -1);
  glVertex2f(-1 + width, -1);
  glVertex2f(-1 + width, -1 + width);
  glVertex2f(-1, -1 + width);
  glEnd();
}
void drawMap(int map[], int columns, float width = WIDTH) {
  // int N = sizeof(map) / sizeof(map[0]);
  for (int i{0}; i <= columns; i++) {
    glPushMatrix();
    for (int j{}; j < map[i]; j++) {
      drawQuads(WIDTH);  //*map[i]);
      glTranslatef(0, WIDTH, 0);
    }
    glPopMatrix();
    glTranslatef(WIDTH, 0, 0);
  }
}
void drawGurevich(int map[]) {
  glLoadIdentity();
  glTranslatef(0, WIDTH * map[0], 0);
  drawQuads(WIDTH * 2, gur_color);
  // drawQuads(WIDTH * 2);
}