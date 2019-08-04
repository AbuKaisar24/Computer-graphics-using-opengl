#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{

glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex2f (0.1, 0.5);
glVertex2f (0.1, 0.8);
glVertex2f (0.8,0.8);
glVertex2f (0.8, 0.5);
glEnd();
glColor3f (1.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.1, 0.8);
glVertex2f (0.1, 0.85);
glVertex2f (0.8,0.85);
glVertex2f (0.8, 0.8);
glEnd();
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.2, 0.6);
glVertex2f (0.2, 0.7);
glVertex2f (0.3,0.7);
glVertex2f (0.3, 0.6);
glEnd();
glColor3f (0.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.4, 0.5);
glVertex2f (0.4, 0.7);
glVertex2f (0.5,0.7);
glVertex2f (0.5, 0.5);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.6, 0.6);
glVertex2f (0.6, 0.7);
glVertex2f (0.7,0.7);
glVertex2f (0.7, 0.6);
glEnd();
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.6, 0.6);
glVertex2f (0.6, 0.7);
glVertex2f (0.7,0.7);
glVertex2f (0.7, 0.6);
glEnd();
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.0, 0.2);
glVertex2f (0.0, 0.3);
glVertex2f (1,0.3);
glVertex2f (1.0, 0.2);
glEnd();
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.4, 0.3);
glVertex2f (0.4, 0.5);
glVertex2f (0.5,0.5);
glVertex2f (0.5, 0.3);
glEnd();
glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f (0.85, 0.5);
glVertex2f (0.85, 0.8);
glVertex2f (0.86,0.8);
glVertex2f (0.86, 0.5);
glEnd();
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex2f (0.85, 0.75);
glVertex2f (0.85, 0.79);
glVertex2f (0.95,0.79);
glVertex2f (0.95, 0.75);
glEnd();
glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800, 800);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Lab1");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}


