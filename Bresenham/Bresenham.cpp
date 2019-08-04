#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
int xs,ys,xe,ye;
void display()
{
    int dx=xe-xs,dy=ye-ys;
    int p=2*dy*dx;
    int twody= 2*dy;
    int twodx= 2*dx;
    int twodyminusdx=2*(dy-dx);
    int x=xs,y=ys;
    glClearColor(1.0,1.0,1.0,1.0);
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(x,y);
    if(dx<0)
    {
        x=xe;
        y=ye;
        xe=xs;
    }
    glVertex2f(x,y);
    while(x<xe)
    {
        x=x+1;
        if(p<0)
        {
            p=p+twody;
        }
        else{
            y=y+1;
            p=p+twodyminusdx;
        }
        glVertex2f(x,y);
    }
glEnd();
glFlush();
}
int main(int argc,char** argv)
{
    printf("Enter x1:");
    scanf("%d",&xs);
    printf("Enter y1:");
    scanf("%d",&ys);
    printf("Enter x2:");
    scanf("%d",&xe);
    printf("Enter y2:");
    scanf("%d",&ye);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("ok");
    gluOrtho2D(0,600,0,600);
    glutDisplayFunc(display);
    glutMainLoop();
}
