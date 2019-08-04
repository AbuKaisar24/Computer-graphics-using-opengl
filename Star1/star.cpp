#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glLineWidth(7.5);
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex3f (0.50,0.14,0.0);
glVertex3f (0.45,0.20,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f (0.50,0.14,0.0);
glVertex3f (0.55,0.20,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f (0.55,0.20,0.0);
glVertex3f (0.62,0.25,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f (0.62,0.25,0.0);
glVertex3f (0.55,0.30,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f (0.45,0.20,0.0);
glVertex3f (0.38,0.25,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f (0.38,0.25,0.0);
glVertex3f (0.45,0.30,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f (0.45,0.30,0.0);
glVertex3f (0.50,0.36,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f (0.50,0.36,0.0);
glVertex3f (0.55,0.30,0.0);
glEnd();
glFlush ();
}
void init (void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (700, 700);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Lab1");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

