#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/gl.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <math.h>
#include<mmsystem.h>
#include<MMSystem.h>
#include<math.h>>
#include<time.h>
# define PI           3.14159265358979323846



GLfloat position = 0.0f;
GLfloat speed = 0.09f;
GLfloat position2 = 0.0f;
GLfloat speed2 = 0.06f;

GLfloat position7 = 0.0f;
GLfloat speed7 = 0.05f;
GLfloat position8 = 0.0f;
GLfloat speed8 = 0.04f;
//aeroplane
GLfloat position3 = 0.0f;
GLfloat speed3 = 0.02f;
//cloud move
GLfloat position4 = 0.0f;
GLfloat speed4 = 0.001f;
GLfloat position5 = 0.0f;
GLfloat speed5 = 0.001f;
//sun
GLfloat position6 = 0.0f;
GLfloat speed6 = 0.0001f;
//rain
GLfloat position11 = 3.5f;
GLfloat speed11 = 0.09f;

GLfloat position12 = 2.0f;
GLfloat speed12 = 0.09f;
///Sun
void update6(int value)
{
    if(position6 >.8)
        position6 = 1.0f;
    position6 += speed6;
    glutPostRedisplay();
    glutTimerFunc(100, update6, 0);
}
///Car move
void update(int value)
{
    if(position >1.8)
        position = -1.0f;
    position += speed;
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}
///Bus move
void update2(int value)
{
    if(position2 <-1.8)
        position2 = 1.8f;
    position2 -= speed2;
    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);
}
///BRTC move
void update7(int value)
{
    if(position7 >1.8)
        position7 = -1.8f;
    position7 += speed7;
    glutPostRedisplay();
    glutTimerFunc(100, update7, 0);
}
///BMW move
void update8(int value)
{
    if(position8 <-1.8)
        position8 = 1.8f;
    position8 -= speed8;
    glutPostRedisplay();
    glutTimerFunc(100, update8, 0);
}
///AEROPLANE move
void update3(int value)
{
    if(position3 >1.8)
        position3 = -1.0f;
    position3 += speed3;
    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}
///cloud1 move
void update4(int value)
{
    if(position4 >1.8)
        position4 = -1.0f;
    position4 += speed4;
    glutPostRedisplay();
    glutTimerFunc(100, update4, 0);
}
///cloud2 move
void update5(int value)
{
    if(position5 <-1.8)
        position5 = 1.8f;
    position5 -= speed5;
    glutPostRedisplay();
    glutTimerFunc(100, update5, 0);
}
/// rain 01
void update11(int value)
{
    if(position11 < -1.0)
        position11 = 2.0f;
    position11 -= speed11;
    glutPostRedisplay();
    glutTimerFunc(100, update11, 0);
}

/// rain 02
void update12(int value)
{
    if(position12 < -1.0)
        position12 = 2.0f;
    position12 -= speed12;
    glutPostRedisplay();
    glutTimerFunc(100, update12, 0);
}

//

using namespace std;


bool night = false;
bool rain = false;
bool cover = false;
bool sound = false;

//float _run1 = 0;

void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void circle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 100; //# of lines used to draw circle

    GLfloat twicePi = 2.0f * PI;

    //glColor3ub(255,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(2);

    //SKY
    /*
    glBegin(GL_POLYGON);
    glColor3ub(176,226,255);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -0.2f);
    glEnd();
    */

    if(!night)
    {

        glBegin(GL_POLYGON);
        glColor3ub(0,178,238);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, -0.2f);
    }

    if(rain && !night)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.18, 0.36, 0.56);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, -0.2f);
    }

    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(40,40,40);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, -0.2f);
    }
    glEnd();
    ///***************************************Star**************
    if(night)
    {
        glColor3ub(255,255,0);
        circle(-0.55f,0.8f,0.001f);
        circle(-0.7f, 0.88f,0.0025f);
        circle(-0.55f,0.8f,0.0018f);
        circle(-0.7f, 0.88f,0.001f);
        circle(-0.55f,0.8f,0.002f);

        circle(-0.78f, 0.98f,0.0021f);
        circle(-0.6f,0.8f,0.0018f);
        circle(-0.7f, 0.68f,0.0011f);
        circle(-0.65f,0.69f,0.0018f);

        circle(0.78f, 0.88f,0.001f);
        circle(0.9f,0.8f,0.0025f);
        circle(0.55f,0.8f,0.001f);
        circle(0.7f, 0.88f,0.0023f);
        circle(0.55f,0.8f,0.0022f);
        circle(0.7f, 0.88f,0.001f);
        circle(0.55f,0.8f,0.002f);

        circle(0.78f, 0.98f,0.003f);
        circle(0.6f,0.8f,0.0019f);
        circle(0.7f, 0.68f,0.0021f);
        circle(0.65f,0.69f,0.0009f);
        //2
        circle(-0.45f,0.8f,0.001f);
        circle(-0.3f, 0.88f,0.0025f);
        circle(-0.25f,0.8f,0.0026f);
        circle(-0.1f, 0.88f,0.001f);
        circle(-0.15f,0.8f,0.002f);

        circle(-0.28f, 0.98f,0.0015f);
        circle(-0.3f,0.8f,0.0016f);
        circle(-0.17f, 0.68f,0.0021f);
        circle(-0.25f,0.69f,0.0022f);


        circle(0.45f,0.8f,0.001f);
        circle(0.3f, 0.88f,0.0025f);
        circle(0.25f,0.8f,0.0022f);
        circle(0.1f, 0.88f,0.001f);
        circle(0.15f,0.8f,0.002f);

        circle(0.28f, 0.98f,0.0015f);
        circle(0.3f,0.8f,0.0028f);
        circle(0.17f, 0.68f,0.0021f);
        circle(0.25f,0.69f,0.0014f);
        //
        circle(-0.95f,-0.8f,0.001f);
        circle(-0.92f, -0.88f,0.0025f);
        circle(-0.88f,0.8f,0.0021f);
        circle(-0.78f, 0.88f,0.001f);

        circle(-0.1f, -0.98f,0.0005f);
        circle(-0.98f,-0.8f,0.0009f);
        circle(-0.96f, 0.68f,0.0021f);
        circle(-0.6f,-0.69f,0.0023f);

        circle(0.95f,-0.8f,0.001f);
        circle(0.92f, -0.88f,0.0025f);
        circle(0.88f,0.8f,0.0023f);
        circle(0.78f, 0.88f,0.001f);
        circle(0.73f,-0.8f,0.002f);

        circle(0.1f, -0.98f,0.00235f);
        circle(0.98f,-0.8f,0.0013f);
        circle(0.96f, 0.68f,0.0021f);
        circle(0.6f,-0.69f,0.0013f);
        //---are not visible
        circle(-0.55f,-0.1f,0.001f);
        circle(-0.7f, -0.2f,0.0025f);
        circle(-0.55f,-0.3f,0.0018f);
        circle(-0.7f, -0.4f,0.001f);
        circle(-0.55f,-0.5f,0.002f);

        circle(-0.78f, -0.6f,0.0021f);
        circle(-0.6f,-0.8f,0.0018f);
        circle(-0.7f, -0.7f,0.021f);
        circle(-0.65f,-0.8f,0.0018f);

        circle(0.78f, -0.88f,0.001f);
        circle(0.9f,-0.9f,0.0025f);
        circle(0.55f,-0.1f,0.001f);
        circle(0.7f, -0.25f,0.0023f);
        circle(0.55f,-0.38f,0.0022f);
        circle(0.7f, -0.48f,0.001f);
        circle(0.55f,-0.5f,0.002f);

        circle(0.78f, -0.98f,0.003f);
        circle(0.6f,-0.68f,0.0019f);
        circle(0.7f, -0.78f,0.0021f);
        circle(0.65f,-0.89f,0.0009f);
        //2
        circle(-0.45f,-0.88f,0.001f);
        circle(-0.3f, -0.98f,0.0025f);
        circle(-0.25f,-0.18f,0.0026f);
        circle(-0.1f, -0.28f,0.001f);
        circle(-0.15f,-0.38f,0.002f);

        circle(-0.28f, -0.48f,0.0015f);
        circle(-0.3f,-0.4f,0.0016f);
        circle(-0.17f, -0.68f,0.021f);
        circle(-0.25f,-0.59f,0.0022f);


        circle(0.45f,-0.68f,0.001f);
        circle(0.3f, -0.88f,0.0025f);
        circle(0.25f,-0.78f,0.0022f);
        circle(0.1f, -0.78f,0.001f);
        circle(0.15f,-0.78f,0.002f);

        circle(0.28f, -0.48f,0.0015f);
        circle(0.3f,-0.48f,0.0028f);
        circle(0.17f, -0.68f,0.021f);
        circle(0.25f,-0.69f,0.0014f);
        //
        circle(-0.95f,-0.8f,0.001f);
        circle(-0.92f, -0.88f,0.0025f);
        circle(-0.88f,-0.8f,0.0021f);
        circle(-0.78f, -0.88f,0.001f);

        circle(-0.1f, -0.98f,0.0005f);
        circle(-0.98f,-0.8f,0.0009f);
        circle(-0.96f, -0.68f,0.021f);
        circle(-0.6f,-0.69f,0.0023f);

        circle(0.95f,-0.68f,0.001f);
        circle(0.92f, -0.88f,0.0025f);
        circle(0.88f,-0.48f,0.0023f);
        circle(0.78f, -0.488f,0.001f);
        circle(0.73f,-0.58f,0.002f);

        circle(0.1f, -0.68f,0.00235f);
        circle(0.98f,-0.78f,0.0013f);
        circle(0.96f, -0.68f,0.021f);
        circle(0.6f,-0.69f,0.0013f);


    }
    ///***************************************SUN move**************
    //
    glPushMatrix();
    glTranslatef(position4,-position4,  -0.0f);
    //sun
    glColor3ub(255,255,0);
    circle(0.4f,0.95f,0.1f);

    if(night)
    {
        glColor3ub(255,250,250);
        circle(0.4f,0.95f,0.1f);
    }
    glPopMatrix();



    ///**********************************************cloud1 move******
    glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);
    //cloud 1
    glColor3ub(240,240,240);
    circle(-0.4f,0.8f,0.05f);
    glColor3ub(240,240,240);
    circle(-0.35f,0.75f,0.05f);
    glColor3ub(240,240,240);
    circle(-0.35f,0.85f,0.05f);
    glColor3ub(240,240,240);
    circle(-0.3f,0.8f,0.05f);
    glColor3ub(240,240,240);
    circle(-0.25f,0.85f,0.05f);

    //
    if(night)
    {
        glColor3ub(40,40,40);
        circle(-0.4f,0.8f,0.05f);
        glColor3ub(40,40,40);
        circle(-0.35f,0.75f,0.05f);
        glColor3ub(40,40,40);
        circle(-0.35f,0.85f,0.05f);
        glColor3ub(40,40,40);
        circle(-0.3f,0.8f,0.05f);
        glColor3ub(40,40,40);
        circle(-0.25f,0.85f,0.05f);
    }
    glPopMatrix();



    ///**************************************************cloud2 move******
    glPushMatrix();
    glTranslatef(position5,0.0f, 0.0f);
    //CLOUD 2
    glColor3ub(240,240,240);
    circle(0.4f,0.8f,0.05f);
    glColor3ub(240,240,240);
    circle(0.35f,0.75f,0.05f);
    glColor3ub(240,240,240);
    circle(0.35f,0.85f,0.05f);
    glColor3ub(240,240,240);
    circle(0.3f,0.8f,0.05f);
    glColor3ub(240,240,240);
    circle(0.25f,0.85f,0.05f);
    glColor3ub(240,240,240);
    circle(0.3f,0.9f,0.05f);
    //
    if(night)
    {
        glColor3ub(40,40,40);
        circle(0.4f,0.8f,0.05f);
        glColor3ub(40,40,40);
        circle(0.35f,0.75f,0.05f);
        glColor3ub(40,40,40);
        circle(0.35f,0.85f,0.05f);
        glColor3ub(40,40,40);
        circle(0.3f,0.8f,0.05f);
        glColor3ub(40,40,40);
        circle(0.25f,0.85f,0.05f);
        glColor3ub(40,40,40);
        circle(0.3f,0.9f,0.05f);
    }

    glPopMatrix();
    //


    /*
    	//AEROPLANE
    	glBegin(GL_LINE_LOOP);
    	glColor3ub(176,0,0);
    	glVertex2f(-0.53f, 0.8f);
    	glVertex2f(-0.53f, 0.82f);
    	glVertex2f(-0.6f, 0.85f);
    	glVertex2f(-0.66f, 0.85f);
    	glVertex2f(-0.83f, 0.93f);
    	glVertex2f(-0.85f, 0.93f);
    	glVertex2f(-0.75f, 0.85f);
    	glVertex2f(-0.9f, 0.85f);
    	glVertex2f(-0.93f, 0.9f);
    	glVertex2f(-0.95f, 0.9f);
    	glVertex2f(-0.95f, 0.8f);
    	glVertex2f(-0.82f, 0.8f);
    	glVertex2f(-0.9f, 0.75f);
    	glVertex2f(-0.87f, 0.75f);
    	glVertex2f(-0.75f, 0.8f);
    	glVertex2f(-0.63f, 0.8f);
    	glVertex2f(-0.62f, 0.78f);
    	glVertex2f(-0.61f, 0.8f);
    	glEnd();
        */


    ///**************************************AEROPLANE Move*************
    glPushMatrix();
    glTranslatef(position3,0.0f, 0.0f);
    //AEROPLANE
    glBegin(GL_POLYGON);
    glColor3ub(237, 249, 244);

    glVertex2f(-0.55f, 0.8f);
    glVertex2f(-0.55f, 0.82f);
    glColor3ub(219,0,0);
    glVertex2f(-0.7f, 0.88f);
    glVertex2f(-0.7f, 0.80f);
    glEnd();
    //lightpoint
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    //if(night)
    //{
      //  glColor3f(0.9f,0.9f,0.0f);
    //}
    glVertex2f(-0.55f, 0.8f);
    glVertex2f(-0.55f, 0.82f);
