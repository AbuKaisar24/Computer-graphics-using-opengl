#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int xstart,ystart,xend,yend;
void display()
{
    int dx=xend-xstart;
    int dy=yend-ystart;
    int steps=dx;
    if(abs(dy)>abs(dx))
    {
        steps=dy;
    }
    float x=1.0*xstart;
    float y=1.0*ystart;
    float xinc=1.0*dx/steps;
    float yinc=1.0*dy/steps;
    glClearColor(1.0,1.0,1.0,1.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(x,y);
    for(int i=1;i<=steps;i++)
    {
        x=x+xinc;
        y=y+yinc;
        glVertex2f(round(x),round(y));
    }
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    printf("Enter x1:");
    scanf("%d",&xstart);
    printf("Enter y1:");
    scanf("%d",&ystart);
    printf("Enter x2:");
    scanf("%d",&xend);
    printf("Enter y2:");
    scanf("%d",&yend);
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA");
    gluOrtho2D(0,600,0,600);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
