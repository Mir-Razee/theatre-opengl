#include <iostream>
#include <math.h>
#include <string.h>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "src/chair.h"
#include "src/chairarm.h"
#include "src/stair.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

using namespace std;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 10.0f, lz = -1.0f;
// XZ position of the camera
float x = -15.0f, z = 50.0f, y = 5.0f;
float roll = 0.0f;

// GLboolean redFlag = true, switchOne = false, switchTwo = false, switchLamp = false, amb1 = true, diff1 = true, spec1 = true, amb2 = true, diff2 = true, spec2 = true, amb3 = true, diff3 = true, spec3 = true;

// for mouse movements
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;

void drawSign(double p, double q, double r, int s);
void drawGrills(int rot);
// 
void lightBulb1()
// {
// 	GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
// 	GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
// 	GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
// 	GLfloat mat_diffuse[] = {1.000, 0.843, 0.000, 1.0};
// 	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
// 	GLfloat high_shininess[] = {100.0};
// 	GLfloat mat_emission[] = {1.000, 1, 1, 0.0};

// 	glPushMatrix();
// 	glTranslatef(5, 5, 8);
// 	glScalef(0.2, 0.2, 0.2);
// 	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
// 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
// 	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
// 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

// 	if (switchOne == true)
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
// 	}
// 	else
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
// 	}

// 	glutSolidSphere(1.0, 16, 16);
// 	glPopMatrix();
// }

// void lamp()
// {
// 	// lamp base
// 	glPushMatrix();
// 	glTranslatef(.6, 0.5, 8.95);
// 	glScalef(0.07, 0.02, 0.07);
// 	// drawCube1(0,0,1,  0,0,0.5);
// 	glPopMatrix();

// 	// lamp stand
// 	glColor3f(1, 0, 0);
// 	glPushMatrix();
// 	glTranslatef(.7, 0.35, 9.05);
// 	glScalef(0.01, 0.2, 0.01);
// 	// drawCube1(1,0,0,  0.5,0.0,0.0);
// 	glPopMatrix();

// 	// lamp shade
// 	glColor3f(0.000, 0.000, 0.545);
// 	glPushMatrix();
// 	glTranslatef(.6, 0.9, 8.9);
// 	glScalef(0.08, 0.09, 0.08);
// 	// drawTrapezoid(0.000, 0.000, 0.545,  0,0,0.2725);
// 	// drawCube1(0.000, 0.000, 0.545,  0,0,0.2725);
// 	glPopMatrix();
// }

// void lightBulb1()
// {
// 	GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
// 	GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
// 	GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
// 	GLfloat mat_diffuse[] = {1.000, 0.843, 0.000, 1.0};
// 	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
// 	GLfloat high_shininess[] = {100.0};
// 	GLfloat mat_emission[] = {1.000, 1, 1, 0.0};

// 	glPushMatrix();
// 	glTranslatef(5, 5, 8);
// 	glScalef(0.2, 0.2, 0.2);
// 	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
// 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
// 	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
// 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

// 	if (switchOne == true)
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
// 	}
// 	else
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
// 	}

// 	glutSolidSphere(1.0, 16, 16);
// 	glPopMatrix();
// }

// void lightBulb2()
// {
// 	GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
// 	GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
// 	GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
// 	GLfloat mat_diffuse[] = {1.000, 0.843, 0.000, 1.0};
// 	GLfloat high_shininess[] = {100.0};
// 	GLfloat mat_emission[] = {1, 1, 1, 1.0};

// 	glPushMatrix();
// 	glTranslatef(0, 5, 8);
// 	glScalef(0.2, 0.2, 0.2);
// 	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
// 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
// 	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
// 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
// 	if (switchTwo == true)
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
// 	}
// 	else
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
// 	}
// 	glutSolidSphere(1.0, 16, 16);
// 	glPopMatrix();
// }

// void lightBulb3()
// {
// 	GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
// 	GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
// 	GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
// 	GLfloat mat_diffuse[] = {1.000, 0.843, 0.000, 1.0};
// 	GLfloat high_shininess[] = {100.0};
// 	GLfloat mat_emission[] = {1, 1, 1, 1.0};

