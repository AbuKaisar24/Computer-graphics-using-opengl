#include <stdio.h>
#include<stdlib.h>
#include <GL/glut.h>

int pntX1, pntY1, r;

void plot(int x, int y)
{
	glPointSize(2.5);
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}
void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x=x+1;
			decision= decision+2*x+1;
		}
		else
		{
			y=y-1;
			x=x+1;
			decision= decision+2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glColor3f (1.0, 0.0, 0.0);
	glPointSize(1.0);
	midPointCircleAlgo();
	glFlush ();
}
int main(int argc, char** argv)
{
	printf("Point 1:");
	scanf("%d",&pntX1);
	printf("Point 2:");
	scanf("%d",&pntY1);
    printf(" radius: ");
    scanf("%d",&r);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}
