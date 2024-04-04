extern float z;
void keyboard(unsigned char, int x, int y);
void specialKeys(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char ch, int x, int y) {
  switch (ch) {
    case 'a':
      z = 1;
      break;
    case 'd':
      z = 2;
      break;
    case 'e':
      z = 3;
      break;
    case 27:
      exit(0);
    default:
      break;
  }
}