// 	glPushMatrix();
// 	glTranslatef(0.7, 1.5, 9.0);
// 	glScalef(0.2, 0.2, 0.2);
// 	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
// 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
// 	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
// 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
// 	if (switchLamp == true)
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
// 	}
// 	else
// 	{
// 		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
// 	}
// 	glutSolidSphere(1.0, 16, 16);
// 	glPopMatrix();
// }

// void lightOne()
// {
// 	glPushMatrix();
// 	GLfloat no_light[] = {0.0, 0.0, 0.0, 1.0};
// 	GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
// 	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
// 	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
// 	GLfloat light_position[] = {-15.0, 5.0, 20.0, 1.0}; // 5 5 10

// 	// glEnable( GL_LIGHT0);

// 	if (amb1 == true)
// 	{
// 		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT0, GL_AMBIENT, no_light);
// 	}

// 	if (diff1 == true)
// 	{
// 		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT0, GL_DIFFUSE, no_light);
// 	}

// 	if (spec1 == true)
// 	{
// 		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT0, GL_SPECULAR, no_light);
// 	}

// 	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
// 	glPopMatrix();
// }

// void lightTwo()
// {
// 	glPushMatrix();
// 	GLfloat no_light[] = {0.0, 0.0, 0.0, 1.0};
// 	GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
// 	GLfloat light_diffuse[] = {1.0, 1.0, 0.9, 1.0};
// 	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
// 	GLfloat light_position[] = {0.0, 5.0, 8.0, 1.0};

// 	// glEnable( GL_LIGHT1);

// 	if (amb2 == true)
// 	{
// 		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT1, GL_AMBIENT, no_light);
// 	}

// 	if (diff2 == true)
// 	{
// 		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT1, GL_DIFFUSE, no_light);
// 	}

// 	if (spec2 == true)
// 	{
// 		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT1, GL_SPECULAR, no_light);
// 	}

// 	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
// 	glPopMatrix();
// }

// void lampLight()
// {
// 	glPushMatrix();
// 	GLfloat no_light[] = {0.0, 0.0, 0.0, 1.0};
// 	GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
// 	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
// 	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
// 	GLfloat light_position[] = {0.7, 1.5, 9.0, 1.0}; // 0.7, 4.5, 9.0

// 	// glEnable( GL_LIGHT2);

// 	if (amb3 == true)
// 	{
// 		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT2, GL_AMBIENT, no_light);
// 	}

// 	if (diff3 == true)
// 	{
// 		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT2, GL_DIFFUSE, no_light);
// 	}

// 	if (spec3 == true)
// 	{
// 		glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
// 	}
// 	else
// 	{
// 		glLightfv(GL_LIGHT2, GL_SPECULAR, no_light);
// 	}

// 	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
// 	GLfloat spot_direction[] = {0.3, -1, -0.8};
// 	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
// 	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 35.0);
// 	glPopMatrix();
// }


void downWall(void)
{
	// Draw floor
	glColor3f(0.33f, 0.33f, 0.33f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 00.0f, -20.0f);
	glVertex3f(-20.0f, 00.0f, +20.0f);
	glVertex3f(+20.0f, 00.0f, +20.0f);
	glVertex3f(+20.0f, 00.0f, -20.0f);
	glEnd();
}

void topWall(void)
{
	// ceiling
	glColor3f(0.1f, 0.1f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 30.0f, +20.0f);
	glVertex3f(-20.0f, 30.0f, +20.0f);
	glEnd();
}

void backWall(void)
{
	// screen wall

	glColor3f(0.15f, 0.15f, 0.15f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 00.0f, -20.0f);
	glVertex3f(-20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 30.0f, -20.0f);
	glVertex3f(+20.0f, 00.0f, -20.0f);
	glEnd();
}