//1
    glBegin(GL_POLYGON);
    glColor3ub(209, 218, 225);
    glVertex2f(-0.58f, 0.81f);
    glVertex2f(-0.58f, 0.825f);
    glVertex2f(-0.63f, 0.84f);
    glVertex2f(-0.63f, 0.81f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(200,200,200);
    glVertex2f(-0.64f, 0.81f);
    glVertex2f(-0.64f, 0.84f);
    glVertex2f(-0.69f, 0.84f);
    glVertex2f(-0.69f, 0.81f);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3ub(219,0,0);
    glVertex2f(-0.7f, 0.88f);
    glVertex2f(-0.7f, 0.80f);
    glColor3ub(237, 249, 244);
    glVertex2f(-0.84f, 0.8f);
    glVertex2f(-0.84f, 0.85f);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glColor3ub(200,200,200);
    glVertex2f(-0.7f, 0.81f);
    glVertex2f(-0.7f, 0.84f);
    glVertex2f(-0.75f, 0.84f);
    glVertex2f(-0.75f, 0.81f);
    glEnd();
    //

    glBegin(GL_POLYGON);
    glColor3ub(82,0,221);
    glVertex2f(-0.84f, 0.8f);
    glVertex2f(-0.84f, 0.85f);
    glVertex2f(-0.88f, 0.9f);
    glVertex2f(-0.9f, 0.9f);
    glVertex2f(-0.9f, 0.8f);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glColor3ub(200,200,200);
    glVertex2f(-0.76f, 0.81f);
    glVertex2f(-0.76f, 0.84f);
    glVertex2f(-0.81f, 0.84f);
    glVertex2f(-0.81f, 0.81f);
    glEnd();
    //

    glBegin(GL_POLYGON);
    glColor3ub(82,0,221);
    glVertex2f(-0.7f, 0.88f);
    glVertex2f(-0.74f, 0.95f);
    glVertex2f(-0.77f, 0.95f);
    glVertex2f(-0.74f, 0.87f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(82,0,221);
    glVertex2f(-0.7f, 0.8f);
    glVertex2f(-0.75f, 0.8f);
    glVertex2f(-0.76f, 0.73f);
    glVertex2f(-0.74f, 0.71f);
    glEnd();

    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(200,200,200);
        glVertex2f(-0.55f, 0.8f);
        glVertex2f(-0.55f, 0.82f);
        glColor3ub(40,40,40);
        glVertex2f(-0.45f, 0.85f);
        glVertex2f(-0.45f, 0.75f);
        glEnd();

    }


    glPopMatrix();



    ///*************************************ROAD*****
    glBegin(GL_POLYGON);
    glColor3ub(38,38,38);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, -1.0f);
    glEnd();

    ///ROAD DEVIDER 1
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.9f, -0.84f);
    glVertex2f(-0.9f, -0.86f);
    glVertex2f(-0.7f, -0.86f);
    glVertex2f(-0.7f, -0.84f);
    glEnd();

    ///ROAD DEVIDER 2
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.4f, -0.84f);
    glVertex2f(-0.4f, -0.86f);
    glVertex2f(-0.2f, -0.86f);
    glVertex2f(-0.2f, -0.84f);
    glEnd();

    ///ROAD DEVIDER 3
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.1f, -0.84f);
    glVertex2f(0.1f, -0.86f);
    glVertex2f(0.3f, -0.86f);
    glVertex2f(0.3f, -0.84f);
    glEnd();

    ///ROAD DEVIDER 4
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.6f, -0.84f);
    glVertex2f(0.6f, -0.86f);
    glVertex2f(0.8f, -0.86f);
    glVertex2f(0.8f, -0.84f);
    glEnd();

    ///***********************************************FIELD
    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.7f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(57, 93, 67);
        glVertex2f(-1.0f, -0.7f);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f(1.0f, -0.4f);
        glVertex2f(1.0f, -0.7f);
        glEnd();
    }

    ///*********************************************Tree 1
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(-0.71f, -0.55f);
    glVertex2f(-0.73f, -0.55f);
    glVertex2f(-0.73f, -0.65f);
    glVertex2f(-0.71f, -0.65f);
    glEnd();

    glColor3ub(0,139,0);
    circle(-0.72f,-0.5f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.75f,-0.55f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.7f,-0.55f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(-0.71f, -0.55f);
        glVertex2f(-0.73f, -0.55f);
        glVertex2f(-0.73f, -0.65f);
        glVertex2f(-0.71f, -0.65f);
        glEnd();

        glColor3ub(23, 78, 43);
        circle(-0.72f,-0.5f,0.04f);
        glColor3ub(23, 78, 43);
        circle(-0.75f,-0.55f,0.04f);
        glColor3ub(23, 78, 43);
        circle(-0.7f,-0.55f,0.04f);

    }

    ///Tree 2
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(0.71f, -0.55f);
    glVertex2f(0.73f, -0.55f);
    glVertex2f(0.73f, -0.65f);
    glVertex2f(0.71f, -0.65f);
    glEnd();

    glColor3ub(0,139,0);
    circle(0.72f,-0.5f,0.04f);
    glColor3ub(0,139,0);
    circle(0.75f,-0.55f,0.04f);
    glColor3ub(0,139,0);
    circle(0.7f,-0.55f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(0.71f, -0.55f);
        glVertex2f(0.73f, -0.55f);
        glVertex2f(0.73f, -0.65f);
        glVertex2f(0.71f, -0.65f);
        glEnd();

        glColor3ub(23, 82, 43);
        circle(0.72f,-0.5f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.75f,-0.55f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.7f,-0.55f,0.04f);

    }



    ///************************BASEMENT OF PARLIAMENT
    glBegin(GL_POLYGON);
    glColor3ub(139,37,0);
    glVertex2f(-1.0f, -0.4f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -0.4f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(139,37,0);
        glVertex2f(-1.0f, -0.4f);
        glColor3ub(195, 177, 104);
        glVertex2f(-1.0f, -0.2f);
        glColor3ub(139,37,0);
        glVertex2f(1.0f, -0.2f);
        glColor3ub(195, 177, 104);
        glVertex2f(1.0f, -0.4f);
        glEnd();
    }

    //BASEMENT LEFT STAIRS 1
    glBegin(GL_POLYGON);
    glColor3ub(224,224,224);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.55f, -0.2f);
    glVertex2f(-0.65f, -0.4f);
    glVertex2f(-0.58f, -0.4f);
    glEnd();

    //BASEMENT RIGHT STAIRS 2
    glBegin(GL_POLYGON);
    glColor3ub(224,224,224);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.55f, -0.2f);
    glVertex2f(0.65f, -0.4f);
    glVertex2f(0.58f, -0.4f);
    glEnd();

    //BASEMENT MIDDLE STAIRS 3
    glBegin(GL_POLYGON);
    glColor3ub(224,224,224);
    glVertex2f(-0.03f, -0.2f);
    glVertex2f(0.03f, -0.2f);
    glVertex2f(0.05f, -0.4f);
    glVertex2f(-0.05f, -0.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(139,0,0);
    glVertex2f(-1.0f, -0.24f);
    glVertex2f(1.0f, -0.24f);

    glColor3ub(139,0,0);
    glVertex2f(-1.0f, -0.28f);
    glVertex2f(1.0f, -0.28f);

    glColor3ub(139,0,0);
    glVertex2f(-1.0f, -0.32f);
    glVertex2f(1.0f, -0.32f);

    glColor3ub(139,0,0);
    glVertex2f(-1.0f, -0.36f);
    glVertex2f(1.0f, -0.36f);
    glEnd();

    //Tree 4
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(-0.44f, -0.4f);
    glVertex2f(-0.46f, -0.4f);
    glVertex2f(-0.46f, -0.5f);
    glVertex2f(-0.44f, -0.5f);
    glEnd();

    glColor3ub(0,139,0);
    circle(-0.45f,-0.35f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.48f,-0.4f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.43f,-0.4f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(-0.44f, -0.4f);
        glVertex2f(-0.46f, -0.4f);
        glVertex2f(-0.46f, -0.5f);
        glVertex2f(-0.44f, -0.5f);
        glEnd();

        glColor3ub(23, 82, 43);
        circle(-0.45f,-0.35f,0.04f);
        glColor3ub(23, 82, 43);
        circle(-0.48f,-0.4f,0.04f);
        glColor3ub(23, 82, 43);
        circle(-0.43f,-0.4f,0.04f);
    }

    //Tree 5
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(0.44f, -0.4f);
    glVertex2f(0.46f, -0.4f);
    glVertex2f(0.46f, -0.5f);
    glVertex2f(0.44f, -0.5f);
    glEnd();

    glColor3ub(0,139,0);
    circle(0.45f,-0.35f,0.04f);
    glColor3ub(0,139,0);
    circle(0.48f,-0.4f,0.04f);
    glColor3ub(0,139,0);
    circle(0.43f,-0.4f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(0.44f, -0.4f);
        glVertex2f(0.46f, -0.4f);
        glVertex2f(0.46f, -0.5f);
        glVertex2f(0.44f, -0.5f);
        glEnd();

        glColor3ub(23, 82, 43);
        circle(0.45f,-0.35f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.48f,-0.4f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.43f,-0.4f,0.04f);
    }

    //Tree 6
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(-0.84f, -0.4f);
    glVertex2f(-0.86f, -0.4f);
    glVertex2f(-0.86f, -0.5f);
    glVertex2f(-0.84f, -0.5f);
    glEnd();

    glColor3ub(0,139,0);
    circle(-0.85f,-0.35f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.88f,-0.4f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.83f,-0.4f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(-0.84f, -0.4f);
        glVertex2f(-0.86f, -0.4f);
        glVertex2f(-0.86f, -0.5f);
        glVertex2f(-0.84f, -0.5f);
        glEnd();

        glColor3ub(23, 82, 43);
        circle(-0.85f,-0.35f,0.04f);
        glColor3ub(23, 82, 43);
        circle(-0.88f,-0.4f,0.04f);
        glColor3ub(23, 82, 43);
        circle(-0.83f,-0.4f,0.04f);
    }

    //Tree 7
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(0.84f, -0.4f);
    glVertex2f(0.86f, -0.4f);
    glVertex2f(0.86f, -0.5f);
    glVertex2f(0.84f, -0.5f);
    glEnd();

    glColor3ub(0,139,0);
    circle(0.85f,-0.35f,0.04f);
    glColor3ub(0,139,0);
    circle(0.88f,-0.4f,0.04f);
    glColor3ub(0,139,0);
    circle(0.83f,-0.4f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(0.84f, -0.4f);
        glVertex2f(0.86f, -0.4f);
        glVertex2f(0.86f, -0.5f);
        glVertex2f(0.84f, -0.5f);
        glEnd();

        glColor3ub(23, 82, 43);
        circle(0.85f,-0.35f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.88f,-0.4f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.83f,-0.4f,0.04f);
    }

    //Tree 8
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(0.01f, -0.4f);
    glVertex2f(-0.01f, -0.4f);
    glVertex2f(-0.01f, -0.5f);
    glVertex2f(0.01f, -0.5f);
    glEnd();

    glColor3ub(0,139,0);
    circle(0.0f,-0.35f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.03f,-0.4f,0.04f);
    glColor3ub(0,139,0);
    circle(0.02f,-0.4f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(0.01f, -0.4f);
        glVertex2f(-0.01f, -0.4f);
        glVertex2f(-0.01f, -0.5f);
        glVertex2f(0.01f, -0.5f);
        glEnd();

        glColor3ub(23, 82, 43);
        circle(0.0f,-0.35f,0.04f);
        glColor3ub(23, 82, 43);
        circle(-0.03f,-0.4f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.02f,-0.4f,0.04f);
    }

    //Tree 3
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(0.01f, -0.55f);
    glVertex2f(-0.01f, -0.55f);
    glVertex2f(-0.01f, -0.65f);
    glVertex2f(0.01f, -0.65f);
    glEnd();

    glColor3ub(0,139,0);
    circle(0.0f,-0.5f,0.04f);
    glColor3ub(0,139,0);
    circle(-0.03f,-0.55f,0.04f);
    glColor3ub(0,139,0);
    circle(0.02f,-0.55f,0.04f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(119, 51, 45);
        glVertex2f(0.01f, -0.55f);
        glVertex2f(-0.01f, -0.55f);
        glVertex2f(-0.01f, -0.65f);
        glVertex2f(0.01f, -0.65f);
        glEnd();

        glColor3ub(23, 82, 43);
        circle(0.0f,-0.5f,0.04f);
        glColor3ub(23, 82, 43);
        circle(-0.03f,-0.55f,0.04f);
        glColor3ub(23, 82, 43);
        circle(0.02f,-0.55f,0.04f);

    }



    ///********************************HOUSE 1
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.5f, 0.55f);
    glVertex2f(-0.3f, 0.6f);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.5f, 0.55f);
    glVertex2f(0.5f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(195,177,104);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.5f, 0.55f);
        glVertex2f(-0.3f, 0.6f);
        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.5f, 0.55f);
        glVertex2f(0.5f, -0.2f);
        glEnd();
    }

    ///HOUSE 1 **************LINES
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.49f, 0.35f);
    glVertex2f(0.49f, 0.35f);

    glColor3ub(255,255,255);
    glVertex2f(-0.49f, 0.4f);
    glVertex2f(0.49f, 0.4f);

    glColor3ub(255,255,255);
    glVertex2f(-0.49f, 0.45f);
    glVertex2f(0.49f, 0.45f);

    glColor3ub(255,255,255);
    glVertex2f(-0.49f, 0.5f);
    glVertex2f(0.49f, 0.5f);

    glColor3ub(255,255,255);
    glVertex2f(-0.49f, 0.55f);
    glVertex2f(0.49f, 0.55f);

    glColor3ub(255,255,255);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(-0.25f, 0.0f);
    glVertex2f(-0.25f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(-0.2f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(-0.15f, 0.0f);
    glVertex2f(-0.15f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.1f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(-0.05f, 0.0f);
    glVertex2f(-0.05f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.25f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.15f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.1f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(0.05f, 0.0f);
    glVertex2f(0.05f, 0.59f);

    glColor3ub(255,255,255);
    glVertex2f(-0.45f, 0.0f);
    glVertex2f(-0.45f, 0.55f);

    glColor3ub(255,255,255);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-0.4f, 0.56f);

    glColor3ub(255,255,255);
    glVertex2f(-0.35f, 0.0f);
    glVertex2f(-0.35f, 0.57f);

    glColor3ub(255,255,255);
    glVertex2f(0.45f, 0.0f);
    glVertex2f(0.45f, 0.55f);

    glColor3ub(255,255,255);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, 0.56f);

    glColor3ub(255,255,255);
    glVertex2f(0.35f, 0.0f);
    glVertex2f(0.35f, 0.57f);

    glEnd();

    //HOUSE 1 CIRCLE 1
    glColor3ub(70,70,70);
    circle(-0.3f,0.5f,0.08);

    glColor3ub(70,70,70);
    circle(0.0f,0.5f,0.08);

    glColor3ub(70,70,70);
    circle(0.3f,0.5f,0.08);
///*************************
    if(night)
    {
        glColor3ub(195, 72, 60);
        circle(-0.3f,0.5f,0.08);

        glColor3ub(227, 113, 60);
        circle(0.0f,0.5f,0.08);

        glColor3ub(195, 72, 60);
        circle(0.3f,0.5f,0.08);
    }



    ///******************************HOUSE 2
    glBegin(GL_POLYGON);
    glColor3ub(51,51,51);
    glVertex2f(-0.35f, -0.2f);
    glVertex2f(-0.35f, 0.45f);
    glVertex2f(0.35f, 0.45f);
    glVertex2f(0.35f, -0.2f);
    glEnd();
    //black

    ///***************************HOUSE 3
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.2f, 0.35f);
    glVertex2f(-0.2f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(207, 207, 176);//-
        glVertex2f(-0.4f, -0.2f);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.2f, 0.35f);
        glVertex2f(-0.2f, -0.2f);
        glEnd();
    }

    //HOUSE 3 lines
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.39f, -0.15f);
    glVertex2f(-0.21f, -0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, -0.1f);
    glVertex2f(-0.21f, -0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, -0.05f);
    glVertex2f(-0.21f, -0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.0f);
    glVertex2f(-0.21f, 0.0f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.05f);
    glVertex2f(-0.21f, 0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.1f);
    glVertex2f(-0.21f, 0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.15f);
    glVertex2f(-0.21f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.2f);
    glVertex2f(-0.21f, 0.2f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.25f);
    glVertex2f(-0.21f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.3f);
    glVertex2f(-0.21f, 0.3f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.34f);
    glVertex2f(-0.21f, 0.32f);

    glColor3ub(255,255,255);
    glVertex2f(-0.39f, 0.39f);
    glVertex2f(-0.21f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(-0.35f, -0.2f);
    glVertex2f(-0.35f, 0.38f);

    glColor3ub(255,255,255);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.3f, 0.37f);

    glColor3ub(255,255,255);
    glVertex2f(-0.25f, -0.2f);
    glVertex2f(-0.25f, 0.36f);

    glEnd();

    ///House 3 circle
    glColor3ub(70,70,70);
    circle(-0.3f,0.1f,0.09f);

    if(night)
    {
        glColor3ub(195, 72, 60);
        circle(-0.3f,0.1f,0.09f);
    }



    //HOUSE 4
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(-0.15f, -0.2f);
    glVertex2f(-0.15f, 0.35f);
    glVertex2f(0.15f, 0.35f);
    glVertex2f(0.15f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(207, 207, 176);
        glVertex2f(-0.15f, -0.2f);
        glVertex2f(-0.15f, 0.35f);
        glVertex2f(0.15f, 0.35f);
        glVertex2f(0.15f, -0.2f);
        glEnd();
    }

    //HOUSE 4 LINES
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.14f, -0.15f);
    glVertex2f(0.14f, -0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, -0.1f);
    glVertex2f(0.14f, -0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, -0.05f);
    glVertex2f(0.14f, -0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.0f);
    glVertex2f(0.14f, 0.0f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.05f);
    glVertex2f(0.14f, 0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.1f);
    glVertex2f(0.14f, 0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.15f);
    glVertex2f(0.14f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.2f);
    glVertex2f(0.14f, 0.2f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.25f);
    glVertex2f(0.14f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.3f);
    glVertex2f(0.14f, 0.3f);

    glColor3ub(255,255,255);
    glVertex2f(-0.14f, 0.34f);
    glVertex2f(0.14f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(-0.1f, -0.19f);
    glVertex2f(-0.1f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(-0.1f, -0.19f);
    glVertex2f(-0.1f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(-0.05f, -0.19f);
    glVertex2f(-0.05f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(0.0f, -0.19f);
    glVertex2f(0.0f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(0.05f, -0.19f);
    glVertex2f(0.05f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(0.1f, -0.19f);
    glVertex2f(0.1f, 0.34f);

    glEnd();

    ///********************HOUSE 5
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.4f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(207, 207, 176);
        glVertex2f(0.2f, -0.2f);
        glVertex2f(0.2f, 0.35f);
        glVertex2f(0.4f, 0.4f);
        glVertex2f(0.4f, -0.2f);
        glEnd();
    }

    //HOUSE 5 lines
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.39f, -0.15f);
    glVertex2f(0.21f, -0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, -0.1f);
    glVertex2f(0.21f, -0.1f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, -0.05f);
    glVertex2f(0.21f, -0.05f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.0f);
    glVertex2f(0.21f, 0.0f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.05f);
    glVertex2f(0.21f, 0.05f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.1f);
    glVertex2f(0.21f, 0.1f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.15f);
    glVertex2f(0.21f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.2f);
    glVertex2f(0.21f, 0.2f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.25f);
    glVertex2f(0.21f, 0.25f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.3f);
    glVertex2f(0.21f, 0.3f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.34f);
    glVertex2f(0.21f, 0.32f);

    glColor3ub(255,255,255);
    glVertex2f(0.39f, 0.39f);
    glVertex2f(0.21f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(0.35f, -0.2f);
    glVertex2f(0.35f, 0.38f);

    glColor3ub(255,255,255);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.3f, 0.37f);

    glColor3ub(255,255,255);
    glVertex2f(0.25f, -0.2f);
    glVertex2f(0.25f, 0.36f);

    glEnd();

    ///HOUSE 5 CIRCLE
    glColor3ub(70,70,70);
    circle(0.3f,0.1f,0.09f);

    if(night)
    {
        glColor3ub(212, 72, 60);
        circle(0.3f,0.1f,0.09f);
    }


    ///************************************HOUSE 8
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.9f, 0.3f);
    glVertex2f(-0.6f, 0.35f);
    glVertex2f(-0.6f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(195,177,104);
        glVertex2f(-0.9f, -0.2f);
        glVertex2f(-0.9f, 0.3f);
        glVertex2f(-0.6f, 0.35f);
        glVertex2f(-0.6f, -0.2f);
        glEnd();
    }

    ///******************************HOUSE 9
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.9f, 0.3f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.6f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(195,177,104);
        glVertex2f(0.9f, -0.2f);
        glVertex2f(0.9f, 0.3f);
        glVertex2f(0.6f, 0.35f);
        glVertex2f(0.6f, -0.2f);
        glEnd();

    }


    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.5f, 0.55f);

    glColor3ub(0,0,0);
    glVertex2f(-0.5f, 0.55f);
    glVertex2f(-0.3f, 0.6f);

    glColor3ub(0,0,0);
    glVertex2f(-0.3f, 0.6f);
    glVertex2f(0.3f, 0.6f);

    glColor3ub(0,0,0);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.5f, 0.55f);

    glColor3ub(0,0,0);
    glVertex2f(0.5f, 0.55f);
    glVertex2f(0.5f, -0.2f);

    glColor3ub(0,0,0);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.4f, 0.4f);

    glColor3ub(0,0,0);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.4f, 0.4f);

    glColor3ub(0,0,0);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.6f, 0.35f);

    glColor3ub(0,0,0);
    glVertex2f(0.6f, -0.2f);
    glVertex2f(0.6f, 0.35f);

    glColor3ub(0,0,0);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.9f, 0.3f);

    glColor3ub(0,0,0);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.9f, 0.3f);

    glColor3ub(0,0,0);
    glVertex2f(0.9f, 0.3f);
    glVertex2f(0.6f, 0.35f);

    glColor3ub(0,0,0);
    glVertex2f(-0.9f, 0.3f);
    glVertex2f(-0.6f, 0.35f);

    glColor3ub(0,0,0);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.6f, 0.35f);

    glColor3ub(0,0,0);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(-0.6f, 0.35f);

    glColor3ub(0,0,0);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.2f, 0.35f);

    glColor3ub(0,0,0);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.2f, 0.35f);

    glColor3ub(255,255,255);
    glVertex2f(-0.85f, -0.2f);
    glVertex2f(-0.85f, 0.30f);

    glColor3ub(255,255,255);
    glVertex2f(-0.8f, -0.2f);
    glVertex2f(-0.8f, 0.31f);

    glColor3ub(255,255,255);
    glVertex2f(-0.75f, -0.2f);
    glVertex2f(-0.75f, 0.32f);

    glColor3ub(255,255,255);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(-0.7f, 0.33f);

    glColor3ub(255,255,255);
    glVertex2f(-0.65f, -0.2f);
    glVertex2f(-0.65f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(0.85f, -0.2f);
    glVertex2f(0.85f, 0.30f);

    glColor3ub(255,255,255);
    glVertex2f(0.8f, -0.2f);
    glVertex2f(0.8f, 0.31f);

    glColor3ub(255,255,255);
    glVertex2f(0.75f, -0.2f);
    glVertex2f(0.75f, 0.32f);

    glColor3ub(255,255,255);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.7f, 0.33f);

    glColor3ub(255,255,255);
    glVertex2f(0.65f, -0.2f);
    glVertex2f(0.65f, 0.34f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, -0.15f);
    glVertex2f(-0.61f, -0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, -0.1f);
    glVertex2f(-0.61f, -0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, -0.05f);
    glVertex2f(-0.61f, -0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, 0.0f);
    glVertex2f(-0.61f, 0.0f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.61f, 0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, 0.1f);
    glVertex2f(-0.61f, 0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, 0.15f);
    glVertex2f(-0.61f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, 0.19f);
    glVertex2f(-0.61f, 0.21f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, 0.24f);
    glVertex2f(-0.61f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(-0.89f, 0.28f);
    glVertex2f(-0.61f, 0.33f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, -0.15f);
    glVertex2f(0.61f, -0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, -0.1f);
    glVertex2f(0.61f, -0.1f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, -0.05f);
    glVertex2f(0.61f, -0.05f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, 0.0f);
    glVertex2f(0.61f, 0.0f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, 0.05f);
    glVertex2f(0.61f, 0.05f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, 0.1f);
    glVertex2f(0.61f, 0.1f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, 0.15f);
    glVertex2f(0.61f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, 0.19f);
    glVertex2f(0.61f, 0.21f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, 0.24f);
    glVertex2f(0.61f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.89f, 0.28f);
    glVertex2f(0.61f, 0.33f);

    glEnd();

    //HOUSE 6
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(-0.6f, 0.35f);
    glVertex2f(-0.6f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(227, 215, 181);///###########
        glVertex2f(-0.4f, -0.2f);
        glVertex2f(-0.4f, 0.3f);
        glVertex2f(-0.6f, 0.35f);
        glVertex2f(-0.6f, -0.2f);
        glEnd();
    }

    //HOUSE 6 LINES
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.59f, -0.15f);
    glVertex2f(-0.41f, -0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, -0.1f);
    glVertex2f(-0.41f, -0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, -0.05f);
    glVertex2f(-0.41f, -0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, 0.0f);
    glVertex2f(-0.41f, 0.0f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, 0.05f);
    glVertex2f(-0.41f, 0.05f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, 0.1f);
    glVertex2f(-0.41f, 0.1f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, 0.15f);
    glVertex2f(-0.41f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, 0.21f);
    glVertex2f(-0.41f, 0.18f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, 0.27f);
    glVertex2f(-0.41f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(-0.59f, 0.33f);
    glVertex2f(-0.41f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(-0.55f, -0.2f);
    glVertex2f(-0.55f, 0.33f);

    glColor3ub(255,255,255);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.5f, 0.32f);

    glColor3ub(255,255,255);
    glVertex2f(-0.45f, -0.2f);
    glVertex2f(-0.45f, 0.31f);

    glEnd();

    ///HOUSE 7
    glBegin(GL_POLYGON);
    glColor3ub(217,217,217);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.6f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(227, 215, 181);
        glVertex2f(0.4f, -0.2f);
        glVertex2f(0.4f, 0.3f);
        glVertex2f(0.6f, 0.35f);
        glVertex2f(0.6f, -0.2f);
        glEnd();
    }

    //HOUSE 7 LINES
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(0.59f, -0.15f);
    glVertex2f(0.41f, -0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, -0.1f);
    glVertex2f(0.41f, -0.1f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, -0.05f);
    glVertex2f(0.41f, -0.05f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, 0.0f);
    glVertex2f(0.41f, 0.0f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, 0.05f);
    glVertex2f(0.41f, 0.05f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, 0.1f);
    glVertex2f(0.41f, 0.1f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, 0.15f);
    glVertex2f(0.41f, 0.15f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, 0.21f);
    glVertex2f(0.41f, 0.18f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, 0.27f);
    glVertex2f(0.41f, 0.22f);

    glColor3ub(255,255,255);
    glVertex2f(0.59f, 0.33f);
    glVertex2f(0.41f, 0.27f);

    glColor3ub(255,255,255);
    glVertex2f(0.55f, -0.2f);
    glVertex2f(0.55f, 0.33f);

    glColor3ub(255,255,255);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.5f, 0.32f);

    glColor3ub(255,255,255);
    glVertex2f(0.45f, -0.2f);
    glVertex2f(0.45f, 0.31f);

    glEnd();

    ///SQUARE 1
    glBegin(GL_POLYGON);
    glColor3ub(70,70,70);
    glVertex2f(-0.58f, -0.2f);
    glVertex2f(-0.58f, -0.05f);
    glVertex2f(-0.42f, -0.05f);
    glVertex2f(-0.42f, -0.2f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(46, 55, 46);//b
        glVertex2f(-0.58f, -0.2f);
        glColor3ub(237, 185, 4);//y
        glVertex2f(-0.58f, -0.05f);
        glColor3ub(245, 211, 86);//dy
        glVertex2f(-0.42f, -0.05f);
        glColor3ub(194, 55, 28);

        //glColor3ub(223, 185, 0);
        glVertex2f(-0.42f, -0.2f);
        glEnd();
    }

    ///SQUARE 2
    glBegin(GL_POLYGON);
    glColor3ub(70,70,70);
    glVertex2f(0.58f, -0.2f);
    glVertex2f(0.58f, -0.05f);
    glVertex2f(0.42f, -0.05f);
    glVertex2f(0.42f, -0.2f);
    glEnd();

    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(46, 55, 46);
        glVertex2f(0.58f, -0.2f);
        glColor3ub(228, 182, 41);
        glVertex2f(0.58f, -0.05f);
        glColor3ub(245, 211, 86);
        glVertex2f(0.42f, -0.05f);
        glColor3ub(166, 44, 33);
        glVertex2f(0.42f, -0.2f);
        glEnd();
    }

    ///SQUARE 3(middle)
    glBegin(GL_POLYGON);
    glColor3ub(70,70,70);
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(-0.1f, -0.05f);
    glVertex2f(0.1f, -0.05f);
    glVertex2f(0.1f, -0.2f);
    glEnd();

    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(255,193,37);
        glVertex2f(-0.1f, -0.2f);
        glVertex2f(-0.1f, -0.05f);
        glColor3ub(227, 113, 60);
        glVertex2f(0.1f, -0.05f);
        glColor3ub(211, 157, 60);
        glVertex2f(0.1f, -0.2f);
        glEnd();
    }

    //TRIANGLE 1
    glBegin(GL_TRIANGLES);
    glColor3ub(70,70,70);
    glVertex2f(-0.58f, 0.0f);
    glVertex2f(-0.42f, 0.0f);
    glVertex2f(-0.5f, 0.28f);
    glEnd();

    if(night)///left
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(205, 74, 56);
        glVertex2f(-0.58f, 0.0f);
        glColor3ub(139, 33, 42);//B
        glVertex2f(-0.42f, 0.0f);
        glColor3ub(232, 143, 55);
        glVertex2f(-0.5f, 0.28f);
        glEnd();
    }

    //TRIANGLE 2
    glBegin(GL_TRIANGLES);
    glColor3ub(70,70,70);
    glVertex2f(0.58f, 0.0f);
    glVertex2f(0.42f, 0.0f);
    glVertex2f(0.5f, 0.28f);
    glEnd();

    if(night)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(235, 175, 42);
        glVertex2f(0.58f, 0.0f);
        glColor3ub(139, 33, 42);//B
        glVertex2f(0.42f, 0.0f);
        glColor3ub(232, 143, 55);
        glVertex2f(0.5f, 0.28f);
        glEnd();
    }

    //FLAG
    glBegin(GL_POLYGON);
    glColor3ub(0,139,0);
    glVertex2f(0.0f, 0.19f);
    glVertex2f(0.23f, 0.19f);
    glVertex2f(0.23f, 0.00f);
    glVertex2f(0.0f, 0.00f);
    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3ub(62, 119, 59);
        glVertex2f(0.0f, 0.19f);
        glVertex2f(0.23f, 0.19f);
        glVertex2f(0.23f, 0.00f);
        glVertex2f(0.0f, 0.00f);
        glEnd();
    }

    ///FLAG CIRCLE
    glColor3ub(255,0,0);
    circle(0.12f,0.09f,0.05f);
    if(night)
    {
        glColor3ub(141, 28, 23);
        circle(0.12f,0.09f,0.05f);
    }


    //FLAG STICK
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.01f, 0.2f);
    glVertex2f(0.01f, -0.2f);
    glEnd();

    ///*************Basement light
    //r1
    glPushMatrix();
    glTranslatef(0.2f,-0.832f,0.0f);
    glScalef(1.2,1.2,1.2);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.905f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.895f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

