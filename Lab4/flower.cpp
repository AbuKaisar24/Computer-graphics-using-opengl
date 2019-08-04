#include <math.h>
#include <GL/glut.h>
#define PI 3.14159
GLfloat pos[3] = {0,0,0};
GLfloat theta[3] = {0,0,0};
GLint fillmode = 1;
GLint numPetals = 5;
void circle(GLfloat r, GLfloat inX, GLfloat inY, GLfloat inZ) {

  GLfloat angle,x,y;
  glBegin(GL_POLYGON);
  for(angle = 0; angle < 2 * PI; angle += .1) {
    x = (r * cos(angle)) + inX;
    y = (r * sin(angle)) + inY;
    glVertex2f(x, y);
  }
  glEnd();
}
void drawCenter(GLfloat r, GLfloat inX, GLfloat inY) {
  GLfloat angle, x, y, z;
  glBegin(GL_POLYGON);
  for(z = -.1; z < .1; z += .01) {
    for(angle = 0; angle < 2*PI; angle += PI/100) {
      x = (r * cos(angle)) + inX;
      y = (r * sin(angle)) + inY;
      glVertex3f(x, y, z);
    }
  }
  glEnd();
  glBegin(GL_POLYGON);
  for(angle = 0; angle < 2*PI; angle += PI/100) {
    x = (r * cos(angle)) + inX;
    y = (r * sin(angle)) + inY;
    glVertex3f(x, y,z);
  }
  glEnd();

}
void drawPetal(GLfloat startx, GLfloat starty, GLfloat inAngle, GLfloat radius) {
  glPushMatrix();
  GLfloat inAngle_degs = inAngle * 180/PI;
  glRotatef(inAngle_degs, 0.0, 0.0, 1.0);
  glTranslatef(2*radius, 0.0, 0.0);
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1,0,1);
  glVertex3f(-radius/5, 0.0, -0.2);
  GLfloat angle, z_value;
  for(angle = 0; angle < 2.01*PI; angle += 2*PI/100){
    if(angle <=PI) {
      z_value = .2 * (1-(angle/PI));
    }
    else {
      z_value = .2 * ((angle-PI)/PI);
    }
    glVertex3f(2*radius * cos(angle), radius/2 * sin(angle), z_value);
  }
  glEnd();
  glPopMatrix();
}
void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  glTranslatef(pos[0], pos[1], pos[2]);
  glRotatef(theta[0], 1.0, 0.0, 0.0);
  glRotatef(theta[1], 0.0, 1.0, 0.0);
  glRotatef(theta[2], 0.0, 0.0, 1.0);
  if(fillmode)
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  else
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  GLfloat radius = .5;
  glColor3f(1,1,0);
  GLint i;
  GLfloat angle,x,y;
  for(i = 0; i < numPetals; i++){
    angle = i*(2*PI / numPetals);
    x = radius * cos(angle);
    y = radius * sin(angle);
    drawPetal(x, y, angle, radius);
  }
  glColor3f(1,1,0);
  drawCenter(radius, 0, 0);
  glFlush();

}
void keypress(unsigned char key, int x, int y) {
  switch(key) {
  case 'x':
    theta[0] += 5.0;
    break;
  case 'X':
    theta[0] -= 5.0;
    break;
  case 'y':
    theta[1] += 5.0;
    break;
  case 'Y':
    theta[1] -= 5.0;
    break;
  case 'z':
    theta[2] += 5.0;
    break;
  case 'Z':
    theta[2] -= 5.0;
    break;

  case 'b':
    pos[2] -= 0.5;
    break;
  case 'f':
    pos[2] += 0.5;
    break;
  case 'd':
    pos[1] -= 0.5;
    break;
  case 'u':
    pos[1] +=0.5;
    break;
  case 'l':
    pos[0] -= 0.5;
    break;
  case 'r':
    pos[0] += 0.5;
    break;
  case '+':
    numPetals++;
    break;
  case '-':
    if(numPetals > 2){
      numPetals--;
    }
    break;

  case 'q':
    exit(0);
    break;
  }
  glutPostRedisplay();
}

void main_menu(int value) {
  switch(value) {
  case 1:
    exit(0);
    break;
 case 2:
   fillmode = !fillmode;
   break;
  }
  glutPostRedisplay();
}
int main(int argc, char** argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(200,200);
  glutCreateWindow(argv[0]);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  pos[2] = -5;
  glutDisplayFunc(display);
  glutKeyboardFunc(keypress);
  glutCreateMenu(main_menu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop();
  return 0;
}

