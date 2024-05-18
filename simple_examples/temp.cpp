#include <GL/glut.h> /* glut graphics library */
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define CELLS 20
#define WIDTH (2.0 / CELLS)

//--------------

std::vector<int> map_v;

uint64_t timer = 0;
uint64_t jump_timer = 0;

struct Hero {
  double x;
  double y;
  double z;
  int x_cell;
  int y_cell;
  int z_cell;
  bool jumped;
};

enum Coords { x, y, z };
Hero Gurevich{0.0, 0.0, 0.0, 0, 0, 0, false};
void myDisp();

bool check_position(int x, int y, int z, std::vector<int> map) {
  if (x >= 20 || x < 0 || y >= 20 || y < 0 || z >= 20 || z < 0) return false;

  if (map[x] >= 0) {
    if (map[x] <= y) return true;
    return false;
  } else {
    return true;
  }
}

void move(Hero& Gurevich, Coords C, std::vector<int> map, int count = 1) {
  int x_cell = Gurevich.x_cell;
  int y_cell = Gurevich.y_cell;
  int z_cell = Gurevich.z_cell;

  switch (C) {
    case Coords::x:
      x_cell += count;
      break;
    case Coords::y:
      y_cell += count;
      break;
    case Coords::z:
      z_cell += count;
      break;
  }

  if (check_position(x_cell, y_cell, z_cell, map)) {
    switch (C) {
      case Coords::x:
        Gurevich.x += count * WIDTH;
        Gurevich.x_cell += count;
        break;
      case Coords::y:
        Gurevich.y += count * WIDTH;
        Gurevich.y_cell += count;
        break;
      case Coords::z:
        Gurevich.z += count * WIDTH;
        Gurevich.z_cell += count;
        break;
    }
  }
  // else
  // no moving today :(
}

// ------------

void draw_rectangle(int height, float width = WIDTH) {
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(0, height * width, 0);
  glVertex3f(width, height * width, 0);
  glVertex3f(width, 0, 0);
  glEnd();
}

void draw_map(std::vector<int>& map) {
  glTranslatef(-1.0, -1.0, 0);

  for (int cell = 0; cell < CELLS; ++cell) {
    if (map_v[cell] >= 0)
      glColor3f(0, 1, 0);
    else
      glColor3f(0, 0, 1);

    draw_rectangle(std::abs(map[cell]), WIDTH);
    glTranslatef(WIDTH, 0, 0);
  }

  // glLoadIdentity ();
  // glTranslatef (-1.0, -1.0, 0);
}

void draw_hero(Hero Gurevich) {
  glLoadIdentity();
  glTranslatef(-1.0, -1.0, 0);

  glTranslatef(Gurevich.x, Gurevich.y, Gurevich.z);

  glColor3f(1.0, 0, 0);

  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 0.1, 0);
  glVertex3f(0.1, 0.1, 0);
  glVertex3f(0.1, 0, 0);
  glEnd();

  // левый глаз
  glColor3f(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex3f(0.02, 0.07, 0);
  glVertex3f(0.02, 0.08, 0);
  glVertex3f(0.03, 0.08, 0);
  glVertex3f(0.03, 0.07, 0);
  glEnd();

  // правый глаз
  glColor3f(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex3f(0.07, 0.07, 0);
  glVertex3f(0.07, 0.08, 0);
  glVertex3f(0.08, 0.08, 0);
  glVertex3f(0.08, 0.07, 0);
  glEnd();

  // рот
  glColor3f(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex3f(0.02, 0.02, 0);
  glVertex3f(0.02, 0.03, 0);
  glVertex3f(0.08, 0.03, 0);
  glVertex3f(0.08, 0.02, 0);
  glEnd();
}

// grid Grid_1;
// grid Grid_2;
// grid Grid_3;
// grid Test;

void setJumpedFalse(int value) { Gurevich.jumped = false; }

bool isInTheAir(std::vector<int>& map, Hero Gurevich) {
  return !(Gurevich.y_cell == std::abs(map[Gurevich.x_cell]));
}

void myKeyboard(unsigned char key, int x, int y) {
  switch (key) {
    case ' ':
      if (!Gurevich.jumped && (!isInTheAir(map_v, Gurevich))) {
        Gurevich.jumped = true;
        move(Gurevich, Coords::y, map_v, 1);
        myDisp();
        move(Gurevich, Coords::y, map_v, 1);
        glutTimerFunc(100, setJumpedFalse, 0);
      }

      break;
    // case 's': move (Gurevich, Coords::y, map_v, -1); break;
    case 'a':
      move(Gurevich, Coords::x, map_v, -1);
      break;
    case 'd':
      move(Gurevich, Coords::x, map_v, 1);
      break;
  }

  myDisp();
}

// void IdleFunc () {
//     }