void leftWall(void)
{
	// wall
	// glColor3f(0.329, 0.106, 0.043);
	// // left wall
	glColor3f(0.66f, 0.49f, 0.44f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 00.0f, -20.0f);
	glVertex3f(-20.0f, 30.0f, -20.0f);
	glVertex3f(-20.0f, 30.0f, +20.0f);
	glVertex3f(-20.0f, 00.0f, +20.0f);
	glEnd();
	// left wall stripes
	for (int i = 0; i < 40; i += 1)
	{
		glColor3f(0.66f, 0.56f, 0.49f);
		glBegin(GL_QUADS);
		glVertex3f(-20.0f + 0.001f, 05.0f, -20.0f + i);
		glVertex3f(-20.0f + 0.001f, 30.0f, -20.0f + i);
		glVertex3f(-20.0f + 0.001f, 30.0f, -20.0f + i + 0.5);
		glVertex3f(-20.0f + 0.001f, 05.0f, -20.0f + i + 0.5);
		glEnd();
	}
	for (int i = 1; i < 41; i += 1)
	{
		glColor3f(0.95f, 0.87f, 0.73f);
		glBegin(GL_QUADS);
		glVertex3f(-20.0f + 0.001f, 05.0f, -20.0f + i - 0.5);
		glVertex3f(-20.0f + 0.001f, 30.0f, -20.0f + i - 0.5);
		glVertex3f(-20.0f + 0.001f, 30.0f, -20.0f + i);
		glVertex3f(-20.0f + 0.001f, 05.0f, -20.0f + i);
		glEnd();
	}
}

void frontWall(void)
{
	// wall with entrance
	glColor3f(0.66f, 0.49f, 0.44f);
	// glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-15.0f, 00.0f, 20.0f);
	glVertex3f(-15.0f, 30.0f, 20.0f);
	glVertex3f(+20.0f, 30.0f, 20.0f);
	glVertex3f(+20.0f, 00.0f, 20.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-18.0f, 30.0f, 20.0f);
	glVertex3f(-18.0f, 04.0f, 20.0f);
	glVertex3f(-15.0f, 04.0f, 20.0f);
	glVertex3f(-15.0f, 30.0f, 20.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-18.0f, 00.0f, 20.0f);
	glVertex3f(-18.0f, 30.0f, 20.0f);
	glVertex3f(-20.0f, 30.0f, 20.0f);
	glVertex3f(-20.0f, 00.0f, 20.0f);
	glEnd();

	// door frame
	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-18.0f, 4.0f, 20.01f);
	glVertex3f(-15.0f, 4.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-18.0f, 4.0f, 20.01f);
	glVertex3f(-18.0f, 0.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-15.0f, 0.0f, 20.01f);
	glVertex3f(-15.0f, 4.0f, 20.01f);
	glEnd();

	// entrance wall stripes
	for (int i = 0; i < 40; i += 1)
	{
		glColor3f(0.66f, 0.56f, 0.49f);
		glBegin(GL_QUADS);
		glVertex3f(-20.0f+i, 05.0f, +20.0f-0.001f);
		glVertex3f(-20.0f+i, 30.0f, +20.0f-0.001f);
		glVertex3f(-20.0f+i+0.5f, 30.0f, +20.0f-0.001f);
		glVertex3f(-20.0f+i+0.5f, 05.0f, +20.0f-0.001f);
		glEnd();
	}
	for (int i = 1; i < 41; i += 1)
	{
		glColor3f(0.95f, 0.87f, 0.73f);
		glBegin(GL_QUADS);
		glVertex3f(-20.0f + i - 0.5f, 05.0f, +20.0f - 0.001f);
		glVertex3f(-20.0f + i - 0.5f, 30.0f, +20.0f - 0.001f);
		glVertex3f(-20.0f + i, 30.0f, +20.0f - 0.001f);
		glVertex3f(-20.0f + i, 05.0f, +20.0f - 0.001f);
		glEnd();
	}
}

