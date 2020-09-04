#include <iostream>
#include<cstdio>
#include <windows.h>
#include <cstdlib>
#include<math.h>
#include<GL/gl.h>
#include <GL/glut.h>
# define PI 3.14159265358979323846

float ferry_x_pos = 30.0f;
float car1_x_pos = -20.0f;
float car2_x_pos = 500.0f;
float train_x_pos =-150.0f;
int state = 3, tstate = 1;

void Init (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}
float angle1= 0.0f;
void windmill1(){
    glBegin(GL_POLYGON);// stem
    glColor3ub(192,192,192);
    glVertex2f(58.0f , 200.0f);
    glVertex2f(52.0f , 200.0f);
    glVertex2f(54.0f , 306.0f);
    glVertex2f(56.0f , 306.0f);
    glEnd();
    glBegin(GL_POLYGON);// stem shadow
    glColor3ub	(105,105,105);
    glVertex2f(58.0f , 200.0f);
    glVertex2f(52.0f , 200.0f);
    glVertex2f(42.0f , 174.0f);
    glVertex2f(42.0f , 170.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(55.0f, 305.0f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);//top fan
    glColor3ub	(128,128,128);
    glVertex2f(-2.0f , 0.0f);
    glVertex2f(2.0f , 0.0f);
    glVertex2f(0.0f , 35.0f);
    glEnd();
    glBegin(GL_TRIANGLES);// left fan
    glVertex2f(-2.5f , 0.5f);
    glVertex2f(1.0f , -2.5f);
    glVertex2f(-30.0f , -18.0f);
    glEnd();
    glBegin(GL_TRIANGLES);//right fan
    glVertex2f(2.5f , 0.5f);
    glVertex2f(-1.0f , -2.5f);
    glVertex2f(30.0f , -15.0f);
    glEnd();
    glPopMatrix();

    int i;
	float x=55.0f; float y=305.0f; float radius =2.5f;
	int triangleAmount = 20;
	float twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(192,192,192);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
float angle2= 0.0f;
void windmill2(){
    glBegin(GL_POLYGON);// stem
    glColor3ub(192,192,192);
    glVertex2f(457.0f , 200.0f);
    glVertex2f(452.0f , 200.0f);
    glVertex2f(453.0f , 306.0f);
    glVertex2f(456.0f , 306.0f);
    glEnd();
    glBegin(GL_POLYGON);// stem shadow
    glColor3ub	(105,105,105);
    glVertex2f(458.0f , 200.0f);
    glVertex2f(452.0f , 200.0f);
    glVertex2f(500.0f , 166.0f);
    glVertex2f(500.0f , 170.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(455.0f, 305.0f, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);//fans
    glColor3ub	(128,128,128);
    glVertex2f(-2.0f , 0.0f);
    glVertex2f(2.0f , 0.0f);
    glVertex2f(0.0f , 35.0f);
    glEnd();
    glBegin(GL_TRIANGLES);//fans
    glVertex2f(-2.5f , 0.5f);
    glVertex2f(1.0f , -2.5f);
    glVertex2f(-30.0f , -18.0f);
    glEnd();
    glBegin(GL_TRIANGLES);//fans
    glVertex2f(2.5f , 0.5f);
    glVertex2f(-1.0f , -2.5f);
    glVertex2f(30.0f , -15.0f);
    glEnd();
    glPopMatrix();

    int i;
	float x=455.0f; float y=305.0f; float radius =2.5f;
	int triangleAmount = 20;
	float twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(220,220,220);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void windmillTimer(int value){
    glutPostRedisplay();
    glutTimerFunc(10, windmillTimer, 0);
        angle1 += 1.0;
}
void train(){
    glBegin(GL_POLYGON);//engine
    glColor3ub(255,255,255);
    glVertex2f(train_x_pos+90.0f, 160.0f);
    glVertex2f(train_x_pos+120.0f , 160.0f);
    glVertex2f(train_x_pos+135.0f , 134.0f);
    glVertex2f(train_x_pos+90.0f , 134.0f);
    glEnd();
    glBegin(GL_POLYGON);//engine window
    glColor3ub(0,0,0);
    glVertex2f(train_x_pos+90.0f, 150.0f);
    glVertex2f(train_x_pos+124.0f , 150.0f);
    glVertex2f(train_x_pos+119.0f , 158.0f);
    glVertex2f(train_x_pos+90.0f , 158.0f);
    glEnd();
    glBegin(GL_POLYGON);//trailer1
    glColor3ub(255,255,255);
    glVertex2f(train_x_pos+51.0f, 160.0f);
    glVertex2f(train_x_pos+89.0f , 160.0f);
    glVertex2f(train_x_pos+89.0f , 134.0f);
    glVertex2f(train_x_pos+51.0f , 134.0f);
    glEnd();
    glBegin(GL_POLYGON);// window
    glColor3ub(0,0,0);
    glVertex2f(train_x_pos+51.0f, 150.0f);
    glVertex2f(train_x_pos+89.0f , 150.0f);
    glVertex2f(train_x_pos+89.0f , 158.0f);
    glVertex2f(train_x_pos+51.0f , 158.0f);
    glEnd();
    glBegin(GL_POLYGON);//trailer2
    glColor3ub(255,255,255);
    glVertex2f(train_x_pos+15.0f, 160.0f);
    glVertex2f(train_x_pos+50.0f , 160.0f);
    glVertex2f(train_x_pos+50.0f , 134.0f);
    glVertex2f(train_x_pos+15.0f , 134.0f);
    glEnd();
    glBegin(GL_POLYGON);// window
    glColor3ub(0,0,0);
    glVertex2f(train_x_pos+16.0f, 150.0f);
    glVertex2f(train_x_pos+50.0f , 150.0f);
    glVertex2f(train_x_pos+50.0f , 158.0f);
    glVertex2f(train_x_pos+16.0f , 158.0f);
    glEnd();
}
void TrainTimer (int value){
    glutPostRedisplay();
    glutTimerFunc(10, TrainTimer, 0);

     if (train_x_pos < 600)
                train_x_pos += 1.5;
            else
        train_x_pos = -150;
}
void railline1(){
    glBegin(GL_POLYGON);//platform
    glColor3ub(192,192,192);
    glVertex2f(67.0f , 130.0f);
    glVertex2f(71.0f , 140.0f);
    glVertex2f(437.0f , 140.0f);
    glVertex2f(441.0f , 130.0f);
    glEnd();
    glBegin(GL_POLYGON);//platform left
    glColor3ub	(222,184,135);
    glVertex2f(67.0f , 127.0f);
    glVertex2f(71.0f , 140.0f);
    glVertex2f(0.0f , 140.0f);
    glVertex2f(0.0f , 127.0f);
    glEnd();
    glBegin(GL_POLYGON);//platform right
    glColor3ub(222,184,135);
    glVertex2f(500.0f , 127.0f);
    glVertex2f(500.0f , 140.0f);
    glVertex2f(437.0f , 140.0f);
    glVertex2f(441.0f , 127.0f);
    glEnd();
    glLineWidth(4.0);//track wooden plate
    glBegin(GL_LINES);
    glColor3ub	(0,0,0);
    glVertex2f(20.0f , 131.0f);
    glVertex2f(25.0f , 139.0f);
    glVertex2f(40.0f , 131.0f);
    glVertex2f(45.0f , 139.0f);
    glVertex2f(60.0f , 131.0f);
    glVertex2f(65.0f , 139.0f);
    glVertex2f(80.0f , 131.0f);
    glVertex2f(85.0f , 139.0f);
    glVertex2f(103.0f , 131.0f);
    glVertex2f(108.0f , 139.0f);
    glVertex2f(120.0f , 131.0f);
    glVertex2f(124.0f , 139.0f);
    glVertex2f(140.0f , 131.0f);
    glVertex2f(144.0f , 139.0f);
    glVertex2f(160.0f , 131.0f);
    glVertex2f(163.0f , 139.0f);
    glVertex2f(180.0f , 131.0f);
    glVertex2f(182.0f , 139.0f);
    glVertex2f(200.0f , 131.0f);
    glVertex2f(201.0f , 139.0f);
    glVertex2f(220.0f , 131.0f);
    glVertex2f(220.0f , 139.0f);
    glVertex2f(240.0f , 131.0f);
    glVertex2f(240.0f , 139.0f);
    glVertex2f(260.0f , 131.0f);
    glVertex2f(260.0f , 139.0f);
    glVertex2f(280.0f , 131.0f);
    glVertex2f(280.0f , 139.0f);
    glVertex2f(300.0f , 131.0f);
    glVertex2f(299.0f , 139.0f);
    glVertex2f(320.0f , 131.0f);
    glVertex2f(318.0f , 139.0f);
    glVertex2f(340.0f , 131.0f);
    glVertex2f(338.0f , 139.0f);
    glVertex2f(360.0f , 131.0f);
    glVertex2f(357.0f , 139.0f);
    glVertex2f(380.0f , 131.0f);
    glVertex2f(376.0f , 139.0f);
    glVertex2f(400.0f , 131.0f);
    glVertex2f(396.0f , 139.0f);
    glVertex2f(420.0f , 131.0f);
    glVertex2f(416.0f , 139.0f);
    glVertex2f(440.0f , 131.0f);
    glVertex2f(435.0f , 139.0f);
    glVertex2f(460.0f , 131.0f);
    glVertex2f(455.0f , 139.0f);
    glVertex2f(480.0f , 131.0f);
    glVertex2f(475.0f , 139.0f);
    glEnd();
    glLineWidth(2.0);//tracks
    glBegin(GL_LINES);
    glColor3ub	(255,255,255);
    glVertex2f(0.0f , 132.0f);
    glVertex2f(500.0f , 132.0f);
    glVertex2f(0.0f , 138.0f);
    glVertex2f(500.0f , 138.0f);
    glEnd();
}
void railline2(){
    glLineWidth(30.0);
    glBegin(GL_LINES);
    glColor3ub	(105,105,105);
    glVertex2f(67.0f , 128.0f);//platform base
    glVertex2f(441.0f , 128.0f);
    glVertex2f(160.0f , 122.0f);//left pillar
    glVertex2f(180.0f , 122.0f);
    glVertex2f(160.0f , 118.0f);
    glVertex2f(180.0f , 118.0f);
    glVertex2f(167.0f , 124.0f);
    glVertex2f(167.0f , 100.0f);
    glVertex2f(170.0f , 124.0f);
    glVertex2f(170.0f , 100.0f);
    glVertex2f(173.0f , 124.0f);
    glVertex2f(173.0f , 100.0f);
    glVertex2f(310.0f , 122.0f);//right pillar
    glVertex2f(330.0f , 122.0f);
    glVertex2f(310.0f , 118.0f);
    glVertex2f(330.0f , 118.0f);
    glVertex2f(317.0f , 124.0f);
    glVertex2f(317.0f , 100.0f);
    glVertex2f(320.0f , 124.0f);
    glVertex2f(320.0f , 100.0f);
    glVertex2f(323.0f , 124.0f);
    glVertex2f(323.0f , 100.0f);
    glVertex2f(100.0f , 130.0f);//steel pillars
    glVertex2f(120.0f , 170.0f);
    glVertex2f(118.0f , 170.0f);
    glVertex2f(222.0f , 170.0f);
    glVertex2f(220.0f , 170.0f);
    glVertex2f(240.0f , 130.0f);
    glVertex2f(250.0f , 130.0f);//steel pillars
    glVertex2f(270.0f , 170.0f);
    glVertex2f(268.0f , 170.0f);
    glVertex2f(373.0f , 170.0f);
    glVertex2f(370.0f , 170.0f);
    glVertex2f(390.0f , 130.0f);
    glEnd();
}
void raillineShadow() {
    glBegin(GL_POLYGON);//platform
    glColor3ub(192,192,192);
    glVertex2f(50.0f , 80.0f);
    glVertex2f(50.0f , 90.0f);
    glVertex2f(447.0f , 90.0f);
    glVertex2f(447.0f , 80.0f);
    glEnd();
    glBegin(GL_POLYGON);//pillar 1
    glColor3ub(192,192,192);
    glVertex2f(170.0f , 85.0f);
    glVertex2f(165.0f , 100.0f);
    glVertex2f(175.0f , 100.0f);
    glVertex2f(180.0f , 85.0f);
    glEnd();
    glBegin(GL_POLYGON);//pillar 2
    glColor3ub(192,192,192);
    glVertex2f(322.0f , 85.0f);
    glVertex2f(315.0f , 100.0f);
    glVertex2f(325.0f , 100.0f);
    glVertex2f(332.0f , 85.0f);
    glEnd();
    glLineWidth(20.0);//steel pillars
    glBegin(GL_LINES);
    glColor3ub(192,192,192);
    glVertex2f(116.0f , 82.0f);
    glVertex2f(140.0f , 60.0f);
    glVertex2f(140.0f , 60.0f);
    glVertex2f(240.0f , 60.0f);
    glVertex2f(239.0f , 59.0f);
    glVertex2f(255.0f , 82.0f);
    glVertex2f(265.0f , 82.0f);//
    glVertex2f(290.0f , 60.0f);
    glVertex2f(290.0f , 60.0f);
    glVertex2f(390.0f , 60.0f);
    glVertex2f(389.0f , 59.0f);
    glVertex2f(405.0f , 82.0f);
    glEnd();
}
void trainShadow(){
    glBegin(GL_POLYGON);//train engine
    glColor3ub(220,220,220);
    glVertex2f(train_x_pos+110.0f , 80.0f);
    glVertex2f(train_x_pos+160.0f , 80.0f);
    glVertex2f(train_x_pos+150.0f , 70.0f);
    glVertex2f(train_x_pos+112.0f , 70.0f);
    glEnd();
    glBegin(GL_POLYGON);//window
    glColor3ub(0,0,0);
    glVertex2f(train_x_pos+111.5f , 75.0f);
    glVertex2f(train_x_pos+154.5f , 75.0f);
    glVertex2f(train_x_pos+149.5f , 71.0f);
    glVertex2f(train_x_pos+112.5f , 71.0f);
    glEnd();
    glBegin(GL_POLYGON);//trailer 1
    glColor3ub(220,220,220);
    glVertex2f(train_x_pos+70.0f , 80.0f);
    glVertex2f(train_x_pos+109.0f, 80.0f);
    glVertex2f(train_x_pos+111.0f, 70.0f);
    glVertex2f(train_x_pos+72.0f , 70.0f);
    glEnd();
    glBegin(GL_POLYGON);//window
    glColor3ub(0,0,0);
    glVertex2f(train_x_pos+71.5f , 75.0f);
    glVertex2f(train_x_pos+108.5f , 75.0f);
    glVertex2f(train_x_pos+110.5f , 71.0f);
    glVertex2f(train_x_pos+72.5f , 71.0f);
    glEnd();
    glBegin(GL_POLYGON);//trailer 1
    glColor3ub(220,220,220);
    glVertex2f(train_x_pos+30.0f , 80.0f);
    glVertex2f(train_x_pos+69.0f, 80.0f);
    glVertex2f(train_x_pos+71.0f, 70.0f);
    glVertex2f(train_x_pos+32.0f , 70.0f);
    glEnd();
    glBegin(GL_POLYGON);//window
    glColor3ub(0,0,0);
    glVertex2f(train_x_pos+31.5f , 75.0f);
    glVertex2f(train_x_pos+68.5f , 75.0f);
    glVertex2f(train_x_pos+70.5f , 71.0f);
    glVertex2f(train_x_pos+32.5f , 71.0f);
    glEnd();
}
void tunnel1()//infront of train
{
    glBegin(GL_POLYGON);//tunnel body
    glColor3ub(255,255,255);
    glVertex2f(0.0f , 185.0f);
    glVertex2f(0.0f , 114.0f);
    glVertex2f(25.5f , 118.0f);
    glVertex2f(25.5f , 168.0f);
    glVertex2f(41.5f , 185.0f);
    glEnd();
    glBegin(GL_TRIANGLES);//mountain
    glColor3ub	(139,69,19);
    glVertex2f(0.0f , 114.0f);
    glVertex2f(25.5f , 118.0f);
    glVertex2f(0.0f , 230.0f);
    glEnd();
    glBegin(GL_TRIANGLES);//mountain
    glColor3ub(160,82,45);
    glVertex2f(30.0f , 185.0f);
    glVertex2f(13.0f , 170.0f);
    glVertex2f(0.0f , 230.0f);
    glEnd();
    glBegin(GL_POLYGON);//tunnel outward
    glColor3ub(205,205,205);
    glVertex2f(25.5f , 168.0f);
    glVertex2f(35.5f , 178.0f);
    glVertex2f(35.5f , 133.0f);
    glVertex2f(25.5f , 118.0f);
    glEnd();
    glBegin(GL_POLYGON);//tunnel
    glColor3ub(0,0,0);
    glVertex2f(30.5f , 155.0f);
    glVertex2f(35.5f , 174.0f);
    glVertex2f(35.5f , 133.0f);
    glVertex2f(30.5f , 125.0f);
    glEnd();
}
void tunnel2()// back of the train
{
    glBegin(GL_POLYGON);//tunnel outward
    glColor3ub(205,205,205);
    glVertex2f(35.5f , 178.0f);
    glVertex2f(41.5f , 185.0f);
    glVertex2f(41.5f , 147.0f);
    glVertex2f(30.5f , 124.0f);
    glEnd();
    glBegin(GL_POLYGON);//tunnel
    glColor3ub(0,0,0);
    glVertex2f(35.5f , 174.0f);
    glVertex2f(38.5f , 165.0f);
    glVertex2f(38.5f , 140.0f);
    glVertex2f(30.5f , 124.0f);
    glEnd();
}
void ferry(){
    glBegin(GL_POLYGON);//bottom
    glColor3ub(0,0,0);
    glVertex2f(ferry_x_pos+100.0f , 40.0f);
    glVertex2f(ferry_x_pos+100.0f , 30.0f);
    glVertex2f(ferry_x_pos+95.0f , 25.0f);
    glVertex2f(ferry_x_pos-5.0f , 25.0f);
    glVertex2f(ferry_x_pos-10, 30.0f);
    glVertex2f(ferry_x_pos-10, 40.0f);
    glEnd();

    glBegin(GL_POLYGON);//floor
    glColor3ub(255,255,255);
    glVertex2f(ferry_x_pos-10, 40.0f);
    glVertex2f(ferry_x_pos-7, 43.0f);
    glVertex2f(ferry_x_pos+50.0f , 43.0f);
    glVertex2f(ferry_x_pos+50.0f , 40.0f);
    glEnd();

    glBegin(GL_POLYGON);//top
    glColor3ub(255,215,0);
    glVertex2f(ferry_x_pos+50.0f , 40.0f);
    glVertex2f(ferry_x_pos+50.0f , 60.0f);
    glVertex2f(ferry_x_pos+98.0f , 60.0f);
    glVertex2f(ferry_x_pos+98.0f , 40.0f);
    glEnd();

    glBegin(GL_POLYGON);//top roof
    glColor3ub(255,255,0);
    glVertex2f(ferry_x_pos+50.0f , 60.0f);
    glVertex2f(ferry_x_pos+55.0f , 65.0f);
    glVertex2f(ferry_x_pos+93.0f , 65.0f);
    glVertex2f(ferry_x_pos+98.0f , 60.0f);
    glEnd();

    glBegin(GL_POLYGON);//window1
    glColor3ub(135,206,250);
    glVertex2f(ferry_x_pos+55.0f , 50.0f);
    glVertex2f(ferry_x_pos+55.0f , 58.0f);
    glVertex2f(ferry_x_pos+65.0f , 58.0f);
    glVertex2f(ferry_x_pos+65.0f , 50.0f);
    glEnd();

    glBegin(GL_POLYGON);//window2
    glColor3ub(135,206,250);
    glVertex2f(ferry_x_pos+70.0f , 50.0f);
    glVertex2f(ferry_x_pos+70.0f , 58.0f);
    glVertex2f(ferry_x_pos+80.0f , 58.0f);
    glVertex2f(ferry_x_pos+80.0f , 50.0f);
    glEnd();

    glBegin(GL_POLYGON);//window3
    glColor3ub(135,206,250);
    glVertex2f(ferry_x_pos+85.0f , 50.0f);
    glVertex2f(ferry_x_pos+85.0f , 58.0f);
    glVertex2f(ferry_x_pos+95.0f , 58.0f);
    glVertex2f(ferry_x_pos+95.0f , 50.0f);
    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);//railing
    glColor3ub(0,0,0);
    glVertex2f(ferry_x_pos+5.0f , 40.0f);
    glVertex2f(ferry_x_pos+5.0f , 50.0f);
    glVertex2f(ferry_x_pos+5.0f , 50.0f);
    glVertex2f(ferry_x_pos+45.0f , 50.0f);
    glVertex2f(ferry_x_pos+45.0f , 50.0f);
    glVertex2f(ferry_x_pos+45.0f , 40.0f);
    glEnd();

    glBegin(GL_POLYGON);//flag
    glColor3ub(0,128,0);
    glVertex2f(ferry_x_pos-20.0f , 80.0f);
    glVertex2f(ferry_x_pos-20.0f , 95.0f);
    glVertex2f(ferry_x_pos+5.0f , 95.0f);
    glVertex2f(ferry_x_pos+5.0f , 80.0f);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);//flag pole
    glColor3ub(0,0,0);
    glVertex2f(ferry_x_pos+5.0f , 40.0f);
    glVertex2f(ferry_x_pos+5.0f , 95.0f);
    glEnd();
    int i;
	float x=ferry_x_pos-5.0; float y=88.0; float radius =4;
	int triangleAmount = 20;
	float twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glFlush();
}
void ferryCarShadow(){
    glBegin(GL_POLYGON);//ferry shadow
    glColor3ub(105,105,105);
    glVertex2f(ferry_x_pos-10, 15.0f);
    glVertex2f(ferry_x_pos, 23.0f);
    glVertex2f(ferry_x_pos+10, 25.0f);
    glVertex2f(ferry_x_pos+110.0f , 25.0f);
    glVertex2f(ferry_x_pos+120, 23.0f);
    glVertex2f(ferry_x_pos+130.0f , 15.0f);
    glEnd();
    glBegin(GL_POLYGON);//car1 shadow
    glColor3ub(255,153,51);
    glVertex2f(car1_x_pos+25.f , 15.0f);
    glVertex2f(car1_x_pos+27.f , 10.0f);
    glVertex2f(car1_x_pos-2, 10.0f);
    glVertex2f(car1_x_pos-5, 15.0f);
    glEnd();
    glBegin(GL_POLYGON);//car2 shadow
    glColor3ub(220,20,60);
    glVertex2f(car2_x_pos+35.f , 15.0f);
    glVertex2f(car2_x_pos+37.f , 10.0f);
    glVertex2f(car2_x_pos+5, 10.0f);
    glVertex2f(car2_x_pos+2, 15.0f);
    glEnd();
    glBegin(GL_POLYGON);//top shadow
    glColor3ub	(255,250,205);
    glVertex2f(ferry_x_pos+110.f , 15.0f);
    glVertex2f(ferry_x_pos+115.f , 5.0f);
    glVertex2f(ferry_x_pos+65, 5.0f);
    glVertex2f(ferry_x_pos+60, 15.0f);
    glEnd();
    glBegin(GL_POLYGON);//top window shadow
    glColor3ub(135,206,250);
    glVertex2f(ferry_x_pos+109.f , 13.0f);
    glVertex2f(ferry_x_pos+112.f , 7.0f);
    glVertex2f(ferry_x_pos+103, 7.0f);
    glVertex2f(ferry_x_pos+100, 13.0f);
    glEnd();
    glBegin(GL_POLYGON);//top window shadow
    glColor3ub(135,206,250);
    glVertex2f(ferry_x_pos+92.f , 13.0f);
    glVertex2f(ferry_x_pos+95.f , 7.0f);
    glVertex2f(ferry_x_pos+86, 7.0f);
    glVertex2f(ferry_x_pos+83, 13.0f);
    glEnd();
    glBegin(GL_POLYGON);//top window shadow
    glColor3ub(135,206,250);
    glVertex2f(ferry_x_pos+75.f , 13.0f);
    glVertex2f(ferry_x_pos+78.f , 7.0f);
    glVertex2f(ferry_x_pos+68, 7.0f);
    glVertex2f(ferry_x_pos+65, 13.0f);
    glEnd();
    glLineWidth(2.0);//flag pole shadow
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(ferry_x_pos+10.0f, 15.0f);
    glVertex2f(ferry_x_pos+15.0f, 0.0f);
    glEnd();
}
void car1(){
    glBegin(GL_POLYGON);//body
    glColor3ub(255,153,51);
    glVertex2f(car1_x_pos+30.f , 55.0f);
    glVertex2f(car1_x_pos+30.f , 45.0f);
    glVertex2f(car1_x_pos-5, 45.0f);
    glVertex2f(car1_x_pos-5, 55.0f);
    glEnd();
    glBegin(GL_POLYGON);//top
    glVertex2f(car1_x_pos+20.f , 62.0f);
    glVertex2f(car1_x_pos+22.f , 55.0f);
    glVertex2f(car1_x_pos+3, 55.0f);
    glVertex2f(car1_x_pos+5, 62.0f);
    glEnd();
    glBegin(GL_POLYGON);//window
    glColor3ub(135,206,250);
    glVertex2f(car1_x_pos+19.f , 61.0f);
    glVertex2f(car1_x_pos+21.f , 55.0f);
    glVertex2f(car1_x_pos+4, 55.0f);
    glVertex2f(car1_x_pos+6, 61.0f);
    glEnd();
    //F wheel
    int i;
	float x=car1_x_pos+5.5f; float y=46.0; float radius1 =4.0;
	int triangleAmount1 = 20;
	float twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
			    y + (radius1 * sin(i * twicePi1 / triangleAmount1))
			);
		}
	glEnd();
	//B wheel
    int j;
	float a=car1_x_pos+20.0f; float b=46.0; float radius2 =4.0;
	int triangleAmount2 = 20;
	float twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 0, 0);
		glVertex2f(a, b); // center of circle
		for(j = 0; j <= triangleAmount2;j++) {
			glVertex2f(
		            a + (radius2 * cos(j *  twicePi2 / triangleAmount2)),
			    b + (radius2 * sin(j * twicePi2 / triangleAmount2))
			);
		}
	glEnd();
    glFlush();
}
void car2(){
    glBegin(GL_POLYGON);//body
    glColor3ub(220,20,60);
    glVertex2f(car2_x_pos+30.f , 55.0f);
    glVertex2f(car2_x_pos+30.f , 45.0f);
    glVertex2f(car2_x_pos-5, 45.0f);
    glVertex2f(car2_x_pos-5, 55.0f);
    glEnd();
    glBegin(GL_POLYGON);//top
    glVertex2f(car2_x_pos+20.f , 62.0f);
    glVertex2f(car2_x_pos+22.f , 55.0f);
    glVertex2f(car2_x_pos+3, 55.0f);
    glVertex2f(car2_x_pos+5, 62.0f);
    glEnd();
    glBegin(GL_POLYGON);//window
    glColor3ub(135,206,250);
    glVertex2f(car2_x_pos+19.f , 61.0f);
    glVertex2f(car2_x_pos+21.f , 55.0f);
    glVertex2f(car2_x_pos+4, 55.0f);
    glVertex2f(car2_x_pos+6, 61.0f);
    glEnd();
    //F wheel
    int i;
	float x=car2_x_pos+5.5f; float y=46.0; float radius1 =4.0;
	int triangleAmount1 = 20;
	float twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount1;i++) {
			glVertex2f(
		            x + (radius1 * cos(i *  twicePi1 / triangleAmount1)),
			    y + (radius1 * sin(i * twicePi1 / triangleAmount1))
			);
		}
	glEnd();
	//B wheel
    int j;
	float a=car2_x_pos+20.0f; float b=46.0; float radius2 =4.0;
	int triangleAmount2 = 20;
	float twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 0, 0);
		glVertex2f(a, b); // center of circle
		for(j = 0; j <= triangleAmount2;j++) {
			glVertex2f(
		            a + (radius2 * cos(j *  twicePi2 / triangleAmount2)),
			    b + (radius2 * sin(j * twicePi2 / triangleAmount2))
			);
		}
	glEnd();
    glFlush();
}
float sun_x_pos=90.0f;
float sun_y_pos= 300.0f;
void sun()
{
    int i;

	float x=sun_x_pos; float y=sun_y_pos; float radius =20.0;
	int triangleAmount = 20;
	float twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 255, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void sunTimer(int value){
    glutPostRedisplay();
    glutTimerFunc(10, sunTimer, 0);

     if (sun_y_pos < 400.0f)
                sun_y_pos += 1.5;
            else
        sun_y_pos = 400.0f;
}
void river(){
    glBegin(GL_POLYGON);
    glColor3ub(64,224,208);
    glVertex2f(0.0f , 0.0f);
    glVertex2f(500.0f , 0.0f);
    glVertex2f(500.0f , 220.0f);
    glVertex2f(0.0f , 220.0f);
    glEnd();
}
void sky_day(){
    glBegin(GL_POLYGON);
    glColor3ub(135,206,250);
    glVertex2f(0.0f , 220.0f);
    glVertex2f(500.0f , 220.0f);
    glVertex2f(500.0f , 500.0f);
    glVertex2f(0.0f , 500.0f);
    glEnd();
}
void cityScape(){
    glBegin(GL_POLYGON);//city bed
    glColor3ub(176,196,222);
    glVertex2f(0.0f , 220.0f);
    glVertex2f(500.0f , 220.0f);
    glVertex2f(500.0f , 225.0f);
    glVertex2f(0.0f , 225.0f);
    glEnd();
    glBegin(GL_POLYGON);//city bed water shade
    glColor3ub	(72,209,204);
    glVertex2f(0.0f , 215.0f);
    glVertex2f(500.0f , 210.0f);
    glVertex2f(500.0f , 220.0f);
    glVertex2f(0.0f , 220.0f);
    glEnd();
    glBegin(GL_POLYGON);//small buildings 8 left
    glColor3ub(245,245,245);
    glVertex2f(190.0f , 225.0f);
    glVertex2f(170.0f , 225.0f);
    glVertex2f(170.0f , 245.0f);
    glVertex2f(190.0f , 245.0f);
    glEnd();
    glBegin(GL_POLYGON);//small buildings 9 left
    glColor3ub(245,245,245);
    glVertex2f(170.0f , 225.0f);
    glVertex2f(100.0f , 225.0f);
    glVertex2f(100.0f , 236.0f);
    glVertex2f(170.0f , 236.0f);
    glEnd();
    glBegin(GL_POLYGON);//small buildings 10 right
    glColor3ub(245,245,245);
    glVertex2f(330.0f , 225.0f);
    glVertex2f(310.0f , 225.0f);
    glVertex2f(310.0f , 250.0f);
    glVertex2f(330.0f , 250.0f);
    glEnd();
    glBegin(GL_POLYGON);//small buildings 11 right
    glColor3ub(245,245,245);
    glVertex2f(370.0f , 225.0f);
    glVertex2f(330.0f , 225.0f);
    glVertex2f(330.0f , 236.0f);
    glVertex2f(370.0f , 236.0f);
    glEnd();
    glBegin(GL_POLYGON);//background shadow building
    glColor3ub(220,220,220);
    glVertex2f(315.0f , 225.0f);
    glVertex2f(185.0f , 225.0f);
    glVertex2f(185.0f , 260.0f);
    glVertex2f(315.0f , 260.0f);
    glEnd();
    glBegin(GL_POLYGON);//building 1 tallest
    glColor3ub(211,211,211);
    glVertex2f(245.0f , 225.0f);
    glVertex2f(265.0f , 225.0f);
    glVertex2f(265.0f , 315.0f);
    glVertex2f(255.0f , 330.0f);
    glVertex2f(245.0f , 315.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);//building 1 border
    glColor3ub	(169,169,169);
    glVertex2f(265.0f , 225.0f);
    glVertex2f(265.0f , 315.0f);
    glVertex2f(265.0f , 315.0f);
    glVertex2f(255.0f , 330.0f);
    glVertex2f(255.0f , 330.0f);
    glVertex2f(245.0f , 315.0f);
    glVertex2f(245.0f , 315.0f);
    glVertex2f(245.0f , 225.0f);
    glEnd();
    glBegin(GL_POLYGON);//building 2
    glColor3ub(211,211,211);
    glVertex2f(300.0f , 225.0f);
    glVertex2f(310.0f , 225.0f);
    glVertex2f(310.0f , 270.0f);
    glVertex2f(300.0f , 270.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);//building 2 border
    glColor3ub	(169,169,169);
    glVertex2f(310.0f , 225.0f);
    glVertex2f(310.0f , 270.0f);
    glVertex2f(310.0f , 270.0f);
    glVertex2f(300.0f , 270.0f);
    glVertex2f(300.0f , 270.0f);
    glVertex2f(300.0f , 225.0f);
    glEnd();
    glBegin(GL_POLYGON);//building 3
    glColor3ub(211,211,211);
    glVertex2f(190.0f , 225.0f);
    glVertex2f(205.0f , 225.0f);
    glVertex2f(205.0f , 270.0f);
    glVertex2f(190.0f , 270.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);//building 3 border
    glColor3ub	(169,169,169);
    glVertex2f(205.0f , 225.0f);
    glVertex2f(205.0f , 270.0f);
    glVertex2f(205.0f , 270.0f);
    glVertex2f(190.0f , 270.0f);
    glVertex2f(190.0f , 270.0f);
    glVertex2f(190.0f , 225.0f);
    glEnd();
    glBegin(GL_POLYGON);//building 4 tall right
    glColor3ub(211,211,211);
    glVertex2f(295.0f , 225.0f);
    glVertex2f(280.0f , 225.0f);
    glVertex2f(280.0f , 310.0f);
    glVertex2f(295.0f , 310.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);//building 4 border
    glColor3ub	(169,169,169);
    glVertex2f(280.0f , 225.0f);
    glVertex2f(280.0f , 310.0f);
    glVertex2f(280.0f , 310.0f);
    glVertex2f(295.0f , 310.0f);
    glVertex2f(295.0f , 310.0f);
    glVertex2f(295.0f , 225.0f);
    glEnd();
    glBegin(GL_POLYGON);//building 5 tall left
    glColor3ub(211,211,211);
    glVertex2f(230.0f , 225.0f);
    glVertex2f(210.0f , 225.0f);
    glVertex2f(210.0f , 300.0f);
    glVertex2f(230.0f , 300.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);//building 5 border
    glColor3ub	(169,169,169);
    glVertex2f(210.0f , 225.0f);
    glVertex2f(210.0f , 300.0f);
    glVertex2f(210.0f , 300.0f);
    glVertex2f(230.0f , 300.0f);
    glVertex2f(230.0f , 300.0f);
    glVertex2f(230.0f , 225.0f);
    glEnd();
    glBegin(GL_POLYGON);//building 6
    glColor3ub(211,211,211);
    glVertex2f(245.0f , 225.0f);
    glVertex2f(233.0f , 225.0f);
    glVertex2f(233.0f , 280.0f);
    glVertex2f(245.0f , 280.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);//building 6 border
    glColor3ub	(169,169,169);
    glVertex2f(233.0f , 225.0f);
    glVertex2f(233.0f , 280.0f);
    glVertex2f(233.0f , 280.0f);
    glVertex2f(245.0f , 280.0f);
    glVertex2f(245.0f , 280.0f);
    glVertex2f(245.0f , 225.0f);
    glEnd();
    glBegin(GL_POLYGON);//building 7
    glColor3ub(211,211,211);
    glVertex2f(280.0f , 225.0f);
    glVertex2f(268.0f , 225.0f);
    glVertex2f(268.0f , 280.0f);
    glVertex2f(280.0f , 280.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);//building 7 border
    glColor3ub	(169,169,169);
    glVertex2f(268.0f , 225.0f);
    glVertex2f(268.0f , 280.0f);
    glVertex2f(268.0f , 280.0f);
    glVertex2f(280.0f , 280.0f);
    glVertex2f(280.0f , 280.0f);
    glVertex2f(280.0f , 225.0f);
    glEnd();
}
void leftBank(){
    glBegin(GL_TRIANGLES);
    glColor3ub(60,179,113);
    glVertex2f(0.0f , 0.0f);
    glVertex2f(100.0f , 200.0f);
    glVertex2f(0.0f , 200.0f);
    glEnd();
    glBegin(GL_POLYGON);//road
    glColor3ub(112,128,144);
    glVertex2f(0.0f , 45.0f);
    glVertex2f(25.0f , 45.0f);
    glVertex2f(14.0f , 30.0f);
    glVertex2f(0.0f , 30.0f);
    glEnd();
    glBegin(GL_POLYGON);//zigzag bank
    glColor3ub(60,179,113);
    glVertex2f(26.0f , 53.0f);
    glVertex2f(90.0f , 130.0f);
    glVertex2f(90.0f , 160.0f);
    glVertex2f(80.0f , 160.0f);
    glEnd();
    glBegin(GL_POLYGON);//zigzag bank 2
    glColor3ub(60,179,113);
    glVertex2f(90.0f , 160.0f);
    glVertex2f(80.0f , 160.0f);
    glVertex2f(100.0f , 200.0f);
    glVertex2f(120.0f , 200.0f);
    glEnd();
    glBegin(GL_POLYGON);//zigzag bank brown part
    glColor3ub(210,180,140);
    glVertex2f(0.0f , 0.0f);
    glVertex2f(10.0f , 0.0f);
    glVertex2f(35.0f , 55.0f);
    glVertex2f(25.0f , 55.0f);
    glEnd();
    glBegin(GL_POLYGON);//zigzag bank brown part
    glColor3ub(210,180,140);
    glVertex2f(25.0f , 55.0f);
    glVertex2f(35.0f , 55.0f);
    glVertex2f(100.0f , 140.0f);
    glVertex2f(90.0f , 140.0f);
    glEnd();
    glBegin(GL_POLYGON);//zigzag bank brown part
    glColor3ub(210,180,140);
    glVertex2f(90.0f , 160.0f);
    glVertex2f(90.0f , 152.0f);
    glVertex2f(125.0f , 200.0f);
    glVertex2f(120.0f , 200.0f);
    glEnd();
}
void rightBank(){
    glBegin(GL_TRIANGLES);
    glColor3ub(60,179,113);
    glVertex2f(500.0f , 200.0f);
    glVertex2f(400.0f , 200.0f);
    glVertex2f(500.0f , 0.0f);
    glEnd();
    glBegin(GL_POLYGON);//road
    glColor3ub(112,128,144);
    glVertex2f(500.0f , 45.0f);
    glVertex2f(475.0f , 45.0f);
    glVertex2f(486.0f , 30.0f);
    glVertex2f(500.0f , 30.0f);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(500.0f , 37.0f);
    glVertex2f(480.0f , 37.0f);
    glEnd();
    glLineWidth(30.0);
    glBegin(GL_LINES);//zigzag bank
    glColor3ub(210,180,140);
    glVertex2f(499.0f , 0.0f);
    glVertex2f(474.0f , 50.0f);
    glVertex2f(474.0f , 50.0f);
    glVertex2f(409.0f , 128.0f);
    glVertex2f(410.0f , 157.0f);
    glVertex2f(379.0f , 198.0f);
    glEnd();
    glBegin(GL_POLYGON);//zigzag bank
    glColor3ub(60,179,113);
    glVertex2f(474.0f , 53.0f);
    glVertex2f(410.0f , 130.0f);
    glVertex2f(410.0f , 160.0f);
    glVertex2f(420.0f , 160.0f);
    glEnd();
    glBegin(GL_POLYGON);//zigzag bank 2
    glColor3ub(60,179,113);
    glVertex2f(410.0f , 160.0f);
    glVertex2f(420.0f , 160.0f);
    glVertex2f(400.0f , 200.0f);
    glVertex2f(380.0f , 200.0f);
    glEnd();
}
void mountain(){
    glBegin(GL_TRIANGLES);//left
    glColor3ub(255,228,181);
    glVertex2f(0.0f , 200.0f);
    glVertex2f(180.0f , 200.0f);
    glVertex2f(0.0f , 400.0f);
    glEnd();
    glBegin(GL_TRIANGLES);//right
    glColor3ub(255,228,181);
    glVertex2f(500.0f , 200.0f);
    glVertex2f(320.0f , 200.0f);
    glVertex2f(500.0f , 400.0f);
    glEnd();
}
void Display(void)
{
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glPointSize(5.0);
sky_day();
sun();
river();
cityScape();
trainShadow();
raillineShadow();
ferryCarShadow();
leftBank();
rightBank();
mountain();
car1();
car2();
ferry();
railline1();
tunnel2();
train();
railline2();
tunnel1();
windmill1();
windmill2();
glutSwapBuffers();
}

void FerryTimer(int)
{
    bool f=false, c1=false, c2=false;
    glutPostRedisplay();
    glutTimerFunc(10, FerryTimer, 0);

    switch (state){

    case 3 :    if (car1_x_pos < 45)
                        car1_x_pos += 1.0;
                else
                        {car1_x_pos += 0;
                        state = 1;
                        c1=true;}
                break;

    case 1 :    while (c1=true)
                    {if ((ferry_x_pos <380.0)&&(car1_x_pos < 395))
                        {ferry_x_pos += 0.7;
                        car1_x_pos += 0.7;}
                    else
                        {ferry_x_pos += 0;
                        car1_x_pos +=0;
                        state= -3;
                        f=true;}
                break;}
                break;

    case -1  :   if (car2_x_pos >395.0)
                    {car2_x_pos += -1.0;
                    ferry_x_pos += 0;}
                else
                    {car2_x_pos += 0;
                    state = 2;
                    c2=true;}
                break;
    case 2 :    while ((f=true) && (c2=true))
                    {if ((ferry_x_pos > 30) && (car2_x_pos > 45))
                        {car2_x_pos += -0.7;
                        ferry_x_pos += -0.7;}
                    else
                        {ferry_x_pos += -0;
                        car2_x_pos += -0;
                        state = -2;
                        f=false;}
                        break;}
                break;

    case -2 :   if (car2_x_pos > -20)
                    car2_x_pos += -1.0;
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
glutInitWindowSize (1240, 900);
glutInitWindowPosition (200, 100);
glutCreateWindow ("PROJECT");
glutDisplayFunc(Display);

glutTimerFunc(10,FerryTimer,0);
glutTimerFunc(10,TrainTimer,0);
glutTimerFunc(10,windmillTimer,0);
glutTimerFunc(10,sunTimer, 0);
Init();
glutMainLoop();
return 0;
}
