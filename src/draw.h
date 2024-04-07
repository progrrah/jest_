
#include <math.h> /* for cos(), sin(), and sqrt() */
float angle = 10.f;
float delta_angle;
float angle2 = 0.0f;
float deltax = 0.f;
float red_x1 = 0.5f;
float red_y1 = 0.f;
float red_x2 = 0.f;
float red_y2 = 0.5f;
float length = sqrt(2) * 0.5;
void redraw(void);
void myaxes() {
  glPushMatrix();
  // grey
  glColor3f(0.9, 0.9, 0.9);
  glBegin(GL_LINES);
  glVertex2f(-0.5f, 0);
  glVertex2f(0.5, 0);
  glEnd();

  // red

  // glRotatef(angle2, 100, 0, 1);
  glColor3f(1, 0, 0);
  glBegin(GL_LINES);
  // change the vertex
  glVertex2f(red_x1, red_y1);
  glVertex2f(red_x2, red_y2);
  glEnd();

  // glLoadIdentity();

  // quad
  glTranslatef(deltax, 0, 0);
  glColor3f(0, 0.9, 0.7);
  glBegin(GL_QUADS);
  glVertex2f(0.45, -0.1);
  glVertex2f(0.65, -0.1);
  glVertex2f(0.65, 0.1);
  glVertex2f(0.45, 0.1);
  glEnd();
  glPopMatrix();
  glLoadIdentity();
  // glRotatef(90, -0.5, 0, 1);

  // мы не понимааем . но это работает
  // glRotatef(angle, 100, 0.f, 1.f);
  // blue
  glColor3f(0, 0, 1);
  glBegin(GL_LINES);
  glVertex2f(red_x2, red_y2);
  glVertex2f(-0.5, 0);
  glEnd();
  // glLoadIdentity();
  glutPostRedisplay();
  red_x2 += length * (cos(angle) - cos(angle + delta_angle));
  red_y2 += length * (sin(angle) - sin(angle + delta_angle));
}
void keyboard(unsigned char ch, int x, int y) {
  switch (ch) {
    case 'a':
      deltax -= 0.15;
      delta_angle -= 2;
      angle2 -= 10;
      red_x1 -= 0.15;
      red_x2 -= 0.15;
      // red_y -=
      break;
    case 'd':
      deltax += 0.15;
      delta_angle += 2;
      angle2 += 10;
      red_x1 += 0.15;

      break;
    case 'w':
      angle += 10;
      break;
    case 's':
      angle -= 10;
      break;
    case 27:
      exit(0);
    default:
      break;
  }
}