//r2
    glPushMatrix();
    glTranslatef(0.6f,-0.832f,0.0f);
    glScalef(1.2,1.2,1.2);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.905f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.895f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    //r3
    glPushMatrix();
    glTranslatef(1.1f,-0.832f,0.0f);
    glScalef(1.2,1.2,1.2);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.905f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.895f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();
//r4
    glPushMatrix();
    glTranslatef(1.6f,-0.832f,0.0f);
    glScalef(1.2,1.2,1.2);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.905f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.895f, 0.12f);
        glColor3ub(57, 93, 67);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();


///**********parliament light
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.96f, -0.2f);
    glVertex2f(-0.96f, -0.1f);
    glVertex2f(-0.95f, -0.1f);
    glVertex2f(-0.95f, -0.2f);
    glEnd();
    //
    glColor3ub(234, 245, 249);
    circle(-0.955f,-0.1f,0.01f);
    if(night)
    {
        glColor3ub(255,255,0);
        circle(-0.955f,-0.1f,0.01f);
    }
    /*
        glBegin(GL_POLYGON);
        glColor3ub(255,255,255);
        glVertex2f(-0.99f, -0.1f);
        glVertex2f(-0.99f, -0.11f);
        glVertex2f(-0.92f, -0.11f);
        glVertex2f(-0.92f, -0.1f);
        glEnd();*/
    //glColor3ub(217, 201, 104);
    //circle(0.95f,0.105f,0.001f);

    //*****2
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.45f, -0.2f);
    glVertex2f(-0.45f, -0.1f);
    glVertex2f(-0.44f, -0.1f);
    glVertex2f(-0.44f, -0.2f);
    glEnd();

    glColor3ub(234, 245, 249);
    circle(-0.445f,-0.1f,0.01f);
    if(night)
    {
        glColor3ub(255,255,0);
        circle(-0.445f,-0.1f,0.01f);
    }

    //*****3
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.05f, -0.1f);
    glVertex2f(0.06f, -0.1f);
    glVertex2f(0.06f, -0.2f);
    glEnd();

    glColor3ub(234, 245, 249);
    circle(0.055f,-0.1f,0.01f);
    if(night)
    {
        glColor3ub(255,255,0);
        circle(0.055f,-0.1f,0.01f);
    }

    //*****4
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(0.55f, -0.2f);
    glVertex2f(0.55f, -0.1f);
    glVertex2f(0.56f, -0.1f);
    glVertex2f(0.56f, -0.2f);
    glEnd();

    glColor3ub(234, 245, 249);
    circle(0.555f,-0.1f,0.01f);
    if(night)
    {
        glColor3ub(255,255,0);
        circle(0.555f,-0.1f,0.01f);
    }
    //*****5
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(0.96f, -0.2f);
    glVertex2f(0.96f, -0.1f);
    glVertex2f(0.95f, -0.1f);
    glVertex2f(0.95f, -0.2f);
    glEnd();

    glColor3ub(234, 245, 249);
    circle(0.955f,-0.1f,0.01f);
    if(night)
    {
        glColor3ub(255,255,0);
        circle(0.955f,-0.1f,0.01f);
    }

    ///**************************************************BMW****************
    glPushMatrix();
    glTranslatef(position8,0.0f, 0.0f);
    glScalef(0.75,0.75,0.75);

    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.5f,0.0f);

    glVertex2f(-0.85f, -0.95f);
    glVertex2f(-0.77f, -0.83f);
    glVertex2f(-0.5f, -0.83f);
    glVertex2f(-0.5f, -0.95f);
    glEnd();

    glBegin(GL_QUADS);///---------------
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(-0.88f, -0.95f);
    glVertex2f(-0.5f, -0.95f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(-0.88f, -1.0f);

    glEnd();
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.9f,0.9f,0.0f);//******
        glVertex2f(-0.88f, -0.95f);
        glVertex2f(-0.88f, -0.98f);
        glVertex2f(-0.95f, -1.02f);
        glVertex2f(-1.05f, -1.02f);
        glEnd();
    }

//Light............................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.038f,0.27f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(-0.5f, -0.98f);
    glVertex2f(-0.518f, -0.98f);
    glVertex2f(-0.518f, -1.0f);
    glEnd();
    if(night)/////////////////////--------------------------------------------------------may problem occur here
    {
        glBegin(GL_QUADS);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.88f, -0.95f);
        glVertex2f(-0.88f, -0.97f);
        glVertex2f(-0.86f, -0.97f);
        glVertex2f(-0.87f, -0.95f);
    }
//back light..................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.38f,0.27f);
    glVertex2f(-0.88f, -0.95f);
    glVertex2f(-0.88f, -0.97f);
    glVertex2f(-0.86f, -0.97f);
    glVertex2f(-0.87f, -0.95f);
    glEnd();
    //window1..................
    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);
    glVertex2f(-0.818f, -0.93f);
    glVertex2f(-0.76f, -0.845f);
    glVertex2f(-0.72f, -0.845f);
    glVertex2f(-0.72f, -0.93f);
    glEnd();
    //window2..............................
    glBegin(GL_QUADS);
    glVertex2f(-0.71f, -0.93f);
    glVertex2f(-0.71f, -0.845f);
    glVertex2f(-0.64f, -0.845f);
    glVertex2f(-0.64f, -0.93f);
    glEnd();
    //window3.................................
    glBegin(GL_QUADS);
    glVertex2f(-0.63f, -0.93f);
    glVertex2f(-0.63f, -0.845f);
    glVertex2f(-0.52f, -0.845f);
    glVertex2f(-0.52f, -0.93f);
    glEnd();
    /////Door1..........................................
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.73f,-0.95f);
    glVertex2f(-0.75f,-0.95f);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.64f,-0.95f);
    glVertex2f(-0.66f,-0.95f);
    glEnd();
    //BUS WHEEL 1
    glColor3ub(99,99,99);
    circle(-0.6f,-1.0f,0.05f);
    glColor3ub(0,0,0);
    circle(-0.6f,-1.0f,0.012f);

    //BUS WHEEL 2
    glColor3ub(99,99,99);
    circle(-0.78f,-1.0f,0.05f);
    glColor3ub(0,0,0);
    circle(-0.78f,-1.0f,0.012f);
    glPopMatrix();

    ///*************************************************************************bus move***********
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);

    //BUS
    //BUS BODY 1
    glBegin(GL_POLYGON);
    glColor3ub(0,255,222);
    glVertex2f(0.24f, -0.6f);
    glVertex2f(0.2f, -0.64f);
    glVertex2f(0.2f, -0.7f);
    glVertex2f(0.6f, -0.7f);
    glVertex2f(0.6f, -0.64f);
    glEnd();

    //BUS BODY 2
    glBegin(GL_POLYGON);
    glColor3ub(224,0,22);
    glVertex2f(0.26f, -0.54f);
    glVertex2f(0.6f, -0.54f);
    glVertex2f(0.6f, -0.64f);
    glVertex2f(0.26f, -0.64f);
    glEnd();
    //window 1
    glBegin(GL_POLYGON);
    glColor3ub(0.4,0.4,0.4);
    glVertex2f(0.28f, -0.60f);
    glVertex2f(0.28f, -0.56f);
    glVertex2f(0.34f, -0.56f);
    glVertex2f(0.34f, -0.60f);
    glEnd();
    //window 2
    glBegin(GL_POLYGON);
    glColor3ub(0.4,0.4,0.4);
    glVertex2f(0.36f, -0.60f);
    glVertex2f(0.36f, -0.56f);
    glVertex2f(0.42f, -0.56f);
    glVertex2f(0.42f, -0.60f);
    glEnd();

    //window 3
    glBegin(GL_POLYGON);
    glColor3ub(0.4,0.4,0.4);
    glVertex2f(0.44f, -0.56f);
    glVertex2f(0.5f, -0.56f);
    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.44f, -0.60f);
    glEnd();
    //window 4
    glBegin(GL_POLYGON);
    glColor3ub(0.4,0.4,0.4);
    glVertex2f(0.52f, -0.56f);
    glVertex2f(0.58f, -0.56f);
    glVertex2f(0.58f, -0.6f);
    glVertex2f(0.52f, -0.60f);
    glEnd();


    //BUS WHEEL 1
    glColor3ub(99,99,99);
    circle(0.28f,-0.7f,0.04f);
    glColor3ub(0,0,0);
    circle(0.28f,-0.7f,0.01f);

    //BUS WHEEL 2
    glColor3ub(99,99,99);
    circle(0.5f,-0.7f,0.04f);
    glColor3ub(0,0,0);
    circle(0.5f,-0.7f,0.01f);
    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.9f,0.9f,0.0f);//******
        glVertex2f(0.05f, -0.73f);
        glVertex2f(0.14f, -0.72f);
        glVertex2f(0.2f, -0.65f);
        glVertex2f(0.2f, -0.69f);
        glEnd();
    }
    glPopMatrix();
    ///***********************************************************BRTC*********
    glPushMatrix();
    glTranslatef(position7,0.0f, 0.0f);


    glBegin(GL_QUADS);///-----bus body
    //glColor3f(1.0, 0.5, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0,-0.7);
    glVertex2f(0.37,-0.7);
    glColor3f(0.98, 0.88, 0.02);
    glVertex2f(0.37,-.88);
    glVertex2f(0.0,-0.88);
    glEnd();

    glBegin(GL_QUADS);//window 1
    //glColor3f(0.00, 0.00, 0.00);
    glColor3ub(0, 153, 178);
    glVertex2f(0.02,-0.78);
    glVertex2f(0.02,-0.74);
    glVertex2f(0.06,-0.74);
    glVertex2f(0.06,-0.78);
    glEnd();
    glBegin(GL_QUADS);;//window 2
    //glColor3f(0.00, 0.00, 0.00);
    glColor3ub(0, 153, 178);
    glVertex2f(0.1,-0.78);
    glVertex2f(0.1,-0.74);
    glVertex2f(0.14,-0.74);
    glVertex2f(0.14,-0.78);
    glEnd();
    glBegin(GL_QUADS);;//window 3
    //glColor3f(0.00, 0.00, 0.00);
    glColor3ub(0, 153, 178);
    glVertex2f(0.18,-0.78);
    glVertex2f(0.18,-0.74);
    glVertex2f(0.22,-0.74);
    glVertex2f(0.22,-0.78);
    glEnd();
    glBegin(GL_QUADS);;//window 4
    //glColor3f(0.00, 0.00, 0.00);
    glColor3ub(0, 153, 178);
    glVertex2f(0.26,-0.78);
    glVertex2f(0.26,-0.74);
    glVertex2f(0.3,-0.74);
    glVertex2f(0.3,-0.78);
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(0.365f,-0.72);
    glVertex2f(0.365f,-0.8);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.02f,-0.81f);
    glVertex2f(0.32f,-0.81f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.02f,-0.83f);
    glVertex2f(0.32f,-0.83f);
    glEnd();
    //u
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(0.35,-0.86);
    glVertex2f(0.35,-0.845);
    glVertex2f(0.37,-0.845);
    glVertex2f(0.37,-0.86);
    glEnd();


    //BUS WHEEL 1
    glColor3ub(99,99,99);
    circle(0.285f,-0.87f,0.04f);
    glColor3ub(0,0,0);
    circle(0.285f,-0.87f,0.01f);

    //BUS WHEEL 2
    glColor3ub(99,99,99);
    circle(0.0796f,-0.87f,0.04f);
    glColor3ub(0,0,0);
    circle(0.0796f,-0.87f,0.01f);

    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.9f,0.9f,0.0f);//******
        glVertex2f(0.52f, -0.92f);
        glVertex2f(0.46f, -0.92f);
        glVertex2f(0.37f, -0.87f);
        glVertex2f(0.37f, -0.84f);
        glEnd();
    }
    glPopMatrix();
    ///****************************************move car****************
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

    //CAR
    //CAR BODY 1
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex2f(-0.7f, -0.9f);
    glVertex2f(-0.7f, -0.84f);
    glVertex2f(-0.45f, -0.84f);
    glVertex2f(-0.41f, -0.88f);
    glVertex2f(-0.41f, -0.9f);
    glEnd();

    //CAR BODY 2
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.66f, -0.84f);
    glVertex2f(-0.62f, -0.8f);
    glVertex2f(-0.51f, -0.8f);
    glVertex2f(-0.47f, -0.84f);
    glEnd();

    //CAR WINDOW 1
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.61f, -0.8f);
    glVertex2f(-0.61f, -0.84f);
    glVertex2f(-0.57f, -0.84f);
    glVertex2f(-0.57f, -0.8f);
    glEnd();


    //CAR WINDOW 2
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.56f, -0.8f);
    glVertex2f(-0.56f, -0.84f);
    glVertex2f(-0.52f, -0.84f);
    glVertex2f(-0.52f, -0.8f);
    glEnd();

    //CAR GUARD
    glBegin(GL_POLYGON);
    glColor3ub(224,224,224);
    glVertex2f(-0.42f, -0.9f);
    glVertex2f(-0.42f, -0.89f);
    glVertex2f(-0.4f, -0.89f);
    glVertex2f(-0.4f, -0.9f);
    glEnd();

    if(night)
    {
        glBegin(GL_POLYGON);
        glColor3f(0.9f,0.9f,0.0f);//******
        glVertex2f(-0.42f, -0.9f);
        glVertex2f(-0.42f, -0.88f);
        glVertex2f(-0.28f, -0.93f);
        glVertex2f(-0.35f, -0.93f);
        glEnd();
    }

    //CAR WHEEL 1
    glColor3ub(99,99,99);
    circle(-0.63f,-0.9f,0.03f);
    glColor3ub(0,0,0);
    circle(-0.63f,-0.9f,0.01f);

    //CAR WHEEL 2
    glColor3ub(99,99,99);
    circle(-0.48f,-0.9f,0.03f);
    glColor3ub(0,0,0);
    circle(-0.48f,-0.9f,0.01f);
    //
    glPopMatrix();
    ///********************road light

    ///Y axix

