#include <iostream>
#include <math.h>
#include <string.h>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "src/chair.h"
#include "src/chairarm.h"
#include "src/fan.h"
#include "src/stair.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

using namespace std;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = -5.0f, z = 18.0f, y = 2.5f;
float roll = 0.0f;

// for mouse movements
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;

// // Fan
// Fan f;
void drawSign(double p, double q, double r, int s);
void drawGrills(int rot);
void renderScene(void)
{

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, y, z,
			  x + lx, y + ly, z + lz,
			  roll + 0.0f, 2.5f, 0.0f);

	// Draw floor
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glEnd();

	// wall
	glColor3f(0.9294f, 0.9216f, 0.8353f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glEnd();

	// wall
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 40.0f, -20.0f);
	glVertex3f(-20.0f, 40.0f, 20.0f);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glEnd();

	// wall with door
	//  glColor3f(1.0f, 0.851f, 0.702f);
	//  glBegin(GL_QUADS);
	//  glVertex3f(-10.0f, 0.0f, 20.0f);
	//  glVertex3f(-10.0f, 7.0f, 20.0f);
	//  glVertex3f(-6.0f, 7.0f, 20.0f);
	//  glVertex3f(-6.0f, 0.0f, 20.0f);
	//  glEnd();

	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-17.0f, 0.0f, 20.0f);
	glVertex3f(-17.0f, 40.0f, 20.0f);
	glVertex3f(20.0f, 40.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glEnd();

	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 40.0f, 20.0f);
	glVertex3f(-20.0f, 4.0f, 20.0f);
	glVertex3f(-17.0f, 4.0f, 20.0f);
	glVertex3f(-17.0f, 40.0f, 20.0f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-20.0f, 4.0f, 20.01f);
	glVertex3f(-17.0f, 4.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-20.0f, 4.0f, 20.01f);
	glVertex3f(-20.0f, 0.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-17.0f, 0.0f, 20.01f);
	glVertex3f(-17.0f, 4.0f, 20.01f);
	glEnd();

	// wall
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glEnd();

	// ceiling
	glColor3f(0.95f, 0.95f, 0.95f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, 20.0f);
	glVertex3f(-20.0f, 40.0f, 20.0f);
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
			chair[i][j].drawChair();
			glTranslatef(2.45f, 0.0f, 0.0f);
			chairArm[i][j].drawChairArm();
			if (i == -3 || i == 13)
			{
				glTranslatef(-4.9f, 0.0f, 0.0f);
				chairArm[i][j].drawChairArm();
			}
			glTranslatef(0.0f, -1.0f, 6.0f);
			glScalef(1.0f, 4.0f, 77.0f - j * 8.0);
			stair[j].drawStair();
			glPopMatrix();
		}
		if (i == -3)
			i = 1;
	}

	// Draw Screen
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-17.0f, 10.0f, -19.99f);
	glVertex3f(-17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 10.0f, -19.99f);
	glEnd();

	// glColor3f(0.149f, 0.149f, 0.149f);
	// glBegin(GL_QUADS);
	// glVertex3f(-5.8f, 2.2f, -9.98f);
	// glVertex3f(-5.8f, 5.3f, -9.98f);
	// glVertex3f(5.8f, 5.3f, -9.98f);
	// glVertex3f(5.8f, 2.2f, -9.98f);
	// glEnd();
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

	// Floor pattern
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(3.0f);
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f + i, 0.001f, -10.01f);
		glVertex3f(-10.0f + i, 0.001f, 10.01f);
		glEnd();
	}
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f, 0.001f, -10.01f + i);
		glVertex3f(10.0f, 0.001f, -10.01f + i);
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
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if (abs(yAngle) < (M_PI / 2))
	{
		yAngle += (0.005f * mouseY);
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

	// f.rotateFan();

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
	}
	else if (rot == 2)
	{
		glRotatef(90.0, 0.0, 1.0, 0.0);
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
	}
	else if (rot == 2)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
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
	else
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"ENTRY");
}
void drawSign(double p, double q, double r, int s)
{
	glPushMatrix();
	glTranslatef(p, q, r);
	glScalef(1.0f, 0.5f, 1.0);
	if (s == 0)
	{
		glRotatef(-90.0, 0.0, 1.0, 0.0);
	}
	else
	{
		glRotatef(-180.0, 0.0, 1.0, 0.0);
		glTranslatef(34.9, -4, 0.1);
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