void rightWall(void)
{
	// wall with exit

	glColor3f(0.66f, 0.49f, 0.44f);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 00.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, +20.0f);
	glVertex3f(20.0f, 00.0f, +20.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(20.0f, 04.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, -12.0f);
	glVertex3f(20.0f, 30.0f, -18.0f);
	glVertex3f(20.0f, 04.0f, -18.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(20.0f, 00.0f, -18.0f);
	glVertex3f(20.0f, 30.0f, -18.0f);
	glVertex3f(20.0f, 30.0f, -20.0f);
	glVertex3f(20.0f, 00.0f, -20.0f);
	glEnd();

	// exit door
	glColor3f(0.58f, 0.29f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 0.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -18.0f);
	glVertex3f(20.0f, 0.0f, -18.0f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(20.0f, 4.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -18.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(20.0f, 4.0f, -18.0f);
	glVertex3f(20.0f, 0.0f, -18.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(20.0f, 0.0f, -15.0f);
	glVertex3f(20.0f, 4.0f, -15.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(20.0f, 0.0f, -12.0f);
	glVertex3f(20.0f, 4.0f, -12.0f);
	glEnd();

	// handle left
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(19.9f, 1.9f, -14.6f);
	glVertex3f(19.9f, 1.9f, -14.5f);
	glVertex3f(19.9f, 2.1f, -14.5f);
	glVertex3f(19.9f, 2.1f, -14.6f);
	glEnd();

	// handle right
	glBegin(GL_QUADS);
	glVertex3f(19.9f, 1.9f, -15.4f);
	glVertex3f(19.9f, 1.9f, -15.5f);
	glVertex3f(19.9f, 2.1f, -15.5f);
	glVertex3f(19.9f, 2.1f, -15.4f);
	glEnd();

	// right wall stripes
	for (int i = 0; i < 40; i += 1)
	{
		glColor3f(0.95f, 0.87f, 0.73f);
		glBegin(GL_QUADS);
		glVertex3f(+20.0f-0.001f, 05.0f, -20.0f+i);
		glVertex3f(+20.0f-0.001f, 30.0f, -20.0f+i);
		glVertex3f(+20.0f-0.001f, 30.0f, -20.0f+i+0.5);
		glVertex3f(+20.0f-0.001f, 05.0f, -20.0f+i+0.5);
		glEnd();
	}
	for (int i = 1; i < 41; i += 1)
	{
		glColor3f(0.66f, 0.56f, 0.49f);
		glBegin(GL_QUADS);
		glVertex3f(+20.0f-0.001f, 05.0f, -20.0f+i-0.5);
		glVertex3f(+20.0f-0.001f, 30.0f, -20.0f+i-0.5);
		glVertex3f(+20.0f-0.001f, 30.0f, -20.0f+i);
		glVertex3f(+20.0f-0.001f, 05.0f, -20.0f+i);
		glEnd();
	}
}

	// stair wall support left

	glColor3f(0.1f, 0.1f, 0.7f);
	glBegin(GL_POLYGON);
	glVertex3f(-14.0f, 00.0f, -08.0f);
	glVertex3f(-14.0f, 02.0f, -08.0f);
	glVertex3f(-14.0f, 15.0f, +17.0f);
	glVertex3f(-14.0f, 15.0f, +20.0f);
	glVertex3f(-14.0f, 00.0f, +20.0f);
	glVertex3f(-14.0f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.4f, 00.0f, -08.0f);
	glVertex3f(-13.4f, 02.0f, -08.0f);
	glVertex3f(-13.4f, 15.0f, +17.0f);
	glVertex3f(-13.4f, 15.0f, +20.0f);
	glVertex3f(-13.4f, 00.0f, +20.0f);
	glVertex3f(-13.4f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.4f, 02.0f, -08.0f);
	glVertex3f(-13.4f, 00.0f, -08.0f);
	glVertex3f(-14.0f, 00.0f, -08.0f);
	glVertex3f(-14.0f, 02.0f, -08.0f);
	glVertex3f(-14.0f, 15.0f, +17.0f);
	glVertex3f(-14.0f, 15.0f, +20.0f);
	glVertex3f(-13.4f, 15.0f, +20.0f);
	glVertex3f(-13.4f, 15.0f, +17.0f);
	glEnd();

	// stair wall support right

	glBegin(GL_POLYGON);
	glVertex3f(+13.2f, 00.0f, -08.0f);
	glVertex3f(+13.2f, 02.0f, -08.0f);
	glVertex3f(+13.2f, 15.0f, +17.0f);
	glVertex3f(+13.2f, 15.0f, +20.0f);
	glVertex3f(+13.2f, 00.0f, +20.0f);
	glVertex3f(+13.2f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(+12.6f, 00.0f, -08.0f);
	glVertex3f(+12.6f, 02.0f, -08.0f);
	glVertex3f(+12.6f, 15.0f, +17.0f);
	glVertex3f(+12.6f, 15.0f, +20.0f);
	glVertex3f(+12.6f, 00.0f, +20.0f);
	glVertex3f(+12.6f, 00.0f, -08.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(+12.6f, 02.0f, -08.0f);
	glVertex3f(+12.6f, 00.0f, -08.0f);
	glVertex3f(+13.2f, 00.0f, -08.0f);
	glVertex3f(+13.2f, 02.0f, -08.0f);
	glVertex3f(+13.2f, 15.0f, +17.0f);
	glVertex3f(+13.2f, 15.0f, +20.0f);
	glVertex3f(+12.6f, 15.0f, +20.0f);
	glVertex3f(+12.6f, 15.0f, +17.0f);
	glEnd();

	// // DRAW projector room
	// door
	glColor3f(0.58f, 0.29f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-13.0f, 12.0f, 19.9f);
	glVertex3f(-13.0f, 18.0f, 19.9f);
	glVertex3f(-10.0f, 18.0f, 19.9f);
	glVertex3f(-10.0f, 12.0f, 19.9f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-13.0f, 18.0f, 19.9f);
	glVertex3f(-10.0f, 18.0f, 19.9f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-13.0f, 18.0f, 19.9f);
	glVertex3f(-13.0f, 12.0f, 19.9f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-10.0f, 12.0f, 19.9f);
	glVertex3f(-10.0f, 18.0f, 19.9f);
	glEnd();

	glColor3f(0, 0, 0);
	// handle left
	glBegin(GL_QUADS);
	glVertex3f(-11.2f, 15.9f, 19.8f);
	glVertex3f(-11.3f, 15.9f, 19.8f);
	glVertex3f(-11.3f, 16.1f, 19.8f);
	glVertex3f(-11.2f, 16.1f, 19.8f);
	glEnd();

	// handle right
	glBegin(GL_QUADS);
	glVertex3f(-12.2f, 15.9f, 19.8f);
	glVertex3f(-12.1f, 15.9f, 19.8f);
	glVertex3f(-12.1f, 16.1f, 19.8f);
	glVertex3f(-12.2f, 16.1f, 19.8f);
	glEnd();

	// Draw floor
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 12.0f, 20.0f);
	glVertex3f(-16.0f, 12.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 20.0f);
	glEnd();

	// cieling
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 18.0f, 20.0f);
	glVertex3f(-16.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 18.0f, 20.0f);
	glEnd();

	// wall
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 12.0f, 26.0f);
	glVertex3f(-16.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 26.0f);
	glEnd();

	// wall
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-16.0f, 12.0f, 20.0f);
	glVertex3f(-16.0f, 18.0f, 20.0f);
	glVertex3f(-16.0f, 18.0f, 26.0f);
	glVertex3f(-16.0f, 12.0f, 26.0f);
	glEnd();

	// wall
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 12.0f, 20.0f);
	glVertex3f(-10.0f, 18.0f, 20.0f);
	glVertex3f(-10.0f, 18.0f, 26.0f);
	glVertex3f(-10.0f, 12.0f, 26.0f);
	glEnd();
	// Draw chairs and arms
	Chair chair[4][4];
	ChairArm chairArm[4][4];
	Stair stair[4];
	for (int i = -13; i <= 13; i += 2)
	{
		for (int j = -4; j <= 8; j += 1)
		{
			glPushMatrix();
			glTranslatef(i * 0.6, j * 1.0 + 4.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			glTranslatef(0, 2.0f, 0);
			chair[i][j].drawChair();
			glTranslatef(2.45f, 0.0f, 0.0f);
			chairArm[i][j].drawChairArm();
			if (i == -3 || i == 13)
			{
				glTranslatef(-4.9f, 0.0f, 0.0f);
				chairArm[i][j].drawChairArm();
			}
			glTranslatef(0.0f, -2.0f, 6.0f);
			glScalef(1.0f, 4.0f, 77.0f - j * 8.0);
			if (j == -4)
			{
				glScalef(1.0f, 0.5f, 1.0f);
			}
			stair[j].drawStair();
			glPopMatrix();
		}
		if (i == -3)
			i = 1;
	}

void screen(void)
{
	// Draw Screen
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-17.0f, 10.0f, -19.99f);
	glVertex3f(-17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 10.0f, -19.99f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex3f(-17.0f, 10.0f, -19.99f);
	glVertex3f(-17.0f, 25.6f, -19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 25.5f, -19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(17.0f, 25.6f, -19.99f);
	glVertex3f(17.0f, 10.0f, -19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(17.0f, 10.0f, -19.99f);
	glVertex3f(-17.0f, 10.0f, -19.99f);
	glEnd();
}

	// Floor pattern
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(3.0f);
	for (int i = 0; i < 40; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-20.0f + i, 0.001f, -20.01f);
		glVertex3f(-20.0f + i, 0.001f, +20.01f);
		glEnd();
	}
	for (int i = 0; i < 40; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-20.0f, 0.001f, -20.01f + i);
		glVertex3f(+20.0f, 0.001f, -20.01f + i);
		glEnd();
	}

	drawSign(0, -6, 0.1, 0);
	drawSign(0, -6, 0.1, 1);
	drawGrills(0);
	drawGrills(1);
	drawGrills(2);
	
	glutSwapBuffers();
	

}
// Handles the events triggered when one of the arrow keys are pressed.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processSpecialKeys(int key, int xx, int yy)
{

	float fraction = 0.1f;

	switch (key)
	{
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

// Handles the events triggered when any key on the keyboard is pressed.
// Specifically, handles w,a,s,d and Esc.
// moves the camera frward, backward and sideways.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processNormalKeys(unsigned char key, int xx, int yy)
{
	float fraction = 1.0f;
	if (key == 'w')
	{
		x += lx * fraction;
		z += lz * fraction;
	}
	else if (key == 'a')
	{
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
	}
	else if (key == 's')
	{
		x -= lx * fraction;
		z -= lz * fraction;
	}
	else if (key == 'd')
	{
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
	}
	else if (key == 'x')
	{
		roll += 0.5f;
	}
	else if (key == 'z')
	{
		roll -= 0.5f;
	}
	else if (key == 'm')
	{
		y += ly * fraction;
	}
	else if (key == 'n')
	{
		y -= ly * fraction;
	}
	// else if (key == 'h')
	// {
	// 	if(switchOne == false)
    //         {
    //             switchOne = true; amb1=true; diff1=true; spec1=true;
    //             glEnable( GL_LIGHT0); 
	// 			// break;
    //         }
    //         else if(switchOne == true)
    //         {
    //             switchOne = false; amb1=false; diff1=false; spec1=false; glDisable( GL_LIGHT0); 
	// 			// break;
    //         }
	// }


	if (key == 27)
		exit(0);
}

// Handles the events triggered when the mouse is moved in the window area.
// Handles yaw and pitch of the camera.
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processMouseMovement(int xx, int yy)
{

	mouseX = (float)(halfWidth - xx) / halfWidth;
	mouseY = (float)(halfHeight - yy) / halfHeight;
	angle -= (0.01f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if (abs(yAngle) < (M_PI / 2))
	{
		yAngle += (0.01f * mouseY);
	}
	ly = sin(yAngle);
}

// Adjusts the viewport sie when the window size is changed and sets the projection.
// @param w : new width of window
// @param h : new height of window
void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w / 2.0);
	halfHeight = (float)(h / 2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void animate()
{
	/* refresh screen */
	glutPostRedisplay();
}

void grill()
{
	// Set the color to light gray
	glColor3f(0.8f, 0.8f, 0.8f);

	// Draw the square vent using GL_TRIANGLE_STRIP
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.4f, 0.4f, 0.0f);	// Top-left vertex
	glVertex3f(0.4f, 0.4f, 0.0f);	// Top-right vertex
	glVertex3f(-0.4f, -0.4f, 0.0f); // Bottom-left vertex
	glVertex3f(0.4f, -0.4f, 0.0f);	// Bottom-right vertex
	glEnd();

	// Set the color to black for the grills
	glColor3f(0.0f, 0.0f, 0.0f);

	// Draw the horizontal grill lines using GL_LINES
	glLineWidth(4.0f); // Set the line width to 1
	glBegin(GL_LINES);
	glVertex3f(-0.4f, 0.3f, 0.0f);	// Top line 1 left point
	glVertex3f(0.4f, 0.3f, 0.0f);	// Top line 1 right point
	glVertex3f(-0.4f, 0.1f, 0.0f);	// Top line 2 left point
	glVertex3f(0.4f, 0.1f, 0.0f);	// Top line 2 right point
	glVertex3f(-0.4f, -0.1f, 0.0f); // Bottom line 1 left point
	glVertex3f(0.4f, -0.1f, 0.0f);	// Bottom line 1 right point
	glVertex3f(-0.4f, -0.3f, 0.0f); // Bottom line 2 left point
	glVertex3f(0.4f, -0.3f, 0.0f);	// Bottom line 2 right point
	glEnd();

	// Draw the vertical grill lines using GL_LINES
	glBegin(GL_LINES);
	glVertex3f(-0.2f, 0.4f, 0.0f);	// Top line left point
	glVertex3f(-0.2f, -0.4f, 0.0f); // Bottom line left point
	glVertex3f(0.2f, 0.4f, 0.0f);	// Top line right point
	glVertex3f(0.2f, -0.4f, 0.0f);	// Bottom line right point
	glEnd();
}

void drawGrills(int rot)
{
	if (rot == 1)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, -0.05);
	}
	else if (rot == 2)
	{
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, -0.05);
	}
	glTranslatef(-19.6, 20, 19.95);
	for (int i = 0; i < 99; i++)
	{
		glPushMatrix();
		glTranslatef(i * 0.4, 0, 0);
		grill();
		glPopMatrix();
	}

	glTranslatef(19.6, -20, -19.95);
	if (rot == 1)
	{
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, 0.05);
	}
	else if (rot == 2)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0, 0.05);
	}
}

