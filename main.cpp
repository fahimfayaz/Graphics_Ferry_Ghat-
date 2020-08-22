#include <iostream>
#include<cstdio>
#include <windows.h>
#include <cstdlib>
#include<math.h>
#include<GL/gl.h>
#include <GL/glut.h>

float ferry_x_pos = 35.0f;
float car1_x_pos = -20.0f;
float car2_x_pos = 500.0f;
int state = 3;

void Init (void)
{
glClearColor(0,0,0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void ferry(){
    glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
    glVertex2f(ferry_x_pos+60.0f , 50.0f);
    glVertex2f(ferry_x_pos+60.0f , 40.0f);
    glVertex2f(ferry_x_pos+55.0f , 30.0f);
    glVertex2f(ferry_x_pos+5.0f , 30.0f);
    glVertex2f(ferry_x_pos, 40.0f);
    glVertex2f(ferry_x_pos, 50.0f);
    glEnd();
}

void car1(){
    glBegin(GL_POLYGON);
    glColor3ub(255,153,51);
    glVertex2f(car1_x_pos+20.f , 60.0f);
    glVertex2f(car1_x_pos+20.f , 50.0f);
    glVertex2f(car1_x_pos, 50.0f);
    glVertex2f(car1_x_pos, 60.0f);
    glEnd();
}

void car2(){
    glBegin(GL_POLYGON);
    glColor3ub(102,178,255);
    glVertex2f(car2_x_pos+20.f , 60.0f);
    glVertex2f(car2_x_pos+20.f , 50.0f);
    glVertex2f(car2_x_pos, 50.0f);
    glVertex2f(car2_x_pos, 60.0f);
    glEnd();
}

void Display(void)
{
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glPointSize(5.0);

glPushMatrix();
//glTranslatef(car2_x_pos, 0.0f, 0.0f);
car1();
glPopMatrix();

glPushMatrix();
//glTranslatef(car2_x_pos, 0.0f, 0.0f);
car2();
glPopMatrix();

glPushMatrix();
//glTranslatef(ferry_x_pos,0.0f, 0.0f);
ferry();
glPopMatrix();

glFlush();
glutSwapBuffers();
}

void Timer(int)
{
    bool f=false, c1=false, c2=false;
    glutPostRedisplay();
    glutTimerFunc(10, Timer, 0);

    switch (state){

    case 3 :    if (car1_x_pos < 50)
                        car1_x_pos += 1.0;
                else
                        {car1_x_pos += 0;
                        state = 1;
                        c1=true;}
                break;

    case 1 :    while (c1=true)
                    {if ((ferry_x_pos <370.0)&&(car1_x_pos < 380))
                        {ferry_x_pos += 2.0;
                        car1_x_pos += 2.0;}
                    else
                        {ferry_x_pos += 0;
                        car1_x_pos +=0;
                        state= -3;
                        f=true;}
                break;}
                break;

    case -1  :   if (car2_x_pos >380.0)
                    {car2_x_pos += -1.0;
                    ferry_x_pos += 0;}
                else
                    {car2_x_pos += 0;
                    state = 2;
                    c2=true;}
                break;
    case 2 :    while ((f=true) && (c2=true))
                    {if ((ferry_x_pos > 40) && (car2_x_pos > 50))
                        {car2_x_pos += -2;
                        ferry_x_pos += -2;}
                    else
                        {ferry_x_pos += -0;
                        car2_x_pos += -0;
                        state = -2;
                        f=false;}
                        break;}
                break;

    case -2 :   if (car2_x_pos > -20)
                    car2_x_pos += -1;
                else
                    {car2_x_pos = 500.0;
                    state = 3;
                    c2=false;}
                break;

    case -3 :   if (car1_x_pos < 500)
                    car1_x_pos += 1.0;
                else
                    {car1_x_pos = -20.0;
                    state = -1;
                    c1=false;
                    break;}

                }
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize (1240, 750);
glutInitWindowPosition (300, 200);
glutCreateWindow ("PROJECT-FERRY GHAT");
glutDisplayFunc(Display);

glutTimerFunc(10,Timer,0);
Init();
glutMainLoop();
return 0;
}