//ry1
    glPushMatrix();
    glTranslatef(0.6f,-1.155f,0.0f);
    glScalef(1.4,1.4,1.4);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    //ry2
    glPushMatrix();
    glTranslatef(1.1f,-1.155f,0.0f);
    glScalef(1.4,1.4,1.4);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    //ry3
    glPushMatrix();
    glTranslatef(1.6f,-1.155f,0.0f);
    glScalef(1.4,1.4,1.4);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();
    //ry4
    glPushMatrix();
    glTranslatef(2.2f,-1.155f,0.0f);
    glScalef(1.4,1.4,1.4);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

///******************Rain

    if(rain)
    {
        glPushMatrix();
        glTranslatef(0.0f, position11, 0.0f);
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.95f);
        glVertex2f(-0.96f, 0.85f);

        glVertex2f(-0.9f, 0.95f);
        glVertex2f(-0.91f, 0.85f);

        glVertex2f(-0.85f, 0.95f);
        glVertex2f(-0.86f, 0.85f);

        glVertex2f(-0.8f, 0.95f);
        glVertex2f(-0.81f, 0.85f);

        glVertex2f(-0.75f, 0.95f);
        glVertex2f(-0.76f, 0.85f);

        glVertex2f(-0.7f, 0.95f);
        glVertex2f(-0.71f, 0.85f);

        glVertex2f(-0.65f, 0.95f);
        glVertex2f(-0.66f, 0.85f);

        glVertex2f(-0.6f, 0.95f);
        glVertex2f(-0.61f, 0.85f);

        glVertex2f(-0.55f, 0.95f);
        glVertex2f(-0.56f, 0.85f);

        glVertex2f(-0.5f, 0.95f);
        glVertex2f(-0.51f, 0.85f);

        glVertex2f(-0.45f, 0.95f);
        glVertex2f(-0.46f, 0.85f);

        glVertex2f(-0.4f, 0.95f);
        glVertex2f(-0.41f, 0.85f);

        glVertex2f(-0.35f, 0.95f);
        glVertex2f(-0.36f, 0.85f);

        glVertex2f(-0.3f, 0.95f);
        glVertex2f(-0.31f, 0.85f);

        glVertex2f(-0.25f, 0.95f);
        glVertex2f(-0.26f, 0.85f);

        glVertex2f(-0.2f, 0.95f);
        glVertex2f(-0.21f, 0.85f);

        glVertex2f(-0.15f, 0.95f);
        glVertex2f(-0.16f, 0.85f);

        glVertex2f(-0.1f, 0.95f);
        glVertex2f(-0.11f, 0.85f);

        glVertex2f(-0.05f, 0.95f);
        glVertex2f(-0.06f, 0.85f);

        glVertex2f(0.0f, 1.0f);
        glVertex2f(-0.01f, 0.85f);

        glVertex2f(0.05f, 0.95f);
        glVertex2f(0.04f, 0.85f);

        glVertex2f(0.10f, 0.95f);
        glVertex2f(0.09f, 0.85f);

        glVertex2f(0.15f, 0.95f);
        glVertex2f(0.14f, 0.85f);

        glVertex2f(0.20f, 0.95f);
        glVertex2f(0.19f, 0.85f);

        glVertex2f(0.25f, 0.95f);
        glVertex2f(0.24f, 0.85f);

        glVertex2f(0.30f, 0.95f);
        glVertex2f(0.29f, 0.85f);

        glVertex2f(0.35f, 0.95f);
        glVertex2f(0.34f, 0.85f);

        glVertex2f(0.40f, 0.95f);
        glVertex2f(0.39f, 0.85f);

        glVertex2f(0.45f, 0.95f);
        glVertex2f(0.44f, 0.85f);

        glVertex2f(0.50f, 0.95f);
        glVertex2f(0.49f, 0.85f);

        glVertex2f(0.55f, 0.95f);
        glVertex2f(0.54f, 0.85f);

        glVertex2f(0.60f, 0.95f);
        glVertex2f(0.59f, 0.85f);

        glVertex2f(0.65f, 0.95f);
        glVertex2f(0.64f, 0.85f);

        glVertex2f(0.70f, 0.95f);
        glVertex2f(0.69f, 0.85f);

        glVertex2f(0.75f, 0.95f);
        glVertex2f(0.74f, 0.85f);

        glVertex2f(0.80f, 0.95f);
        glVertex2f(0.79f, 0.85f);

        glVertex2f(0.85f, 0.95f);
        glVertex2f(0.84f, 0.85f);

        glVertex2f(0.90f, 0.95f);
        glVertex2f(0.89f, 0.85f);

        glVertex2f(0.95f, 0.95f);
        glVertex2f(0.94f, 0.85f);

        glVertex2f(1.0f, 0.95f);
        glVertex2f(0.99f, 0.85f);

        glVertex2f(1.05f, 0.95f);
        glVertex2f(1.04f, 0.85f);

        glEnd();


        ///2nd line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.75f);
        glVertex2f(-0.96f, 0.65f);

        glVertex2f(-0.9f, 0.75f);
        glVertex2f(-0.91f, 0.65f);

        glVertex2f(-0.85f, 0.75f);
        glVertex2f(-0.86f, 0.65f);

        glVertex2f(-0.8f, 0.75f);
        glVertex2f(-0.81f, 0.65f);

        glVertex2f(-0.75f, 0.75f);
        glVertex2f(-0.76f, 0.65f);

        glVertex2f(-0.7f, 0.75f);
        glVertex2f(-0.71f, 0.65f);

        glVertex2f(-0.65f, 0.75f);
        glVertex2f(-0.66f, 0.65f);

        glVertex2f(-0.6f, 0.75f);
        glVertex2f(-0.61f, 0.65f);

        glVertex2f(-0.55f, 0.75f);
        glVertex2f(-0.56f, 0.65f);

        glVertex2f(-0.5f, 0.75f);
        glVertex2f(-0.51f, 0.65f);

        glVertex2f(-0.45f, 0.75f);
        glVertex2f(-0.46f, 0.65f);

        glVertex2f(-0.4f, 0.75f);
        glVertex2f(-0.41f, 0.65f);

        glVertex2f(-0.35f, 0.75f);
        glVertex2f(-0.36f, 0.65f);

        glVertex2f(-0.3f, 0.75f);
        glVertex2f(-0.31f, 0.65f);

        glVertex2f(-0.25f, 0.75f);
        glVertex2f(-0.26f, 0.65f);

        glVertex2f(-0.2f, 0.75f);
        glVertex2f(-0.21f, 0.65f);

        glVertex2f(-0.15f, 0.75f);
        glVertex2f(-0.16f, 0.65f);

        glVertex2f(-0.1f, 0.75f);
        glVertex2f(-0.11f, 0.65f);

        glVertex2f(-0.05f, 0.75f);
        glVertex2f(-0.06f, 0.65f);

        glVertex2f(0.0f, 0.75f);
        glVertex2f(-0.01f, 0.65f);

        glVertex2f(0.05f, 0.75f);
        glVertex2f(0.04f, 0.65f);

        glVertex2f(0.10f, 0.75f);
        glVertex2f(0.09f, 0.65f);

        glVertex2f(0.15f, 0.75f);
        glVertex2f(0.14f, 0.65f);

        glVertex2f(0.20f, 0.75f);
        glVertex2f(0.19f, 0.65f);

        glVertex2f(0.25f, 0.75f);
        glVertex2f(0.24f, 0.65f);

        glVertex2f(0.30f, 0.75f);
        glVertex2f(0.29f, 0.65f);

        glVertex2f(0.35f, 0.75f);
        glVertex2f(0.34f, 0.65f);

        glVertex2f(0.40f, 0.75f);
        glVertex2f(0.39f, 0.65f);

        glVertex2f(0.45f, 0.75f);
        glVertex2f(0.44f, 0.65f);

        glVertex2f(0.50f, 0.75f);
        glVertex2f(0.49f, 0.65f);

        glVertex2f(0.55f, 0.75f);
        glVertex2f(0.54f, 0.65f);

        glVertex2f(0.60f, 0.75f);
        glVertex2f(0.59f, 0.65f);

        glVertex2f(0.65f, 0.75f);
        glVertex2f(0.64f, 0.65f);

        glVertex2f(0.70f, 0.75f);
        glVertex2f(0.69f, 0.65f);

        glVertex2f(0.75f, 0.75f);
        glVertex2f(0.74f, 0.65f);

        glVertex2f(0.80f, 0.75f);
        glVertex2f(0.79f, 0.65f);

        glVertex2f(0.85f, 0.75f);
        glVertex2f(0.84f, 0.65f);

        glVertex2f(0.90f, 0.75f);
        glVertex2f(0.89f, 0.65f);

        glVertex2f(0.95f, 0.75f);
        glVertex2f(0.94f, 0.65f);

        glVertex2f(1.0f, 0.75f);
        glVertex2f(0.99f, 0.65f);

        glVertex2f(1.05f, 0.75f);
        glVertex2f(1.04f, 0.65f);

        glEnd();

        ///2nd line end

        ///3rd line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.55f);
        glVertex2f(-0.96f, 0.45f);

        glVertex2f(-0.9f, 0.55f);
        glVertex2f(-0.91f, 0.45f);

        glVertex2f(-0.85f, 0.55f);
        glVertex2f(-0.86f, 0.45f);

        glVertex2f(-0.8f, 0.55f);
        glVertex2f(-0.81f, 0.45f);

        glVertex2f(-0.75f, 0.55f);
        glVertex2f(-0.76f, 0.45f);

        glVertex2f(-0.7f, 0.55f);
        glVertex2f(-0.71f, 0.45f);

        glVertex2f(-0.65f, 0.55f);
        glVertex2f(-0.66f, 0.45f);

        glVertex2f(-0.6f, 0.55f);
        glVertex2f(-0.61f, 0.45f);

        glVertex2f(-0.55f, 0.55f);
        glVertex2f(-0.56f, 0.45f);

        glVertex2f(-0.5f, 0.55f);
        glVertex2f(-0.51f, 0.45f);

        glVertex2f(-0.45f, 0.55f);
        glVertex2f(-0.46f, 0.45f);

        glVertex2f(-0.4f, 0.55f);
        glVertex2f(-0.41f, 0.45f);

        glVertex2f(-0.35f, 0.55f);
        glVertex2f(-0.36f, 0.45f);

        glVertex2f(-0.3f, 0.55f);
        glVertex2f(-0.31f, 0.45f);

        glVertex2f(-0.25f, 0.55f);
        glVertex2f(-0.26f, 0.45f);

        glVertex2f(-0.2f, 0.55f);
        glVertex2f(-0.21f, 0.45f);

        glVertex2f(-0.15f, 0.55f);
        glVertex2f(-0.16f, 0.45f);

        glVertex2f(-0.1f, 0.55f);
        glVertex2f(-0.11f, 0.45f);

        glVertex2f(-0.05f, 0.55f);
        glVertex2f(-0.06f, 0.45f);

        glVertex2f(0.0f, 0.55f);
        glVertex2f(-0.01f, 0.45f);

        glVertex2f(0.05f, 0.55f);
        glVertex2f(0.04f, 0.45f);

        glVertex2f(0.10f, 0.55f);
        glVertex2f(0.09f, 0.45f);

        glVertex2f(0.15f, 0.55f);
        glVertex2f(0.14f, 0.45f);

        glVertex2f(0.20f, 0.55f);
        glVertex2f(0.19f, 0.45f);

        glVertex2f(0.25f, 0.55f);
        glVertex2f(0.24f, 0.45f);

        glVertex2f(0.30f, 0.55f);
        glVertex2f(0.29f, 0.45f);

        glVertex2f(0.35f, 0.55f);
        glVertex2f(0.34f, 0.45f);

        glVertex2f(0.40f, 0.55f);
        glVertex2f(0.39f, 0.45f);

        glVertex2f(0.45f, 0.55f);
        glVertex2f(0.44f, 0.45f);

        glVertex2f(0.50f, 0.55f);
        glVertex2f(0.49f, 0.45f);

        glVertex2f(0.55f, 0.55f);
        glVertex2f(0.54f, 0.45f);

        glVertex2f(0.60f, 0.55f);
        glVertex2f(0.59f, 0.45f);

        glVertex2f(0.65f, 0.55f);
        glVertex2f(0.64f, 0.45f);

        glVertex2f(0.70f, 0.55f);
        glVertex2f(0.69f, 0.45f);

        glVertex2f(0.75f, 0.55f);
        glVertex2f(0.74f, 0.45f);

        glVertex2f(0.80f, 0.55f);
        glVertex2f(0.79f, 0.45f);

        glVertex2f(0.85f, 0.55f);
        glVertex2f(0.84f, 0.45f);

        glVertex2f(0.90f, 0.55f);
        glVertex2f(0.89f, 0.45f);

        glVertex2f(0.95f, 0.55f);
        glVertex2f(0.94f, 0.45f);

        glVertex2f(1.0f, 0.55f);
        glVertex2f(0.99f, 0.45f);

        glVertex2f(1.05f, 0.55f);
        glVertex2f(1.04f, 0.45f);

        glEnd();

        ///3rd line end

        ///4th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.35f);
        glVertex2f(-0.96f, 0.25f);

        glVertex2f(-0.9f, 0.35f);
        glVertex2f(-0.91f, 0.25f);

        glVertex2f(-0.85f, 0.35f);
        glVertex2f(-0.86f, 0.25f);

        glVertex2f(-0.8f, 0.35f);
        glVertex2f(-0.81f, 0.25f);

        glVertex2f(-0.75f, 0.35f);
        glVertex2f(-0.76f, 0.25f);

        glVertex2f(-0.7f, 0.35f);
        glVertex2f(-0.71f, 0.25f);

        glVertex2f(-0.65f, 0.35f);
        glVertex2f(-0.66f, 0.25f);

        glVertex2f(-0.6f, 0.35f);
        glVertex2f(-0.61f, 0.25f);

        glVertex2f(-0.55f, 0.35f);
        glVertex2f(-0.56f, 0.25f);

        glVertex2f(-0.5f, 0.35f);
        glVertex2f(-0.51f, 0.25f);

        glVertex2f(-0.45f, 0.35f);
        glVertex2f(-0.46f, 0.25f);

        glVertex2f(-0.4f, 0.35f);
        glVertex2f(-0.41f, 0.25f);

        glVertex2f(-0.35f, 0.35f);
        glVertex2f(-0.36f, 0.25f);

        glVertex2f(-0.3f, 0.35f);
        glVertex2f(-0.31f, 0.25f);

        glVertex2f(-0.25f, 0.35f);
        glVertex2f(-0.26f, 0.25f);

        glVertex2f(-0.2f, 0.35f);
        glVertex2f(-0.21f, 0.25f);

        glVertex2f(-0.15f, 0.35f);
        glVertex2f(-0.16f, 0.25f);

        glVertex2f(-0.1f, 0.35f);
        glVertex2f(-0.11f, 0.25f);

        glVertex2f(-0.05f, 0.35f);
        glVertex2f(-0.06f, 0.25f);

        glVertex2f(0.0f, 0.35f);
        glVertex2f(-0.01f, 0.25f);

        glVertex2f(0.05f, 0.35f);
        glVertex2f(0.04f, 0.25f);

        glVertex2f(0.10f, 0.35f);
        glVertex2f(0.09f, 0.25f);

        glVertex2f(0.15f, 0.35f);
        glVertex2f(0.14f, 0.25f);

        glVertex2f(0.20f, 0.35f);
        glVertex2f(0.19f, 0.25f);

        glVertex2f(0.25f, 0.35f);
        glVertex2f(0.24f, 0.25f);

        glVertex2f(0.30f, 0.35f);
        glVertex2f(0.29f, 0.25f);

        glVertex2f(0.35f, 0.35f);
        glVertex2f(0.34f, 0.25f);

        glVertex2f(0.40f, 0.35f);
        glVertex2f(0.39f, 0.25f);

        glVertex2f(0.45f, 0.35f);
        glVertex2f(0.44f, 0.25f);

        glVertex2f(0.50f, 0.35f);
        glVertex2f(0.49f, 0.25f);

        glVertex2f(0.55f, 0.35f);
        glVertex2f(0.54f, 0.25f);

        glVertex2f(0.60f, 0.35f);
        glVertex2f(0.59f, 0.25f);

        glVertex2f(0.65f, 0.35f);
        glVertex2f(0.64f, 0.25f);

        glVertex2f(0.70f, 0.35f);
        glVertex2f(0.69f, 0.25f);

        glVertex2f(0.75f, 0.35f);
        glVertex2f(0.74f, 0.25f);

        glVertex2f(0.80f, 0.35f);
        glVertex2f(0.79f, 0.25f);

        glVertex2f(0.85f, 0.35f);
        glVertex2f(0.84f, 0.25f);

        glVertex2f(0.90f, 0.35f);
        glVertex2f(0.89f, 0.25f);

        glVertex2f(0.95f, 0.35f);
        glVertex2f(0.94f, 0.25f);

        glVertex2f(1.0f, 0.35f);
        glVertex2f(0.99f, 0.25f);

        glVertex2f(1.05f, 0.35f);
        glVertex2f(1.04f, 0.25f);

        glEnd();

        ///4th line end

        ///5th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.15f);
        glVertex2f(-0.96f, 0.05f);

        glVertex2f(-0.9f, 0.15f);
        glVertex2f(-0.91f, 0.05f);

        glVertex2f(-0.85f, 0.15f);
        glVertex2f(-0.86f, 0.05f);

        glVertex2f(-0.8f, 0.15f);
        glVertex2f(-0.81f, 0.05f);

        glVertex2f(-0.75f, 0.15f);
        glVertex2f(-0.76f, 0.05f);

        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-0.71f, 0.05f);

        glVertex2f(-0.65f, 0.15f);
        glVertex2f(-0.66f, 0.05f);

        glVertex2f(-0.6f, 0.15f);
        glVertex2f(-0.61f, 0.05f);

        glVertex2f(-0.55f, 0.15f);
        glVertex2f(-0.56f, 0.05f);

        glVertex2f(-0.5f, 0.15f);
        glVertex2f(-0.51f, 0.05f);

        glVertex2f(-0.45f, 0.15f);
        glVertex2f(-0.46f, 0.05f);

        glVertex2f(-0.4f, 0.15f);
        glVertex2f(-0.41f, 0.05f);

        glVertex2f(-0.35f, 0.15f);
        glVertex2f(-0.36f, 0.05f);

        glVertex2f(-0.3f, 0.15f);
        glVertex2f(-0.31f, 0.05f);

        glVertex2f(-0.25f, 0.15f);
        glVertex2f(-0.26f, 0.05f);

        glVertex2f(-0.2f, 0.15f);
        glVertex2f(-0.21f, 0.05f);

        glVertex2f(-0.15f, 0.15f);
        glVertex2f(-0.16f, 0.05f);

        glVertex2f(-0.1f, 0.15f);
        glVertex2f(-0.11f, 0.05f);

        glVertex2f(-0.05f, 0.15f);
        glVertex2f(-0.06f, 0.05f);

        glVertex2f(0.0f, 0.15f);
        glVertex2f(-0.01f, 0.05f);

        glVertex2f(0.05f, 0.15f);
        glVertex2f(0.04f, 0.05f);

        glVertex2f(0.10f, 0.15f);
        glVertex2f(0.09f, 0.05f);

        glVertex2f(0.15f, 0.15f);
        glVertex2f(0.14f, 0.05f);

        glVertex2f(0.20f, 0.15f);
        glVertex2f(0.19f, 0.05f);

        glVertex2f(0.25f, 0.15f);
        glVertex2f(0.24f, 0.05f);

        glVertex2f(0.30f, 0.15f);
        glVertex2f(0.29f, 0.05f);

        glVertex2f(0.35f, 0.15f);
        glVertex2f(0.34f, 0.05f);

        glVertex2f(0.40f, 0.15f);
        glVertex2f(0.39f, 0.05f);

        glVertex2f(0.45f, 0.15f);
        glVertex2f(0.44f, 0.05f);

        glVertex2f(0.50f, 0.15f);
        glVertex2f(0.49f, 0.05f);

        glVertex2f(0.55f, 0.15f);
        glVertex2f(0.54f, 0.05f);

        glVertex2f(0.60f, 0.15f);
        glVertex2f(0.59f, 0.05f);

        glVertex2f(0.65f, 0.15f);
        glVertex2f(0.64f, 0.05f);

        glVertex2f(0.70f, 0.15f);
        glVertex2f(0.69f, 0.05f);

        glVertex2f(0.75f, 0.15f);
        glVertex2f(0.74f, 0.05f);

        glVertex2f(0.80f, 0.15f);
        glVertex2f(0.79f, 0.05f);

        glVertex2f(0.85f, 0.15f);
        glVertex2f(0.84f, 0.05f);

        glVertex2f(0.90f, 0.15f);
        glVertex2f(0.89f, 0.05f);

        glVertex2f(0.95f, 0.15f);
        glVertex2f(0.94f, 0.05f);

        glVertex2f(1.0f, 0.15f);
        glVertex2f(0.99f, 0.05f);

        glVertex2f(1.05f, 0.15f);
        glVertex2f(1.04f, 0.05f);

        glEnd();

        ///5th line end

        ///6th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.05f);
        glVertex2f(-0.96f, -0.15f);

        glVertex2f(-0.9f, -0.05f);
        glVertex2f(-0.91f, -0.15f);

        glVertex2f(-0.85f, -0.05f);
        glVertex2f(-0.86f, -0.15f);

        glVertex2f(-0.8f, -0.05f);
        glVertex2f(-0.81f, -0.15f);

        glVertex2f(-0.75f, -0.05f);
        glVertex2f(-0.76f, -0.15f);

        glVertex2f(-0.7f, -0.05f);
        glVertex2f(-0.71f, -0.15f);

        glVertex2f(-0.65f, -0.05f);
        glVertex2f(-0.66f, -0.15f);

        glVertex2f(-0.6f, -0.05f);
        glVertex2f(-0.61f, -0.15f);

        glVertex2f(-0.55f, -0.05f);
        glVertex2f(-0.56f, -0.15f);

        glVertex2f(-0.5f, -0.05f);
        glVertex2f(-0.51f, -0.15f);

        glVertex2f(-0.45f, -0.05f);
        glVertex2f(-0.46f, -0.15f);

        glVertex2f(-0.4f, -0.05f);
        glVertex2f(-0.41f, -0.15f);

        glVertex2f(-0.35f, -0.05f);
        glVertex2f(-0.36f, -0.15f);

        glVertex2f(-0.3f, -0.05f);
        glVertex2f(-0.31f, -0.15f);

        glVertex2f(-0.25f, -0.05f);
        glVertex2f(-0.26f, -0.15f);

        glVertex2f(-0.2f, -0.05f);
        glVertex2f(-0.21f, -0.15f);

        glVertex2f(-0.15f, -0.05f);
        glVertex2f(-0.16f, -0.15f);

        glVertex2f(-0.1f, -0.05f);
        glVertex2f(-0.11f, -0.15f);

        glVertex2f(-0.05f, -0.05f);
        glVertex2f(-0.06f, -0.15f);

        glVertex2f(0.0f, -0.05f);
        glVertex2f(-0.01f, -0.15f);

        glVertex2f(0.05f, -0.05f);
        glVertex2f(0.04f, -0.15f);

        glVertex2f(0.10f, -0.05f);
        glVertex2f(0.09f, -0.15f);

        glVertex2f(0.15f, -0.05f);
        glVertex2f(0.14f, -0.15f);

        glVertex2f(0.20f, -0.05f);
        glVertex2f(0.19f, -0.15f);

        glVertex2f(0.25f, -0.05f);
        glVertex2f(0.24f, -0.15f);

        glVertex2f(0.30f, -0.05f);
        glVertex2f(0.29f, -0.15f);

        glVertex2f(0.35f, -0.05f);
        glVertex2f(0.34f, -0.15f);

        glVertex2f(0.40f, -0.05f);
        glVertex2f(0.39f, -0.15f);

        glVertex2f(0.45f, -0.05f);
        glVertex2f(0.44f, -0.15f);

        glVertex2f(0.50f, -0.05f);
        glVertex2f(0.49f, -0.15f);

        glVertex2f(0.55f, -0.05f);
        glVertex2f(0.54f, -0.15f);

        glVertex2f(0.60f, -0.05f);
        glVertex2f(0.59f, -0.15f);

        glVertex2f(0.65f, -0.05f);
        glVertex2f(0.64f, -0.15f);

        glVertex2f(0.70f, -0.05f);
        glVertex2f(0.69f, -0.15f);

        glVertex2f(0.75f, -0.05f);
        glVertex2f(0.74f, -0.15f);

        glVertex2f(0.80f, -0.05f);
        glVertex2f(0.79f, -0.15f);

        glVertex2f(0.85f, -0.05f);
        glVertex2f(0.84f, -0.15f);

        glVertex2f(0.90f, -0.05f);
        glVertex2f(0.89f, -0.15f);

        glVertex2f(0.95f, -0.05f);
        glVertex2f(0.94f, -0.15f);

        glVertex2f(1.0f, -0.05f);
        glVertex2f(0.99f, -0.15f);

        glVertex2f(1.05f, -0.05f);
        glVertex2f(1.04f, -0.15f);

        glEnd();

        ///6th line end


        ///7th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.25f);
        glVertex2f(-0.96f, -0.35f);

        glVertex2f(-0.9f, -0.25f);
        glVertex2f(-0.91f, -0.35f);

        glVertex2f(-0.85f, -0.25f);
        glVertex2f(-0.86f, -0.35f);

        glVertex2f(-0.8f, -0.25f);
        glVertex2f(-0.81f, -0.35f);

        glVertex2f(-0.75f, -0.25f);
        glVertex2f(-0.76f, -0.35f);

        glVertex2f(-0.7f, -0.25f);
        glVertex2f(-0.71f, -0.35f);

        glVertex2f(-0.65f, -0.25f);
        glVertex2f(-0.66f, -0.35f);

        glVertex2f(-0.6f, -0.25f);
        glVertex2f(-0.61f, -0.35f);

        glVertex2f(-0.55f, -0.25f);
        glVertex2f(-0.56f, -0.35f);

        glVertex2f(-0.5f, -0.25f);
        glVertex2f(-0.51f, -0.35f);

        glVertex2f(-0.45f, -0.25f);
        glVertex2f(-0.46f, -0.35f);

        glVertex2f(-0.4f, -0.25f);
        glVertex2f(-0.41f, -0.35f);

        glVertex2f(-0.35f, -0.25f);
        glVertex2f(-0.36f, -0.35f);

        glVertex2f(-0.3f, -0.25f);
        glVertex2f(-0.31f, -0.35f);

        glVertex2f(-0.25f, -0.25f);
        glVertex2f(-0.26f, -0.35f);

        glVertex2f(-0.2f, -0.25f);
        glVertex2f(-0.21f, -0.35f);

        glVertex2f(-0.15f, -0.25f);
        glVertex2f(-0.16f, -0.35f);

        glVertex2f(-0.1f, -0.25f);
        glVertex2f(-0.11f, -0.35f);

        glVertex2f(-0.05f, -0.25f);
        glVertex2f(-0.06f, -0.35f);

        glVertex2f(0.0f, -0.25f);
        glVertex2f(-0.01f, -0.35f);

        glVertex2f(0.05f, -0.25f);
        glVertex2f(0.04f, -0.35f);

        glVertex2f(0.10f, -0.25f);
        glVertex2f(0.09f, -0.35f);

        glVertex2f(0.15f, -0.25f);
        glVertex2f(0.14f, -0.35f);

        glVertex2f(0.20f, -0.25f);
        glVertex2f(0.19f, -0.35f);

        glVertex2f(0.25f, -0.25f);
        glVertex2f(0.24f, -0.35f);

        glVertex2f(0.30f, -0.25f);
        glVertex2f(0.29f, -0.35f);

        glVertex2f(0.35f, -0.25f);
        glVertex2f(0.34f, -0.35f);

        glVertex2f(0.40f, -0.25f);
        glVertex2f(0.39f, -0.35f);

        glVertex2f(0.45f, -0.25f);
        glVertex2f(0.44f, -0.35f);

        glVertex2f(0.50f, -0.25f);
        glVertex2f(0.49f, -0.35f);

        glVertex2f(0.55f, -0.25f);
        glVertex2f(0.54f, -0.35f);

        glVertex2f(0.60f, -0.25f);
        glVertex2f(0.59f, -0.35f);

        glVertex2f(0.65f, -0.25f);
        glVertex2f(0.64f, -0.35f);

        glVertex2f(0.70f, -0.25f);
        glVertex2f(0.69f, -0.35f);

        glVertex2f(0.75f, -0.25f);
        glVertex2f(0.74f, -0.35f);

        glVertex2f(0.80f, -0.25f);
        glVertex2f(0.79f, -0.35f);

        glVertex2f(0.85f, -0.25f);
        glVertex2f(0.84f, -0.35f);

        glVertex2f(0.90f, -0.25f);
        glVertex2f(0.89f, -0.35f);

        glVertex2f(0.95f, -0.25f);
        glVertex2f(0.94f, -0.35f);

        glVertex2f(1.0f, -0.25f);
        glVertex2f(0.99f, -0.35f);

        glVertex2f(1.05f, -0.25f);
        glVertex2f(1.04f, -0.35f);

        glEnd();

        ///7th line end

        ///8th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.45f);
        glVertex2f(-0.96f, -0.55f);

        glVertex2f(-0.9f, -0.45f);
        glVertex2f(-0.91f, -0.55f);

        glVertex2f(-0.85f, -0.45f);
        glVertex2f(-0.86f, -0.55f);

        glVertex2f(-0.8f, -0.45f);
        glVertex2f(-0.81f, -0.55f);

        glVertex2f(-0.75f, -0.45f);
        glVertex2f(-0.76f, -0.55f);

        glVertex2f(-0.7f, -0.45f);
        glVertex2f(-0.71f, -0.55f);

        glVertex2f(-0.65f, -0.45f);
        glVertex2f(-0.66f, -0.55f);

        glVertex2f(-0.6f, -0.45f);
        glVertex2f(-0.61f, -0.55f);

        glVertex2f(-0.55f, -0.45f);
        glVertex2f(-0.56f, -0.55f);

        glVertex2f(-0.5f, -0.45f);
        glVertex2f(-0.51f, -0.55f);

        glVertex2f(-0.45f, -0.45f);
        glVertex2f(-0.46f, -0.55f);

        glVertex2f(-0.4f, -0.45f);
        glVertex2f(-0.41f, -0.55f);

        glVertex2f(-0.35f, -0.45f);
        glVertex2f(-0.36f, -0.55f);

        glVertex2f(-0.3f, -0.45f);
        glVertex2f(-0.31f, -0.55f);

        glVertex2f(-0.25f, -0.45f);
        glVertex2f(-0.26f, -0.55f);

        glVertex2f(-0.2f, -0.45f);
        glVertex2f(-0.21f, -0.55f);

        glVertex2f(-0.15f, -0.45f);
        glVertex2f(-0.16f, -0.55f);

        glVertex2f(-0.1f, -0.45f);
        glVertex2f(-0.11f, -0.55f);

        glVertex2f(-0.05f, -0.45f);
        glVertex2f(-0.06f, -0.55f);

        glVertex2f(0.0f, -0.45f);
        glVertex2f(-0.01f, -0.55f);

        glVertex2f(0.05f, -0.45f);
        glVertex2f(0.04f, -0.55f);

        glVertex2f(0.10f, -0.45f);
        glVertex2f(0.09f, -0.55f);

        glVertex2f(0.15f, -0.45f);
        glVertex2f(0.14f, -0.55f);

        glVertex2f(0.20f, -0.45f);
        glVertex2f(0.19f, -0.55f);

        glVertex2f(0.25f, -0.45f);
        glVertex2f(0.24f, -0.55f);

        glVertex2f(0.30f, -0.45f);
        glVertex2f(0.29f, -0.55f);

        glVertex2f(0.35f, -0.45f);
        glVertex2f(0.34f, -0.55f);

        glVertex2f(0.40f, -0.45f);
        glVertex2f(0.39f, -0.55f);

        glVertex2f(0.45f, -0.45f);
        glVertex2f(0.44f, -0.55f);

        glVertex2f(0.50f, -0.45f);
        glVertex2f(0.49f, -0.55f);

        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.54f, -0.55f);

        glVertex2f(0.60f, -0.45f);
        glVertex2f(0.59f, -0.55f);

        glVertex2f(0.65f, -0.45f);
        glVertex2f(0.64f, -0.55f);

        glVertex2f(0.70f, -0.45f);
        glVertex2f(0.69f, -0.55f);

        glVertex2f(0.75f, -0.45f);
        glVertex2f(0.74f, -0.55f);

        glVertex2f(0.80f, -0.45f);
        glVertex2f(0.79f, -0.55f);

        glVertex2f(0.85f, -0.45f);
        glVertex2f(0.84f, -0.55f);

        glVertex2f(0.90f, -0.45f);
        glVertex2f(0.89f, -0.55f);

        glVertex2f(0.95f, -0.45f);
        glVertex2f(0.94f, -0.55f);

        glVertex2f(1.0f, -0.45f);
        glVertex2f(0.99f, -0.55f);

        glVertex2f(1.05f, -0.45f);
        glVertex2f(1.04f, -0.55f);

        glEnd();

        ///8th line end

        ///9th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.65f);
        glVertex2f(-0.96f, -0.75f);

        glVertex2f(-0.9f, -0.65f);
        glVertex2f(-0.91f, -0.75f);

        glVertex2f(-0.85f, -0.65f);
        glVertex2f(-0.86f, -0.75f);

        glVertex2f(-0.8f, -0.65f);
        glVertex2f(-0.81f, -0.75f);

        glVertex2f(-0.75f, -0.65f);
        glVertex2f(-0.76f, -0.75f);

        glVertex2f(-0.7f, -0.65f);
        glVertex2f(-0.71f, -0.75f);

        glVertex2f(-0.65f, -0.65f);
        glVertex2f(-0.66f, -0.75f);

        glVertex2f(-0.6f, -0.65f);
        glVertex2f(-0.61f, -0.75f);

        glVertex2f(-0.55f, -0.65f);
        glVertex2f(-0.56f, -0.75f);

        glVertex2f(-0.5f, -0.65f);
        glVertex2f(-0.51f, -0.75f);

        glVertex2f(-0.45f, -0.65f);
        glVertex2f(-0.46f, -0.75f);

        glVertex2f(-0.4f, -0.65f);
        glVertex2f(-0.41f, -0.75f);

        glVertex2f(-0.35f, -0.65f);
        glVertex2f(-0.36f, -0.75f);

        glVertex2f(-0.3f, -0.65f);
        glVertex2f(-0.31f, -0.75f);

        glVertex2f(-0.25f, -0.65f);
        glVertex2f(-0.26f, -0.75f);

        glVertex2f(-0.2f, -0.65f);
        glVertex2f(-0.21f, -0.75f);

        glVertex2f(-0.15f, -0.65f);
        glVertex2f(-0.16f, -0.75f);

        glVertex2f(-0.1f, -0.65f);
        glVertex2f(-0.11f, -0.75f);

        glVertex2f(-0.05f, -0.65f);
        glVertex2f(-0.06f, -0.75f);

        glVertex2f(0.0f, -0.65f);
        glVertex2f(-0.01f, -0.75f);

        glVertex2f(0.05f, -0.65f);
        glVertex2f(0.04f, -0.75f);

        glVertex2f(0.10f, -0.65f);
        glVertex2f(0.09f, -0.75f);

        glVertex2f(0.15f, -0.65f);
        glVertex2f(0.14f, -0.75f);

        glVertex2f(0.20f, -0.65f);
        glVertex2f(0.19f, -0.75f);

        glVertex2f(0.25f, -0.65f);
        glVertex2f(0.24f, -0.75f);

        glVertex2f(0.30f, -0.65f);
        glVertex2f(0.29f, -0.75f);

        glVertex2f(0.35f, -0.65f);
        glVertex2f(0.34f, -0.75f);

        glVertex2f(0.40f, -0.65f);
        glVertex2f(0.39f, -0.75f);

        glVertex2f(0.45f, -0.65f);
        glVertex2f(0.44f, -0.75f);

        glVertex2f(0.50f, -0.65f);
        glVertex2f(0.49f, -0.75f);

        glVertex2f(0.55f, -0.65f);
        glVertex2f(0.54f, -0.75f);

        glVertex2f(0.60f, -0.65f);
        glVertex2f(0.59f, -0.75f);

        glVertex2f(0.65f, -0.65f);
        glVertex2f(0.64f, -0.75f);

        glVertex2f(0.70f, -0.65f);
        glVertex2f(0.69f, -0.75f);

        glVertex2f(0.75f, -0.65f);
        glVertex2f(0.74f, -0.75f);

        glVertex2f(0.80f, -0.65f);
        glVertex2f(0.79f, -0.75f);

        glVertex2f(0.85f, -0.65f);
        glVertex2f(0.84f, -0.75f);

        glVertex2f(0.90f, -0.65f);
        glVertex2f(0.89f, -0.75f);

        glVertex2f(0.95f, -0.65f);
        glVertex2f(0.94f, -0.75f);

        glVertex2f(1.0f, -0.65f);
        glVertex2f(0.99f, -0.75f);

        glVertex2f(1.05f, -0.65f);
        glVertex2f(1.04f, -0.75f);

        glEnd();

        ///9th line end


        ///10th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.85f);
        glVertex2f(-0.96f, -0.95f);

        glVertex2f(-0.9f, -0.85f);
        glVertex2f(-0.91f, -0.95f);

        glVertex2f(-0.85f, -0.85f);
        glVertex2f(-0.86f, -0.95f);

        glVertex2f(-0.8f, -0.85f);
        glVertex2f(-0.81f, -0.95f);

        glVertex2f(-0.75f, -0.85f);
        glVertex2f(-0.76f, -0.95f);

        glVertex2f(-0.7f, -0.85f);
        glVertex2f(-0.71f, -0.95f);

        glVertex2f(-0.65f, -0.85f);
        glVertex2f(-0.66f, -0.95f);

        glVertex2f(-0.6f, -0.85f);
        glVertex2f(-0.61f, -0.95f);

        glVertex2f(-0.55f, -0.85f);
        glVertex2f(-0.56f, -0.95f);

        glVertex2f(-0.5f, -0.85f);
        glVertex2f(-0.51f, -0.95f);

        glVertex2f(-0.45f, -0.85f);
        glVertex2f(-0.46f, -0.95f);

        glVertex2f(-0.4f, -0.85f);
        glVertex2f(-0.41f, -0.95f);

        glVertex2f(-0.35f, -0.85f);
        glVertex2f(-0.36f, -0.95f);

        glVertex2f(-0.3f, -0.85f);
        glVertex2f(-0.31f, -0.95f);

        glVertex2f(-0.25f, -0.85f);
        glVertex2f(-0.26f, -0.95f);

        glVertex2f(-0.2f, -0.85f);
        glVertex2f(-0.21f, -0.95f);

        glVertex2f(-0.15f, -0.85f);
        glVertex2f(-0.16f, -0.95f);

        glVertex2f(-0.1f, -0.85f);
        glVertex2f(-0.11f, -0.95f);

        glVertex2f(-0.05f, -0.85f);
        glVertex2f(-0.06f, -0.95f);

        glVertex2f(0.0f, -0.85f);
        glVertex2f(-0.01f, -0.95f);

        glVertex2f(0.05f, -0.85f);
        glVertex2f(0.04f, -0.95f);

        glVertex2f(0.10f, -0.85f);
        glVertex2f(0.09f, -0.95f);

        glVertex2f(0.15f, -0.85f);
        glVertex2f(0.14f, -0.95f);

        glVertex2f(0.20f, -0.85f);
        glVertex2f(0.19f, -0.95f);

        glVertex2f(0.25f, -0.85f);
        glVertex2f(0.24f, -0.95f);

        glVertex2f(0.30f, -0.85f);
        glVertex2f(0.29f, -0.95f);

        glVertex2f(0.35f, -0.85f);
        glVertex2f(0.34f, -0.95f);

        glVertex2f(0.40f, -0.85f);
        glVertex2f(0.39f, -0.95f);

        glVertex2f(0.45f, -0.85f);
        glVertex2f(0.44f, -0.95f);

        glVertex2f(0.50f, -0.85f);
        glVertex2f(0.49f, -0.95f);

        glVertex2f(0.55f, -0.85f);
        glVertex2f(0.54f, -1.0f);

        glVertex2f(0.60f, -0.85f);
        glVertex2f(0.59f, -0.95f);

        glVertex2f(0.65f, -0.85f);
        glVertex2f(0.64f, -0.95f);

        glVertex2f(0.70f, -0.85f);
        glVertex2f(0.69f, -0.95f);

        glVertex2f(0.75f, -0.85f);
        glVertex2f(0.74f, -0.95f);

        glVertex2f(0.80f, -0.85f);
        glVertex2f(0.79f, -0.95f);

        glVertex2f(0.85f, -0.85f);
        glVertex2f(0.84f, -0.95f);

        glVertex2f(0.90f, -0.85f);
        glVertex2f(0.89f, -0.95f);

        glVertex2f(0.95f, -0.85f);
        glVertex2f(0.94f, -0.95f);

        glVertex2f(1.0f, -0.85f);
        glVertex2f(0.99f, -0.95f);

        glVertex2f(1.05f, -0.85f);
        glVertex2f(1.04f, -0.95f);

        glEnd();
        glPopMatrix();
    }

    ///10th line end

    ///------------------------------rain 01 end

    if(rain)
    {
        glPushMatrix();
        glTranslatef(0.0f, position12, 0.0f);
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.95f);
        glVertex2f(-0.96f, 0.85f);

        glVertex2f(-0.9f, 0.95f);
        glVertex2f(-0.91f, 0.85f);

        glVertex2f(-0.85f, 0.95f);
        glVertex2f(-0.86f, 0.85f);

        glVertex2f(-0.8f, 0.95f);
        glVertex2f(-0.81f, 0.85f);

        glVertex2f(-0.75f, 0.95f);
        glVertex2f(-0.76f, 0.85f);

        glVertex2f(-0.7f, 0.95f);
        glVertex2f(-0.71f, 0.85f);

        glVertex2f(-0.65f, 0.95f);
        glVertex2f(-0.66f, 0.85f);

        glVertex2f(-0.6f, 0.95f);
        glVertex2f(-0.61f, 0.85f);

        glVertex2f(-0.55f, 0.95f);
        glVertex2f(-0.56f, 0.85f);

        glVertex2f(-0.5f, 0.95f);
        glVertex2f(-0.51f, 0.85f);

        glVertex2f(-0.45f, 0.95f);
        glVertex2f(-0.46f, 0.85f);

        glVertex2f(-0.4f, 0.95f);
        glVertex2f(-0.41f, 0.85f);

        glVertex2f(-0.35f, 0.95f);
        glVertex2f(-0.36f, 0.85f);

        glVertex2f(-0.3f, 0.95f);
        glVertex2f(-0.31f, 0.85f);

        glVertex2f(-0.25f, 0.95f);
        glVertex2f(-0.26f, 0.85f);

        glVertex2f(-0.2f, 0.95f);
        glVertex2f(-0.21f, 0.85f);

        glVertex2f(-0.15f, 0.95f);
        glVertex2f(-0.16f, 0.85f);

        glVertex2f(-0.1f, 0.95f);
        glVertex2f(-0.11f, 0.85f);

        glVertex2f(-0.05f, 0.95f);
        glVertex2f(-0.06f, 0.85f);

        glVertex2f(0.0f, 0.95f);
        glVertex2f(-0.01f, 0.85f);

        glVertex2f(0.05f, 0.95f);
        glVertex2f(0.04f, 0.85f);

        glVertex2f(0.10f, 0.95f);
        glVertex2f(0.09f, 0.85f);

        glVertex2f(0.15f, 0.95f);
        glVertex2f(0.14f, 0.85f);

        glVertex2f(0.20f, 0.95f);
        glVertex2f(0.19f, 0.85f);

        glVertex2f(0.25f, 0.95f);
        glVertex2f(0.24f, 0.85f);

        glVertex2f(0.30f, 0.95f);
        glVertex2f(0.29f, 0.85f);

        glVertex2f(0.35f, 0.95f);
        glVertex2f(0.34f, 0.85f);

        glVertex2f(0.40f, 1.0f);
        glVertex2f(0.39f, 0.85f);

        glVertex2f(0.45f, 0.95f);
        glVertex2f(0.44f, 0.85f);

        glVertex2f(0.50f, 0.95f);
        glVertex2f(0.49f, 0.85f);

        glVertex2f(0.55f, 0.95f);
        glVertex2f(0.54f, 0.85f);

        glVertex2f(0.60f, 0.95f);
        glVertex2f(0.59f, 0.85f);

        glVertex2f(0.65f, 0.95f);
        glVertex2f(0.64f, 0.85f);

        glVertex2f(0.70f, 0.95f);
        glVertex2f(0.69f, 0.85f);

        glVertex2f(0.75f, 0.95f);
        glVertex2f(0.74f, 0.85f);

        glVertex2f(0.80f, 0.95f);
        glVertex2f(0.79f, 0.85f);

        glVertex2f(0.85f, 0.95f);
        glVertex2f(0.84f, 0.85f);

        glVertex2f(0.90f, 0.95f);
        glVertex2f(0.89f, 0.85f);

        glVertex2f(0.95f, 0.95f);
        glVertex2f(0.94f, 0.85f);

        glVertex2f(1.0f, 0.95f);
        glVertex2f(0.99f, 0.85f);

        glVertex2f(1.05f, 0.95f);
        glVertex2f(1.04f, 0.85f);

        glEnd();


        ///2nd line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.75f);
        glVertex2f(-0.96f, 0.65f);

        glVertex2f(-0.9f, 0.75f);
        glVertex2f(-0.91f, 0.65f);

        glVertex2f(-0.85f, 0.75f);
        glVertex2f(-0.86f, 0.65f);

        glVertex2f(-0.8f, 0.75f);
        glVertex2f(-0.81f, 0.65f);

        glVertex2f(-0.75f, 0.75f);
        glVertex2f(-0.76f, 0.65f);

        glVertex2f(-0.7f, 0.75f);
        glVertex2f(-0.71f, 0.65f);

        glVertex2f(-0.65f, 0.75f);
        glVertex2f(-0.66f, 0.65f);

        glVertex2f(-0.6f, 0.75f);
        glVertex2f(-0.61f, 0.65f);

        glVertex2f(-0.55f, 0.75f);
        glVertex2f(-0.56f, 0.65f);

        glVertex2f(-0.5f, 0.75f);
        glVertex2f(-0.51f, 0.65f);

        glVertex2f(-0.45f, 0.75f);
        glVertex2f(-0.46f, 0.65f);

        glVertex2f(-0.4f, 0.75f);
        glVertex2f(-0.41f, 0.65f);

        glVertex2f(-0.35f, 0.75f);
        glVertex2f(-0.36f, 0.65f);

        glVertex2f(-0.3f, 0.75f);
        glVertex2f(-0.31f, 0.65f);

        glVertex2f(-0.25f, 0.75f);
        glVertex2f(-0.26f, 0.65f);

        glVertex2f(-0.2f, 0.75f);
        glVertex2f(-0.21f, 0.65f);

        glVertex2f(-0.15f, 0.75f);
        glVertex2f(-0.16f, 0.65f);

        glVertex2f(-0.1f, 0.75f);
        glVertex2f(-0.11f, 0.65f);

        glVertex2f(-0.05f, 0.75f);
        glVertex2f(-0.06f, 0.65f);

        glVertex2f(0.0f, 0.75f);
        glVertex2f(-0.01f, 0.65f);

        glVertex2f(0.05f, 0.75f);
        glVertex2f(0.04f, 0.65f);

        glVertex2f(0.10f, 0.75f);
        glVertex2f(0.09f, 0.65f);

        glVertex2f(0.15f, 0.75f);
        glVertex2f(0.14f, 0.65f);

        glVertex2f(0.20f, 0.75f);
        glVertex2f(0.19f, 0.65f);

        glVertex2f(0.25f, 0.75f);
        glVertex2f(0.24f, 0.65f);

        glVertex2f(0.30f, 0.75f);
        glVertex2f(0.29f, 0.65f);

        glVertex2f(0.35f, 0.75f);
        glVertex2f(0.34f, 0.65f);

        glVertex2f(0.40f, 0.75f);
        glVertex2f(0.39f, 0.65f);

        glVertex2f(0.45f, 0.75f);
        glVertex2f(0.44f, 0.65f);

        glVertex2f(0.50f, 0.75f);
        glVertex2f(0.49f, 0.65f);

        glVertex2f(0.55f, 0.75f);
        glVertex2f(0.54f, 0.65f);

        glVertex2f(0.60f, 0.75f);
        glVertex2f(0.59f, 0.65f);

        glVertex2f(0.65f, 0.75f);
        glVertex2f(0.64f, 0.65f);

        glVertex2f(0.70f, 0.75f);
        glVertex2f(0.69f, 0.65f);

        glVertex2f(0.75f, 0.75f);
        glVertex2f(0.74f, 0.65f);

        glVertex2f(0.80f, 0.75f);
        glVertex2f(0.79f, 0.65f);

        glVertex2f(0.85f, 0.75f);
        glVertex2f(0.84f, 0.65f);

        glVertex2f(0.90f, 0.75f);
        glVertex2f(0.89f, 0.65f);

        glVertex2f(0.95f, 0.75f);
        glVertex2f(0.94f, 0.65f);

        glVertex2f(1.0f, 0.75f);
        glVertex2f(0.99f, 0.65f);

        glVertex2f(1.05f, 0.75f);
        glVertex2f(1.04f, 0.65f);

        glEnd();

        ///2nd line end

        ///3rd line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.55f);
        glVertex2f(-0.96f, 0.45f);

        glVertex2f(-0.9f, 0.55f);
        glVertex2f(-0.91f, 0.45f);

        glVertex2f(-0.85f, 0.55f);
        glVertex2f(-0.86f, 0.45f);

        glVertex2f(-0.8f, 0.55f);
        glVertex2f(-0.81f, 0.45f);

        glVertex2f(-0.75f, 0.55f);
        glVertex2f(-0.76f, 0.45f);

        glVertex2f(-0.7f, 0.55f);
        glVertex2f(-0.71f, 0.45f);

        glVertex2f(-0.65f, 0.55f);
        glVertex2f(-0.66f, 0.45f);

        glVertex2f(-0.6f, 0.55f);
        glVertex2f(-0.61f, 0.45f);

        glVertex2f(-0.55f, 0.55f);
        glVertex2f(-0.56f, 0.45f);

        glVertex2f(-0.5f, 0.55f);
        glVertex2f(-0.51f, 0.45f);

        glVertex2f(-0.45f, 0.55f);
        glVertex2f(-0.46f, 0.45f);

        glVertex2f(-0.4f, 0.55f);
        glVertex2f(-0.41f, 0.45f);

        glVertex2f(-0.35f, 0.55f);
        glVertex2f(-0.36f, 0.45f);

        glVertex2f(-0.3f, 0.55f);
        glVertex2f(-0.31f, 0.45f);

        glVertex2f(-0.25f, 0.55f);
        glVertex2f(-0.26f, 0.45f);

        glVertex2f(-0.2f, 0.55f);
        glVertex2f(-0.21f, 0.45f);

        glVertex2f(-0.15f, 0.55f);
        glVertex2f(-0.16f, 0.45f);

        glVertex2f(-0.1f, 0.55f);
        glVertex2f(-0.11f, 0.45f);

        glVertex2f(-0.05f, 0.55f);
        glVertex2f(-0.06f, 0.45f);

        glVertex2f(0.0f, 0.55f);
        glVertex2f(-0.01f, 0.45f);

        glVertex2f(0.05f, 0.55f);
        glVertex2f(0.04f, 0.45f);

        glVertex2f(0.10f, 0.55f);
        glVertex2f(0.09f, 0.45f);

        glVertex2f(0.15f, 0.55f);
        glVertex2f(0.14f, 0.45f);

        glVertex2f(0.20f, 0.55f);
        glVertex2f(0.19f, 0.45f);

        glVertex2f(0.25f, 0.55f);
        glVertex2f(0.24f, 0.45f);

        glVertex2f(0.30f, 0.55f);
        glVertex2f(0.29f, 0.45f);

        glVertex2f(0.35f, 0.55f);
        glVertex2f(0.34f, 0.45f);

        glVertex2f(0.40f, 0.55f);
        glVertex2f(0.39f, 0.45f);

        glVertex2f(0.45f, 0.55f);
        glVertex2f(0.44f, 0.45f);

        glVertex2f(0.50f, 0.55f);
        glVertex2f(0.49f, 0.45f);

        glVertex2f(0.55f, 0.55f);
        glVertex2f(0.54f, 0.45f);

        glVertex2f(0.60f, 0.55f);
        glVertex2f(0.59f, 0.45f);

        glVertex2f(0.65f, 0.55f);
        glVertex2f(0.64f, 0.45f);

        glVertex2f(0.70f, 0.55f);
        glVertex2f(0.69f, 0.45f);

        glVertex2f(0.75f, 0.55f);
        glVertex2f(0.74f, 0.45f);

        glVertex2f(0.80f, 0.55f);
        glVertex2f(0.79f, 0.45f);

        glVertex2f(0.85f, 0.55f);
        glVertex2f(0.84f, 0.45f);

        glVertex2f(0.90f, 0.55f);
        glVertex2f(0.89f, 0.45f);

        glVertex2f(0.95f, 0.55f);
        glVertex2f(0.94f, 0.45f);

        glVertex2f(1.0f, 0.55f);
        glVertex2f(0.99f, 0.45f);

        glVertex2f(1.05f, 0.55f);
        glVertex2f(1.04f, 0.45f);

        glEnd();

        ///3rd line end

        ///4th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.35f);
        glVertex2f(-0.96f, 0.25f);

        glVertex2f(-0.9f, 0.35f);
        glVertex2f(-0.91f, 0.25f);

        glVertex2f(-0.85f, 0.35f);
        glVertex2f(-0.86f, 0.25f);

        glVertex2f(-0.8f, 0.35f);
        glVertex2f(-0.81f, 0.25f);

        glVertex2f(-0.75f, 0.35f);
        glVertex2f(-0.76f, 0.25f);

        glVertex2f(-0.7f, 0.35f);
        glVertex2f(-0.71f, 0.25f);

        glVertex2f(-0.65f, 0.35f);
        glVertex2f(-0.66f, 0.25f);

        glVertex2f(-0.6f, 0.35f);
        glVertex2f(-0.61f, 0.25f);

        glVertex2f(-0.55f, 0.35f);
        glVertex2f(-0.56f, 0.25f);

        glVertex2f(-0.5f, 0.35f);
        glVertex2f(-0.51f, 0.25f);

        glVertex2f(-0.45f, 0.35f);
        glVertex2f(-0.46f, 0.25f);

        glVertex2f(-0.4f, 0.35f);
        glVertex2f(-0.41f, 0.25f);

        glVertex2f(-0.35f, 0.35f);
        glVertex2f(-0.36f, 0.25f);

        glVertex2f(-0.3f, 0.35f);
        glVertex2f(-0.31f, 0.25f);

        glVertex2f(-0.25f, 0.35f);
        glVertex2f(-0.26f, 0.25f);

        glVertex2f(-0.2f, 0.35f);
        glVertex2f(-0.21f, 0.25f);

        glVertex2f(-0.15f, 0.35f);
        glVertex2f(-0.16f, 0.25f);

        glVertex2f(-0.1f, 0.35f);
        glVertex2f(-0.11f, 0.25f);

        glVertex2f(-0.05f, 0.35f);
        glVertex2f(-0.06f, 0.25f);

        glVertex2f(0.0f, 0.35f);
        glVertex2f(-0.01f, 0.25f);

        glVertex2f(0.05f, 0.35f);
        glVertex2f(0.04f, 0.25f);

        glVertex2f(0.10f, 0.35f);
        glVertex2f(0.09f, 0.25f);

        glVertex2f(0.15f, 0.35f);
        glVertex2f(0.14f, 0.25f);

        glVertex2f(0.20f, 0.35f);
        glVertex2f(0.19f, 0.25f);

        glVertex2f(0.25f, 0.35f);
        glVertex2f(0.24f, 0.25f);

        glVertex2f(0.30f, 0.35f);
        glVertex2f(0.29f, 0.25f);

        glVertex2f(0.35f, 0.35f);
        glVertex2f(0.34f, 0.25f);

        glVertex2f(0.40f, 0.35f);
        glVertex2f(0.39f, 0.25f);

        glVertex2f(0.45f, 0.35f);
        glVertex2f(0.44f, 0.25f);

        glVertex2f(0.50f, 0.35f);
        glVertex2f(0.49f, 0.25f);

        glVertex2f(0.55f, 0.35f);
        glVertex2f(0.54f, 0.25f);

        glVertex2f(0.60f, 0.35f);
        glVertex2f(0.59f, 0.25f);

        glVertex2f(0.65f, 0.35f);
        glVertex2f(0.64f, 0.25f);

        glVertex2f(0.70f, 0.35f);
        glVertex2f(0.69f, 0.25f);

        glVertex2f(0.75f, 0.35f);
        glVertex2f(0.74f, 0.25f);

        glVertex2f(0.80f, 0.35f);
        glVertex2f(0.79f, 0.25f);

        glVertex2f(0.85f, 0.35f);
        glVertex2f(0.84f, 0.25f);

        glVertex2f(0.90f, 0.35f);
        glVertex2f(0.89f, 0.25f);

        glVertex2f(0.95f, 0.35f);
        glVertex2f(0.94f, 0.25f);

        glVertex2f(1.0f, 0.35f);
        glVertex2f(0.99f, 0.25f);

        glVertex2f(1.05f, 0.35f);
        glVertex2f(1.04f, 0.25f);

        glEnd();

        ///4th line end

        ///5th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, 0.15f);
        glVertex2f(-0.96f, 0.05f);

        glVertex2f(-0.9f, 0.15f);
        glVertex2f(-0.91f, 0.05f);

        glVertex2f(-0.85f, 0.15f);
        glVertex2f(-0.86f, 0.05f);

        glVertex2f(-0.8f, 0.15f);
        glVertex2f(-0.81f, 0.05f);

        glVertex2f(-0.75f, 0.15f);
        glVertex2f(-0.76f, 0.05f);

        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-0.71f, 0.05f);

        glVertex2f(-0.65f, 0.15f);
        glVertex2f(-0.66f, 0.05f);

        glVertex2f(-0.6f, 0.15f);
        glVertex2f(-0.61f, 0.05f);

        glVertex2f(-0.55f, 0.15f);
        glVertex2f(-0.56f, 0.05f);

        glVertex2f(-0.5f, 0.15f);
        glVertex2f(-0.51f, 0.05f);

        glVertex2f(-0.45f, 0.15f);
        glVertex2f(-0.46f, 0.05f);

        glVertex2f(-0.4f, 0.15f);
        glVertex2f(-0.41f, 0.05f);

        glVertex2f(-0.35f, 0.15f);
        glVertex2f(-0.36f, 0.05f);

        glVertex2f(-0.3f, 0.15f);
        glVertex2f(-0.31f, 0.05f);

        glVertex2f(-0.25f, 0.15f);
        glVertex2f(-0.26f, 0.05f);

        glVertex2f(-0.2f, 0.15f);
        glVertex2f(-0.21f, 0.05f);

        glVertex2f(-0.15f, 0.15f);
        glVertex2f(-0.16f, 0.05f);

        glVertex2f(-0.1f, 0.15f);
        glVertex2f(-0.11f, 0.05f);

        glVertex2f(-0.05f, 0.15f);
        glVertex2f(-0.06f, 0.05f);

        glVertex2f(0.0f, 0.15f);
        glVertex2f(-0.01f, 0.05f);

        glVertex2f(0.05f, 0.15f);
        glVertex2f(0.04f, 0.05f);

        glVertex2f(0.10f, 0.15f);
        glVertex2f(0.09f, 0.05f);

        glVertex2f(0.15f, 0.15f);
        glVertex2f(0.14f, 0.05f);

        glVertex2f(0.20f, 0.15f);
        glVertex2f(0.19f, 0.05f);

        glVertex2f(0.25f, 0.15f);
        glVertex2f(0.24f, 0.05f);

        glVertex2f(0.30f, 0.15f);
        glVertex2f(0.29f, 0.05f);

        glVertex2f(0.35f, 0.15f);
        glVertex2f(0.34f, 0.05f);

        glVertex2f(0.40f, 0.15f);
        glVertex2f(0.39f, 0.05f);

        glVertex2f(0.45f, 0.15f);
        glVertex2f(0.44f, 0.05f);

        glVertex2f(0.50f, 0.15f);
        glVertex2f(0.49f, 0.05f);

        glVertex2f(0.55f, 0.15f);
        glVertex2f(0.54f, 0.05f);

        glVertex2f(0.60f, 0.15f);
        glVertex2f(0.59f, 0.05f);

        glVertex2f(0.65f, 0.15f);
        glVertex2f(0.64f, 0.05f);

        glVertex2f(0.70f, 0.15f);
        glVertex2f(0.69f, 0.05f);

        glVertex2f(0.75f, 0.15f);
        glVertex2f(0.74f, 0.05f);

        glVertex2f(0.80f, 0.15f);
        glVertex2f(0.79f, 0.05f);

        glVertex2f(0.85f, 0.15f);
        glVertex2f(0.84f, 0.05f);

        glVertex2f(0.90f, 0.15f);
        glVertex2f(0.89f, 0.05f);

        glVertex2f(0.95f, 0.15f);
        glVertex2f(0.94f, 0.05f);

        glVertex2f(1.0f, 0.15f);
        glVertex2f(0.99f, 0.05f);

        glVertex2f(1.05f, 0.15f);
        glVertex2f(1.04f, 0.05f);

        glEnd();

        ///5th line end

        ///6th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.05f);
        glVertex2f(-0.96f, -0.15f);

        glVertex2f(-0.9f, -0.05f);
        glVertex2f(-0.91f, -0.15f);

        glVertex2f(-0.85f, -0.05f);
        glVertex2f(-0.86f, -0.15f);

        glVertex2f(-0.8f, -0.05f);
        glVertex2f(-0.81f, -0.15f);

        glVertex2f(-0.75f, -0.05f);
        glVertex2f(-0.76f, -0.15f);

        glVertex2f(-0.7f, -0.05f);
        glVertex2f(-0.71f, -0.15f);

        glVertex2f(-0.65f, -0.05f);
        glVertex2f(-0.66f, -0.15f);

        glVertex2f(-0.6f, -0.05f);
        glVertex2f(-0.61f, -0.15f);

        glVertex2f(-0.55f, -0.05f);
        glVertex2f(-0.56f, -0.15f);

        glVertex2f(-0.5f, -0.05f);
        glVertex2f(-0.51f, -0.15f);

        glVertex2f(-0.45f, -0.05f);
        glVertex2f(-0.46f, -0.15f);

        glVertex2f(-0.4f, -0.05f);
        glVertex2f(-0.41f, -0.15f);

        glVertex2f(-0.35f, -0.05f);
        glVertex2f(-0.36f, -0.15f);

        glVertex2f(-0.3f, -0.05f);
        glVertex2f(-0.31f, -0.15f);

        glVertex2f(-0.25f, -0.05f);
        glVertex2f(-0.26f, -0.15f);

        glVertex2f(-0.2f, -0.05f);
        glVertex2f(-0.21f, -0.15f);

        glVertex2f(-0.15f, -0.05f);
        glVertex2f(-0.16f, -0.15f);

        glVertex2f(-0.1f, -0.05f);
        glVertex2f(-0.11f, -0.15f);

        glVertex2f(-0.05f, -0.05f);
        glVertex2f(-0.06f, -0.15f);

        glVertex2f(0.0f, -0.05f);
        glVertex2f(-0.01f, -0.15f);

        glVertex2f(0.05f, -0.05f);
        glVertex2f(0.04f, -0.15f);

        glVertex2f(0.10f, -0.05f);
        glVertex2f(0.09f, -0.15f);

        glVertex2f(0.15f, -0.05f);
        glVertex2f(0.14f, -0.15f);

        glVertex2f(0.20f, -0.05f);
        glVertex2f(0.19f, -0.15f);

        glVertex2f(0.25f, -0.05f);
        glVertex2f(0.24f, -0.15f);

        glVertex2f(0.30f, -0.05f);
        glVertex2f(0.29f, -0.15f);

        glVertex2f(0.35f, -0.05f);
        glVertex2f(0.34f, -0.15f);

        glVertex2f(0.40f, -0.05f);
        glVertex2f(0.39f, -0.15f);

        glVertex2f(0.45f, -0.05f);
        glVertex2f(0.44f, -0.15f);

        glVertex2f(0.50f, -0.05f);
        glVertex2f(0.49f, -0.15f);

        glVertex2f(0.55f, -0.05f);
        glVertex2f(0.54f, -0.15f);

        glVertex2f(0.60f, -0.05f);
        glVertex2f(0.59f, -0.15f);

        glVertex2f(0.65f, -0.05f);
        glVertex2f(0.64f, -0.15f);

        glVertex2f(0.70f, -0.05f);
        glVertex2f(0.69f, -0.15f);

        glVertex2f(0.75f, -0.05f);
        glVertex2f(0.74f, -0.15f);

        glVertex2f(0.80f, -0.05f);
        glVertex2f(0.79f, -0.15f);

        glVertex2f(0.85f, -0.05f);
        glVertex2f(0.84f, -0.15f);

        glVertex2f(0.90f, -0.05f);
        glVertex2f(0.89f, -0.15f);

        glVertex2f(0.95f, -0.05f);
        glVertex2f(0.94f, -0.15f);

        glVertex2f(1.0f, -0.05f);
        glVertex2f(0.99f, -0.15f);

        glVertex2f(1.05f, -0.05f);
        glVertex2f(1.04f, -0.15f);

        glEnd();

        ///6th line end


        ///7th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.25f);
        glVertex2f(-0.96f, -0.35f);

        glVertex2f(-0.9f, -0.25f);
        glVertex2f(-0.91f, -0.35f);

        glVertex2f(-0.85f, -0.25f);
        glVertex2f(-0.86f, -0.35f);

        glVertex2f(-0.8f, -0.25f);
        glVertex2f(-0.81f, -0.35f);

        glVertex2f(-0.75f, -0.25f);
        glVertex2f(-0.76f, -0.35f);

        glVertex2f(-0.7f, -0.25f);
        glVertex2f(-0.71f, -0.35f);

        glVertex2f(-0.65f, -0.25f);
        glVertex2f(-0.66f, -0.35f);

        glVertex2f(-0.6f, -0.25f);
        glVertex2f(-0.61f, -0.35f);

        glVertex2f(-0.55f, -0.25f);
        glVertex2f(-0.56f, -0.35f);

        glVertex2f(-0.5f, -0.25f);
        glVertex2f(-0.51f, -0.35f);

        glVertex2f(-0.45f, -0.25f);
        glVertex2f(-0.46f, -0.35f);

        glVertex2f(-0.4f, -0.25f);
        glVertex2f(-0.41f, -0.35f);

        glVertex2f(-0.35f, -0.25f);
        glVertex2f(-0.36f, -0.35f);

        glVertex2f(-0.3f, -0.25f);
        glVertex2f(-0.31f, -0.35f);

        glVertex2f(-0.25f, -0.25f);
        glVertex2f(-0.26f, -0.35f);

        glVertex2f(-0.2f, -0.25f);
        glVertex2f(-0.21f, -0.35f);

        glVertex2f(-0.15f, -0.25f);
        glVertex2f(-0.16f, -0.35f);

        glVertex2f(-0.1f, -0.25f);
        glVertex2f(-0.11f, -0.35f);

        glVertex2f(-0.05f, -0.25f);
        glVertex2f(-0.06f, -0.35f);

        glVertex2f(0.0f, -0.25f);
        glVertex2f(-0.01f, -0.35f);

        glVertex2f(0.05f, -0.25f);
        glVertex2f(0.04f, -0.35f);

        glVertex2f(0.10f, -0.25f);
        glVertex2f(0.09f, -0.35f);

        glVertex2f(0.15f, -0.25f);
        glVertex2f(0.14f, -0.35f);

        glVertex2f(0.20f, -0.25f);
        glVertex2f(0.19f, -0.35f);

        glVertex2f(0.25f, -0.25f);
        glVertex2f(0.24f, -0.35f);

        glVertex2f(0.30f, -0.25f);
        glVertex2f(0.29f, -0.35f);

        glVertex2f(0.35f, -0.25f);
        glVertex2f(0.34f, -0.35f);

        glVertex2f(0.40f, -0.25f);
        glVertex2f(0.39f, -0.35f);

        glVertex2f(0.45f, -0.25f);
        glVertex2f(0.44f, -0.35f);

        glVertex2f(0.50f, -0.25f);
        glVertex2f(0.49f, -0.35f);

        glVertex2f(0.55f, -0.25f);
        glVertex2f(0.54f, -0.35f);

        glVertex2f(0.60f, -0.25f);
        glVertex2f(0.59f, -0.35f);

        glVertex2f(0.65f, -0.25f);
        glVertex2f(0.64f, -0.35f);

        glVertex2f(0.70f, -0.25f);
        glVertex2f(0.69f, -0.35f);

        glVertex2f(0.75f, -0.25f);
        glVertex2f(0.74f, -0.35f);

        glVertex2f(0.80f, -0.25f);
        glVertex2f(0.79f, -0.35f);

        glVertex2f(0.85f, -0.25f);
        glVertex2f(0.84f, -0.35f);

        glVertex2f(0.90f, -0.25f);
        glVertex2f(0.89f, -0.35f);

        glVertex2f(0.95f, -0.25f);
        glVertex2f(0.94f, -0.35f);

        glVertex2f(1.0f, -0.25f);
        glVertex2f(0.99f, -0.35f);

        glVertex2f(1.05f, -0.25f);
        glVertex2f(1.04f, -0.35f);

        glEnd();

        ///7th line end

        ///8th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.45f);
        glVertex2f(-0.96f, -0.55f);

        glVertex2f(-0.9f, -0.45f);
        glVertex2f(-0.91f, -0.55f);

        glVertex2f(-0.85f, -0.45f);
        glVertex2f(-0.86f, -0.55f);

        glVertex2f(-0.8f, -0.45f);
        glVertex2f(-0.81f, -0.55f);

        glVertex2f(-0.75f, -0.45f);
        glVertex2f(-0.76f, -0.55f);

        glVertex2f(-0.7f, -0.45f);
        glVertex2f(-0.71f, -0.55f);

        glVertex2f(-0.65f, -0.45f);
        glVertex2f(-0.66f, -0.55f);

        glVertex2f(-0.6f, -0.45f);
        glVertex2f(-0.61f, -0.55f);

        glVertex2f(-0.55f, -0.45f);
        glVertex2f(-0.56f, -0.55f);

        glVertex2f(-0.5f, -0.45f);
        glVertex2f(-0.51f, -0.55f);

        glVertex2f(-0.45f, -0.45f);
        glVertex2f(-0.46f, -0.55f);

        glVertex2f(-0.4f, -0.45f);
        glVertex2f(-0.41f, -0.55f);

        glVertex2f(-0.35f, -0.45f);
        glVertex2f(-0.36f, -0.55f);

        glVertex2f(-0.3f, -0.45f);
        glVertex2f(-0.31f, -0.55f);

        glVertex2f(-0.25f, -0.45f);
        glVertex2f(-0.26f, -0.55f);

        glVertex2f(-0.2f, -0.45f);
        glVertex2f(-0.21f, -0.55f);

        glVertex2f(-0.15f, -0.45f);
        glVertex2f(-0.16f, -0.55f);

        glVertex2f(-0.1f, -0.45f);
        glVertex2f(-0.11f, -0.55f);

        glVertex2f(-0.05f, -0.45f);
        glVertex2f(-0.06f, -0.55f);

        glVertex2f(0.0f, -0.45f);
        glVertex2f(-0.01f, -0.55f);

        glVertex2f(0.05f, -0.45f);
        glVertex2f(0.04f, -0.55f);

        glVertex2f(0.10f, -0.45f);
        glVertex2f(0.09f, -0.55f);

        glVertex2f(0.15f, -0.45f);
        glVertex2f(0.14f, -0.55f);

        glVertex2f(0.20f, -0.45f);
        glVertex2f(0.19f, -0.55f);

        glVertex2f(0.25f, -0.45f);
        glVertex2f(0.24f, -0.55f);

        glVertex2f(0.30f, -0.45f);
        glVertex2f(0.29f, -0.55f);

        glVertex2f(0.35f, -0.45f);
        glVertex2f(0.34f, -0.55f);

        glVertex2f(0.40f, -0.45f);
        glVertex2f(0.39f, -0.55f);

        glVertex2f(0.45f, -0.45f);
        glVertex2f(0.44f, -0.55f);

        glVertex2f(0.50f, -0.45f);
        glVertex2f(0.49f, -0.55f);

        glVertex2f(0.55f, -0.45f);
        glVertex2f(0.54f, -0.55f);

        glVertex2f(0.60f, -0.45f);
        glVertex2f(0.59f, -0.55f);

        glVertex2f(0.65f, -0.45f);
        glVertex2f(0.64f, -0.55f);

        glVertex2f(0.70f, -0.45f);
        glVertex2f(0.69f, -0.55f);

        glVertex2f(0.75f, -0.45f);
        glVertex2f(0.74f, -0.55f);

        glVertex2f(0.80f, -0.45f);
        glVertex2f(0.79f, -0.55f);

        glVertex2f(0.85f, -0.45f);
        glVertex2f(0.84f, -0.55f);

        glVertex2f(0.90f, -0.45f);
        glVertex2f(0.89f, -0.55f);

        glVertex2f(0.95f, -0.45f);
        glVertex2f(0.94f, -0.55f);

        glVertex2f(1.0f, -0.45f);
        glVertex2f(0.99f, -0.55f);

        glVertex2f(1.05f, -0.45f);
        glVertex2f(1.04f, -0.55f);

        glEnd();

        ///8th line end

        ///9th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.65f);
        glVertex2f(-0.96f, -0.75f);

        glVertex2f(-0.9f, -0.65f);
        glVertex2f(-0.91f, -0.75f);

        glVertex2f(-0.85f, -0.65f);
        glVertex2f(-0.86f, -0.75f);

        glVertex2f(-0.8f, -0.65f);
        glVertex2f(-0.81f, -0.75f);

        glVertex2f(-0.75f, -0.65f);
        glVertex2f(-0.76f, -0.75f);

        glVertex2f(-0.7f, -0.65f);
        glVertex2f(-0.71f, -0.75f);

        glVertex2f(-0.65f, -0.65f);
        glVertex2f(-0.66f, -0.75f);

        glVertex2f(-0.6f, -0.65f);
        glVertex2f(-0.61f, -0.75f);

        glVertex2f(-0.55f, -0.65f);
        glVertex2f(-0.56f, -0.75f);

        glVertex2f(-0.5f, -0.65f);
        glVertex2f(-0.51f, -0.75f);

        glVertex2f(-0.45f, -0.65f);
        glVertex2f(-0.46f, -0.75f);

        glVertex2f(-0.4f, -0.65f);
        glVertex2f(-0.41f, -0.75f);

        glVertex2f(-0.35f, -0.65f);
        glVertex2f(-0.36f, -0.75f);

        glVertex2f(-0.3f, -0.65f);
        glVertex2f(-0.31f, -0.75f);

        glVertex2f(-0.25f, -0.65f);
        glVertex2f(-0.26f, -0.75f);

        glVertex2f(-0.2f, -0.65f);
        glVertex2f(-0.21f, -0.75f);

        glVertex2f(-0.15f, -0.65f);
        glVertex2f(-0.16f, -0.75f);

        glVertex2f(-0.1f, -0.65f);
        glVertex2f(-0.11f, -0.75f);

        glVertex2f(-0.05f, -0.65f);
        glVertex2f(-0.06f, -0.75f);

        glVertex2f(0.0f, -0.65f);
        glVertex2f(-0.01f, -0.75f);

        glVertex2f(0.05f, -0.65f);
        glVertex2f(0.04f, -0.75f);

        glVertex2f(0.10f, -0.65f);
        glVertex2f(0.09f, -0.75f);

        glVertex2f(0.15f, -0.65f);
        glVertex2f(0.14f, -0.75f);

        glVertex2f(0.20f, -0.65f);
        glVertex2f(0.19f, -0.75f);

        glVertex2f(0.25f, -0.65f);
        glVertex2f(0.24f, -0.75f);

        glVertex2f(0.30f, -0.65f);
        glVertex2f(0.29f, -0.75f);

        glVertex2f(0.35f, -0.65f);
        glVertex2f(0.34f, -0.75f);

        glVertex2f(0.40f, -0.65f);
        glVertex2f(0.39f, -0.75f);

        glVertex2f(0.45f, -0.65f);
        glVertex2f(0.44f, -0.75f);

        glVertex2f(0.50f, -0.65f);
        glVertex2f(0.49f, -0.75f);

        glVertex2f(0.55f, -0.65f);
        glVertex2f(0.54f, -0.75f);

        glVertex2f(0.60f, -0.65f);
        glVertex2f(0.59f, -0.75f);

        glVertex2f(0.65f, -0.65f);
        glVertex2f(0.64f, -0.75f);

        glVertex2f(0.70f, -0.65f);
        glVertex2f(0.69f, -0.75f);

        glVertex2f(0.75f, -0.65f);
        glVertex2f(0.74f, -0.75f);

        glVertex2f(0.80f, -0.65f);
        glVertex2f(0.79f, -0.75f);

        glVertex2f(0.85f, -0.65f);
        glVertex2f(0.84f, -0.75f);

        glVertex2f(0.90f, -0.65f);
        glVertex2f(0.89f, -0.75f);

        glVertex2f(0.95f, -0.65f);
        glVertex2f(0.94f, -0.75f);

        glVertex2f(1.0f, -0.65f);
        glVertex2f(0.99f, -0.75f);

        glVertex2f(1.05f, -0.65f);
        glVertex2f(1.04f, -0.75f);

        glEnd();

        ///9th line end


        ///10th line start

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(-0.95f, -0.85f);
        glVertex2f(-0.96f, -0.95f);

        glVertex2f(-0.9f, -0.85f);
        glVertex2f(-0.91f, -0.95f);

        glVertex2f(-0.85f, -0.85f);
        glVertex2f(-0.86f, -0.95f);

        glVertex2f(-0.8f, -0.85f);
        glVertex2f(-0.81f, -0.95f);

        glVertex2f(-0.75f, -0.85f);
        glVertex2f(-0.76f, -0.95f);

        glVertex2f(-0.7f, -0.85f);
        glVertex2f(-0.71f, -0.95f);

        glVertex2f(-0.65f, -0.85f);
        glVertex2f(-0.66f, -0.95f);

        glVertex2f(-0.6f, -0.85f);
        glVertex2f(-0.61f, -0.95f);

        glVertex2f(-0.55f, -0.85f);
        glVertex2f(-0.56f, -0.95f);

        glVertex2f(-0.5f, -0.85f);
        glVertex2f(-0.51f, -0.95f);

        glVertex2f(-0.45f, -0.85f);
        glVertex2f(-0.46f, -0.95f);

        glVertex2f(-0.4f, -0.85f);
        glVertex2f(-0.41f, -0.95f);

        glVertex2f(-0.35f, -0.85f);
        glVertex2f(-0.36f, -0.95f);

        glVertex2f(-0.3f, -0.85f);
        glVertex2f(-0.31f, -0.95f);

        glVertex2f(-0.25f, -0.85f);
        glVertex2f(-0.26f, -0.95f);

        glVertex2f(-0.2f, -0.85f);
        glVertex2f(-0.21f, -0.95f);

        glVertex2f(-0.15f, -0.85f);
        glVertex2f(-0.16f, -0.95f);

        glVertex2f(-0.1f, -0.85f);
        glVertex2f(-0.11f, -0.95f);

        glVertex2f(-0.05f, -0.85f);
        glVertex2f(-0.06f, -0.95f);

        glVertex2f(0.0f, -0.85f);
        glVertex2f(-0.01f, -0.95f);

        glVertex2f(0.05f, -0.85f);
        glVertex2f(0.04f, -0.95f);

        glVertex2f(0.10f, -0.85f);
        glVertex2f(0.09f, -0.95f);

        glVertex2f(0.15f, -0.85f);
        glVertex2f(0.14f, -0.95f);

        glVertex2f(0.20f, -0.85f);
        glVertex2f(0.19f, -0.95f);

        glVertex2f(0.25f, -0.85f);
        glVertex2f(0.24f, -0.95f);

        glVertex2f(0.30f, -0.85f);
        glVertex2f(0.29f, -0.95f);

        glVertex2f(0.35f, -0.85f);
        glVertex2f(0.34f, -0.95f);

        glVertex2f(0.40f, -0.85f);
        glVertex2f(0.39f, -0.95f);

        glVertex2f(0.45f, -0.85f);
        glVertex2f(0.44f, -0.95f);

        glVertex2f(0.50f, -0.85f);
        glVertex2f(0.49f, -0.95f);

        glVertex2f(0.55f, -0.85f);
        glVertex2f(0.54f, -0.95f);

        glVertex2f(0.60f, -0.85f);
        glVertex2f(0.59f, -1.0f);

        glVertex2f(0.65f, -0.85f);
        glVertex2f(0.64f, -0.95f);

        glVertex2f(0.70f, -0.85f);
        glVertex2f(0.69f, -0.95f);

        glVertex2f(0.75f, -0.85f);
        glVertex2f(0.74f, -0.95f);

        glVertex2f(0.80f, -0.85f);
        glVertex2f(0.79f, -0.95f);

        glVertex2f(0.85f, -0.85f);
        glVertex2f(0.84f, -0.95f);

        glVertex2f(0.90f, -0.85f);
        glVertex2f(0.89f, -0.95f);

        glVertex2f(0.95f, -0.85f);
        glVertex2f(0.94f, -0.95f);

        glVertex2f(1.0f, -0.85f);
        glVertex2f(0.99f, -0.95f);

        glVertex2f(1.05f, -0.85f);
        glVertex2f(1.04f, -0.95f);

        glEnd();

        ///10th line end


        ///----------------------------------rain 02 end


        glPopMatrix();
    }



    if(!cover)
    {
        glBegin(GL_QUADS);
        glColor3ub(64, 75, 129);
        glVertex2f(-1.0f,-1.0f);
        glVertex2f(1.0f, -1.0f);
        glColor3ub(0.18, 0.36, 0.56);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
        glEnd();
        glColor3ub(227, 234, 226);




        renderBitmapString(-0.26f, 0.85f, 0.0f, GLUT_BITMAP_HELVETICA_18," 01047 - COMPUTER GRAPHICS [A]");


        glPushMatrix();
        renderBitmapString(-0.26f, 0.75f, 0.0f, GLUT_BITMAP_HELVETICA_18, "NATIONAL PARLIAMENT BANGLADESH");
        glLoadIdentity();
        glPopMatrix();


        renderBitmapString(-0.18f, 0.6f, 0.0f, GLUT_BITMAP_HELVETICA_18,                                  "Submitted by Group[] ");
        renderBitmapString(-0.35f, 0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18,                 "ID                                        Name                                             Contribution ");
        renderBitmapString(-0.4f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-43651-2               MD. NASIFUR RAHMAN                               40% ");
        renderBitmapString(-0.4f, 0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-42675-1               MAHARABUR RAHMAN APU                       40% ");
        renderBitmapString(-0.4f, 0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "19-41692-3               ISHTIAQ HOQUE FARABI                             5% ");
        renderBitmapString(-0.4f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "19-41702-3               MD. SANJID BIN KARIM SEZAN                  5% ");
        renderBitmapString(-0.4f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-42516-1               NUSRAT JAHAN MARIA                                5% ");
        renderBitmapString(-0.4f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18,  "20-42802-1               MD. ZAHID HASAN                                        5% ");

        renderBitmapString(-0.12f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18,      "Submitted to");
        renderBitmapString(-0.18f, -0.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MAHFUJUR RAHAMAN");
        renderBitmapString(-0.22f, -0.65f, 0.0f, GLUT_BITMAP_HELVETICA_12,"FACULTY OF SCIENCE & TECHNOLOGY");
        renderBitmapString(-0.2f, -0.7f, 0.0f, GLUT_BITMAP_HELVETICA_10,  "American International University-Bangladesh");
    }



    glFlush();  // Render now
}

void Input(unsigned char key, int x, int y)
{

    switch(key)
    {
    case 'n':
        night = true;

        //sndPlaySound("H:\\AIUB\\9th sem\\01054 - COMPUTER GRAPHICS [M]\\CGPROJECT\\music\\night.wav",SND_ASYNC);

        break;
    case 'd':
        night = false;
        //sndPlaySound("H:\\AIUB\\9th sem\\01054 - COMPUTER GRAPHICS [M]\\CGPROJECT\\music\\day.wav",SND_ASYNC);
        break;

    case 's':
        if(cover)
        {
            cover = false;
        }
        else
        {
            cover = true;
        }
        break;
    case 'r':
        rain = true;
        break;

    case 'R':
        rain = false;

        break;

    case '1':
        sound = true;
        if(rain)
        {
            sndPlaySound("F:\\r\\rain1",SND_ASYNC);
        }
        else
            sndPlaySound("F:\\1a",SND_ASYNC);

        break;

    case '2':
        sound = false;

        break;

    case '+':
        glutFullScreen();
        break;

    case '-':
        glutReshapeWindow(1024,576);
        glutInitWindowPosition(50,40);
        break;

    }
    glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
//PlaySound("E:\\Code\\traffic",NULL,SND_ASYNC | SND_LOOP);///For sound
    cout << "Press s : For Start" << endl << endl;
    cout << "Press + : For Full Screen " << endl << endl;
    cout << "Press - : For Restore Screen " << endl << endl;
    cout << "Press n : For Night " << endl << endl;
    cout << "Press d : For Day " << endl << endl;
    cout << "Press r : For Rain start " << endl << endl;
    cout << "Press R : For Rain stop " << endl << endl;
    cout << "Press 1 : For Sound " << endl << endl;
    cout << "Press 2 : For Sound OFF " << endl << endl;



    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("National Parliament Bangladesh"); // Create a window with the given title
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    glutTimerFunc(100, update4, 0);
    glutTimerFunc(100, update5, 0);
    glutTimerFunc(100, update6, 0);
    glutTimerFunc(100, update7, 0);
    glutTimerFunc(100, update8, 0);

    glutTimerFunc(100, update11, 0);
    glutTimerFunc(100, update12, 0);
    glutInitWindowSize(1024, 576);
    glutInitWindowPosition(50, 40);  // Set the window's initial width & height
    glutKeyboardFunc(Input);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