void sign(int s)
{

	glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white
	glBegin(GL_QUADS);
	glVertex3f(-17.75f, 29.0f, -20.0f); // Top-left vertex
	glVertex3f(-15.25f, 29.0f, -20.0f); // Top-right vertex
	glVertex3f(-15.25f, 26.0f, -20.0f); // Bottom-right vertex
	glVertex3f(-17.75f, 26.0f, -20.0f); // Bottom-left vertex
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f); // Set the color to white

	// Draw the rectangle
	glBegin(GL_QUADS);
	glVertex3f(-17.5f, 28.5f, -19.90f); // Top-left vertex
	glVertex3f(-15.5f, 28.5f, -19.90f); // Top-right vertex
	glVertex3f(-15.5f, 26.5f, -19.90f); // Bottom-right vertex
	glVertex3f(-17.5f, 26.5f, -19.90f); // Bottom-left vertex
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f); // Set the color to black

	// Draw the "EXIT" text
	glRasterPos3f(-17.5f, 27.5f, -19.90f); // Set the position of the text
	if (s == 0)
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"EXIT");
	else if (s == 1)
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"ENTRY");
	else
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"Projector");
}
void drawSign(double p, double q, double r, int s)
{
	glPushMatrix();
	glTranslatef(p, q, r);
	glScalef(1.0f, 0.5f, 1.0);
	if (s == 0)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glTranslatef(0, -4, 0.2);
	}
	else
	{
		glRotatef(-180.0, 0.0, 1.0, 0.0);
		glTranslatef(34.9, -4, 0.2);
	}
	sign(s);
	glPopMatrix();
}

int main(int argc, char **argv)
{

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Theatre");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(processMouseMovement);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}