void createBody() {
  glColor3f(0.7, 0, 1);
  glutSolidSphere(1.5, 20, 20);
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
  glMatrixMode(GL_MODELVIEW);    // To operate on Model-View matrix
  glLoadIdentity();              // Reset the model-view matrix

  // glTranslatef(-0.5f, 0.4f, 0.0f);  // Translate left and up
  glBegin(GL_QUADS);            // Each set of 4 vertices form a quad
  glColor3f(1.0f, 0.0f, 0.0f);  // Red
  glVertex2f(-0.3f, -0.3f);  // Define vertices in counter-clockwise (CCW) order
  glVertex2f(0.3f, -0.3f);   //  so that the normal (front-face) is facing you
  glVertex2f(0.3f, 0.3f);
  glVertex2f(-0.3f, 0.3f);
  glEnd();

  glBegin(GL_POINTS);
  glColor3f(1.f, 1.f, 1.f);
  glVertex2f(0.f, 0.f);
  glEnd();
  // int thickness = 2;

  auto circle = [](float radius, float x0, float y0) {
    float x, y;
    float t;
    int n = 10;
    float length = x0 + radius;
    glBegin(GL_POINTS);
    for (x; x <= length; x += length / n) {
      y = y0 + sqrt(pow(radius, 2) - pow(x - x0, 2));
      glVertex2f(x, y);
      y = y0 - sqrt(pow(radius, 2) - pow(x - x0, 2));
      glVertex2f(x, y);
    }
    glEnd();
  };
  float thickness = 10;
  for (float init_thickness{0}; init_thickness <= thickness;
       init_thickness += thickness / 10) {
    // circle(init_thickness, 0, 0);
  }
  glutSwapBuffers();
}
void display2() {
  glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
  glMatrixMode(GL_MODELVIEW);    // To operate on Model-View matrix
  glLoadIdentity();              // Reset the model-view matrix

  // glTranslatef(-0.5f, 0.4f, 0.0f);  // Translate left and up
  glBegin(GL_QUADS);            // Each set of 4 vertices form a quad
  glColor3f(1.0f, 0.0f, 0.0f);  // Red
  glVertex2f(-0.3f, -0.3f);  // Define vertices in counter-clockwise (CCW) order
  glVertex2f(0.3f, -0.3f);   //  so that the normal (front-face) is facing you
  glVertex2f(0.3f, 0.3f);
  glVertex2f(-0.3f, 0.3f);
  glEnd();

  glBegin(GL_POINTS);
  glColor3f(1.f, 1.f, 1.f);
  glVertex2f(0.f, 0.f);
  glEnd();

  // glTranslatef(0.1f, -0.7f, 0.0f);  // Translate right and down
  // glBegin(GL_QUADS);                // Each set of 4 vertices form a quad
  // glColor3f(0.0f, 1.0f, 0.0f);      // Green
  // glVertex2f(-0.3f, -0.3f);
  // glVertex2f(0.3f, -0.3f);
  // glVertex2f(0.3f, 0.3f);
  // glVertex2f(-0.3f, 0.3f);
  // glEnd();

  // glTranslatef(-0.3f, -0.2f, 0.0f);  // Translate left and down
  // glBegin(GL_QUADS);                 // Each set of 4 vertices form a quad
  // glColor3f(0.2f, 0.2f, 0.2f);       // Dark Gray
  // glVertex2f(-0.2f, -0.2f);
  // glColor3f(1.0f, 1.0f, 1.0f);  // White
  // glVertex2f(0.2f, -0.2f);
  // glColor3f(0.2f, 0.2f, 0.2f);  // Dark Gray
  // glVertex2f(0.2f, 0.2f);
  // glColor3f(1.0f, 1.0f, 1.0f);  // White
  // glVertex2f(-0.2f, 0.2f);
  // glEnd();

  // glTranslatef(1.1f, 0.2f, 0.0f);  // Translate right and up
  // glBegin(GL_TRIANGLES);           // Each set of 3 vertices form a triangle
  // glColor3f(0.0f, 0.0f, 1.0f);     // Blue
  // glVertex2f(-0.3f, -0.2f);
  // glVertex2f(0.3f, -0.2f);
  // glVertex2f(0.0f, 0.3f);
  // glEnd();

  // glTranslatef(0.2f, -0.3f, 0.0f);      // Translate right and down
  // glRotatef(180.0f, 0.0f, 0.0f, 1.0f);  // Rotate 180 degree
  // glBegin(GL_TRIANGLES);        // Each set of 3 vertices form a triangle
  // glColor3f(1.0f, 0.0f, 0.0f);  // Red
  // glVertex2f(-0.3f, -0.2f);
  // glColor3f(0.0f, 1.0f, 0.0f);  // Green
  // glVertex2f(0.3f, -0.2f);
  // glColor3f(0.0f, 0.0f, 1.0f);  // Blue
  // glVertex2f(0.0f, 0.3f);
  // glEnd();

  // glRotatef(-180.0f, 0.0f, 0.0f, 1.0f);  // Undo previous rotate
  // glTranslatef(-0.1f, 1.0f, 0.0f);       // Translate right and down
  // glBegin(GL_POLYGON);                   // The vertices form one closed
  // polygon glColor3f(1.0f, 1.0f, 0.0f);           // Yellowы glVertex2f(-0.1f,
  // -0.2f); glVertex2f(0.1f, -0.2f); glVertex2f(0.2f, 0.0f); glVertex2f(0.1f,
  // 0.2f); glVertex2f(-0.1f, 0.2f); glVertex2f(-0.2f, 0.0f); glEnd();

  glutSwapBuffers();
}
void axes(void);
void init(void);
void createBody(void);